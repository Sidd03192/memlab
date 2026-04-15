// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_ozone_cdb.h for the primary calling header

#ifndef VERILATED_VTB_OZONE_CDB___024ROOT_H_
#define VERILATED_VTB_OZONE_CDB___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_ozone_cdb__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_ozone_cdb___024root final {
  public:

    // DESIGN SPECIFIC STATE
    CData/*5:0*/ tb_ozone_cdb__DOT__rob_head;
    CData/*0:0*/ tb_ozone_cdb__DOT__adder_granted;
    CData/*0:0*/ tb_ozone_cdb__DOT__logic_granted;
    CData/*0:0*/ tb_ozone_cdb__DOT__fpu_granted;
    CData/*0:0*/ tb_ozone_cdb__DOT__mem_granted;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VstlPhaseResult;
    CData/*0:0*/ __VactPhaseResult;
    CData/*0:0*/ __VinactPhaseResult;
    CData/*0:0*/ __VnbaPhaseResult;
    IData/*31:0*/ __VactIterCount;
    IData/*31:0*/ __VinactIterCount;
    IData/*31:0*/ __Vi;
    VlWide<5>/*150:0*/ tb_ozone_cdb__DOT__adder_req;
    VlWide<5>/*150:0*/ tb_ozone_cdb__DOT__logic_req;
    VlWide<5>/*150:0*/ tb_ozone_cdb__DOT__fpu_req;
    VlWide<5>/*150:0*/ tb_ozone_cdb__DOT__mem_req;
    VlWide<5>/*150:0*/ tb_ozone_cdb__DOT__cdb_broadcast;
    VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggeredAcc;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    std::string __Vtask_tb_ozone_cdb__DOT__check_bit__1__label;
    std::string __Vtask_tb_ozone_cdb__DOT__check_bit__2__label;
    std::string __Vtask_tb_ozone_cdb__DOT__check_bit__3__label;
    std::string __Vtask_tb_ozone_cdb__DOT__check_bit__5__label;
    std::string __Vtask_tb_ozone_cdb__DOT__check_tag__6__label;
    std::string __Vtask_tb_ozone_cdb__DOT__check_bit__7__label;
    std::string __Vtask_tb_ozone_cdb__DOT__check_bit__8__label;
    std::string __Vtask_tb_ozone_cdb__DOT__check_tag__12__label;
    std::string __Vtask_tb_ozone_cdb__DOT__check_bit__13__label;
    std::string __Vtask_tb_ozone_cdb__DOT__check_bit__14__label;
    std::string __Vtask_tb_ozone_cdb__DOT__check_tag__18__label;
    std::string __Vtask_tb_ozone_cdb__DOT__check_bit__19__label;
    std::string __Vtask_tb_ozone_cdb__DOT__check_bit__20__label;
    std::string __Vtask_tb_ozone_cdb__DOT__check_tag__26__label;
    std::string __Vtask_tb_ozone_cdb__DOT__check_bit__27__label;
    std::string __Vtask_tb_ozone_cdb__DOT__check_bit__28__label;
    std::string __Vtask_tb_ozone_cdb__DOT__check_bit__29__label;
    std::string __Vtask_tb_ozone_cdb__DOT__check_bit__30__label;
    VlDelayScheduler __VdlySched;

    // INTERNAL VARIABLES
    Vtb_ozone_cdb__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vtb_ozone_cdb___024root(Vtb_ozone_cdb__Syms* symsp, const char* namep);
    ~Vtb_ozone_cdb___024root();
    VL_UNCOPYABLE(Vtb_ozone_cdb___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
