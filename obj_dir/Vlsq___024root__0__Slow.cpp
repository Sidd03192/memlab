// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vlsq.h for the primary calling header

#include "Vlsq__pch.h"

VL_ATTR_COLD void Vlsq___024root___eval_static(Vlsq___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlsq___024root___eval_static\n"); );
    Vlsq__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.lsq_tb__DOT__test_num = 0U;
    vlSelfRef.lsq_tb__DOT__pass_count = 0U;
    vlSelfRef.lsq_tb__DOT__fail_count = 0U;
    vlSelfRef.__Vtrigprevexpr___TOP__lsq_tb__DOT__clk__0 
        = vlSelfRef.lsq_tb__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__lsq_tb__DOT__rst_n__0 
        = vlSelfRef.lsq_tb__DOT__rst_n;
}

VL_ATTR_COLD void Vlsq___024root___eval_static__TOP(Vlsq___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlsq___024root___eval_static__TOP\n"); );
    Vlsq__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.lsq_tb__DOT__test_num = 0U;
    vlSelfRef.lsq_tb__DOT__pass_count = 0U;
    vlSelfRef.lsq_tb__DOT__fail_count = 0U;
}

VL_ATTR_COLD void Vlsq___024root___eval_initial__TOP(Vlsq___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlsq___024root___eval_initial__TOP\n"); );
    Vlsq__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.lsq_tb__DOT__clk = 0U;
}

VL_ATTR_COLD void Vlsq___024root___eval_final(Vlsq___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlsq___024root___eval_final\n"); );
    Vlsq__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vlsq___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vlsq___024root___eval_phase__stl(Vlsq___024root* vlSelf);

VL_ATTR_COLD void Vlsq___024root___eval_settle(Vlsq___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlsq___024root___eval_settle\n"); );
    Vlsq__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vlsq___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("tb_lsq.sv", 19, "", "DIDNOTCONVERGE: Settle region did not converge after 100 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
    } while (Vlsq___024root___eval_phase__stl(vlSelf));
}

VL_ATTR_COLD void Vlsq___024root___eval_triggers__stl(Vlsq___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlsq___024root___eval_triggers__stl\n"); );
    Vlsq__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered
                                      [0U]) | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
    vlSelfRef.__VstlFirstIteration = 0U;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vlsq___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
}

VL_ATTR_COLD bool Vlsq___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vlsq___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlsq___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vlsq___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vlsq___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlsq___024root___trigger_anySet__stl\n"); );
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

VL_ATTR_COLD void Vlsq___024root___stl_sequent__TOP__0(Vlsq___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlsq___024root___stl_sequent__TOP__0\n"); );
    Vlsq__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ lsq_tb__DOT__dut__DOT__sq_unresolved;
    lsq_tb__DOT__dut__DOT__sq_unresolved = 0;
    CData/*0:0*/ lsq_tb__DOT__dut__DOT__terminate_loop;
    lsq_tb__DOT__dut__DOT__terminate_loop = 0;
    CData/*2:0*/ lsq_tb__DOT__dut__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx;
    lsq_tb__DOT__dut__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx = 0;
    CData/*2:0*/ lsq_tb__DOT__dut__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx;
    lsq_tb__DOT__dut__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx = 0;
    CData/*2:0*/ lsq_tb__DOT__dut__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx;
    lsq_tb__DOT__dut__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx = 0;
    CData/*2:0*/ lsq_tb__DOT__dut__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx;
    lsq_tb__DOT__dut__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx = 0;
    CData/*2:0*/ lsq_tb__DOT__dut__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx;
    lsq_tb__DOT__dut__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx = 0;
    // Body
    vlSelfRef.lsq_tb__DOT__sq_ready = (((IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__sq_tail) 
                                        != (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__sq_head)) 
                                       | (0U == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_state
                                          [vlSelfRef.lsq_tb__DOT__dut__DOT__sq_head]));
    vlSelfRef.lsq_tb__DOT__dut__DOT__lq_found = 0U;
    vlSelfRef.lsq_tb__DOT__dut__DOT__lq_found_entry = 0U;
    lsq_tb__DOT__dut__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx 
        = vlSelfRef.lsq_tb__DOT__dut__DOT__lq_head;
    if ((2U == vlSelfRef.lsq_tb__DOT__dut__DOT__lq_state
         [lsq_tb__DOT__dut__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx])) {
        vlSelfRef.lsq_tb__DOT__dut__DOT__lq_found = 1U;
        vlSelfRef.lsq_tb__DOT__dut__DOT__lq_found_entry 
            = lsq_tb__DOT__dut__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx;
    }
    lsq_tb__DOT__dut__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx 
        = (7U & ((IData)(1U) + (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__lq_head)));
    if (((~ (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__lq_found)) 
         & (2U == vlSelfRef.lsq_tb__DOT__dut__DOT__lq_state
            [lsq_tb__DOT__dut__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx]))) {
        vlSelfRef.lsq_tb__DOT__dut__DOT__lq_found = 1U;
        vlSelfRef.lsq_tb__DOT__dut__DOT__lq_found_entry 
            = lsq_tb__DOT__dut__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx;
    }
    lsq_tb__DOT__dut__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx 
        = (7U & ((IData)(2U) + (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__lq_head)));
    if (((~ (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__lq_found)) 
         & (2U == vlSelfRef.lsq_tb__DOT__dut__DOT__lq_state
            [lsq_tb__DOT__dut__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx]))) {
        vlSelfRef.lsq_tb__DOT__dut__DOT__lq_found = 1U;
        vlSelfRef.lsq_tb__DOT__dut__DOT__lq_found_entry 
            = lsq_tb__DOT__dut__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx;
    }
    lsq_tb__DOT__dut__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx 
        = (7U & ((IData)(3U) + (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__lq_head)));
    if (((~ (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__lq_found)) 
         & (2U == vlSelfRef.lsq_tb__DOT__dut__DOT__lq_state
            [lsq_tb__DOT__dut__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx]))) {
        vlSelfRef.lsq_tb__DOT__dut__DOT__lq_found = 1U;
        vlSelfRef.lsq_tb__DOT__dut__DOT__lq_found_entry 
            = lsq_tb__DOT__dut__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx;
    }
    lsq_tb__DOT__dut__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx 
        = (7U & ((IData)(4U) + (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__lq_head)));
    if (((~ (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__lq_found)) 
         & (2U == vlSelfRef.lsq_tb__DOT__dut__DOT__lq_state
            [lsq_tb__DOT__dut__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx]))) {
        vlSelfRef.lsq_tb__DOT__dut__DOT__lq_found = 1U;
        vlSelfRef.lsq_tb__DOT__dut__DOT__lq_found_entry 
            = lsq_tb__DOT__dut__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx;
    }
    lsq_tb__DOT__dut__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx 
        = (7U & ((IData)(5U) + (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__lq_head)));
    if (((~ (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__lq_found)) 
         & (2U == vlSelfRef.lsq_tb__DOT__dut__DOT__lq_state
            [lsq_tb__DOT__dut__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx]))) {
        vlSelfRef.lsq_tb__DOT__dut__DOT__lq_found = 1U;
        vlSelfRef.lsq_tb__DOT__dut__DOT__lq_found_entry 
            = lsq_tb__DOT__dut__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx;
    }
    lsq_tb__DOT__dut__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx 
        = (7U & ((IData)(6U) + (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__lq_head)));
    if (((~ (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__lq_found)) 
         & (2U == vlSelfRef.lsq_tb__DOT__dut__DOT__lq_state
            [lsq_tb__DOT__dut__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx]))) {
        vlSelfRef.lsq_tb__DOT__dut__DOT__lq_found = 1U;
        vlSelfRef.lsq_tb__DOT__dut__DOT__lq_found_entry 
            = lsq_tb__DOT__dut__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx;
    }
    lsq_tb__DOT__dut__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx 
        = (7U & ((IData)(7U) + (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__lq_head)));
    if (((~ (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__lq_found)) 
         & (2U == vlSelfRef.lsq_tb__DOT__dut__DOT__lq_state
            [lsq_tb__DOT__dut__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx]))) {
        vlSelfRef.lsq_tb__DOT__dut__DOT__lq_found = 1U;
        vlSelfRef.lsq_tb__DOT__dut__DOT__lq_found_entry 
            = lsq_tb__DOT__dut__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx;
    }
    vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found = 0U;
    vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found_entry = 0U;
    lsq_tb__DOT__dut__DOT__sq_unresolved = 0U;
    lsq_tb__DOT__dut__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx 
        = vlSelfRef.lsq_tb__DOT__dut__DOT__sq_head;
    if ((4U == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_state
         [lsq_tb__DOT__dut__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx])) {
        vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found = 1U;
        vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found_entry 
            = lsq_tb__DOT__dut__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx;
    } else if ((((~ (IData)(lsq_tb__DOT__dut__DOT__sq_unresolved)) 
                 & (~ (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found))) 
                & ((2U == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_state
                    [lsq_tb__DOT__dut__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx]) 
                   | (1U == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_state
                      [lsq_tb__DOT__dut__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx])))) {
        lsq_tb__DOT__dut__DOT__sq_unresolved = 1U;
    }
    lsq_tb__DOT__dut__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx 
        = (7U & ((IData)(1U) + (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__sq_head)));
    if ((((~ (IData)(lsq_tb__DOT__dut__DOT__sq_unresolved)) 
          & (~ (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found))) 
         & (4U == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_state
            [lsq_tb__DOT__dut__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx]))) {
        vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found = 1U;
        vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found_entry 
            = lsq_tb__DOT__dut__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx;
    } else if ((((~ (IData)(lsq_tb__DOT__dut__DOT__sq_unresolved)) 
                 & (~ (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found))) 
                & ((2U == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_state
                    [lsq_tb__DOT__dut__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx]) 
                   | (1U == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_state
                      [lsq_tb__DOT__dut__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx])))) {
        lsq_tb__DOT__dut__DOT__sq_unresolved = 1U;
    }
    lsq_tb__DOT__dut__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx 
        = (7U & ((IData)(2U) + (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__sq_head)));
    if ((((~ (IData)(lsq_tb__DOT__dut__DOT__sq_unresolved)) 
          & (~ (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found))) 
         & (4U == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_state
            [lsq_tb__DOT__dut__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx]))) {
        vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found = 1U;
        vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found_entry 
            = lsq_tb__DOT__dut__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx;
    } else if ((((~ (IData)(lsq_tb__DOT__dut__DOT__sq_unresolved)) 
                 & (~ (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found))) 
                & ((2U == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_state
                    [lsq_tb__DOT__dut__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx]) 
                   | (1U == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_state
                      [lsq_tb__DOT__dut__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx])))) {
        lsq_tb__DOT__dut__DOT__sq_unresolved = 1U;
    }
    lsq_tb__DOT__dut__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx 
        = (7U & ((IData)(3U) + (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__sq_head)));
    if ((((~ (IData)(lsq_tb__DOT__dut__DOT__sq_unresolved)) 
          & (~ (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found))) 
         & (4U == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_state
            [lsq_tb__DOT__dut__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx]))) {
        vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found = 1U;
        vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found_entry 
            = lsq_tb__DOT__dut__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx;
    } else if ((((~ (IData)(lsq_tb__DOT__dut__DOT__sq_unresolved)) 
                 & (~ (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found))) 
                & ((2U == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_state
                    [lsq_tb__DOT__dut__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx]) 
                   | (1U == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_state
                      [lsq_tb__DOT__dut__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx])))) {
        lsq_tb__DOT__dut__DOT__sq_unresolved = 1U;
    }
    lsq_tb__DOT__dut__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx 
        = (7U & ((IData)(4U) + (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__sq_head)));
    if ((((~ (IData)(lsq_tb__DOT__dut__DOT__sq_unresolved)) 
          & (~ (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found))) 
         & (4U == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_state
            [lsq_tb__DOT__dut__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx]))) {
        vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found = 1U;
        vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found_entry 
            = lsq_tb__DOT__dut__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx;
    } else if ((((~ (IData)(lsq_tb__DOT__dut__DOT__sq_unresolved)) 
                 & (~ (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found))) 
                & ((2U == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_state
                    [lsq_tb__DOT__dut__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx]) 
                   | (1U == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_state
                      [lsq_tb__DOT__dut__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx])))) {
        lsq_tb__DOT__dut__DOT__sq_unresolved = 1U;
    }
    lsq_tb__DOT__dut__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx 
        = (7U & ((IData)(5U) + (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__sq_head)));
    if ((((~ (IData)(lsq_tb__DOT__dut__DOT__sq_unresolved)) 
          & (~ (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found))) 
         & (4U == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_state
            [lsq_tb__DOT__dut__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx]))) {
        vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found = 1U;
        vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found_entry 
            = lsq_tb__DOT__dut__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx;
    } else if ((((~ (IData)(lsq_tb__DOT__dut__DOT__sq_unresolved)) 
                 & (~ (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found))) 
                & ((2U == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_state
                    [lsq_tb__DOT__dut__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx]) 
                   | (1U == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_state
                      [lsq_tb__DOT__dut__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx])))) {
        lsq_tb__DOT__dut__DOT__sq_unresolved = 1U;
    }
    lsq_tb__DOT__dut__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx 
        = (7U & ((IData)(6U) + (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__sq_head)));
    if ((((~ (IData)(lsq_tb__DOT__dut__DOT__sq_unresolved)) 
          & (~ (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found))) 
         & (4U == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_state
            [lsq_tb__DOT__dut__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx]))) {
        vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found = 1U;
        vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found_entry 
            = lsq_tb__DOT__dut__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx;
    } else if ((((~ (IData)(lsq_tb__DOT__dut__DOT__sq_unresolved)) 
                 & (~ (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found))) 
                & ((2U == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_state
                    [lsq_tb__DOT__dut__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx]) 
                   | (1U == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_state
                      [lsq_tb__DOT__dut__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx])))) {
        lsq_tb__DOT__dut__DOT__sq_unresolved = 1U;
    }
    lsq_tb__DOT__dut__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx 
        = (7U & ((IData)(7U) + (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__sq_head)));
    if ((((~ (IData)(lsq_tb__DOT__dut__DOT__sq_unresolved)) 
          & (~ (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found))) 
         & (4U == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_state
            [lsq_tb__DOT__dut__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx]))) {
        vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found = 1U;
        vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found_entry 
            = lsq_tb__DOT__dut__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx;
    } else if ((((~ (IData)(lsq_tb__DOT__dut__DOT__sq_unresolved)) 
                 & (~ (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found))) 
                & ((2U == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_state
                    [lsq_tb__DOT__dut__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx]) 
                   | (1U == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_state
                      [lsq_tb__DOT__dut__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx])))) {
        lsq_tb__DOT__dut__DOT__sq_unresolved = 1U;
    }
    vlSelfRef.lsq_tb__DOT__dut__DOT__is_unresolved_store = 0U;
    lsq_tb__DOT__dut__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx 
        = vlSelfRef.lsq_tb__DOT__dut__DOT__sq_head;
    if (vlSelfRef.lsq_tb__DOT__dut__DOT__lq_found) {
        if ((((~ (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__is_unresolved_store)) 
              & (vlSelfRef.lsq_tb__DOT__dut__DOT__lq_before_vec
                 [vlSelfRef.lsq_tb__DOT__dut__DOT__lq_found_entry] 
                 >> (IData)(lsq_tb__DOT__dut__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx))) 
             & (((2U == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_state
                  [lsq_tb__DOT__dut__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx]) 
                 | (1U == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_state
                    [lsq_tb__DOT__dut__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx])) 
                | ((3U == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_state
                    [lsq_tb__DOT__dut__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx]) 
                   & (vlSelfRef.lsq_tb__DOT__dut__DOT__sq_vaddr
                      [lsq_tb__DOT__dut__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx] 
                      == vlSelfRef.lsq_tb__DOT__dut__DOT__lq_vaddr
                      [vlSelfRef.lsq_tb__DOT__dut__DOT__lq_found_entry]))))) {
            vlSelfRef.lsq_tb__DOT__dut__DOT__is_unresolved_store = 1U;
        }
    }
    lsq_tb__DOT__dut__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx 
        = (7U & ((IData)(1U) + (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__sq_head)));
    if (vlSelfRef.lsq_tb__DOT__dut__DOT__lq_found) {
        if ((((~ (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__is_unresolved_store)) 
              & (vlSelfRef.lsq_tb__DOT__dut__DOT__lq_before_vec
                 [vlSelfRef.lsq_tb__DOT__dut__DOT__lq_found_entry] 
                 >> (IData)(lsq_tb__DOT__dut__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx))) 
             & (((2U == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_state
                  [lsq_tb__DOT__dut__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx]) 
                 | (1U == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_state
                    [lsq_tb__DOT__dut__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx])) 
                | ((3U == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_state
                    [lsq_tb__DOT__dut__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx]) 
                   & (vlSelfRef.lsq_tb__DOT__dut__DOT__sq_vaddr
                      [lsq_tb__DOT__dut__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx] 
                      == vlSelfRef.lsq_tb__DOT__dut__DOT__lq_vaddr
                      [vlSelfRef.lsq_tb__DOT__dut__DOT__lq_found_entry]))))) {
            vlSelfRef.lsq_tb__DOT__dut__DOT__is_unresolved_store = 1U;
        }
    }
    lsq_tb__DOT__dut__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx 
        = (7U & ((IData)(2U) + (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__sq_head)));
    if (vlSelfRef.lsq_tb__DOT__dut__DOT__lq_found) {
        if ((((~ (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__is_unresolved_store)) 
              & (vlSelfRef.lsq_tb__DOT__dut__DOT__lq_before_vec
                 [vlSelfRef.lsq_tb__DOT__dut__DOT__lq_found_entry] 
                 >> (IData)(lsq_tb__DOT__dut__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx))) 
             & (((2U == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_state
                  [lsq_tb__DOT__dut__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx]) 
                 | (1U == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_state
                    [lsq_tb__DOT__dut__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx])) 
                | ((3U == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_state
                    [lsq_tb__DOT__dut__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx]) 
                   & (vlSelfRef.lsq_tb__DOT__dut__DOT__sq_vaddr
                      [lsq_tb__DOT__dut__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx] 
                      == vlSelfRef.lsq_tb__DOT__dut__DOT__lq_vaddr
                      [vlSelfRef.lsq_tb__DOT__dut__DOT__lq_found_entry]))))) {
            vlSelfRef.lsq_tb__DOT__dut__DOT__is_unresolved_store = 1U;
        }
    }
    lsq_tb__DOT__dut__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx 
        = (7U & ((IData)(3U) + (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__sq_head)));
    if (vlSelfRef.lsq_tb__DOT__dut__DOT__lq_found) {
        if ((((~ (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__is_unresolved_store)) 
              & (vlSelfRef.lsq_tb__DOT__dut__DOT__lq_before_vec
                 [vlSelfRef.lsq_tb__DOT__dut__DOT__lq_found_entry] 
                 >> (IData)(lsq_tb__DOT__dut__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx))) 
             & (((2U == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_state
                  [lsq_tb__DOT__dut__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx]) 
                 | (1U == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_state
                    [lsq_tb__DOT__dut__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx])) 
                | ((3U == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_state
                    [lsq_tb__DOT__dut__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx]) 
                   & (vlSelfRef.lsq_tb__DOT__dut__DOT__sq_vaddr
                      [lsq_tb__DOT__dut__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx] 
                      == vlSelfRef.lsq_tb__DOT__dut__DOT__lq_vaddr
                      [vlSelfRef.lsq_tb__DOT__dut__DOT__lq_found_entry]))))) {
            vlSelfRef.lsq_tb__DOT__dut__DOT__is_unresolved_store = 1U;
        }
    }
    lsq_tb__DOT__dut__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx 
        = (7U & ((IData)(4U) + (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__sq_head)));
    if (vlSelfRef.lsq_tb__DOT__dut__DOT__lq_found) {
        if ((((~ (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__is_unresolved_store)) 
              & (vlSelfRef.lsq_tb__DOT__dut__DOT__lq_before_vec
                 [vlSelfRef.lsq_tb__DOT__dut__DOT__lq_found_entry] 
                 >> (IData)(lsq_tb__DOT__dut__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx))) 
             & (((2U == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_state
                  [lsq_tb__DOT__dut__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx]) 
                 | (1U == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_state
                    [lsq_tb__DOT__dut__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx])) 
                | ((3U == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_state
                    [lsq_tb__DOT__dut__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx]) 
                   & (vlSelfRef.lsq_tb__DOT__dut__DOT__sq_vaddr
                      [lsq_tb__DOT__dut__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx] 
                      == vlSelfRef.lsq_tb__DOT__dut__DOT__lq_vaddr
                      [vlSelfRef.lsq_tb__DOT__dut__DOT__lq_found_entry]))))) {
            vlSelfRef.lsq_tb__DOT__dut__DOT__is_unresolved_store = 1U;
        }
    }
    lsq_tb__DOT__dut__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx 
        = (7U & ((IData)(5U) + (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__sq_head)));
    if (vlSelfRef.lsq_tb__DOT__dut__DOT__lq_found) {
        if ((((~ (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__is_unresolved_store)) 
              & (vlSelfRef.lsq_tb__DOT__dut__DOT__lq_before_vec
                 [vlSelfRef.lsq_tb__DOT__dut__DOT__lq_found_entry] 
                 >> (IData)(lsq_tb__DOT__dut__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx))) 
             & (((2U == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_state
                  [lsq_tb__DOT__dut__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx]) 
                 | (1U == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_state
                    [lsq_tb__DOT__dut__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx])) 
                | ((3U == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_state
                    [lsq_tb__DOT__dut__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx]) 
                   & (vlSelfRef.lsq_tb__DOT__dut__DOT__sq_vaddr
                      [lsq_tb__DOT__dut__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx] 
                      == vlSelfRef.lsq_tb__DOT__dut__DOT__lq_vaddr
                      [vlSelfRef.lsq_tb__DOT__dut__DOT__lq_found_entry]))))) {
            vlSelfRef.lsq_tb__DOT__dut__DOT__is_unresolved_store = 1U;
        }
    }
    lsq_tb__DOT__dut__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx 
        = (7U & ((IData)(6U) + (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__sq_head)));
    if (vlSelfRef.lsq_tb__DOT__dut__DOT__lq_found) {
        if ((((~ (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__is_unresolved_store)) 
              & (vlSelfRef.lsq_tb__DOT__dut__DOT__lq_before_vec
                 [vlSelfRef.lsq_tb__DOT__dut__DOT__lq_found_entry] 
                 >> (IData)(lsq_tb__DOT__dut__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx))) 
             & (((2U == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_state
                  [lsq_tb__DOT__dut__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx]) 
                 | (1U == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_state
                    [lsq_tb__DOT__dut__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx])) 
                | ((3U == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_state
                    [lsq_tb__DOT__dut__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx]) 
                   & (vlSelfRef.lsq_tb__DOT__dut__DOT__sq_vaddr
                      [lsq_tb__DOT__dut__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx] 
                      == vlSelfRef.lsq_tb__DOT__dut__DOT__lq_vaddr
                      [vlSelfRef.lsq_tb__DOT__dut__DOT__lq_found_entry]))))) {
            vlSelfRef.lsq_tb__DOT__dut__DOT__is_unresolved_store = 1U;
        }
    }
    lsq_tb__DOT__dut__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx 
        = (7U & ((IData)(7U) + (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__sq_head)));
    if (vlSelfRef.lsq_tb__DOT__dut__DOT__lq_found) {
        if ((((~ (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__is_unresolved_store)) 
              & (vlSelfRef.lsq_tb__DOT__dut__DOT__lq_before_vec
                 [vlSelfRef.lsq_tb__DOT__dut__DOT__lq_found_entry] 
                 >> (IData)(lsq_tb__DOT__dut__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx))) 
             & (((2U == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_state
                  [lsq_tb__DOT__dut__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx]) 
                 | (1U == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_state
                    [lsq_tb__DOT__dut__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx])) 
                | ((3U == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_state
                    [lsq_tb__DOT__dut__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx]) 
                   & (vlSelfRef.lsq_tb__DOT__dut__DOT__sq_vaddr
                      [lsq_tb__DOT__dut__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx] 
                      == vlSelfRef.lsq_tb__DOT__dut__DOT__lq_vaddr
                      [vlSelfRef.lsq_tb__DOT__dut__DOT__lq_found_entry]))))) {
            vlSelfRef.lsq_tb__DOT__dut__DOT__is_unresolved_store = 1U;
        }
    }
    vlSelfRef.lsq_tb__DOT__dut__DOT__is_unresolved_load = 0U;
    lsq_tb__DOT__dut__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx 
        = vlSelfRef.lsq_tb__DOT__dut__DOT__lq_head;
    if (vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found) {
        if ((((~ (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__is_unresolved_load)) 
              & (vlSelfRef.lsq_tb__DOT__dut__DOT__sq_before_vec
                 [vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found_entry] 
                 >> (IData)(lsq_tb__DOT__dut__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx))) 
             & (1U == vlSelfRef.lsq_tb__DOT__dut__DOT__lq_state
                [lsq_tb__DOT__dut__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx]))) {
            vlSelfRef.lsq_tb__DOT__dut__DOT__is_unresolved_load = 1U;
        }
    }
    lsq_tb__DOT__dut__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx 
        = (7U & ((IData)(1U) + (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__lq_head)));
    if (vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found) {
        if ((((~ (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__is_unresolved_load)) 
              & (vlSelfRef.lsq_tb__DOT__dut__DOT__sq_before_vec
                 [vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found_entry] 
                 >> (IData)(lsq_tb__DOT__dut__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx))) 
             & (1U == vlSelfRef.lsq_tb__DOT__dut__DOT__lq_state
                [lsq_tb__DOT__dut__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx]))) {
            vlSelfRef.lsq_tb__DOT__dut__DOT__is_unresolved_load = 1U;
        }
    }
    lsq_tb__DOT__dut__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx 
        = (7U & ((IData)(2U) + (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__lq_head)));
    if (vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found) {
        if ((((~ (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__is_unresolved_load)) 
              & (vlSelfRef.lsq_tb__DOT__dut__DOT__sq_before_vec
                 [vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found_entry] 
                 >> (IData)(lsq_tb__DOT__dut__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx))) 
             & (1U == vlSelfRef.lsq_tb__DOT__dut__DOT__lq_state
                [lsq_tb__DOT__dut__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx]))) {
            vlSelfRef.lsq_tb__DOT__dut__DOT__is_unresolved_load = 1U;
        }
    }
    lsq_tb__DOT__dut__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx 
        = (7U & ((IData)(3U) + (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__lq_head)));
    if (vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found) {
        if ((((~ (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__is_unresolved_load)) 
              & (vlSelfRef.lsq_tb__DOT__dut__DOT__sq_before_vec
                 [vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found_entry] 
                 >> (IData)(lsq_tb__DOT__dut__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx))) 
             & (1U == vlSelfRef.lsq_tb__DOT__dut__DOT__lq_state
                [lsq_tb__DOT__dut__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx]))) {
            vlSelfRef.lsq_tb__DOT__dut__DOT__is_unresolved_load = 1U;
        }
    }
    lsq_tb__DOT__dut__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx 
        = (7U & ((IData)(4U) + (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__lq_head)));
    if (vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found) {
        if ((((~ (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__is_unresolved_load)) 
              & (vlSelfRef.lsq_tb__DOT__dut__DOT__sq_before_vec
                 [vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found_entry] 
                 >> (IData)(lsq_tb__DOT__dut__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx))) 
             & (1U == vlSelfRef.lsq_tb__DOT__dut__DOT__lq_state
                [lsq_tb__DOT__dut__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx]))) {
            vlSelfRef.lsq_tb__DOT__dut__DOT__is_unresolved_load = 1U;
        }
    }
    lsq_tb__DOT__dut__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx 
        = (7U & ((IData)(5U) + (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__lq_head)));
    if (vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found) {
        if ((((~ (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__is_unresolved_load)) 
              & (vlSelfRef.lsq_tb__DOT__dut__DOT__sq_before_vec
                 [vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found_entry] 
                 >> (IData)(lsq_tb__DOT__dut__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx))) 
             & (1U == vlSelfRef.lsq_tb__DOT__dut__DOT__lq_state
                [lsq_tb__DOT__dut__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx]))) {
            vlSelfRef.lsq_tb__DOT__dut__DOT__is_unresolved_load = 1U;
        }
    }
    lsq_tb__DOT__dut__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx 
        = (7U & ((IData)(6U) + (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__lq_head)));
    if (vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found) {
        if ((((~ (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__is_unresolved_load)) 
              & (vlSelfRef.lsq_tb__DOT__dut__DOT__sq_before_vec
                 [vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found_entry] 
                 >> (IData)(lsq_tb__DOT__dut__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx))) 
             & (1U == vlSelfRef.lsq_tb__DOT__dut__DOT__lq_state
                [lsq_tb__DOT__dut__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx]))) {
            vlSelfRef.lsq_tb__DOT__dut__DOT__is_unresolved_load = 1U;
        }
    }
    lsq_tb__DOT__dut__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx 
        = (7U & ((IData)(7U) + (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__lq_head)));
    vlSelfRef.lsq_tb__DOT__dut__DOT__unresolved_val_store = 0U;
    lsq_tb__DOT__dut__DOT__terminate_loop = 0U;
    lsq_tb__DOT__dut__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx 
        = vlSelfRef.lsq_tb__DOT__dut__DOT__sq_head;
    if (vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found) {
        if ((((~ (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__is_unresolved_load)) 
              & (vlSelfRef.lsq_tb__DOT__dut__DOT__sq_before_vec
                 [vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found_entry] 
                 >> (IData)(lsq_tb__DOT__dut__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx))) 
             & (1U == vlSelfRef.lsq_tb__DOT__dut__DOT__lq_state
                [lsq_tb__DOT__dut__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx]))) {
            vlSelfRef.lsq_tb__DOT__dut__DOT__is_unresolved_load = 1U;
        }
        if (((IData)(lsq_tb__DOT__dut__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx) 
             == (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found_entry))) {
            lsq_tb__DOT__dut__DOT__terminate_loop = 1U;
        } else if (((((~ (IData)(lsq_tb__DOT__dut__DOT__terminate_loop)) 
                      & (~ (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__unresolved_val_store))) 
                     & (vlSelfRef.lsq_tb__DOT__dut__DOT__sq_vaddr
                        [vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found_entry] 
                        == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_vaddr
                        [lsq_tb__DOT__dut__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx])) 
                    & (3U == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_state
                       [lsq_tb__DOT__dut__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx]))) {
            vlSelfRef.lsq_tb__DOT__dut__DOT__unresolved_val_store = 1U;
            lsq_tb__DOT__dut__DOT__terminate_loop = 1U;
        }
    }
    lsq_tb__DOT__dut__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx 
        = (7U & ((IData)(1U) + (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__sq_head)));
    if (vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found) {
        if (((IData)(lsq_tb__DOT__dut__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx) 
             == (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found_entry))) {
            lsq_tb__DOT__dut__DOT__terminate_loop = 1U;
        } else if (((((~ (IData)(lsq_tb__DOT__dut__DOT__terminate_loop)) 
                      & (~ (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__unresolved_val_store))) 
                     & (vlSelfRef.lsq_tb__DOT__dut__DOT__sq_vaddr
                        [vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found_entry] 
                        == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_vaddr
                        [lsq_tb__DOT__dut__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx])) 
                    & (3U == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_state
                       [lsq_tb__DOT__dut__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx]))) {
            vlSelfRef.lsq_tb__DOT__dut__DOT__unresolved_val_store = 1U;
            lsq_tb__DOT__dut__DOT__terminate_loop = 1U;
        }
    }
    lsq_tb__DOT__dut__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx 
        = (7U & ((IData)(2U) + (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__sq_head)));
    if (vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found) {
        if (((IData)(lsq_tb__DOT__dut__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx) 
             == (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found_entry))) {
            lsq_tb__DOT__dut__DOT__terminate_loop = 1U;
        } else if (((((~ (IData)(lsq_tb__DOT__dut__DOT__terminate_loop)) 
                      & (~ (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__unresolved_val_store))) 
                     & (vlSelfRef.lsq_tb__DOT__dut__DOT__sq_vaddr
                        [vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found_entry] 
                        == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_vaddr
                        [lsq_tb__DOT__dut__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx])) 
                    & (3U == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_state
                       [lsq_tb__DOT__dut__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx]))) {
            vlSelfRef.lsq_tb__DOT__dut__DOT__unresolved_val_store = 1U;
            lsq_tb__DOT__dut__DOT__terminate_loop = 1U;
        }
    }
    lsq_tb__DOT__dut__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx 
        = (7U & ((IData)(3U) + (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__sq_head)));
    if (vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found) {
        if (((IData)(lsq_tb__DOT__dut__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx) 
             == (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found_entry))) {
            lsq_tb__DOT__dut__DOT__terminate_loop = 1U;
        } else if (((((~ (IData)(lsq_tb__DOT__dut__DOT__terminate_loop)) 
                      & (~ (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__unresolved_val_store))) 
                     & (vlSelfRef.lsq_tb__DOT__dut__DOT__sq_vaddr
                        [vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found_entry] 
                        == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_vaddr
                        [lsq_tb__DOT__dut__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx])) 
                    & (3U == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_state
                       [lsq_tb__DOT__dut__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx]))) {
            vlSelfRef.lsq_tb__DOT__dut__DOT__unresolved_val_store = 1U;
            lsq_tb__DOT__dut__DOT__terminate_loop = 1U;
        }
    }
    lsq_tb__DOT__dut__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx 
        = (7U & ((IData)(4U) + (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__sq_head)));
    if (vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found) {
        if (((IData)(lsq_tb__DOT__dut__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx) 
             == (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found_entry))) {
            lsq_tb__DOT__dut__DOT__terminate_loop = 1U;
        } else if (((((~ (IData)(lsq_tb__DOT__dut__DOT__terminate_loop)) 
                      & (~ (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__unresolved_val_store))) 
                     & (vlSelfRef.lsq_tb__DOT__dut__DOT__sq_vaddr
                        [vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found_entry] 
                        == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_vaddr
                        [lsq_tb__DOT__dut__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx])) 
                    & (3U == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_state
                       [lsq_tb__DOT__dut__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx]))) {
            vlSelfRef.lsq_tb__DOT__dut__DOT__unresolved_val_store = 1U;
            lsq_tb__DOT__dut__DOT__terminate_loop = 1U;
        }
    }
    lsq_tb__DOT__dut__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx 
        = (7U & ((IData)(5U) + (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__sq_head)));
    if (vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found) {
        if (((IData)(lsq_tb__DOT__dut__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx) 
             == (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found_entry))) {
            lsq_tb__DOT__dut__DOT__terminate_loop = 1U;
        } else if (((((~ (IData)(lsq_tb__DOT__dut__DOT__terminate_loop)) 
                      & (~ (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__unresolved_val_store))) 
                     & (vlSelfRef.lsq_tb__DOT__dut__DOT__sq_vaddr
                        [vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found_entry] 
                        == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_vaddr
                        [lsq_tb__DOT__dut__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx])) 
                    & (3U == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_state
                       [lsq_tb__DOT__dut__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx]))) {
            vlSelfRef.lsq_tb__DOT__dut__DOT__unresolved_val_store = 1U;
            lsq_tb__DOT__dut__DOT__terminate_loop = 1U;
        }
    }
    lsq_tb__DOT__dut__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx 
        = (7U & ((IData)(6U) + (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__sq_head)));
    if (vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found) {
        if (((IData)(lsq_tb__DOT__dut__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx) 
             == (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found_entry))) {
            lsq_tb__DOT__dut__DOT__terminate_loop = 1U;
        } else if (((((~ (IData)(lsq_tb__DOT__dut__DOT__terminate_loop)) 
                      & (~ (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__unresolved_val_store))) 
                     & (vlSelfRef.lsq_tb__DOT__dut__DOT__sq_vaddr
                        [vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found_entry] 
                        == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_vaddr
                        [lsq_tb__DOT__dut__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx])) 
                    & (3U == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_state
                       [lsq_tb__DOT__dut__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx]))) {
            vlSelfRef.lsq_tb__DOT__dut__DOT__unresolved_val_store = 1U;
            lsq_tb__DOT__dut__DOT__terminate_loop = 1U;
        }
    }
    lsq_tb__DOT__dut__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx 
        = (7U & ((IData)(7U) + (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__sq_head)));
    if (vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found) {
        if (((IData)(lsq_tb__DOT__dut__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx) 
             == (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found_entry))) {
            lsq_tb__DOT__dut__DOT__terminate_loop = 1U;
        } else if (((((~ (IData)(lsq_tb__DOT__dut__DOT__terminate_loop)) 
                      & (~ (IData)(vlSelfRef.lsq_tb__DOT__dut__DOT__unresolved_val_store))) 
                     & (vlSelfRef.lsq_tb__DOT__dut__DOT__sq_vaddr
                        [vlSelfRef.lsq_tb__DOT__dut__DOT__sq_found_entry] 
                        == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_vaddr
                        [lsq_tb__DOT__dut__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx])) 
                    & (3U == vlSelfRef.lsq_tb__DOT__dut__DOT__sq_state
                       [lsq_tb__DOT__dut__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx]))) {
            vlSelfRef.lsq_tb__DOT__dut__DOT__unresolved_val_store = 1U;
            lsq_tb__DOT__dut__DOT__terminate_loop = 1U;
        }
    }
}

VL_ATTR_COLD void Vlsq___024root___eval_stl(Vlsq___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlsq___024root___eval_stl\n"); );
    Vlsq__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vlsq___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD bool Vlsq___024root___eval_phase__stl(Vlsq___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlsq___024root___eval_phase__stl\n"); );
    Vlsq__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    Vlsq___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = Vlsq___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        Vlsq___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool Vlsq___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vlsq___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlsq___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vlsq___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge lsq_tb.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(negedge lsq_tb.rst_n)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((1U & (IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @(negedge lsq_tb.clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vlsq___024root___ctor_var_reset(Vlsq___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlsq___024root___ctor_var_reset\n"); );
    Vlsq__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->lsq_tb__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13176813863752297954ull);
    vlSelf->lsq_tb__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16025668217458111833ull);
    vlSelf->lsq_tb__DOT__op = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 6010752259073805856ull);
    vlSelf->lsq_tb__DOT__valid_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7497970147720064809ull);
    vlSelf->lsq_tb__DOT__vaddr_in = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 1161475834165602233ull);
    vlSelf->lsq_tb__DOT__wdata_in = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 14815644584011593885ull);
    vlSelf->lsq_tb__DOT__vaddr_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14230000157709389224ull);
    vlSelf->lsq_tb__DOT__wdata_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11344494862877912909ull);
    vlSelf->lsq_tb__DOT__id_in = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 17707632241205992228ull);
    vlSelf->lsq_tb__DOT__l1_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7710858775108612369ull);
    vlSelf->lsq_tb__DOT__tlb_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7096948254288228545ull);
    vlSelf->lsq_tb__DOT__sq_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4001947462541226410ull);
    vlSelf->lsq_tb__DOT__valid_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16611504667195135264ull);
    vlSelf->lsq_tb__DOT__issue_vaddr = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 7396565766881785380ull);
    vlSelf->lsq_tb__DOT__issue_wdata = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 14994124651127929792ull);
    vlSelf->lsq_tb__DOT__test_num = 0;
    vlSelf->lsq_tb__DOT__pass_count = 0;
    vlSelf->lsq_tb__DOT__fail_count = 0;
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->lsq_tb__DOT__dut__DOT__lq_state[__Vi0] = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 8691429006165675876ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->lsq_tb__DOT__dut__DOT__lq_vaddr[__Vi0] = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 6778168725397032553ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->lsq_tb__DOT__dut__DOT__lq_id[__Vi0] = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 6510683550212658481ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->lsq_tb__DOT__dut__DOT__lq_before_vec[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8960976347559740143ull);
    }
    vlSelf->lsq_tb__DOT__dut__DOT__lq_head = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 4141515442814584841ull);
    vlSelf->lsq_tb__DOT__dut__DOT__lq_tail = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 14604804607932012006ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->lsq_tb__DOT__dut__DOT__sq_state[__Vi0] = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 7109578368547755764ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->lsq_tb__DOT__dut__DOT__sq_vaddr[__Vi0] = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 3368820453857872237ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->lsq_tb__DOT__dut__DOT__sq_wdata[__Vi0] = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 4046223114849029081ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->lsq_tb__DOT__dut__DOT__sq_id[__Vi0] = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 14747029558070507283ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->lsq_tb__DOT__dut__DOT__sq_before_vec[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10163891541276975374ull);
    }
    vlSelf->lsq_tb__DOT__dut__DOT__sq_head = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 18106902545423008002ull);
    vlSelf->lsq_tb__DOT__dut__DOT__sq_tail = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 2491753917127743978ull);
    vlSelf->lsq_tb__DOT__dut__DOT__lq_found = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12477682029314637098ull);
    vlSelf->lsq_tb__DOT__dut__DOT__lq_found_entry = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 18134688521587498076ull);
    vlSelf->lsq_tb__DOT__dut__DOT__is_unresolved_store = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14007650908815986601ull);
    vlSelf->lsq_tb__DOT__dut__DOT__sq_found = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6912675338695911064ull);
    vlSelf->lsq_tb__DOT__dut__DOT__sq_found_entry = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 5191782653055039329ull);
    vlSelf->lsq_tb__DOT__dut__DOT__is_unresolved_load = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10983709202663854568ull);
    vlSelf->lsq_tb__DOT__dut__DOT__unresolved_val_store = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12769247090420479363ull);
    vlSelf->lsq_tb__DOT__dut__DOT__unnamedblk13__DOT__unnamedblk14__DOT__idx = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 1322109543267768943ull);
    vlSelf->lsq_tb__DOT__dut__DOT__unnamedblk15__DOT__unnamedblk16__DOT__idx = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 10281658051749037829ull);
    vlSelf->lsq_tb__DOT__dut__DOT__unnamedblk17__DOT__unnamedblk18__DOT__idx = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 5722233632047312496ull);
    vlSelf->lsq_tb__DOT__dut__DOT__unnamedblk19__DOT__unnamedblk20__DOT__idx = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 5060504487555104549ull);
    vlSelf->lsq_tb__DOT__dut__DOT__unnamedblk21__DOT__unnamedblk22__DOT__idx = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 10210101579479672600ull);
    vlSelf->lsq_tb__DOT__dut__DOT__unnamedblk23__DOT__unnamedblk24__DOT__idx = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 12471526798143828308ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__lsq_tb__DOT__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__lsq_tb__DOT__rst_n__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
}
