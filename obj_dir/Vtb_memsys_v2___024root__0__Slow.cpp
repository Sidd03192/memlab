// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_memsys_v2.h for the primary calling header

#include "Vtb_memsys_v2__pch.h"

VL_ATTR_COLD void Vtb_memsys_v2___024root___eval_static(Vtb_memsys_v2___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_memsys_v2___024root___eval_static\n"); );
    Vtb_memsys_v2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__tb_memsys_v2__DOT__clk__0 
        = vlSelfRef.tb_memsys_v2__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_memsys_v2__DOT__rst_n__0 
        = vlSelfRef.tb_memsys_v2__DOT__rst_n;
}

VL_ATTR_COLD void Vtb_memsys_v2___024root___eval_initial__TOP(Vtb_memsys_v2___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_memsys_v2___024root___eval_initial__TOP\n"); );
    Vtb_memsys_v2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_memsys_v2__DOT__clk = 0U;
}

VL_ATTR_COLD void Vtb_memsys_v2___024root___eval_final(Vtb_memsys_v2___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_memsys_v2___024root___eval_final\n"); );
    Vtb_memsys_v2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_memsys_v2___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_memsys_v2___024root___eval_phase__stl(Vtb_memsys_v2___024root* vlSelf);

VL_ATTR_COLD void Vtb_memsys_v2___024root___eval_settle(Vtb_memsys_v2___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_memsys_v2___024root___eval_settle\n"); );
    Vtb_memsys_v2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtb_memsys_v2___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("tb_memsys_v2.sv", 22, "", "DIDNOTCONVERGE: Settle region did not converge after 100 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
    } while (Vtb_memsys_v2___024root___eval_phase__stl(vlSelf));
}

VL_ATTR_COLD void Vtb_memsys_v2___024root___eval_triggers__stl(Vtb_memsys_v2___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_memsys_v2___024root___eval_triggers__stl\n"); );
    Vtb_memsys_v2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered
                                      [0U]) | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
    vlSelfRef.__VstlFirstIteration = 0U;
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_memsys_v2___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
}

VL_ATTR_COLD bool Vtb_memsys_v2___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_memsys_v2___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_memsys_v2___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vtb_memsys_v2___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vtb_memsys_v2___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_memsys_v2___024root___trigger_anySet__stl\n"); );
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

extern const VlWide<16>/*511:0*/ Vtb_memsys_v2__ConstPool__CONST_h93e1b771_0;

VL_ATTR_COLD void Vtb_memsys_v2___024root___stl_sequent__TOP__0(Vtb_memsys_v2___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_memsys_v2___024root___stl_sequent__TOP__0\n"); );
    Vtb_memsys_v2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ tb_memsys_v2__DOT__dut__DOT__trace_fire;
    tb_memsys_v2__DOT__dut__DOT__trace_fire = 0;
    CData/*0:0*/ tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__terminate_loop;
    tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__terminate_loop = 0;
    CData/*2:0*/ tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx;
    tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx = 0;
    CData/*2:0*/ tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx;
    tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx = 0;
    CData/*2:0*/ tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx;
    tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx = 0;
    CData/*2:0*/ tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx;
    tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx = 0;
    CData/*2:0*/ tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx;
    tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx = 0;
    CData/*0:0*/ tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__free_found;
    tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__free_found = 0;
    // Body
    vlSelfRef.tb_memsys_v2__DOT__mem_req_is_write = 
        (0U != (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_count));
    vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_full 
        = (4U == (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_count));
    vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_empty 
        = (0U == (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_count));
    vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_full 
        = (2U == (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_count));
    vlSelfRef.tb_memsys_v2__DOT__dut__DOT__l1_l2_wb_paddr 
        = vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_paddr_q
        [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_head];
    vlSelfRef.tb_memsys_v2__DOT__dut__DOT__l1_l2_wb_data[0U] 
        = vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_data_q
        [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_head][0U];
    vlSelfRef.tb_memsys_v2__DOT__dut__DOT__l1_l2_wb_data[1U] 
        = vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_data_q
        [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_head][1U];
    vlSelfRef.tb_memsys_v2__DOT__dut__DOT__l1_l2_wb_data[2U] 
        = vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_data_q
        [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_head][2U];
    vlSelfRef.tb_memsys_v2__DOT__dut__DOT__l1_l2_wb_data[3U] 
        = vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_data_q
        [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_head][3U];
    vlSelfRef.tb_memsys_v2__DOT__dut__DOT__l1_l2_wb_data[4U] 
        = vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_data_q
        [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_head][4U];
    vlSelfRef.tb_memsys_v2__DOT__dut__DOT__l1_l2_wb_data[5U] 
        = vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_data_q
        [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_head][5U];
    vlSelfRef.tb_memsys_v2__DOT__dut__DOT__l1_l2_wb_data[6U] 
        = vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_data_q
        [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_head][6U];
    vlSelfRef.tb_memsys_v2__DOT__dut__DOT__l1_l2_wb_data[7U] 
        = vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_data_q
        [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_head][7U];
    vlSelfRef.tb_memsys_v2__DOT__dut__DOT__l1_l2_wb_data[8U] 
        = vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_data_q
        [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_head][8U];
    vlSelfRef.tb_memsys_v2__DOT__dut__DOT__l1_l2_wb_data[9U] 
        = vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_data_q
        [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_head][9U];
    vlSelfRef.tb_memsys_v2__DOT__dut__DOT__l1_l2_wb_data[0x0000000aU] 
        = vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_data_q
        [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_head][0x0000000aU];
    vlSelfRef.tb_memsys_v2__DOT__dut__DOT__l1_l2_wb_data[0x0000000bU] 
        = vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_data_q
        [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_head][0x0000000bU];
    vlSelfRef.tb_memsys_v2__DOT__dut__DOT__l1_l2_wb_data[0x0000000cU] 
        = vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_data_q
        [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_head][0x0000000cU];
    vlSelfRef.tb_memsys_v2__DOT__dut__DOT__l1_l2_wb_data[0x0000000dU] 
        = vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_data_q
        [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_head][0x0000000dU];
    vlSelfRef.tb_memsys_v2__DOT__dut__DOT__l1_l2_wb_data[0x0000000eU] 
        = vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_data_q
        [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_head][0x0000000eU];
    vlSelfRef.tb_memsys_v2__DOT__dut__DOT__l1_l2_wb_data[0x0000000fU] 
        = vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_data_q
        [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_head][0x0000000fU];
    vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__free_index = 0U;
    tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__free_found = 0U;
    if ((0U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__lrumat
         [0U])) {
        tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__free_found = 1U;
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__free_index = 0U;
    }
    if (((~ (IData)(tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__free_found)) 
         & (0U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__lrumat
            [1U]))) {
        tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__free_found = 1U;
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__free_index = 1U;
    }
    if (((~ (IData)(tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__free_found)) 
         & (0U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__lrumat
            [2U]))) {
        tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__free_found = 1U;
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__free_index = 2U;
    }
    if (((~ (IData)(tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__free_found)) 
         & (0U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__lrumat
            [3U]))) {
        tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__free_found = 1U;
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__free_index = 3U;
    }
    if (((~ (IData)(tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__free_found)) 
         & (0U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__lrumat
            [4U]))) {
        tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__free_found = 1U;
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__free_index = 4U;
    }
    if (((~ (IData)(tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__free_found)) 
         & (0U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__lrumat
            [5U]))) {
        tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__free_found = 1U;
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__free_index = 5U;
    }
    if (((~ (IData)(tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__free_found)) 
         & (0U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__lrumat
            [6U]))) {
        tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__free_found = 1U;
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__free_index = 6U;
    }
    if (((~ (IData)(tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__free_found)) 
         & (0U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__lrumat
            [7U]))) {
        tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__free_found = 1U;
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__free_index = 7U;
    }
    if (((~ (IData)(tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__free_found)) 
         & (0U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__lrumat
            [8U]))) {
        tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__free_found = 1U;
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__free_index = 8U;
    }
    if (((~ (IData)(tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__free_found)) 
         & (0U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__lrumat
            [9U]))) {
        tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__free_found = 1U;
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__free_index = 9U;
    }
    if (((~ (IData)(tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__free_found)) 
         & (0U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__lrumat
            [0x0aU]))) {
        tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__free_found = 1U;
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__free_index = 0x0aU;
    }
    if (((~ (IData)(tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__free_found)) 
         & (0U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__lrumat
            [0x0bU]))) {
        tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__free_found = 1U;
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__free_index = 0x0bU;
    }
    if (((~ (IData)(tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__free_found)) 
         & (0U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__lrumat
            [0x0cU]))) {
        tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__free_found = 1U;
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__free_index = 0x0cU;
    }
    if (((~ (IData)(tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__free_found)) 
         & (0U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__lrumat
            [0x0dU]))) {
        tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__free_found = 1U;
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__free_index = 0x0dU;
    }
    if (((~ (IData)(tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__free_found)) 
         & (0U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__lrumat
            [0x0eU]))) {
        tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__free_found = 1U;
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__free_index = 0x0eU;
    }
    if (((~ (IData)(tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__free_found)) 
         & (0U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__lrumat
            [0x0fU]))) {
        tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__free_found = 1U;
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__free_index = 0x0fU;
    }
    vlSelfRef.tb_memsys_v2__DOT__mem_req_wdata[0U] 
        = Vtb_memsys_v2__ConstPool__CONST_h93e1b771_0[0U];
    vlSelfRef.tb_memsys_v2__DOT__mem_req_wdata[1U] 
        = Vtb_memsys_v2__ConstPool__CONST_h93e1b771_0[1U];
    vlSelfRef.tb_memsys_v2__DOT__mem_req_wdata[2U] 
        = Vtb_memsys_v2__ConstPool__CONST_h93e1b771_0[2U];
    vlSelfRef.tb_memsys_v2__DOT__mem_req_wdata[3U] 
        = Vtb_memsys_v2__ConstPool__CONST_h93e1b771_0[3U];
    vlSelfRef.tb_memsys_v2__DOT__mem_req_wdata[4U] 
        = Vtb_memsys_v2__ConstPool__CONST_h93e1b771_0[4U];
    vlSelfRef.tb_memsys_v2__DOT__mem_req_wdata[5U] 
        = Vtb_memsys_v2__ConstPool__CONST_h93e1b771_0[5U];
    vlSelfRef.tb_memsys_v2__DOT__mem_req_wdata[6U] 
        = Vtb_memsys_v2__ConstPool__CONST_h93e1b771_0[6U];
    vlSelfRef.tb_memsys_v2__DOT__mem_req_wdata[7U] 
        = Vtb_memsys_v2__ConstPool__CONST_h93e1b771_0[7U];
    vlSelfRef.tb_memsys_v2__DOT__mem_req_wdata[8U] 
        = Vtb_memsys_v2__ConstPool__CONST_h93e1b771_0[8U];
    vlSelfRef.tb_memsys_v2__DOT__mem_req_wdata[9U] 
        = Vtb_memsys_v2__ConstPool__CONST_h93e1b771_0[9U];
    vlSelfRef.tb_memsys_v2__DOT__mem_req_wdata[0x0000000aU] 
        = Vtb_memsys_v2__ConstPool__CONST_h93e1b771_0[0x0000000aU];
    vlSelfRef.tb_memsys_v2__DOT__mem_req_wdata[0x0000000bU] 
        = Vtb_memsys_v2__ConstPool__CONST_h93e1b771_0[0x0000000bU];
    vlSelfRef.tb_memsys_v2__DOT__mem_req_wdata[0x0000000cU] 
        = Vtb_memsys_v2__ConstPool__CONST_h93e1b771_0[0x0000000cU];
    vlSelfRef.tb_memsys_v2__DOT__mem_req_wdata[0x0000000dU] 
        = Vtb_memsys_v2__ConstPool__CONST_h93e1b771_0[0x0000000dU];
    vlSelfRef.tb_memsys_v2__DOT__mem_req_wdata[0x0000000eU] 
        = Vtb_memsys_v2__ConstPool__CONST_h93e1b771_0[0x0000000eU];
    vlSelfRef.tb_memsys_v2__DOT__mem_req_wdata[0x0000000fU] 
        = Vtb_memsys_v2__ConstPool__CONST_h93e1b771_0[0x0000000fU];
    if ((0U != (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_count))) {
        vlSelfRef.tb_memsys_v2__DOT__mem_req_wdata[0U] 
            = vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_data_q
            [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_head][0U];
        vlSelfRef.tb_memsys_v2__DOT__mem_req_wdata[1U] 
            = vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_data_q
            [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_head][1U];
        vlSelfRef.tb_memsys_v2__DOT__mem_req_wdata[2U] 
            = vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_data_q
            [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_head][2U];
        vlSelfRef.tb_memsys_v2__DOT__mem_req_wdata[3U] 
            = vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_data_q
            [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_head][3U];
        vlSelfRef.tb_memsys_v2__DOT__mem_req_wdata[4U] 
            = vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_data_q
            [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_head][4U];
        vlSelfRef.tb_memsys_v2__DOT__mem_req_wdata[5U] 
            = vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_data_q
            [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_head][5U];
        vlSelfRef.tb_memsys_v2__DOT__mem_req_wdata[6U] 
            = vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_data_q
            [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_head][6U];
        vlSelfRef.tb_memsys_v2__DOT__mem_req_wdata[7U] 
            = vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_data_q
            [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_head][7U];
        vlSelfRef.tb_memsys_v2__DOT__mem_req_wdata[8U] 
            = vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_data_q
            [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_head][8U];
        vlSelfRef.tb_memsys_v2__DOT__mem_req_wdata[9U] 
            = vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_data_q
            [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_head][9U];
        vlSelfRef.tb_memsys_v2__DOT__mem_req_wdata[0x0000000aU] 
            = vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_data_q
            [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_head][0x0000000aU];
        vlSelfRef.tb_memsys_v2__DOT__mem_req_wdata[0x0000000bU] 
            = vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_data_q
            [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_head][0x0000000bU];
        vlSelfRef.tb_memsys_v2__DOT__mem_req_wdata[0x0000000cU] 
            = vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_data_q
            [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_head][0x0000000cU];
        vlSelfRef.tb_memsys_v2__DOT__mem_req_wdata[0x0000000dU] 
            = vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_data_q
            [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_head][0x0000000dU];
        vlSelfRef.tb_memsys_v2__DOT__mem_req_wdata[0x0000000eU] 
            = vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_data_q
            [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_head][0x0000000eU];
        vlSelfRef.tb_memsys_v2__DOT__mem_req_wdata[0x0000000fU] 
            = vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_data_q
            [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_head][0x0000000fU];
    }
    vlSelfRef.tb_memsys_v2__DOT__dut__DOT__l1_l2_req_valid = 0U;
    vlSelfRef.tb_memsys_v2__DOT__dut__DOT__l1_l2_req_paddr = 0U;
    if ((1U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__mshr_state
         [0U])) {
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__l1_l2_req_valid = 1U;
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__l1_l2_req_paddr 
            = vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__mshr_paddr
            [0U];
    }
    if (((1U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__mshr_state
          [1U]) & (~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__l1_l2_req_valid)))) {
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__l1_l2_req_valid = 1U;
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__l1_l2_req_paddr 
            = vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__mshr_paddr
            [1U];
    }
    vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__hit = 0U;
    if ((vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__set_valids
         [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__curr_index] 
         & (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__tags
            [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__curr_index]
            [0U] == (0x003fffffU & (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__tlb_result_paddr 
                                    >> 8U))))) {
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__hit = 1U;
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__hit_way = 0U;
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__hit_way = 0U;
    } else {
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__hit_way = 0U;
    }
    if (((vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__set_valids
          [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__curr_index] 
          >> 1U) & (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__tags
                    [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__curr_index]
                    [1U] == (0x003fffffU & (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__tlb_result_paddr 
                                            >> 8U))))) {
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__hit = 1U;
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__hit_way = 1U;
    }
    vlSelfRef.tb_memsys_v2__DOT__mem_req_valid = 0U;
    vlSelfRef.tb_memsys_v2__DOT__mem_req_addr = 0U;
    if ((0U == (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_count))) {
        if ((((1U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_state
               [0U]) & (~ vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_mem_issued
                        [0U])) & (~ (IData)(vlSelfRef.tb_memsys_v2__DOT__mem_req_valid)))) {
            vlSelfRef.tb_memsys_v2__DOT__mem_req_valid = 1U;
            vlSelfRef.tb_memsys_v2__DOT__mem_req_addr 
                = vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_paddr
                [0U];
        }
        if ((((1U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_state
               [1U]) & (~ vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_mem_issued
                        [1U])) & (~ (IData)(vlSelfRef.tb_memsys_v2__DOT__mem_req_valid)))) {
            vlSelfRef.tb_memsys_v2__DOT__mem_req_valid = 1U;
            vlSelfRef.tb_memsys_v2__DOT__mem_req_addr 
                = vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_paddr
                [1U];
        }
        if ((((1U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_state
               [2U]) & (~ vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_mem_issued
                        [2U])) & (~ (IData)(vlSelfRef.tb_memsys_v2__DOT__mem_req_valid)))) {
            vlSelfRef.tb_memsys_v2__DOT__mem_req_valid = 1U;
            vlSelfRef.tb_memsys_v2__DOT__mem_req_addr 
                = vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_paddr
                [2U];
        }
        if ((((1U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_state
               [3U]) & (~ vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_mem_issued
                        [3U])) & (~ (IData)(vlSelfRef.tb_memsys_v2__DOT__mem_req_valid)))) {
            vlSelfRef.tb_memsys_v2__DOT__mem_req_valid = 1U;
            vlSelfRef.tb_memsys_v2__DOT__mem_req_addr 
                = vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_paddr
                [3U];
        }
    } else {
        vlSelfRef.tb_memsys_v2__DOT__mem_req_valid = 1U;
        vlSelfRef.tb_memsys_v2__DOT__mem_req_addr = 
            vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_paddr_q
            [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_head];
    }
    vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__mshr_full = 1U;
    vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__mshr_free_idx = 0U;
    if ((0U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__mshr_state
         [0U])) {
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__mshr_full = 0U;
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__mshr_free_idx = 0U;
    }
    if (((0U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__mshr_state
          [1U]) & (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__mshr_full))) {
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__mshr_full = 0U;
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__mshr_free_idx = 1U;
    }
    vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_found = 0U;
    vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_found_entry = 0U;
    tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx 
        = vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_head;
    if ((2U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_state
         [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx])) {
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_found = 1U;
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_found_entry 
            = tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx;
    }
    tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx 
        = (7U & ((IData)(1U) + (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_head)));
    if (((~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_found)) 
         & (2U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_state
            [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx]))) {
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_found = 1U;
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_found_entry 
            = tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx;
    }
    tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx 
        = (7U & ((IData)(2U) + (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_head)));
    if (((~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_found)) 
         & (2U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_state
            [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx]))) {
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_found = 1U;
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_found_entry 
            = tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx;
    }
    tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx 
        = (7U & ((IData)(3U) + (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_head)));
    if (((~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_found)) 
         & (2U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_state
            [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx]))) {
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_found = 1U;
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_found_entry 
            = tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx;
    }
    tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx 
        = (7U & ((IData)(4U) + (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_head)));
    if (((~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_found)) 
         & (2U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_state
            [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx]))) {
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_found = 1U;
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_found_entry 
            = tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx;
    }
    tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx 
        = (7U & ((IData)(5U) + (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_head)));
    if (((~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_found)) 
         & (2U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_state
            [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx]))) {
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_found = 1U;
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_found_entry 
            = tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx;
    }
    tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx 
        = (7U & ((IData)(6U) + (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_head)));
    if (((~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_found)) 
         & (2U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_state
            [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx]))) {
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_found = 1U;
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_found_entry 
            = tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx;
    }
    tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx 
        = (7U & ((IData)(7U) + (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_head)));
    if (((~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_found)) 
         & (2U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_state
            [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx]))) {
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_found = 1U;
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_found_entry 
            = tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk1__DOT__unnamedblk2__DOT__idx;
    }
    vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found = 0U;
    vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found_entry = 0U;
    vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_unresolved = 0U;
    tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx 
        = vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_head;
    if ((4U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_state
         [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx])) {
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found = 1U;
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found_entry 
            = tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx;
    } else if ((((~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_unresolved)) 
                 & (~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found))) 
                & ((2U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_state
                    [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx]) 
                   | (1U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_state
                      [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx])))) {
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_unresolved = 1U;
    }
    tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx 
        = (7U & ((IData)(1U) + (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_head)));
    if ((((~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_unresolved)) 
          & (~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found))) 
         & (4U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_state
            [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx]))) {
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found = 1U;
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found_entry 
            = tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx;
    } else if ((((~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_unresolved)) 
                 & (~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found))) 
                & ((2U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_state
                    [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx]) 
                   | (1U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_state
                      [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx])))) {
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_unresolved = 1U;
    }
    tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx 
        = (7U & ((IData)(2U) + (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_head)));
    if ((((~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_unresolved)) 
          & (~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found))) 
         & (4U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_state
            [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx]))) {
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found = 1U;
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found_entry 
            = tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx;
    } else if ((((~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_unresolved)) 
                 & (~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found))) 
                & ((2U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_state
                    [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx]) 
                   | (1U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_state
                      [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx])))) {
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_unresolved = 1U;
    }
    tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx 
        = (7U & ((IData)(3U) + (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_head)));
    if ((((~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_unresolved)) 
          & (~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found))) 
         & (4U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_state
            [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx]))) {
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found = 1U;
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found_entry 
            = tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx;
    } else if ((((~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_unresolved)) 
                 & (~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found))) 
                & ((2U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_state
                    [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx]) 
                   | (1U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_state
                      [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx])))) {
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_unresolved = 1U;
    }
    tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx 
        = (7U & ((IData)(4U) + (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_head)));
    if ((((~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_unresolved)) 
          & (~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found))) 
         & (4U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_state
            [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx]))) {
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found = 1U;
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found_entry 
            = tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx;
    } else if ((((~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_unresolved)) 
                 & (~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found))) 
                & ((2U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_state
                    [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx]) 
                   | (1U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_state
                      [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx])))) {
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_unresolved = 1U;
    }
    tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx 
        = (7U & ((IData)(5U) + (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_head)));
    if ((((~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_unresolved)) 
          & (~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found))) 
         & (4U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_state
            [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx]))) {
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found = 1U;
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found_entry 
            = tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx;
    } else if ((((~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_unresolved)) 
                 & (~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found))) 
                & ((2U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_state
                    [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx]) 
                   | (1U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_state
                      [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx])))) {
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_unresolved = 1U;
    }
    tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx 
        = (7U & ((IData)(6U) + (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_head)));
    if ((((~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_unresolved)) 
          & (~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found))) 
         & (4U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_state
            [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx]))) {
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found = 1U;
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found_entry 
            = tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx;
    } else if ((((~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_unresolved)) 
                 & (~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found))) 
                & ((2U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_state
                    [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx]) 
                   | (1U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_state
                      [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx])))) {
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_unresolved = 1U;
    }
    tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx 
        = (7U & ((IData)(7U) + (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_head)));
    if ((((~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_unresolved)) 
          & (~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found))) 
         & (4U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_state
            [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx]))) {
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found = 1U;
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found_entry 
            = tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx;
    } else if ((((~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_unresolved)) 
                 & (~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found))) 
                & ((2U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_state
                    [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx]) 
                   | (1U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_state
                      [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk5__DOT__unnamedblk6__DOT__idx])))) {
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_unresolved = 1U;
    }
    vlSelfRef.tb_memsys_v2__DOT__dut__DOT__lsq_sq_ready 
        = (0U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_state
           [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_tail]);
    vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__is_unresolved_store = 0U;
    tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx 
        = vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_head;
    if (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_found) {
        if ((((~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__is_unresolved_store)) 
              & (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_before_vec
                 [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_found_entry] 
                 >> (IData)(tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx))) 
             & (((2U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_state
                  [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx]) 
                 | (1U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_state
                    [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx])) 
                | ((3U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_state
                    [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx]) 
                   & (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_vaddr
                      [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx] 
                      == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_vaddr
                      [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_found_entry]))))) {
            vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__is_unresolved_store = 1U;
        }
    }
    tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx 
        = (7U & ((IData)(1U) + (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_head)));
    if (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_found) {
        if ((((~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__is_unresolved_store)) 
              & (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_before_vec
                 [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_found_entry] 
                 >> (IData)(tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx))) 
             & (((2U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_state
                  [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx]) 
                 | (1U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_state
                    [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx])) 
                | ((3U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_state
                    [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx]) 
                   & (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_vaddr
                      [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx] 
                      == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_vaddr
                      [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_found_entry]))))) {
            vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__is_unresolved_store = 1U;
        }
    }
    tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx 
        = (7U & ((IData)(2U) + (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_head)));
    if (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_found) {
        if ((((~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__is_unresolved_store)) 
              & (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_before_vec
                 [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_found_entry] 
                 >> (IData)(tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx))) 
             & (((2U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_state
                  [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx]) 
                 | (1U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_state
                    [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx])) 
                | ((3U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_state
                    [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx]) 
                   & (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_vaddr
                      [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx] 
                      == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_vaddr
                      [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_found_entry]))))) {
            vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__is_unresolved_store = 1U;
        }
    }
    tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx 
        = (7U & ((IData)(3U) + (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_head)));
    if (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_found) {
        if ((((~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__is_unresolved_store)) 
              & (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_before_vec
                 [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_found_entry] 
                 >> (IData)(tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx))) 
             & (((2U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_state
                  [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx]) 
                 | (1U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_state
                    [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx])) 
                | ((3U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_state
                    [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx]) 
                   & (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_vaddr
                      [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx] 
                      == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_vaddr
                      [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_found_entry]))))) {
            vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__is_unresolved_store = 1U;
        }
    }
    tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx 
        = (7U & ((IData)(4U) + (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_head)));
    if (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_found) {
        if ((((~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__is_unresolved_store)) 
              & (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_before_vec
                 [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_found_entry] 
                 >> (IData)(tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx))) 
             & (((2U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_state
                  [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx]) 
                 | (1U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_state
                    [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx])) 
                | ((3U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_state
                    [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx]) 
                   & (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_vaddr
                      [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx] 
                      == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_vaddr
                      [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_found_entry]))))) {
            vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__is_unresolved_store = 1U;
        }
    }
    tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx 
        = (7U & ((IData)(5U) + (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_head)));
    if (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_found) {
        if ((((~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__is_unresolved_store)) 
              & (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_before_vec
                 [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_found_entry] 
                 >> (IData)(tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx))) 
             & (((2U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_state
                  [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx]) 
                 | (1U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_state
                    [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx])) 
                | ((3U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_state
                    [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx]) 
                   & (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_vaddr
                      [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx] 
                      == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_vaddr
                      [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_found_entry]))))) {
            vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__is_unresolved_store = 1U;
        }
    }
    tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx 
        = (7U & ((IData)(6U) + (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_head)));
    if (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_found) {
        if ((((~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__is_unresolved_store)) 
              & (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_before_vec
                 [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_found_entry] 
                 >> (IData)(tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx))) 
             & (((2U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_state
                  [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx]) 
                 | (1U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_state
                    [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx])) 
                | ((3U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_state
                    [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx]) 
                   & (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_vaddr
                      [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx] 
                      == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_vaddr
                      [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_found_entry]))))) {
            vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__is_unresolved_store = 1U;
        }
    }
    tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx 
        = (7U & ((IData)(7U) + (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_head)));
    if (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_found) {
        if ((((~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__is_unresolved_store)) 
              & (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_before_vec
                 [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_found_entry] 
                 >> (IData)(tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx))) 
             & (((2U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_state
                  [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx]) 
                 | (1U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_state
                    [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx])) 
                | ((3U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_state
                    [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx]) 
                   & (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_vaddr
                      [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk3__DOT__unnamedblk4__DOT__idx] 
                      == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_vaddr
                      [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_found_entry]))))) {
            vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__is_unresolved_store = 1U;
        }
    }
    vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__is_unresolved_load = 0U;
    tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx 
        = vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_head;
    if (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found) {
        if ((((~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__is_unresolved_load)) 
              & (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_before_vec
                 [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found_entry] 
                 >> (IData)(tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx))) 
             & (1U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_state
                [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx]))) {
            vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__is_unresolved_load = 1U;
        }
    }
    tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx 
        = (7U & ((IData)(1U) + (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_head)));
    if (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found) {
        if ((((~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__is_unresolved_load)) 
              & (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_before_vec
                 [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found_entry] 
                 >> (IData)(tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx))) 
             & (1U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_state
                [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx]))) {
            vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__is_unresolved_load = 1U;
        }
    }
    tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx 
        = (7U & ((IData)(2U) + (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_head)));
    if (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found) {
        if ((((~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__is_unresolved_load)) 
              & (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_before_vec
                 [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found_entry] 
                 >> (IData)(tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx))) 
             & (1U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_state
                [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx]))) {
            vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__is_unresolved_load = 1U;
        }
    }
    tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx 
        = (7U & ((IData)(3U) + (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_head)));
    if (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found) {
        if ((((~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__is_unresolved_load)) 
              & (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_before_vec
                 [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found_entry] 
                 >> (IData)(tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx))) 
             & (1U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_state
                [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx]))) {
            vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__is_unresolved_load = 1U;
        }
    }
    tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx 
        = (7U & ((IData)(4U) + (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_head)));
    if (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found) {
        if ((((~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__is_unresolved_load)) 
              & (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_before_vec
                 [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found_entry] 
                 >> (IData)(tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx))) 
             & (1U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_state
                [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx]))) {
            vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__is_unresolved_load = 1U;
        }
    }
    tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx 
        = (7U & ((IData)(5U) + (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_head)));
    if (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found) {
        if ((((~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__is_unresolved_load)) 
              & (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_before_vec
                 [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found_entry] 
                 >> (IData)(tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx))) 
             & (1U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_state
                [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx]))) {
            vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__is_unresolved_load = 1U;
        }
    }
    tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx 
        = (7U & ((IData)(6U) + (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_head)));
    if (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found) {
        if ((((~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__is_unresolved_load)) 
              & (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_before_vec
                 [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found_entry] 
                 >> (IData)(tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx))) 
             & (1U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_state
                [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx]))) {
            vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__is_unresolved_load = 1U;
        }
    }
    tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx 
        = (7U & ((IData)(7U) + (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_head)));
    vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unresolved_val_store = 0U;
    tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__terminate_loop = 0U;
    tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx 
        = vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_head;
    if (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found) {
        if ((((~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__is_unresolved_load)) 
              & (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_before_vec
                 [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found_entry] 
                 >> (IData)(tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx))) 
             & (1U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_state
                [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk7__DOT__unnamedblk8__DOT__idx]))) {
            vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__is_unresolved_load = 1U;
        }
        if (((IData)(tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx) 
             == (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found_entry))) {
            tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__terminate_loop = 1U;
        } else if (((((~ (IData)(tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__terminate_loop)) 
                      & (~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unresolved_val_store))) 
                     & (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_vaddr
                        [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found_entry] 
                        == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_vaddr
                        [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx])) 
                    & (3U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_state
                       [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx]))) {
            vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unresolved_val_store = 1U;
            tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__terminate_loop = 1U;
        }
    }
    tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx 
        = (7U & ((IData)(1U) + (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_head)));
    if (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found) {
        if (((IData)(tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx) 
             == (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found_entry))) {
            tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__terminate_loop = 1U;
        } else if (((((~ (IData)(tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__terminate_loop)) 
                      & (~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unresolved_val_store))) 
                     & (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_vaddr
                        [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found_entry] 
                        == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_vaddr
                        [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx])) 
                    & (3U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_state
                       [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx]))) {
            vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unresolved_val_store = 1U;
            tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__terminate_loop = 1U;
        }
    }
    tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx 
        = (7U & ((IData)(2U) + (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_head)));
    if (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found) {
        if (((IData)(tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx) 
             == (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found_entry))) {
            tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__terminate_loop = 1U;
        } else if (((((~ (IData)(tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__terminate_loop)) 
                      & (~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unresolved_val_store))) 
                     & (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_vaddr
                        [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found_entry] 
                        == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_vaddr
                        [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx])) 
                    & (3U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_state
                       [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx]))) {
            vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unresolved_val_store = 1U;
            tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__terminate_loop = 1U;
        }
    }
    tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx 
        = (7U & ((IData)(3U) + (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_head)));
    if (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found) {
        if (((IData)(tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx) 
             == (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found_entry))) {
            tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__terminate_loop = 1U;
        } else if (((((~ (IData)(tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__terminate_loop)) 
                      & (~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unresolved_val_store))) 
                     & (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_vaddr
                        [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found_entry] 
                        == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_vaddr
                        [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx])) 
                    & (3U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_state
                       [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx]))) {
            vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unresolved_val_store = 1U;
            tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__terminate_loop = 1U;
        }
    }
    tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx 
        = (7U & ((IData)(4U) + (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_head)));
    if (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found) {
        if (((IData)(tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx) 
             == (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found_entry))) {
            tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__terminate_loop = 1U;
        } else if (((((~ (IData)(tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__terminate_loop)) 
                      & (~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unresolved_val_store))) 
                     & (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_vaddr
                        [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found_entry] 
                        == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_vaddr
                        [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx])) 
                    & (3U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_state
                       [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx]))) {
            vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unresolved_val_store = 1U;
            tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__terminate_loop = 1U;
        }
    }
    tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx 
        = (7U & ((IData)(5U) + (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_head)));
    if (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found) {
        if (((IData)(tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx) 
             == (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found_entry))) {
            tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__terminate_loop = 1U;
        } else if (((((~ (IData)(tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__terminate_loop)) 
                      & (~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unresolved_val_store))) 
                     & (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_vaddr
                        [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found_entry] 
                        == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_vaddr
                        [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx])) 
                    & (3U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_state
                       [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx]))) {
            vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unresolved_val_store = 1U;
            tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__terminate_loop = 1U;
        }
    }
    tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx 
        = (7U & ((IData)(6U) + (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_head)));
    if (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found) {
        if (((IData)(tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx) 
             == (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found_entry))) {
            tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__terminate_loop = 1U;
        } else if (((((~ (IData)(tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__terminate_loop)) 
                      & (~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unresolved_val_store))) 
                     & (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_vaddr
                        [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found_entry] 
                        == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_vaddr
                        [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx])) 
                    & (3U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_state
                       [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx]))) {
            vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unresolved_val_store = 1U;
            tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__terminate_loop = 1U;
        }
    }
    tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx 
        = (7U & ((IData)(7U) + (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_head)));
    if (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found) {
        if (((IData)(tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx) 
             == (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found_entry))) {
            tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__terminate_loop = 1U;
        } else if (((((~ (IData)(tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__terminate_loop)) 
                      & (~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unresolved_val_store))) 
                     & (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_vaddr
                        [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found_entry] 
                        == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_vaddr
                        [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx])) 
                    & (3U == vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_state
                       [tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk9__DOT__unnamedblk10__DOT__idx]))) {
            vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unresolved_val_store = 1U;
            tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__terminate_loop = 1U;
        }
    }
    vlSelfRef.tb_memsys_v2__DOT__trace_ready = ((4U 
                                                 == 
                                                 (7U 
                                                  & (vlSelfRef.tb_memsys_v2__DOT__trace_data[1U] 
                                                     >> 0x00000014U)))
                                                 ? (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__tlb_ready)
                                                 : 
                                                ((0U 
                                                  == 
                                                  (7U 
                                                   & (vlSelfRef.tb_memsys_v2__DOT__trace_data[1U] 
                                                      >> 0x00000014U)))
                                                  ? 
                                                 (0U 
                                                  == 
                                                  vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_state
                                                  [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_tail])
                                                  : 
                                                 ((1U 
                                                   == 
                                                   (7U 
                                                    & (vlSelfRef.tb_memsys_v2__DOT__trace_data[1U] 
                                                       >> 0x00000014U)))
                                                   ? (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__lsq_sq_ready)
                                                   : 
                                                  (2U 
                                                   == 
                                                   (7U 
                                                    & (vlSelfRef.tb_memsys_v2__DOT__trace_data[1U] 
                                                       >> 0x00000014U))))));
    tb_memsys_v2__DOT__dut__DOT__trace_fire = ((IData)(vlSelfRef.tb_memsys_v2__DOT__trace_valid) 
                                               & ((4U 
                                                   == 
                                                   (7U 
                                                    & (vlSelfRef.tb_memsys_v2__DOT__trace_data[1U] 
                                                       >> 0x00000014U)))
                                                   ? (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__tlb_ready)
                                                   : 
                                                  ((0U 
                                                    == 
                                                    (7U 
                                                     & (vlSelfRef.tb_memsys_v2__DOT__trace_data[1U] 
                                                        >> 0x00000014U)))
                                                    ? 
                                                   (0U 
                                                    == 
                                                    vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_state
                                                    [vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_tail])
                                                    : 
                                                   ((1U 
                                                     == 
                                                     (7U 
                                                      & (vlSelfRef.tb_memsys_v2__DOT__trace_data[1U] 
                                                         >> 0x00000014U)))
                                                     ? (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__lsq_sq_ready)
                                                     : 
                                                    (2U 
                                                     == 
                                                     (7U 
                                                      & (vlSelfRef.tb_memsys_v2__DOT__trace_data[1U] 
                                                         >> 0x00000014U)))))));
    vlSelfRef.tb_memsys_v2__DOT__dut__DOT__lsq_trace_valid 
        = ((IData)(tb_memsys_v2__DOT__dut__DOT__trace_fire) 
           & ((0U == (7U & (vlSelfRef.tb_memsys_v2__DOT__trace_data[1U] 
                            >> 0x00000014U))) | ((1U 
                                                  == 
                                                  (7U 
                                                   & (vlSelfRef.tb_memsys_v2__DOT__trace_data[1U] 
                                                      >> 0x00000014U))) 
                                                 | (2U 
                                                    == 
                                                    (7U 
                                                     & (vlSelfRef.tb_memsys_v2__DOT__trace_data[1U] 
                                                        >> 0x00000014U))))));
    vlSelfRef.tb_memsys_v2__DOT__dut__DOT__is_tlb_fill_now 
        = ((IData)(tb_memsys_v2__DOT__dut__DOT__trace_fire) 
           & (0x00400000U == (0x00700000U & vlSelfRef.tb_memsys_v2__DOT__trace_data[1U])));
    vlSelfRef.tb_memsys_v2__DOT__dut__DOT__tlb_vaddr_mux 
        = (0x0000ffffffffffffULL & ((IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__is_tlb_fill_now)
                                     ? (((QData)((IData)(
                                                         vlSelfRef.tb_memsys_v2__DOT__trace_data[1U])) 
                                         << 0x00000020U) 
                                        | (QData)((IData)(
                                                          vlSelfRef.tb_memsys_v2__DOT__trace_data[0U])))
                                     : vlSelfRef.tb_memsys_v2__DOT__dut__DOT__issue_buf_vaddr));
    vlSelfRef.tb_memsys_v2__DOT__dut__DOT__launch_issue_now 
        = ((~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__is_tlb_fill_now)) 
           & ((IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__issue_buf_valid) 
              & ((~ ((0U != (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__state)) 
                     | (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__mshr_full))) 
                 & (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__tlb_ready))));
    vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__hit_index = 0U;
    vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__hit_found = 0U;
    if (((IData)((vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__ways
                  [0U] >> 0x36U)) & ((0x0000000fffffffffULL 
                                      & vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__ways
                                      [0U]) == (0x0000000fffffffffULL 
                                                & (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__tlb_vaddr_mux 
                                                   >> 0x0cU))))) {
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__hit_found = 1U;
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__hit_index = 0U;
    }
    if ((((~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__hit_found)) 
          & (IData)((vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__ways
                     [1U] >> 0x36U))) & ((0x0000000fffffffffULL 
                                          & vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__ways
                                          [1U]) == 
                                         (0x0000000fffffffffULL 
                                          & (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__tlb_vaddr_mux 
                                             >> 0x0cU))))) {
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__hit_found = 1U;
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__hit_index = 1U;
    }
    if ((((~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__hit_found)) 
          & (IData)((vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__ways
                     [2U] >> 0x36U))) & ((0x0000000fffffffffULL 
                                          & vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__ways
                                          [2U]) == 
                                         (0x0000000fffffffffULL 
                                          & (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__tlb_vaddr_mux 
                                             >> 0x0cU))))) {
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__hit_found = 1U;
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__hit_index = 2U;
    }
    if ((((~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__hit_found)) 
          & (IData)((vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__ways
                     [3U] >> 0x36U))) & ((0x0000000fffffffffULL 
                                          & vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__ways
                                          [3U]) == 
                                         (0x0000000fffffffffULL 
                                          & (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__tlb_vaddr_mux 
                                             >> 0x0cU))))) {
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__hit_found = 1U;
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__hit_index = 3U;
    }
    if ((((~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__hit_found)) 
          & (IData)((vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__ways
                     [4U] >> 0x36U))) & ((0x0000000fffffffffULL 
                                          & vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__ways
                                          [4U]) == 
                                         (0x0000000fffffffffULL 
                                          & (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__tlb_vaddr_mux 
                                             >> 0x0cU))))) {
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__hit_found = 1U;
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__hit_index = 4U;
    }
    if ((((~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__hit_found)) 
          & (IData)((vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__ways
                     [5U] >> 0x36U))) & ((0x0000000fffffffffULL 
                                          & vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__ways
                                          [5U]) == 
                                         (0x0000000fffffffffULL 
                                          & (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__tlb_vaddr_mux 
                                             >> 0x0cU))))) {
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__hit_found = 1U;
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__hit_index = 5U;
    }
    if ((((~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__hit_found)) 
          & (IData)((vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__ways
                     [6U] >> 0x36U))) & ((0x0000000fffffffffULL 
                                          & vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__ways
                                          [6U]) == 
                                         (0x0000000fffffffffULL 
                                          & (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__tlb_vaddr_mux 
                                             >> 0x0cU))))) {
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__hit_found = 1U;
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__hit_index = 6U;
    }
    if ((((~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__hit_found)) 
          & (IData)((vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__ways
                     [7U] >> 0x36U))) & ((0x0000000fffffffffULL 
                                          & vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__ways
                                          [7U]) == 
                                         (0x0000000fffffffffULL 
                                          & (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__tlb_vaddr_mux 
                                             >> 0x0cU))))) {
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__hit_found = 1U;
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__hit_index = 7U;
    }
    if ((((~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__hit_found)) 
          & (IData)((vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__ways
                     [8U] >> 0x36U))) & ((0x0000000fffffffffULL 
                                          & vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__ways
                                          [8U]) == 
                                         (0x0000000fffffffffULL 
                                          & (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__tlb_vaddr_mux 
                                             >> 0x0cU))))) {
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__hit_found = 1U;
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__hit_index = 8U;
    }
    if ((((~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__hit_found)) 
          & (IData)((vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__ways
                     [9U] >> 0x36U))) & ((0x0000000fffffffffULL 
                                          & vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__ways
                                          [9U]) == 
                                         (0x0000000fffffffffULL 
                                          & (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__tlb_vaddr_mux 
                                             >> 0x0cU))))) {
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__hit_found = 1U;
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__hit_index = 9U;
    }
    if ((((~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__hit_found)) 
          & (IData)((vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__ways
                     [0x0aU] >> 0x36U))) & ((0x0000000fffffffffULL 
                                             & vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__ways
                                             [0x0aU]) 
                                            == (0x0000000fffffffffULL 
                                                & (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__tlb_vaddr_mux 
                                                   >> 0x0cU))))) {
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__hit_found = 1U;
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__hit_index = 0x0aU;
    }
    if ((((~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__hit_found)) 
          & (IData)((vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__ways
                     [0x0bU] >> 0x36U))) & ((0x0000000fffffffffULL 
                                             & vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__ways
                                             [0x0bU]) 
                                            == (0x0000000fffffffffULL 
                                                & (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__tlb_vaddr_mux 
                                                   >> 0x0cU))))) {
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__hit_found = 1U;
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__hit_index = 0x0bU;
    }
    if ((((~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__hit_found)) 
          & (IData)((vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__ways
                     [0x0cU] >> 0x36U))) & ((0x0000000fffffffffULL 
                                             & vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__ways
                                             [0x0cU]) 
                                            == (0x0000000fffffffffULL 
                                                & (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__tlb_vaddr_mux 
                                                   >> 0x0cU))))) {
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__hit_found = 1U;
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__hit_index = 0x0cU;
    }
    if ((((~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__hit_found)) 
          & (IData)((vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__ways
                     [0x0dU] >> 0x36U))) & ((0x0000000fffffffffULL 
                                             & vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__ways
                                             [0x0dU]) 
                                            == (0x0000000fffffffffULL 
                                                & (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__tlb_vaddr_mux 
                                                   >> 0x0cU))))) {
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__hit_found = 1U;
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__hit_index = 0x0dU;
    }
    if ((((~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__hit_found)) 
          & (IData)((vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__ways
                     [0x0eU] >> 0x36U))) & ((0x0000000fffffffffULL 
                                             & vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__ways
                                             [0x0eU]) 
                                            == (0x0000000fffffffffULL 
                                                & (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__tlb_vaddr_mux 
                                                   >> 0x0cU))))) {
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__hit_found = 1U;
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__hit_index = 0x0eU;
    }
    if ((((~ (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__hit_found)) 
          & (IData)((vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__ways
                     [0x0fU] >> 0x36U))) & ((0x0000000fffffffffULL 
                                             & vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__ways
                                             [0x0fU]) 
                                            == (0x0000000fffffffffULL 
                                                & (vlSelfRef.tb_memsys_v2__DOT__dut__DOT__tlb_vaddr_mux 
                                                   >> 0x0cU))))) {
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__hit_found = 1U;
        vlSelfRef.tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__hit_index = 0x0fU;
    }
    vlSelfRef.tb_memsys_v2__DOT__dut__DOT__tlb_start 
        = ((IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__is_tlb_fill_now) 
           | (IData)(vlSelfRef.tb_memsys_v2__DOT__dut__DOT__launch_issue_now));
}

VL_ATTR_COLD void Vtb_memsys_v2___024root___eval_stl(Vtb_memsys_v2___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_memsys_v2___024root___eval_stl\n"); );
    Vtb_memsys_v2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vtb_memsys_v2___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD bool Vtb_memsys_v2___024root___eval_phase__stl(Vtb_memsys_v2___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_memsys_v2___024root___eval_phase__stl\n"); );
    Vtb_memsys_v2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtb_memsys_v2___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = Vtb_memsys_v2___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        Vtb_memsys_v2___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool Vtb_memsys_v2___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_memsys_v2___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_memsys_v2___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vtb_memsys_v2___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge tb_memsys_v2.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(negedge tb_memsys_v2.rst_n)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @(negedge tb_memsys_v2.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((1U & (IData)((triggers[0U] >> 4U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 4 is active: @([true] __VdynSched.evaluate())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_memsys_v2___024root___ctor_var_reset(Vtb_memsys_v2___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_memsys_v2___024root___ctor_var_reset\n"); );
    Vtb_memsys_v2__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->tb_memsys_v2__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14147868331576767217ull);
    vlSelf->tb_memsys_v2__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15740636944920300581ull);
    VL_SCOPED_RAND_RESET_W(121, vlSelf->tb_memsys_v2__DOT__trace_data, __VscopeHash, 16398237527042120781ull);
    vlSelf->tb_memsys_v2__DOT__trace_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1046637516314564525ull);
    vlSelf->tb_memsys_v2__DOT__trace_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4500398536378883015ull);
    vlSelf->tb_memsys_v2__DOT__mem_req_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 421588167676879526ull);
    vlSelf->tb_memsys_v2__DOT__mem_req_is_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 244765700845216440ull);
    vlSelf->tb_memsys_v2__DOT__mem_req_addr = VL_SCOPED_RAND_RESET_I(30, __VscopeHash, 1142679466887142948ull);
    VL_SCOPED_RAND_RESET_W(512, vlSelf->tb_memsys_v2__DOT__mem_req_wdata, __VscopeHash, 7434768917439597276ull);
    vlSelf->tb_memsys_v2__DOT__mem_req_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3940483447184379936ull);
    vlSelf->tb_memsys_v2__DOT__mem_resp_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12905138043383034562ull);
    vlSelf->tb_memsys_v2__DOT__mem_resp_paddr = VL_SCOPED_RAND_RESET_I(30, __VscopeHash, 15703801935812018457ull);
    VL_SCOPED_RAND_RESET_W(512, vlSelf->tb_memsys_v2__DOT__mem_resp_rdata, __VscopeHash, 14342723083624035262ull);
    vlSelf->tb_memsys_v2__DOT__cycle_ctr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 11013971512001381468ull);
    vlSelf->tb_memsys_v2__DOT__checker_error_cnt = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 17813518204079582744ull);
    vlSelf->tb_memsys_v2__DOT__records_seen = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4629150246680693466ull);
    vlSelf->tb_memsys_v2__DOT__records_sent = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 7655851481595671906ull);
    vlSelf->tb_memsys_v2__DOT__timeout_cycles = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 14608194893051971999ull);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tb_memsys_v2__DOT__trace_buffer[__Vi0] = 0;
    }
    vlSelf->tb_memsys_v2__DOT__stopped_by_limit = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6054756676873371203ull);
    vlSelf->tb_memsys_v2__DOT__reached_eof = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5469552733413943258ull);
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_memsys_v2__DOT__shadow_op[__Vi0] = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 4283105410633175453ull);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_memsys_v2__DOT__shadow_vaddr[__Vi0] = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 9055325877708072143ull);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_memsys_v2__DOT__shadow_vaddr_valid[__Vi0] = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11192903192536333746ull);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_memsys_v2__DOT__shadow_value[__Vi0] = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 2646979411823087124ull);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_memsys_v2__DOT__shadow_value_valid[__Vi0] = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5827161337552461330ull);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_memsys_v2__DOT__shadow_id[__Vi0] = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 12413999505245810149ull);
    }
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        vlSelf->tb_memsys_v2__DOT__shadow_access_idx[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12315740267988392596ull);
    }
    for (int __Vi0 = 0; __Vi0 < 2048; ++__Vi0) {
        vlSelf->tb_memsys_v2__DOT__tlb_map_valid[__Vi0] = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2410923958070477460ull);
    }
    for (int __Vi0 = 0; __Vi0 < 2048; ++__Vi0) {
        vlSelf->tb_memsys_v2__DOT__tlb_map_vpn[__Vi0] = VL_SCOPED_RAND_RESET_Q(36, __VscopeHash, 2822379924051356207ull);
    }
    for (int __Vi0 = 0; __Vi0 < 2048; ++__Vi0) {
        vlSelf->tb_memsys_v2__DOT__tlb_map_ptag[__Vi0] = VL_SCOPED_RAND_RESET_I(18, __VscopeHash, 3602613358867696858ull);
    }
    for (int __Vi0 = 0; __Vi0 < 32768; ++__Vi0) {
        vlSelf->tb_memsys_v2__DOT__expected_valid[__Vi0] = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14412746569333403801ull);
    }
    for (int __Vi0 = 0; __Vi0 < 32768; ++__Vi0) {
        vlSelf->tb_memsys_v2__DOT__expected_paddr[__Vi0] = VL_SCOPED_RAND_RESET_I(30, __VscopeHash, 17095401999158024352ull);
    }
    for (int __Vi0 = 0; __Vi0 < 32768; ++__Vi0) {
        vlSelf->tb_memsys_v2__DOT__expected_vaddr[__Vi0] = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 2442518259657580800ull);
    }
    for (int __Vi0 = 0; __Vi0 < 32768; ++__Vi0) {
        vlSelf->tb_memsys_v2__DOT__expected_value[__Vi0] = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 4757164371654267269ull);
    }
    for (int __Vi0 = 0; __Vi0 < 32768; ++__Vi0) {
        vlSelf->tb_memsys_v2__DOT__expected_last_access[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 1725893698813488632ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8192; ++__Vi0) {
        vlSelf->tb_memsys_v2__DOT__line_valid[__Vi0] = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18060163039999657219ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8192; ++__Vi0) {
        vlSelf->tb_memsys_v2__DOT__line_addr[__Vi0] = VL_SCOPED_RAND_RESET_I(30, __VscopeHash, 18363111454883154291ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8192; ++__Vi0) {
        VL_SCOPED_RAND_RESET_W(512, vlSelf->tb_memsys_v2__DOT__line_data[__Vi0], __VscopeHash, 11595028250683338240ull);
    }
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->tb_memsys_v2__DOT__pending_valid[__Vi0] = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13500088113561021398ull);
    }
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->tb_memsys_v2__DOT__pending_addr[__Vi0] = VL_SCOPED_RAND_RESET_I(30, __VscopeHash, 2932815045608403845ull);
    }
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->tb_memsys_v2__DOT__pending_count[__Vi0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 15355880379173730880ull);
    }
    vlSelf->tb_memsys_v2__DOT__backing_memory__DOT__free_idx = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9173541413450480399ull);
    VL_SCOPED_RAND_RESET_W(512, vlSelf->tb_memsys_v2__DOT__backing_memory__DOT__read_line, __VscopeHash, 4154898390692307587ull);
    VL_SCOPED_RAND_RESET_W(121, vlSelf->tb_memsys_v2__DOT__drive_trace__DOT__packet, __VscopeHash, 12222622961107217612ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__lsq_trace_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3810403596302411763ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__tlb_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11818009814236443295ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__tlb_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13679329332712214121ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__tlb_result_paddr = VL_SCOPED_RAND_RESET_I(30, __VscopeHash, 7191401794890323527ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__is_tlb_fill_now = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9073292466975651558ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__lsq_vaddr_to_l1 = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 3692109359885038169ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__lsq_valid_to_l1 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15560595964458453195ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__lsq_wdata_to_l1 = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 849317740387411256ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__lsq_issue_op = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 16241823857480524086ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__lsq_sq_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 701744646434881309ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__issue_buf_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4937538806749346761ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__issue_buf_vaddr = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 4113504973756248459ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__issue_buf_wdata = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 6175757875268922529ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__issue_buf_op = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 1815669470043332597ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__launch_issue_now = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6349322135105560182ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__tlb_start = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13244825193898998571ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__tlb_vaddr_mux = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 9591732159079742647ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__l1_l2_wb_paddr = VL_SCOPED_RAND_RESET_I(30, __VscopeHash, 14261625921525845044ull);
    VL_SCOPED_RAND_RESET_W(512, vlSelf->tb_memsys_v2__DOT__dut__DOT__l1_l2_wb_data, __VscopeHash, 2779851412379473905ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__l2_l1_wb_ack = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12953806878326660778ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__l1_l2_req_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18068684510999615432ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__l1_l2_req_paddr = VL_SCOPED_RAND_RESET_I(30, __VscopeHash, 9501792107743819183ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__l2_l1_data_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14220485289907645489ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__l2_l1_data_paddr = VL_SCOPED_RAND_RESET_I(30, __VscopeHash, 4420126943472905245ull);
    VL_SCOPED_RAND_RESET_W(512, vlSelf->tb_memsys_v2__DOT__dut__DOT__l2_l1_data, __VscopeHash, 7552173318815512186ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_state[__Vi0] = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 15075366719704433696ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_vaddr[__Vi0] = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 12284707869517967842ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_id[__Vi0] = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 1032465567330285185ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_before_vec[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 4062174416228864494ull);
    }
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_head = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 10558837853184299957ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_tail = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 8810513821940189270ull);
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_state[__Vi0] = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 13758761443440071540ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_vaddr[__Vi0] = VL_SCOPED_RAND_RESET_Q(48, __VscopeHash, 14718194408579135104ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_wdata[__Vi0] = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 1387378936899816153ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_id[__Vi0] = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 15539571957995514907ull);
    }
    for (int __Vi0 = 0; __Vi0 < 8; ++__Vi0) {
        vlSelf->tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_before_vec[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 8321144955817826325ull);
    }
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_head = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 23976927208265072ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_tail = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 4065108163388579776ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_found = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 8704879629836999326ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_found_entry = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 5507834486913720713ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__is_unresolved_store = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5178845096671388646ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11704370851803363396ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found_entry = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 17258373400005213197ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_unresolved = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5956845503823087222ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__is_unresolved_load = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9359372563513735630ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unresolved_val_store = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16451624685583895879ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk13__DOT__unnamedblk14__DOT__idx = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 16870310683898955303ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk15__DOT__unnamedblk16__DOT__idx = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 3129676855891338447ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk17__DOT__resolve_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3748947053522842512ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk17__DOT__unnamedblk18__DOT__unnamedblk19__DOT__idx = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 11295974510857864337ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk20__DOT__resolve_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4368470042810525941ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk20__DOT__unnamedblk21__DOT__unnamedblk22__DOT__idx = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 13571512171853683605ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk23__DOT__unnamedblk24__DOT__idx = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 10953536679058401343ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk25__DOT__unnamedblk26__DOT__idx = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 14416117291355235991ull);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__ways[__Vi0] = VL_SCOPED_RAND_RESET_Q(55, __VscopeHash, 469178723568739083ull);
    }
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__lrumat[__Vi0] = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 16220991620552711702ull);
    }
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__hit_index = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 18442820083003397315ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__free_index = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 4540158476072268491ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__hit_found = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14863168934947081192ull);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 2; ++__Vi1) {
            VL_SCOPED_RAND_RESET_W(512, vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__set_contents[__Vi0][__Vi1], __VscopeHash, 2324192001514535551ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 2; ++__Vi1) {
            vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__tags[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(22, __VscopeHash, 5518558548086823323ull);
        }
    }
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__lru = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 16616469777332131010ull);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__set_valids[__Vi0] = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 760476011271182841ull);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__set_dirty[__Vi0] = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 1291672022390938913ull);
    }
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__state = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 18406586682795714863ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__curr_index = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 5694172124076403045ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__curr_is_write = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7239191362560545897ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__curr_wdata = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 14983176808367528901ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__curr_word_offset = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 6849035062401783084ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__mshr_dup = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10199442582760428351ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__mshr_dup_idx = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1697983964526181017ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__evict_way_l = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16669496957482639898ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__mshr_install_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7079018082577813346ull);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__mshr_state[__Vi0] = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 11158726273397221461ull);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__mshr_paddr[__Vi0] = VL_SCOPED_RAND_RESET_I(30, __VscopeHash, 12716164417669660715ull);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__mshr_index[__Vi0] = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 787781847204224467ull);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        VL_SCOPED_RAND_RESET_W(512, vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__mshr_block[__Vi0], __VscopeHash, 13645925213737143991ull);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__mshr_store_mask[__Vi0] = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 1513059711529415609ull);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        VL_SCOPED_RAND_RESET_W(512, vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__mshr_store_data[__Vi0], __VscopeHash, 4183037570534130041ull);
    }
    VL_SCOPED_RAND_RESET_W(512, vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__install_block, __VscopeHash, 18204253309626488240ull);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_paddr_q[__Vi0] = VL_SCOPED_RAND_RESET_I(30, __VscopeHash, 3792507243054062653ull);
    }
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        VL_SCOPED_RAND_RESET_W(512, vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_data_q[__Vi0], __VscopeHash, 11858072253020845860ull);
    }
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_head = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18235319639075252056ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_tail = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4264877637953383854ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_count = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 2429554188207094797ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_push = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9809096308775206587ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_push_paddr = VL_SCOPED_RAND_RESET_I(30, __VscopeHash, 3155614098304419559ull);
    VL_SCOPED_RAND_RESET_W(512, vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_push_data, __VscopeHash, 8151638684141219157ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_pop = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1165374611565721396ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_empty = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11570051959839190122ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_full = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14078299946983274061ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__victim_dirty = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11914053574013359754ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__victim_paddr = VL_SCOPED_RAND_RESET_I(30, __VscopeHash, 6028458447563041717ull);
    VL_SCOPED_RAND_RESET_W(512, vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__victim_data, __VscopeHash, 9474370121096280940ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__mshr_full = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15730355112723158051ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__mshr_free_idx = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4567537469057473249ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__hit = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10343261415472154337ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__hit_way = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4731550318623495973ull);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 4; ++__Vi1) {
            VL_SCOPED_RAND_RESET_W(512, vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__set_contents[__Vi0][__Vi1], __VscopeHash, 2984285488969101047ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 4; ++__Vi1) {
            vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__tags[__Vi0][__Vi1] = VL_SCOPED_RAND_RESET_I(20, __VscopeHash, 6135806078752432177ull);
        }
    }
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__set_valids[__Vi0] = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 7935349386916487321ull);
    }
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__set_dirty[__Vi0] = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 7448595154828820956ull);
    }
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        for (int __Vi1 = 0; __Vi1 < 4; ++__Vi1) {
            for (int __Vi2 = 0; __Vi2 < 4; ++__Vi2) {
                vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__lru_matrix[__Vi0][__Vi1][__Vi2] = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7107873154528022749ull);
            }
        }
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_state[__Vi0] = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 11386757233213588032ull);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_paddr[__Vi0] = VL_SCOPED_RAND_RESET_I(30, __VscopeHash, 5777289820664835523ull);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        VL_SCOPED_RAND_RESET_W(512, vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_block[__Vi0], __VscopeHash, 10372087331293957738ull);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_mem_issued[__Vi0] = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15417244923555526748ull);
    }
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_issued_one = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6634408151473340059ull);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_paddr_q[__Vi0] = VL_SCOPED_RAND_RESET_I(30, __VscopeHash, 14830487014212495370ull);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        VL_SCOPED_RAND_RESET_W(512, vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_data_q[__Vi0], __VscopeHash, 9972194988452512141ull);
    }
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_head = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 14616362602336349834ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_tail = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 5995473609136953138ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_count = VL_SCOPED_RAND_RESET_I(3, __VscopeHash, 2824703211620176316ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_push = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16915808746434143354ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_push_paddr = VL_SCOPED_RAND_RESET_I(30, __VscopeHash, 5533803514596481395ull);
    VL_SCOPED_RAND_RESET_W(512, vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_push_data, __VscopeHash, 4619206947108167346ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_pop = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12119817060266205113ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_full = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11375049888337675090ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__req_hit = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17406345432519759637ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__req_hit_way = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 17326542617687975503ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_dup = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2404873485388321817ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_full_l2 = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5524719624637108381ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_free_idx = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 2779156228464260546ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_hit = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6299434784765080573ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_hit_way = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 5708168432614506361ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_victim_way = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 17553045108598153178ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_found_invalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12093729550532602745ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_victim_dirty = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18043704107094846057ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_is_lru = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5288419528925640848ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_install_done = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10941307721314199320ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_inst_index = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 14237317485329129695ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_inst_tag = VL_SCOPED_RAND_RESET_I(20, __VscopeHash, 3017439411795827214ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_inst_victim = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 8701657198156968502ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_inst_found_invalid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16142267768184422758ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_inst_victim_dirty = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3098456126558117801ull);
    vlSelf->tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_inst_is_lru = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6999125939540318681ull);
    vlSelf->__Vdly__tb_memsys_v2__DOT__cycle_ctr = 0;
    vlSelf->__Vdly__tb_memsys_v2__DOT__dut__DOT__lsq_valid_to_l1 = 0;
    vlSelf->__Vdly__tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_tail = 0;
    vlSelf->__Vdly__tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__state = 0;
    vlSelf->__Vdly__tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_count = 0;
    vlSelf->__Vdly__tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_count = 0;
    vlSelf->__VdlySet__tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_vaddr__v0 = 0;
    vlSelf->__VdlyVal__tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_state__v0 = 0;
    vlSelf->__VdlyDim0__tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_state__v0 = 0;
    vlSelf->__VdlySet__tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_vaddr__v1 = 0;
    vlSelf->__VdlyDim0__tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_state__v1 = 0;
    vlSelf->__VdlySet__tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_vaddr__v2 = 0;
    vlSelf->__VdlyDim0__tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_state__v2 = 0;
    vlSelf->__VdlySet__tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_vaddr__v3 = 0;
    vlSelf->__VdlyDim0__tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_state__v3 = 0;
    vlSelf->__VdlySet__tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_vaddr__v4 = 0;
    vlSelf->__VdlyDim0__tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_state__v4 = 0;
    vlSelf->__VdlySet__tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_vaddr__v5 = 0;
    vlSelf->__VdlyDim0__tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_state__v5 = 0;
    vlSelf->__VdlySet__tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_vaddr__v6 = 0;
    vlSelf->__VdlyDim0__tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_state__v6 = 0;
    vlSelf->__VdlySet__tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_vaddr__v7 = 0;
    vlSelf->__VdlyDim0__tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_state__v7 = 0;
    vlSelf->__VdlySet__tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_vaddr__v8 = 0;
    vlSelf->__VdlyDim0__tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_state__v8 = 0;
    vlSelf->__VdlyDim0__tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_state__v9 = 0;
    vlSelf->__VdlySet__tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_state__v9 = 0;
    vlSelf->__VdlySet__tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_state__v10 = 0;
    vlSelf->__VdlySet__tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__mshr_state__v0 = 0;
    vlSelf->__VdlySet__tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__mshr_state__v1 = 0;
    vlSelf->__VdlySet__tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__mshr_paddr__v0 = 0;
    vlSelf->__VdlyDim0__tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__mshr_state__v2 = 0;
    vlSelf->__VdlySet__tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__mshr_block__v0 = 0;
    vlSelf->__VdlySet__tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__mshr_block__v1 = 0;
    vlSelf->__VdlySet__tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__mshr_state__v5 = 0;
    vlSelf->__VdlySet__tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_block__v0 = 0;
    vlSelf->__VdlySet__tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_block__v1 = 0;
    vlSelf->__VdlySet__tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_block__v2 = 0;
    vlSelf->__VdlySet__tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_block__v3 = 0;
    vlSelf->__VdlySet__tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_state__v4 = 0;
    vlSelf->__VdlySet__tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_state__v5 = 0;
    vlSelf->__VdlySet__tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_state__v6 = 0;
    vlSelf->__VdlySet__tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_state__v7 = 0;
    vlSelf->__VdlyDim0__tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_state__v8 = 0;
    vlSelf->__VdlySet__tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_state__v8 = 0;
    vlSelf->__VdlySet__tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_state__v9 = 0;
    vlSelf->__VdlySet__tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_state__v10 = 0;
    vlSelf->__VdlySet__tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_state__v11 = 0;
    vlSelf->__VdlySet__tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_state__v12 = 0;
    vlSelf->__VdlySet__tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__set_valids__v5 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__tb_memsys_v2__DOT__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tb_memsys_v2__DOT__rst_n__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
}
