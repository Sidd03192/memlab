// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_ozone_cdb.h for the primary calling header

#include "Vtb_ozone_cdb__pch.h"

VL_ATTR_COLD void Vtb_ozone_cdb___024root___eval_static(Vtb_ozone_cdb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ozone_cdb___024root___eval_static\n"); );
    Vtb_ozone_cdb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*2:0*/ __Vinline__eval_static__TOP_tb_ozone_cdb__DOT__dut__DOT__unnamedblk1__DOT__winner;
    __Vinline__eval_static__TOP_tb_ozone_cdb__DOT__dut__DOT__unnamedblk1__DOT__winner = 0;
    CData/*5:0*/ __Vinline__eval_static__TOP_tb_ozone_cdb__DOT__dut__DOT__unnamedblk1__DOT__best_age;
    __Vinline__eval_static__TOP_tb_ozone_cdb__DOT__dut__DOT__unnamedblk1__DOT__best_age = 0;
    // Body
    __Vinline__eval_static__TOP_tb_ozone_cdb__DOT__dut__DOT__unnamedblk1__DOT__winner = 0;
    __Vinline__eval_static__TOP_tb_ozone_cdb__DOT__dut__DOT__unnamedblk1__DOT__best_age = 0;
    do {
        vlSelfRef.__VactTriggeredAcc[vlSelfRef.__Vi] 
            = vlSelfRef.__VactTriggered[vlSelfRef.__Vi];
        vlSelfRef.__Vi = ((IData)(1U) + vlSelfRef.__Vi);
    } while ((0U >= vlSelfRef.__Vi));
}

VL_ATTR_COLD void Vtb_ozone_cdb___024root___eval_static__TOP(Vtb_ozone_cdb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ozone_cdb___024root___eval_static__TOP\n"); );
    Vtb_ozone_cdb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*2:0*/ tb_ozone_cdb__DOT__dut__DOT__unnamedblk1__DOT__winner;
    tb_ozone_cdb__DOT__dut__DOT__unnamedblk1__DOT__winner = 0;
    CData/*5:0*/ tb_ozone_cdb__DOT__dut__DOT__unnamedblk1__DOT__best_age;
    tb_ozone_cdb__DOT__dut__DOT__unnamedblk1__DOT__best_age = 0;
    // Body
    tb_ozone_cdb__DOT__dut__DOT__unnamedblk1__DOT__winner = 0;
    tb_ozone_cdb__DOT__dut__DOT__unnamedblk1__DOT__best_age = 0;
}

VL_ATTR_COLD void Vtb_ozone_cdb___024root___eval_final(Vtb_ozone_cdb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ozone_cdb___024root___eval_final\n"); );
    Vtb_ozone_cdb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_ozone_cdb___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_ozone_cdb___024root___eval_phase__stl(Vtb_ozone_cdb___024root* vlSelf);

VL_ATTR_COLD void Vtb_ozone_cdb___024root___eval_settle(Vtb_ozone_cdb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ozone_cdb___024root___eval_settle\n"); );
    Vtb_ozone_cdb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtb_ozone_cdb___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("tb/tb_ozone_backend.sv", 4, "", "DIDNOTCONVERGE: Settle region did not converge after '--converge-limit' of 100 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        vlSelfRef.__VstlPhaseResult = Vtb_ozone_cdb___024root___eval_phase__stl(vlSelf);
        vlSelfRef.__VstlFirstIteration = 0U;
    } while (vlSelfRef.__VstlPhaseResult);
}

VL_ATTR_COLD void Vtb_ozone_cdb___024root___eval_triggers_vec__stl(Vtb_ozone_cdb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ozone_cdb___024root___eval_triggers_vec__stl\n"); );
    Vtb_ozone_cdb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered[0U]) 
                                     | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
}

VL_ATTR_COLD bool Vtb_ozone_cdb___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_ozone_cdb___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ozone_cdb___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vtb_ozone_cdb___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vtb_ozone_cdb___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ozone_cdb___024root___trigger_anySet__stl\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vtb_ozone_cdb___024root___act_sequent__TOP__0(Vtb_ozone_cdb___024root* vlSelf);

VL_ATTR_COLD void Vtb_ozone_cdb___024root___eval_stl(Vtb_ozone_cdb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ozone_cdb___024root___eval_stl\n"); );
    Vtb_ozone_cdb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vtb_ozone_cdb___024root___act_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD bool Vtb_ozone_cdb___024root___eval_phase__stl(Vtb_ozone_cdb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ozone_cdb___024root___eval_phase__stl\n"); );
    Vtb_ozone_cdb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtb_ozone_cdb___024root___eval_triggers_vec__stl(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_ozone_cdb___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vtb_ozone_cdb___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        Vtb_ozone_cdb___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool Vtb_ozone_cdb___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_ozone_cdb___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ozone_cdb___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vtb_ozone_cdb___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_ozone_cdb___024root___ctor_var_reset(Vtb_ozone_cdb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ozone_cdb___024root___ctor_var_reset\n"); );
    Vtb_ozone_cdb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    VL_SCOPED_RAND_RESET_W(151, vlSelf->tb_ozone_cdb__DOT__adder_req, __VscopeHash, 15827380170978044039ull);
    VL_SCOPED_RAND_RESET_W(151, vlSelf->tb_ozone_cdb__DOT__logic_req, __VscopeHash, 15560729068268431028ull);
    VL_SCOPED_RAND_RESET_W(151, vlSelf->tb_ozone_cdb__DOT__fpu_req, __VscopeHash, 1060955263565037454ull);
    VL_SCOPED_RAND_RESET_W(151, vlSelf->tb_ozone_cdb__DOT__mem_req, __VscopeHash, 1494274671894041483ull);
    vlSelf->tb_ozone_cdb__DOT__rob_head = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 7801191124627850772ull);
    VL_SCOPED_RAND_RESET_W(151, vlSelf->tb_ozone_cdb__DOT__cdb_broadcast, __VscopeHash, 2859058326979911358ull);
    vlSelf->tb_ozone_cdb__DOT__adder_granted = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4517701172082672587ull);
    vlSelf->tb_ozone_cdb__DOT__logic_granted = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14720258372502236601ull);
    vlSelf->tb_ozone_cdb__DOT__fpu_granted = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13911406065147085171ull);
    vlSelf->tb_ozone_cdb__DOT__mem_granted = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5289934047896323572ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggeredAcc[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    vlSelf->__Vi = 0;
}
