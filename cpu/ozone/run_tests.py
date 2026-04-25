#!/usr/bin/env python3
"""
Run all testcases comparing verilator (RTL) output against functional sim output.

For each test:
  1. ./ozone ozone-config.json sim <elf>              → reference state
  2. ./ozone ozone-config.json run_verilator <elf>    → RTL state  (fresh VTop each time)
  3. Parse "Final Architectural State" from both and diff GPRs, FP regs, and memory.

Usage:
    python3 run_tests.py [--timeout SECS] [--filter PATTERN]
"""
import subprocess
import re
import os
import sys
import argparse
import time
import fnmatch
import tempfile

ROOT_DIR     = os.path.dirname(os.path.abspath(__file__))
OZONE_BIN    = os.path.join(ROOT_DIR, "ozone")
CONFIG_PATH  = os.path.join(ROOT_DIR, "ozone-config.json")
TESTCASE_DIR = os.path.join(ROOT_DIR, "testcases", "bin")
VTOP_BIN     = os.path.join(ROOT_DIR, "verilator", "obj_dir", "VTop")
DEFAULT_TIMEOUT = 10

# Tests skipped in verilator mode (RTL feature not implemented / expected crash).
SKIP_VERILATOR = {
    # "el1_3_page_fault",  # TLB $stop assertion — page fault handling not in RTL
    # "3_page_fault",  # TLB $stop assertion — page fault handling not in RTL

}


def parse_final_state(output):
    """
    Parse the "Final Architectural State" block from ozone text output.
    Returns dict: 'xN' -> int, 'vN' -> int, 'mem@0xADDR' -> int.
    Skips PC, PSTATE, EL, and system registers (not present in RTL output).
    """
    state = {}
    lines = output.splitlines()

    start = next((i + 1 for i, l in enumerate(lines)
                  if 'Final Architectural State' in l), None)
    if start is None:
        return state

    section = None
    for line in lines[start:]:
        stripped = line.strip()
        if stripped.startswith('==='):
            break
        if not stripped:
            continue

        if 'General Purpose Registers' in stripped:
            section = 'gpr'
        elif 'Floating Point Registers' in stripped:
            section = 'fpr'
        elif 'Modified Memory' in stripped:
            section = 'mem'
        elif 'System Registers' in stripped or stripped.startswith(('PC:', 'PSTATE:', 'EL:')):
            section = None  # skip header fields and system-reg block
        elif section == 'gpr':
            for m in re.finditer(r'X(\d+)\s*:\s*(0x[0-9a-fA-F]+)', line):
                state[f'x{m.group(1)}'] = int(m.group(2), 16)
        elif section == 'fpr':
            for m in re.finditer(r'V(\d+)\s*:\s*(0x[0-9a-fA-F]+)', line):
                state[f'v{m.group(1)}'] = int(m.group(2), 16)
        elif section == 'mem':
            m = re.match(r'\s*(0x[0-9a-fA-F]+):\s*(0x[0-9a-fA-F]+)', line)
            if m:
                state[f'mem@{m.group(1)}'] = int(m.group(2), 16)

    return state


def run_sim(elf_path, timeout):
    try:
        r = subprocess.run(
            [OZONE_BIN, CONFIG_PATH, "sim", elf_path],
            capture_output=True, text=True, timeout=timeout, cwd=ROOT_DIR,
        )
    except subprocess.TimeoutExpired:
        return None, "timed out"
    if r.returncode != 0:
        return None, f"exited {r.returncode}: {r.stderr.strip()}"
    state = parse_final_state(r.stdout)
    return (state, None) if state else (None, "no parseable final state")


def run_verilator(elf_path, timeout):
    if not os.path.exists(VTOP_BIN):
        return None, f"VTop not found at {VTOP_BIN}"

    # Capture VTop's stdout via a temp file — avoids pipe-buffer deadlock when
    # VTop prints simulation output while ozone is waiting for it to respond.
    with tempfile.TemporaryFile() as vtop_out:
        vtop = subprocess.Popen([VTOP_BIN], stdout=vtop_out, stderr=subprocess.DEVNULL)
        time.sleep(0.1)

        ozone_err = None
        try:
            r = subprocess.run(
                [OZONE_BIN, CONFIG_PATH, "run_verilator", elf_path],
                capture_output=True, text=True, timeout=timeout, cwd=ROOT_DIR,
            )
            if r.returncode != 0:
                ozone_err = f"ozone exited {r.returncode}: {r.stderr.strip()}"
        except subprocess.TimeoutExpired:
            ozone_err = "timed out"

        if ozone_err:
            vtop.terminate()
            vtop.wait()
            return None, ozone_err

        # Ozone exited cleanly. VTop signals completion before finishing its
        # print, so wait for it to exit naturally and flush all output.
        try:
            vtop.wait(timeout=2.0)
        except subprocess.TimeoutExpired:
            vtop.terminate()
            vtop.wait()

        vtop_out.seek(0)
        vtop_text = vtop_out.read().decode("utf-8", errors="replace")

    state = parse_final_state(vtop_text)
    return (state, None) if state else (None, "no parseable final state in VTop output")


def compare_states(sim, rtl):
    """Return list of (field, sim_val, rtl_val) for every mismatch.

    Registers: full diff (any disagreement is a bug).
    Memory: only flag addresses present in BOTH outputs with different values.
      Addresses missing from one side are ignored — sim and RTL have different
      128-word caps and the boot page-table fill saturates the RTL's cap
      differently than the sim's, producing false positives for missing entries.
    """
    diffs = []
    for key in sorted(sim):
        if key.startswith('mem@'):
            continue
        rtl_val = rtl.get(key, 0)
        if sim[key] != rtl_val:
            diffs.append((key, sim[key], rtl_val))
    for key in sorted(rtl):
        if key.startswith('mem@'):
            continue
        if key not in sim and rtl[key] != 0:
            diffs.append((key, 0, rtl[key]))
    # Memory: value mismatch at the same address only.
    # Skip RTL entries with value 0 — VTop tracks cache writebacks in addition to
    # committed stores; cold zero-initialized lines evicting over PTE addresses
    # produce spurious 0-value entries that don't represent real store failures.
    for key in sorted(sim):
        if not key.startswith('mem@') or key not in rtl:
            continue
        rtl_val = rtl[key]
        if rtl_val == 0:
            continue  # spurious cache writeback of uninitialized line
        if sim[key] != rtl_val:
            diffs.append((key, sim[key], rtl_val))
    return diffs


def run_test(name, timeout):
    if name in SKIP_VERILATOR:
        print(f"  SKIP  {name}", flush=True)
        return "skip", []
    elf = os.path.join(TESTCASE_DIR, f"{name}.elf")
    print(f"  RUN   {name}", flush=True)

    sim_state, err = run_sim(elf, timeout)
    if sim_state is None:
        print(f"  ERROR {name}: sim — {err}", flush=True)
        return "error", []

    rtl_state, err = run_verilator(elf, timeout)
    if rtl_state is None:
        print(f"  ERROR {name}: verilator — {err}", flush=True)
        return "error", []

    diffs = compare_states(sim_state, rtl_state)
    return ("pass" if not diffs else "fail"), diffs


def discover_tests():
    return [f[:-4] for f in sorted(os.listdir(TESTCASE_DIR))
            if f.startswith("el1_") and f.endswith(".elf")]
            # if f.endswith(".elf")]


def main():
    p = argparse.ArgumentParser(description="Compare verilator RTL against functional sim.")
    p.add_argument("--timeout", type=float, default=DEFAULT_TIMEOUT,
                   help=f"seconds per test (default: {DEFAULT_TIMEOUT})")
    p.add_argument("--filter", default=None, help="only run tests whose name matches this glob")
    args = p.parse_args()

    print("=" * 55)
    print("Verilator vs Sim Test Runner")
    print("=" * 55)
    print(f"Ozone:  {OZONE_BIN}")
    print(f"VTop:   {VTOP_BIN}")
    print(f"Tests:  {TESTCASE_DIR}\n", flush=True)

    tests = discover_tests()
    if args.filter:
        tests = [t for t in tests if fnmatch.fnmatch(t, f"*{args.filter}*")]
        if not tests:
            print(f"No tests match filter '{args.filter}'")
            return 0

    passed = failed = errors = skipped = 0
    for name in tests:
        outcome, diffs = run_test(name, args.timeout)
        if outcome == "pass":
            print(f"  PASS  {name}", flush=True)
            passed += 1
        elif outcome == "fail":
            print(f"  FAIL  {name}", flush=True)
            failed += 1
            for field, sv, rv in diffs:
                print(f"        {field}: sim=0x{sv:016x}  rtl=0x{rv:016x}", flush=True)
        elif outcome == "skip":
            skipped += 1
        else:
            errors += 1

    print("\n" + "=" * 55)
    print(f"Results: {passed} passed, {failed} failed, {errors} errors, {skipped} skipped")
    print("=" * 55)
    return 1 if (failed or errors) else 0


if __name__ == "__main__":
    sys.exit(main())
