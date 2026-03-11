// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vlsq.h for the primary calling header

#include "Vlsq__pch.h"

VL_ATTR_COLD void Vlsq___024root___eval_static(Vlsq___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlsq___024root___eval_static\n"); );
    Vlsq__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst_n__0 = vlSelfRef.rst_n;
}

VL_ATTR_COLD void Vlsq___024root___eval_initial(Vlsq___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlsq___024root___eval_initial\n"); );
    Vlsq__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
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
            VL_FATAL_MT("lsq.sv", 22, "", "DIDNOTCONVERGE: Settle region did not converge after 100 tries");
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
    CData/*0:0*/ lsq__DOT__sq_unresolved;
    lsq__DOT__sq_unresolved = 0;
    CData/*0:0*/ lsq__DOT__terminate_loop;
    lsq__DOT__terminate_loop = 0;
    CData/*2:0*/ lsq__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx;
    lsq__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx = 0;
    CData/*2:0*/ lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx;
    lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx = 0;
    CData/*2:0*/ lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx;
    lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx = 0;
    CData/*2:0*/ lsq__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx;
    lsq__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx = 0;
    CData/*2:0*/ lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx;
    lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx = 0;
    // Body
    vlSelfRef.lq_ready = (((IData)(vlSelfRef.lsq__DOT__lq_tail) 
                           != (IData)(vlSelfRef.lsq__DOT__lq_head)) 
                          | (0U == vlSelfRef.lsq__DOT__lq_state
                             [vlSelfRef.lsq__DOT__lq_head]));
    vlSelfRef.sq_ready = (((IData)(vlSelfRef.lsq__DOT__sq_tail) 
                           != (IData)(vlSelfRef.lsq__DOT__sq_head)) 
                          | (0U == vlSelfRef.lsq__DOT__sq_state
                             [vlSelfRef.lsq__DOT__sq_head]));
    vlSelfRef.lsq__DOT__lq_found = 0U;
    vlSelfRef.lsq__DOT__lq_found_entry = 0U;
    lsq__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx 
        = vlSelfRef.lsq__DOT__lq_head;
    if ((2U == vlSelfRef.lsq__DOT__lq_state[lsq__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx])) {
        vlSelfRef.lsq__DOT__lq_found = 1U;
        vlSelfRef.lsq__DOT__lq_found_entry = lsq__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx;
    }
    lsq__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx 
        = (7U & ((IData)(1U) + (IData)(vlSelfRef.lsq__DOT__lq_head)));
    if (((~ (IData)(vlSelfRef.lsq__DOT__lq_found)) 
         & (2U == vlSelfRef.lsq__DOT__lq_state[lsq__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx]))) {
        vlSelfRef.lsq__DOT__lq_found = 1U;
        vlSelfRef.lsq__DOT__lq_found_entry = lsq__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx;
    }
    lsq__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx 
        = (7U & ((IData)(2U) + (IData)(vlSelfRef.lsq__DOT__lq_head)));
    if (((~ (IData)(vlSelfRef.lsq__DOT__lq_found)) 
         & (2U == vlSelfRef.lsq__DOT__lq_state[lsq__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx]))) {
        vlSelfRef.lsq__DOT__lq_found = 1U;
        vlSelfRef.lsq__DOT__lq_found_entry = lsq__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx;
    }
    lsq__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx 
        = (7U & ((IData)(3U) + (IData)(vlSelfRef.lsq__DOT__lq_head)));
    if (((~ (IData)(vlSelfRef.lsq__DOT__lq_found)) 
         & (2U == vlSelfRef.lsq__DOT__lq_state[lsq__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx]))) {
        vlSelfRef.lsq__DOT__lq_found = 1U;
        vlSelfRef.lsq__DOT__lq_found_entry = lsq__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx;
    }
    lsq__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx 
        = (7U & ((IData)(4U) + (IData)(vlSelfRef.lsq__DOT__lq_head)));
    if (((~ (IData)(vlSelfRef.lsq__DOT__lq_found)) 
         & (2U == vlSelfRef.lsq__DOT__lq_state[lsq__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx]))) {
        vlSelfRef.lsq__DOT__lq_found = 1U;
        vlSelfRef.lsq__DOT__lq_found_entry = lsq__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx;
    }
    lsq__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx 
        = (7U & ((IData)(5U) + (IData)(vlSelfRef.lsq__DOT__lq_head)));
    if (((~ (IData)(vlSelfRef.lsq__DOT__lq_found)) 
         & (2U == vlSelfRef.lsq__DOT__lq_state[lsq__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx]))) {
        vlSelfRef.lsq__DOT__lq_found = 1U;
        vlSelfRef.lsq__DOT__lq_found_entry = lsq__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx;
    }
    lsq__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx 
        = (7U & ((IData)(6U) + (IData)(vlSelfRef.lsq__DOT__lq_head)));
    if (((~ (IData)(vlSelfRef.lsq__DOT__lq_found)) 
         & (2U == vlSelfRef.lsq__DOT__lq_state[lsq__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx]))) {
        vlSelfRef.lsq__DOT__lq_found = 1U;
        vlSelfRef.lsq__DOT__lq_found_entry = lsq__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx;
    }
    lsq__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx 
        = (7U & ((IData)(7U) + (IData)(vlSelfRef.lsq__DOT__lq_head)));
    if (((~ (IData)(vlSelfRef.lsq__DOT__lq_found)) 
         & (2U == vlSelfRef.lsq__DOT__lq_state[lsq__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx]))) {
        vlSelfRef.lsq__DOT__lq_found = 1U;
        vlSelfRef.lsq__DOT__lq_found_entry = lsq__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx;
    }
    vlSelfRef.lsq__DOT__sq_found = 0U;
    vlSelfRef.lsq__DOT__sq_found_entry = 0U;
    lsq__DOT__sq_unresolved = 0U;
    lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx 
        = vlSelfRef.lsq__DOT__sq_head;
    if ((4U == vlSelfRef.lsq__DOT__sq_state[lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx])) {
        vlSelfRef.lsq__DOT__sq_found = 1U;
        vlSelfRef.lsq__DOT__sq_found_entry = lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx;
    } else if ((((~ (IData)(lsq__DOT__sq_unresolved)) 
                 & (~ (IData)(vlSelfRef.lsq__DOT__sq_found))) 
                & ((2U == vlSelfRef.lsq__DOT__sq_state
                    [lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx]) 
                   | (1U == vlSelfRef.lsq__DOT__sq_state
                      [lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx])))) {
        lsq__DOT__sq_unresolved = 1U;
    }
    lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx 
        = (7U & ((IData)(1U) + (IData)(vlSelfRef.lsq__DOT__sq_head)));
    if ((((~ (IData)(lsq__DOT__sq_unresolved)) & (~ (IData)(vlSelfRef.lsq__DOT__sq_found))) 
         & (4U == vlSelfRef.lsq__DOT__sq_state[lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx]))) {
        vlSelfRef.lsq__DOT__sq_found = 1U;
        vlSelfRef.lsq__DOT__sq_found_entry = lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx;
    } else if ((((~ (IData)(lsq__DOT__sq_unresolved)) 
                 & (~ (IData)(vlSelfRef.lsq__DOT__sq_found))) 
                & ((2U == vlSelfRef.lsq__DOT__sq_state
                    [lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx]) 
                   | (1U == vlSelfRef.lsq__DOT__sq_state
                      [lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx])))) {
        lsq__DOT__sq_unresolved = 1U;
    }
    lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx 
        = (7U & ((IData)(2U) + (IData)(vlSelfRef.lsq__DOT__sq_head)));
    if ((((~ (IData)(lsq__DOT__sq_unresolved)) & (~ (IData)(vlSelfRef.lsq__DOT__sq_found))) 
         & (4U == vlSelfRef.lsq__DOT__sq_state[lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx]))) {
        vlSelfRef.lsq__DOT__sq_found = 1U;
        vlSelfRef.lsq__DOT__sq_found_entry = lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx;
    } else if ((((~ (IData)(lsq__DOT__sq_unresolved)) 
                 & (~ (IData)(vlSelfRef.lsq__DOT__sq_found))) 
                & ((2U == vlSelfRef.lsq__DOT__sq_state
                    [lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx]) 
                   | (1U == vlSelfRef.lsq__DOT__sq_state
                      [lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx])))) {
        lsq__DOT__sq_unresolved = 1U;
    }
    lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx 
        = (7U & ((IData)(3U) + (IData)(vlSelfRef.lsq__DOT__sq_head)));
    if ((((~ (IData)(lsq__DOT__sq_unresolved)) & (~ (IData)(vlSelfRef.lsq__DOT__sq_found))) 
         & (4U == vlSelfRef.lsq__DOT__sq_state[lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx]))) {
        vlSelfRef.lsq__DOT__sq_found = 1U;
        vlSelfRef.lsq__DOT__sq_found_entry = lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx;
    } else if ((((~ (IData)(lsq__DOT__sq_unresolved)) 
                 & (~ (IData)(vlSelfRef.lsq__DOT__sq_found))) 
                & ((2U == vlSelfRef.lsq__DOT__sq_state
                    [lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx]) 
                   | (1U == vlSelfRef.lsq__DOT__sq_state
                      [lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx])))) {
        lsq__DOT__sq_unresolved = 1U;
    }
    lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx 
        = (7U & ((IData)(4U) + (IData)(vlSelfRef.lsq__DOT__sq_head)));
    if ((((~ (IData)(lsq__DOT__sq_unresolved)) & (~ (IData)(vlSelfRef.lsq__DOT__sq_found))) 
         & (4U == vlSelfRef.lsq__DOT__sq_state[lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx]))) {
        vlSelfRef.lsq__DOT__sq_found = 1U;
        vlSelfRef.lsq__DOT__sq_found_entry = lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx;
    } else if ((((~ (IData)(lsq__DOT__sq_unresolved)) 
                 & (~ (IData)(vlSelfRef.lsq__DOT__sq_found))) 
                & ((2U == vlSelfRef.lsq__DOT__sq_state
                    [lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx]) 
                   | (1U == vlSelfRef.lsq__DOT__sq_state
                      [lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx])))) {
        lsq__DOT__sq_unresolved = 1U;
    }
    lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx 
        = (7U & ((IData)(5U) + (IData)(vlSelfRef.lsq__DOT__sq_head)));
    if ((((~ (IData)(lsq__DOT__sq_unresolved)) & (~ (IData)(vlSelfRef.lsq__DOT__sq_found))) 
         & (4U == vlSelfRef.lsq__DOT__sq_state[lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx]))) {
        vlSelfRef.lsq__DOT__sq_found = 1U;
        vlSelfRef.lsq__DOT__sq_found_entry = lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx;
    } else if ((((~ (IData)(lsq__DOT__sq_unresolved)) 
                 & (~ (IData)(vlSelfRef.lsq__DOT__sq_found))) 
                & ((2U == vlSelfRef.lsq__DOT__sq_state
                    [lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx]) 
                   | (1U == vlSelfRef.lsq__DOT__sq_state
                      [lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx])))) {
        lsq__DOT__sq_unresolved = 1U;
    }
    lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx 
        = (7U & ((IData)(6U) + (IData)(vlSelfRef.lsq__DOT__sq_head)));
    if ((((~ (IData)(lsq__DOT__sq_unresolved)) & (~ (IData)(vlSelfRef.lsq__DOT__sq_found))) 
         & (4U == vlSelfRef.lsq__DOT__sq_state[lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx]))) {
        vlSelfRef.lsq__DOT__sq_found = 1U;
        vlSelfRef.lsq__DOT__sq_found_entry = lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx;
    } else if ((((~ (IData)(lsq__DOT__sq_unresolved)) 
                 & (~ (IData)(vlSelfRef.lsq__DOT__sq_found))) 
                & ((2U == vlSelfRef.lsq__DOT__sq_state
                    [lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx]) 
                   | (1U == vlSelfRef.lsq__DOT__sq_state
                      [lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx])))) {
        lsq__DOT__sq_unresolved = 1U;
    }
    lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx 
        = (7U & ((IData)(7U) + (IData)(vlSelfRef.lsq__DOT__sq_head)));
    if ((((~ (IData)(lsq__DOT__sq_unresolved)) & (~ (IData)(vlSelfRef.lsq__DOT__sq_found))) 
         & (4U == vlSelfRef.lsq__DOT__sq_state[lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx]))) {
        vlSelfRef.lsq__DOT__sq_found = 1U;
        vlSelfRef.lsq__DOT__sq_found_entry = lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx;
    } else if ((((~ (IData)(lsq__DOT__sq_unresolved)) 
                 & (~ (IData)(vlSelfRef.lsq__DOT__sq_found))) 
                & ((2U == vlSelfRef.lsq__DOT__sq_state
                    [lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx]) 
                   | (1U == vlSelfRef.lsq__DOT__sq_state
                      [lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx])))) {
        lsq__DOT__sq_unresolved = 1U;
    }
    vlSelfRef.lsq__DOT__is_unresolved_store = 0U;
    lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx 
        = vlSelfRef.lsq__DOT__sq_head;
    if (vlSelfRef.lsq__DOT__lq_found) {
        if ((((~ (IData)(vlSelfRef.lsq__DOT__is_unresolved_store)) 
              & (vlSelfRef.lsq__DOT__lq_before_vec[vlSelfRef.lsq__DOT__lq_found_entry] 
                 >> (IData)(lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx))) 
             & (((2U == vlSelfRef.lsq__DOT__sq_state
                  [lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx]) 
                 | (1U == vlSelfRef.lsq__DOT__sq_state
                    [lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx])) 
                | ((3U == vlSelfRef.lsq__DOT__sq_state
                    [lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx]) 
                   & (vlSelfRef.lsq__DOT__sq_vaddr[lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx] 
                      == vlSelfRef.lsq__DOT__lq_vaddr
                      [vlSelfRef.lsq__DOT__lq_found_entry]))))) {
            vlSelfRef.lsq__DOT__is_unresolved_store = 1U;
        }
    }
    lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx 
        = (7U & ((IData)(1U) + (IData)(vlSelfRef.lsq__DOT__sq_head)));
    if (vlSelfRef.lsq__DOT__lq_found) {
        if ((((~ (IData)(vlSelfRef.lsq__DOT__is_unresolved_store)) 
              & (vlSelfRef.lsq__DOT__lq_before_vec[vlSelfRef.lsq__DOT__lq_found_entry] 
                 >> (IData)(lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx))) 
             & (((2U == vlSelfRef.lsq__DOT__sq_state
                  [lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx]) 
                 | (1U == vlSelfRef.lsq__DOT__sq_state
                    [lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx])) 
                | ((3U == vlSelfRef.lsq__DOT__sq_state
                    [lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx]) 
                   & (vlSelfRef.lsq__DOT__sq_vaddr[lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx] 
                      == vlSelfRef.lsq__DOT__lq_vaddr
                      [vlSelfRef.lsq__DOT__lq_found_entry]))))) {
            vlSelfRef.lsq__DOT__is_unresolved_store = 1U;
        }
    }
    lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx 
        = (7U & ((IData)(2U) + (IData)(vlSelfRef.lsq__DOT__sq_head)));
    if (vlSelfRef.lsq__DOT__lq_found) {
        if ((((~ (IData)(vlSelfRef.lsq__DOT__is_unresolved_store)) 
              & (vlSelfRef.lsq__DOT__lq_before_vec[vlSelfRef.lsq__DOT__lq_found_entry] 
                 >> (IData)(lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx))) 
             & (((2U == vlSelfRef.lsq__DOT__sq_state
                  [lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx]) 
                 | (1U == vlSelfRef.lsq__DOT__sq_state
                    [lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx])) 
                | ((3U == vlSelfRef.lsq__DOT__sq_state
                    [lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx]) 
                   & (vlSelfRef.lsq__DOT__sq_vaddr[lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx] 
                      == vlSelfRef.lsq__DOT__lq_vaddr
                      [vlSelfRef.lsq__DOT__lq_found_entry]))))) {
            vlSelfRef.lsq__DOT__is_unresolved_store = 1U;
        }
    }
    lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx 
        = (7U & ((IData)(3U) + (IData)(vlSelfRef.lsq__DOT__sq_head)));
    if (vlSelfRef.lsq__DOT__lq_found) {
        if ((((~ (IData)(vlSelfRef.lsq__DOT__is_unresolved_store)) 
              & (vlSelfRef.lsq__DOT__lq_before_vec[vlSelfRef.lsq__DOT__lq_found_entry] 
                 >> (IData)(lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx))) 
             & (((2U == vlSelfRef.lsq__DOT__sq_state
                  [lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx]) 
                 | (1U == vlSelfRef.lsq__DOT__sq_state
                    [lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx])) 
                | ((3U == vlSelfRef.lsq__DOT__sq_state
                    [lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx]) 
                   & (vlSelfRef.lsq__DOT__sq_vaddr[lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx] 
                      == vlSelfRef.lsq__DOT__lq_vaddr
                      [vlSelfRef.lsq__DOT__lq_found_entry]))))) {
            vlSelfRef.lsq__DOT__is_unresolved_store = 1U;
        }
    }
    lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx 
        = (7U & ((IData)(4U) + (IData)(vlSelfRef.lsq__DOT__sq_head)));
    if (vlSelfRef.lsq__DOT__lq_found) {
        if ((((~ (IData)(vlSelfRef.lsq__DOT__is_unresolved_store)) 
              & (vlSelfRef.lsq__DOT__lq_before_vec[vlSelfRef.lsq__DOT__lq_found_entry] 
                 >> (IData)(lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx))) 
             & (((2U == vlSelfRef.lsq__DOT__sq_state
                  [lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx]) 
                 | (1U == vlSelfRef.lsq__DOT__sq_state
                    [lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx])) 
                | ((3U == vlSelfRef.lsq__DOT__sq_state
                    [lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx]) 
                   & (vlSelfRef.lsq__DOT__sq_vaddr[lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx] 
                      == vlSelfRef.lsq__DOT__lq_vaddr
                      [vlSelfRef.lsq__DOT__lq_found_entry]))))) {
            vlSelfRef.lsq__DOT__is_unresolved_store = 1U;
        }
    }
    lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx 
        = (7U & ((IData)(5U) + (IData)(vlSelfRef.lsq__DOT__sq_head)));
    if (vlSelfRef.lsq__DOT__lq_found) {
        if ((((~ (IData)(vlSelfRef.lsq__DOT__is_unresolved_store)) 
              & (vlSelfRef.lsq__DOT__lq_before_vec[vlSelfRef.lsq__DOT__lq_found_entry] 
                 >> (IData)(lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx))) 
             & (((2U == vlSelfRef.lsq__DOT__sq_state
                  [lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx]) 
                 | (1U == vlSelfRef.lsq__DOT__sq_state
                    [lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx])) 
                | ((3U == vlSelfRef.lsq__DOT__sq_state
                    [lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx]) 
                   & (vlSelfRef.lsq__DOT__sq_vaddr[lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx] 
                      == vlSelfRef.lsq__DOT__lq_vaddr
                      [vlSelfRef.lsq__DOT__lq_found_entry]))))) {
            vlSelfRef.lsq__DOT__is_unresolved_store = 1U;
        }
    }
    lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx 
        = (7U & ((IData)(6U) + (IData)(vlSelfRef.lsq__DOT__sq_head)));
    if (vlSelfRef.lsq__DOT__lq_found) {
        if ((((~ (IData)(vlSelfRef.lsq__DOT__is_unresolved_store)) 
              & (vlSelfRef.lsq__DOT__lq_before_vec[vlSelfRef.lsq__DOT__lq_found_entry] 
                 >> (IData)(lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx))) 
             & (((2U == vlSelfRef.lsq__DOT__sq_state
                  [lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx]) 
                 | (1U == vlSelfRef.lsq__DOT__sq_state
                    [lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx])) 
                | ((3U == vlSelfRef.lsq__DOT__sq_state
                    [lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx]) 
                   & (vlSelfRef.lsq__DOT__sq_vaddr[lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx] 
                      == vlSelfRef.lsq__DOT__lq_vaddr
                      [vlSelfRef.lsq__DOT__lq_found_entry]))))) {
            vlSelfRef.lsq__DOT__is_unresolved_store = 1U;
        }
    }
    lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx 
        = (7U & ((IData)(7U) + (IData)(vlSelfRef.lsq__DOT__sq_head)));
    if (vlSelfRef.lsq__DOT__lq_found) {
        if ((((~ (IData)(vlSelfRef.lsq__DOT__is_unresolved_store)) 
              & (vlSelfRef.lsq__DOT__lq_before_vec[vlSelfRef.lsq__DOT__lq_found_entry] 
                 >> (IData)(lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx))) 
             & (((2U == vlSelfRef.lsq__DOT__sq_state
                  [lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx]) 
                 | (1U == vlSelfRef.lsq__DOT__sq_state
                    [lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx])) 
                | ((3U == vlSelfRef.lsq__DOT__sq_state
                    [lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx]) 
                   & (vlSelfRef.lsq__DOT__sq_vaddr[lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx] 
                      == vlSelfRef.lsq__DOT__lq_vaddr
                      [vlSelfRef.lsq__DOT__lq_found_entry]))))) {
            vlSelfRef.lsq__DOT__is_unresolved_store = 1U;
        }
    }
    vlSelfRef.lsq__DOT__is_unresolved_load = 0U;
    lsq__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx 
        = vlSelfRef.lsq__DOT__lq_head;
    if (vlSelfRef.lsq__DOT__sq_found) {
        if ((((~ (IData)(vlSelfRef.lsq__DOT__is_unresolved_load)) 
              & (vlSelfRef.lsq__DOT__sq_before_vec[vlSelfRef.lsq__DOT__sq_found_entry] 
                 >> (IData)(lsq__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx))) 
             & (1U == vlSelfRef.lsq__DOT__lq_state[lsq__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx]))) {
            vlSelfRef.lsq__DOT__is_unresolved_load = 1U;
        }
    }
    lsq__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx 
        = (7U & ((IData)(1U) + (IData)(vlSelfRef.lsq__DOT__lq_head)));
    if (vlSelfRef.lsq__DOT__sq_found) {
        if ((((~ (IData)(vlSelfRef.lsq__DOT__is_unresolved_load)) 
              & (vlSelfRef.lsq__DOT__sq_before_vec[vlSelfRef.lsq__DOT__sq_found_entry] 
                 >> (IData)(lsq__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx))) 
             & (1U == vlSelfRef.lsq__DOT__lq_state[lsq__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx]))) {
            vlSelfRef.lsq__DOT__is_unresolved_load = 1U;
        }
    }
    lsq__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx 
        = (7U & ((IData)(2U) + (IData)(vlSelfRef.lsq__DOT__lq_head)));
    if (vlSelfRef.lsq__DOT__sq_found) {
        if ((((~ (IData)(vlSelfRef.lsq__DOT__is_unresolved_load)) 
              & (vlSelfRef.lsq__DOT__sq_before_vec[vlSelfRef.lsq__DOT__sq_found_entry] 
                 >> (IData)(lsq__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx))) 
             & (1U == vlSelfRef.lsq__DOT__lq_state[lsq__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx]))) {
            vlSelfRef.lsq__DOT__is_unresolved_load = 1U;
        }
    }
    lsq__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx 
        = (7U & ((IData)(3U) + (IData)(vlSelfRef.lsq__DOT__lq_head)));
    if (vlSelfRef.lsq__DOT__sq_found) {
        if ((((~ (IData)(vlSelfRef.lsq__DOT__is_unresolved_load)) 
              & (vlSelfRef.lsq__DOT__sq_before_vec[vlSelfRef.lsq__DOT__sq_found_entry] 
                 >> (IData)(lsq__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx))) 
             & (1U == vlSelfRef.lsq__DOT__lq_state[lsq__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx]))) {
            vlSelfRef.lsq__DOT__is_unresolved_load = 1U;
        }
    }
    lsq__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx 
        = (7U & ((IData)(4U) + (IData)(vlSelfRef.lsq__DOT__lq_head)));
    if (vlSelfRef.lsq__DOT__sq_found) {
        if ((((~ (IData)(vlSelfRef.lsq__DOT__is_unresolved_load)) 
              & (vlSelfRef.lsq__DOT__sq_before_vec[vlSelfRef.lsq__DOT__sq_found_entry] 
                 >> (IData)(lsq__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx))) 
             & (1U == vlSelfRef.lsq__DOT__lq_state[lsq__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx]))) {
            vlSelfRef.lsq__DOT__is_unresolved_load = 1U;
        }
    }
    lsq__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx 
        = (7U & ((IData)(5U) + (IData)(vlSelfRef.lsq__DOT__lq_head)));
    if (vlSelfRef.lsq__DOT__sq_found) {
        if ((((~ (IData)(vlSelfRef.lsq__DOT__is_unresolved_load)) 
              & (vlSelfRef.lsq__DOT__sq_before_vec[vlSelfRef.lsq__DOT__sq_found_entry] 
                 >> (IData)(lsq__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx))) 
             & (1U == vlSelfRef.lsq__DOT__lq_state[lsq__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx]))) {
            vlSelfRef.lsq__DOT__is_unresolved_load = 1U;
        }
    }
    lsq__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx 
        = (7U & ((IData)(6U) + (IData)(vlSelfRef.lsq__DOT__lq_head)));
    if (vlSelfRef.lsq__DOT__sq_found) {
        if ((((~ (IData)(vlSelfRef.lsq__DOT__is_unresolved_load)) 
              & (vlSelfRef.lsq__DOT__sq_before_vec[vlSelfRef.lsq__DOT__sq_found_entry] 
                 >> (IData)(lsq__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx))) 
             & (1U == vlSelfRef.lsq__DOT__lq_state[lsq__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx]))) {
            vlSelfRef.lsq__DOT__is_unresolved_load = 1U;
        }
    }
    lsq__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx 
        = (7U & ((IData)(7U) + (IData)(vlSelfRef.lsq__DOT__lq_head)));
    vlSelfRef.lsq__DOT__unresolved_val_store = 0U;
    lsq__DOT__terminate_loop = 0U;
    lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx 
        = vlSelfRef.lsq__DOT__sq_head;
    if (vlSelfRef.lsq__DOT__sq_found) {
        if ((((~ (IData)(vlSelfRef.lsq__DOT__is_unresolved_load)) 
              & (vlSelfRef.lsq__DOT__sq_before_vec[vlSelfRef.lsq__DOT__sq_found_entry] 
                 >> (IData)(lsq__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx))) 
             & (1U == vlSelfRef.lsq__DOT__lq_state[lsq__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx]))) {
            vlSelfRef.lsq__DOT__is_unresolved_load = 1U;
        }
        if (((IData)(lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx) 
             == (IData)(vlSelfRef.lsq__DOT__sq_found_entry))) {
            lsq__DOT__terminate_loop = 1U;
        } else if (((((~ (IData)(lsq__DOT__terminate_loop)) 
                      & (~ (IData)(vlSelfRef.lsq__DOT__unresolved_val_store))) 
                     & (vlSelfRef.lsq__DOT__sq_vaddr
                        [vlSelfRef.lsq__DOT__sq_found_entry] 
                        == vlSelfRef.lsq__DOT__sq_vaddr
                        [lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx])) 
                    & (3U == vlSelfRef.lsq__DOT__sq_state
                       [lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx]))) {
            vlSelfRef.lsq__DOT__unresolved_val_store = 1U;
            lsq__DOT__terminate_loop = 1U;
        }
    }
    lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx 
        = (7U & ((IData)(1U) + (IData)(vlSelfRef.lsq__DOT__sq_head)));
    if (vlSelfRef.lsq__DOT__sq_found) {
        if (((IData)(lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx) 
             == (IData)(vlSelfRef.lsq__DOT__sq_found_entry))) {
            lsq__DOT__terminate_loop = 1U;
        } else if (((((~ (IData)(lsq__DOT__terminate_loop)) 
                      & (~ (IData)(vlSelfRef.lsq__DOT__unresolved_val_store))) 
                     & (vlSelfRef.lsq__DOT__sq_vaddr
                        [vlSelfRef.lsq__DOT__sq_found_entry] 
                        == vlSelfRef.lsq__DOT__sq_vaddr
                        [lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx])) 
                    & (3U == vlSelfRef.lsq__DOT__sq_state
                       [lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx]))) {
            vlSelfRef.lsq__DOT__unresolved_val_store = 1U;
            lsq__DOT__terminate_loop = 1U;
        }
    }
    lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx 
        = (7U & ((IData)(2U) + (IData)(vlSelfRef.lsq__DOT__sq_head)));
    if (vlSelfRef.lsq__DOT__sq_found) {
        if (((IData)(lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx) 
             == (IData)(vlSelfRef.lsq__DOT__sq_found_entry))) {
            lsq__DOT__terminate_loop = 1U;
        } else if (((((~ (IData)(lsq__DOT__terminate_loop)) 
                      & (~ (IData)(vlSelfRef.lsq__DOT__unresolved_val_store))) 
                     & (vlSelfRef.lsq__DOT__sq_vaddr
                        [vlSelfRef.lsq__DOT__sq_found_entry] 
                        == vlSelfRef.lsq__DOT__sq_vaddr
                        [lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx])) 
                    & (3U == vlSelfRef.lsq__DOT__sq_state
                       [lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx]))) {
            vlSelfRef.lsq__DOT__unresolved_val_store = 1U;
            lsq__DOT__terminate_loop = 1U;
        }
    }
    lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx 
        = (7U & ((IData)(3U) + (IData)(vlSelfRef.lsq__DOT__sq_head)));
    if (vlSelfRef.lsq__DOT__sq_found) {
        if (((IData)(lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx) 
             == (IData)(vlSelfRef.lsq__DOT__sq_found_entry))) {
            lsq__DOT__terminate_loop = 1U;
        } else if (((((~ (IData)(lsq__DOT__terminate_loop)) 
                      & (~ (IData)(vlSelfRef.lsq__DOT__unresolved_val_store))) 
                     & (vlSelfRef.lsq__DOT__sq_vaddr
                        [vlSelfRef.lsq__DOT__sq_found_entry] 
                        == vlSelfRef.lsq__DOT__sq_vaddr
                        [lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx])) 
                    & (3U == vlSelfRef.lsq__DOT__sq_state
                       [lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx]))) {
            vlSelfRef.lsq__DOT__unresolved_val_store = 1U;
            lsq__DOT__terminate_loop = 1U;
        }
    }
    lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx 
        = (7U & ((IData)(4U) + (IData)(vlSelfRef.lsq__DOT__sq_head)));
    if (vlSelfRef.lsq__DOT__sq_found) {
        if (((IData)(lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx) 
             == (IData)(vlSelfRef.lsq__DOT__sq_found_entry))) {
            lsq__DOT__terminate_loop = 1U;
        } else if (((((~ (IData)(lsq__DOT__terminate_loop)) 
                      & (~ (IData)(vlSelfRef.lsq__DOT__unresolved_val_store))) 
                     & (vlSelfRef.lsq__DOT__sq_vaddr
                        [vlSelfRef.lsq__DOT__sq_found_entry] 
                        == vlSelfRef.lsq__DOT__sq_vaddr
                        [lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx])) 
                    & (3U == vlSelfRef.lsq__DOT__sq_state
                       [lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx]))) {
            vlSelfRef.lsq__DOT__unresolved_val_store = 1U;
            lsq__DOT__terminate_loop = 1U;
        }
    }
    lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx 
        = (7U & ((IData)(5U) + (IData)(vlSelfRef.lsq__DOT__sq_head)));
    if (vlSelfRef.lsq__DOT__sq_found) {
        if (((IData)(lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx) 
             == (IData)(vlSelfRef.lsq__DOT__sq_found_entry))) {
            lsq__DOT__terminate_loop = 1U;
        } else if (((((~ (IData)(lsq__DOT__terminate_loop)) 
                      & (~ (IData)(vlSelfRef.lsq__DOT__unresolved_val_store))) 
                     & (vlSelfRef.lsq__DOT__sq_vaddr
                        [vlSelfRef.lsq__DOT__sq_found_entry] 
                        == vlSelfRef.lsq__DOT__sq_vaddr
                        [lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx])) 
                    & (3U == vlSelfRef.lsq__DOT__sq_state
                       [lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx]))) {
            vlSelfRef.lsq__DOT__unresolved_val_store = 1U;
            lsq__DOT__terminate_loop = 1U;
        }
    }
    lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx 
        = (7U & ((IData)(6U) + (IData)(vlSelfRef.lsq__DOT__sq_head)));
    if (vlSelfRef.lsq__DOT__sq_found) {
        if (((IData)(lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx) 
             == (IData)(vlSelfRef.lsq__DOT__sq_found_entry))) {
            lsq__DOT__terminate_loop = 1U;
        } else if (((((~ (IData)(lsq__DOT__terminate_loop)) 
                      & (~ (IData)(vlSelfRef.lsq__DOT__unresolved_val_store))) 
                     & (vlSelfRef.lsq__DOT__sq_vaddr
                        [vlSelfRef.lsq__DOT__sq_found_entry] 
                        == vlSelfRef.lsq__DOT__sq_vaddr
                        [lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx])) 
                    & (3U == vlSelfRef.lsq__DOT__sq_state
                       [lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx]))) {
            vlSelfRef.lsq__DOT__unresolved_val_store = 1U;
            lsq__DOT__terminate_loop = 1U;
        }
    }
    lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx 
        = (7U & ((IData)(7U) + (IData)(vlSelfRef.lsq__DOT__sq_head)));
    if (vlSelfRef.lsq__DOT__sq_found) {
        if (((IData)(lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx) 
             == (IData)(vlSelfRef.lsq__DOT__sq_found_entry))) {
            lsq__DOT__terminate_loop = 1U;
        } else if (((((~ (IData)(lsq__DOT__terminate_loop)) 
                      & (~ (IData)(vlSelfRef.lsq__DOT__unresolved_val_store))) 
                     & (vlSelfRef.lsq__DOT__sq_vaddr
                        [vlSelfRef.lsq__DOT__sq_found_entry] 
                        == vlSelfRef.lsq__DOT__sq_vaddr
                        [lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx])) 
                    & (3U == vlSelfRef.lsq__DOT__sq_state
                       [lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx]))) {
            vlSelfRef.lsq__DOT__unresolved_val_store = 1U;
            lsq__DOT__terminate_loop = 1U;
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
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(negedge rst_n)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vlsq___024root___ctor_var_reset(Vlsq___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlsq___024root___ctor_var_reset\n"); );
    Vlsq__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1638864771569018232ull);
    vlSelf->op = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 3630531923276091163ull);
    vlSelf->valid_in = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16540271516330450727ull);
    vlSelf->vaddr_in = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 11135254703117732702ull);
    vlSelf->wdata_in = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 6914393786649069530ull);
    vlSelf->vaddr_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6914601844602299360ull);
    vlSelf->wdata_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12503666757050263776ull);
    vlSelf->id_in = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 2417037724108067409ull);
    vlSelf->l1_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13396175474316397434ull);
    vlSelf->tlb_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4527109571053711915ull);
    vlSelf->lq_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9288204715925989942ull);
    vlSelf->sq_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16402828452367894437ull);
    vlSelf->valid_out = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8744939437868816662ull);
    vlSelf->issue_vaddr = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 9044225386562614035ull);
    vlSelf->issue_wdata = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 6804679727207633242ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->lsq__DOT__lq_state[__Vi0] = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 13879143644445463096ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->lsq__DOT__lq_vaddr[__Vi0] = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 16688647613817212251ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->lsq__DOT__lq_id[__Vi0] = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 10573786136723332024ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->lsq__DOT__lq_before_vec[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 392262652306823658ull);
    }
    vlSelf->lsq__DOT__lq_head = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 3754037881869170874ull);
    vlSelf->lsq__DOT__lq_tail = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 2816988255501957540ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->lsq__DOT__sq_state[__Vi0] = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 5853877336139496154ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->lsq__DOT__sq_vaddr[__Vi0] = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 2655296202057099467ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->lsq__DOT__sq_wdata[__Vi0] = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 4054397585916761534ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->lsq__DOT__sq_id[__Vi0] = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 1818436865997585505ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->lsq__DOT__sq_before_vec[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14011505383866955599ull);
    }
    vlSelf->lsq__DOT__sq_head = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 16592195800565064587ull);
    vlSelf->lsq__DOT__sq_tail = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 12930696016395152299ull);
    vlSelf->lsq__DOT__lq_found = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7275286089055725108ull);
    vlSelf->lsq__DOT__lq_found_entry = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 16021462374318573661ull);
    vlSelf->lsq__DOT__is_unresolved_store = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3729517810806634302ull);
    vlSelf->lsq__DOT__sq_found = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10953843476859651548ull);
    vlSelf->lsq__DOT__sq_found_entry = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 14902802026161650038ull);
    vlSelf->lsq__DOT__is_unresolved_load = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14455347261135489899ull);
    vlSelf->lsq__DOT__unresolved_val_store = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 597044270973914934ull);
    vlSelf->lsq__DOT__unnamedblk13__DOT__unnamedblk14__DOT__idx = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 17385669509051276101ull);
    vlSelf->lsq__DOT__unnamedblk15__DOT__unnamedblk16__DOT__idx = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 3374385997419257570ull);
    vlSelf->lsq__DOT__unnamedblk17__DOT__unnamedblk18__DOT__idx = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 13954208571715772169ull);
    vlSelf->lsq__DOT__unnamedblk19__DOT__unnamedblk20__DOT__idx = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 1592109139111053006ull);
    vlSelf->lsq__DOT__unnamedblk21__DOT__unnamedblk22__DOT__idx = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 263235328934583990ull);
    vlSelf->lsq__DOT__unnamedblk23__DOT__unnamedblk24__DOT__idx = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 441757732329312672ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__rst_n__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
}
