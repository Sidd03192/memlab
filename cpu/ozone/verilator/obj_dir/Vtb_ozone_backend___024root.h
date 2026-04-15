// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_ozone_backend.h for the primary calling header

#ifndef VERILATED_VTB_OZONE_BACKEND___024ROOT_H_
#define VERILATED_VTB_OZONE_BACKEND___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_ozone_backend__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_ozone_backend___024root final {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ tb_ozone_backend__DOT__clk;
        CData/*0:0*/ tb_ozone_backend__DOT__rst_n;
        CData/*4:0*/ tb_ozone_backend__DOT__src1_addr;
        CData/*4:0*/ tb_ozone_backend__DOT__src2_addr;
        CData/*0:0*/ tb_ozone_backend__DOT__disp_wr_en;
        CData/*4:0*/ tb_ozone_backend__DOT__disp_wr_addr;
        CData/*5:0*/ tb_ozone_backend__DOT__disp_rob_idx;
        CData/*0:0*/ tb_ozone_backend__DOT__disp_nzcv_wr_en;
        CData/*5:0*/ tb_ozone_backend__DOT__disp_nzcv_rob_idx;
        CData/*5:0*/ tb_ozone_backend__DOT__src1_rob_idx;
        CData/*5:0*/ tb_ozone_backend__DOT__src2_rob_idx;
        CData/*0:0*/ tb_ozone_backend__DOT__src1_ready;
        CData/*0:0*/ tb_ozone_backend__DOT__src2_ready;
        CData/*0:0*/ tb_ozone_backend__DOT__rob_alloc_valid;
        CData/*0:0*/ tb_ozone_backend__DOT__alloc_has_dest;
        CData/*0:0*/ tb_ozone_backend__DOT__commit_valid;
        CData/*0:0*/ tb_ozone_backend__DOT__commit_reg_en;
        CData/*4:0*/ tb_ozone_backend__DOT__commit_reg_addr;
        CData/*0:0*/ tb_ozone_backend__DOT__commit_nzcv_en;
        CData/*3:0*/ tb_ozone_backend__DOT__commit_nzcv_value;
        CData/*0:0*/ tb_ozone_backend__DOT__adder_alloc_valid;
        CData/*0:0*/ tb_ozone_backend__DOT__adder_full;
        CData/*0:0*/ tb_ozone_backend__DOT__adder_granted;
        CData/*0:0*/ tb_ozone_backend__DOT__logic_alloc_valid;
        CData/*0:0*/ tb_ozone_backend__DOT__logic_full;
        CData/*0:0*/ tb_ozone_backend__DOT__logic_granted;
        CData/*5:0*/ tb_ozone_backend__DOT__regstate__DOT____Vlvbound_h6817daf0__0;
        CData/*0:0*/ tb_ozone_backend__DOT__regstate__DOT____Vlvbound_h687da136__0;
        CData/*0:0*/ tb_ozone_backend__DOT__regstate__DOT____Vlvbound_hc878112f__0;
        CData/*5:0*/ tb_ozone_backend__DOT__rob__DOT__head;
        CData/*5:0*/ tb_ozone_backend__DOT__rob__DOT__tail;
        CData/*6:0*/ tb_ozone_backend__DOT__rob__DOT__count;
        CData/*0:0*/ tb_ozone_backend__DOT__rob__DOT__head_can_commit;
        CData/*0:0*/ tb_ozone_backend__DOT__rob__DOT__do_alloc;
        CData/*0:0*/ tb_ozone_backend__DOT__adder__DOT__fu_ready;
        CData/*0:0*/ tb_ozone_backend__DOT__adder__DOT__issue_valid;
        CData/*0:0*/ tb_ozone_backend__DOT__adder__DOT__add_value_valid;
        CData/*3:0*/ tb_ozone_backend__DOT__adder__DOT__add_nzcv;
        CData/*0:0*/ tb_ozone_backend__DOT__adder__DOT__add_flags_valid;
        CData/*0:0*/ tb_ozone_backend__DOT__adder__DOT__add_br_valid;
        CData/*0:0*/ tb_ozone_backend__DOT__adder__DOT__add_br_taken;
        CData/*0:0*/ tb_ozone_backend__DOT__logic_fu__DOT__fu_ready;
        CData/*0:0*/ tb_ozone_backend__DOT__logic_fu__DOT__issue_valid;
        CData/*0:0*/ tb_ozone_backend__DOT__logic_fu__DOT__logic_value_valid;
        CData/*3:0*/ tb_ozone_backend__DOT__logic_fu__DOT__logic_nzcv;
        CData/*0:0*/ tb_ozone_backend__DOT__logic_fu__DOT__logic_flags_valid;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __VstlPhaseResult;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_ozone_backend__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_ozone_backend__DOT__rst_n__0;
        CData/*0:0*/ __VactPhaseResult;
        CData/*0:0*/ __VinactPhaseResult;
        CData/*0:0*/ __VnbaPhaseResult;
        IData/*31:0*/ tb_ozone_backend__DOT__adder__DOT__unnamedblk5__DOT__i;
        IData/*31:0*/ tb_ozone_backend__DOT__adder__DOT__unnamedblk6__DOT__i;
        IData/*31:0*/ tb_ozone_backend__DOT__logic_fu__DOT__unnamedblk5__DOT__i;
        IData/*31:0*/ tb_ozone_backend__DOT__logic_fu__DOT__unnamedblk6__DOT__i;
        IData/*31:0*/ __VactIterCount;
        IData/*31:0*/ __VinactIterCount;
        IData/*31:0*/ __Vi;
        VlWide<3>/*70:0*/ tb_ozone_backend__DOT__src1_status;
        VlWide<3>/*70:0*/ tb_ozone_backend__DOT__src2_status;
        QData/*63:0*/ tb_ozone_backend__DOT__src1_value;
        QData/*63:0*/ tb_ozone_backend__DOT__src2_value;
    };
    struct {
        VlWide<9>/*279:0*/ tb_ozone_backend__DOT__alloc_data;
        QData/*63:0*/ tb_ozone_backend__DOT__commit_reg_value;
        VlWide<6>/*164:0*/ tb_ozone_backend__DOT__adder_alloc_entry;
        VlWide<5>/*158:0*/ tb_ozone_backend__DOT__logic_alloc_entry;
        VlWide<5>/*150:0*/ tb_ozone_backend__DOT__cdb_broadcast;
        QData/*63:0*/ tb_ozone_backend__DOT__regstate__DOT____Vlvbound_h733992fd__0;
        VlWide<3>/*70:0*/ tb_ozone_backend__DOT__regstate__DOT__nzcv_reg;
        VlWide<5>/*150:0*/ tb_ozone_backend__DOT__adder__DOT__result;
        VlWide<6>/*164:0*/ tb_ozone_backend__DOT__adder__DOT__issue_entry;
        QData/*63:0*/ tb_ozone_backend__DOT__adder__DOT__add_result;
        QData/*63:0*/ tb_ozone_backend__DOT__adder__DOT__add_br_target;
        VlWide<5>/*150:0*/ tb_ozone_backend__DOT__logic_fu__DOT__result;
        VlWide<5>/*158:0*/ tb_ozone_backend__DOT__logic_fu__DOT__issue_entry;
        QData/*63:0*/ tb_ozone_backend__DOT__logic_fu__DOT__logic_result;
        VlUnpacked<VlWide<3>/*70:0*/, 31> tb_ozone_backend__DOT__regstate__DOT__gp_reg;
        VlUnpacked<VlWide<9>/*279:0*/, 64> tb_ozone_backend__DOT__rob__DOT__rob_entries;
        VlUnpacked<VlWide<6>/*164:0*/, 4> tb_ozone_backend__DOT__adder__DOT__entries;
        VlUnpacked<VlWide<5>/*158:0*/, 4> tb_ozone_backend__DOT__logic_fu__DOT__entries;
        VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VactTriggeredAcc;
        VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    };
    VlNBACommitQueue<VlUnpacked<VlWide<6>/*164:0*/, 4>, true, VlWide<6>/*164:0*/, 1> __VdlyCommitQueuetb_ozone_backend__DOT__adder__DOT__entries;
    VlNBACommitQueue<VlUnpacked<VlWide<5>/*158:0*/, 4>, true, VlWide<5>/*158:0*/, 1> __VdlyCommitQueuetb_ozone_backend__DOT__logic_fu__DOT__entries;
    std::string __Vtask_tb_ozone_backend__DOT__check_true__5__label;
    std::string __Vtask_tb_ozone_backend__DOT__check_true__6__label;
    std::string __Vtask_tb_ozone_backend__DOT__check_true__7__label;
    std::string __Vtask_tb_ozone_backend__DOT__check_true__8__label;
    std::string __Vtask_tb_ozone_backend__DOT__check_true__9__label;
    std::string __Vtask_tb_ozone_backend__DOT__check_true__10__label;
    std::string __Vtask_tb_ozone_backend__DOT__check_true__11__label;
    std::string __Vtask_tb_ozone_backend__DOT__check_true__12__label;
    std::string __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__22__label;
    std::string __Vtask_tb_ozone_backend__DOT__check_u64__23__label;
    std::string __Vtask_tb_ozone_backend__DOT__check_true__24__label;
    std::string __Vtask_tb_ozone_backend__DOT__check_true__25__label;
    std::string __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__35__label;
    std::string __Vtask_tb_ozone_backend__DOT__check_u64__36__label;
    std::string __Vtask_tb_ozone_backend__DOT__check_true__37__label;
    std::string __Vtask_tb_ozone_backend__DOT__check_true__38__label;
    std::string __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__51__label;
    std::string __Vtask_tb_ozone_backend__DOT__check_u64__52__label;
    std::string __Vtask_tb_ozone_backend__DOT__check_true__53__label;
    std::string __Vtask_tb_ozone_backend__DOT__check_true__64__label;
    std::string __Vtask_tb_ozone_backend__DOT__check_true__65__label;
    std::string __Vtask_tb_ozone_backend__DOT__check_u64__66__label;
    std::string __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__67__label;
    std::string __Vtask_tb_ozone_backend__DOT__check_u64__68__label;
    std::string __Vtask_tb_ozone_backend__DOT__check_true__69__label;
    std::string __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__70__label;
    std::string __Vtask_tb_ozone_backend__DOT__check_u64__71__label;
    std::string __Vtask_tb_ozone_backend__DOT__check_true__72__label;
    std::string __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__85__label;
    std::string __Vtask_tb_ozone_backend__DOT__check_u64__86__label;
    std::string __Vtask_tb_ozone_backend__DOT__check_true__87__label;
    std::string __Vtask_tb_ozone_backend__DOT__check_true__98__label;
    std::string __Vtask_tb_ozone_backend__DOT__check_true__99__label;
    std::string __Vtask_tb_ozone_backend__DOT__check_u64__100__label;
    std::string __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__101__label;
    std::string __Vtask_tb_ozone_backend__DOT__check_u64__102__label;
    std::string __Vtask_tb_ozone_backend__DOT__check_true__103__label;
    std::string __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__104__label;
    std::string __Vtask_tb_ozone_backend__DOT__check_u64__105__label;
    std::string __Vtask_tb_ozone_backend__DOT__check_true__106__label;
    std::string __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__119__label;
    std::string __Vtask_tb_ozone_backend__DOT__check_u64__120__label;
    std::string __Vtask_tb_ozone_backend__DOT__check_true__121__label;
    std::string __Vtask_tb_ozone_backend__DOT__check_true__132__label;
    std::string __Vtask_tb_ozone_backend__DOT__check_true__133__label;
    std::string __Vtask_tb_ozone_backend__DOT__check_u4__134__label;
    std::string __Vtask_tb_ozone_backend__DOT__check_u64__135__label;
    std::string __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__136__label;
    std::string __Vtask_tb_ozone_backend__DOT__check_u64__137__label;
    std::string __Vtask_tb_ozone_backend__DOT__check_true__138__label;
    std::string __Vtask_tb_ozone_backend__DOT__wait_for_nzcv_value__139__label;
    std::string __Vtask_tb_ozone_backend__DOT__check_u4__140__label;
    std::string __Vtask_tb_ozone_backend__DOT__check_true__141__label;
    std::string __Vtask_tb_ozone_backend__DOT__check_u64__142__label;
    std::string __Vtask_tb_ozone_backend__DOT__check_true__143__label;
    std::string __Vtask_tb_ozone_backend__DOT__check_u64__144__label;
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h0e5d9782__0;
    VlTriggerScheduler __VtrigSched_h0e5d9448__0;

    // INTERNAL VARIABLES
    Vtb_ozone_backend__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vtb_ozone_backend___024root(Vtb_ozone_backend__Syms* symsp, const char* namep);
    ~Vtb_ozone_backend___024root();
    VL_UNCOPYABLE(Vtb_ozone_backend___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
