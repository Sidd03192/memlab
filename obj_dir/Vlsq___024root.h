// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vlsq.h for the primary calling header

#ifndef VERILATED_VLSQ___024ROOT_H_
#define VERILATED_VLSQ___024ROOT_H_  // guard

#include "verilated.h"


class Vlsq__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vlsq___024root final {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst_n,0,0);
    VL_IN8(op,2,0);
    VL_IN8(valid_in,0,0);
    VL_IN8(vaddr_ready,0,0);
    VL_IN8(wdata_ready,0,0);
    VL_IN8(id_in,3,0);
    VL_IN8(l1_ready,0,0);
    VL_IN8(tlb_ready,0,0);
    VL_OUT8(lq_ready,0,0);
    VL_OUT8(sq_ready,0,0);
    VL_OUT8(valid_out,0,0);
    CData/*2:0*/ lsq__DOT__lq_head;
    CData/*2:0*/ lsq__DOT__lq_tail;
    CData/*2:0*/ lsq__DOT__sq_head;
    CData/*2:0*/ lsq__DOT__sq_tail;
    CData/*0:0*/ lsq__DOT__lq_found;
    CData/*2:0*/ lsq__DOT__lq_found_entry;
    CData/*0:0*/ lsq__DOT__is_unresolved_store;
    CData/*0:0*/ lsq__DOT__sq_found;
    CData/*2:0*/ lsq__DOT__sq_found_entry;
    CData/*0:0*/ lsq__DOT__is_unresolved_load;
    CData/*0:0*/ lsq__DOT__unresolved_val_store;
    CData/*2:0*/ lsq__DOT__unnamedblk13__DOT__unnamedblk14__DOT__idx;
    CData/*2:0*/ lsq__DOT__unnamedblk15__DOT__unnamedblk16__DOT__idx;
    CData/*2:0*/ lsq__DOT__unnamedblk17__DOT__unnamedblk18__DOT__idx;
    CData/*2:0*/ lsq__DOT__unnamedblk19__DOT__unnamedblk20__DOT__idx;
    CData/*2:0*/ lsq__DOT__unnamedblk21__DOT__unnamedblk22__DOT__idx;
    CData/*2:0*/ lsq__DOT__unnamedblk23__DOT__unnamedblk24__DOT__idx;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__rst_n__0;
    IData/*31:0*/ __VactIterCount;
    VL_IN64(vaddr_in,47,0);
    VL_IN64(wdata_in,63,0);
    VL_OUT64(issue_vaddr,47,0);
    VL_OUT64(issue_wdata,63,0);
    VlUnpacked<CData/*1:0*/, 8> lsq__DOT__lq_state;
    VlUnpacked<QData/*47:0*/, 8> lsq__DOT__lq_vaddr;
    VlUnpacked<CData/*3:0*/, 8> lsq__DOT__lq_id;
    VlUnpacked<CData/*7:0*/, 8> lsq__DOT__lq_before_vec;
    VlUnpacked<CData/*2:0*/, 8> lsq__DOT__sq_state;
    VlUnpacked<QData/*47:0*/, 8> lsq__DOT__sq_vaddr;
    VlUnpacked<QData/*63:0*/, 8> lsq__DOT__sq_wdata;
    VlUnpacked<CData/*3:0*/, 8> lsq__DOT__sq_id;
    VlUnpacked<CData/*7:0*/, 8> lsq__DOT__sq_before_vec;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;

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
