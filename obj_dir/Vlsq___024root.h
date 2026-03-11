// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vlsq.h for the primary calling header

#ifndef VERILATED_VLSQ___024ROOT_H_
#define VERILATED_VLSQ___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vlsq__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vlsq___024root final {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ lsq_tb__DOT__clk;
    CData/*0:0*/ lsq_tb__DOT__rst_n;
    CData/*2:0*/ lsq_tb__DOT__op;
    CData/*0:0*/ lsq_tb__DOT__valid_in;
    CData/*0:0*/ lsq_tb__DOT__vaddr_ready;
    CData/*0:0*/ lsq_tb__DOT__wdata_ready;
    CData/*3:0*/ lsq_tb__DOT__id_in;
    CData/*0:0*/ lsq_tb__DOT__l1_ready;
    CData/*0:0*/ lsq_tb__DOT__tlb_ready;
    CData/*0:0*/ lsq_tb__DOT__sq_ready;
    CData/*0:0*/ lsq_tb__DOT__valid_out;
    CData/*2:0*/ lsq_tb__DOT__dut__DOT__lq_head;
    CData/*2:0*/ lsq_tb__DOT__dut__DOT__lq_tail;
    CData/*2:0*/ lsq_tb__DOT__dut__DOT__sq_head;
    CData/*2:0*/ lsq_tb__DOT__dut__DOT__sq_tail;
    CData/*0:0*/ lsq_tb__DOT__dut__DOT__lq_found;
    CData/*2:0*/ lsq_tb__DOT__dut__DOT__lq_found_entry;
    CData/*0:0*/ lsq_tb__DOT__dut__DOT__is_unresolved_store;
    CData/*0:0*/ lsq_tb__DOT__dut__DOT__sq_found;
    CData/*2:0*/ lsq_tb__DOT__dut__DOT__sq_found_entry;
    CData/*0:0*/ lsq_tb__DOT__dut__DOT__is_unresolved_load;
    CData/*0:0*/ lsq_tb__DOT__dut__DOT__unresolved_val_store;
    CData/*2:0*/ lsq_tb__DOT__dut__DOT__unnamedblk13__DOT__unnamedblk14__DOT__idx;
    CData/*2:0*/ lsq_tb__DOT__dut__DOT__unnamedblk15__DOT__unnamedblk16__DOT__idx;
    CData/*2:0*/ lsq_tb__DOT__dut__DOT__unnamedblk17__DOT__unnamedblk18__DOT__idx;
    CData/*2:0*/ lsq_tb__DOT__dut__DOT__unnamedblk19__DOT__unnamedblk20__DOT__idx;
    CData/*2:0*/ lsq_tb__DOT__dut__DOT__unnamedblk21__DOT__unnamedblk22__DOT__idx;
    CData/*2:0*/ lsq_tb__DOT__dut__DOT__unnamedblk23__DOT__unnamedblk24__DOT__idx;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__lsq_tb__DOT__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__lsq_tb__DOT__rst_n__0;
    IData/*31:0*/ lsq_tb__DOT__test_num;
    IData/*31:0*/ lsq_tb__DOT__pass_count;
    IData/*31:0*/ lsq_tb__DOT__fail_count;
    IData/*31:0*/ __VactIterCount;
    QData/*47:0*/ lsq_tb__DOT__vaddr_in;
    QData/*63:0*/ lsq_tb__DOT__wdata_in;
    QData/*47:0*/ lsq_tb__DOT__issue_vaddr;
    QData/*63:0*/ lsq_tb__DOT__issue_wdata;
    VlUnpacked<CData/*1:0*/, 8> lsq_tb__DOT__dut__DOT__lq_state;
    VlUnpacked<QData/*47:0*/, 8> lsq_tb__DOT__dut__DOT__lq_vaddr;
    VlUnpacked<CData/*3:0*/, 8> lsq_tb__DOT__dut__DOT__lq_id;
    VlUnpacked<CData/*7:0*/, 8> lsq_tb__DOT__dut__DOT__lq_before_vec;
    VlUnpacked<CData/*2:0*/, 8> lsq_tb__DOT__dut__DOT__sq_state;
    VlUnpacked<QData/*47:0*/, 8> lsq_tb__DOT__dut__DOT__sq_vaddr;
    VlUnpacked<QData/*63:0*/, 8> lsq_tb__DOT__dut__DOT__sq_wdata;
    VlUnpacked<CData/*3:0*/, 8> lsq_tb__DOT__dut__DOT__sq_id;
    VlUnpacked<CData/*7:0*/, 8> lsq_tb__DOT__dut__DOT__sq_before_vec;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h1553b621__0;
    VlTriggerScheduler __VtrigSched_h1553b6e0__0;

    // INTERNAL VARIABLES
    Vlsq__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vlsq___024root(Vlsq__Syms* symsp, const char* namep);
    ~Vlsq___024root();
    VL_UNCOPYABLE(Vlsq___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
