#!/usr/bin/env python3
"""
Thsi runs a couple tests, we need to add more. Just made it so we can ensure that whne we make changs, we cna maek sure that old stuff is runnign properly.

Usage:
    1. Start VTop in another terminal: cd verilator/obj_dir && ./VTop
    2. Run tests: python3 -u /Users/spotta/Desktop/School/aca/memlab/cpu/ozone/run_tests.py

"""
import subprocess
import mmap
import struct
import os
import sys
import argparse
import ctypes
import ctypes.util

ROOT_DIR = os.path.dirname(os.path.abspath(__file__))
OZONE_BIN = os.path.join(ROOT_DIR, "ozone")
CONFIG_PATH = os.path.join(ROOT_DIR, "ozone-config.json")
TESTCASE_DIR = os.path.join(ROOT_DIR, "testcases", "bin")
CSR_SHM_NAME = "/ozone_csr"
CSR_SPAN = 0x00200000
X_REGS_BASE = 0x100
X_REG_COUNT = 31
V_REGS_BASE = 0x200   # FP registers (Verilator: sim_main writes here)
V_REG_COUNT = 32
DEFAULT_TIMEOUT_SECONDS = 10

# Expected register values after each test completes.
# Only registers listed here are checked; unlisted registers are ignored.
# "x0".."x30" = integer registers, "v0".."v31" = FP registers (raw 64-bit).
EXPECTED = {
    # ── Level 0: basic ALU ────────────────────────────────────────────────────
    "0_basic": {f"x{i}": 0 for i in range(X_REG_COUNT)},
    "0_add":  {"x0": 0x1, "x1": 0xfff, "x4": 0x2},
    "0_sub":  {"x0": 0xffffffffffffffff, "x1": 0xfffffffffffff001, "x4": 0xfffffffffffffffe},
    "0_movz": {"x0": 0xCDEF000000000000, "x1": 0x1234, "x2": 0x56780000, "x3": 0x90AB00000000},
    "0_movk": {
        "x0": 0xCDEF90AB56781234,
        "x1": 0xCDEF90AB56781234,
        "x2": 0xCDEF90AB56781234,
        "x3": 0xCDEF90AB56781234,
    },

    # ── Level 1: branches, BL/RET ────────────────────────────────────────────
    # B.EQ taken: x0=65535, x1=42069; branch-not-taken path never runs
    "1_branch_taken":     {"x0": 0xffff, "x1": 0xa455, "x3": 0, "x5": 0xffffffffffffffff},
    # B.EQ not taken (1 != 2): fall through, x0 stays 1
    "1_branch_not_taken": {"x0": 1, "x1": 2, "x3": 0xffffffffffffffff, "x5": 0xffffffffffffffff},
    # CMN sets V (0x7000...+0x4000... overflows), B.VS taken, adds 13+12 to x0
    "1_bcond_cmn":        {"x0": 0x7000000000000019, "x1": 0x4000000000000000, "x5": 0xffffffffffffffff},
    # BL to helper, helper sets x0=85 x1=28, caller adds: 85+28=113
    "1_ret_hazard":       {"x0": 113, "x1": 28, "x5": 0xffffffffffffffff},
    # BL add_two_nums(100, 1000) = 1100; x1 cleared to 0 before ret
    "1_bl":               {"x0": 1100, "x1": 0},

    # ── Level 2: memory, loops, FP ───────────────────────────────────────────
    # Binary search for 7 in {1,3,5,7,9,11,13,15,17,19}: index 3
    "2_bin_search":       {"x0": 3},
    # 0/1 knapsack, capacity=25, 10 items: optimal value = 42
    "2_knapsack_simple":  {"x0": 0x2a},
    # Iterative sum of 1..25 = 325
    "2_iter_sum":         {"x0": 325},
    # 2.0+1.5=3.5, 3.5-1.5=2.0, 2.0*2.0=4.0; FCMP 4.0>2.0 → b.gt taken → x0=0xABCD
    "2_floating_point":   {
        "x0": 0xabcd,
        "v2": 0x400C000000000000,   # 3.5
        "v3": 0x4000000000000000,   # 2.0
        "v4": 0x4010000000000000,   # 4.0
        "v5": 0xC010000000000000,   # -4.0
    },
    # Stores 1..26 to stack then exits immediately (recursive fn not called): x0=0
    "2_rec_sum":          {"x0": 0},
}

def open_shared_memory(name):
    """Open a POSIX shared memory object and return its file descriptor."""
    libc_path = ctypes.util.find_library("c")
    if libc_path is None:
        raise RuntimeError("could not find libc for shm_open")

    libc = ctypes.CDLL(libc_path, use_errno=True)
    shm_open = libc.shm_open
    shm_open.argtypes = [ctypes.c_char_p, ctypes.c_int, ctypes.c_uint]
    shm_open.restype = ctypes.c_int

    fd = shm_open(name.encode(), os.O_RDONLY, 0)
    if fd < 0:
        err = ctypes.get_errno()
        raise OSError(err, os.strerror(err), name)

    return fd

def read_registers():
    """Read X0-X30 and V0-V31 from /ozone_csr shared memory."""
    fd = None
    try:
        fd = open_shared_memory(CSR_SHM_NAME)
        mm = mmap.mmap(fd, CSR_SPAN, access=mmap.ACCESS_READ)

        regs = {}
        for i in range(X_REG_COUNT):
            offset = X_REGS_BASE + i * 8
            regs[f"x{i}"] = struct.unpack("<Q", mm[offset:offset+8])[0]
        for i in range(V_REG_COUNT):
            offset = V_REGS_BASE + i * 8
            regs[f"v{i}"] = struct.unpack("<Q", mm[offset:offset+8])[0]

        mm.close()
        return regs
    except OSError as exc:
        if exc.errno == 2:
            print(f"Error: {CSR_SHM_NAME} shared memory not found. Is VTop running?")
        else:
            print(f"Error: could not read {CSR_SHM_NAME}: {exc}")
        return None
    finally:
        if fd is not None:
            os.close(fd)

def run_test(test_name, timeout_seconds):
    """Run a single test and return (passed, actual_regs)"""
    elf_path = os.path.join(TESTCASE_DIR, f"{test_name}.elf")
    print(f"  RUN   {test_name}", flush=True)

    # Check if ELF exists
    if not os.path.exists(elf_path):
        print(f"  SKIP  {test_name} (ELF not found)")
        return None, None

    # Run ozone
    try:
        result = subprocess.run(
            [OZONE_BIN, CONFIG_PATH, "run_verilator", elf_path],
            capture_output=True,
            text=True,
            timeout=timeout_seconds,
            cwd=ROOT_DIR,
        )
    except subprocess.TimeoutExpired:
        print(f"  ERROR {test_name}: ozone timed out after {timeout_seconds}s", flush=True)
        return False, None

    if result.returncode != 0:
        print(f"  ERROR {test_name}: ozone failed", flush=True)
        if result.stderr:
            print(f"        {result.stderr.strip()}", flush=True)
        if result.stdout:
            print(f"        {result.stdout.strip()}", flush=True)
        return False, None

    # Read registers from shared memory
    actual = read_registers()
    if actual is None:
        return False, None

    expected = EXPECTED.get(test_name, {})

    # Check all expected registers
    passed = True
    for reg, exp_val in expected.items():
        if actual[reg] != exp_val:
            passed = False
            break

    return passed, actual

def main():
    parser = argparse.ArgumentParser(description="Run Level 0 Verilator tests against VTop.")
    parser.add_argument(
        "--timeout",
        type=float,
        default=DEFAULT_TIMEOUT_SECONDS,
        help=f"seconds to wait for each ozone invocation (default: {DEFAULT_TIMEOUT_SECONDS})",
    )
    args = parser.parse_args()

    print("=" * 50)
    print("Verilator Test Runner")
    print("=" * 50)
    print(f"Runner: {os.path.abspath(__file__)}")
    print(f"Repo:   {ROOT_DIR}")
    print(f"Ozone:  {OZONE_BIN}")
    print("\nNote: VTop must be running in another terminal")
    print("      cd verilator/obj_dir && ./VTop\n", flush=True)

    passed = 0
    failed = 0
    skipped = 0

    for test_name in EXPECTED:
        ok, regs = run_test(test_name, args.timeout)

        if ok is None:
            skipped += 1
            continue

        if ok:
            print(f"  PASS  {test_name}", flush=True)
            passed += 1
        else:
            print(f"  FAIL  {test_name}", flush=True)
            failed += 1
            # Print mismatches
            if regs:
                for reg, exp in EXPECTED[test_name].items():
                    actual = regs[reg]
                    if actual != exp:
                        print(f"        {reg}: expected 0x{exp:016x}", flush=True)
                        print(f"        {reg}: got      0x{actual:016x}", flush=True)

    print("\n" + "=" * 50)
    print(f"Results: {passed} passed, {failed} failed, {skipped} skipped")
    print("=" * 50)

    return 1 if failed > 0 or skipped > 0 else 0

if __name__ == "__main__":
    sys.exit(main())
