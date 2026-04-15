// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_ozone_backend.h for the primary calling header

#include "Vtb_ozone_backend__pch.h"

VlCoroutine Vtb_ozone_backend___024root___eval_initial__TOP__Vtiming__0(Vtb_ozone_backend___024root* vlSelf);
VlCoroutine Vtb_ozone_backend___024root___eval_initial__TOP__Vtiming__1(Vtb_ozone_backend___024root* vlSelf);

void Vtb_ozone_backend___024root___eval_initial(Vtb_ozone_backend___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ozone_backend___024root___eval_initial\n"); );
    Vtb_ozone_backend__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_ozone_backend__DOT__clk = 0U;
    Vtb_ozone_backend___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_ozone_backend___024root___eval_initial__TOP__Vtiming__1(vlSelf);
}

extern const VlWide<9>/*287:0*/ Vtb_ozone_backend__ConstPool__CONST_h083ec1be_0;
void Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9782__0(Vtb_ozone_backend___024root* vlSelf, const char* __VeventDescription);
void Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9448__0(Vtb_ozone_backend___024root* vlSelf, const char* __VeventDescription);

VlCoroutine Vtb_ozone_backend___024root___eval_initial__TOP__Vtiming__0(Vtb_ozone_backend___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ozone_backend___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vtb_ozone_backend__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ tb_ozone_backend__DOT__failures;
    tb_ozone_backend__DOT__failures = 0;
    IData/*31:0*/ __Vtask_tb_ozone_backend__DOT__reset_dut__2__tb_ozone_backend__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_ozone_backend__DOT__reset_dut__2__tb_ozone_backend__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__check_true__5__cond;
    __Vtask_tb_ozone_backend__DOT__check_true__5__cond = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__check_true__6__cond;
    __Vtask_tb_ozone_backend__DOT__check_true__6__cond = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__check_true__7__cond;
    __Vtask_tb_ozone_backend__DOT__check_true__7__cond = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__check_true__8__cond;
    __Vtask_tb_ozone_backend__DOT__check_true__8__cond = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__check_true__9__cond;
    __Vtask_tb_ozone_backend__DOT__check_true__9__cond = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__check_true__10__cond;
    __Vtask_tb_ozone_backend__DOT__check_true__10__cond = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__check_true__11__cond;
    __Vtask_tb_ozone_backend__DOT__check_true__11__cond = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__check_true__12__cond;
    __Vtask_tb_ozone_backend__DOT__check_true__12__cond = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__test_basic_adder_commit__13__add_tag;
    __Vtask_tb_ozone_backend__DOT__test_basic_adder_commit__13__add_tag = 0;
    IData/*31:0*/ __Vtask_tb_ozone_backend__DOT__reset_dut__14__tb_ozone_backend__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_ozone_backend__DOT__reset_dut__14__tb_ozone_backend__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    IData/*31:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__17__idx;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__17__idx = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__17__value;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__17__value = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__17____Vlvbound_hee8445f9__0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__17____Vlvbound_hee8445f9__0 = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__17____Vlvbound_hee492a18__0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__17____Vlvbound_hee492a18__0 = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__17____Vlvbound_hffe4168d__0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__17____Vlvbound_hffe4168d__0 = 0;
    IData/*31:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__18__idx;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__18__idx = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__18__value;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__18__value = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__18____Vlvbound_hee8445f9__0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__18____Vlvbound_hee8445f9__0 = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__18____Vlvbound_hee492a18__0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__18____Vlvbound_hee492a18__0 = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__18____Vlvbound_hffe4168d__0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__18____Vlvbound_hffe4168d__0 = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__op;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__op = 0;
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__reg_a;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__reg_a = 0;
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__reg_b;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__reg_b = 0;
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__dest_reg;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__dest_reg = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__has_dest;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__has_dest = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__writes_nzcv;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__writes_nzcv = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__tag_out;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__tag_out = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__vj;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__vj = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__vk;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__vk = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__qj;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__qj = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__qk;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__qk = 0;
    VlWide<6>/*164:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__entry;
    VL_ZERO_W(165, __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__entry);
    VlWide<9>/*279:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__rob_entry;
    VL_ZERO_W(280, __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__rob_entry);
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__20__reg_a;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__20__reg_a = 0;
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__20__reg_b;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__20__reg_b = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__20__vj;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__20__vj = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__20__qj;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__20__qj = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__20__vk;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__20__vk = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__20__qk;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__20__qk = 0;
    IData/*31:0*/ __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__22__reg_idx;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__22__reg_idx = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__22__expected;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__22__expected = 0;
    IData/*31:0*/ __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__22__cycles;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__22__cycles = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__check_u64__23__got;
    __Vtask_tb_ozone_backend__DOT__check_u64__23__got = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__check_u64__23__expected;
    __Vtask_tb_ozone_backend__DOT__check_u64__23__expected = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__check_true__24__cond;
    __Vtask_tb_ozone_backend__DOT__check_true__24__cond = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__check_true__25__cond;
    __Vtask_tb_ozone_backend__DOT__check_true__25__cond = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__test_basic_logic_commit__26__logic_tag;
    __Vtask_tb_ozone_backend__DOT__test_basic_logic_commit__26__logic_tag = 0;
    IData/*31:0*/ __Vtask_tb_ozone_backend__DOT__reset_dut__27__tb_ozone_backend__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_ozone_backend__DOT__reset_dut__27__tb_ozone_backend__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    IData/*31:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__30__idx;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__30__idx = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__30__value;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__30__value = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__30____Vlvbound_hee8445f9__0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__30____Vlvbound_hee8445f9__0 = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__30____Vlvbound_hee492a18__0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__30____Vlvbound_hee492a18__0 = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__30____Vlvbound_hffe4168d__0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__30____Vlvbound_hffe4168d__0 = 0;
    IData/*31:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__31__idx;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__31__idx = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__31__value;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__31__value = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__31____Vlvbound_hee8445f9__0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__31____Vlvbound_hee8445f9__0 = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__31____Vlvbound_hee492a18__0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__31____Vlvbound_hee492a18__0 = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__31____Vlvbound_hffe4168d__0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__31____Vlvbound_hffe4168d__0 = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__op;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__op = 0;
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__reg_a;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__reg_a = 0;
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__reg_b;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__reg_b = 0;
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__dest_reg;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__dest_reg = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__has_dest;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__has_dest = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__writes_nzcv;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__writes_nzcv = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__tag_out;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__tag_out = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__vj;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__vj = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__vk;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__vk = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__qj;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__qj = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__qk;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__qk = 0;
    VlWide<5>/*158:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__entry;
    VL_ZERO_W(159, __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__entry);
    VlWide<9>/*279:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__rob_entry;
    VL_ZERO_W(280, __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__rob_entry);
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__33__reg_a;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__33__reg_a = 0;
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__33__reg_b;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__33__reg_b = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__33__vj;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__33__vj = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__33__qj;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__33__qj = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__33__vk;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__33__vk = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__33__qk;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__33__qk = 0;
    IData/*31:0*/ __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__35__reg_idx;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__35__reg_idx = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__35__expected;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__35__expected = 0;
    IData/*31:0*/ __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__35__cycles;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__35__cycles = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__check_u64__36__got;
    __Vtask_tb_ozone_backend__DOT__check_u64__36__got = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__check_u64__36__expected;
    __Vtask_tb_ozone_backend__DOT__check_u64__36__expected = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__check_true__37__cond;
    __Vtask_tb_ozone_backend__DOT__check_true__37__cond = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__check_true__38__cond;
    __Vtask_tb_ozone_backend__DOT__check_true__38__cond = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__test_adder_internal_forwarding__39__prod_tag;
    __Vtask_tb_ozone_backend__DOT__test_adder_internal_forwarding__39__prod_tag = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__test_adder_internal_forwarding__39__cons_tag;
    __Vtask_tb_ozone_backend__DOT__test_adder_internal_forwarding__39__cons_tag = 0;
    IData/*31:0*/ __Vtask_tb_ozone_backend__DOT__test_adder_internal_forwarding__39__cons_slot;
    __Vtask_tb_ozone_backend__DOT__test_adder_internal_forwarding__39__cons_slot = 0;
    IData/*31:0*/ __Vtask_tb_ozone_backend__DOT__reset_dut__40__tb_ozone_backend__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_ozone_backend__DOT__reset_dut__40__tb_ozone_backend__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    IData/*31:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__43__idx;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__43__idx = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__43__value;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__43__value = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__43____Vlvbound_hee8445f9__0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__43____Vlvbound_hee8445f9__0 = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__43____Vlvbound_hee492a18__0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__43____Vlvbound_hee492a18__0 = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__43____Vlvbound_hffe4168d__0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__43____Vlvbound_hffe4168d__0 = 0;
    IData/*31:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__44__idx;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__44__idx = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__44__value;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__44__value = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__44____Vlvbound_hee8445f9__0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__44____Vlvbound_hee8445f9__0 = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__44____Vlvbound_hee492a18__0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__44____Vlvbound_hee492a18__0 = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__44____Vlvbound_hffe4168d__0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__44____Vlvbound_hffe4168d__0 = 0;
    IData/*31:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__45__idx;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__45__idx = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__45__value;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__45__value = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__45____Vlvbound_hee8445f9__0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__45____Vlvbound_hee8445f9__0 = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__45____Vlvbound_hee492a18__0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__45____Vlvbound_hee492a18__0 = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__45____Vlvbound_hffe4168d__0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__45____Vlvbound_hffe4168d__0 = 0;
    IData/*31:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__46__idx;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__46__idx = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__46__value;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__46__value = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__46____Vlvbound_hee8445f9__0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__46____Vlvbound_hee8445f9__0 = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__46____Vlvbound_hee492a18__0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__46____Vlvbound_hee492a18__0 = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__46____Vlvbound_hffe4168d__0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__46____Vlvbound_hffe4168d__0 = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__warmup_tag_zero__47__expected;
    __Vtask_tb_ozone_backend__DOT__warmup_tag_zero__47__expected = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__op;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__op = 0;
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__reg_a;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__reg_a = 0;
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__reg_b;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__reg_b = 0;
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__dest_reg;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__dest_reg = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__has_dest;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__has_dest = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__writes_nzcv;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__writes_nzcv = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__tag_out;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__tag_out = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__vj;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__vj = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__vk;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__vk = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__qj;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__qj = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__qk;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__qk = 0;
    VlWide<5>/*158:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__entry;
    VL_ZERO_W(159, __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__entry);
    VlWide<9>/*279:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__rob_entry;
    VL_ZERO_W(280, __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__rob_entry);
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__49__reg_a;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__49__reg_a = 0;
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__49__reg_b;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__49__reg_b = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__49__vj;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__49__vj = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__49__qj;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__49__qj = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__49__vk;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__49__vk = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__49__qk;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__49__qk = 0;
    IData/*31:0*/ __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__51__reg_idx;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__51__reg_idx = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__51__expected;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__51__expected = 0;
    IData/*31:0*/ __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__51__cycles;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__51__cycles = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__check_u64__52__got;
    __Vtask_tb_ozone_backend__DOT__check_u64__52__got = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__check_u64__52__expected;
    __Vtask_tb_ozone_backend__DOT__check_u64__52__expected = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__check_true__53__cond;
    __Vtask_tb_ozone_backend__DOT__check_true__53__cond = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__op;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__op = 0;
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__reg_a;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__reg_a = 0;
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__reg_b;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__reg_b = 0;
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__dest_reg;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__dest_reg = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__has_dest;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__has_dest = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__writes_nzcv;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__writes_nzcv = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__tag_out;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__tag_out = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__vj;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__vj = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__vk;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__vk = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__qj;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__qj = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__qk;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__qk = 0;
    VlWide<5>/*158:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__entry;
    VL_ZERO_W(159, __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__entry);
    VlWide<9>/*279:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__rob_entry;
    VL_ZERO_W(280, __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__rob_entry);
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__55__reg_a;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__55__reg_a = 0;
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__55__reg_b;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__55__reg_b = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__55__vj;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__55__vj = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__55__qj;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__55__qj = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__55__vk;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__55__vk = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__55__qk;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__55__qk = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__op;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__op = 0;
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__reg_a;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__reg_a = 0;
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__reg_b;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__reg_b = 0;
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__dest_reg;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__dest_reg = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__has_dest;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__has_dest = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__writes_nzcv;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__writes_nzcv = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__tag_out;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__tag_out = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__vj;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__vj = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__vk;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__vk = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__qj;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__qj = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__qk;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__qk = 0;
    VlWide<6>/*164:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__entry;
    VL_ZERO_W(165, __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__entry);
    VlWide<9>/*279:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__rob_entry;
    VL_ZERO_W(280, __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__rob_entry);
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__58__reg_a;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__58__reg_a = 0;
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__58__reg_b;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__58__reg_b = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__58__vj;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__58__vj = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__58__qj;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__58__qj = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__58__vk;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__58__vk = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__58__qk;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__58__qk = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__op;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__op = 0;
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__reg_a;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__reg_a = 0;
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__reg_b;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__reg_b = 0;
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__dest_reg;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__dest_reg = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__has_dest;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__has_dest = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__writes_nzcv;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__writes_nzcv = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__tag_out;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__tag_out = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__vj;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__vj = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__vk;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__vk = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__qj;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__qj = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__qk;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__qk = 0;
    VlWide<6>/*164:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__entry;
    VL_ZERO_W(165, __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__entry);
    VlWide<9>/*279:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__rob_entry;
    VL_ZERO_W(280, __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__rob_entry);
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__61__reg_a;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__61__reg_a = 0;
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__61__reg_b;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__61__reg_b = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__61__vj;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__61__vj = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__61__qj;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__61__qj = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__61__vk;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__61__vk = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__61__qk;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__61__qk = 0;
    IData/*31:0*/ __Vfunc_tb_ozone_backend__DOT__find_adder_slot__63__Vfuncout;
    __Vfunc_tb_ozone_backend__DOT__find_adder_slot__63__Vfuncout = 0;
    CData/*5:0*/ __Vfunc_tb_ozone_backend__DOT__find_adder_slot__63__tag;
    __Vfunc_tb_ozone_backend__DOT__find_adder_slot__63__tag = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__check_true__64__cond;
    __Vtask_tb_ozone_backend__DOT__check_true__64__cond = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__check_true__65__cond;
    __Vtask_tb_ozone_backend__DOT__check_true__65__cond = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__check_u64__66__got;
    __Vtask_tb_ozone_backend__DOT__check_u64__66__got = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__check_u64__66__expected;
    __Vtask_tb_ozone_backend__DOT__check_u64__66__expected = 0;
    IData/*31:0*/ __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__67__reg_idx;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__67__reg_idx = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__67__expected;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__67__expected = 0;
    IData/*31:0*/ __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__67__cycles;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__67__cycles = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__check_u64__68__got;
    __Vtask_tb_ozone_backend__DOT__check_u64__68__got = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__check_u64__68__expected;
    __Vtask_tb_ozone_backend__DOT__check_u64__68__expected = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__check_true__69__cond;
    __Vtask_tb_ozone_backend__DOT__check_true__69__cond = 0;
    IData/*31:0*/ __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__70__reg_idx;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__70__reg_idx = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__70__expected;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__70__expected = 0;
    IData/*31:0*/ __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__70__cycles;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__70__cycles = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__check_u64__71__got;
    __Vtask_tb_ozone_backend__DOT__check_u64__71__got = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__check_u64__71__expected;
    __Vtask_tb_ozone_backend__DOT__check_u64__71__expected = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__check_true__72__cond;
    __Vtask_tb_ozone_backend__DOT__check_true__72__cond = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__test_logic_internal_forwarding__73__prod_tag;
    __Vtask_tb_ozone_backend__DOT__test_logic_internal_forwarding__73__prod_tag = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__test_logic_internal_forwarding__73__cons_tag;
    __Vtask_tb_ozone_backend__DOT__test_logic_internal_forwarding__73__cons_tag = 0;
    IData/*31:0*/ __Vtask_tb_ozone_backend__DOT__test_logic_internal_forwarding__73__cons_slot;
    __Vtask_tb_ozone_backend__DOT__test_logic_internal_forwarding__73__cons_slot = 0;
    IData/*31:0*/ __Vtask_tb_ozone_backend__DOT__reset_dut__74__tb_ozone_backend__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_ozone_backend__DOT__reset_dut__74__tb_ozone_backend__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    IData/*31:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__77__idx;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__77__idx = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__77__value;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__77__value = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__77____Vlvbound_hee8445f9__0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__77____Vlvbound_hee8445f9__0 = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__77____Vlvbound_hee492a18__0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__77____Vlvbound_hee492a18__0 = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__77____Vlvbound_hffe4168d__0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__77____Vlvbound_hffe4168d__0 = 0;
    IData/*31:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__78__idx;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__78__idx = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__78__value;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__78__value = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__78____Vlvbound_hee8445f9__0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__78____Vlvbound_hee8445f9__0 = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__78____Vlvbound_hee492a18__0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__78____Vlvbound_hee492a18__0 = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__78____Vlvbound_hffe4168d__0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__78____Vlvbound_hffe4168d__0 = 0;
    IData/*31:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__79__idx;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__79__idx = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__79__value;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__79__value = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__79____Vlvbound_hee8445f9__0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__79____Vlvbound_hee8445f9__0 = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__79____Vlvbound_hee492a18__0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__79____Vlvbound_hee492a18__0 = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__79____Vlvbound_hffe4168d__0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__79____Vlvbound_hffe4168d__0 = 0;
    IData/*31:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__80__idx;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__80__idx = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__80__value;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__80__value = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__80____Vlvbound_hee8445f9__0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__80____Vlvbound_hee8445f9__0 = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__80____Vlvbound_hee492a18__0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__80____Vlvbound_hee492a18__0 = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__80____Vlvbound_hffe4168d__0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__80____Vlvbound_hffe4168d__0 = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__warmup_tag_zero__81__expected;
    __Vtask_tb_ozone_backend__DOT__warmup_tag_zero__81__expected = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__op;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__op = 0;
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__reg_a;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__reg_a = 0;
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__reg_b;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__reg_b = 0;
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__dest_reg;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__dest_reg = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__has_dest;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__has_dest = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__writes_nzcv;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__writes_nzcv = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__tag_out;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__tag_out = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__vj;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__vj = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__vk;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__vk = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__qj;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__qj = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__qk;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__qk = 0;
    VlWide<5>/*158:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__entry;
    VL_ZERO_W(159, __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__entry);
    VlWide<9>/*279:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__rob_entry;
    VL_ZERO_W(280, __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__rob_entry);
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__83__reg_a;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__83__reg_a = 0;
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__83__reg_b;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__83__reg_b = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__83__vj;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__83__vj = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__83__qj;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__83__qj = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__83__vk;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__83__vk = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__83__qk;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__83__qk = 0;
    IData/*31:0*/ __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__85__reg_idx;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__85__reg_idx = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__85__expected;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__85__expected = 0;
    IData/*31:0*/ __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__85__cycles;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__85__cycles = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__check_u64__86__got;
    __Vtask_tb_ozone_backend__DOT__check_u64__86__got = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__check_u64__86__expected;
    __Vtask_tb_ozone_backend__DOT__check_u64__86__expected = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__check_true__87__cond;
    __Vtask_tb_ozone_backend__DOT__check_true__87__cond = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__op;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__op = 0;
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__reg_a;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__reg_a = 0;
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__reg_b;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__reg_b = 0;
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__dest_reg;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__dest_reg = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__has_dest;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__has_dest = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__writes_nzcv;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__writes_nzcv = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__tag_out;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__tag_out = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__vj;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__vj = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__vk;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__vk = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__qj;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__qj = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__qk;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__qk = 0;
    VlWide<6>/*164:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__entry;
    VL_ZERO_W(165, __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__entry);
    VlWide<9>/*279:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__rob_entry;
    VL_ZERO_W(280, __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__rob_entry);
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__89__reg_a;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__89__reg_a = 0;
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__89__reg_b;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__89__reg_b = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__89__vj;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__89__vj = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__89__qj;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__89__qj = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__89__vk;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__89__vk = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__89__qk;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__89__qk = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__op;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__op = 0;
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__reg_a;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__reg_a = 0;
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__reg_b;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__reg_b = 0;
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__dest_reg;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__dest_reg = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__has_dest;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__has_dest = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__writes_nzcv;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__writes_nzcv = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__tag_out;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__tag_out = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__vj;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__vj = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__vk;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__vk = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__qj;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__qj = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__qk;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__qk = 0;
    VlWide<5>/*158:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__entry;
    VL_ZERO_W(159, __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__entry);
    VlWide<9>/*279:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__rob_entry;
    VL_ZERO_W(280, __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__rob_entry);
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__92__reg_a;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__92__reg_a = 0;
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__92__reg_b;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__92__reg_b = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__92__vj;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__92__vj = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__92__qj;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__92__qj = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__92__vk;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__92__vk = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__92__qk;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__92__qk = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__op;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__op = 0;
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__reg_a;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__reg_a = 0;
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__reg_b;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__reg_b = 0;
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__dest_reg;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__dest_reg = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__has_dest;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__has_dest = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__writes_nzcv;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__writes_nzcv = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__tag_out;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__tag_out = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__vj;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__vj = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__vk;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__vk = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__qj;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__qj = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__qk;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__qk = 0;
    VlWide<5>/*158:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__entry;
    VL_ZERO_W(159, __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__entry);
    VlWide<9>/*279:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__rob_entry;
    VL_ZERO_W(280, __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__rob_entry);
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__95__reg_a;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__95__reg_a = 0;
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__95__reg_b;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__95__reg_b = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__95__vj;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__95__vj = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__95__qj;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__95__qj = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__95__vk;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__95__vk = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__95__qk;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__95__qk = 0;
    IData/*31:0*/ __Vfunc_tb_ozone_backend__DOT__find_logic_slot__97__Vfuncout;
    __Vfunc_tb_ozone_backend__DOT__find_logic_slot__97__Vfuncout = 0;
    CData/*5:0*/ __Vfunc_tb_ozone_backend__DOT__find_logic_slot__97__tag;
    __Vfunc_tb_ozone_backend__DOT__find_logic_slot__97__tag = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__check_true__98__cond;
    __Vtask_tb_ozone_backend__DOT__check_true__98__cond = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__check_true__99__cond;
    __Vtask_tb_ozone_backend__DOT__check_true__99__cond = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__check_u64__100__got;
    __Vtask_tb_ozone_backend__DOT__check_u64__100__got = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__check_u64__100__expected;
    __Vtask_tb_ozone_backend__DOT__check_u64__100__expected = 0;
    IData/*31:0*/ __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__101__reg_idx;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__101__reg_idx = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__101__expected;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__101__expected = 0;
    IData/*31:0*/ __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__101__cycles;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__101__cycles = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__check_u64__102__got;
    __Vtask_tb_ozone_backend__DOT__check_u64__102__got = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__check_u64__102__expected;
    __Vtask_tb_ozone_backend__DOT__check_u64__102__expected = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__check_true__103__cond;
    __Vtask_tb_ozone_backend__DOT__check_true__103__cond = 0;
    IData/*31:0*/ __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__104__reg_idx;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__104__reg_idx = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__104__expected;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__104__expected = 0;
    IData/*31:0*/ __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__104__cycles;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__104__cycles = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__check_u64__105__got;
    __Vtask_tb_ozone_backend__DOT__check_u64__105__got = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__check_u64__105__expected;
    __Vtask_tb_ozone_backend__DOT__check_u64__105__expected = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__check_true__106__cond;
    __Vtask_tb_ozone_backend__DOT__check_true__106__cond = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__test_nzcv_and_bcond_forwarding__107__flags_tag;
    __Vtask_tb_ozone_backend__DOT__test_nzcv_and_bcond_forwarding__107__flags_tag = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__test_nzcv_and_bcond_forwarding__107__branch_tag;
    __Vtask_tb_ozone_backend__DOT__test_nzcv_and_bcond_forwarding__107__branch_tag = 0;
    IData/*31:0*/ __Vtask_tb_ozone_backend__DOT__test_nzcv_and_bcond_forwarding__107__branch_slot;
    __Vtask_tb_ozone_backend__DOT__test_nzcv_and_bcond_forwarding__107__branch_slot = 0;
    IData/*31:0*/ __Vtask_tb_ozone_backend__DOT__reset_dut__108__tb_ozone_backend__DOT__unnamedblk1_1__DOT____Vrepeat0;
    __Vtask_tb_ozone_backend__DOT__reset_dut__108__tb_ozone_backend__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    IData/*31:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__111__idx;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__111__idx = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__111__value;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__111__value = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__111____Vlvbound_hee8445f9__0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__111____Vlvbound_hee8445f9__0 = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__111____Vlvbound_hee492a18__0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__111____Vlvbound_hee492a18__0 = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__111____Vlvbound_hffe4168d__0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__111____Vlvbound_hffe4168d__0 = 0;
    IData/*31:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__112__idx;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__112__idx = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__112__value;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__112__value = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__112____Vlvbound_hee8445f9__0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__112____Vlvbound_hee8445f9__0 = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__112____Vlvbound_hee492a18__0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__112____Vlvbound_hee492a18__0 = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__112____Vlvbound_hffe4168d__0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__112____Vlvbound_hffe4168d__0 = 0;
    IData/*31:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__113__idx;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__113__idx = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__113__value;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__113__value = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__113____Vlvbound_hee8445f9__0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__113____Vlvbound_hee8445f9__0 = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__113____Vlvbound_hee492a18__0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__113____Vlvbound_hee492a18__0 = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__preload_gpr__113____Vlvbound_hffe4168d__0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__113____Vlvbound_hffe4168d__0 = 0;
    CData/*3:0*/ __Vtask_tb_ozone_backend__DOT__preload_nzcv__114__flags;
    __Vtask_tb_ozone_backend__DOT__preload_nzcv__114__flags = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__warmup_tag_zero__115__expected;
    __Vtask_tb_ozone_backend__DOT__warmup_tag_zero__115__expected = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__op;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__op = 0;
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__reg_a;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__reg_a = 0;
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__reg_b;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__reg_b = 0;
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__dest_reg;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__dest_reg = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__has_dest;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__has_dest = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__writes_nzcv;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__writes_nzcv = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__tag_out;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__tag_out = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__vj;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__vj = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__vk;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__vk = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__qj;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__qj = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__qk;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__qk = 0;
    VlWide<5>/*158:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__entry;
    VL_ZERO_W(159, __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__entry);
    VlWide<9>/*279:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__rob_entry;
    VL_ZERO_W(280, __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__rob_entry);
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__117__reg_a;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__117__reg_a = 0;
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__117__reg_b;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__117__reg_b = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__117__vj;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__117__vj = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__117__qj;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__117__qj = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__117__vk;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__117__vk = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__117__qk;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__117__qk = 0;
    IData/*31:0*/ __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__119__reg_idx;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__119__reg_idx = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__119__expected;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__119__expected = 0;
    IData/*31:0*/ __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__119__cycles;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__119__cycles = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__check_u64__120__got;
    __Vtask_tb_ozone_backend__DOT__check_u64__120__got = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__check_u64__120__expected;
    __Vtask_tb_ozone_backend__DOT__check_u64__120__expected = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__check_true__121__cond;
    __Vtask_tb_ozone_backend__DOT__check_true__121__cond = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__op;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__op = 0;
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__reg_a;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__reg_a = 0;
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__reg_b;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__reg_b = 0;
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__dest_reg;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__dest_reg = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__has_dest;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__has_dest = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__writes_nzcv;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__writes_nzcv = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__tag_out;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__tag_out = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__vj;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__vj = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__vk;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__vk = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__qj;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__qj = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__qk;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__qk = 0;
    VlWide<5>/*158:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__entry;
    VL_ZERO_W(159, __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__entry);
    VlWide<9>/*279:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__rob_entry;
    VL_ZERO_W(280, __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__rob_entry);
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__123__reg_a;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__123__reg_a = 0;
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__123__reg_b;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__123__reg_b = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__123__vj;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__123__vj = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__123__qj;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__123__qj = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__123__vk;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__123__vk = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__123__qk;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__123__qk = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__op;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__op = 0;
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__reg_a;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__reg_a = 0;
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__reg_b;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__reg_b = 0;
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__dest_reg;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__dest_reg = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__has_dest;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__has_dest = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__writes_nzcv;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__writes_nzcv = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__tag_out;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__tag_out = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__vj;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__vj = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__vk;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__vk = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__qj;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__qj = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__qk;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__qk = 0;
    VlWide<6>/*164:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__entry;
    VL_ZERO_W(165, __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__entry);
    VlWide<9>/*279:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__rob_entry;
    VL_ZERO_W(280, __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__rob_entry);
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__126__reg_a;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__126__reg_a = 0;
    CData/*4:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__126__reg_b;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__126__reg_b = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__126__vj;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__126__vj = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__126__qj;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__126__qj = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__126__vk;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__126__vk = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__126__qk;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__126__qk = 0;
    CData/*3:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__cond;
    __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__cond = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__branch_pc;
    __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__branch_pc = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__branch_off;
    __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__branch_off = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__tag_out;
    __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__tag_out = 0;
    CData/*3:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__flags;
    __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__flags = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__q_flags;
    __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__q_flags = 0;
    VlWide<6>/*164:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__entry;
    VL_ZERO_W(165, __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__entry);
    VlWide<9>/*279:0*/ __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__rob_entry;
    VL_ZERO_W(280, __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__rob_entry);
    CData/*3:0*/ __Vtask_tb_ozone_backend__DOT__resolve_nzcv_source__129__flags;
    __Vtask_tb_ozone_backend__DOT__resolve_nzcv_source__129__flags = 0;
    CData/*5:0*/ __Vtask_tb_ozone_backend__DOT__resolve_nzcv_source__129__q;
    __Vtask_tb_ozone_backend__DOT__resolve_nzcv_source__129__q = 0;
    IData/*31:0*/ __Vfunc_tb_ozone_backend__DOT__find_adder_slot__131__Vfuncout;
    __Vfunc_tb_ozone_backend__DOT__find_adder_slot__131__Vfuncout = 0;
    CData/*5:0*/ __Vfunc_tb_ozone_backend__DOT__find_adder_slot__131__tag;
    __Vfunc_tb_ozone_backend__DOT__find_adder_slot__131__tag = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__check_true__132__cond;
    __Vtask_tb_ozone_backend__DOT__check_true__132__cond = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__check_true__133__cond;
    __Vtask_tb_ozone_backend__DOT__check_true__133__cond = 0;
    CData/*3:0*/ __Vtask_tb_ozone_backend__DOT__check_u4__134__got;
    __Vtask_tb_ozone_backend__DOT__check_u4__134__got = 0;
    CData/*3:0*/ __Vtask_tb_ozone_backend__DOT__check_u4__134__expected;
    __Vtask_tb_ozone_backend__DOT__check_u4__134__expected = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__check_u64__135__got;
    __Vtask_tb_ozone_backend__DOT__check_u64__135__got = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__check_u64__135__expected;
    __Vtask_tb_ozone_backend__DOT__check_u64__135__expected = 0;
    IData/*31:0*/ __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__136__reg_idx;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__136__reg_idx = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__136__expected;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__136__expected = 0;
    IData/*31:0*/ __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__136__cycles;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__136__cycles = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__check_u64__137__got;
    __Vtask_tb_ozone_backend__DOT__check_u64__137__got = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__check_u64__137__expected;
    __Vtask_tb_ozone_backend__DOT__check_u64__137__expected = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__check_true__138__cond;
    __Vtask_tb_ozone_backend__DOT__check_true__138__cond = 0;
    CData/*3:0*/ __Vtask_tb_ozone_backend__DOT__wait_for_nzcv_value__139__expected;
    __Vtask_tb_ozone_backend__DOT__wait_for_nzcv_value__139__expected = 0;
    IData/*31:0*/ __Vtask_tb_ozone_backend__DOT__wait_for_nzcv_value__139__cycles;
    __Vtask_tb_ozone_backend__DOT__wait_for_nzcv_value__139__cycles = 0;
    CData/*3:0*/ __Vtask_tb_ozone_backend__DOT__check_u4__140__got;
    __Vtask_tb_ozone_backend__DOT__check_u4__140__got = 0;
    CData/*3:0*/ __Vtask_tb_ozone_backend__DOT__check_u4__140__expected;
    __Vtask_tb_ozone_backend__DOT__check_u4__140__expected = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__check_true__141__cond;
    __Vtask_tb_ozone_backend__DOT__check_true__141__cond = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__check_u64__142__got;
    __Vtask_tb_ozone_backend__DOT__check_u64__142__got = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__check_u64__142__expected;
    __Vtask_tb_ozone_backend__DOT__check_u64__142__expected = 0;
    CData/*0:0*/ __Vtask_tb_ozone_backend__DOT__check_true__143__cond;
    __Vtask_tb_ozone_backend__DOT__check_true__143__cond = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__check_u64__144__got;
    __Vtask_tb_ozone_backend__DOT__check_u64__144__got = 0;
    QData/*63:0*/ __Vtask_tb_ozone_backend__DOT__check_u64__144__expected;
    __Vtask_tb_ozone_backend__DOT__check_u64__144__expected = 0;
    // Body
    tb_ozone_backend__DOT__failures = 0U;
    VL_WRITEF_NX("Running reset and idle smoke\n",0);
    vlSelfRef.tb_ozone_backend__DOT__src1_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src1_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_en = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_wr_en = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__rob_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__alloc_has_dest = 0U;
    VL_ASSIGN_W(280, vlSelfRef.tb_ozone_backend__DOT__alloc_data, Vtb_ozone_backend__ConstPool__CONST_h083ec1be_0);
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[0U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[1U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[2U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[3U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[4U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[5U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[0U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[1U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[2U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[3U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[4U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__rst_n = 0U;
    __Vtask_tb_ozone_backend__DOT__reset_dut__2__tb_ozone_backend__DOT__unnamedblk1_1__DOT____Vrepeat0 = 3U;
    while (VL_LTS_III(32, 0U, __Vtask_tb_ozone_backend__DOT__reset_dut__2__tb_ozone_backend__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9782__0(vlSelf, 
                                                                "@(posedge tb_ozone_backend.clk)");
        co_await vlSelfRef.__VtrigSched_h0e5d9782__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_ozone_backend.clk)", 
                                                             "tb/tb_ozone_backend.sv", 
                                                             380);
        __Vtask_tb_ozone_backend__DOT__reset_dut__2__tb_ozone_backend__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (__Vtask_tb_ozone_backend__DOT__reset_dut__2__tb_ozone_backend__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    vlSelfRef.tb_ozone_backend__DOT__rst_n = 1U;
    Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9782__0(vlSelf, 
                                                            "@(posedge tb_ozone_backend.clk)");
    co_await vlSelfRef.__VtrigSched_h0e5d9782__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_ozone_backend.clk)", 
                                                         "tb/tb_ozone_backend.sv", 
                                                         382);
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_ozone_backend.sv", 
                                         383);
    vlSelfRef.tb_ozone_backend__DOT__src1_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src1_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_en = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_wr_en = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__rob_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__alloc_has_dest = 0U;
    VL_ASSIGN_W(280, vlSelfRef.tb_ozone_backend__DOT__alloc_data, Vtb_ozone_backend__ConstPool__CONST_h083ec1be_0);
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[0U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[1U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[2U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[3U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[4U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[5U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[0U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[1U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[2U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[3U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[4U] = 0U;
    vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_true__5__label = "rob count reset"s;
    __Vtask_tb_ozone_backend__DOT__check_true__5__cond 
        = (0U == (IData)(vlSelfRef.tb_ozone_backend__DOT__rob__DOT__count));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_ozone_backend__DOT__check_true__5__cond)))))) {
        tb_ozone_backend__DOT__failures = ((IData)(1U) 
                                           + tb_ozone_backend__DOT__failures);
        VL_WRITEF_NX("[FAIL] %@\n",0,-1,&(vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_true__5__label));
    }
    vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_true__6__label = "rob not full after reset"s;
    __Vtask_tb_ozone_backend__DOT__check_true__6__cond 
        = (0x40U != (IData)(vlSelfRef.tb_ozone_backend__DOT__rob__DOT__count));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_ozone_backend__DOT__check_true__6__cond)))))) {
        tb_ozone_backend__DOT__failures = ((IData)(1U) 
                                           + tb_ozone_backend__DOT__failures);
        VL_WRITEF_NX("[FAIL] %@\n",0,-1,&(vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_true__6__label));
    }
    vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_true__7__label = "no commit after reset"s;
    __Vtask_tb_ozone_backend__DOT__check_true__7__cond 
        = (1U & (~ (IData)(vlSelfRef.tb_ozone_backend__DOT__commit_valid)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_ozone_backend__DOT__check_true__7__cond)))))) {
        tb_ozone_backend__DOT__failures = ((IData)(1U) 
                                           + tb_ozone_backend__DOT__failures);
        VL_WRITEF_NX("[FAIL] %@\n",0,-1,&(vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_true__7__label));
    }
    vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_true__8__label = "cdb idle after reset"s;
    __Vtask_tb_ozone_backend__DOT__check_true__8__cond 
        = (1U & (~ (vlSelfRef.tb_ozone_backend__DOT__cdb_broadcast[4U] 
                    >> 0x00000016U)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_ozone_backend__DOT__check_true__8__cond)))))) {
        tb_ozone_backend__DOT__failures = ((IData)(1U) 
                                           + tb_ozone_backend__DOT__failures);
        VL_WRITEF_NX("[FAIL] %@\n",0,-1,&(vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_true__8__label));
    }
    vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_true__9__label = "adder request idle after reset"s;
    __Vtask_tb_ozone_backend__DOT__check_true__9__cond 
        = (1U & (~ (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__result[4U] 
                    >> 0x00000016U)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_ozone_backend__DOT__check_true__9__cond)))))) {
        tb_ozone_backend__DOT__failures = ((IData)(1U) 
                                           + tb_ozone_backend__DOT__failures);
        VL_WRITEF_NX("[FAIL] %@\n",0,-1,&(vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_true__9__label));
    }
    vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_true__10__label = "logic request idle after reset"s;
    __Vtask_tb_ozone_backend__DOT__check_true__10__cond 
        = (1U & (~ (vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__result[4U] 
                    >> 0x00000016U)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_ozone_backend__DOT__check_true__10__cond)))))) {
        tb_ozone_backend__DOT__failures = ((IData)(1U) 
                                           + tb_ozone_backend__DOT__failures);
        VL_WRITEF_NX("[FAIL] %@\n",0,-1,&(vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_true__10__label));
    }
    vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_true__11__label = "nzcv not busy after reset"s;
    __Vtask_tb_ozone_backend__DOT__check_true__11__cond 
        = (1U & (~ (vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__nzcv_reg[0U] 
                    >> 6U)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_ozone_backend__DOT__check_true__11__cond)))))) {
        tb_ozone_backend__DOT__failures = ((IData)(1U) 
                                           + tb_ozone_backend__DOT__failures);
        VL_WRITEF_NX("[FAIL] %@\n",0,-1,&(vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_true__11__label));
    }
    vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_true__12__label = "x1 not busy after reset"s;
    __Vtask_tb_ozone_backend__DOT__check_true__12__cond 
        = (1U & (~ (vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[1U][0U] 
                    >> 6U)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_ozone_backend__DOT__check_true__12__cond)))))) {
        tb_ozone_backend__DOT__failures = ((IData)(1U) 
                                           + tb_ozone_backend__DOT__failures);
        VL_WRITEF_NX("[FAIL] %@\n",0,-1,&(vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_true__12__label));
    }
    __Vtask_tb_ozone_backend__DOT__test_basic_adder_commit__13__add_tag = 0;
    VL_WRITEF_NX("Running basic adder commit\n",0);
    __Vtask_tb_ozone_backend__DOT__reset_dut__14__tb_ozone_backend__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    vlSelfRef.tb_ozone_backend__DOT__src1_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src1_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_en = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_wr_en = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__rob_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__alloc_has_dest = 0U;
    VL_ASSIGN_W(280, vlSelfRef.tb_ozone_backend__DOT__alloc_data, Vtb_ozone_backend__ConstPool__CONST_h083ec1be_0);
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[0U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[1U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[2U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[3U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[4U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[5U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[0U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[1U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[2U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[3U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[4U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__rst_n = 0U;
    __Vtask_tb_ozone_backend__DOT__reset_dut__14__tb_ozone_backend__DOT__unnamedblk1_1__DOT____Vrepeat0 = 3U;
    while (VL_LTS_III(32, 0U, __Vtask_tb_ozone_backend__DOT__reset_dut__14__tb_ozone_backend__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9782__0(vlSelf, 
                                                                "@(posedge tb_ozone_backend.clk)");
        co_await vlSelfRef.__VtrigSched_h0e5d9782__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_ozone_backend.clk)", 
                                                             "tb/tb_ozone_backend.sv", 
                                                             380);
        __Vtask_tb_ozone_backend__DOT__reset_dut__14__tb_ozone_backend__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (__Vtask_tb_ozone_backend__DOT__reset_dut__14__tb_ozone_backend__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    vlSelfRef.tb_ozone_backend__DOT__rst_n = 1U;
    Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9782__0(vlSelf, 
                                                            "@(posedge tb_ozone_backend.clk)");
    co_await vlSelfRef.__VtrigSched_h0e5d9782__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_ozone_backend.clk)", 
                                                         "tb/tb_ozone_backend.sv", 
                                                         382);
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_ozone_backend.sv", 
                                         383);
    vlSelfRef.tb_ozone_backend__DOT__src1_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src1_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_en = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_wr_en = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__rob_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__alloc_has_dest = 0U;
    VL_ASSIGN_W(280, vlSelfRef.tb_ozone_backend__DOT__alloc_data, Vtb_ozone_backend__ConstPool__CONST_h083ec1be_0);
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[0U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[1U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[2U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[3U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[4U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[5U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[0U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[1U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[2U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[3U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[4U] = 0U;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__17__value = 0x000000000000000aULL;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__17__idx = 1U;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__17____Vlvbound_hee8445f9__0 = 0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__17____Vlvbound_hee492a18__0 = 0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__17____Vlvbound_hffe4168d__0 = 0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__17____Vlvbound_hffe4168d__0 
        = __Vtask_tb_ozone_backend__DOT__preload_gpr__17__value;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__17____Vlvbound_hee492a18__0 = 0U;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__17____Vlvbound_hee8445f9__0 = 0U;
    if (VL_LIKELY(((0x1eU >= (0x0000001fU & __Vtask_tb_ozone_backend__DOT__preload_gpr__17__idx))))) {
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__17__idx)][0U] 
            = ((0x0000007fU & vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                [(0x0000001fU & __Vtask_tb_ozone_backend__DOT__preload_gpr__17__idx)][0U]) 
               | ((IData)(__Vtask_tb_ozone_backend__DOT__preload_gpr__17____Vlvbound_hffe4168d__0) 
                  << 7U));
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__17__idx)][1U] 
            = (((IData)(__Vtask_tb_ozone_backend__DOT__preload_gpr__17____Vlvbound_hffe4168d__0) 
                >> 0x00000019U) | ((IData)((__Vtask_tb_ozone_backend__DOT__preload_gpr__17____Vlvbound_hffe4168d__0 
                                            >> 0x00000020U)) 
                                   << 7U));
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__17__idx)][2U] 
            = ((IData)((__Vtask_tb_ozone_backend__DOT__preload_gpr__17____Vlvbound_hffe4168d__0 
                        >> 0x00000020U)) >> 0x00000019U);
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__17__idx)][0U] 
            = ((0xffffffbfU & vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                [(0x0000001fU & __Vtask_tb_ozone_backend__DOT__preload_gpr__17__idx)][0U]) 
               | ((IData)(__Vtask_tb_ozone_backend__DOT__preload_gpr__17____Vlvbound_hee492a18__0) 
                  << 6U));
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__17__idx)][0U] 
            = ((0xffffffc0U & vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                [(0x0000001fU & __Vtask_tb_ozone_backend__DOT__preload_gpr__17__idx)][0U]) 
               | (IData)(__Vtask_tb_ozone_backend__DOT__preload_gpr__17____Vlvbound_hee8445f9__0));
    }
    __Vtask_tb_ozone_backend__DOT__preload_gpr__18__value = 7ULL;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__18__idx = 2U;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__18____Vlvbound_hee8445f9__0 = 0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__18____Vlvbound_hee492a18__0 = 0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__18____Vlvbound_hffe4168d__0 = 0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__18____Vlvbound_hffe4168d__0 
        = __Vtask_tb_ozone_backend__DOT__preload_gpr__18__value;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__18____Vlvbound_hee492a18__0 = 0U;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__18____Vlvbound_hee8445f9__0 = 0U;
    if (VL_LIKELY(((0x1eU >= (0x0000001fU & __Vtask_tb_ozone_backend__DOT__preload_gpr__18__idx))))) {
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__18__idx)][0U] 
            = ((0x0000007fU & vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                [(0x0000001fU & __Vtask_tb_ozone_backend__DOT__preload_gpr__18__idx)][0U]) 
               | ((IData)(__Vtask_tb_ozone_backend__DOT__preload_gpr__18____Vlvbound_hffe4168d__0) 
                  << 7U));
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__18__idx)][1U] 
            = (((IData)(__Vtask_tb_ozone_backend__DOT__preload_gpr__18____Vlvbound_hffe4168d__0) 
                >> 0x00000019U) | ((IData)((__Vtask_tb_ozone_backend__DOT__preload_gpr__18____Vlvbound_hffe4168d__0 
                                            >> 0x00000020U)) 
                                   << 7U));
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__18__idx)][2U] 
            = ((IData)((__Vtask_tb_ozone_backend__DOT__preload_gpr__18____Vlvbound_hffe4168d__0 
                        >> 0x00000020U)) >> 0x00000019U);
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__18__idx)][0U] 
            = ((0xffffffbfU & vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                [(0x0000001fU & __Vtask_tb_ozone_backend__DOT__preload_gpr__18__idx)][0U]) 
               | ((IData)(__Vtask_tb_ozone_backend__DOT__preload_gpr__18____Vlvbound_hee492a18__0) 
                  << 6U));
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__18__idx)][0U] 
            = ((0xffffffc0U & vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                [(0x0000001fU & __Vtask_tb_ozone_backend__DOT__preload_gpr__18__idx)][0U]) 
               | (IData)(__Vtask_tb_ozone_backend__DOT__preload_gpr__18____Vlvbound_hee8445f9__0));
    }
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__writes_nzcv = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__has_dest = 1U;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__dest_reg = 3U;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__reg_b = 2U;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__reg_a = 1U;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__op = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__tag_out = 0;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__vj = 0;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__vk = 0;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__qj = 0;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__qk = 0;
    VL_ZERO_W(165, __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__entry);
    VL_ZERO_W(280, __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__rob_entry);
    while (((0x40U == (IData)(vlSelfRef.tb_ozone_backend__DOT__rob__DOT__count)) 
            | (IData)(vlSelfRef.tb_ozone_backend__DOT__adder_full))) {
        Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9448__0(vlSelf, 
                                                                "@(negedge tb_ozone_backend.clk)");
        co_await vlSelfRef.__VtrigSched_h0e5d9448__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_ozone_backend.clk)", 
                                                             "tb/tb_ozone_backend.sv", 
                                                             522);
    }
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__20__reg_b 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__reg_b;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__20__reg_a 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__reg_a;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__20__vj = 0;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__20__qj = 0;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__20__vk = 0;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__20__qk = 0;
    vlSelfRef.tb_ozone_backend__DOT__src1_addr = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__20__reg_a;
    vlSelfRef.tb_ozone_backend__DOT__src2_addr = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__20__reg_b;
    vlSelfRef.tb_ozone_backend__DOT__src1_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_rob_idx = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_ozone_backend.sv", 
                                         452);
    vlSelfRef.tb_ozone_backend__DOT__src1_rob_idx = 
        (0x0000003fU & vlSelfRef.tb_ozone_backend__DOT__src1_status[0U]);
    vlSelfRef.tb_ozone_backend__DOT__src2_rob_idx = 
        (0x0000003fU & vlSelfRef.tb_ozone_backend__DOT__src2_status[0U]);
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_ozone_backend.sv", 
                                         456);
    if ((0x00000040U & vlSelfRef.tb_ozone_backend__DOT__src1_status[0U])) {
        if (vlSelfRef.tb_ozone_backend__DOT__src1_ready) {
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__20__vj 
                = vlSelfRef.tb_ozone_backend__DOT__src1_value;
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__20__qj = 0U;
        } else {
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__20__vj = 0ULL;
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__20__qj 
                = (0x0000003fU & vlSelfRef.tb_ozone_backend__DOT__src1_status[0U]);
        }
    } else {
        __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__20__vj 
            = (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src1_status[2U])) 
                << 0x00000039U) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src1_status[1U])) 
                                    << 0x00000019U) 
                                   | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src1_status[0U])) 
                                      >> 7U)));
        __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__20__qj = 0U;
    }
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__vj 
        = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__20__vj;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__qj 
        = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__20__qj;
    if ((0x00000040U & vlSelfRef.tb_ozone_backend__DOT__src2_status[0U])) {
        if (vlSelfRef.tb_ozone_backend__DOT__src2_ready) {
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__20__vk 
                = vlSelfRef.tb_ozone_backend__DOT__src2_value;
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__20__qk = 0U;
        } else {
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__20__vk = 0ULL;
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__20__qk 
                = (0x0000003fU & vlSelfRef.tb_ozone_backend__DOT__src2_status[0U]);
        }
    } else {
        __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__20__vk 
            = (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src2_status[2U])) 
                << 0x00000039U) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src2_status[1U])) 
                                    << 0x00000019U) 
                                   | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src2_status[0U])) 
                                      >> 7U)));
        __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__20__qk = 0U;
    }
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__vk 
        = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__20__vk;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__qk 
        = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__20__qk;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__tag_out 
        = vlSelfRef.tb_ozone_backend__DOT__rob__DOT__tail;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__entry[0U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__entry[1U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__entry[2U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__entry[3U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__entry[4U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__entry[5U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__entry[0U] 
        = ((0x0003ffffU & __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__entry[0U]) 
           | (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__qj) 
               << 0x0000001eU) | (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__qk) 
                                   << 0x00000018U) 
                                  | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__tag_out) 
                                     << 0x00000012U))));
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__entry[1U] 
        = (((0x0003fff0U & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__vk) 
                            << 4U)) | ((0x0003ffffU 
                                        & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__qj) 
                                           >> 2U)) 
                                       | ((0x0003ffffU 
                                           & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__qk) 
                                              >> 8U)) 
                                          | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__tag_out) 
                                             >> 0x0000000eU)))) 
           | (0xfffc0000U & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__vk) 
                             << 4U)));
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__entry[2U] 
        = ((((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__vk) 
             >> 0x0000001cU) | (0x0003fff0U & ((IData)(
                                                       (__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__vk 
                                                        >> 0x00000020U)) 
                                               << 4U))) 
           | (0xfffc0000U & ((IData)((__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__vk 
                                      >> 0x00000020U)) 
                             << 4U)));
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__entry[3U] 
        = ((0xfffffff0U & __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__entry[3U]) 
           | ((IData)((__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__vk 
                       >> 0x00000020U)) >> 0x0000001cU));
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__entry[3U] 
        = ((0x0000000fU & __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__entry[3U]) 
           | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__vj) 
              << 4U));
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__entry[4U] 
        = (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__vj) 
            >> 0x0000001cU) | ((IData)((__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__vj 
                                        >> 0x00000020U)) 
                               << 4U));
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__entry[5U] 
        = ((0x00000010U & __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__entry[5U]) 
           | (0x0000001fU & ((IData)((__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__vj 
                                      >> 0x00000020U)) 
                             >> 0x0000001cU)));
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__entry[0U] 
        = ((0xfffe0007U & __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__entry[0U]) 
           | (0xfffffff8U & (0x00000070U | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__op) 
                                            << 0x0000000bU))));
    VL_ASSIGN_W(280, __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__rob_entry, Vtb_ozone_backend__ConstPool__CONST_h083ec1be_0);
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__rob_entry[8U] 
        = ((0x00801fffU & __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__rob_entry[8U]) 
           | (0x00ffe000U & (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__dest_reg) 
                              << 0x00000010U) | ((((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__has_dest)
                                                    ? 1U
                                                    : 0U) 
                                                  << 0x0000000eU) 
                                                 | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__has_dest) 
                                                    << 0x0000000dU)))));
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__rob_entry[6U] 
        = ((0xffffefffU & __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__rob_entry[6U]) 
           | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__writes_nzcv) 
              << 0x0000000cU));
    Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9448__0(vlSelf, 
                                                            "@(negedge tb_ozone_backend.clk)");
    co_await vlSelfRef.__VtrigSched_h0e5d9448__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_ozone_backend.clk)", 
                                                         "tb/tb_ozone_backend.sv", 
                                                         543);
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[0U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__rob_entry[0U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[1U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__rob_entry[1U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[2U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__rob_entry[2U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[3U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__rob_entry[3U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[4U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__rob_entry[4U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[5U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__rob_entry[5U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[6U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__rob_entry[6U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[7U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__rob_entry[7U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[8U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__rob_entry[8U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_has_dest 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__has_dest;
    vlSelfRef.tb_ozone_backend__DOT__rob_alloc_valid = 1U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[0U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__entry[0U];
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[1U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__entry[1U];
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[2U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__entry[2U];
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[3U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__entry[3U];
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[4U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__entry[4U];
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[5U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__entry[5U];
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_valid = 1U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_en = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__has_dest;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_addr = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__dest_reg;
    vlSelfRef.tb_ozone_backend__DOT__disp_rob_idx = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__tag_out;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_wr_en 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__writes_nzcv;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_rob_idx 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__tag_out;
    Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9782__0(vlSelf, 
                                                            "@(posedge tb_ozone_backend.clk)");
    co_await vlSelfRef.__VtrigSched_h0e5d9782__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_ozone_backend.clk)", 
                                                         "tb/tb_ozone_backend.sv", 
                                                         554);
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_ozone_backend.sv", 
                                         555);
    vlSelfRef.tb_ozone_backend__DOT__src1_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src1_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_en = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_wr_en = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__rob_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__alloc_has_dest = 0U;
    VL_ASSIGN_W(280, vlSelfRef.tb_ozone_backend__DOT__alloc_data, Vtb_ozone_backend__ConstPool__CONST_h083ec1be_0);
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[0U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[1U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[2U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[3U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[4U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[5U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[0U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[1U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[2U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[3U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[4U] = 0U;
    __Vtask_tb_ozone_backend__DOT__test_basic_adder_commit__13__add_tag 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__19__tag_out;
    vlSelfRef.__Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__22__label = "adder commit x3"s;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__22__expected = 0x0000000000000011ULL;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__22__reg_idx = 3U;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__22__cycles = 0U;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__22__cycles = 0U;
    while (((((((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                                [((0x1eU >= (0x0000001fU 
                                             & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__22__reg_idx))
                                   ? (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__22__reg_idx)
                                   : 0U)][2U])) << 0x00000039U) 
               | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                                   [((0x1eU >= (0x0000001fU 
                                                & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__22__reg_idx))
                                      ? (0x0000001fU 
                                         & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__22__reg_idx)
                                      : 0U)][1U])) 
                   << 0x00000019U) | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                                                      [
                                                      ((0x1eU 
                                                        >= 
                                                        (0x0000001fU 
                                                         & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__22__reg_idx))
                                                        ? 
                                                       (0x0000001fU 
                                                        & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__22__reg_idx)
                                                        : 0U)][0U])) 
                                      >> 7U))) != __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__22__expected) 
             | (vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                [((0x1eU >= (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__22__reg_idx))
                   ? (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__22__reg_idx)
                   : 0U)][0U] >> 6U)) & VL_GTS_III(32, 0x00000028U, __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__22__cycles))) {
        Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9782__0(vlSelf, 
                                                                "@(posedge tb_ozone_backend.clk)");
        co_await vlSelfRef.__VtrigSched_h0e5d9782__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_ozone_backend.clk)", 
                                                             "tb/tb_ozone_backend.sv", 
                                                             691);
        co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                             nullptr, 
                                             "tb/tb_ozone_backend.sv", 
                                             692);
        __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__22__cycles 
            = ((IData)(1U) + __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__22__cycles);
    }
    vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_u64__23__label 
        = vlSelfRef.__Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__22__label;
    __Vtask_tb_ozone_backend__DOT__check_u64__23__expected 
        = __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__22__expected;
    __Vtask_tb_ozone_backend__DOT__check_u64__23__got 
        = (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                            [((0x1eU >= (0x0000001fU 
                                         & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__22__reg_idx))
                               ? (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__22__reg_idx)
                               : 0U)][2U])) << 0x00000039U) 
           | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                               [((0x1eU >= (0x0000001fU 
                                            & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__22__reg_idx))
                                  ? (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__22__reg_idx)
                                  : 0U)][1U])) << 0x00000019U) 
              | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                                 [((0x1eU >= (0x0000001fU 
                                              & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__22__reg_idx))
                                    ? (0x0000001fU 
                                       & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__22__reg_idx)
                                    : 0U)][0U])) >> 7U)));
    if (VL_UNLIKELY(((__Vtask_tb_ozone_backend__DOT__check_u64__23__got 
                      != __Vtask_tb_ozone_backend__DOT__check_u64__23__expected)))) {
        tb_ozone_backend__DOT__failures = ((IData)(1U) 
                                           + tb_ozone_backend__DOT__failures);
        VL_WRITEF_NX("[FAIL] %@ expected=0x%016x got=0x%016x\n",0,
                     -1,&(vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_u64__23__label),
                     64,__Vtask_tb_ozone_backend__DOT__check_u64__23__expected,
                     64,__Vtask_tb_ozone_backend__DOT__check_u64__23__got);
    }
    vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_true__24__label 
        = VL_CVT_PACK_STR_NN(VL_CONCATN_NNN(vlSelfRef.__Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__22__label, " busy clear"s));
    __Vtask_tb_ozone_backend__DOT__check_true__24__cond 
        = (1U & (~ (vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                    [((0x1eU >= (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__22__reg_idx))
                       ? (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__22__reg_idx)
                       : 0U)][0U] >> 6U)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_ozone_backend__DOT__check_true__24__cond)))))) {
        tb_ozone_backend__DOT__failures = ((IData)(1U) 
                                           + tb_ozone_backend__DOT__failures);
        VL_WRITEF_NX("[FAIL] %@\n",0,-1,&(vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_true__24__label));
    }
    vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_true__25__label = "adder rob entry became ready"s;
    __Vtask_tb_ozone_backend__DOT__check_true__25__cond 
        = (1U & (vlSelfRef.tb_ozone_backend__DOT__rob__DOT__rob_entries
                 [__Vtask_tb_ozone_backend__DOT__test_basic_adder_commit__13__add_tag][6U] 
                 >> 7U));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_ozone_backend__DOT__check_true__25__cond)))))) {
        tb_ozone_backend__DOT__failures = ((IData)(1U) 
                                           + tb_ozone_backend__DOT__failures);
        VL_WRITEF_NX("[FAIL] %@\n",0,-1,&(vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_true__25__label));
    }
    __Vtask_tb_ozone_backend__DOT__test_basic_logic_commit__26__logic_tag = 0;
    VL_WRITEF_NX("Running basic logic commit\n",0);
    __Vtask_tb_ozone_backend__DOT__reset_dut__27__tb_ozone_backend__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    vlSelfRef.tb_ozone_backend__DOT__src1_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src1_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_en = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_wr_en = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__rob_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__alloc_has_dest = 0U;
    VL_ASSIGN_W(280, vlSelfRef.tb_ozone_backend__DOT__alloc_data, Vtb_ozone_backend__ConstPool__CONST_h083ec1be_0);
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[0U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[1U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[2U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[3U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[4U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[5U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[0U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[1U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[2U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[3U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[4U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__rst_n = 0U;
    __Vtask_tb_ozone_backend__DOT__reset_dut__27__tb_ozone_backend__DOT__unnamedblk1_1__DOT____Vrepeat0 = 3U;
    while (VL_LTS_III(32, 0U, __Vtask_tb_ozone_backend__DOT__reset_dut__27__tb_ozone_backend__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9782__0(vlSelf, 
                                                                "@(posedge tb_ozone_backend.clk)");
        co_await vlSelfRef.__VtrigSched_h0e5d9782__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_ozone_backend.clk)", 
                                                             "tb/tb_ozone_backend.sv", 
                                                             380);
        __Vtask_tb_ozone_backend__DOT__reset_dut__27__tb_ozone_backend__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (__Vtask_tb_ozone_backend__DOT__reset_dut__27__tb_ozone_backend__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    vlSelfRef.tb_ozone_backend__DOT__rst_n = 1U;
    Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9782__0(vlSelf, 
                                                            "@(posedge tb_ozone_backend.clk)");
    co_await vlSelfRef.__VtrigSched_h0e5d9782__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_ozone_backend.clk)", 
                                                         "tb/tb_ozone_backend.sv", 
                                                         382);
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_ozone_backend.sv", 
                                         383);
    vlSelfRef.tb_ozone_backend__DOT__src1_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src1_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_en = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_wr_en = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__rob_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__alloc_has_dest = 0U;
    VL_ASSIGN_W(280, vlSelfRef.tb_ozone_backend__DOT__alloc_data, Vtb_ozone_backend__ConstPool__CONST_h083ec1be_0);
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[0U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[1U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[2U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[3U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[4U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[5U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[0U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[1U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[2U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[3U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[4U] = 0U;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__30__value = 0x000000000000f0f0ULL;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__30__idx = 1U;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__30____Vlvbound_hee8445f9__0 = 0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__30____Vlvbound_hee492a18__0 = 0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__30____Vlvbound_hffe4168d__0 = 0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__30____Vlvbound_hffe4168d__0 
        = __Vtask_tb_ozone_backend__DOT__preload_gpr__30__value;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__30____Vlvbound_hee492a18__0 = 0U;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__30____Vlvbound_hee8445f9__0 = 0U;
    if (VL_LIKELY(((0x1eU >= (0x0000001fU & __Vtask_tb_ozone_backend__DOT__preload_gpr__30__idx))))) {
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__30__idx)][0U] 
            = ((0x0000007fU & vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                [(0x0000001fU & __Vtask_tb_ozone_backend__DOT__preload_gpr__30__idx)][0U]) 
               | ((IData)(__Vtask_tb_ozone_backend__DOT__preload_gpr__30____Vlvbound_hffe4168d__0) 
                  << 7U));
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__30__idx)][1U] 
            = (((IData)(__Vtask_tb_ozone_backend__DOT__preload_gpr__30____Vlvbound_hffe4168d__0) 
                >> 0x00000019U) | ((IData)((__Vtask_tb_ozone_backend__DOT__preload_gpr__30____Vlvbound_hffe4168d__0 
                                            >> 0x00000020U)) 
                                   << 7U));
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__30__idx)][2U] 
            = ((IData)((__Vtask_tb_ozone_backend__DOT__preload_gpr__30____Vlvbound_hffe4168d__0 
                        >> 0x00000020U)) >> 0x00000019U);
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__30__idx)][0U] 
            = ((0xffffffbfU & vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                [(0x0000001fU & __Vtask_tb_ozone_backend__DOT__preload_gpr__30__idx)][0U]) 
               | ((IData)(__Vtask_tb_ozone_backend__DOT__preload_gpr__30____Vlvbound_hee492a18__0) 
                  << 6U));
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__30__idx)][0U] 
            = ((0xffffffc0U & vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                [(0x0000001fU & __Vtask_tb_ozone_backend__DOT__preload_gpr__30__idx)][0U]) 
               | (IData)(__Vtask_tb_ozone_backend__DOT__preload_gpr__30____Vlvbound_hee8445f9__0));
    }
    __Vtask_tb_ozone_backend__DOT__preload_gpr__31__value = 0x0000000000000ff0ULL;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__31__idx = 2U;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__31____Vlvbound_hee8445f9__0 = 0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__31____Vlvbound_hee492a18__0 = 0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__31____Vlvbound_hffe4168d__0 = 0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__31____Vlvbound_hffe4168d__0 
        = __Vtask_tb_ozone_backend__DOT__preload_gpr__31__value;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__31____Vlvbound_hee492a18__0 = 0U;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__31____Vlvbound_hee8445f9__0 = 0U;
    if (VL_LIKELY(((0x1eU >= (0x0000001fU & __Vtask_tb_ozone_backend__DOT__preload_gpr__31__idx))))) {
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__31__idx)][0U] 
            = ((0x0000007fU & vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                [(0x0000001fU & __Vtask_tb_ozone_backend__DOT__preload_gpr__31__idx)][0U]) 
               | ((IData)(__Vtask_tb_ozone_backend__DOT__preload_gpr__31____Vlvbound_hffe4168d__0) 
                  << 7U));
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__31__idx)][1U] 
            = (((IData)(__Vtask_tb_ozone_backend__DOT__preload_gpr__31____Vlvbound_hffe4168d__0) 
                >> 0x00000019U) | ((IData)((__Vtask_tb_ozone_backend__DOT__preload_gpr__31____Vlvbound_hffe4168d__0 
                                            >> 0x00000020U)) 
                                   << 7U));
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__31__idx)][2U] 
            = ((IData)((__Vtask_tb_ozone_backend__DOT__preload_gpr__31____Vlvbound_hffe4168d__0 
                        >> 0x00000020U)) >> 0x00000019U);
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__31__idx)][0U] 
            = ((0xffffffbfU & vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                [(0x0000001fU & __Vtask_tb_ozone_backend__DOT__preload_gpr__31__idx)][0U]) 
               | ((IData)(__Vtask_tb_ozone_backend__DOT__preload_gpr__31____Vlvbound_hee492a18__0) 
                  << 6U));
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__31__idx)][0U] 
            = ((0xffffffc0U & vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                [(0x0000001fU & __Vtask_tb_ozone_backend__DOT__preload_gpr__31__idx)][0U]) 
               | (IData)(__Vtask_tb_ozone_backend__DOT__preload_gpr__31____Vlvbound_hee8445f9__0));
    }
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__writes_nzcv = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__has_dest = 1U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__dest_reg = 4U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__reg_b = 2U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__reg_a = 1U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__op = 7U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__tag_out = 0;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__vj = 0;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__vk = 0;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__qj = 0;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__qk = 0;
    VL_ZERO_W(159, __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__entry);
    VL_ZERO_W(280, __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__rob_entry);
    while (((0x40U == (IData)(vlSelfRef.tb_ozone_backend__DOT__rob__DOT__count)) 
            | (IData)(vlSelfRef.tb_ozone_backend__DOT__logic_full))) {
        Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9448__0(vlSelf, 
                                                                "@(negedge tb_ozone_backend.clk)");
        co_await vlSelfRef.__VtrigSched_h0e5d9448__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_ozone_backend.clk)", 
                                                             "tb/tb_ozone_backend.sv", 
                                                             576);
    }
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__33__reg_b 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__reg_b;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__33__reg_a 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__reg_a;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__33__vj = 0;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__33__qj = 0;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__33__vk = 0;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__33__qk = 0;
    vlSelfRef.tb_ozone_backend__DOT__src1_addr = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__33__reg_a;
    vlSelfRef.tb_ozone_backend__DOT__src2_addr = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__33__reg_b;
    vlSelfRef.tb_ozone_backend__DOT__src1_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_rob_idx = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_ozone_backend.sv", 
                                         452);
    vlSelfRef.tb_ozone_backend__DOT__src1_rob_idx = 
        (0x0000003fU & vlSelfRef.tb_ozone_backend__DOT__src1_status[0U]);
    vlSelfRef.tb_ozone_backend__DOT__src2_rob_idx = 
        (0x0000003fU & vlSelfRef.tb_ozone_backend__DOT__src2_status[0U]);
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_ozone_backend.sv", 
                                         456);
    if ((0x00000040U & vlSelfRef.tb_ozone_backend__DOT__src1_status[0U])) {
        if (vlSelfRef.tb_ozone_backend__DOT__src1_ready) {
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__33__vj 
                = vlSelfRef.tb_ozone_backend__DOT__src1_value;
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__33__qj = 0U;
        } else {
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__33__vj = 0ULL;
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__33__qj 
                = (0x0000003fU & vlSelfRef.tb_ozone_backend__DOT__src1_status[0U]);
        }
    } else {
        __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__33__vj 
            = (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src1_status[2U])) 
                << 0x00000039U) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src1_status[1U])) 
                                    << 0x00000019U) 
                                   | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src1_status[0U])) 
                                      >> 7U)));
        __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__33__qj = 0U;
    }
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__vj 
        = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__33__vj;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__qj 
        = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__33__qj;
    if ((0x00000040U & vlSelfRef.tb_ozone_backend__DOT__src2_status[0U])) {
        if (vlSelfRef.tb_ozone_backend__DOT__src2_ready) {
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__33__vk 
                = vlSelfRef.tb_ozone_backend__DOT__src2_value;
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__33__qk = 0U;
        } else {
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__33__vk = 0ULL;
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__33__qk 
                = (0x0000003fU & vlSelfRef.tb_ozone_backend__DOT__src2_status[0U]);
        }
    } else {
        __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__33__vk 
            = (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src2_status[2U])) 
                << 0x00000039U) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src2_status[1U])) 
                                    << 0x00000019U) 
                                   | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src2_status[0U])) 
                                      >> 7U)));
        __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__33__qk = 0U;
    }
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__vk 
        = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__33__vk;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__qk 
        = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__33__qk;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__tag_out 
        = vlSelfRef.tb_ozone_backend__DOT__rob__DOT__tail;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__entry[0U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__entry[1U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__entry[2U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__entry[3U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__entry[4U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__entry[0U] 
        = ((0x00000fffU & __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__entry[0U]) 
           | (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__vk) 
               << 0x0000001eU) | (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__qj) 
                                   << 0x00000018U) 
                                  | (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__qk) 
                                      << 0x00000012U) 
                                     | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__tag_out) 
                                        << 0x0000000cU)))));
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__entry[1U] 
        = (((0x00000fffU & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__vk) 
                            >> 2U)) | ((0x00000fffU 
                                        & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__qj) 
                                           >> 8U)) 
                                       | ((0x00000fffU 
                                           & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__qk) 
                                              >> 0x0000000eU)) 
                                          | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__tag_out) 
                                             >> 0x00000014U)))) 
           | ((0x3ffff000U & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__vk) 
                              >> 2U)) | ((IData)((__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__vk 
                                                  >> 0x00000020U)) 
                                         << 0x0000001eU)));
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__entry[2U] 
        = ((0xc0000000U & __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__entry[2U]) 
           | ((0x00000fffU & ((IData)((__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__vk 
                                       >> 0x00000020U)) 
                              >> 2U)) | (0x3ffff000U 
                                         & ((IData)(
                                                    (__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__vk 
                                                     >> 0x00000020U)) 
                                            >> 2U))));
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__entry[2U] 
        = ((0x3fffffffU & __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__entry[2U]) 
           | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__vj) 
              << 0x0000001eU));
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__entry[3U] 
        = (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__vj) 
            >> 2U) | ((IData)((__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__vj 
                               >> 0x00000020U)) << 0x0000001eU));
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__entry[4U] 
        = ((0x40000000U & __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__entry[4U]) 
           | (0x7fffffffU & ((IData)((__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__vj 
                                      >> 0x00000020U)) 
                             >> 2U)));
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__entry[0U] 
        = ((0xfffff801U & __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__entry[0U]) 
           | (0xfffffffeU & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__op) 
                             << 5U)));
    VL_ASSIGN_W(280, __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__rob_entry, Vtb_ozone_backend__ConstPool__CONST_h083ec1be_0);
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__rob_entry[8U] 
        = ((0x00801fffU & __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__rob_entry[8U]) 
           | (0x00ffe000U & (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__dest_reg) 
                              << 0x00000010U) | ((((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__has_dest)
                                                    ? 1U
                                                    : 0U) 
                                                  << 0x0000000eU) 
                                                 | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__has_dest) 
                                                    << 0x0000000dU)))));
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__rob_entry[6U] 
        = ((0xffffefffU & __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__rob_entry[6U]) 
           | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__writes_nzcv) 
              << 0x0000000cU));
    Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9448__0(vlSelf, 
                                                            "@(negedge tb_ozone_backend.clk)");
    co_await vlSelfRef.__VtrigSched_h0e5d9448__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_ozone_backend.clk)", 
                                                         "tb/tb_ozone_backend.sv", 
                                                         596);
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[0U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__rob_entry[0U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[1U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__rob_entry[1U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[2U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__rob_entry[2U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[3U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__rob_entry[3U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[4U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__rob_entry[4U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[5U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__rob_entry[5U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[6U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__rob_entry[6U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[7U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__rob_entry[7U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[8U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__rob_entry[8U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_has_dest 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__has_dest;
    vlSelfRef.tb_ozone_backend__DOT__rob_alloc_valid = 1U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[0U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__entry[0U];
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[1U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__entry[1U];
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[2U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__entry[2U];
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[3U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__entry[3U];
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[4U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__entry[4U];
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_valid = 1U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_en = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__has_dest;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_addr = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__dest_reg;
    vlSelfRef.tb_ozone_backend__DOT__disp_rob_idx = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__tag_out;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_wr_en 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__writes_nzcv;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_rob_idx 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__tag_out;
    Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9782__0(vlSelf, 
                                                            "@(posedge tb_ozone_backend.clk)");
    co_await vlSelfRef.__VtrigSched_h0e5d9782__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_ozone_backend.clk)", 
                                                         "tb/tb_ozone_backend.sv", 
                                                         607);
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_ozone_backend.sv", 
                                         608);
    vlSelfRef.tb_ozone_backend__DOT__src1_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src1_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_en = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_wr_en = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__rob_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__alloc_has_dest = 0U;
    VL_ASSIGN_W(280, vlSelfRef.tb_ozone_backend__DOT__alloc_data, Vtb_ozone_backend__ConstPool__CONST_h083ec1be_0);
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[0U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[1U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[2U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[3U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[4U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[5U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[0U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[1U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[2U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[3U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[4U] = 0U;
    __Vtask_tb_ozone_backend__DOT__test_basic_logic_commit__26__logic_tag 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__32__tag_out;
    vlSelfRef.__Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__35__label = "logic commit x4"s;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__35__expected = 0x00000000000000f0ULL;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__35__reg_idx = 4U;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__35__cycles = 0U;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__35__cycles = 0U;
    while (((((((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                                [((0x1eU >= (0x0000001fU 
                                             & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__35__reg_idx))
                                   ? (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__35__reg_idx)
                                   : 0U)][2U])) << 0x00000039U) 
               | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                                   [((0x1eU >= (0x0000001fU 
                                                & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__35__reg_idx))
                                      ? (0x0000001fU 
                                         & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__35__reg_idx)
                                      : 0U)][1U])) 
                   << 0x00000019U) | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                                                      [
                                                      ((0x1eU 
                                                        >= 
                                                        (0x0000001fU 
                                                         & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__35__reg_idx))
                                                        ? 
                                                       (0x0000001fU 
                                                        & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__35__reg_idx)
                                                        : 0U)][0U])) 
                                      >> 7U))) != __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__35__expected) 
             | (vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                [((0x1eU >= (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__35__reg_idx))
                   ? (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__35__reg_idx)
                   : 0U)][0U] >> 6U)) & VL_GTS_III(32, 0x00000028U, __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__35__cycles))) {
        Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9782__0(vlSelf, 
                                                                "@(posedge tb_ozone_backend.clk)");
        co_await vlSelfRef.__VtrigSched_h0e5d9782__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_ozone_backend.clk)", 
                                                             "tb/tb_ozone_backend.sv", 
                                                             691);
        co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                             nullptr, 
                                             "tb/tb_ozone_backend.sv", 
                                             692);
        __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__35__cycles 
            = ((IData)(1U) + __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__35__cycles);
    }
    vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_u64__36__label 
        = vlSelfRef.__Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__35__label;
    __Vtask_tb_ozone_backend__DOT__check_u64__36__expected 
        = __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__35__expected;
    __Vtask_tb_ozone_backend__DOT__check_u64__36__got 
        = (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                            [((0x1eU >= (0x0000001fU 
                                         & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__35__reg_idx))
                               ? (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__35__reg_idx)
                               : 0U)][2U])) << 0x00000039U) 
           | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                               [((0x1eU >= (0x0000001fU 
                                            & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__35__reg_idx))
                                  ? (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__35__reg_idx)
                                  : 0U)][1U])) << 0x00000019U) 
              | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                                 [((0x1eU >= (0x0000001fU 
                                              & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__35__reg_idx))
                                    ? (0x0000001fU 
                                       & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__35__reg_idx)
                                    : 0U)][0U])) >> 7U)));
    if (VL_UNLIKELY(((__Vtask_tb_ozone_backend__DOT__check_u64__36__got 
                      != __Vtask_tb_ozone_backend__DOT__check_u64__36__expected)))) {
        tb_ozone_backend__DOT__failures = ((IData)(1U) 
                                           + tb_ozone_backend__DOT__failures);
        VL_WRITEF_NX("[FAIL] %@ expected=0x%016x got=0x%016x\n",0,
                     -1,&(vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_u64__36__label),
                     64,__Vtask_tb_ozone_backend__DOT__check_u64__36__expected,
                     64,__Vtask_tb_ozone_backend__DOT__check_u64__36__got);
    }
    vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_true__37__label 
        = VL_CVT_PACK_STR_NN(VL_CONCATN_NNN(vlSelfRef.__Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__35__label, " busy clear"s));
    __Vtask_tb_ozone_backend__DOT__check_true__37__cond 
        = (1U & (~ (vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                    [((0x1eU >= (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__35__reg_idx))
                       ? (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__35__reg_idx)
                       : 0U)][0U] >> 6U)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_ozone_backend__DOT__check_true__37__cond)))))) {
        tb_ozone_backend__DOT__failures = ((IData)(1U) 
                                           + tb_ozone_backend__DOT__failures);
        VL_WRITEF_NX("[FAIL] %@\n",0,-1,&(vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_true__37__label));
    }
    vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_true__38__label = "logic rob entry became ready"s;
    __Vtask_tb_ozone_backend__DOT__check_true__38__cond 
        = (1U & (vlSelfRef.tb_ozone_backend__DOT__rob__DOT__rob_entries
                 [__Vtask_tb_ozone_backend__DOT__test_basic_logic_commit__26__logic_tag][6U] 
                 >> 7U));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_ozone_backend__DOT__check_true__38__cond)))))) {
        tb_ozone_backend__DOT__failures = ((IData)(1U) 
                                           + tb_ozone_backend__DOT__failures);
        VL_WRITEF_NX("[FAIL] %@\n",0,-1,&(vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_true__38__label));
    }
    __Vtask_tb_ozone_backend__DOT__test_adder_internal_forwarding__39__prod_tag = 0;
    __Vtask_tb_ozone_backend__DOT__test_adder_internal_forwarding__39__cons_tag = 0;
    __Vtask_tb_ozone_backend__DOT__test_adder_internal_forwarding__39__cons_slot = 0U;
    VL_WRITEF_NX("Running adder internal forwarding\n",0);
    __Vtask_tb_ozone_backend__DOT__reset_dut__40__tb_ozone_backend__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    vlSelfRef.tb_ozone_backend__DOT__src1_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src1_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_en = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_wr_en = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__rob_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__alloc_has_dest = 0U;
    VL_ASSIGN_W(280, vlSelfRef.tb_ozone_backend__DOT__alloc_data, Vtb_ozone_backend__ConstPool__CONST_h083ec1be_0);
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[0U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[1U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[2U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[3U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[4U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[5U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[0U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[1U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[2U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[3U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[4U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__rst_n = 0U;
    __Vtask_tb_ozone_backend__DOT__reset_dut__40__tb_ozone_backend__DOT__unnamedblk1_1__DOT____Vrepeat0 = 3U;
    while (VL_LTS_III(32, 0U, __Vtask_tb_ozone_backend__DOT__reset_dut__40__tb_ozone_backend__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9782__0(vlSelf, 
                                                                "@(posedge tb_ozone_backend.clk)");
        co_await vlSelfRef.__VtrigSched_h0e5d9782__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_ozone_backend.clk)", 
                                                             "tb/tb_ozone_backend.sv", 
                                                             380);
        __Vtask_tb_ozone_backend__DOT__reset_dut__40__tb_ozone_backend__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (__Vtask_tb_ozone_backend__DOT__reset_dut__40__tb_ozone_backend__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    vlSelfRef.tb_ozone_backend__DOT__rst_n = 1U;
    Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9782__0(vlSelf, 
                                                            "@(posedge tb_ozone_backend.clk)");
    co_await vlSelfRef.__VtrigSched_h0e5d9782__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_ozone_backend.clk)", 
                                                         "tb/tb_ozone_backend.sv", 
                                                         382);
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_ozone_backend.sv", 
                                         383);
    vlSelfRef.tb_ozone_backend__DOT__src1_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src1_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_en = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_wr_en = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__rob_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__alloc_has_dest = 0U;
    VL_ASSIGN_W(280, vlSelfRef.tb_ozone_backend__DOT__alloc_data, Vtb_ozone_backend__ConstPool__CONST_h083ec1be_0);
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[0U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[1U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[2U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[3U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[4U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[5U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[0U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[1U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[2U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[3U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[4U] = 0U;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__43__value = 8ULL;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__43__idx = 1U;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__43____Vlvbound_hee8445f9__0 = 0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__43____Vlvbound_hee492a18__0 = 0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__43____Vlvbound_hffe4168d__0 = 0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__43____Vlvbound_hffe4168d__0 
        = __Vtask_tb_ozone_backend__DOT__preload_gpr__43__value;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__43____Vlvbound_hee492a18__0 = 0U;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__43____Vlvbound_hee8445f9__0 = 0U;
    if (VL_LIKELY(((0x1eU >= (0x0000001fU & __Vtask_tb_ozone_backend__DOT__preload_gpr__43__idx))))) {
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__43__idx)][0U] 
            = ((0x0000007fU & vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                [(0x0000001fU & __Vtask_tb_ozone_backend__DOT__preload_gpr__43__idx)][0U]) 
               | ((IData)(__Vtask_tb_ozone_backend__DOT__preload_gpr__43____Vlvbound_hffe4168d__0) 
                  << 7U));
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__43__idx)][1U] 
            = (((IData)(__Vtask_tb_ozone_backend__DOT__preload_gpr__43____Vlvbound_hffe4168d__0) 
                >> 0x00000019U) | ((IData)((__Vtask_tb_ozone_backend__DOT__preload_gpr__43____Vlvbound_hffe4168d__0 
                                            >> 0x00000020U)) 
                                   << 7U));
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__43__idx)][2U] 
            = ((IData)((__Vtask_tb_ozone_backend__DOT__preload_gpr__43____Vlvbound_hffe4168d__0 
                        >> 0x00000020U)) >> 0x00000019U);
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__43__idx)][0U] 
            = ((0xffffffbfU & vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                [(0x0000001fU & __Vtask_tb_ozone_backend__DOT__preload_gpr__43__idx)][0U]) 
               | ((IData)(__Vtask_tb_ozone_backend__DOT__preload_gpr__43____Vlvbound_hee492a18__0) 
                  << 6U));
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__43__idx)][0U] 
            = ((0xffffffc0U & vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                [(0x0000001fU & __Vtask_tb_ozone_backend__DOT__preload_gpr__43__idx)][0U]) 
               | (IData)(__Vtask_tb_ozone_backend__DOT__preload_gpr__43____Vlvbound_hee8445f9__0));
    }
    __Vtask_tb_ozone_backend__DOT__preload_gpr__44__value = 3ULL;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__44__idx = 2U;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__44____Vlvbound_hee8445f9__0 = 0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__44____Vlvbound_hee492a18__0 = 0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__44____Vlvbound_hffe4168d__0 = 0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__44____Vlvbound_hffe4168d__0 
        = __Vtask_tb_ozone_backend__DOT__preload_gpr__44__value;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__44____Vlvbound_hee492a18__0 = 0U;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__44____Vlvbound_hee8445f9__0 = 0U;
    if (VL_LIKELY(((0x1eU >= (0x0000001fU & __Vtask_tb_ozone_backend__DOT__preload_gpr__44__idx))))) {
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__44__idx)][0U] 
            = ((0x0000007fU & vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                [(0x0000001fU & __Vtask_tb_ozone_backend__DOT__preload_gpr__44__idx)][0U]) 
               | ((IData)(__Vtask_tb_ozone_backend__DOT__preload_gpr__44____Vlvbound_hffe4168d__0) 
                  << 7U));
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__44__idx)][1U] 
            = (((IData)(__Vtask_tb_ozone_backend__DOT__preload_gpr__44____Vlvbound_hffe4168d__0) 
                >> 0x00000019U) | ((IData)((__Vtask_tb_ozone_backend__DOT__preload_gpr__44____Vlvbound_hffe4168d__0 
                                            >> 0x00000020U)) 
                                   << 7U));
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__44__idx)][2U] 
            = ((IData)((__Vtask_tb_ozone_backend__DOT__preload_gpr__44____Vlvbound_hffe4168d__0 
                        >> 0x00000020U)) >> 0x00000019U);
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__44__idx)][0U] 
            = ((0xffffffbfU & vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                [(0x0000001fU & __Vtask_tb_ozone_backend__DOT__preload_gpr__44__idx)][0U]) 
               | ((IData)(__Vtask_tb_ozone_backend__DOT__preload_gpr__44____Vlvbound_hee492a18__0) 
                  << 6U));
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__44__idx)][0U] 
            = ((0xffffffc0U & vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                [(0x0000001fU & __Vtask_tb_ozone_backend__DOT__preload_gpr__44__idx)][0U]) 
               | (IData)(__Vtask_tb_ozone_backend__DOT__preload_gpr__44____Vlvbound_hee8445f9__0));
    }
    __Vtask_tb_ozone_backend__DOT__preload_gpr__45__value = 4ULL;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__45__idx = 3U;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__45____Vlvbound_hee8445f9__0 = 0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__45____Vlvbound_hee492a18__0 = 0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__45____Vlvbound_hffe4168d__0 = 0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__45____Vlvbound_hffe4168d__0 
        = __Vtask_tb_ozone_backend__DOT__preload_gpr__45__value;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__45____Vlvbound_hee492a18__0 = 0U;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__45____Vlvbound_hee8445f9__0 = 0U;
    if (VL_LIKELY(((0x1eU >= (0x0000001fU & __Vtask_tb_ozone_backend__DOT__preload_gpr__45__idx))))) {
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__45__idx)][0U] 
            = ((0x0000007fU & vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                [(0x0000001fU & __Vtask_tb_ozone_backend__DOT__preload_gpr__45__idx)][0U]) 
               | ((IData)(__Vtask_tb_ozone_backend__DOT__preload_gpr__45____Vlvbound_hffe4168d__0) 
                  << 7U));
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__45__idx)][1U] 
            = (((IData)(__Vtask_tb_ozone_backend__DOT__preload_gpr__45____Vlvbound_hffe4168d__0) 
                >> 0x00000019U) | ((IData)((__Vtask_tb_ozone_backend__DOT__preload_gpr__45____Vlvbound_hffe4168d__0 
                                            >> 0x00000020U)) 
                                   << 7U));
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__45__idx)][2U] 
            = ((IData)((__Vtask_tb_ozone_backend__DOT__preload_gpr__45____Vlvbound_hffe4168d__0 
                        >> 0x00000020U)) >> 0x00000019U);
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__45__idx)][0U] 
            = ((0xffffffbfU & vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                [(0x0000001fU & __Vtask_tb_ozone_backend__DOT__preload_gpr__45__idx)][0U]) 
               | ((IData)(__Vtask_tb_ozone_backend__DOT__preload_gpr__45____Vlvbound_hee492a18__0) 
                  << 6U));
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__45__idx)][0U] 
            = ((0xffffffc0U & vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                [(0x0000001fU & __Vtask_tb_ozone_backend__DOT__preload_gpr__45__idx)][0U]) 
               | (IData)(__Vtask_tb_ozone_backend__DOT__preload_gpr__45____Vlvbound_hee8445f9__0));
    }
    __Vtask_tb_ozone_backend__DOT__preload_gpr__46__value = 5ULL;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__46__idx = 6U;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__46____Vlvbound_hee8445f9__0 = 0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__46____Vlvbound_hee492a18__0 = 0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__46____Vlvbound_hffe4168d__0 = 0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__46____Vlvbound_hffe4168d__0 
        = __Vtask_tb_ozone_backend__DOT__preload_gpr__46__value;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__46____Vlvbound_hee492a18__0 = 0U;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__46____Vlvbound_hee8445f9__0 = 0U;
    if (VL_LIKELY(((0x1eU >= (0x0000001fU & __Vtask_tb_ozone_backend__DOT__preload_gpr__46__idx))))) {
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__46__idx)][0U] 
            = ((0x0000007fU & vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                [(0x0000001fU & __Vtask_tb_ozone_backend__DOT__preload_gpr__46__idx)][0U]) 
               | ((IData)(__Vtask_tb_ozone_backend__DOT__preload_gpr__46____Vlvbound_hffe4168d__0) 
                  << 7U));
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__46__idx)][1U] 
            = (((IData)(__Vtask_tb_ozone_backend__DOT__preload_gpr__46____Vlvbound_hffe4168d__0) 
                >> 0x00000019U) | ((IData)((__Vtask_tb_ozone_backend__DOT__preload_gpr__46____Vlvbound_hffe4168d__0 
                                            >> 0x00000020U)) 
                                   << 7U));
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__46__idx)][2U] 
            = ((IData)((__Vtask_tb_ozone_backend__DOT__preload_gpr__46____Vlvbound_hffe4168d__0 
                        >> 0x00000020U)) >> 0x00000019U);
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__46__idx)][0U] 
            = ((0xffffffbfU & vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                [(0x0000001fU & __Vtask_tb_ozone_backend__DOT__preload_gpr__46__idx)][0U]) 
               | ((IData)(__Vtask_tb_ozone_backend__DOT__preload_gpr__46____Vlvbound_hee492a18__0) 
                  << 6U));
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__46__idx)][0U] 
            = ((0xffffffc0U & vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                [(0x0000001fU & __Vtask_tb_ozone_backend__DOT__preload_gpr__46__idx)][0U]) 
               | (IData)(__Vtask_tb_ozone_backend__DOT__preload_gpr__46____Vlvbound_hee8445f9__0));
    }
    __Vtask_tb_ozone_backend__DOT__warmup_tag_zero__47__expected = 0;
    __Vtask_tb_ozone_backend__DOT__warmup_tag_zero__47__expected 
        = ((((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[1U][2U])) 
             << 0x00000039U) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[1U][1U])) 
                                 << 0x00000019U) | 
                                ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[1U][0U])) 
                                 >> 7U))) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[2U][2U])) 
                                              << 0x00000039U) 
                                             | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[2U][1U])) 
                                                 << 0x00000019U) 
                                                | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[2U][0U])) 
                                                   >> 7U))));
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__writes_nzcv = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__has_dest = 1U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__dest_reg = 0x1eU;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__reg_b = 2U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__reg_a = 1U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__op = 0x13U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__tag_out = 0;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__vj = 0;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__vk = 0;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__qj = 0;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__qk = 0;
    VL_ZERO_W(159, __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__entry);
    VL_ZERO_W(280, __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__rob_entry);
    while (((0x40U == (IData)(vlSelfRef.tb_ozone_backend__DOT__rob__DOT__count)) 
            | (IData)(vlSelfRef.tb_ozone_backend__DOT__logic_full))) {
        Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9448__0(vlSelf, 
                                                                "@(negedge tb_ozone_backend.clk)");
        co_await vlSelfRef.__VtrigSched_h0e5d9448__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_ozone_backend.clk)", 
                                                             "tb/tb_ozone_backend.sv", 
                                                             576);
    }
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__49__reg_b 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__reg_b;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__49__reg_a 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__reg_a;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__49__vj = 0;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__49__qj = 0;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__49__vk = 0;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__49__qk = 0;
    vlSelfRef.tb_ozone_backend__DOT__src1_addr = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__49__reg_a;
    vlSelfRef.tb_ozone_backend__DOT__src2_addr = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__49__reg_b;
    vlSelfRef.tb_ozone_backend__DOT__src1_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_rob_idx = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_ozone_backend.sv", 
                                         452);
    vlSelfRef.tb_ozone_backend__DOT__src1_rob_idx = 
        (0x0000003fU & vlSelfRef.tb_ozone_backend__DOT__src1_status[0U]);
    vlSelfRef.tb_ozone_backend__DOT__src2_rob_idx = 
        (0x0000003fU & vlSelfRef.tb_ozone_backend__DOT__src2_status[0U]);
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_ozone_backend.sv", 
                                         456);
    if ((0x00000040U & vlSelfRef.tb_ozone_backend__DOT__src1_status[0U])) {
        if (vlSelfRef.tb_ozone_backend__DOT__src1_ready) {
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__49__vj 
                = vlSelfRef.tb_ozone_backend__DOT__src1_value;
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__49__qj = 0U;
        } else {
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__49__vj = 0ULL;
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__49__qj 
                = (0x0000003fU & vlSelfRef.tb_ozone_backend__DOT__src1_status[0U]);
        }
    } else {
        __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__49__vj 
            = (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src1_status[2U])) 
                << 0x00000039U) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src1_status[1U])) 
                                    << 0x00000019U) 
                                   | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src1_status[0U])) 
                                      >> 7U)));
        __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__49__qj = 0U;
    }
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__vj 
        = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__49__vj;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__qj 
        = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__49__qj;
    if ((0x00000040U & vlSelfRef.tb_ozone_backend__DOT__src2_status[0U])) {
        if (vlSelfRef.tb_ozone_backend__DOT__src2_ready) {
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__49__vk 
                = vlSelfRef.tb_ozone_backend__DOT__src2_value;
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__49__qk = 0U;
        } else {
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__49__vk = 0ULL;
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__49__qk 
                = (0x0000003fU & vlSelfRef.tb_ozone_backend__DOT__src2_status[0U]);
        }
    } else {
        __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__49__vk 
            = (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src2_status[2U])) 
                << 0x00000039U) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src2_status[1U])) 
                                    << 0x00000019U) 
                                   | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src2_status[0U])) 
                                      >> 7U)));
        __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__49__qk = 0U;
    }
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__vk 
        = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__49__vk;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__qk 
        = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__49__qk;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__tag_out 
        = vlSelfRef.tb_ozone_backend__DOT__rob__DOT__tail;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__entry[0U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__entry[1U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__entry[2U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__entry[3U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__entry[4U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__entry[0U] 
        = ((0x00000fffU & __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__entry[0U]) 
           | (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__vk) 
               << 0x0000001eU) | (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__qj) 
                                   << 0x00000018U) 
                                  | (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__qk) 
                                      << 0x00000012U) 
                                     | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__tag_out) 
                                        << 0x0000000cU)))));
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__entry[1U] 
        = (((0x00000fffU & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__vk) 
                            >> 2U)) | ((0x00000fffU 
                                        & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__qj) 
                                           >> 8U)) 
                                       | ((0x00000fffU 
                                           & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__qk) 
                                              >> 0x0000000eU)) 
                                          | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__tag_out) 
                                             >> 0x00000014U)))) 
           | ((0x3ffff000U & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__vk) 
                              >> 2U)) | ((IData)((__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__vk 
                                                  >> 0x00000020U)) 
                                         << 0x0000001eU)));
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__entry[2U] 
        = ((0xc0000000U & __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__entry[2U]) 
           | ((0x00000fffU & ((IData)((__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__vk 
                                       >> 0x00000020U)) 
                              >> 2U)) | (0x3ffff000U 
                                         & ((IData)(
                                                    (__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__vk 
                                                     >> 0x00000020U)) 
                                            >> 2U))));
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__entry[2U] 
        = ((0x3fffffffU & __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__entry[2U]) 
           | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__vj) 
              << 0x0000001eU));
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__entry[3U] 
        = (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__vj) 
            >> 2U) | ((IData)((__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__vj 
                               >> 0x00000020U)) << 0x0000001eU));
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__entry[4U] 
        = ((0x40000000U & __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__entry[4U]) 
           | (0x7fffffffU & ((IData)((__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__vj 
                                      >> 0x00000020U)) 
                             >> 2U)));
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__entry[0U] 
        = ((0xfffff801U & __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__entry[0U]) 
           | (0xfffffffeU & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__op) 
                             << 5U)));
    VL_ASSIGN_W(280, __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__rob_entry, Vtb_ozone_backend__ConstPool__CONST_h083ec1be_0);
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__rob_entry[8U] 
        = ((0x00801fffU & __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__rob_entry[8U]) 
           | (0x00ffe000U & (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__dest_reg) 
                              << 0x00000010U) | ((((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__has_dest)
                                                    ? 1U
                                                    : 0U) 
                                                  << 0x0000000eU) 
                                                 | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__has_dest) 
                                                    << 0x0000000dU)))));
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__rob_entry[6U] 
        = ((0xffffefffU & __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__rob_entry[6U]) 
           | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__writes_nzcv) 
              << 0x0000000cU));
    Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9448__0(vlSelf, 
                                                            "@(negedge tb_ozone_backend.clk)");
    co_await vlSelfRef.__VtrigSched_h0e5d9448__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_ozone_backend.clk)", 
                                                         "tb/tb_ozone_backend.sv", 
                                                         596);
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[0U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__rob_entry[0U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[1U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__rob_entry[1U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[2U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__rob_entry[2U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[3U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__rob_entry[3U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[4U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__rob_entry[4U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[5U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__rob_entry[5U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[6U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__rob_entry[6U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[7U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__rob_entry[7U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[8U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__rob_entry[8U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_has_dest 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__has_dest;
    vlSelfRef.tb_ozone_backend__DOT__rob_alloc_valid = 1U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[0U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__entry[0U];
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[1U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__entry[1U];
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[2U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__entry[2U];
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[3U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__entry[3U];
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[4U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__entry[4U];
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_valid = 1U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_en = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__has_dest;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_addr = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__dest_reg;
    vlSelfRef.tb_ozone_backend__DOT__disp_rob_idx = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__tag_out;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_wr_en 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__writes_nzcv;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_rob_idx 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__48__tag_out;
    Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9782__0(vlSelf, 
                                                            "@(posedge tb_ozone_backend.clk)");
    co_await vlSelfRef.__VtrigSched_h0e5d9782__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_ozone_backend.clk)", 
                                                         "tb/tb_ozone_backend.sv", 
                                                         607);
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_ozone_backend.sv", 
                                         608);
    vlSelfRef.tb_ozone_backend__DOT__src1_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src1_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_en = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_wr_en = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__rob_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__alloc_has_dest = 0U;
    VL_ASSIGN_W(280, vlSelfRef.tb_ozone_backend__DOT__alloc_data, Vtb_ozone_backend__ConstPool__CONST_h083ec1be_0);
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[0U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[1U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[2U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[3U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[4U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[5U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[0U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[1U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[2U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[3U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[4U] = 0U;
    vlSelfRef.__Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__51__label = "warmup x30"s;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__51__expected 
        = __Vtask_tb_ozone_backend__DOT__warmup_tag_zero__47__expected;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__51__reg_idx = 0x0000001eU;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__51__cycles = 0U;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__51__cycles = 0U;
    while (((((((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                                [((0x1eU >= (0x0000001fU 
                                             & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__51__reg_idx))
                                   ? (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__51__reg_idx)
                                   : 0U)][2U])) << 0x00000039U) 
               | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                                   [((0x1eU >= (0x0000001fU 
                                                & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__51__reg_idx))
                                      ? (0x0000001fU 
                                         & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__51__reg_idx)
                                      : 0U)][1U])) 
                   << 0x00000019U) | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                                                      [
                                                      ((0x1eU 
                                                        >= 
                                                        (0x0000001fU 
                                                         & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__51__reg_idx))
                                                        ? 
                                                       (0x0000001fU 
                                                        & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__51__reg_idx)
                                                        : 0U)][0U])) 
                                      >> 7U))) != __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__51__expected) 
             | (vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                [((0x1eU >= (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__51__reg_idx))
                   ? (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__51__reg_idx)
                   : 0U)][0U] >> 6U)) & VL_GTS_III(32, 0x00000028U, __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__51__cycles))) {
        Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9782__0(vlSelf, 
                                                                "@(posedge tb_ozone_backend.clk)");
        co_await vlSelfRef.__VtrigSched_h0e5d9782__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_ozone_backend.clk)", 
                                                             "tb/tb_ozone_backend.sv", 
                                                             691);
        co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                             nullptr, 
                                             "tb/tb_ozone_backend.sv", 
                                             692);
        __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__51__cycles 
            = ((IData)(1U) + __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__51__cycles);
    }
    vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_u64__52__label 
        = vlSelfRef.__Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__51__label;
    __Vtask_tb_ozone_backend__DOT__check_u64__52__expected 
        = __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__51__expected;
    __Vtask_tb_ozone_backend__DOT__check_u64__52__got 
        = (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                            [((0x1eU >= (0x0000001fU 
                                         & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__51__reg_idx))
                               ? (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__51__reg_idx)
                               : 0U)][2U])) << 0x00000039U) 
           | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                               [((0x1eU >= (0x0000001fU 
                                            & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__51__reg_idx))
                                  ? (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__51__reg_idx)
                                  : 0U)][1U])) << 0x00000019U) 
              | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                                 [((0x1eU >= (0x0000001fU 
                                              & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__51__reg_idx))
                                    ? (0x0000001fU 
                                       & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__51__reg_idx)
                                    : 0U)][0U])) >> 7U)));
    if (VL_UNLIKELY(((__Vtask_tb_ozone_backend__DOT__check_u64__52__got 
                      != __Vtask_tb_ozone_backend__DOT__check_u64__52__expected)))) {
        tb_ozone_backend__DOT__failures = ((IData)(1U) 
                                           + tb_ozone_backend__DOT__failures);
        VL_WRITEF_NX("[FAIL] %@ expected=0x%016x got=0x%016x\n",0,
                     -1,&(vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_u64__52__label),
                     64,__Vtask_tb_ozone_backend__DOT__check_u64__52__expected,
                     64,__Vtask_tb_ozone_backend__DOT__check_u64__52__got);
    }
    vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_true__53__label 
        = VL_CVT_PACK_STR_NN(VL_CONCATN_NNN(vlSelfRef.__Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__51__label, " busy clear"s));
    __Vtask_tb_ozone_backend__DOT__check_true__53__cond 
        = (1U & (~ (vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                    [((0x1eU >= (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__51__reg_idx))
                       ? (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__51__reg_idx)
                       : 0U)][0U] >> 6U)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_ozone_backend__DOT__check_true__53__cond)))))) {
        tb_ozone_backend__DOT__failures = ((IData)(1U) 
                                           + tb_ozone_backend__DOT__failures);
        VL_WRITEF_NX("[FAIL] %@\n",0,-1,&(vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_true__53__label));
    }
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__writes_nzcv = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__has_dest = 1U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__dest_reg = 0x0aU;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__reg_b = 2U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__reg_a = 1U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__op = 0x13U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__tag_out = 0;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__vj = 0;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__vk = 0;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__qj = 0;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__qk = 0;
    VL_ZERO_W(159, __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__entry);
    VL_ZERO_W(280, __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__rob_entry);
    while (((0x40U == (IData)(vlSelfRef.tb_ozone_backend__DOT__rob__DOT__count)) 
            | (IData)(vlSelfRef.tb_ozone_backend__DOT__logic_full))) {
        Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9448__0(vlSelf, 
                                                                "@(negedge tb_ozone_backend.clk)");
        co_await vlSelfRef.__VtrigSched_h0e5d9448__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_ozone_backend.clk)", 
                                                             "tb/tb_ozone_backend.sv", 
                                                             576);
    }
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__55__reg_b 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__reg_b;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__55__reg_a 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__reg_a;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__55__vj = 0;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__55__qj = 0;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__55__vk = 0;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__55__qk = 0;
    vlSelfRef.tb_ozone_backend__DOT__src1_addr = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__55__reg_a;
    vlSelfRef.tb_ozone_backend__DOT__src2_addr = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__55__reg_b;
    vlSelfRef.tb_ozone_backend__DOT__src1_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_rob_idx = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_ozone_backend.sv", 
                                         452);
    vlSelfRef.tb_ozone_backend__DOT__src1_rob_idx = 
        (0x0000003fU & vlSelfRef.tb_ozone_backend__DOT__src1_status[0U]);
    vlSelfRef.tb_ozone_backend__DOT__src2_rob_idx = 
        (0x0000003fU & vlSelfRef.tb_ozone_backend__DOT__src2_status[0U]);
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_ozone_backend.sv", 
                                         456);
    if ((0x00000040U & vlSelfRef.tb_ozone_backend__DOT__src1_status[0U])) {
        if (vlSelfRef.tb_ozone_backend__DOT__src1_ready) {
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__55__vj 
                = vlSelfRef.tb_ozone_backend__DOT__src1_value;
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__55__qj = 0U;
        } else {
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__55__vj = 0ULL;
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__55__qj 
                = (0x0000003fU & vlSelfRef.tb_ozone_backend__DOT__src1_status[0U]);
        }
    } else {
        __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__55__vj 
            = (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src1_status[2U])) 
                << 0x00000039U) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src1_status[1U])) 
                                    << 0x00000019U) 
                                   | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src1_status[0U])) 
                                      >> 7U)));
        __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__55__qj = 0U;
    }
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__vj 
        = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__55__vj;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__qj 
        = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__55__qj;
    if ((0x00000040U & vlSelfRef.tb_ozone_backend__DOT__src2_status[0U])) {
        if (vlSelfRef.tb_ozone_backend__DOT__src2_ready) {
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__55__vk 
                = vlSelfRef.tb_ozone_backend__DOT__src2_value;
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__55__qk = 0U;
        } else {
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__55__vk = 0ULL;
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__55__qk 
                = (0x0000003fU & vlSelfRef.tb_ozone_backend__DOT__src2_status[0U]);
        }
    } else {
        __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__55__vk 
            = (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src2_status[2U])) 
                << 0x00000039U) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src2_status[1U])) 
                                    << 0x00000019U) 
                                   | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src2_status[0U])) 
                                      >> 7U)));
        __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__55__qk = 0U;
    }
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__vk 
        = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__55__vk;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__qk 
        = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__55__qk;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__tag_out 
        = vlSelfRef.tb_ozone_backend__DOT__rob__DOT__tail;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__entry[0U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__entry[1U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__entry[2U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__entry[3U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__entry[4U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__entry[0U] 
        = ((0x00000fffU & __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__entry[0U]) 
           | (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__vk) 
               << 0x0000001eU) | (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__qj) 
                                   << 0x00000018U) 
                                  | (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__qk) 
                                      << 0x00000012U) 
                                     | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__tag_out) 
                                        << 0x0000000cU)))));
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__entry[1U] 
        = (((0x00000fffU & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__vk) 
                            >> 2U)) | ((0x00000fffU 
                                        & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__qj) 
                                           >> 8U)) 
                                       | ((0x00000fffU 
                                           & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__qk) 
                                              >> 0x0000000eU)) 
                                          | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__tag_out) 
                                             >> 0x00000014U)))) 
           | ((0x3ffff000U & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__vk) 
                              >> 2U)) | ((IData)((__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__vk 
                                                  >> 0x00000020U)) 
                                         << 0x0000001eU)));
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__entry[2U] 
        = ((0xc0000000U & __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__entry[2U]) 
           | ((0x00000fffU & ((IData)((__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__vk 
                                       >> 0x00000020U)) 
                              >> 2U)) | (0x3ffff000U 
                                         & ((IData)(
                                                    (__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__vk 
                                                     >> 0x00000020U)) 
                                            >> 2U))));
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__entry[2U] 
        = ((0x3fffffffU & __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__entry[2U]) 
           | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__vj) 
              << 0x0000001eU));
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__entry[3U] 
        = (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__vj) 
            >> 2U) | ((IData)((__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__vj 
                               >> 0x00000020U)) << 0x0000001eU));
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__entry[4U] 
        = ((0x40000000U & __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__entry[4U]) 
           | (0x7fffffffU & ((IData)((__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__vj 
                                      >> 0x00000020U)) 
                             >> 2U)));
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__entry[0U] 
        = ((0xfffff801U & __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__entry[0U]) 
           | (0xfffffffeU & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__op) 
                             << 5U)));
    VL_ASSIGN_W(280, __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__rob_entry, Vtb_ozone_backend__ConstPool__CONST_h083ec1be_0);
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__rob_entry[8U] 
        = ((0x00801fffU & __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__rob_entry[8U]) 
           | (0x00ffe000U & (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__dest_reg) 
                              << 0x00000010U) | ((((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__has_dest)
                                                    ? 1U
                                                    : 0U) 
                                                  << 0x0000000eU) 
                                                 | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__has_dest) 
                                                    << 0x0000000dU)))));
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__rob_entry[6U] 
        = ((0xffffefffU & __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__rob_entry[6U]) 
           | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__writes_nzcv) 
              << 0x0000000cU));
    Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9448__0(vlSelf, 
                                                            "@(negedge tb_ozone_backend.clk)");
    co_await vlSelfRef.__VtrigSched_h0e5d9448__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_ozone_backend.clk)", 
                                                         "tb/tb_ozone_backend.sv", 
                                                         596);
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[0U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__rob_entry[0U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[1U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__rob_entry[1U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[2U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__rob_entry[2U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[3U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__rob_entry[3U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[4U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__rob_entry[4U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[5U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__rob_entry[5U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[6U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__rob_entry[6U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[7U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__rob_entry[7U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[8U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__rob_entry[8U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_has_dest 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__has_dest;
    vlSelfRef.tb_ozone_backend__DOT__rob_alloc_valid = 1U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[0U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__entry[0U];
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[1U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__entry[1U];
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[2U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__entry[2U];
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[3U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__entry[3U];
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[4U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__entry[4U];
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_valid = 1U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_en = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__has_dest;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_addr = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__dest_reg;
    vlSelfRef.tb_ozone_backend__DOT__disp_rob_idx = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__tag_out;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_wr_en 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__writes_nzcv;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_rob_idx 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__54__tag_out;
    Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9782__0(vlSelf, 
                                                            "@(posedge tb_ozone_backend.clk)");
    co_await vlSelfRef.__VtrigSched_h0e5d9782__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_ozone_backend.clk)", 
                                                         "tb/tb_ozone_backend.sv", 
                                                         607);
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_ozone_backend.sv", 
                                         608);
    vlSelfRef.tb_ozone_backend__DOT__src1_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src1_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_en = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_wr_en = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__rob_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__alloc_has_dest = 0U;
    VL_ASSIGN_W(280, vlSelfRef.tb_ozone_backend__DOT__alloc_data, Vtb_ozone_backend__ConstPool__CONST_h083ec1be_0);
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[0U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[1U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[2U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[3U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[4U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[5U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[0U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[1U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[2U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[3U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[4U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__writes_nzcv = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__has_dest = 1U;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__dest_reg = 4U;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__reg_b = 3U;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__reg_a = 0x0aU;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__op = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__tag_out = 0;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__vj = 0;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__vk = 0;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__qj = 0;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__qk = 0;
    VL_ZERO_W(165, __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__entry);
    VL_ZERO_W(280, __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__rob_entry);
    while (((0x40U == (IData)(vlSelfRef.tb_ozone_backend__DOT__rob__DOT__count)) 
            | (IData)(vlSelfRef.tb_ozone_backend__DOT__adder_full))) {
        Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9448__0(vlSelf, 
                                                                "@(negedge tb_ozone_backend.clk)");
        co_await vlSelfRef.__VtrigSched_h0e5d9448__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_ozone_backend.clk)", 
                                                             "tb/tb_ozone_backend.sv", 
                                                             522);
    }
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__58__reg_b 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__reg_b;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__58__reg_a 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__reg_a;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__58__vj = 0;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__58__qj = 0;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__58__vk = 0;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__58__qk = 0;
    vlSelfRef.tb_ozone_backend__DOT__src1_addr = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__58__reg_a;
    vlSelfRef.tb_ozone_backend__DOT__src2_addr = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__58__reg_b;
    vlSelfRef.tb_ozone_backend__DOT__src1_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_rob_idx = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_ozone_backend.sv", 
                                         452);
    vlSelfRef.tb_ozone_backend__DOT__src1_rob_idx = 
        (0x0000003fU & vlSelfRef.tb_ozone_backend__DOT__src1_status[0U]);
    vlSelfRef.tb_ozone_backend__DOT__src2_rob_idx = 
        (0x0000003fU & vlSelfRef.tb_ozone_backend__DOT__src2_status[0U]);
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_ozone_backend.sv", 
                                         456);
    if ((0x00000040U & vlSelfRef.tb_ozone_backend__DOT__src1_status[0U])) {
        if (vlSelfRef.tb_ozone_backend__DOT__src1_ready) {
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__58__vj 
                = vlSelfRef.tb_ozone_backend__DOT__src1_value;
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__58__qj = 0U;
        } else {
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__58__vj = 0ULL;
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__58__qj 
                = (0x0000003fU & vlSelfRef.tb_ozone_backend__DOT__src1_status[0U]);
        }
    } else {
        __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__58__vj 
            = (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src1_status[2U])) 
                << 0x00000039U) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src1_status[1U])) 
                                    << 0x00000019U) 
                                   | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src1_status[0U])) 
                                      >> 7U)));
        __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__58__qj = 0U;
    }
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__vj 
        = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__58__vj;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__qj 
        = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__58__qj;
    if ((0x00000040U & vlSelfRef.tb_ozone_backend__DOT__src2_status[0U])) {
        if (vlSelfRef.tb_ozone_backend__DOT__src2_ready) {
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__58__vk 
                = vlSelfRef.tb_ozone_backend__DOT__src2_value;
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__58__qk = 0U;
        } else {
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__58__vk = 0ULL;
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__58__qk 
                = (0x0000003fU & vlSelfRef.tb_ozone_backend__DOT__src2_status[0U]);
        }
    } else {
        __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__58__vk 
            = (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src2_status[2U])) 
                << 0x00000039U) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src2_status[1U])) 
                                    << 0x00000019U) 
                                   | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src2_status[0U])) 
                                      >> 7U)));
        __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__58__qk = 0U;
    }
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__vk 
        = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__58__vk;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__qk 
        = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__58__qk;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__tag_out 
        = vlSelfRef.tb_ozone_backend__DOT__rob__DOT__tail;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__entry[0U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__entry[1U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__entry[2U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__entry[3U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__entry[4U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__entry[5U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__entry[0U] 
        = ((0x0003ffffU & __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__entry[0U]) 
           | (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__qj) 
               << 0x0000001eU) | (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__qk) 
                                   << 0x00000018U) 
                                  | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__tag_out) 
                                     << 0x00000012U))));
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__entry[1U] 
        = (((0x0003fff0U & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__vk) 
                            << 4U)) | ((0x0003ffffU 
                                        & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__qj) 
                                           >> 2U)) 
                                       | ((0x0003ffffU 
                                           & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__qk) 
                                              >> 8U)) 
                                          | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__tag_out) 
                                             >> 0x0000000eU)))) 
           | (0xfffc0000U & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__vk) 
                             << 4U)));
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__entry[2U] 
        = ((((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__vk) 
             >> 0x0000001cU) | (0x0003fff0U & ((IData)(
                                                       (__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__vk 
                                                        >> 0x00000020U)) 
                                               << 4U))) 
           | (0xfffc0000U & ((IData)((__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__vk 
                                      >> 0x00000020U)) 
                             << 4U)));
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__entry[3U] 
        = ((0xfffffff0U & __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__entry[3U]) 
           | ((IData)((__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__vk 
                       >> 0x00000020U)) >> 0x0000001cU));
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__entry[3U] 
        = ((0x0000000fU & __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__entry[3U]) 
           | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__vj) 
              << 4U));
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__entry[4U] 
        = (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__vj) 
            >> 0x0000001cU) | ((IData)((__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__vj 
                                        >> 0x00000020U)) 
                               << 4U));
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__entry[5U] 
        = ((0x00000010U & __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__entry[5U]) 
           | (0x0000001fU & ((IData)((__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__vj 
                                      >> 0x00000020U)) 
                             >> 0x0000001cU)));
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__entry[0U] 
        = ((0xfffe0007U & __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__entry[0U]) 
           | (0xfffffff8U & (0x00000070U | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__op) 
                                            << 0x0000000bU))));
    VL_ASSIGN_W(280, __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__rob_entry, Vtb_ozone_backend__ConstPool__CONST_h083ec1be_0);
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__rob_entry[8U] 
        = ((0x00801fffU & __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__rob_entry[8U]) 
           | (0x00ffe000U & (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__dest_reg) 
                              << 0x00000010U) | ((((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__has_dest)
                                                    ? 1U
                                                    : 0U) 
                                                  << 0x0000000eU) 
                                                 | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__has_dest) 
                                                    << 0x0000000dU)))));
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__rob_entry[6U] 
        = ((0xffffefffU & __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__rob_entry[6U]) 
           | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__writes_nzcv) 
              << 0x0000000cU));
    Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9448__0(vlSelf, 
                                                            "@(negedge tb_ozone_backend.clk)");
    co_await vlSelfRef.__VtrigSched_h0e5d9448__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_ozone_backend.clk)", 
                                                         "tb/tb_ozone_backend.sv", 
                                                         543);
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[0U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__rob_entry[0U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[1U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__rob_entry[1U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[2U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__rob_entry[2U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[3U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__rob_entry[3U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[4U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__rob_entry[4U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[5U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__rob_entry[5U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[6U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__rob_entry[6U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[7U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__rob_entry[7U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[8U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__rob_entry[8U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_has_dest 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__has_dest;
    vlSelfRef.tb_ozone_backend__DOT__rob_alloc_valid = 1U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[0U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__entry[0U];
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[1U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__entry[1U];
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[2U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__entry[2U];
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[3U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__entry[3U];
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[4U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__entry[4U];
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[5U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__entry[5U];
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_valid = 1U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_en = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__has_dest;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_addr = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__dest_reg;
    vlSelfRef.tb_ozone_backend__DOT__disp_rob_idx = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__tag_out;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_wr_en 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__writes_nzcv;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_rob_idx 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__tag_out;
    Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9782__0(vlSelf, 
                                                            "@(posedge tb_ozone_backend.clk)");
    co_await vlSelfRef.__VtrigSched_h0e5d9782__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_ozone_backend.clk)", 
                                                         "tb/tb_ozone_backend.sv", 
                                                         554);
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_ozone_backend.sv", 
                                         555);
    vlSelfRef.tb_ozone_backend__DOT__src1_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src1_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_en = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_wr_en = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__rob_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__alloc_has_dest = 0U;
    VL_ASSIGN_W(280, vlSelfRef.tb_ozone_backend__DOT__alloc_data, Vtb_ozone_backend__ConstPool__CONST_h083ec1be_0);
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[0U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[1U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[2U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[3U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[4U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[5U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[0U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[1U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[2U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[3U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[4U] = 0U;
    __Vtask_tb_ozone_backend__DOT__test_adder_internal_forwarding__39__prod_tag 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__57__tag_out;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__writes_nzcv = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__has_dest = 1U;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__dest_reg = 5U;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__reg_b = 6U;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__reg_a = 4U;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__op = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__tag_out = 0;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__vj = 0;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__vk = 0;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__qj = 0;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__qk = 0;
    VL_ZERO_W(165, __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__entry);
    VL_ZERO_W(280, __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__rob_entry);
    while (((0x40U == (IData)(vlSelfRef.tb_ozone_backend__DOT__rob__DOT__count)) 
            | (IData)(vlSelfRef.tb_ozone_backend__DOT__adder_full))) {
        Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9448__0(vlSelf, 
                                                                "@(negedge tb_ozone_backend.clk)");
        co_await vlSelfRef.__VtrigSched_h0e5d9448__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_ozone_backend.clk)", 
                                                             "tb/tb_ozone_backend.sv", 
                                                             522);
    }
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__61__reg_b 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__reg_b;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__61__reg_a 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__reg_a;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__61__vj = 0;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__61__qj = 0;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__61__vk = 0;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__61__qk = 0;
    vlSelfRef.tb_ozone_backend__DOT__src1_addr = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__61__reg_a;
    vlSelfRef.tb_ozone_backend__DOT__src2_addr = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__61__reg_b;
    vlSelfRef.tb_ozone_backend__DOT__src1_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_rob_idx = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_ozone_backend.sv", 
                                         452);
    vlSelfRef.tb_ozone_backend__DOT__src1_rob_idx = 
        (0x0000003fU & vlSelfRef.tb_ozone_backend__DOT__src1_status[0U]);
    vlSelfRef.tb_ozone_backend__DOT__src2_rob_idx = 
        (0x0000003fU & vlSelfRef.tb_ozone_backend__DOT__src2_status[0U]);
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_ozone_backend.sv", 
                                         456);
    if ((0x00000040U & vlSelfRef.tb_ozone_backend__DOT__src1_status[0U])) {
        if (vlSelfRef.tb_ozone_backend__DOT__src1_ready) {
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__61__vj 
                = vlSelfRef.tb_ozone_backend__DOT__src1_value;
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__61__qj = 0U;
        } else {
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__61__vj = 0ULL;
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__61__qj 
                = (0x0000003fU & vlSelfRef.tb_ozone_backend__DOT__src1_status[0U]);
        }
    } else {
        __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__61__vj 
            = (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src1_status[2U])) 
                << 0x00000039U) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src1_status[1U])) 
                                    << 0x00000019U) 
                                   | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src1_status[0U])) 
                                      >> 7U)));
        __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__61__qj = 0U;
    }
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__vj 
        = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__61__vj;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__qj 
        = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__61__qj;
    if ((0x00000040U & vlSelfRef.tb_ozone_backend__DOT__src2_status[0U])) {
        if (vlSelfRef.tb_ozone_backend__DOT__src2_ready) {
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__61__vk 
                = vlSelfRef.tb_ozone_backend__DOT__src2_value;
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__61__qk = 0U;
        } else {
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__61__vk = 0ULL;
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__61__qk 
                = (0x0000003fU & vlSelfRef.tb_ozone_backend__DOT__src2_status[0U]);
        }
    } else {
        __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__61__vk 
            = (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src2_status[2U])) 
                << 0x00000039U) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src2_status[1U])) 
                                    << 0x00000019U) 
                                   | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src2_status[0U])) 
                                      >> 7U)));
        __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__61__qk = 0U;
    }
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__vk 
        = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__61__vk;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__qk 
        = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__61__qk;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__tag_out 
        = vlSelfRef.tb_ozone_backend__DOT__rob__DOT__tail;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__entry[0U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__entry[1U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__entry[2U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__entry[3U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__entry[4U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__entry[5U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__entry[0U] 
        = ((0x0003ffffU & __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__entry[0U]) 
           | (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__qj) 
               << 0x0000001eU) | (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__qk) 
                                   << 0x00000018U) 
                                  | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__tag_out) 
                                     << 0x00000012U))));
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__entry[1U] 
        = (((0x0003fff0U & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__vk) 
                            << 4U)) | ((0x0003ffffU 
                                        & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__qj) 
                                           >> 2U)) 
                                       | ((0x0003ffffU 
                                           & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__qk) 
                                              >> 8U)) 
                                          | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__tag_out) 
                                             >> 0x0000000eU)))) 
           | (0xfffc0000U & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__vk) 
                             << 4U)));
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__entry[2U] 
        = ((((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__vk) 
             >> 0x0000001cU) | (0x0003fff0U & ((IData)(
                                                       (__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__vk 
                                                        >> 0x00000020U)) 
                                               << 4U))) 
           | (0xfffc0000U & ((IData)((__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__vk 
                                      >> 0x00000020U)) 
                             << 4U)));
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__entry[3U] 
        = ((0xfffffff0U & __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__entry[3U]) 
           | ((IData)((__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__vk 
                       >> 0x00000020U)) >> 0x0000001cU));
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__entry[3U] 
        = ((0x0000000fU & __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__entry[3U]) 
           | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__vj) 
              << 4U));
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__entry[4U] 
        = (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__vj) 
            >> 0x0000001cU) | ((IData)((__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__vj 
                                        >> 0x00000020U)) 
                               << 4U));
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__entry[5U] 
        = ((0x00000010U & __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__entry[5U]) 
           | (0x0000001fU & ((IData)((__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__vj 
                                      >> 0x00000020U)) 
                             >> 0x0000001cU)));
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__entry[0U] 
        = ((0xfffe0007U & __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__entry[0U]) 
           | (0xfffffff8U & (0x00000070U | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__op) 
                                            << 0x0000000bU))));
    VL_ASSIGN_W(280, __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__rob_entry, Vtb_ozone_backend__ConstPool__CONST_h083ec1be_0);
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__rob_entry[8U] 
        = ((0x00801fffU & __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__rob_entry[8U]) 
           | (0x00ffe000U & (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__dest_reg) 
                              << 0x00000010U) | ((((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__has_dest)
                                                    ? 1U
                                                    : 0U) 
                                                  << 0x0000000eU) 
                                                 | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__has_dest) 
                                                    << 0x0000000dU)))));
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__rob_entry[6U] 
        = ((0xffffefffU & __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__rob_entry[6U]) 
           | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__writes_nzcv) 
              << 0x0000000cU));
    Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9448__0(vlSelf, 
                                                            "@(negedge tb_ozone_backend.clk)");
    co_await vlSelfRef.__VtrigSched_h0e5d9448__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_ozone_backend.clk)", 
                                                         "tb/tb_ozone_backend.sv", 
                                                         543);
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[0U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__rob_entry[0U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[1U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__rob_entry[1U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[2U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__rob_entry[2U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[3U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__rob_entry[3U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[4U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__rob_entry[4U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[5U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__rob_entry[5U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[6U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__rob_entry[6U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[7U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__rob_entry[7U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[8U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__rob_entry[8U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_has_dest 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__has_dest;
    vlSelfRef.tb_ozone_backend__DOT__rob_alloc_valid = 1U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[0U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__entry[0U];
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[1U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__entry[1U];
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[2U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__entry[2U];
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[3U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__entry[3U];
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[4U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__entry[4U];
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[5U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__entry[5U];
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_valid = 1U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_en = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__has_dest;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_addr = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__dest_reg;
    vlSelfRef.tb_ozone_backend__DOT__disp_rob_idx = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__tag_out;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_wr_en 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__writes_nzcv;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_rob_idx 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__tag_out;
    Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9782__0(vlSelf, 
                                                            "@(posedge tb_ozone_backend.clk)");
    co_await vlSelfRef.__VtrigSched_h0e5d9782__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_ozone_backend.clk)", 
                                                         "tb/tb_ozone_backend.sv", 
                                                         554);
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_ozone_backend.sv", 
                                         555);
    vlSelfRef.tb_ozone_backend__DOT__src1_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src1_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_en = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_wr_en = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__rob_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__alloc_has_dest = 0U;
    VL_ASSIGN_W(280, vlSelfRef.tb_ozone_backend__DOT__alloc_data, Vtb_ozone_backend__ConstPool__CONST_h083ec1be_0);
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[0U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[1U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[2U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[3U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[4U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[5U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[0U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[1U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[2U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[3U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[4U] = 0U;
    __Vtask_tb_ozone_backend__DOT__test_adder_internal_forwarding__39__cons_tag 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__60__tag_out;
    while ((1U & (~ ((vlSelfRef.tb_ozone_backend__DOT__adder__DOT__result[4U] 
                      >> 0x00000016U) & ((0x0000003fU 
                                          & (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__result[4U] 
                                             >> 0x00000010U)) 
                                         == (IData)(__Vtask_tb_ozone_backend__DOT__test_adder_internal_forwarding__39__prod_tag)))))) {
        Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9782__0(vlSelf, 
                                                                "@(posedge tb_ozone_backend.clk)");
        co_await vlSelfRef.__VtrigSched_h0e5d9782__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_ozone_backend.clk)", 
                                                             "tb/tb_ozone_backend.sv", 
                                                             789);
        co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                             nullptr, 
                                             "tb/tb_ozone_backend.sv", 
                                             790);
    }
    __Vfunc_tb_ozone_backend__DOT__find_adder_slot__63__tag 
        = __Vtask_tb_ozone_backend__DOT__test_adder_internal_forwarding__39__cons_tag;
    __Vfunc_tb_ozone_backend__DOT__find_adder_slot__63__Vfuncout = 0U;
    __Vfunc_tb_ozone_backend__DOT__find_adder_slot__63__Vfuncout = 0xffffffffU;
    if (((vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[0U][0U] 
          >> 0x00000011U) & ((0x0000003fU & (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[0U][0U] 
                                             >> 0x00000012U)) 
                             == (IData)(__Vfunc_tb_ozone_backend__DOT__find_adder_slot__63__tag)))) {
        __Vfunc_tb_ozone_backend__DOT__find_adder_slot__63__Vfuncout = 0U;
    }
    if (((vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[1U][0U] 
          >> 0x00000011U) & ((0x0000003fU & (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[1U][0U] 
                                             >> 0x00000012U)) 
                             == (IData)(__Vfunc_tb_ozone_backend__DOT__find_adder_slot__63__tag)))) {
        __Vfunc_tb_ozone_backend__DOT__find_adder_slot__63__Vfuncout = 1U;
    }
    if (((vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[2U][0U] 
          >> 0x00000011U) & ((0x0000003fU & (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[2U][0U] 
                                             >> 0x00000012U)) 
                             == (IData)(__Vfunc_tb_ozone_backend__DOT__find_adder_slot__63__tag)))) {
        __Vfunc_tb_ozone_backend__DOT__find_adder_slot__63__Vfuncout = 2U;
    }
    if (((vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[3U][0U] 
          >> 0x00000011U) & ((0x0000003fU & (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[3U][0U] 
                                             >> 0x00000012U)) 
                             == (IData)(__Vfunc_tb_ozone_backend__DOT__find_adder_slot__63__tag)))) {
        __Vfunc_tb_ozone_backend__DOT__find_adder_slot__63__Vfuncout = 3U;
    }
    __Vtask_tb_ozone_backend__DOT__test_adder_internal_forwarding__39__cons_slot 
        = __Vfunc_tb_ozone_backend__DOT__find_adder_slot__63__Vfuncout;
    vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_true__64__label = "adder consumer still in RS"s;
    __Vtask_tb_ozone_backend__DOT__check_true__64__cond 
        = VL_LTES_III(32, 0U, __Vtask_tb_ozone_backend__DOT__test_adder_internal_forwarding__39__cons_slot);
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_ozone_backend__DOT__check_true__64__cond)))))) {
        tb_ozone_backend__DOT__failures = ((IData)(1U) 
                                           + tb_ozone_backend__DOT__failures);
        VL_WRITEF_NX("[FAIL] %@\n",0,-1,&(vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_true__64__label));
    }
    if (VL_LTES_III(32, 0U, __Vtask_tb_ozone_backend__DOT__test_adder_internal_forwarding__39__cons_slot)) {
        vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_true__65__label = "adder consumer Qj cleared by local forward"s;
        __Vtask_tb_ozone_backend__DOT__check_true__65__cond 
            = (0U == (0x0000003fU & ((vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries
                                      [(3U & __Vtask_tb_ozone_backend__DOT__test_adder_internal_forwarding__39__cons_slot)][1U] 
                                      << 2U) | (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries
                                                [(3U 
                                                  & __Vtask_tb_ozone_backend__DOT__test_adder_internal_forwarding__39__cons_slot)][0U] 
                                                >> 0x0000001eU))));
        if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_ozone_backend__DOT__check_true__65__cond)))))) {
            tb_ozone_backend__DOT__failures = ((IData)(1U) 
                                               + tb_ozone_backend__DOT__failures);
            VL_WRITEF_NX("[FAIL] %@\n",0,-1,&(vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_true__65__label));
        }
        vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_u64__66__label = "adder consumer forwarded value"s;
        __Vtask_tb_ozone_backend__DOT__check_u64__66__expected = 0x000000000000000fULL;
        __Vtask_tb_ozone_backend__DOT__check_u64__66__got 
            = (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries
                                [(3U & __Vtask_tb_ozone_backend__DOT__test_adder_internal_forwarding__39__cons_slot)][5U])) 
                << 0x0000003cU) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries
                                                    [
                                                    (3U 
                                                     & __Vtask_tb_ozone_backend__DOT__test_adder_internal_forwarding__39__cons_slot)][4U])) 
                                    << 0x0000001cU) 
                                   | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries
                                                      [
                                                      (3U 
                                                       & __Vtask_tb_ozone_backend__DOT__test_adder_internal_forwarding__39__cons_slot)][3U])) 
                                      >> 4U)));
        if (VL_UNLIKELY(((__Vtask_tb_ozone_backend__DOT__check_u64__66__got 
                          != __Vtask_tb_ozone_backend__DOT__check_u64__66__expected)))) {
            tb_ozone_backend__DOT__failures = ((IData)(1U) 
                                               + tb_ozone_backend__DOT__failures);
            VL_WRITEF_NX("[FAIL] %@ expected=0x%016x got=0x%016x\n",0,
                         -1,&(vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_u64__66__label),
                         64,__Vtask_tb_ozone_backend__DOT__check_u64__66__expected,
                         64,__Vtask_tb_ozone_backend__DOT__check_u64__66__got);
        }
    }
    vlSelfRef.__Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__67__label = "adder producer commit x4"s;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__67__expected = 0x000000000000000fULL;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__67__reg_idx = 4U;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__67__cycles = 0U;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__67__cycles = 0U;
    while (((((((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                                [((0x1eU >= (0x0000001fU 
                                             & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__67__reg_idx))
                                   ? (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__67__reg_idx)
                                   : 0U)][2U])) << 0x00000039U) 
               | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                                   [((0x1eU >= (0x0000001fU 
                                                & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__67__reg_idx))
                                      ? (0x0000001fU 
                                         & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__67__reg_idx)
                                      : 0U)][1U])) 
                   << 0x00000019U) | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                                                      [
                                                      ((0x1eU 
                                                        >= 
                                                        (0x0000001fU 
                                                         & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__67__reg_idx))
                                                        ? 
                                                       (0x0000001fU 
                                                        & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__67__reg_idx)
                                                        : 0U)][0U])) 
                                      >> 7U))) != __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__67__expected) 
             | (vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                [((0x1eU >= (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__67__reg_idx))
                   ? (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__67__reg_idx)
                   : 0U)][0U] >> 6U)) & VL_GTS_III(32, 0x00000028U, __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__67__cycles))) {
        Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9782__0(vlSelf, 
                                                                "@(posedge tb_ozone_backend.clk)");
        co_await vlSelfRef.__VtrigSched_h0e5d9782__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_ozone_backend.clk)", 
                                                             "tb/tb_ozone_backend.sv", 
                                                             691);
        co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                             nullptr, 
                                             "tb/tb_ozone_backend.sv", 
                                             692);
        __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__67__cycles 
            = ((IData)(1U) + __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__67__cycles);
    }
    vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_u64__68__label 
        = vlSelfRef.__Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__67__label;
    __Vtask_tb_ozone_backend__DOT__check_u64__68__expected 
        = __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__67__expected;
    __Vtask_tb_ozone_backend__DOT__check_u64__68__got 
        = (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                            [((0x1eU >= (0x0000001fU 
                                         & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__67__reg_idx))
                               ? (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__67__reg_idx)
                               : 0U)][2U])) << 0x00000039U) 
           | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                               [((0x1eU >= (0x0000001fU 
                                            & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__67__reg_idx))
                                  ? (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__67__reg_idx)
                                  : 0U)][1U])) << 0x00000019U) 
              | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                                 [((0x1eU >= (0x0000001fU 
                                              & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__67__reg_idx))
                                    ? (0x0000001fU 
                                       & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__67__reg_idx)
                                    : 0U)][0U])) >> 7U)));
    if (VL_UNLIKELY(((__Vtask_tb_ozone_backend__DOT__check_u64__68__got 
                      != __Vtask_tb_ozone_backend__DOT__check_u64__68__expected)))) {
        tb_ozone_backend__DOT__failures = ((IData)(1U) 
                                           + tb_ozone_backend__DOT__failures);
        VL_WRITEF_NX("[FAIL] %@ expected=0x%016x got=0x%016x\n",0,
                     -1,&(vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_u64__68__label),
                     64,__Vtask_tb_ozone_backend__DOT__check_u64__68__expected,
                     64,__Vtask_tb_ozone_backend__DOT__check_u64__68__got);
    }
    vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_true__69__label 
        = VL_CVT_PACK_STR_NN(VL_CONCATN_NNN(vlSelfRef.__Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__67__label, " busy clear"s));
    __Vtask_tb_ozone_backend__DOT__check_true__69__cond 
        = (1U & (~ (vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                    [((0x1eU >= (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__67__reg_idx))
                       ? (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__67__reg_idx)
                       : 0U)][0U] >> 6U)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_ozone_backend__DOT__check_true__69__cond)))))) {
        tb_ozone_backend__DOT__failures = ((IData)(1U) 
                                           + tb_ozone_backend__DOT__failures);
        VL_WRITEF_NX("[FAIL] %@\n",0,-1,&(vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_true__69__label));
    }
    vlSelfRef.__Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__70__label = "adder consumer commit x5"s;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__70__expected = 0x0000000000000014ULL;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__70__reg_idx = 5U;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__70__cycles = 0U;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__70__cycles = 0U;
    while (((((((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                                [((0x1eU >= (0x0000001fU 
                                             & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__70__reg_idx))
                                   ? (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__70__reg_idx)
                                   : 0U)][2U])) << 0x00000039U) 
               | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                                   [((0x1eU >= (0x0000001fU 
                                                & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__70__reg_idx))
                                      ? (0x0000001fU 
                                         & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__70__reg_idx)
                                      : 0U)][1U])) 
                   << 0x00000019U) | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                                                      [
                                                      ((0x1eU 
                                                        >= 
                                                        (0x0000001fU 
                                                         & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__70__reg_idx))
                                                        ? 
                                                       (0x0000001fU 
                                                        & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__70__reg_idx)
                                                        : 0U)][0U])) 
                                      >> 7U))) != __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__70__expected) 
             | (vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                [((0x1eU >= (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__70__reg_idx))
                   ? (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__70__reg_idx)
                   : 0U)][0U] >> 6U)) & VL_GTS_III(32, 0x00000028U, __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__70__cycles))) {
        Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9782__0(vlSelf, 
                                                                "@(posedge tb_ozone_backend.clk)");
        co_await vlSelfRef.__VtrigSched_h0e5d9782__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_ozone_backend.clk)", 
                                                             "tb/tb_ozone_backend.sv", 
                                                             691);
        co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                             nullptr, 
                                             "tb/tb_ozone_backend.sv", 
                                             692);
        __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__70__cycles 
            = ((IData)(1U) + __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__70__cycles);
    }
    vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_u64__71__label 
        = vlSelfRef.__Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__70__label;
    __Vtask_tb_ozone_backend__DOT__check_u64__71__expected 
        = __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__70__expected;
    __Vtask_tb_ozone_backend__DOT__check_u64__71__got 
        = (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                            [((0x1eU >= (0x0000001fU 
                                         & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__70__reg_idx))
                               ? (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__70__reg_idx)
                               : 0U)][2U])) << 0x00000039U) 
           | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                               [((0x1eU >= (0x0000001fU 
                                            & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__70__reg_idx))
                                  ? (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__70__reg_idx)
                                  : 0U)][1U])) << 0x00000019U) 
              | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                                 [((0x1eU >= (0x0000001fU 
                                              & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__70__reg_idx))
                                    ? (0x0000001fU 
                                       & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__70__reg_idx)
                                    : 0U)][0U])) >> 7U)));
    if (VL_UNLIKELY(((__Vtask_tb_ozone_backend__DOT__check_u64__71__got 
                      != __Vtask_tb_ozone_backend__DOT__check_u64__71__expected)))) {
        tb_ozone_backend__DOT__failures = ((IData)(1U) 
                                           + tb_ozone_backend__DOT__failures);
        VL_WRITEF_NX("[FAIL] %@ expected=0x%016x got=0x%016x\n",0,
                     -1,&(vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_u64__71__label),
                     64,__Vtask_tb_ozone_backend__DOT__check_u64__71__expected,
                     64,__Vtask_tb_ozone_backend__DOT__check_u64__71__got);
    }
    vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_true__72__label 
        = VL_CVT_PACK_STR_NN(VL_CONCATN_NNN(vlSelfRef.__Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__70__label, " busy clear"s));
    __Vtask_tb_ozone_backend__DOT__check_true__72__cond 
        = (1U & (~ (vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                    [((0x1eU >= (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__70__reg_idx))
                       ? (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__70__reg_idx)
                       : 0U)][0U] >> 6U)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_ozone_backend__DOT__check_true__72__cond)))))) {
        tb_ozone_backend__DOT__failures = ((IData)(1U) 
                                           + tb_ozone_backend__DOT__failures);
        VL_WRITEF_NX("[FAIL] %@\n",0,-1,&(vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_true__72__label));
    }
    __Vtask_tb_ozone_backend__DOT__test_logic_internal_forwarding__73__prod_tag = 0;
    __Vtask_tb_ozone_backend__DOT__test_logic_internal_forwarding__73__cons_tag = 0;
    __Vtask_tb_ozone_backend__DOT__test_logic_internal_forwarding__73__cons_slot = 0U;
    VL_WRITEF_NX("Running logic internal forwarding\n",0);
    __Vtask_tb_ozone_backend__DOT__reset_dut__74__tb_ozone_backend__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    vlSelfRef.tb_ozone_backend__DOT__src1_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src1_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_en = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_wr_en = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__rob_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__alloc_has_dest = 0U;
    VL_ASSIGN_W(280, vlSelfRef.tb_ozone_backend__DOT__alloc_data, Vtb_ozone_backend__ConstPool__CONST_h083ec1be_0);
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[0U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[1U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[2U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[3U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[4U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[5U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[0U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[1U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[2U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[3U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[4U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__rst_n = 0U;
    __Vtask_tb_ozone_backend__DOT__reset_dut__74__tb_ozone_backend__DOT__unnamedblk1_1__DOT____Vrepeat0 = 3U;
    while (VL_LTS_III(32, 0U, __Vtask_tb_ozone_backend__DOT__reset_dut__74__tb_ozone_backend__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9782__0(vlSelf, 
                                                                "@(posedge tb_ozone_backend.clk)");
        co_await vlSelfRef.__VtrigSched_h0e5d9782__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_ozone_backend.clk)", 
                                                             "tb/tb_ozone_backend.sv", 
                                                             380);
        __Vtask_tb_ozone_backend__DOT__reset_dut__74__tb_ozone_backend__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (__Vtask_tb_ozone_backend__DOT__reset_dut__74__tb_ozone_backend__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    vlSelfRef.tb_ozone_backend__DOT__rst_n = 1U;
    Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9782__0(vlSelf, 
                                                            "@(posedge tb_ozone_backend.clk)");
    co_await vlSelfRef.__VtrigSched_h0e5d9782__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_ozone_backend.clk)", 
                                                         "tb/tb_ozone_backend.sv", 
                                                         382);
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_ozone_backend.sv", 
                                         383);
    vlSelfRef.tb_ozone_backend__DOT__src1_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src1_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_en = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_wr_en = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__rob_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__alloc_has_dest = 0U;
    VL_ASSIGN_W(280, vlSelfRef.tb_ozone_backend__DOT__alloc_data, Vtb_ozone_backend__ConstPool__CONST_h083ec1be_0);
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[0U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[1U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[2U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[3U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[4U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[5U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[0U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[1U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[2U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[3U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[4U] = 0U;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__77__value = 0x000000000000f0f0ULL;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__77__idx = 1U;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__77____Vlvbound_hee8445f9__0 = 0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__77____Vlvbound_hee492a18__0 = 0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__77____Vlvbound_hffe4168d__0 = 0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__77____Vlvbound_hffe4168d__0 
        = __Vtask_tb_ozone_backend__DOT__preload_gpr__77__value;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__77____Vlvbound_hee492a18__0 = 0U;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__77____Vlvbound_hee8445f9__0 = 0U;
    if (VL_LIKELY(((0x1eU >= (0x0000001fU & __Vtask_tb_ozone_backend__DOT__preload_gpr__77__idx))))) {
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__77__idx)][0U] 
            = ((0x0000007fU & vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                [(0x0000001fU & __Vtask_tb_ozone_backend__DOT__preload_gpr__77__idx)][0U]) 
               | ((IData)(__Vtask_tb_ozone_backend__DOT__preload_gpr__77____Vlvbound_hffe4168d__0) 
                  << 7U));
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__77__idx)][1U] 
            = (((IData)(__Vtask_tb_ozone_backend__DOT__preload_gpr__77____Vlvbound_hffe4168d__0) 
                >> 0x00000019U) | ((IData)((__Vtask_tb_ozone_backend__DOT__preload_gpr__77____Vlvbound_hffe4168d__0 
                                            >> 0x00000020U)) 
                                   << 7U));
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__77__idx)][2U] 
            = ((IData)((__Vtask_tb_ozone_backend__DOT__preload_gpr__77____Vlvbound_hffe4168d__0 
                        >> 0x00000020U)) >> 0x00000019U);
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__77__idx)][0U] 
            = ((0xffffffbfU & vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                [(0x0000001fU & __Vtask_tb_ozone_backend__DOT__preload_gpr__77__idx)][0U]) 
               | ((IData)(__Vtask_tb_ozone_backend__DOT__preload_gpr__77____Vlvbound_hee492a18__0) 
                  << 6U));
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__77__idx)][0U] 
            = ((0xffffffc0U & vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                [(0x0000001fU & __Vtask_tb_ozone_backend__DOT__preload_gpr__77__idx)][0U]) 
               | (IData)(__Vtask_tb_ozone_backend__DOT__preload_gpr__77____Vlvbound_hee8445f9__0));
    }
    __Vtask_tb_ozone_backend__DOT__preload_gpr__78__value = 0x00000000000000ffULL;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__78__idx = 2U;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__78____Vlvbound_hee8445f9__0 = 0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__78____Vlvbound_hee492a18__0 = 0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__78____Vlvbound_hffe4168d__0 = 0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__78____Vlvbound_hffe4168d__0 
        = __Vtask_tb_ozone_backend__DOT__preload_gpr__78__value;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__78____Vlvbound_hee492a18__0 = 0U;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__78____Vlvbound_hee8445f9__0 = 0U;
    if (VL_LIKELY(((0x1eU >= (0x0000001fU & __Vtask_tb_ozone_backend__DOT__preload_gpr__78__idx))))) {
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__78__idx)][0U] 
            = ((0x0000007fU & vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                [(0x0000001fU & __Vtask_tb_ozone_backend__DOT__preload_gpr__78__idx)][0U]) 
               | ((IData)(__Vtask_tb_ozone_backend__DOT__preload_gpr__78____Vlvbound_hffe4168d__0) 
                  << 7U));
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__78__idx)][1U] 
            = (((IData)(__Vtask_tb_ozone_backend__DOT__preload_gpr__78____Vlvbound_hffe4168d__0) 
                >> 0x00000019U) | ((IData)((__Vtask_tb_ozone_backend__DOT__preload_gpr__78____Vlvbound_hffe4168d__0 
                                            >> 0x00000020U)) 
                                   << 7U));
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__78__idx)][2U] 
            = ((IData)((__Vtask_tb_ozone_backend__DOT__preload_gpr__78____Vlvbound_hffe4168d__0 
                        >> 0x00000020U)) >> 0x00000019U);
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__78__idx)][0U] 
            = ((0xffffffbfU & vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                [(0x0000001fU & __Vtask_tb_ozone_backend__DOT__preload_gpr__78__idx)][0U]) 
               | ((IData)(__Vtask_tb_ozone_backend__DOT__preload_gpr__78____Vlvbound_hee492a18__0) 
                  << 6U));
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__78__idx)][0U] 
            = ((0xffffffc0U & vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                [(0x0000001fU & __Vtask_tb_ozone_backend__DOT__preload_gpr__78__idx)][0U]) 
               | (IData)(__Vtask_tb_ozone_backend__DOT__preload_gpr__78____Vlvbound_hee8445f9__0));
    }
    __Vtask_tb_ozone_backend__DOT__preload_gpr__79__value = 0x0000000000000ff0ULL;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__79__idx = 3U;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__79____Vlvbound_hee8445f9__0 = 0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__79____Vlvbound_hee492a18__0 = 0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__79____Vlvbound_hffe4168d__0 = 0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__79____Vlvbound_hffe4168d__0 
        = __Vtask_tb_ozone_backend__DOT__preload_gpr__79__value;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__79____Vlvbound_hee492a18__0 = 0U;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__79____Vlvbound_hee8445f9__0 = 0U;
    if (VL_LIKELY(((0x1eU >= (0x0000001fU & __Vtask_tb_ozone_backend__DOT__preload_gpr__79__idx))))) {
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__79__idx)][0U] 
            = ((0x0000007fU & vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                [(0x0000001fU & __Vtask_tb_ozone_backend__DOT__preload_gpr__79__idx)][0U]) 
               | ((IData)(__Vtask_tb_ozone_backend__DOT__preload_gpr__79____Vlvbound_hffe4168d__0) 
                  << 7U));
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__79__idx)][1U] 
            = (((IData)(__Vtask_tb_ozone_backend__DOT__preload_gpr__79____Vlvbound_hffe4168d__0) 
                >> 0x00000019U) | ((IData)((__Vtask_tb_ozone_backend__DOT__preload_gpr__79____Vlvbound_hffe4168d__0 
                                            >> 0x00000020U)) 
                                   << 7U));
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__79__idx)][2U] 
            = ((IData)((__Vtask_tb_ozone_backend__DOT__preload_gpr__79____Vlvbound_hffe4168d__0 
                        >> 0x00000020U)) >> 0x00000019U);
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__79__idx)][0U] 
            = ((0xffffffbfU & vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                [(0x0000001fU & __Vtask_tb_ozone_backend__DOT__preload_gpr__79__idx)][0U]) 
               | ((IData)(__Vtask_tb_ozone_backend__DOT__preload_gpr__79____Vlvbound_hee492a18__0) 
                  << 6U));
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__79__idx)][0U] 
            = ((0xffffffc0U & vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                [(0x0000001fU & __Vtask_tb_ozone_backend__DOT__preload_gpr__79__idx)][0U]) 
               | (IData)(__Vtask_tb_ozone_backend__DOT__preload_gpr__79____Vlvbound_hee8445f9__0));
    }
    __Vtask_tb_ozone_backend__DOT__preload_gpr__80__value = 0x000000000000000fULL;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__80__idx = 6U;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__80____Vlvbound_hee8445f9__0 = 0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__80____Vlvbound_hee492a18__0 = 0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__80____Vlvbound_hffe4168d__0 = 0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__80____Vlvbound_hffe4168d__0 
        = __Vtask_tb_ozone_backend__DOT__preload_gpr__80__value;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__80____Vlvbound_hee492a18__0 = 0U;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__80____Vlvbound_hee8445f9__0 = 0U;
    if (VL_LIKELY(((0x1eU >= (0x0000001fU & __Vtask_tb_ozone_backend__DOT__preload_gpr__80__idx))))) {
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__80__idx)][0U] 
            = ((0x0000007fU & vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                [(0x0000001fU & __Vtask_tb_ozone_backend__DOT__preload_gpr__80__idx)][0U]) 
               | ((IData)(__Vtask_tb_ozone_backend__DOT__preload_gpr__80____Vlvbound_hffe4168d__0) 
                  << 7U));
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__80__idx)][1U] 
            = (((IData)(__Vtask_tb_ozone_backend__DOT__preload_gpr__80____Vlvbound_hffe4168d__0) 
                >> 0x00000019U) | ((IData)((__Vtask_tb_ozone_backend__DOT__preload_gpr__80____Vlvbound_hffe4168d__0 
                                            >> 0x00000020U)) 
                                   << 7U));
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__80__idx)][2U] 
            = ((IData)((__Vtask_tb_ozone_backend__DOT__preload_gpr__80____Vlvbound_hffe4168d__0 
                        >> 0x00000020U)) >> 0x00000019U);
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__80__idx)][0U] 
            = ((0xffffffbfU & vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                [(0x0000001fU & __Vtask_tb_ozone_backend__DOT__preload_gpr__80__idx)][0U]) 
               | ((IData)(__Vtask_tb_ozone_backend__DOT__preload_gpr__80____Vlvbound_hee492a18__0) 
                  << 6U));
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__80__idx)][0U] 
            = ((0xffffffc0U & vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                [(0x0000001fU & __Vtask_tb_ozone_backend__DOT__preload_gpr__80__idx)][0U]) 
               | (IData)(__Vtask_tb_ozone_backend__DOT__preload_gpr__80____Vlvbound_hee8445f9__0));
    }
    __Vtask_tb_ozone_backend__DOT__warmup_tag_zero__81__expected = 0;
    __Vtask_tb_ozone_backend__DOT__warmup_tag_zero__81__expected 
        = ((((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[1U][2U])) 
             << 0x00000039U) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[1U][1U])) 
                                 << 0x00000019U) | 
                                ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[1U][0U])) 
                                 >> 7U))) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[2U][2U])) 
                                              << 0x00000039U) 
                                             | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[2U][1U])) 
                                                 << 0x00000019U) 
                                                | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[2U][0U])) 
                                                   >> 7U))));
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__writes_nzcv = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__has_dest = 1U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__dest_reg = 0x1eU;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__reg_b = 2U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__reg_a = 1U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__op = 0x13U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__tag_out = 0;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__vj = 0;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__vk = 0;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__qj = 0;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__qk = 0;
    VL_ZERO_W(159, __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__entry);
    VL_ZERO_W(280, __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__rob_entry);
    while (((0x40U == (IData)(vlSelfRef.tb_ozone_backend__DOT__rob__DOT__count)) 
            | (IData)(vlSelfRef.tb_ozone_backend__DOT__logic_full))) {
        Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9448__0(vlSelf, 
                                                                "@(negedge tb_ozone_backend.clk)");
        co_await vlSelfRef.__VtrigSched_h0e5d9448__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_ozone_backend.clk)", 
                                                             "tb/tb_ozone_backend.sv", 
                                                             576);
    }
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__83__reg_b 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__reg_b;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__83__reg_a 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__reg_a;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__83__vj = 0;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__83__qj = 0;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__83__vk = 0;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__83__qk = 0;
    vlSelfRef.tb_ozone_backend__DOT__src1_addr = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__83__reg_a;
    vlSelfRef.tb_ozone_backend__DOT__src2_addr = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__83__reg_b;
    vlSelfRef.tb_ozone_backend__DOT__src1_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_rob_idx = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_ozone_backend.sv", 
                                         452);
    vlSelfRef.tb_ozone_backend__DOT__src1_rob_idx = 
        (0x0000003fU & vlSelfRef.tb_ozone_backend__DOT__src1_status[0U]);
    vlSelfRef.tb_ozone_backend__DOT__src2_rob_idx = 
        (0x0000003fU & vlSelfRef.tb_ozone_backend__DOT__src2_status[0U]);
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_ozone_backend.sv", 
                                         456);
    if ((0x00000040U & vlSelfRef.tb_ozone_backend__DOT__src1_status[0U])) {
        if (vlSelfRef.tb_ozone_backend__DOT__src1_ready) {
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__83__vj 
                = vlSelfRef.tb_ozone_backend__DOT__src1_value;
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__83__qj = 0U;
        } else {
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__83__vj = 0ULL;
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__83__qj 
                = (0x0000003fU & vlSelfRef.tb_ozone_backend__DOT__src1_status[0U]);
        }
    } else {
        __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__83__vj 
            = (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src1_status[2U])) 
                << 0x00000039U) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src1_status[1U])) 
                                    << 0x00000019U) 
                                   | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src1_status[0U])) 
                                      >> 7U)));
        __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__83__qj = 0U;
    }
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__vj 
        = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__83__vj;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__qj 
        = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__83__qj;
    if ((0x00000040U & vlSelfRef.tb_ozone_backend__DOT__src2_status[0U])) {
        if (vlSelfRef.tb_ozone_backend__DOT__src2_ready) {
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__83__vk 
                = vlSelfRef.tb_ozone_backend__DOT__src2_value;
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__83__qk = 0U;
        } else {
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__83__vk = 0ULL;
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__83__qk 
                = (0x0000003fU & vlSelfRef.tb_ozone_backend__DOT__src2_status[0U]);
        }
    } else {
        __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__83__vk 
            = (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src2_status[2U])) 
                << 0x00000039U) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src2_status[1U])) 
                                    << 0x00000019U) 
                                   | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src2_status[0U])) 
                                      >> 7U)));
        __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__83__qk = 0U;
    }
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__vk 
        = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__83__vk;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__qk 
        = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__83__qk;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__tag_out 
        = vlSelfRef.tb_ozone_backend__DOT__rob__DOT__tail;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__entry[0U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__entry[1U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__entry[2U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__entry[3U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__entry[4U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__entry[0U] 
        = ((0x00000fffU & __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__entry[0U]) 
           | (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__vk) 
               << 0x0000001eU) | (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__qj) 
                                   << 0x00000018U) 
                                  | (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__qk) 
                                      << 0x00000012U) 
                                     | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__tag_out) 
                                        << 0x0000000cU)))));
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__entry[1U] 
        = (((0x00000fffU & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__vk) 
                            >> 2U)) | ((0x00000fffU 
                                        & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__qj) 
                                           >> 8U)) 
                                       | ((0x00000fffU 
                                           & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__qk) 
                                              >> 0x0000000eU)) 
                                          | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__tag_out) 
                                             >> 0x00000014U)))) 
           | ((0x3ffff000U & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__vk) 
                              >> 2U)) | ((IData)((__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__vk 
                                                  >> 0x00000020U)) 
                                         << 0x0000001eU)));
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__entry[2U] 
        = ((0xc0000000U & __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__entry[2U]) 
           | ((0x00000fffU & ((IData)((__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__vk 
                                       >> 0x00000020U)) 
                              >> 2U)) | (0x3ffff000U 
                                         & ((IData)(
                                                    (__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__vk 
                                                     >> 0x00000020U)) 
                                            >> 2U))));
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__entry[2U] 
        = ((0x3fffffffU & __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__entry[2U]) 
           | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__vj) 
              << 0x0000001eU));
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__entry[3U] 
        = (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__vj) 
            >> 2U) | ((IData)((__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__vj 
                               >> 0x00000020U)) << 0x0000001eU));
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__entry[4U] 
        = ((0x40000000U & __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__entry[4U]) 
           | (0x7fffffffU & ((IData)((__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__vj 
                                      >> 0x00000020U)) 
                             >> 2U)));
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__entry[0U] 
        = ((0xfffff801U & __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__entry[0U]) 
           | (0xfffffffeU & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__op) 
                             << 5U)));
    VL_ASSIGN_W(280, __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__rob_entry, Vtb_ozone_backend__ConstPool__CONST_h083ec1be_0);
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__rob_entry[8U] 
        = ((0x00801fffU & __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__rob_entry[8U]) 
           | (0x00ffe000U & (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__dest_reg) 
                              << 0x00000010U) | ((((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__has_dest)
                                                    ? 1U
                                                    : 0U) 
                                                  << 0x0000000eU) 
                                                 | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__has_dest) 
                                                    << 0x0000000dU)))));
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__rob_entry[6U] 
        = ((0xffffefffU & __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__rob_entry[6U]) 
           | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__writes_nzcv) 
              << 0x0000000cU));
    Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9448__0(vlSelf, 
                                                            "@(negedge tb_ozone_backend.clk)");
    co_await vlSelfRef.__VtrigSched_h0e5d9448__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_ozone_backend.clk)", 
                                                         "tb/tb_ozone_backend.sv", 
                                                         596);
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[0U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__rob_entry[0U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[1U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__rob_entry[1U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[2U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__rob_entry[2U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[3U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__rob_entry[3U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[4U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__rob_entry[4U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[5U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__rob_entry[5U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[6U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__rob_entry[6U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[7U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__rob_entry[7U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[8U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__rob_entry[8U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_has_dest 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__has_dest;
    vlSelfRef.tb_ozone_backend__DOT__rob_alloc_valid = 1U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[0U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__entry[0U];
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[1U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__entry[1U];
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[2U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__entry[2U];
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[3U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__entry[3U];
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[4U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__entry[4U];
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_valid = 1U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_en = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__has_dest;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_addr = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__dest_reg;
    vlSelfRef.tb_ozone_backend__DOT__disp_rob_idx = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__tag_out;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_wr_en 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__writes_nzcv;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_rob_idx 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__82__tag_out;
    Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9782__0(vlSelf, 
                                                            "@(posedge tb_ozone_backend.clk)");
    co_await vlSelfRef.__VtrigSched_h0e5d9782__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_ozone_backend.clk)", 
                                                         "tb/tb_ozone_backend.sv", 
                                                         607);
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_ozone_backend.sv", 
                                         608);
    vlSelfRef.tb_ozone_backend__DOT__src1_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src1_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_en = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_wr_en = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__rob_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__alloc_has_dest = 0U;
    VL_ASSIGN_W(280, vlSelfRef.tb_ozone_backend__DOT__alloc_data, Vtb_ozone_backend__ConstPool__CONST_h083ec1be_0);
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[0U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[1U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[2U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[3U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[4U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[5U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[0U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[1U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[2U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[3U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[4U] = 0U;
    vlSelfRef.__Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__85__label = "warmup x30"s;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__85__expected 
        = __Vtask_tb_ozone_backend__DOT__warmup_tag_zero__81__expected;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__85__reg_idx = 0x0000001eU;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__85__cycles = 0U;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__85__cycles = 0U;
    while (((((((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                                [((0x1eU >= (0x0000001fU 
                                             & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__85__reg_idx))
                                   ? (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__85__reg_idx)
                                   : 0U)][2U])) << 0x00000039U) 
               | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                                   [((0x1eU >= (0x0000001fU 
                                                & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__85__reg_idx))
                                      ? (0x0000001fU 
                                         & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__85__reg_idx)
                                      : 0U)][1U])) 
                   << 0x00000019U) | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                                                      [
                                                      ((0x1eU 
                                                        >= 
                                                        (0x0000001fU 
                                                         & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__85__reg_idx))
                                                        ? 
                                                       (0x0000001fU 
                                                        & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__85__reg_idx)
                                                        : 0U)][0U])) 
                                      >> 7U))) != __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__85__expected) 
             | (vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                [((0x1eU >= (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__85__reg_idx))
                   ? (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__85__reg_idx)
                   : 0U)][0U] >> 6U)) & VL_GTS_III(32, 0x00000028U, __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__85__cycles))) {
        Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9782__0(vlSelf, 
                                                                "@(posedge tb_ozone_backend.clk)");
        co_await vlSelfRef.__VtrigSched_h0e5d9782__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_ozone_backend.clk)", 
                                                             "tb/tb_ozone_backend.sv", 
                                                             691);
        co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                             nullptr, 
                                             "tb/tb_ozone_backend.sv", 
                                             692);
        __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__85__cycles 
            = ((IData)(1U) + __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__85__cycles);
    }
    vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_u64__86__label 
        = vlSelfRef.__Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__85__label;
    __Vtask_tb_ozone_backend__DOT__check_u64__86__expected 
        = __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__85__expected;
    __Vtask_tb_ozone_backend__DOT__check_u64__86__got 
        = (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                            [((0x1eU >= (0x0000001fU 
                                         & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__85__reg_idx))
                               ? (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__85__reg_idx)
                               : 0U)][2U])) << 0x00000039U) 
           | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                               [((0x1eU >= (0x0000001fU 
                                            & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__85__reg_idx))
                                  ? (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__85__reg_idx)
                                  : 0U)][1U])) << 0x00000019U) 
              | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                                 [((0x1eU >= (0x0000001fU 
                                              & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__85__reg_idx))
                                    ? (0x0000001fU 
                                       & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__85__reg_idx)
                                    : 0U)][0U])) >> 7U)));
    if (VL_UNLIKELY(((__Vtask_tb_ozone_backend__DOT__check_u64__86__got 
                      != __Vtask_tb_ozone_backend__DOT__check_u64__86__expected)))) {
        tb_ozone_backend__DOT__failures = ((IData)(1U) 
                                           + tb_ozone_backend__DOT__failures);
        VL_WRITEF_NX("[FAIL] %@ expected=0x%016x got=0x%016x\n",0,
                     -1,&(vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_u64__86__label),
                     64,__Vtask_tb_ozone_backend__DOT__check_u64__86__expected,
                     64,__Vtask_tb_ozone_backend__DOT__check_u64__86__got);
    }
    vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_true__87__label 
        = VL_CVT_PACK_STR_NN(VL_CONCATN_NNN(vlSelfRef.__Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__85__label, " busy clear"s));
    __Vtask_tb_ozone_backend__DOT__check_true__87__cond 
        = (1U & (~ (vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                    [((0x1eU >= (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__85__reg_idx))
                       ? (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__85__reg_idx)
                       : 0U)][0U] >> 6U)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_ozone_backend__DOT__check_true__87__cond)))))) {
        tb_ozone_backend__DOT__failures = ((IData)(1U) 
                                           + tb_ozone_backend__DOT__failures);
        VL_WRITEF_NX("[FAIL] %@\n",0,-1,&(vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_true__87__label));
    }
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__writes_nzcv = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__has_dest = 1U;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__dest_reg = 0x0aU;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__reg_b = 2U;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__reg_a = 1U;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__op = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__tag_out = 0;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__vj = 0;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__vk = 0;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__qj = 0;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__qk = 0;
    VL_ZERO_W(165, __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__entry);
    VL_ZERO_W(280, __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__rob_entry);
    while (((0x40U == (IData)(vlSelfRef.tb_ozone_backend__DOT__rob__DOT__count)) 
            | (IData)(vlSelfRef.tb_ozone_backend__DOT__adder_full))) {
        Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9448__0(vlSelf, 
                                                                "@(negedge tb_ozone_backend.clk)");
        co_await vlSelfRef.__VtrigSched_h0e5d9448__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_ozone_backend.clk)", 
                                                             "tb/tb_ozone_backend.sv", 
                                                             522);
    }
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__89__reg_b 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__reg_b;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__89__reg_a 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__reg_a;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__89__vj = 0;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__89__qj = 0;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__89__vk = 0;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__89__qk = 0;
    vlSelfRef.tb_ozone_backend__DOT__src1_addr = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__89__reg_a;
    vlSelfRef.tb_ozone_backend__DOT__src2_addr = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__89__reg_b;
    vlSelfRef.tb_ozone_backend__DOT__src1_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_rob_idx = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_ozone_backend.sv", 
                                         452);
    vlSelfRef.tb_ozone_backend__DOT__src1_rob_idx = 
        (0x0000003fU & vlSelfRef.tb_ozone_backend__DOT__src1_status[0U]);
    vlSelfRef.tb_ozone_backend__DOT__src2_rob_idx = 
        (0x0000003fU & vlSelfRef.tb_ozone_backend__DOT__src2_status[0U]);
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_ozone_backend.sv", 
                                         456);
    if ((0x00000040U & vlSelfRef.tb_ozone_backend__DOT__src1_status[0U])) {
        if (vlSelfRef.tb_ozone_backend__DOT__src1_ready) {
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__89__vj 
                = vlSelfRef.tb_ozone_backend__DOT__src1_value;
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__89__qj = 0U;
        } else {
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__89__vj = 0ULL;
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__89__qj 
                = (0x0000003fU & vlSelfRef.tb_ozone_backend__DOT__src1_status[0U]);
        }
    } else {
        __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__89__vj 
            = (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src1_status[2U])) 
                << 0x00000039U) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src1_status[1U])) 
                                    << 0x00000019U) 
                                   | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src1_status[0U])) 
                                      >> 7U)));
        __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__89__qj = 0U;
    }
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__vj 
        = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__89__vj;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__qj 
        = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__89__qj;
    if ((0x00000040U & vlSelfRef.tb_ozone_backend__DOT__src2_status[0U])) {
        if (vlSelfRef.tb_ozone_backend__DOT__src2_ready) {
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__89__vk 
                = vlSelfRef.tb_ozone_backend__DOT__src2_value;
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__89__qk = 0U;
        } else {
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__89__vk = 0ULL;
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__89__qk 
                = (0x0000003fU & vlSelfRef.tb_ozone_backend__DOT__src2_status[0U]);
        }
    } else {
        __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__89__vk 
            = (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src2_status[2U])) 
                << 0x00000039U) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src2_status[1U])) 
                                    << 0x00000019U) 
                                   | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src2_status[0U])) 
                                      >> 7U)));
        __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__89__qk = 0U;
    }
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__vk 
        = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__89__vk;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__qk 
        = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__89__qk;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__tag_out 
        = vlSelfRef.tb_ozone_backend__DOT__rob__DOT__tail;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__entry[0U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__entry[1U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__entry[2U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__entry[3U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__entry[4U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__entry[5U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__entry[0U] 
        = ((0x0003ffffU & __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__entry[0U]) 
           | (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__qj) 
               << 0x0000001eU) | (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__qk) 
                                   << 0x00000018U) 
                                  | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__tag_out) 
                                     << 0x00000012U))));
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__entry[1U] 
        = (((0x0003fff0U & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__vk) 
                            << 4U)) | ((0x0003ffffU 
                                        & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__qj) 
                                           >> 2U)) 
                                       | ((0x0003ffffU 
                                           & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__qk) 
                                              >> 8U)) 
                                          | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__tag_out) 
                                             >> 0x0000000eU)))) 
           | (0xfffc0000U & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__vk) 
                             << 4U)));
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__entry[2U] 
        = ((((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__vk) 
             >> 0x0000001cU) | (0x0003fff0U & ((IData)(
                                                       (__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__vk 
                                                        >> 0x00000020U)) 
                                               << 4U))) 
           | (0xfffc0000U & ((IData)((__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__vk 
                                      >> 0x00000020U)) 
                             << 4U)));
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__entry[3U] 
        = ((0xfffffff0U & __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__entry[3U]) 
           | ((IData)((__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__vk 
                       >> 0x00000020U)) >> 0x0000001cU));
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__entry[3U] 
        = ((0x0000000fU & __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__entry[3U]) 
           | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__vj) 
              << 4U));
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__entry[4U] 
        = (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__vj) 
            >> 0x0000001cU) | ((IData)((__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__vj 
                                        >> 0x00000020U)) 
                               << 4U));
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__entry[5U] 
        = ((0x00000010U & __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__entry[5U]) 
           | (0x0000001fU & ((IData)((__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__vj 
                                      >> 0x00000020U)) 
                             >> 0x0000001cU)));
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__entry[0U] 
        = ((0xfffe0007U & __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__entry[0U]) 
           | (0xfffffff8U & (0x00000070U | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__op) 
                                            << 0x0000000bU))));
    VL_ASSIGN_W(280, __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__rob_entry, Vtb_ozone_backend__ConstPool__CONST_h083ec1be_0);
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__rob_entry[8U] 
        = ((0x00801fffU & __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__rob_entry[8U]) 
           | (0x00ffe000U & (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__dest_reg) 
                              << 0x00000010U) | ((((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__has_dest)
                                                    ? 1U
                                                    : 0U) 
                                                  << 0x0000000eU) 
                                                 | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__has_dest) 
                                                    << 0x0000000dU)))));
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__rob_entry[6U] 
        = ((0xffffefffU & __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__rob_entry[6U]) 
           | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__writes_nzcv) 
              << 0x0000000cU));
    Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9448__0(vlSelf, 
                                                            "@(negedge tb_ozone_backend.clk)");
    co_await vlSelfRef.__VtrigSched_h0e5d9448__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_ozone_backend.clk)", 
                                                         "tb/tb_ozone_backend.sv", 
                                                         543);
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[0U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__rob_entry[0U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[1U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__rob_entry[1U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[2U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__rob_entry[2U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[3U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__rob_entry[3U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[4U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__rob_entry[4U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[5U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__rob_entry[5U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[6U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__rob_entry[6U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[7U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__rob_entry[7U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[8U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__rob_entry[8U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_has_dest 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__has_dest;
    vlSelfRef.tb_ozone_backend__DOT__rob_alloc_valid = 1U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[0U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__entry[0U];
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[1U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__entry[1U];
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[2U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__entry[2U];
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[3U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__entry[3U];
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[4U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__entry[4U];
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[5U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__entry[5U];
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_valid = 1U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_en = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__has_dest;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_addr = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__dest_reg;
    vlSelfRef.tb_ozone_backend__DOT__disp_rob_idx = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__tag_out;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_wr_en 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__writes_nzcv;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_rob_idx 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__88__tag_out;
    Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9782__0(vlSelf, 
                                                            "@(posedge tb_ozone_backend.clk)");
    co_await vlSelfRef.__VtrigSched_h0e5d9782__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_ozone_backend.clk)", 
                                                         "tb/tb_ozone_backend.sv", 
                                                         554);
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_ozone_backend.sv", 
                                         555);
    vlSelfRef.tb_ozone_backend__DOT__src1_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src1_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_en = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_wr_en = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__rob_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__alloc_has_dest = 0U;
    VL_ASSIGN_W(280, vlSelfRef.tb_ozone_backend__DOT__alloc_data, Vtb_ozone_backend__ConstPool__CONST_h083ec1be_0);
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[0U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[1U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[2U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[3U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[4U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[5U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[0U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[1U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[2U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[3U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[4U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__writes_nzcv = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__has_dest = 1U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__dest_reg = 4U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__reg_b = 3U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__reg_a = 0x0aU;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__op = 7U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__tag_out = 0;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__vj = 0;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__vk = 0;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__qj = 0;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__qk = 0;
    VL_ZERO_W(159, __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__entry);
    VL_ZERO_W(280, __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__rob_entry);
    while (((0x40U == (IData)(vlSelfRef.tb_ozone_backend__DOT__rob__DOT__count)) 
            | (IData)(vlSelfRef.tb_ozone_backend__DOT__logic_full))) {
        Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9448__0(vlSelf, 
                                                                "@(negedge tb_ozone_backend.clk)");
        co_await vlSelfRef.__VtrigSched_h0e5d9448__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_ozone_backend.clk)", 
                                                             "tb/tb_ozone_backend.sv", 
                                                             576);
    }
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__92__reg_b 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__reg_b;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__92__reg_a 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__reg_a;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__92__vj = 0;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__92__qj = 0;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__92__vk = 0;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__92__qk = 0;
    vlSelfRef.tb_ozone_backend__DOT__src1_addr = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__92__reg_a;
    vlSelfRef.tb_ozone_backend__DOT__src2_addr = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__92__reg_b;
    vlSelfRef.tb_ozone_backend__DOT__src1_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_rob_idx = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_ozone_backend.sv", 
                                         452);
    vlSelfRef.tb_ozone_backend__DOT__src1_rob_idx = 
        (0x0000003fU & vlSelfRef.tb_ozone_backend__DOT__src1_status[0U]);
    vlSelfRef.tb_ozone_backend__DOT__src2_rob_idx = 
        (0x0000003fU & vlSelfRef.tb_ozone_backend__DOT__src2_status[0U]);
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_ozone_backend.sv", 
                                         456);
    if ((0x00000040U & vlSelfRef.tb_ozone_backend__DOT__src1_status[0U])) {
        if (vlSelfRef.tb_ozone_backend__DOT__src1_ready) {
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__92__vj 
                = vlSelfRef.tb_ozone_backend__DOT__src1_value;
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__92__qj = 0U;
        } else {
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__92__vj = 0ULL;
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__92__qj 
                = (0x0000003fU & vlSelfRef.tb_ozone_backend__DOT__src1_status[0U]);
        }
    } else {
        __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__92__vj 
            = (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src1_status[2U])) 
                << 0x00000039U) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src1_status[1U])) 
                                    << 0x00000019U) 
                                   | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src1_status[0U])) 
                                      >> 7U)));
        __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__92__qj = 0U;
    }
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__vj 
        = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__92__vj;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__qj 
        = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__92__qj;
    if ((0x00000040U & vlSelfRef.tb_ozone_backend__DOT__src2_status[0U])) {
        if (vlSelfRef.tb_ozone_backend__DOT__src2_ready) {
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__92__vk 
                = vlSelfRef.tb_ozone_backend__DOT__src2_value;
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__92__qk = 0U;
        } else {
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__92__vk = 0ULL;
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__92__qk 
                = (0x0000003fU & vlSelfRef.tb_ozone_backend__DOT__src2_status[0U]);
        }
    } else {
        __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__92__vk 
            = (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src2_status[2U])) 
                << 0x00000039U) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src2_status[1U])) 
                                    << 0x00000019U) 
                                   | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src2_status[0U])) 
                                      >> 7U)));
        __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__92__qk = 0U;
    }
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__vk 
        = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__92__vk;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__qk 
        = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__92__qk;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__tag_out 
        = vlSelfRef.tb_ozone_backend__DOT__rob__DOT__tail;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__entry[0U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__entry[1U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__entry[2U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__entry[3U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__entry[4U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__entry[0U] 
        = ((0x00000fffU & __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__entry[0U]) 
           | (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__vk) 
               << 0x0000001eU) | (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__qj) 
                                   << 0x00000018U) 
                                  | (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__qk) 
                                      << 0x00000012U) 
                                     | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__tag_out) 
                                        << 0x0000000cU)))));
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__entry[1U] 
        = (((0x00000fffU & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__vk) 
                            >> 2U)) | ((0x00000fffU 
                                        & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__qj) 
                                           >> 8U)) 
                                       | ((0x00000fffU 
                                           & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__qk) 
                                              >> 0x0000000eU)) 
                                          | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__tag_out) 
                                             >> 0x00000014U)))) 
           | ((0x3ffff000U & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__vk) 
                              >> 2U)) | ((IData)((__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__vk 
                                                  >> 0x00000020U)) 
                                         << 0x0000001eU)));
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__entry[2U] 
        = ((0xc0000000U & __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__entry[2U]) 
           | ((0x00000fffU & ((IData)((__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__vk 
                                       >> 0x00000020U)) 
                              >> 2U)) | (0x3ffff000U 
                                         & ((IData)(
                                                    (__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__vk 
                                                     >> 0x00000020U)) 
                                            >> 2U))));
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__entry[2U] 
        = ((0x3fffffffU & __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__entry[2U]) 
           | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__vj) 
              << 0x0000001eU));
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__entry[3U] 
        = (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__vj) 
            >> 2U) | ((IData)((__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__vj 
                               >> 0x00000020U)) << 0x0000001eU));
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__entry[4U] 
        = ((0x40000000U & __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__entry[4U]) 
           | (0x7fffffffU & ((IData)((__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__vj 
                                      >> 0x00000020U)) 
                             >> 2U)));
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__entry[0U] 
        = ((0xfffff801U & __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__entry[0U]) 
           | (0xfffffffeU & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__op) 
                             << 5U)));
    VL_ASSIGN_W(280, __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__rob_entry, Vtb_ozone_backend__ConstPool__CONST_h083ec1be_0);
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__rob_entry[8U] 
        = ((0x00801fffU & __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__rob_entry[8U]) 
           | (0x00ffe000U & (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__dest_reg) 
                              << 0x00000010U) | ((((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__has_dest)
                                                    ? 1U
                                                    : 0U) 
                                                  << 0x0000000eU) 
                                                 | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__has_dest) 
                                                    << 0x0000000dU)))));
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__rob_entry[6U] 
        = ((0xffffefffU & __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__rob_entry[6U]) 
           | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__writes_nzcv) 
              << 0x0000000cU));
    Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9448__0(vlSelf, 
                                                            "@(negedge tb_ozone_backend.clk)");
    co_await vlSelfRef.__VtrigSched_h0e5d9448__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_ozone_backend.clk)", 
                                                         "tb/tb_ozone_backend.sv", 
                                                         596);
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[0U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__rob_entry[0U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[1U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__rob_entry[1U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[2U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__rob_entry[2U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[3U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__rob_entry[3U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[4U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__rob_entry[4U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[5U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__rob_entry[5U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[6U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__rob_entry[6U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[7U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__rob_entry[7U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[8U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__rob_entry[8U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_has_dest 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__has_dest;
    vlSelfRef.tb_ozone_backend__DOT__rob_alloc_valid = 1U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[0U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__entry[0U];
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[1U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__entry[1U];
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[2U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__entry[2U];
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[3U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__entry[3U];
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[4U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__entry[4U];
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_valid = 1U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_en = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__has_dest;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_addr = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__dest_reg;
    vlSelfRef.tb_ozone_backend__DOT__disp_rob_idx = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__tag_out;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_wr_en 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__writes_nzcv;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_rob_idx 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__tag_out;
    Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9782__0(vlSelf, 
                                                            "@(posedge tb_ozone_backend.clk)");
    co_await vlSelfRef.__VtrigSched_h0e5d9782__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_ozone_backend.clk)", 
                                                         "tb/tb_ozone_backend.sv", 
                                                         607);
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_ozone_backend.sv", 
                                         608);
    vlSelfRef.tb_ozone_backend__DOT__src1_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src1_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_en = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_wr_en = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__rob_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__alloc_has_dest = 0U;
    VL_ASSIGN_W(280, vlSelfRef.tb_ozone_backend__DOT__alloc_data, Vtb_ozone_backend__ConstPool__CONST_h083ec1be_0);
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[0U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[1U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[2U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[3U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[4U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[5U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[0U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[1U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[2U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[3U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[4U] = 0U;
    __Vtask_tb_ozone_backend__DOT__test_logic_internal_forwarding__73__prod_tag 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__91__tag_out;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__writes_nzcv = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__has_dest = 1U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__dest_reg = 5U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__reg_b = 6U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__reg_a = 4U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__op = 0x13U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__tag_out = 0;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__vj = 0;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__vk = 0;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__qj = 0;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__qk = 0;
    VL_ZERO_W(159, __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__entry);
    VL_ZERO_W(280, __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__rob_entry);
    while (((0x40U == (IData)(vlSelfRef.tb_ozone_backend__DOT__rob__DOT__count)) 
            | (IData)(vlSelfRef.tb_ozone_backend__DOT__logic_full))) {
        Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9448__0(vlSelf, 
                                                                "@(negedge tb_ozone_backend.clk)");
        co_await vlSelfRef.__VtrigSched_h0e5d9448__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_ozone_backend.clk)", 
                                                             "tb/tb_ozone_backend.sv", 
                                                             576);
    }
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__95__reg_b 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__reg_b;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__95__reg_a 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__reg_a;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__95__vj = 0;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__95__qj = 0;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__95__vk = 0;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__95__qk = 0;
    vlSelfRef.tb_ozone_backend__DOT__src1_addr = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__95__reg_a;
    vlSelfRef.tb_ozone_backend__DOT__src2_addr = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__95__reg_b;
    vlSelfRef.tb_ozone_backend__DOT__src1_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_rob_idx = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_ozone_backend.sv", 
                                         452);
    vlSelfRef.tb_ozone_backend__DOT__src1_rob_idx = 
        (0x0000003fU & vlSelfRef.tb_ozone_backend__DOT__src1_status[0U]);
    vlSelfRef.tb_ozone_backend__DOT__src2_rob_idx = 
        (0x0000003fU & vlSelfRef.tb_ozone_backend__DOT__src2_status[0U]);
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_ozone_backend.sv", 
                                         456);
    if ((0x00000040U & vlSelfRef.tb_ozone_backend__DOT__src1_status[0U])) {
        if (vlSelfRef.tb_ozone_backend__DOT__src1_ready) {
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__95__vj 
                = vlSelfRef.tb_ozone_backend__DOT__src1_value;
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__95__qj = 0U;
        } else {
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__95__vj = 0ULL;
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__95__qj 
                = (0x0000003fU & vlSelfRef.tb_ozone_backend__DOT__src1_status[0U]);
        }
    } else {
        __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__95__vj 
            = (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src1_status[2U])) 
                << 0x00000039U) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src1_status[1U])) 
                                    << 0x00000019U) 
                                   | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src1_status[0U])) 
                                      >> 7U)));
        __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__95__qj = 0U;
    }
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__vj 
        = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__95__vj;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__qj 
        = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__95__qj;
    if ((0x00000040U & vlSelfRef.tb_ozone_backend__DOT__src2_status[0U])) {
        if (vlSelfRef.tb_ozone_backend__DOT__src2_ready) {
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__95__vk 
                = vlSelfRef.tb_ozone_backend__DOT__src2_value;
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__95__qk = 0U;
        } else {
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__95__vk = 0ULL;
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__95__qk 
                = (0x0000003fU & vlSelfRef.tb_ozone_backend__DOT__src2_status[0U]);
        }
    } else {
        __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__95__vk 
            = (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src2_status[2U])) 
                << 0x00000039U) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src2_status[1U])) 
                                    << 0x00000019U) 
                                   | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src2_status[0U])) 
                                      >> 7U)));
        __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__95__qk = 0U;
    }
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__vk 
        = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__95__vk;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__qk 
        = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__95__qk;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__tag_out 
        = vlSelfRef.tb_ozone_backend__DOT__rob__DOT__tail;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__entry[0U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__entry[1U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__entry[2U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__entry[3U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__entry[4U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__entry[0U] 
        = ((0x00000fffU & __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__entry[0U]) 
           | (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__vk) 
               << 0x0000001eU) | (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__qj) 
                                   << 0x00000018U) 
                                  | (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__qk) 
                                      << 0x00000012U) 
                                     | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__tag_out) 
                                        << 0x0000000cU)))));
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__entry[1U] 
        = (((0x00000fffU & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__vk) 
                            >> 2U)) | ((0x00000fffU 
                                        & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__qj) 
                                           >> 8U)) 
                                       | ((0x00000fffU 
                                           & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__qk) 
                                              >> 0x0000000eU)) 
                                          | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__tag_out) 
                                             >> 0x00000014U)))) 
           | ((0x3ffff000U & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__vk) 
                              >> 2U)) | ((IData)((__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__vk 
                                                  >> 0x00000020U)) 
                                         << 0x0000001eU)));
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__entry[2U] 
        = ((0xc0000000U & __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__entry[2U]) 
           | ((0x00000fffU & ((IData)((__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__vk 
                                       >> 0x00000020U)) 
                              >> 2U)) | (0x3ffff000U 
                                         & ((IData)(
                                                    (__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__vk 
                                                     >> 0x00000020U)) 
                                            >> 2U))));
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__entry[2U] 
        = ((0x3fffffffU & __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__entry[2U]) 
           | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__vj) 
              << 0x0000001eU));
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__entry[3U] 
        = (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__vj) 
            >> 2U) | ((IData)((__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__vj 
                               >> 0x00000020U)) << 0x0000001eU));
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__entry[4U] 
        = ((0x40000000U & __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__entry[4U]) 
           | (0x7fffffffU & ((IData)((__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__vj 
                                      >> 0x00000020U)) 
                             >> 2U)));
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__entry[0U] 
        = ((0xfffff801U & __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__entry[0U]) 
           | (0xfffffffeU & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__op) 
                             << 5U)));
    VL_ASSIGN_W(280, __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__rob_entry, Vtb_ozone_backend__ConstPool__CONST_h083ec1be_0);
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__rob_entry[8U] 
        = ((0x00801fffU & __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__rob_entry[8U]) 
           | (0x00ffe000U & (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__dest_reg) 
                              << 0x00000010U) | ((((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__has_dest)
                                                    ? 1U
                                                    : 0U) 
                                                  << 0x0000000eU) 
                                                 | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__has_dest) 
                                                    << 0x0000000dU)))));
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__rob_entry[6U] 
        = ((0xffffefffU & __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__rob_entry[6U]) 
           | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__writes_nzcv) 
              << 0x0000000cU));
    Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9448__0(vlSelf, 
                                                            "@(negedge tb_ozone_backend.clk)");
    co_await vlSelfRef.__VtrigSched_h0e5d9448__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_ozone_backend.clk)", 
                                                         "tb/tb_ozone_backend.sv", 
                                                         596);
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[0U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__rob_entry[0U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[1U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__rob_entry[1U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[2U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__rob_entry[2U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[3U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__rob_entry[3U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[4U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__rob_entry[4U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[5U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__rob_entry[5U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[6U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__rob_entry[6U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[7U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__rob_entry[7U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[8U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__rob_entry[8U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_has_dest 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__has_dest;
    vlSelfRef.tb_ozone_backend__DOT__rob_alloc_valid = 1U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[0U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__entry[0U];
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[1U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__entry[1U];
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[2U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__entry[2U];
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[3U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__entry[3U];
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[4U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__entry[4U];
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_valid = 1U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_en = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__has_dest;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_addr = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__dest_reg;
    vlSelfRef.tb_ozone_backend__DOT__disp_rob_idx = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__tag_out;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_wr_en 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__writes_nzcv;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_rob_idx 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__tag_out;
    Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9782__0(vlSelf, 
                                                            "@(posedge tb_ozone_backend.clk)");
    co_await vlSelfRef.__VtrigSched_h0e5d9782__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_ozone_backend.clk)", 
                                                         "tb/tb_ozone_backend.sv", 
                                                         607);
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_ozone_backend.sv", 
                                         608);
    vlSelfRef.tb_ozone_backend__DOT__src1_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src1_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_en = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_wr_en = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__rob_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__alloc_has_dest = 0U;
    VL_ASSIGN_W(280, vlSelfRef.tb_ozone_backend__DOT__alloc_data, Vtb_ozone_backend__ConstPool__CONST_h083ec1be_0);
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[0U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[1U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[2U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[3U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[4U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[5U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[0U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[1U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[2U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[3U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[4U] = 0U;
    __Vtask_tb_ozone_backend__DOT__test_logic_internal_forwarding__73__cons_tag 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__94__tag_out;
    while ((1U & (~ ((vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__result[4U] 
                      >> 0x00000016U) & ((0x0000003fU 
                                          & (vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__result[4U] 
                                             >> 0x00000010U)) 
                                         == (IData)(__Vtask_tb_ozone_backend__DOT__test_logic_internal_forwarding__73__prod_tag)))))) {
        Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9782__0(vlSelf, 
                                                                "@(posedge tb_ozone_backend.clk)");
        co_await vlSelfRef.__VtrigSched_h0e5d9782__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_ozone_backend.clk)", 
                                                             "tb/tb_ozone_backend.sv", 
                                                             824);
        co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                             nullptr, 
                                             "tb/tb_ozone_backend.sv", 
                                             825);
    }
    __Vfunc_tb_ozone_backend__DOT__find_logic_slot__97__tag 
        = __Vtask_tb_ozone_backend__DOT__test_logic_internal_forwarding__73__cons_tag;
    __Vfunc_tb_ozone_backend__DOT__find_logic_slot__97__Vfuncout = 0U;
    __Vfunc_tb_ozone_backend__DOT__find_logic_slot__97__Vfuncout = 0xffffffffU;
    if (((vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__entries[0U][0U] 
          >> 0x0000000bU) & ((0x0000003fU & (vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__entries[0U][0U] 
                                             >> 0x0000000cU)) 
                             == (IData)(__Vfunc_tb_ozone_backend__DOT__find_logic_slot__97__tag)))) {
        __Vfunc_tb_ozone_backend__DOT__find_logic_slot__97__Vfuncout = 0U;
    }
    if (((vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__entries[1U][0U] 
          >> 0x0000000bU) & ((0x0000003fU & (vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__entries[1U][0U] 
                                             >> 0x0000000cU)) 
                             == (IData)(__Vfunc_tb_ozone_backend__DOT__find_logic_slot__97__tag)))) {
        __Vfunc_tb_ozone_backend__DOT__find_logic_slot__97__Vfuncout = 1U;
    }
    if (((vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__entries[2U][0U] 
          >> 0x0000000bU) & ((0x0000003fU & (vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__entries[2U][0U] 
                                             >> 0x0000000cU)) 
                             == (IData)(__Vfunc_tb_ozone_backend__DOT__find_logic_slot__97__tag)))) {
        __Vfunc_tb_ozone_backend__DOT__find_logic_slot__97__Vfuncout = 2U;
    }
    if (((vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__entries[3U][0U] 
          >> 0x0000000bU) & ((0x0000003fU & (vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__entries[3U][0U] 
                                             >> 0x0000000cU)) 
                             == (IData)(__Vfunc_tb_ozone_backend__DOT__find_logic_slot__97__tag)))) {
        __Vfunc_tb_ozone_backend__DOT__find_logic_slot__97__Vfuncout = 3U;
    }
    __Vtask_tb_ozone_backend__DOT__test_logic_internal_forwarding__73__cons_slot 
        = __Vfunc_tb_ozone_backend__DOT__find_logic_slot__97__Vfuncout;
    vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_true__98__label = "logic consumer still in RS"s;
    __Vtask_tb_ozone_backend__DOT__check_true__98__cond 
        = VL_LTES_III(32, 0U, __Vtask_tb_ozone_backend__DOT__test_logic_internal_forwarding__73__cons_slot);
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_ozone_backend__DOT__check_true__98__cond)))))) {
        tb_ozone_backend__DOT__failures = ((IData)(1U) 
                                           + tb_ozone_backend__DOT__failures);
        VL_WRITEF_NX("[FAIL] %@\n",0,-1,&(vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_true__98__label));
    }
    if (VL_LTES_III(32, 0U, __Vtask_tb_ozone_backend__DOT__test_logic_internal_forwarding__73__cons_slot)) {
        vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_true__99__label = "logic consumer Qj cleared by local forward"s;
        __Vtask_tb_ozone_backend__DOT__check_true__99__cond 
            = (0U == (0x0000003fU & (vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__entries
                                     [(3U & __Vtask_tb_ozone_backend__DOT__test_logic_internal_forwarding__73__cons_slot)][0U] 
                                     >> 0x00000018U)));
        if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_ozone_backend__DOT__check_true__99__cond)))))) {
            tb_ozone_backend__DOT__failures = ((IData)(1U) 
                                               + tb_ozone_backend__DOT__failures);
            VL_WRITEF_NX("[FAIL] %@\n",0,-1,&(vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_true__99__label));
        }
        vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_u64__100__label = "logic consumer forwarded value"s;
        __Vtask_tb_ozone_backend__DOT__check_u64__100__expected = 0x00000000000001e0ULL;
        __Vtask_tb_ozone_backend__DOT__check_u64__100__got 
            = (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__entries
                                [(3U & __Vtask_tb_ozone_backend__DOT__test_logic_internal_forwarding__73__cons_slot)][4U])) 
                << 0x00000022U) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__entries
                                                    [
                                                    (3U 
                                                     & __Vtask_tb_ozone_backend__DOT__test_logic_internal_forwarding__73__cons_slot)][3U])) 
                                    << 2U) | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__entries
                                                              [
                                                              (3U 
                                                               & __Vtask_tb_ozone_backend__DOT__test_logic_internal_forwarding__73__cons_slot)][2U])) 
                                              >> 0x0000001eU)));
        if (VL_UNLIKELY(((__Vtask_tb_ozone_backend__DOT__check_u64__100__got 
                          != __Vtask_tb_ozone_backend__DOT__check_u64__100__expected)))) {
            tb_ozone_backend__DOT__failures = ((IData)(1U) 
                                               + tb_ozone_backend__DOT__failures);
            VL_WRITEF_NX("[FAIL] %@ expected=0x%016x got=0x%016x\n",0,
                         -1,&(vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_u64__100__label),
                         64,__Vtask_tb_ozone_backend__DOT__check_u64__100__expected,
                         64,__Vtask_tb_ozone_backend__DOT__check_u64__100__got);
        }
    }
    vlSelfRef.__Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__101__label = "logic producer commit x4"s;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__101__expected = 0x00000000000001e0ULL;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__101__reg_idx = 4U;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__101__cycles = 0U;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__101__cycles = 0U;
    while (((((((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                                [((0x1eU >= (0x0000001fU 
                                             & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__101__reg_idx))
                                   ? (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__101__reg_idx)
                                   : 0U)][2U])) << 0x00000039U) 
               | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                                   [((0x1eU >= (0x0000001fU 
                                                & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__101__reg_idx))
                                      ? (0x0000001fU 
                                         & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__101__reg_idx)
                                      : 0U)][1U])) 
                   << 0x00000019U) | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                                                      [
                                                      ((0x1eU 
                                                        >= 
                                                        (0x0000001fU 
                                                         & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__101__reg_idx))
                                                        ? 
                                                       (0x0000001fU 
                                                        & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__101__reg_idx)
                                                        : 0U)][0U])) 
                                      >> 7U))) != __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__101__expected) 
             | (vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                [((0x1eU >= (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__101__reg_idx))
                   ? (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__101__reg_idx)
                   : 0U)][0U] >> 6U)) & VL_GTS_III(32, 0x00000028U, __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__101__cycles))) {
        Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9782__0(vlSelf, 
                                                                "@(posedge tb_ozone_backend.clk)");
        co_await vlSelfRef.__VtrigSched_h0e5d9782__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_ozone_backend.clk)", 
                                                             "tb/tb_ozone_backend.sv", 
                                                             691);
        co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                             nullptr, 
                                             "tb/tb_ozone_backend.sv", 
                                             692);
        __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__101__cycles 
            = ((IData)(1U) + __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__101__cycles);
    }
    vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_u64__102__label 
        = vlSelfRef.__Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__101__label;
    __Vtask_tb_ozone_backend__DOT__check_u64__102__expected 
        = __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__101__expected;
    __Vtask_tb_ozone_backend__DOT__check_u64__102__got 
        = (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                            [((0x1eU >= (0x0000001fU 
                                         & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__101__reg_idx))
                               ? (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__101__reg_idx)
                               : 0U)][2U])) << 0x00000039U) 
           | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                               [((0x1eU >= (0x0000001fU 
                                            & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__101__reg_idx))
                                  ? (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__101__reg_idx)
                                  : 0U)][1U])) << 0x00000019U) 
              | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                                 [((0x1eU >= (0x0000001fU 
                                              & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__101__reg_idx))
                                    ? (0x0000001fU 
                                       & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__101__reg_idx)
                                    : 0U)][0U])) >> 7U)));
    if (VL_UNLIKELY(((__Vtask_tb_ozone_backend__DOT__check_u64__102__got 
                      != __Vtask_tb_ozone_backend__DOT__check_u64__102__expected)))) {
        tb_ozone_backend__DOT__failures = ((IData)(1U) 
                                           + tb_ozone_backend__DOT__failures);
        VL_WRITEF_NX("[FAIL] %@ expected=0x%016x got=0x%016x\n",0,
                     -1,&(vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_u64__102__label),
                     64,__Vtask_tb_ozone_backend__DOT__check_u64__102__expected,
                     64,__Vtask_tb_ozone_backend__DOT__check_u64__102__got);
    }
    vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_true__103__label 
        = VL_CVT_PACK_STR_NN(VL_CONCATN_NNN(vlSelfRef.__Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__101__label, " busy clear"s));
    __Vtask_tb_ozone_backend__DOT__check_true__103__cond 
        = (1U & (~ (vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                    [((0x1eU >= (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__101__reg_idx))
                       ? (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__101__reg_idx)
                       : 0U)][0U] >> 6U)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_ozone_backend__DOT__check_true__103__cond)))))) {
        tb_ozone_backend__DOT__failures = ((IData)(1U) 
                                           + tb_ozone_backend__DOT__failures);
        VL_WRITEF_NX("[FAIL] %@\n",0,-1,&(vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_true__103__label));
    }
    vlSelfRef.__Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__104__label = "logic consumer commit x5"s;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__104__expected = 0x00000000000001efULL;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__104__reg_idx = 5U;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__104__cycles = 0U;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__104__cycles = 0U;
    while (((((((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                                [((0x1eU >= (0x0000001fU 
                                             & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__104__reg_idx))
                                   ? (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__104__reg_idx)
                                   : 0U)][2U])) << 0x00000039U) 
               | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                                   [((0x1eU >= (0x0000001fU 
                                                & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__104__reg_idx))
                                      ? (0x0000001fU 
                                         & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__104__reg_idx)
                                      : 0U)][1U])) 
                   << 0x00000019U) | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                                                      [
                                                      ((0x1eU 
                                                        >= 
                                                        (0x0000001fU 
                                                         & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__104__reg_idx))
                                                        ? 
                                                       (0x0000001fU 
                                                        & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__104__reg_idx)
                                                        : 0U)][0U])) 
                                      >> 7U))) != __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__104__expected) 
             | (vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                [((0x1eU >= (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__104__reg_idx))
                   ? (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__104__reg_idx)
                   : 0U)][0U] >> 6U)) & VL_GTS_III(32, 0x00000028U, __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__104__cycles))) {
        Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9782__0(vlSelf, 
                                                                "@(posedge tb_ozone_backend.clk)");
        co_await vlSelfRef.__VtrigSched_h0e5d9782__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_ozone_backend.clk)", 
                                                             "tb/tb_ozone_backend.sv", 
                                                             691);
        co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                             nullptr, 
                                             "tb/tb_ozone_backend.sv", 
                                             692);
        __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__104__cycles 
            = ((IData)(1U) + __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__104__cycles);
    }
    vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_u64__105__label 
        = vlSelfRef.__Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__104__label;
    __Vtask_tb_ozone_backend__DOT__check_u64__105__expected 
        = __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__104__expected;
    __Vtask_tb_ozone_backend__DOT__check_u64__105__got 
        = (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                            [((0x1eU >= (0x0000001fU 
                                         & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__104__reg_idx))
                               ? (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__104__reg_idx)
                               : 0U)][2U])) << 0x00000039U) 
           | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                               [((0x1eU >= (0x0000001fU 
                                            & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__104__reg_idx))
                                  ? (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__104__reg_idx)
                                  : 0U)][1U])) << 0x00000019U) 
              | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                                 [((0x1eU >= (0x0000001fU 
                                              & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__104__reg_idx))
                                    ? (0x0000001fU 
                                       & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__104__reg_idx)
                                    : 0U)][0U])) >> 7U)));
    if (VL_UNLIKELY(((__Vtask_tb_ozone_backend__DOT__check_u64__105__got 
                      != __Vtask_tb_ozone_backend__DOT__check_u64__105__expected)))) {
        tb_ozone_backend__DOT__failures = ((IData)(1U) 
                                           + tb_ozone_backend__DOT__failures);
        VL_WRITEF_NX("[FAIL] %@ expected=0x%016x got=0x%016x\n",0,
                     -1,&(vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_u64__105__label),
                     64,__Vtask_tb_ozone_backend__DOT__check_u64__105__expected,
                     64,__Vtask_tb_ozone_backend__DOT__check_u64__105__got);
    }
    vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_true__106__label 
        = VL_CVT_PACK_STR_NN(VL_CONCATN_NNN(vlSelfRef.__Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__104__label, " busy clear"s));
    __Vtask_tb_ozone_backend__DOT__check_true__106__cond 
        = (1U & (~ (vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                    [((0x1eU >= (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__104__reg_idx))
                       ? (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__104__reg_idx)
                       : 0U)][0U] >> 6U)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_ozone_backend__DOT__check_true__106__cond)))))) {
        tb_ozone_backend__DOT__failures = ((IData)(1U) 
                                           + tb_ozone_backend__DOT__failures);
        VL_WRITEF_NX("[FAIL] %@\n",0,-1,&(vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_true__106__label));
    }
    __Vtask_tb_ozone_backend__DOT__test_nzcv_and_bcond_forwarding__107__flags_tag = 0;
    __Vtask_tb_ozone_backend__DOT__test_nzcv_and_bcond_forwarding__107__branch_tag = 0;
    __Vtask_tb_ozone_backend__DOT__test_nzcv_and_bcond_forwarding__107__branch_slot = 0U;
    VL_WRITEF_NX("Running NZCV and B.cond forwarding\n",0);
    __Vtask_tb_ozone_backend__DOT__reset_dut__108__tb_ozone_backend__DOT__unnamedblk1_1__DOT____Vrepeat0 = 0;
    vlSelfRef.tb_ozone_backend__DOT__src1_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src1_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_en = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_wr_en = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__rob_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__alloc_has_dest = 0U;
    VL_ASSIGN_W(280, vlSelfRef.tb_ozone_backend__DOT__alloc_data, Vtb_ozone_backend__ConstPool__CONST_h083ec1be_0);
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[0U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[1U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[2U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[3U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[4U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[5U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[0U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[1U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[2U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[3U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[4U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__rst_n = 0U;
    __Vtask_tb_ozone_backend__DOT__reset_dut__108__tb_ozone_backend__DOT__unnamedblk1_1__DOT____Vrepeat0 = 3U;
    while (VL_LTS_III(32, 0U, __Vtask_tb_ozone_backend__DOT__reset_dut__108__tb_ozone_backend__DOT__unnamedblk1_1__DOT____Vrepeat0)) {
        Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9782__0(vlSelf, 
                                                                "@(posedge tb_ozone_backend.clk)");
        co_await vlSelfRef.__VtrigSched_h0e5d9782__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_ozone_backend.clk)", 
                                                             "tb/tb_ozone_backend.sv", 
                                                             380);
        __Vtask_tb_ozone_backend__DOT__reset_dut__108__tb_ozone_backend__DOT__unnamedblk1_1__DOT____Vrepeat0 
            = (__Vtask_tb_ozone_backend__DOT__reset_dut__108__tb_ozone_backend__DOT__unnamedblk1_1__DOT____Vrepeat0 
               - (IData)(1U));
    }
    vlSelfRef.tb_ozone_backend__DOT__rst_n = 1U;
    Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9782__0(vlSelf, 
                                                            "@(posedge tb_ozone_backend.clk)");
    co_await vlSelfRef.__VtrigSched_h0e5d9782__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_ozone_backend.clk)", 
                                                         "tb/tb_ozone_backend.sv", 
                                                         382);
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_ozone_backend.sv", 
                                         383);
    vlSelfRef.tb_ozone_backend__DOT__src1_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src1_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_en = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_wr_en = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__rob_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__alloc_has_dest = 0U;
    VL_ASSIGN_W(280, vlSelfRef.tb_ozone_backend__DOT__alloc_data, Vtb_ozone_backend__ConstPool__CONST_h083ec1be_0);
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[0U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[1U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[2U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[3U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[4U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[5U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[0U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[1U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[2U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[3U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[4U] = 0U;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__111__value = 1ULL;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__111__idx = 1U;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__111____Vlvbound_hee8445f9__0 = 0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__111____Vlvbound_hee492a18__0 = 0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__111____Vlvbound_hffe4168d__0 = 0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__111____Vlvbound_hffe4168d__0 
        = __Vtask_tb_ozone_backend__DOT__preload_gpr__111__value;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__111____Vlvbound_hee492a18__0 = 0U;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__111____Vlvbound_hee8445f9__0 = 0U;
    if (VL_LIKELY(((0x1eU >= (0x0000001fU & __Vtask_tb_ozone_backend__DOT__preload_gpr__111__idx))))) {
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__111__idx)][0U] 
            = ((0x0000007fU & vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                [(0x0000001fU & __Vtask_tb_ozone_backend__DOT__preload_gpr__111__idx)][0U]) 
               | ((IData)(__Vtask_tb_ozone_backend__DOT__preload_gpr__111____Vlvbound_hffe4168d__0) 
                  << 7U));
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__111__idx)][1U] 
            = (((IData)(__Vtask_tb_ozone_backend__DOT__preload_gpr__111____Vlvbound_hffe4168d__0) 
                >> 0x00000019U) | ((IData)((__Vtask_tb_ozone_backend__DOT__preload_gpr__111____Vlvbound_hffe4168d__0 
                                            >> 0x00000020U)) 
                                   << 7U));
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__111__idx)][2U] 
            = ((IData)((__Vtask_tb_ozone_backend__DOT__preload_gpr__111____Vlvbound_hffe4168d__0 
                        >> 0x00000020U)) >> 0x00000019U);
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__111__idx)][0U] 
            = ((0xffffffbfU & vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                [(0x0000001fU & __Vtask_tb_ozone_backend__DOT__preload_gpr__111__idx)][0U]) 
               | ((IData)(__Vtask_tb_ozone_backend__DOT__preload_gpr__111____Vlvbound_hee492a18__0) 
                  << 6U));
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__111__idx)][0U] 
            = ((0xffffffc0U & vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                [(0x0000001fU & __Vtask_tb_ozone_backend__DOT__preload_gpr__111__idx)][0U]) 
               | (IData)(__Vtask_tb_ozone_backend__DOT__preload_gpr__111____Vlvbound_hee8445f9__0));
    }
    __Vtask_tb_ozone_backend__DOT__preload_gpr__112__value = 0xffffffffffffffffULL;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__112__idx = 2U;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__112____Vlvbound_hee8445f9__0 = 0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__112____Vlvbound_hee492a18__0 = 0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__112____Vlvbound_hffe4168d__0 = 0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__112____Vlvbound_hffe4168d__0 
        = __Vtask_tb_ozone_backend__DOT__preload_gpr__112__value;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__112____Vlvbound_hee492a18__0 = 0U;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__112____Vlvbound_hee8445f9__0 = 0U;
    if (VL_LIKELY(((0x1eU >= (0x0000001fU & __Vtask_tb_ozone_backend__DOT__preload_gpr__112__idx))))) {
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__112__idx)][0U] 
            = ((0x0000007fU & vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                [(0x0000001fU & __Vtask_tb_ozone_backend__DOT__preload_gpr__112__idx)][0U]) 
               | ((IData)(__Vtask_tb_ozone_backend__DOT__preload_gpr__112____Vlvbound_hffe4168d__0) 
                  << 7U));
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__112__idx)][1U] 
            = (((IData)(__Vtask_tb_ozone_backend__DOT__preload_gpr__112____Vlvbound_hffe4168d__0) 
                >> 0x00000019U) | ((IData)((__Vtask_tb_ozone_backend__DOT__preload_gpr__112____Vlvbound_hffe4168d__0 
                                            >> 0x00000020U)) 
                                   << 7U));
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__112__idx)][2U] 
            = ((IData)((__Vtask_tb_ozone_backend__DOT__preload_gpr__112____Vlvbound_hffe4168d__0 
                        >> 0x00000020U)) >> 0x00000019U);
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__112__idx)][0U] 
            = ((0xffffffbfU & vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                [(0x0000001fU & __Vtask_tb_ozone_backend__DOT__preload_gpr__112__idx)][0U]) 
               | ((IData)(__Vtask_tb_ozone_backend__DOT__preload_gpr__112____Vlvbound_hee492a18__0) 
                  << 6U));
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__112__idx)][0U] 
            = ((0xffffffc0U & vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                [(0x0000001fU & __Vtask_tb_ozone_backend__DOT__preload_gpr__112__idx)][0U]) 
               | (IData)(__Vtask_tb_ozone_backend__DOT__preload_gpr__112____Vlvbound_hee8445f9__0));
    }
    __Vtask_tb_ozone_backend__DOT__preload_gpr__113__value = 0ULL;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__113__idx = 3U;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__113____Vlvbound_hee8445f9__0 = 0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__113____Vlvbound_hee492a18__0 = 0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__113____Vlvbound_hffe4168d__0 = 0;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__113____Vlvbound_hffe4168d__0 
        = __Vtask_tb_ozone_backend__DOT__preload_gpr__113__value;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__113____Vlvbound_hee492a18__0 = 0U;
    __Vtask_tb_ozone_backend__DOT__preload_gpr__113____Vlvbound_hee8445f9__0 = 0U;
    if (VL_LIKELY(((0x1eU >= (0x0000001fU & __Vtask_tb_ozone_backend__DOT__preload_gpr__113__idx))))) {
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__113__idx)][0U] 
            = ((0x0000007fU & vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                [(0x0000001fU & __Vtask_tb_ozone_backend__DOT__preload_gpr__113__idx)][0U]) 
               | ((IData)(__Vtask_tb_ozone_backend__DOT__preload_gpr__113____Vlvbound_hffe4168d__0) 
                  << 7U));
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__113__idx)][1U] 
            = (((IData)(__Vtask_tb_ozone_backend__DOT__preload_gpr__113____Vlvbound_hffe4168d__0) 
                >> 0x00000019U) | ((IData)((__Vtask_tb_ozone_backend__DOT__preload_gpr__113____Vlvbound_hffe4168d__0 
                                            >> 0x00000020U)) 
                                   << 7U));
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__113__idx)][2U] 
            = ((IData)((__Vtask_tb_ozone_backend__DOT__preload_gpr__113____Vlvbound_hffe4168d__0 
                        >> 0x00000020U)) >> 0x00000019U);
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__113__idx)][0U] 
            = ((0xffffffbfU & vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                [(0x0000001fU & __Vtask_tb_ozone_backend__DOT__preload_gpr__113__idx)][0U]) 
               | ((IData)(__Vtask_tb_ozone_backend__DOT__preload_gpr__113____Vlvbound_hee492a18__0) 
                  << 6U));
        vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[(0x0000001fU 
                                                                & __Vtask_tb_ozone_backend__DOT__preload_gpr__113__idx)][0U] 
            = ((0xffffffc0U & vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                [(0x0000001fU & __Vtask_tb_ozone_backend__DOT__preload_gpr__113__idx)][0U]) 
               | (IData)(__Vtask_tb_ozone_backend__DOT__preload_gpr__113____Vlvbound_hee8445f9__0));
    }
    __Vtask_tb_ozone_backend__DOT__preload_nzcv__114__flags = 0U;
    vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__nzcv_reg[0U] 
        = ((IData)((QData)((IData)(__Vtask_tb_ozone_backend__DOT__preload_nzcv__114__flags))) 
           << 7U);
    vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__nzcv_reg[1U] 
        = (((IData)((QData)((IData)(__Vtask_tb_ozone_backend__DOT__preload_nzcv__114__flags))) 
            >> 0x00000019U) | ((IData)(((QData)((IData)(__Vtask_tb_ozone_backend__DOT__preload_nzcv__114__flags)) 
                                        >> 0x00000020U)) 
                               << 7U));
    vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__nzcv_reg[2U] 
        = ((IData)(((QData)((IData)(__Vtask_tb_ozone_backend__DOT__preload_nzcv__114__flags)) 
                    >> 0x00000020U)) >> 0x00000019U);
    __Vtask_tb_ozone_backend__DOT__warmup_tag_zero__115__expected = 0;
    __Vtask_tb_ozone_backend__DOT__warmup_tag_zero__115__expected 
        = ((((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[1U][2U])) 
             << 0x00000039U) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[1U][1U])) 
                                 << 0x00000019U) | 
                                ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[1U][0U])) 
                                 >> 7U))) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[2U][2U])) 
                                              << 0x00000039U) 
                                             | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[2U][1U])) 
                                                 << 0x00000019U) 
                                                | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg[2U][0U])) 
                                                   >> 7U))));
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__writes_nzcv = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__has_dest = 1U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__dest_reg = 0x1eU;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__reg_b = 2U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__reg_a = 1U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__op = 0x13U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__tag_out = 0;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__vj = 0;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__vk = 0;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__qj = 0;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__qk = 0;
    VL_ZERO_W(159, __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__entry);
    VL_ZERO_W(280, __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__rob_entry);
    while (((0x40U == (IData)(vlSelfRef.tb_ozone_backend__DOT__rob__DOT__count)) 
            | (IData)(vlSelfRef.tb_ozone_backend__DOT__logic_full))) {
        Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9448__0(vlSelf, 
                                                                "@(negedge tb_ozone_backend.clk)");
        co_await vlSelfRef.__VtrigSched_h0e5d9448__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_ozone_backend.clk)", 
                                                             "tb/tb_ozone_backend.sv", 
                                                             576);
    }
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__117__reg_b 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__reg_b;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__117__reg_a 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__reg_a;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__117__vj = 0;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__117__qj = 0;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__117__vk = 0;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__117__qk = 0;
    vlSelfRef.tb_ozone_backend__DOT__src1_addr = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__117__reg_a;
    vlSelfRef.tb_ozone_backend__DOT__src2_addr = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__117__reg_b;
    vlSelfRef.tb_ozone_backend__DOT__src1_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_rob_idx = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_ozone_backend.sv", 
                                         452);
    vlSelfRef.tb_ozone_backend__DOT__src1_rob_idx = 
        (0x0000003fU & vlSelfRef.tb_ozone_backend__DOT__src1_status[0U]);
    vlSelfRef.tb_ozone_backend__DOT__src2_rob_idx = 
        (0x0000003fU & vlSelfRef.tb_ozone_backend__DOT__src2_status[0U]);
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_ozone_backend.sv", 
                                         456);
    if ((0x00000040U & vlSelfRef.tb_ozone_backend__DOT__src1_status[0U])) {
        if (vlSelfRef.tb_ozone_backend__DOT__src1_ready) {
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__117__vj 
                = vlSelfRef.tb_ozone_backend__DOT__src1_value;
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__117__qj = 0U;
        } else {
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__117__vj = 0ULL;
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__117__qj 
                = (0x0000003fU & vlSelfRef.tb_ozone_backend__DOT__src1_status[0U]);
        }
    } else {
        __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__117__vj 
            = (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src1_status[2U])) 
                << 0x00000039U) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src1_status[1U])) 
                                    << 0x00000019U) 
                                   | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src1_status[0U])) 
                                      >> 7U)));
        __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__117__qj = 0U;
    }
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__vj 
        = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__117__vj;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__qj 
        = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__117__qj;
    if ((0x00000040U & vlSelfRef.tb_ozone_backend__DOT__src2_status[0U])) {
        if (vlSelfRef.tb_ozone_backend__DOT__src2_ready) {
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__117__vk 
                = vlSelfRef.tb_ozone_backend__DOT__src2_value;
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__117__qk = 0U;
        } else {
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__117__vk = 0ULL;
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__117__qk 
                = (0x0000003fU & vlSelfRef.tb_ozone_backend__DOT__src2_status[0U]);
        }
    } else {
        __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__117__vk 
            = (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src2_status[2U])) 
                << 0x00000039U) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src2_status[1U])) 
                                    << 0x00000019U) 
                                   | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src2_status[0U])) 
                                      >> 7U)));
        __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__117__qk = 0U;
    }
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__vk 
        = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__117__vk;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__qk 
        = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__117__qk;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__tag_out 
        = vlSelfRef.tb_ozone_backend__DOT__rob__DOT__tail;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__entry[0U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__entry[1U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__entry[2U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__entry[3U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__entry[4U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__entry[0U] 
        = ((0x00000fffU & __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__entry[0U]) 
           | (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__vk) 
               << 0x0000001eU) | (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__qj) 
                                   << 0x00000018U) 
                                  | (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__qk) 
                                      << 0x00000012U) 
                                     | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__tag_out) 
                                        << 0x0000000cU)))));
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__entry[1U] 
        = (((0x00000fffU & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__vk) 
                            >> 2U)) | ((0x00000fffU 
                                        & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__qj) 
                                           >> 8U)) 
                                       | ((0x00000fffU 
                                           & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__qk) 
                                              >> 0x0000000eU)) 
                                          | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__tag_out) 
                                             >> 0x00000014U)))) 
           | ((0x3ffff000U & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__vk) 
                              >> 2U)) | ((IData)((__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__vk 
                                                  >> 0x00000020U)) 
                                         << 0x0000001eU)));
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__entry[2U] 
        = ((0xc0000000U & __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__entry[2U]) 
           | ((0x00000fffU & ((IData)((__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__vk 
                                       >> 0x00000020U)) 
                              >> 2U)) | (0x3ffff000U 
                                         & ((IData)(
                                                    (__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__vk 
                                                     >> 0x00000020U)) 
                                            >> 2U))));
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__entry[2U] 
        = ((0x3fffffffU & __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__entry[2U]) 
           | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__vj) 
              << 0x0000001eU));
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__entry[3U] 
        = (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__vj) 
            >> 2U) | ((IData)((__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__vj 
                               >> 0x00000020U)) << 0x0000001eU));
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__entry[4U] 
        = ((0x40000000U & __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__entry[4U]) 
           | (0x7fffffffU & ((IData)((__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__vj 
                                      >> 0x00000020U)) 
                             >> 2U)));
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__entry[0U] 
        = ((0xfffff801U & __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__entry[0U]) 
           | (0xfffffffeU & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__op) 
                             << 5U)));
    VL_ASSIGN_W(280, __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__rob_entry, Vtb_ozone_backend__ConstPool__CONST_h083ec1be_0);
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__rob_entry[8U] 
        = ((0x00801fffU & __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__rob_entry[8U]) 
           | (0x00ffe000U & (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__dest_reg) 
                              << 0x00000010U) | ((((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__has_dest)
                                                    ? 1U
                                                    : 0U) 
                                                  << 0x0000000eU) 
                                                 | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__has_dest) 
                                                    << 0x0000000dU)))));
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__rob_entry[6U] 
        = ((0xffffefffU & __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__rob_entry[6U]) 
           | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__writes_nzcv) 
              << 0x0000000cU));
    Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9448__0(vlSelf, 
                                                            "@(negedge tb_ozone_backend.clk)");
    co_await vlSelfRef.__VtrigSched_h0e5d9448__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_ozone_backend.clk)", 
                                                         "tb/tb_ozone_backend.sv", 
                                                         596);
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[0U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__rob_entry[0U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[1U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__rob_entry[1U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[2U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__rob_entry[2U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[3U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__rob_entry[3U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[4U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__rob_entry[4U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[5U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__rob_entry[5U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[6U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__rob_entry[6U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[7U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__rob_entry[7U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[8U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__rob_entry[8U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_has_dest 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__has_dest;
    vlSelfRef.tb_ozone_backend__DOT__rob_alloc_valid = 1U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[0U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__entry[0U];
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[1U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__entry[1U];
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[2U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__entry[2U];
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[3U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__entry[3U];
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[4U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__entry[4U];
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_valid = 1U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_en = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__has_dest;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_addr = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__dest_reg;
    vlSelfRef.tb_ozone_backend__DOT__disp_rob_idx = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__tag_out;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_wr_en 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__writes_nzcv;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_rob_idx 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__116__tag_out;
    Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9782__0(vlSelf, 
                                                            "@(posedge tb_ozone_backend.clk)");
    co_await vlSelfRef.__VtrigSched_h0e5d9782__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_ozone_backend.clk)", 
                                                         "tb/tb_ozone_backend.sv", 
                                                         607);
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_ozone_backend.sv", 
                                         608);
    vlSelfRef.tb_ozone_backend__DOT__src1_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src1_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_en = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_wr_en = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__rob_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__alloc_has_dest = 0U;
    VL_ASSIGN_W(280, vlSelfRef.tb_ozone_backend__DOT__alloc_data, Vtb_ozone_backend__ConstPool__CONST_h083ec1be_0);
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[0U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[1U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[2U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[3U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[4U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[5U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[0U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[1U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[2U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[3U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[4U] = 0U;
    vlSelfRef.__Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__119__label = "warmup x30"s;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__119__expected 
        = __Vtask_tb_ozone_backend__DOT__warmup_tag_zero__115__expected;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__119__reg_idx = 0x0000001eU;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__119__cycles = 0U;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__119__cycles = 0U;
    while (((((((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                                [((0x1eU >= (0x0000001fU 
                                             & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__119__reg_idx))
                                   ? (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__119__reg_idx)
                                   : 0U)][2U])) << 0x00000039U) 
               | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                                   [((0x1eU >= (0x0000001fU 
                                                & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__119__reg_idx))
                                      ? (0x0000001fU 
                                         & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__119__reg_idx)
                                      : 0U)][1U])) 
                   << 0x00000019U) | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                                                      [
                                                      ((0x1eU 
                                                        >= 
                                                        (0x0000001fU 
                                                         & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__119__reg_idx))
                                                        ? 
                                                       (0x0000001fU 
                                                        & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__119__reg_idx)
                                                        : 0U)][0U])) 
                                      >> 7U))) != __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__119__expected) 
             | (vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                [((0x1eU >= (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__119__reg_idx))
                   ? (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__119__reg_idx)
                   : 0U)][0U] >> 6U)) & VL_GTS_III(32, 0x00000028U, __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__119__cycles))) {
        Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9782__0(vlSelf, 
                                                                "@(posedge tb_ozone_backend.clk)");
        co_await vlSelfRef.__VtrigSched_h0e5d9782__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_ozone_backend.clk)", 
                                                             "tb/tb_ozone_backend.sv", 
                                                             691);
        co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                             nullptr, 
                                             "tb/tb_ozone_backend.sv", 
                                             692);
        __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__119__cycles 
            = ((IData)(1U) + __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__119__cycles);
    }
    vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_u64__120__label 
        = vlSelfRef.__Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__119__label;
    __Vtask_tb_ozone_backend__DOT__check_u64__120__expected 
        = __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__119__expected;
    __Vtask_tb_ozone_backend__DOT__check_u64__120__got 
        = (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                            [((0x1eU >= (0x0000001fU 
                                         & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__119__reg_idx))
                               ? (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__119__reg_idx)
                               : 0U)][2U])) << 0x00000039U) 
           | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                               [((0x1eU >= (0x0000001fU 
                                            & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__119__reg_idx))
                                  ? (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__119__reg_idx)
                                  : 0U)][1U])) << 0x00000019U) 
              | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                                 [((0x1eU >= (0x0000001fU 
                                              & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__119__reg_idx))
                                    ? (0x0000001fU 
                                       & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__119__reg_idx)
                                    : 0U)][0U])) >> 7U)));
    if (VL_UNLIKELY(((__Vtask_tb_ozone_backend__DOT__check_u64__120__got 
                      != __Vtask_tb_ozone_backend__DOT__check_u64__120__expected)))) {
        tb_ozone_backend__DOT__failures = ((IData)(1U) 
                                           + tb_ozone_backend__DOT__failures);
        VL_WRITEF_NX("[FAIL] %@ expected=0x%016x got=0x%016x\n",0,
                     -1,&(vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_u64__120__label),
                     64,__Vtask_tb_ozone_backend__DOT__check_u64__120__expected,
                     64,__Vtask_tb_ozone_backend__DOT__check_u64__120__got);
    }
    vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_true__121__label 
        = VL_CVT_PACK_STR_NN(VL_CONCATN_NNN(vlSelfRef.__Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__119__label, " busy clear"s));
    __Vtask_tb_ozone_backend__DOT__check_true__121__cond 
        = (1U & (~ (vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                    [((0x1eU >= (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__119__reg_idx))
                       ? (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__119__reg_idx)
                       : 0U)][0U] >> 6U)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_ozone_backend__DOT__check_true__121__cond)))))) {
        tb_ozone_backend__DOT__failures = ((IData)(1U) 
                                           + tb_ozone_backend__DOT__failures);
        VL_WRITEF_NX("[FAIL] %@\n",0,-1,&(vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_true__121__label));
    }
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__writes_nzcv = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__has_dest = 1U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__dest_reg = 0x0aU;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__reg_b = 3U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__reg_a = 1U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__op = 0x13U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__tag_out = 0;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__vj = 0;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__vk = 0;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__qj = 0;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__qk = 0;
    VL_ZERO_W(159, __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__entry);
    VL_ZERO_W(280, __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__rob_entry);
    while (((0x40U == (IData)(vlSelfRef.tb_ozone_backend__DOT__rob__DOT__count)) 
            | (IData)(vlSelfRef.tb_ozone_backend__DOT__logic_full))) {
        Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9448__0(vlSelf, 
                                                                "@(negedge tb_ozone_backend.clk)");
        co_await vlSelfRef.__VtrigSched_h0e5d9448__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_ozone_backend.clk)", 
                                                             "tb/tb_ozone_backend.sv", 
                                                             576);
    }
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__123__reg_b 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__reg_b;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__123__reg_a 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__reg_a;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__123__vj = 0;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__123__qj = 0;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__123__vk = 0;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__123__qk = 0;
    vlSelfRef.tb_ozone_backend__DOT__src1_addr = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__123__reg_a;
    vlSelfRef.tb_ozone_backend__DOT__src2_addr = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__123__reg_b;
    vlSelfRef.tb_ozone_backend__DOT__src1_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_rob_idx = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_ozone_backend.sv", 
                                         452);
    vlSelfRef.tb_ozone_backend__DOT__src1_rob_idx = 
        (0x0000003fU & vlSelfRef.tb_ozone_backend__DOT__src1_status[0U]);
    vlSelfRef.tb_ozone_backend__DOT__src2_rob_idx = 
        (0x0000003fU & vlSelfRef.tb_ozone_backend__DOT__src2_status[0U]);
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_ozone_backend.sv", 
                                         456);
    if ((0x00000040U & vlSelfRef.tb_ozone_backend__DOT__src1_status[0U])) {
        if (vlSelfRef.tb_ozone_backend__DOT__src1_ready) {
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__123__vj 
                = vlSelfRef.tb_ozone_backend__DOT__src1_value;
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__123__qj = 0U;
        } else {
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__123__vj = 0ULL;
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__123__qj 
                = (0x0000003fU & vlSelfRef.tb_ozone_backend__DOT__src1_status[0U]);
        }
    } else {
        __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__123__vj 
            = (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src1_status[2U])) 
                << 0x00000039U) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src1_status[1U])) 
                                    << 0x00000019U) 
                                   | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src1_status[0U])) 
                                      >> 7U)));
        __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__123__qj = 0U;
    }
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__vj 
        = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__123__vj;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__qj 
        = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__123__qj;
    if ((0x00000040U & vlSelfRef.tb_ozone_backend__DOT__src2_status[0U])) {
        if (vlSelfRef.tb_ozone_backend__DOT__src2_ready) {
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__123__vk 
                = vlSelfRef.tb_ozone_backend__DOT__src2_value;
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__123__qk = 0U;
        } else {
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__123__vk = 0ULL;
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__123__qk 
                = (0x0000003fU & vlSelfRef.tb_ozone_backend__DOT__src2_status[0U]);
        }
    } else {
        __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__123__vk 
            = (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src2_status[2U])) 
                << 0x00000039U) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src2_status[1U])) 
                                    << 0x00000019U) 
                                   | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src2_status[0U])) 
                                      >> 7U)));
        __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__123__qk = 0U;
    }
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__vk 
        = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__123__vk;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__qk 
        = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__123__qk;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__tag_out 
        = vlSelfRef.tb_ozone_backend__DOT__rob__DOT__tail;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__entry[0U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__entry[1U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__entry[2U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__entry[3U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__entry[4U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__entry[0U] 
        = ((0x00000fffU & __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__entry[0U]) 
           | (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__vk) 
               << 0x0000001eU) | (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__qj) 
                                   << 0x00000018U) 
                                  | (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__qk) 
                                      << 0x00000012U) 
                                     | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__tag_out) 
                                        << 0x0000000cU)))));
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__entry[1U] 
        = (((0x00000fffU & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__vk) 
                            >> 2U)) | ((0x00000fffU 
                                        & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__qj) 
                                           >> 8U)) 
                                       | ((0x00000fffU 
                                           & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__qk) 
                                              >> 0x0000000eU)) 
                                          | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__tag_out) 
                                             >> 0x00000014U)))) 
           | ((0x3ffff000U & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__vk) 
                              >> 2U)) | ((IData)((__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__vk 
                                                  >> 0x00000020U)) 
                                         << 0x0000001eU)));
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__entry[2U] 
        = ((0xc0000000U & __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__entry[2U]) 
           | ((0x00000fffU & ((IData)((__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__vk 
                                       >> 0x00000020U)) 
                              >> 2U)) | (0x3ffff000U 
                                         & ((IData)(
                                                    (__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__vk 
                                                     >> 0x00000020U)) 
                                            >> 2U))));
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__entry[2U] 
        = ((0x3fffffffU & __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__entry[2U]) 
           | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__vj) 
              << 0x0000001eU));
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__entry[3U] 
        = (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__vj) 
            >> 2U) | ((IData)((__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__vj 
                               >> 0x00000020U)) << 0x0000001eU));
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__entry[4U] 
        = ((0x40000000U & __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__entry[4U]) 
           | (0x7fffffffU & ((IData)((__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__vj 
                                      >> 0x00000020U)) 
                             >> 2U)));
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__entry[0U] 
        = ((0xfffff801U & __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__entry[0U]) 
           | (0xfffffffeU & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__op) 
                             << 5U)));
    VL_ASSIGN_W(280, __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__rob_entry, Vtb_ozone_backend__ConstPool__CONST_h083ec1be_0);
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__rob_entry[8U] 
        = ((0x00801fffU & __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__rob_entry[8U]) 
           | (0x00ffe000U & (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__dest_reg) 
                              << 0x00000010U) | ((((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__has_dest)
                                                    ? 1U
                                                    : 0U) 
                                                  << 0x0000000eU) 
                                                 | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__has_dest) 
                                                    << 0x0000000dU)))));
    __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__rob_entry[6U] 
        = ((0xffffefffU & __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__rob_entry[6U]) 
           | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__writes_nzcv) 
              << 0x0000000cU));
    Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9448__0(vlSelf, 
                                                            "@(negedge tb_ozone_backend.clk)");
    co_await vlSelfRef.__VtrigSched_h0e5d9448__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_ozone_backend.clk)", 
                                                         "tb/tb_ozone_backend.sv", 
                                                         596);
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[0U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__rob_entry[0U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[1U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__rob_entry[1U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[2U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__rob_entry[2U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[3U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__rob_entry[3U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[4U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__rob_entry[4U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[5U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__rob_entry[5U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[6U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__rob_entry[6U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[7U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__rob_entry[7U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[8U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__rob_entry[8U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_has_dest 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__has_dest;
    vlSelfRef.tb_ozone_backend__DOT__rob_alloc_valid = 1U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[0U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__entry[0U];
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[1U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__entry[1U];
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[2U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__entry[2U];
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[3U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__entry[3U];
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[4U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__entry[4U];
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_valid = 1U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_en = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__has_dest;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_addr = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__dest_reg;
    vlSelfRef.tb_ozone_backend__DOT__disp_rob_idx = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__tag_out;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_wr_en 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__writes_nzcv;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_rob_idx 
        = __Vtask_tb_ozone_backend__DOT__dispatch_logic_rr__122__tag_out;
    Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9782__0(vlSelf, 
                                                            "@(posedge tb_ozone_backend.clk)");
    co_await vlSelfRef.__VtrigSched_h0e5d9782__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_ozone_backend.clk)", 
                                                         "tb/tb_ozone_backend.sv", 
                                                         607);
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_ozone_backend.sv", 
                                         608);
    vlSelfRef.tb_ozone_backend__DOT__src1_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src1_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_en = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_wr_en = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__rob_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__alloc_has_dest = 0U;
    VL_ASSIGN_W(280, vlSelfRef.tb_ozone_backend__DOT__alloc_data, Vtb_ozone_backend__ConstPool__CONST_h083ec1be_0);
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[0U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[1U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[2U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[3U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[4U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[5U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[0U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[1U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[2U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[3U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[4U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__writes_nzcv = 1U;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__has_dest = 1U;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__dest_reg = 4U;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__reg_b = 2U;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__reg_a = 0x0aU;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__op = 1U;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__tag_out = 0;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__vj = 0;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__vk = 0;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__qj = 0;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__qk = 0;
    VL_ZERO_W(165, __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__entry);
    VL_ZERO_W(280, __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__rob_entry);
    while (((0x40U == (IData)(vlSelfRef.tb_ozone_backend__DOT__rob__DOT__count)) 
            | (IData)(vlSelfRef.tb_ozone_backend__DOT__adder_full))) {
        Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9448__0(vlSelf, 
                                                                "@(negedge tb_ozone_backend.clk)");
        co_await vlSelfRef.__VtrigSched_h0e5d9448__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_ozone_backend.clk)", 
                                                             "tb/tb_ozone_backend.sv", 
                                                             522);
    }
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__126__reg_b 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__reg_b;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__126__reg_a 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__reg_a;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__126__vj = 0;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__126__qj = 0;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__126__vk = 0;
    __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__126__qk = 0;
    vlSelfRef.tb_ozone_backend__DOT__src1_addr = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__126__reg_a;
    vlSelfRef.tb_ozone_backend__DOT__src2_addr = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__126__reg_b;
    vlSelfRef.tb_ozone_backend__DOT__src1_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_rob_idx = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_ozone_backend.sv", 
                                         452);
    vlSelfRef.tb_ozone_backend__DOT__src1_rob_idx = 
        (0x0000003fU & vlSelfRef.tb_ozone_backend__DOT__src1_status[0U]);
    vlSelfRef.tb_ozone_backend__DOT__src2_rob_idx = 
        (0x0000003fU & vlSelfRef.tb_ozone_backend__DOT__src2_status[0U]);
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_ozone_backend.sv", 
                                         456);
    if ((0x00000040U & vlSelfRef.tb_ozone_backend__DOT__src2_status[0U])) {
        if (vlSelfRef.tb_ozone_backend__DOT__src2_ready) {
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__126__vk 
                = vlSelfRef.tb_ozone_backend__DOT__src2_value;
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__126__qk = 0U;
        } else {
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__126__vk = 0ULL;
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__126__qk 
                = (0x0000003fU & vlSelfRef.tb_ozone_backend__DOT__src2_status[0U]);
        }
    } else {
        __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__126__vk 
            = (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src2_status[2U])) 
                << 0x00000039U) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src2_status[1U])) 
                                    << 0x00000019U) 
                                   | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src2_status[0U])) 
                                      >> 7U)));
        __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__126__qk = 0U;
    }
    if ((0x00000040U & vlSelfRef.tb_ozone_backend__DOT__src1_status[0U])) {
        if (vlSelfRef.tb_ozone_backend__DOT__src1_ready) {
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__126__vj 
                = vlSelfRef.tb_ozone_backend__DOT__src1_value;
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__126__qj = 0U;
        } else {
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__126__vj = 0ULL;
            __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__126__qj 
                = (0x0000003fU & vlSelfRef.tb_ozone_backend__DOT__src1_status[0U]);
        }
    } else {
        __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__126__vj 
            = (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src1_status[2U])) 
                << 0x00000039U) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src1_status[1U])) 
                                    << 0x00000019U) 
                                   | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__src1_status[0U])) 
                                      >> 7U)));
        __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__126__qj = 0U;
    }
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__vj 
        = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__126__vj;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__qj 
        = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__126__qj;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__vk 
        = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__126__vk;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__qk 
        = __Vtask_tb_ozone_backend__DOT__resolve_gpr_sources__126__qk;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__tag_out 
        = vlSelfRef.tb_ozone_backend__DOT__rob__DOT__tail;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__entry[0U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__entry[1U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__entry[2U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__entry[3U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__entry[4U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__entry[5U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__entry[0U] 
        = ((0x0003ffffU & __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__entry[0U]) 
           | (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__qj) 
               << 0x0000001eU) | (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__qk) 
                                   << 0x00000018U) 
                                  | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__tag_out) 
                                     << 0x00000012U))));
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__entry[1U] 
        = (((0x0003fff0U & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__vk) 
                            << 4U)) | ((0x0003ffffU 
                                        & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__qj) 
                                           >> 2U)) 
                                       | ((0x0003ffffU 
                                           & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__qk) 
                                              >> 8U)) 
                                          | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__tag_out) 
                                             >> 0x0000000eU)))) 
           | (0xfffc0000U & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__vk) 
                             << 4U)));
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__entry[2U] 
        = ((((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__vk) 
             >> 0x0000001cU) | (0x0003fff0U & ((IData)(
                                                       (__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__vk 
                                                        >> 0x00000020U)) 
                                               << 4U))) 
           | (0xfffc0000U & ((IData)((__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__vk 
                                      >> 0x00000020U)) 
                             << 4U)));
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__entry[3U] 
        = ((0xfffffff0U & __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__entry[3U]) 
           | ((IData)((__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__vk 
                       >> 0x00000020U)) >> 0x0000001cU));
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__entry[3U] 
        = ((0x0000000fU & __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__entry[3U]) 
           | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__vj) 
              << 4U));
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__entry[4U] 
        = (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__vj) 
            >> 0x0000001cU) | ((IData)((__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__vj 
                                        >> 0x00000020U)) 
                               << 4U));
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__entry[5U] 
        = ((0x00000010U & __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__entry[5U]) 
           | (0x0000001fU & ((IData)((__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__vj 
                                      >> 0x00000020U)) 
                             >> 0x0000001cU)));
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__entry[0U] 
        = ((0xfffe0007U & __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__entry[0U]) 
           | (0xfffffff8U & (0x00000070U | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__op) 
                                            << 0x0000000bU))));
    VL_ASSIGN_W(280, __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__rob_entry, Vtb_ozone_backend__ConstPool__CONST_h083ec1be_0);
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__rob_entry[8U] 
        = ((0x00801fffU & __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__rob_entry[8U]) 
           | (0x00ffe000U & (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__dest_reg) 
                              << 0x00000010U) | ((((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__has_dest)
                                                    ? 1U
                                                    : 0U) 
                                                  << 0x0000000eU) 
                                                 | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__has_dest) 
                                                    << 0x0000000dU)))));
    __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__rob_entry[6U] 
        = ((0xffffefffU & __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__rob_entry[6U]) 
           | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__writes_nzcv) 
              << 0x0000000cU));
    Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9448__0(vlSelf, 
                                                            "@(negedge tb_ozone_backend.clk)");
    co_await vlSelfRef.__VtrigSched_h0e5d9448__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_ozone_backend.clk)", 
                                                         "tb/tb_ozone_backend.sv", 
                                                         543);
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[0U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__rob_entry[0U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[1U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__rob_entry[1U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[2U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__rob_entry[2U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[3U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__rob_entry[3U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[4U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__rob_entry[4U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[5U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__rob_entry[5U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[6U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__rob_entry[6U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[7U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__rob_entry[7U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[8U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__rob_entry[8U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_has_dest 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__has_dest;
    vlSelfRef.tb_ozone_backend__DOT__rob_alloc_valid = 1U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[0U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__entry[0U];
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[1U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__entry[1U];
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[2U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__entry[2U];
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[3U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__entry[3U];
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[4U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__entry[4U];
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[5U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__entry[5U];
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_valid = 1U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_en = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__has_dest;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_addr = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__dest_reg;
    vlSelfRef.tb_ozone_backend__DOT__disp_rob_idx = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__tag_out;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_wr_en 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__writes_nzcv;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_rob_idx 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__tag_out;
    Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9782__0(vlSelf, 
                                                            "@(posedge tb_ozone_backend.clk)");
    co_await vlSelfRef.__VtrigSched_h0e5d9782__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_ozone_backend.clk)", 
                                                         "tb/tb_ozone_backend.sv", 
                                                         554);
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_ozone_backend.sv", 
                                         555);
    vlSelfRef.tb_ozone_backend__DOT__src1_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src1_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_en = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_wr_en = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__rob_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__alloc_has_dest = 0U;
    VL_ASSIGN_W(280, vlSelfRef.tb_ozone_backend__DOT__alloc_data, Vtb_ozone_backend__ConstPool__CONST_h083ec1be_0);
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[0U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[1U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[2U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[3U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[4U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[5U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[0U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[1U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[2U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[3U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[4U] = 0U;
    __Vtask_tb_ozone_backend__DOT__test_nzcv_and_bcond_forwarding__107__flags_tag 
        = __Vtask_tb_ozone_backend__DOT__dispatch_adder_rr__125__tag_out;
    __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__branch_off = 0x0000000000000010ULL;
    __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__branch_pc = 0x0000000000001000ULL;
    __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__cond = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__tag_out = 0;
    __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__flags = 0;
    __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__q_flags = 0;
    VL_ZERO_W(165, __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__entry);
    VL_ZERO_W(280, __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__rob_entry);
    while (((0x40U == (IData)(vlSelfRef.tb_ozone_backend__DOT__rob__DOT__count)) 
            | (IData)(vlSelfRef.tb_ozone_backend__DOT__adder_full))) {
        Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9448__0(vlSelf, 
                                                                "@(negedge tb_ozone_backend.clk)");
        co_await vlSelfRef.__VtrigSched_h0e5d9448__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(negedge tb_ozone_backend.clk)", 
                                                             "tb/tb_ozone_backend.sv", 
                                                             624);
    }
    __Vtask_tb_ozone_backend__DOT__resolve_nzcv_source__129__flags = 0;
    __Vtask_tb_ozone_backend__DOT__resolve_nzcv_source__129__q = 0;
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_ozone_backend.sv", 
                                         487);
    if ((0x00000040U & vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__nzcv_reg[0U])) {
        if ((((vlSelfRef.tb_ozone_backend__DOT__cdb_broadcast[4U] 
               >> 0x00000016U) & ((0x0000003fU & (vlSelfRef.tb_ozone_backend__DOT__cdb_broadcast[4U] 
                                                  >> 0x00000010U)) 
                                  == (0x0000003fU & vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__nzcv_reg[0U]))) 
             & (vlSelfRef.tb_ozone_backend__DOT__cdb_broadcast[2U] 
                >> 0x0000000fU))) {
            __Vtask_tb_ozone_backend__DOT__resolve_nzcv_source__129__flags 
                = (0x0000000fU & (vlSelfRef.tb_ozone_backend__DOT__cdb_broadcast[2U] 
                                  >> 0x0000000bU));
            __Vtask_tb_ozone_backend__DOT__resolve_nzcv_source__129__q = 0U;
        } else if ((0x00000080U & vlSelfRef.tb_ozone_backend__DOT__rob__DOT__rob_entries
                    [(0x0000003fU & vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__nzcv_reg[0U])][6U])) {
            __Vtask_tb_ozone_backend__DOT__resolve_nzcv_source__129__flags 
                = (0x0000000fU & (vlSelfRef.tb_ozone_backend__DOT__rob__DOT__rob_entries
                                  [(0x0000003fU & vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__nzcv_reg[0U])][6U] 
                                  >> 8U));
            __Vtask_tb_ozone_backend__DOT__resolve_nzcv_source__129__q = 0U;
        } else {
            __Vtask_tb_ozone_backend__DOT__resolve_nzcv_source__129__flags = 0U;
            __Vtask_tb_ozone_backend__DOT__resolve_nzcv_source__129__q 
                = (0x0000003fU & vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__nzcv_reg[0U]);
        }
    } else {
        __Vtask_tb_ozone_backend__DOT__resolve_nzcv_source__129__flags 
            = (0x0000000fU & (vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__nzcv_reg[0U] 
                              >> 7U));
        __Vtask_tb_ozone_backend__DOT__resolve_nzcv_source__129__q = 0U;
    }
    __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__flags 
        = __Vtask_tb_ozone_backend__DOT__resolve_nzcv_source__129__flags;
    __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__q_flags 
        = __Vtask_tb_ozone_backend__DOT__resolve_nzcv_source__129__q;
    __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__tag_out 
        = vlSelfRef.tb_ozone_backend__DOT__rob__DOT__tail;
    __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__entry[0U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__entry[1U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__entry[2U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__entry[3U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__entry[4U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__entry[5U] = 0U;
    __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__entry[0U] 
        = ((0x0003ffffU & __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__entry[0U]) 
           | (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__q_flags) 
               << 0x0000001eU) | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__tag_out) 
                                  << 0x00000012U)));
    __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__entry[1U] 
        = (((0x0003fff0U & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__branch_off) 
                            << 4U)) | ((0x0003ffffU 
                                        & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__q_flags) 
                                           >> 2U)) 
                                       | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__tag_out) 
                                          >> 0x0000000eU))) 
           | (0xfffc0000U & ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__branch_off) 
                             << 4U)));
    __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__entry[2U] 
        = ((((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__branch_off) 
             >> 0x0000001cU) | (0x0003fff0U & ((IData)(
                                                       (__Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__branch_off 
                                                        >> 0x00000020U)) 
                                               << 4U))) 
           | (0xfffc0000U & ((IData)((__Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__branch_off 
                                      >> 0x00000020U)) 
                             << 4U)));
    __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__entry[3U] 
        = ((0xfffffff0U & __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__entry[3U]) 
           | ((IData)((__Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__branch_off 
                       >> 0x00000020U)) >> 0x0000001cU));
    __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__entry[3U] 
        = ((0x0000000fU & __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__entry[3U]) 
           | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__branch_pc) 
              << 4U));
    __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__entry[4U] 
        = (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__branch_pc) 
            >> 0x0000001cU) | ((IData)((__Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__branch_pc 
                                        >> 0x00000020U)) 
                               << 4U));
    __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__entry[5U] 
        = ((0x00000010U & __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__entry[5U]) 
           | (0x0000001fU & ((IData)((__Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__branch_pc 
                                      >> 0x00000020U)) 
                             >> 0x0000001cU)));
    __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__entry[0U] 
        = ((0xfffe0007U & __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__entry[0U]) 
           | (0xfffffff8U & (0x00009000U | (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__flags) 
                                             << 7U) 
                                            | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__cond) 
                                               << 3U)))));
    VL_ASSIGN_W(280, __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__rob_entry, Vtb_ozone_backend__ConstPool__CONST_h083ec1be_0);
    __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__rob_entry[8U] 
        = (0x00200000U | (0x009fffffU & __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__rob_entry[8U]));
    __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__rob_entry[8U] 
        = (0x00ff1fffU & __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__rob_entry[8U]);
    __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__rob_entry[4U] 
        = ((3U & __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__rob_entry[4U]) 
           | ((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__branch_pc) 
              << 2U));
    __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__rob_entry[5U] 
        = (((IData)(__Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__branch_pc) 
            >> 0x0000001eU) | ((IData)((__Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__branch_pc 
                                        >> 0x00000020U)) 
                               << 2U));
    __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__rob_entry[6U] 
        = ((0xfffffffcU & __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__rob_entry[6U]) 
           | ((IData)((__Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__branch_pc 
                       >> 0x00000020U)) >> 0x0000001eU));
    Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9448__0(vlSelf, 
                                                            "@(negedge tb_ozone_backend.clk)");
    co_await vlSelfRef.__VtrigSched_h0e5d9448__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(negedge tb_ozone_backend.clk)", 
                                                         "tb/tb_ozone_backend.sv", 
                                                         644);
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[0U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__rob_entry[0U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[1U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__rob_entry[1U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[2U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__rob_entry[2U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[3U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__rob_entry[3U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[4U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__rob_entry[4U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[5U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__rob_entry[5U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[6U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__rob_entry[6U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[7U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__rob_entry[7U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_data[8U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__rob_entry[8U];
    vlSelfRef.tb_ozone_backend__DOT__alloc_has_dest = 0U;
    vlSelfRef.tb_ozone_backend__DOT__rob_alloc_valid = 1U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[0U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__entry[0U];
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[1U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__entry[1U];
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[2U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__entry[2U];
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[3U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__entry[3U];
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[4U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__entry[4U];
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[5U] 
        = __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__entry[5U];
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_valid = 1U;
    Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9782__0(vlSelf, 
                                                            "@(posedge tb_ozone_backend.clk)");
    co_await vlSelfRef.__VtrigSched_h0e5d9782__0.trigger(0U, 
                                                         nullptr, 
                                                         "@(posedge tb_ozone_backend.clk)", 
                                                         "tb/tb_ozone_backend.sv", 
                                                         650);
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_ozone_backend.sv", 
                                         651);
    vlSelfRef.tb_ozone_backend__DOT__src1_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src1_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__src2_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_en = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_wr_addr = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_wr_en = 0U;
    vlSelfRef.tb_ozone_backend__DOT__disp_nzcv_rob_idx = 0U;
    vlSelfRef.tb_ozone_backend__DOT__rob_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__alloc_has_dest = 0U;
    VL_ASSIGN_W(280, vlSelfRef.tb_ozone_backend__DOT__alloc_data, Vtb_ozone_backend__ConstPool__CONST_h083ec1be_0);
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[0U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[1U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[2U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[3U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[4U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_alloc_entry[5U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[0U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[1U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[2U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[3U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_alloc_entry[4U] = 0U;
    __Vtask_tb_ozone_backend__DOT__test_nzcv_and_bcond_forwarding__107__branch_tag 
        = __Vtask_tb_ozone_backend__DOT__dispatch_bcond__128__tag_out;
    while ((1U & (~ ((vlSelfRef.tb_ozone_backend__DOT__adder__DOT__result[4U] 
                      >> 0x00000016U) & ((0x0000003fU 
                                          & (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__result[4U] 
                                             >> 0x00000010U)) 
                                         == (IData)(__Vtask_tb_ozone_backend__DOT__test_nzcv_and_bcond_forwarding__107__flags_tag)))))) {
        Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9782__0(vlSelf, 
                                                                "@(posedge tb_ozone_backend.clk)");
        co_await vlSelfRef.__VtrigSched_h0e5d9782__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_ozone_backend.clk)", 
                                                             "tb/tb_ozone_backend.sv", 
                                                             859);
        co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                             nullptr, 
                                             "tb/tb_ozone_backend.sv", 
                                             860);
    }
    __Vfunc_tb_ozone_backend__DOT__find_adder_slot__131__tag 
        = __Vtask_tb_ozone_backend__DOT__test_nzcv_and_bcond_forwarding__107__branch_tag;
    __Vfunc_tb_ozone_backend__DOT__find_adder_slot__131__Vfuncout = 0U;
    __Vfunc_tb_ozone_backend__DOT__find_adder_slot__131__Vfuncout = 0xffffffffU;
    if (((vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[0U][0U] 
          >> 0x00000011U) & ((0x0000003fU & (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[0U][0U] 
                                             >> 0x00000012U)) 
                             == (IData)(__Vfunc_tb_ozone_backend__DOT__find_adder_slot__131__tag)))) {
        __Vfunc_tb_ozone_backend__DOT__find_adder_slot__131__Vfuncout = 0U;
    }
    if (((vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[1U][0U] 
          >> 0x00000011U) & ((0x0000003fU & (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[1U][0U] 
                                             >> 0x00000012U)) 
                             == (IData)(__Vfunc_tb_ozone_backend__DOT__find_adder_slot__131__tag)))) {
        __Vfunc_tb_ozone_backend__DOT__find_adder_slot__131__Vfuncout = 1U;
    }
    if (((vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[2U][0U] 
          >> 0x00000011U) & ((0x0000003fU & (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[2U][0U] 
                                             >> 0x00000012U)) 
                             == (IData)(__Vfunc_tb_ozone_backend__DOT__find_adder_slot__131__tag)))) {
        __Vfunc_tb_ozone_backend__DOT__find_adder_slot__131__Vfuncout = 2U;
    }
    if (((vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[3U][0U] 
          >> 0x00000011U) & ((0x0000003fU & (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[3U][0U] 
                                             >> 0x00000012U)) 
                             == (IData)(__Vfunc_tb_ozone_backend__DOT__find_adder_slot__131__tag)))) {
        __Vfunc_tb_ozone_backend__DOT__find_adder_slot__131__Vfuncout = 3U;
    }
    __Vtask_tb_ozone_backend__DOT__test_nzcv_and_bcond_forwarding__107__branch_slot 
        = __Vfunc_tb_ozone_backend__DOT__find_adder_slot__131__Vfuncout;
    vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_true__132__label = "bcond entry still in RS"s;
    __Vtask_tb_ozone_backend__DOT__check_true__132__cond 
        = VL_LTES_III(32, 0U, __Vtask_tb_ozone_backend__DOT__test_nzcv_and_bcond_forwarding__107__branch_slot);
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_ozone_backend__DOT__check_true__132__cond)))))) {
        tb_ozone_backend__DOT__failures = ((IData)(1U) 
                                           + tb_ozone_backend__DOT__failures);
        VL_WRITEF_NX("[FAIL] %@\n",0,-1,&(vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_true__132__label));
    }
    if (VL_LTES_III(32, 0U, __Vtask_tb_ozone_backend__DOT__test_nzcv_and_bcond_forwarding__107__branch_slot)) {
        vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_true__133__label = "bcond nzcv dependency cleared locally"s;
        __Vtask_tb_ozone_backend__DOT__check_true__133__cond 
            = (0U == (0x0000003fU & ((vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries
                                      [(3U & __Vtask_tb_ozone_backend__DOT__test_nzcv_and_bcond_forwarding__107__branch_slot)][1U] 
                                      << 2U) | (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries
                                                [(3U 
                                                  & __Vtask_tb_ozone_backend__DOT__test_nzcv_and_bcond_forwarding__107__branch_slot)][0U] 
                                                >> 0x0000001eU))));
        if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_ozone_backend__DOT__check_true__133__cond)))))) {
            tb_ozone_backend__DOT__failures = ((IData)(1U) 
                                               + tb_ozone_backend__DOT__failures);
            VL_WRITEF_NX("[FAIL] %@\n",0,-1,&(vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_true__133__label));
        }
        vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_u4__134__label = "bcond got forwarded nzcv"s;
        __Vtask_tb_ozone_backend__DOT__check_u4__134__expected = 6U;
        __Vtask_tb_ozone_backend__DOT__check_u4__134__got 
            = (0x0000000fU & (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries
                              [(3U & __Vtask_tb_ozone_backend__DOT__test_nzcv_and_bcond_forwarding__107__branch_slot)][0U] 
                              >> 7U));
        if (VL_UNLIKELY((((IData)(__Vtask_tb_ozone_backend__DOT__check_u4__134__got) 
                          != (IData)(__Vtask_tb_ozone_backend__DOT__check_u4__134__expected))))) {
            tb_ozone_backend__DOT__failures = ((IData)(1U) 
                                               + tb_ozone_backend__DOT__failures);
            VL_WRITEF_NX("[FAIL] %@ expected=0x%0x got=0x%0x\n",0,
                         -1,&(vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_u4__134__label),
                         4,(IData)(__Vtask_tb_ozone_backend__DOT__check_u4__134__expected),
                         4,__Vtask_tb_ozone_backend__DOT__check_u4__134__got);
        }
        vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_u64__135__label = "bcond kept branch pc"s;
        __Vtask_tb_ozone_backend__DOT__check_u64__135__expected = 0x0000000000001000ULL;
        __Vtask_tb_ozone_backend__DOT__check_u64__135__got 
            = (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries
                                [(3U & __Vtask_tb_ozone_backend__DOT__test_nzcv_and_bcond_forwarding__107__branch_slot)][5U])) 
                << 0x0000003cU) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries
                                                    [
                                                    (3U 
                                                     & __Vtask_tb_ozone_backend__DOT__test_nzcv_and_bcond_forwarding__107__branch_slot)][4U])) 
                                    << 0x0000001cU) 
                                   | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries
                                                      [
                                                      (3U 
                                                       & __Vtask_tb_ozone_backend__DOT__test_nzcv_and_bcond_forwarding__107__branch_slot)][3U])) 
                                      >> 4U)));
        if (VL_UNLIKELY(((__Vtask_tb_ozone_backend__DOT__check_u64__135__got 
                          != __Vtask_tb_ozone_backend__DOT__check_u64__135__expected)))) {
            tb_ozone_backend__DOT__failures = ((IData)(1U) 
                                               + tb_ozone_backend__DOT__failures);
            VL_WRITEF_NX("[FAIL] %@ expected=0x%016x got=0x%016x\n",0,
                         -1,&(vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_u64__135__label),
                         64,__Vtask_tb_ozone_backend__DOT__check_u64__135__expected,
                         64,__Vtask_tb_ozone_backend__DOT__check_u64__135__got);
        }
    }
    vlSelfRef.__Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__136__label = "adds commit x4"s;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__136__expected = 0ULL;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__136__reg_idx = 4U;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__136__cycles = 0U;
    __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__136__cycles = 0U;
    while (((((((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                                [((0x1eU >= (0x0000001fU 
                                             & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__136__reg_idx))
                                   ? (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__136__reg_idx)
                                   : 0U)][2U])) << 0x00000039U) 
               | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                                   [((0x1eU >= (0x0000001fU 
                                                & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__136__reg_idx))
                                      ? (0x0000001fU 
                                         & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__136__reg_idx)
                                      : 0U)][1U])) 
                   << 0x00000019U) | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                                                      [
                                                      ((0x1eU 
                                                        >= 
                                                        (0x0000001fU 
                                                         & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__136__reg_idx))
                                                        ? 
                                                       (0x0000001fU 
                                                        & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__136__reg_idx)
                                                        : 0U)][0U])) 
                                      >> 7U))) != __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__136__expected) 
             | (vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                [((0x1eU >= (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__136__reg_idx))
                   ? (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__136__reg_idx)
                   : 0U)][0U] >> 6U)) & VL_GTS_III(32, 0x00000028U, __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__136__cycles))) {
        Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9782__0(vlSelf, 
                                                                "@(posedge tb_ozone_backend.clk)");
        co_await vlSelfRef.__VtrigSched_h0e5d9782__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_ozone_backend.clk)", 
                                                             "tb/tb_ozone_backend.sv", 
                                                             691);
        co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                             nullptr, 
                                             "tb/tb_ozone_backend.sv", 
                                             692);
        __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__136__cycles 
            = ((IData)(1U) + __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__136__cycles);
    }
    vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_u64__137__label 
        = vlSelfRef.__Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__136__label;
    __Vtask_tb_ozone_backend__DOT__check_u64__137__expected 
        = __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__136__expected;
    __Vtask_tb_ozone_backend__DOT__check_u64__137__got 
        = (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                            [((0x1eU >= (0x0000001fU 
                                         & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__136__reg_idx))
                               ? (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__136__reg_idx)
                               : 0U)][2U])) << 0x00000039U) 
           | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                               [((0x1eU >= (0x0000001fU 
                                            & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__136__reg_idx))
                                  ? (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__136__reg_idx)
                                  : 0U)][1U])) << 0x00000019U) 
              | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                                 [((0x1eU >= (0x0000001fU 
                                              & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__136__reg_idx))
                                    ? (0x0000001fU 
                                       & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__136__reg_idx)
                                    : 0U)][0U])) >> 7U)));
    if (VL_UNLIKELY(((__Vtask_tb_ozone_backend__DOT__check_u64__137__got 
                      != __Vtask_tb_ozone_backend__DOT__check_u64__137__expected)))) {
        tb_ozone_backend__DOT__failures = ((IData)(1U) 
                                           + tb_ozone_backend__DOT__failures);
        VL_WRITEF_NX("[FAIL] %@ expected=0x%016x got=0x%016x\n",0,
                     -1,&(vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_u64__137__label),
                     64,__Vtask_tb_ozone_backend__DOT__check_u64__137__expected,
                     64,__Vtask_tb_ozone_backend__DOT__check_u64__137__got);
    }
    vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_true__138__label 
        = VL_CVT_PACK_STR_NN(VL_CONCATN_NNN(vlSelfRef.__Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__136__label, " busy clear"s));
    __Vtask_tb_ozone_backend__DOT__check_true__138__cond 
        = (1U & (~ (vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
                    [((0x1eU >= (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__136__reg_idx))
                       ? (0x0000001fU & __Vtask_tb_ozone_backend__DOT__wait_for_gpr_value__136__reg_idx)
                       : 0U)][0U] >> 6U)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_ozone_backend__DOT__check_true__138__cond)))))) {
        tb_ozone_backend__DOT__failures = ((IData)(1U) 
                                           + tb_ozone_backend__DOT__failures);
        VL_WRITEF_NX("[FAIL] %@\n",0,-1,&(vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_true__138__label));
    }
    vlSelfRef.__Vtask_tb_ozone_backend__DOT__wait_for_nzcv_value__139__label = "adds commit nzcv"s;
    __Vtask_tb_ozone_backend__DOT__wait_for_nzcv_value__139__expected = 6U;
    __Vtask_tb_ozone_backend__DOT__wait_for_nzcv_value__139__cycles = 0U;
    __Vtask_tb_ozone_backend__DOT__wait_for_nzcv_value__139__cycles = 0U;
    while ((((0x0000000fU & (vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__nzcv_reg[0U] 
                             >> 7U)) != (IData)(__Vtask_tb_ozone_backend__DOT__wait_for_nzcv_value__139__expected)) 
            & VL_GTS_III(32, 0x00000028U, __Vtask_tb_ozone_backend__DOT__wait_for_nzcv_value__139__cycles))) {
        Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9782__0(vlSelf, 
                                                                "@(posedge tb_ozone_backend.clk)");
        co_await vlSelfRef.__VtrigSched_h0e5d9782__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_ozone_backend.clk)", 
                                                             "tb/tb_ozone_backend.sv", 
                                                             709);
        co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                             nullptr, 
                                             "tb/tb_ozone_backend.sv", 
                                             710);
        __Vtask_tb_ozone_backend__DOT__wait_for_nzcv_value__139__cycles 
            = ((IData)(1U) + __Vtask_tb_ozone_backend__DOT__wait_for_nzcv_value__139__cycles);
    }
    vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_u4__140__label 
        = vlSelfRef.__Vtask_tb_ozone_backend__DOT__wait_for_nzcv_value__139__label;
    __Vtask_tb_ozone_backend__DOT__check_u4__140__expected 
        = __Vtask_tb_ozone_backend__DOT__wait_for_nzcv_value__139__expected;
    __Vtask_tb_ozone_backend__DOT__check_u4__140__got 
        = (0x0000000fU & (vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__nzcv_reg[0U] 
                          >> 7U));
    if (VL_UNLIKELY((((IData)(__Vtask_tb_ozone_backend__DOT__check_u4__140__got) 
                      != (IData)(__Vtask_tb_ozone_backend__DOT__check_u4__140__expected))))) {
        tb_ozone_backend__DOT__failures = ((IData)(1U) 
                                           + tb_ozone_backend__DOT__failures);
        VL_WRITEF_NX("[FAIL] %@ expected=0x%0x got=0x%0x\n",0,
                     -1,&(vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_u4__140__label),
                     4,(IData)(__Vtask_tb_ozone_backend__DOT__check_u4__140__expected),
                     4,__Vtask_tb_ozone_backend__DOT__check_u4__140__got);
    }
    vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_true__141__label 
        = VL_CVT_PACK_STR_NN(VL_CONCATN_NNN(vlSelfRef.__Vtask_tb_ozone_backend__DOT__wait_for_nzcv_value__139__label, " busy clear"s));
    __Vtask_tb_ozone_backend__DOT__check_true__141__cond 
        = (1U & (~ (vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__nzcv_reg[0U] 
                    >> 6U)));
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_ozone_backend__DOT__check_true__141__cond)))))) {
        tb_ozone_backend__DOT__failures = ((IData)(1U) 
                                           + tb_ozone_backend__DOT__failures);
        VL_WRITEF_NX("[FAIL] %@\n",0,-1,&(vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_true__141__label));
    }
    while ((1U & (~ ((vlSelfRef.tb_ozone_backend__DOT__adder__DOT__result[4U] 
                      >> 0x00000016U) & ((0x0000003fU 
                                          & (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__result[4U] 
                                             >> 0x00000010U)) 
                                         == (IData)(__Vtask_tb_ozone_backend__DOT__test_nzcv_and_bcond_forwarding__107__branch_tag)))))) {
        Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9782__0(vlSelf, 
                                                                "@(posedge tb_ozone_backend.clk)");
        co_await vlSelfRef.__VtrigSched_h0e5d9782__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_ozone_backend.clk)", 
                                                             "tb/tb_ozone_backend.sv", 
                                                             875);
        co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                             nullptr, 
                                             "tb/tb_ozone_backend.sv", 
                                             876);
    }
    vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_u64__142__label = "bcond adder target"s;
    __Vtask_tb_ozone_backend__DOT__check_u64__142__expected = 0x0000000000001010ULL;
    __Vtask_tb_ozone_backend__DOT__check_u64__142__got 
        = (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__result[2U])) 
            << 0x00000037U) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__result[1U])) 
                                << 0x00000017U) | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__result[0U])) 
                                                   >> 9U)));
    if (VL_UNLIKELY(((__Vtask_tb_ozone_backend__DOT__check_u64__142__got 
                      != __Vtask_tb_ozone_backend__DOT__check_u64__142__expected)))) {
        tb_ozone_backend__DOT__failures = ((IData)(1U) 
                                           + tb_ozone_backend__DOT__failures);
        VL_WRITEF_NX("[FAIL] %@ expected=0x%016x got=0x%016x\n",0,
                     -1,&(vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_u64__142__label),
                     64,__Vtask_tb_ozone_backend__DOT__check_u64__142__expected,
                     64,__Vtask_tb_ozone_backend__DOT__check_u64__142__got);
    }
    while ((1U & (~ (vlSelfRef.tb_ozone_backend__DOT__rob__DOT__rob_entries
                     [__Vtask_tb_ozone_backend__DOT__test_nzcv_and_bcond_forwarding__107__branch_tag][6U] 
                     >> 7U)))) {
        Vtb_ozone_backend___024root____VbeforeTrig_h0e5d9782__0(vlSelf, 
                                                                "@(posedge tb_ozone_backend.clk)");
        co_await vlSelfRef.__VtrigSched_h0e5d9782__0.trigger(0U, 
                                                             nullptr, 
                                                             "@(posedge tb_ozone_backend.clk)", 
                                                             "tb/tb_ozone_backend.sv", 
                                                             881);
        co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                             nullptr, 
                                             "tb/tb_ozone_backend.sv", 
                                             882);
    }
    vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_true__143__label = "bcond taken"s;
    __Vtask_tb_ozone_backend__DOT__check_true__143__cond 
        = (1U & vlSelfRef.tb_ozone_backend__DOT__rob__DOT__rob_entries
           [__Vtask_tb_ozone_backend__DOT__test_nzcv_and_bcond_forwarding__107__branch_tag][4U]);
    if (VL_UNLIKELY(((1U & (~ (IData)(__Vtask_tb_ozone_backend__DOT__check_true__143__cond)))))) {
        tb_ozone_backend__DOT__failures = ((IData)(1U) 
                                           + tb_ozone_backend__DOT__failures);
        VL_WRITEF_NX("[FAIL] %@\n",0,-1,&(vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_true__143__label));
    }
    vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_u64__144__label = "bcond target"s;
    __Vtask_tb_ozone_backend__DOT__check_u64__144__expected = 0x0000000000001010ULL;
    __Vtask_tb_ozone_backend__DOT__check_u64__144__got 
        = (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__rob__DOT__rob_entries
                            [__Vtask_tb_ozone_backend__DOT__test_nzcv_and_bcond_forwarding__107__branch_tag][3U])) 
            << 0x00000020U) | (QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__rob__DOT__rob_entries
                                              [__Vtask_tb_ozone_backend__DOT__test_nzcv_and_bcond_forwarding__107__branch_tag][2U])));
    if (VL_UNLIKELY(((__Vtask_tb_ozone_backend__DOT__check_u64__144__got 
                      != __Vtask_tb_ozone_backend__DOT__check_u64__144__expected)))) {
        tb_ozone_backend__DOT__failures = ((IData)(1U) 
                                           + tb_ozone_backend__DOT__failures);
        VL_WRITEF_NX("[FAIL] %@ expected=0x%016x got=0x%016x\n",0,
                     -1,&(vlSelfRef.__Vtask_tb_ozone_backend__DOT__check_u64__144__label),
                     64,__Vtask_tb_ozone_backend__DOT__check_u64__144__expected,
                     64,__Vtask_tb_ozone_backend__DOT__check_u64__144__got);
    }
    if (VL_UNLIKELY(((0U != tb_ozone_backend__DOT__failures)))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_ozone_backend.sv:901: Assertion failed in %Ntb_ozone_backend: tb_ozone_backend failed with %0d failures\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     32,tb_ozone_backend__DOT__failures);
        VL_STOP_MT("tb/tb_ozone_backend.sv", 901, "", false);
    }
    VL_WRITEF_NX("tb_ozone_backend passed\n",0);
    VL_FINISH_MT("tb/tb_ozone_backend.sv", 905, "");
    co_return;
}
