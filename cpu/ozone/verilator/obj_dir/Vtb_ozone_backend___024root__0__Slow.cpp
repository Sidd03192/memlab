// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_ozone_backend.h for the primary calling header

#include "Vtb_ozone_backend__pch.h"

void Vtb_ozone_backend___024root___timing_ready(Vtb_ozone_backend___024root* vlSelf);

VL_ATTR_COLD void Vtb_ozone_backend___024root___eval_static(Vtb_ozone_backend___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ozone_backend___024root___eval_static\n"); );
    Vtb_ozone_backend__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*2:0*/ __Vinline__eval_static__TOP_tb_ozone_backend__DOT__cdb__DOT__unnamedblk1__DOT__winner;
    __Vinline__eval_static__TOP_tb_ozone_backend__DOT__cdb__DOT__unnamedblk1__DOT__winner = 0;
    CData/*5:0*/ __Vinline__eval_static__TOP_tb_ozone_backend__DOT__cdb__DOT__unnamedblk1__DOT__best_age;
    __Vinline__eval_static__TOP_tb_ozone_backend__DOT__cdb__DOT__unnamedblk1__DOT__best_age = 0;
    // Body
    __Vinline__eval_static__TOP_tb_ozone_backend__DOT__cdb__DOT__unnamedblk1__DOT__winner = 0;
    __Vinline__eval_static__TOP_tb_ozone_backend__DOT__cdb__DOT__unnamedblk1__DOT__best_age = 0;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_ozone_backend__DOT__clk__0 
        = vlSelfRef.tb_ozone_backend__DOT__clk;
    vlSelfRef.__Vtrigprevexpr___TOP__tb_ozone_backend__DOT__rst_n__0 
        = vlSelfRef.tb_ozone_backend__DOT__rst_n;
    Vtb_ozone_backend___024root___timing_ready(vlSelf);
    do {
        vlSelfRef.__VactTriggeredAcc[vlSelfRef.__Vi] 
            = vlSelfRef.__VactTriggered[vlSelfRef.__Vi];
        vlSelfRef.__Vi = ((IData)(1U) + vlSelfRef.__Vi);
    } while ((0U >= vlSelfRef.__Vi));
}

VL_ATTR_COLD void Vtb_ozone_backend___024root___eval_static__TOP(Vtb_ozone_backend___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ozone_backend___024root___eval_static__TOP\n"); );
    Vtb_ozone_backend__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*2:0*/ tb_ozone_backend__DOT__cdb__DOT__unnamedblk1__DOT__winner;
    tb_ozone_backend__DOT__cdb__DOT__unnamedblk1__DOT__winner = 0;
    CData/*5:0*/ tb_ozone_backend__DOT__cdb__DOT__unnamedblk1__DOT__best_age;
    tb_ozone_backend__DOT__cdb__DOT__unnamedblk1__DOT__best_age = 0;
    // Body
    tb_ozone_backend__DOT__cdb__DOT__unnamedblk1__DOT__winner = 0;
    tb_ozone_backend__DOT__cdb__DOT__unnamedblk1__DOT__best_age = 0;
}

VL_ATTR_COLD void Vtb_ozone_backend___024root___eval_initial__TOP(Vtb_ozone_backend___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ozone_backend___024root___eval_initial__TOP\n"); );
    Vtb_ozone_backend__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.tb_ozone_backend__DOT__clk = 0U;
}

VL_ATTR_COLD void Vtb_ozone_backend___024root___eval_final(Vtb_ozone_backend___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ozone_backend___024root___eval_final\n"); );
    Vtb_ozone_backend__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_ozone_backend___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_ozone_backend___024root___eval_phase__stl(Vtb_ozone_backend___024root* vlSelf);

VL_ATTR_COLD void Vtb_ozone_backend___024root___eval_settle(Vtb_ozone_backend___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ozone_backend___024root___eval_settle\n"); );
    Vtb_ozone_backend__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VstlIterCount;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            Vtb_ozone_backend___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
            VL_FATAL_MT("tb/tb_ozone_backend.sv", 143, "", "DIDNOTCONVERGE: Settle region did not converge after '--converge-limit' of 100 tries");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        vlSelfRef.__VstlPhaseResult = Vtb_ozone_backend___024root___eval_phase__stl(vlSelf);
        vlSelfRef.__VstlFirstIteration = 0U;
    } while (vlSelfRef.__VstlPhaseResult);
}

VL_ATTR_COLD void Vtb_ozone_backend___024root___eval_triggers_vec__stl(Vtb_ozone_backend___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ozone_backend___024root___eval_triggers_vec__stl\n"); );
    Vtb_ozone_backend__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered[0U]) 
                                     | (IData)((IData)(vlSelfRef.__VstlFirstIteration)));
}

VL_ATTR_COLD bool Vtb_ozone_backend___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_ozone_backend___024root___dump_triggers__stl(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ozone_backend___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(Vtb_ozone_backend___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vtb_ozone_backend___024root___trigger_anySet__stl(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ozone_backend___024root___trigger_anySet__stl\n"); );
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

extern const VlWide<9>/*287:0*/ Vtb_ozone_backend__ConstPool__CONST_h083ec1be_0;

VL_ATTR_COLD void Vtb_ozone_backend___024root___stl_sequent__TOP__0(Vtb_ozone_backend___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ozone_backend___024root___stl_sequent__TOP__0\n"); );
    Vtb_ozone_backend__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    VlWide<9>/*279:0*/ tb_ozone_backend__DOT__rob__DOT__head_entry;
    VL_ZERO_W(280, tb_ozone_backend__DOT__rob__DOT__head_entry);
    VlWide<3>/*64:0*/ tb_ozone_backend__DOT__adder__DOT__add_result_ext;
    VL_ZERO_W(65, tb_ozone_backend__DOT__adder__DOT__add_result_ext);
    VlWide<3>/*64:0*/ tb_ozone_backend__DOT__adder__DOT__sub_result_ext;
    VL_ZERO_W(65, tb_ozone_backend__DOT__adder__DOT__sub_result_ext);
    CData/*0:0*/ tb_ozone_backend__DOT__adder__DOT__add_carry;
    tb_ozone_backend__DOT__adder__DOT__add_carry = 0;
    CData/*0:0*/ tb_ozone_backend__DOT__adder__DOT__add_overflow;
    tb_ozone_backend__DOT__adder__DOT__add_overflow = 0;
    CData/*0:0*/ tb_ozone_backend__DOT__adder__DOT__sub_carry;
    tb_ozone_backend__DOT__adder__DOT__sub_carry = 0;
    CData/*0:0*/ tb_ozone_backend__DOT__adder__DOT__sub_overflow;
    tb_ozone_backend__DOT__adder__DOT__sub_overflow = 0;
    CData/*5:0*/ tb_ozone_backend__DOT__cdb__DOT__logic_age;
    tb_ozone_backend__DOT__cdb__DOT__logic_age = 0;
    CData/*2:0*/ tb_ozone_backend__DOT__cdb__DOT__unnamedblk1__DOT__winner;
    tb_ozone_backend__DOT__cdb__DOT__unnamedblk1__DOT__winner = 0;
    CData/*5:0*/ tb_ozone_backend__DOT__cdb__DOT__unnamedblk1__DOT__best_age;
    tb_ozone_backend__DOT__cdb__DOT__unnamedblk1__DOT__best_age = 0;
    VlWide<3>/*95:0*/ __Vtemp_2;
    VlWide<3>/*95:0*/ __Vtemp_3;
    VlWide<3>/*95:0*/ __Vtemp_4;
    VlWide<3>/*95:0*/ __Vtemp_6;
    VlWide<3>/*95:0*/ __Vtemp_7;
    VlWide<3>/*95:0*/ __Vtemp_8;
    VlWide<3>/*95:0*/ __Vtemp_9;
    VlWide<3>/*95:0*/ __Vtemp_10;
    // Body
    vlSelfRef.tb_ozone_backend__DOT__adder_full = 1U;
    if ((1U & (~ (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[0U][0U] 
                  >> 0x00000011U)))) {
        vlSelfRef.tb_ozone_backend__DOT__adder_full = 0U;
    }
    if ((1U & (~ (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[1U][0U] 
                  >> 0x00000011U)))) {
        vlSelfRef.tb_ozone_backend__DOT__adder_full = 0U;
    }
    if ((1U & (~ (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[2U][0U] 
                  >> 0x00000011U)))) {
        vlSelfRef.tb_ozone_backend__DOT__adder_full = 0U;
    }
    if ((1U & (~ (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[3U][0U] 
                  >> 0x00000011U)))) {
        vlSelfRef.tb_ozone_backend__DOT__adder_full = 0U;
    }
    vlSelfRef.tb_ozone_backend__DOT__logic_full = 1U;
    if ((1U & (~ (vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__entries[0U][0U] 
                  >> 0x0000000bU)))) {
        vlSelfRef.tb_ozone_backend__DOT__logic_full = 0U;
    }
    if ((1U & (~ (vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__entries[1U][0U] 
                  >> 0x0000000bU)))) {
        vlSelfRef.tb_ozone_backend__DOT__logic_full = 0U;
    }
    if ((1U & (~ (vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__entries[2U][0U] 
                  >> 0x0000000bU)))) {
        vlSelfRef.tb_ozone_backend__DOT__logic_full = 0U;
    }
    if ((1U & (~ (vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__entries[3U][0U] 
                  >> 0x0000000bU)))) {
        vlSelfRef.tb_ozone_backend__DOT__logic_full = 0U;
    }
    vlSelfRef.tb_ozone_backend__DOT__adder__DOT__fu_ready 
        = (1U & (~ (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__result[4U] 
                    >> 0x00000016U)));
    vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__fu_ready 
        = (1U & (~ (vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__result[4U] 
                    >> 0x00000016U)));
    vlSelfRef.tb_ozone_backend__DOT__src1_status[0U] 
        = vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
        [((0x1eU >= (IData)(vlSelfRef.tb_ozone_backend__DOT__src1_addr))
           ? (IData)(vlSelfRef.tb_ozone_backend__DOT__src1_addr)
           : 0U)][0U];
    vlSelfRef.tb_ozone_backend__DOT__src1_status[1U] 
        = vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
        [((0x1eU >= (IData)(vlSelfRef.tb_ozone_backend__DOT__src1_addr))
           ? (IData)(vlSelfRef.tb_ozone_backend__DOT__src1_addr)
           : 0U)][1U];
    vlSelfRef.tb_ozone_backend__DOT__src1_status[2U] 
        = vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
        [((0x1eU >= (IData)(vlSelfRef.tb_ozone_backend__DOT__src1_addr))
           ? (IData)(vlSelfRef.tb_ozone_backend__DOT__src1_addr)
           : 0U)][2U];
    vlSelfRef.tb_ozone_backend__DOT__src2_status[0U] 
        = vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
        [((0x1eU >= (IData)(vlSelfRef.tb_ozone_backend__DOT__src2_addr))
           ? (IData)(vlSelfRef.tb_ozone_backend__DOT__src2_addr)
           : 0U)][0U];
    vlSelfRef.tb_ozone_backend__DOT__src2_status[1U] 
        = vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
        [((0x1eU >= (IData)(vlSelfRef.tb_ozone_backend__DOT__src2_addr))
           ? (IData)(vlSelfRef.tb_ozone_backend__DOT__src2_addr)
           : 0U)][1U];
    vlSelfRef.tb_ozone_backend__DOT__src2_status[2U] 
        = vlSelfRef.tb_ozone_backend__DOT__regstate__DOT__gp_reg
        [((0x1eU >= (IData)(vlSelfRef.tb_ozone_backend__DOT__src2_addr))
           ? (IData)(vlSelfRef.tb_ozone_backend__DOT__src2_addr)
           : 0U)][2U];
    vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[0U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[1U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[2U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[3U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[4U] = 0U;
    if (((((vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__entries[0U][0U] 
            >> 0x0000000bU) & (0U == (0x0000003fU & 
                                      (vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__entries[0U][0U] 
                                       >> 0x00000018U)))) 
          & (0U == (0x0000003fU & (vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__entries[0U][0U] 
                                   >> 0x00000012U)))) 
         & (~ (vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__result[4U] 
               >> 0x00000016U)))) {
        if ((1U & ((~ (IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_valid)) 
                   | ((0x0000003fU & (vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__entries[0U][0U] 
                                      >> 0x0000000cU)) 
                      < (0x0000003fU & (vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[0U] 
                                        >> 0x0000000cU)))))) {
            vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_valid = 1U;
            vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[0U] 
                = vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__entries[0U][0U];
            vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[1U] 
                = vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__entries[0U][1U];
            vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[2U] 
                = vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__entries[0U][2U];
            vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[3U] 
                = vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__entries[0U][3U];
            vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[4U] 
                = vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__entries[0U][4U];
        }
    }
    if (((((vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__entries[1U][0U] 
            >> 0x0000000bU) & (0U == (0x0000003fU & 
                                      (vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__entries[1U][0U] 
                                       >> 0x00000018U)))) 
          & (0U == (0x0000003fU & (vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__entries[1U][0U] 
                                   >> 0x00000012U)))) 
         & (~ (vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__result[4U] 
               >> 0x00000016U)))) {
        if ((1U & ((~ (IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_valid)) 
                   | ((0x0000003fU & (vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__entries[1U][0U] 
                                      >> 0x0000000cU)) 
                      < (0x0000003fU & (vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[0U] 
                                        >> 0x0000000cU)))))) {
            vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_valid = 1U;
            vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[0U] 
                = vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__entries[1U][0U];
            vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[1U] 
                = vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__entries[1U][1U];
            vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[2U] 
                = vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__entries[1U][2U];
            vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[3U] 
                = vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__entries[1U][3U];
            vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[4U] 
                = vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__entries[1U][4U];
        }
    }
    if (((((vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__entries[2U][0U] 
            >> 0x0000000bU) & (0U == (0x0000003fU & 
                                      (vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__entries[2U][0U] 
                                       >> 0x00000018U)))) 
          & (0U == (0x0000003fU & (vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__entries[2U][0U] 
                                   >> 0x00000012U)))) 
         & (~ (vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__result[4U] 
               >> 0x00000016U)))) {
        if ((1U & ((~ (IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_valid)) 
                   | ((0x0000003fU & (vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__entries[2U][0U] 
                                      >> 0x0000000cU)) 
                      < (0x0000003fU & (vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[0U] 
                                        >> 0x0000000cU)))))) {
            vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_valid = 1U;
            vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[0U] 
                = vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__entries[2U][0U];
            vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[1U] 
                = vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__entries[2U][1U];
            vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[2U] 
                = vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__entries[2U][2U];
            vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[3U] 
                = vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__entries[2U][3U];
            vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[4U] 
                = vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__entries[2U][4U];
        }
    }
    if (((((vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__entries[3U][0U] 
            >> 0x0000000bU) & (0U == (0x0000003fU & 
                                      (vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__entries[3U][0U] 
                                       >> 0x00000018U)))) 
          & (0U == (0x0000003fU & (vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__entries[3U][0U] 
                                   >> 0x00000012U)))) 
         & (~ (vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__result[4U] 
               >> 0x00000016U)))) {
        if ((1U & ((~ (IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_valid)) 
                   | ((0x0000003fU & (vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__entries[3U][0U] 
                                      >> 0x0000000cU)) 
                      < (0x0000003fU & (vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[0U] 
                                        >> 0x0000000cU)))))) {
            vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_valid = 1U;
            vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[0U] 
                = vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__entries[3U][0U];
            vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[1U] 
                = vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__entries[3U][1U];
            vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[2U] 
                = vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__entries[3U][2U];
            vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[3U] 
                = vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__entries[3U][3U];
            vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[4U] 
                = vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__entries[3U][4U];
        }
    }
    VL_ASSIGN_W(280, tb_ozone_backend__DOT__rob__DOT__head_entry, Vtb_ozone_backend__ConstPool__CONST_h083ec1be_0);
    if ((0U != (IData)(vlSelfRef.tb_ozone_backend__DOT__rob__DOT__count))) {
        tb_ozone_backend__DOT__rob__DOT__head_entry[0U] 
            = vlSelfRef.tb_ozone_backend__DOT__rob__DOT__rob_entries
            [vlSelfRef.tb_ozone_backend__DOT__rob__DOT__head][0U];
        tb_ozone_backend__DOT__rob__DOT__head_entry[1U] 
            = vlSelfRef.tb_ozone_backend__DOT__rob__DOT__rob_entries
            [vlSelfRef.tb_ozone_backend__DOT__rob__DOT__head][1U];
        tb_ozone_backend__DOT__rob__DOT__head_entry[2U] 
            = vlSelfRef.tb_ozone_backend__DOT__rob__DOT__rob_entries
            [vlSelfRef.tb_ozone_backend__DOT__rob__DOT__head][2U];
        tb_ozone_backend__DOT__rob__DOT__head_entry[3U] 
            = vlSelfRef.tb_ozone_backend__DOT__rob__DOT__rob_entries
            [vlSelfRef.tb_ozone_backend__DOT__rob__DOT__head][3U];
        tb_ozone_backend__DOT__rob__DOT__head_entry[4U] 
            = vlSelfRef.tb_ozone_backend__DOT__rob__DOT__rob_entries
            [vlSelfRef.tb_ozone_backend__DOT__rob__DOT__head][4U];
        tb_ozone_backend__DOT__rob__DOT__head_entry[5U] 
            = vlSelfRef.tb_ozone_backend__DOT__rob__DOT__rob_entries
            [vlSelfRef.tb_ozone_backend__DOT__rob__DOT__head][5U];
        tb_ozone_backend__DOT__rob__DOT__head_entry[6U] 
            = vlSelfRef.tb_ozone_backend__DOT__rob__DOT__rob_entries
            [vlSelfRef.tb_ozone_backend__DOT__rob__DOT__head][6U];
        tb_ozone_backend__DOT__rob__DOT__head_entry[7U] 
            = vlSelfRef.tb_ozone_backend__DOT__rob__DOT__rob_entries
            [vlSelfRef.tb_ozone_backend__DOT__rob__DOT__head][7U];
        tb_ozone_backend__DOT__rob__DOT__head_entry[8U] 
            = vlSelfRef.tb_ozone_backend__DOT__rob__DOT__rob_entries
            [vlSelfRef.tb_ozone_backend__DOT__rob__DOT__head][8U];
    }
    vlSelfRef.tb_ozone_backend__DOT__rob__DOT__head_can_commit 
        = (((0U != (IData)(vlSelfRef.tb_ozone_backend__DOT__rob__DOT__count)) 
            & (tb_ozone_backend__DOT__rob__DOT__head_entry[8U] 
               >> 0x00000017U)) & (tb_ozone_backend__DOT__rob__DOT__head_entry[6U] 
                                   >> 7U));
    vlSelfRef.tb_ozone_backend__DOT__rob__DOT__do_alloc 
        = ((IData)(vlSelfRef.tb_ozone_backend__DOT__rob_alloc_valid) 
           & ((0x40U != (IData)(vlSelfRef.tb_ozone_backend__DOT__rob__DOT__count)) 
              | (IData)(vlSelfRef.tb_ozone_backend__DOT__rob__DOT__head_can_commit)));
    vlSelfRef.tb_ozone_backend__DOT__commit_valid = vlSelfRef.tb_ozone_backend__DOT__rob__DOT__head_can_commit;
    vlSelfRef.tb_ozone_backend__DOT__commit_reg_en 
        = (((IData)(vlSelfRef.tb_ozone_backend__DOT__rob__DOT__head_can_commit) 
            & (0x00004000U == (0x0000c000U & tb_ozone_backend__DOT__rob__DOT__head_entry[8U]))) 
           & (0x1fU != (0x0000001fU & (tb_ozone_backend__DOT__rob__DOT__head_entry[8U] 
                                       >> 0x00000010U))));
    vlSelfRef.tb_ozone_backend__DOT__commit_reg_addr 
        = (0x0000001fU & (tb_ozone_backend__DOT__rob__DOT__head_entry[8U] 
                          >> 0x00000010U));
    vlSelfRef.tb_ozone_backend__DOT__commit_reg_value 
        = (((QData)((IData)(tb_ozone_backend__DOT__rob__DOT__head_entry[8U])) 
            << 0x00000033U) | (((QData)((IData)(tb_ozone_backend__DOT__rob__DOT__head_entry[7U])) 
                                << 0x00000013U) | ((QData)((IData)(tb_ozone_backend__DOT__rob__DOT__head_entry[6U])) 
                                                   >> 0x0000000dU)));
    vlSelfRef.tb_ozone_backend__DOT__commit_nzcv_en 
        = ((IData)(vlSelfRef.tb_ozone_backend__DOT__rob__DOT__head_can_commit) 
           & (tb_ozone_backend__DOT__rob__DOT__head_entry[6U] 
              >> 0x0000000cU));
    vlSelfRef.tb_ozone_backend__DOT__commit_nzcv_value 
        = (0x0000000fU & (tb_ozone_backend__DOT__rob__DOT__head_entry[6U] 
                          >> 8U));
    vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[1U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[2U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[3U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[4U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[5U] = 0U;
    if (((((vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[0U][0U] 
            >> 0x00000011U) & (0U == (0x0000003fU & 
                                      ((vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[0U][1U] 
                                        << 2U) | (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[0U][0U] 
                                                  >> 0x0000001eU))))) 
          & (0U == (0x0000003fU & (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[0U][0U] 
                                   >> 0x00000018U)))) 
         & (~ (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__result[4U] 
               >> 0x00000016U)))) {
        if ((1U & ((~ (IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_valid)) 
                   | ((0x0000003fU & (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[0U][0U] 
                                      >> 0x00000012U)) 
                      < (0x0000003fU & (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U] 
                                        >> 0x00000012U)))))) {
            vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_valid = 1U;
            vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U] 
                = vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[0U][0U];
            vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[1U] 
                = vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[0U][1U];
            vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[2U] 
                = vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[0U][2U];
            vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[3U] 
                = vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[0U][3U];
            vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[4U] 
                = vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[0U][4U];
            vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[5U] 
                = vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[0U][5U];
        }
    }
    if (((((vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[1U][0U] 
            >> 0x00000011U) & (0U == (0x0000003fU & 
                                      ((vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[1U][1U] 
                                        << 2U) | (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[1U][0U] 
                                                  >> 0x0000001eU))))) 
          & (0U == (0x0000003fU & (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[1U][0U] 
                                   >> 0x00000018U)))) 
         & (~ (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__result[4U] 
               >> 0x00000016U)))) {
        if ((1U & ((~ (IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_valid)) 
                   | ((0x0000003fU & (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[1U][0U] 
                                      >> 0x00000012U)) 
                      < (0x0000003fU & (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U] 
                                        >> 0x00000012U)))))) {
            vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_valid = 1U;
            vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U] 
                = vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[1U][0U];
            vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[1U] 
                = vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[1U][1U];
            vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[2U] 
                = vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[1U][2U];
            vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[3U] 
                = vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[1U][3U];
            vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[4U] 
                = vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[1U][4U];
            vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[5U] 
                = vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[1U][5U];
        }
    }
    if (((((vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[2U][0U] 
            >> 0x00000011U) & (0U == (0x0000003fU & 
                                      ((vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[2U][1U] 
                                        << 2U) | (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[2U][0U] 
                                                  >> 0x0000001eU))))) 
          & (0U == (0x0000003fU & (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[2U][0U] 
                                   >> 0x00000018U)))) 
         & (~ (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__result[4U] 
               >> 0x00000016U)))) {
        if ((1U & ((~ (IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_valid)) 
                   | ((0x0000003fU & (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[2U][0U] 
                                      >> 0x00000012U)) 
                      < (0x0000003fU & (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U] 
                                        >> 0x00000012U)))))) {
            vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_valid = 1U;
            vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U] 
                = vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[2U][0U];
            vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[1U] 
                = vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[2U][1U];
            vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[2U] 
                = vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[2U][2U];
            vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[3U] 
                = vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[2U][3U];
            vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[4U] 
                = vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[2U][4U];
            vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[5U] 
                = vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[2U][5U];
        }
    }
    if (((((vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[3U][0U] 
            >> 0x00000011U) & (0U == (0x0000003fU & 
                                      ((vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[3U][1U] 
                                        << 2U) | (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[3U][0U] 
                                                  >> 0x0000001eU))))) 
          & (0U == (0x0000003fU & (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[3U][0U] 
                                   >> 0x00000018U)))) 
         & (~ (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__result[4U] 
               >> 0x00000016U)))) {
        if ((1U & ((~ (IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_valid)) 
                   | ((0x0000003fU & (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[3U][0U] 
                                      >> 0x00000012U)) 
                      < (0x0000003fU & (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U] 
                                        >> 0x00000012U)))))) {
            vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_valid = 1U;
            vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U] 
                = vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[3U][0U];
            vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[1U] 
                = vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[3U][1U];
            vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[2U] 
                = vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[3U][2U];
            vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[3U] 
                = vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[3U][3U];
            vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[4U] 
                = vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[3U][4U];
            vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[5U] 
                = vlSelfRef.tb_ozone_backend__DOT__adder__DOT__entries[3U][5U];
        }
    }
    tb_ozone_backend__DOT__cdb__DOT__logic_age = (0x0000003fU 
                                                  & (((vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__result[4U] 
                                                       << 0x00000010U) 
                                                      | (vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__result[4U] 
                                                         >> 0x00000010U)) 
                                                     - (IData)(vlSelfRef.tb_ozone_backend__DOT__rob__DOT__head)));
    vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__logic_value_valid = 1U;
    vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__logic_flags_valid = 0U;
    if ((1U & (~ (vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[0U] 
                  >> 0x0000000aU)))) {
        if ((0x00000200U & vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[0U])) {
            if ((0x00000100U & vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[0U])) {
                if ((1U & (~ (vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[0U] 
                              >> 7U)))) {
                    if ((1U & (~ (vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[0U] 
                                  >> 6U)))) {
                        if ((1U & (~ (vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[0U] 
                                      >> 5U)))) {
                            vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__logic_value_valid = 0U;
                            vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__logic_flags_valid = 1U;
                        }
                    }
                }
            } else if ((0x00000080U & vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[0U])) {
                if ((0x00000040U & vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[0U])) {
                    if ((0x00000020U & vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[0U])) {
                        vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__logic_flags_valid = 1U;
                    }
                }
            }
        }
    }
    vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__logic_result 
        = (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[4U])) 
            << 0x00000022U) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[3U])) 
                                << 2U) | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[2U])) 
                                          >> 0x0000001eU)));
    vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__logic_nzcv = 0U;
    if ((0x00000400U & vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[0U])) {
        vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__logic_result 
            = (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[4U])) 
                << 0x00000022U) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[3U])) 
                                    << 2U) | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[2U])) 
                                              >> 0x0000001eU)));
    } else if ((0x00000200U & vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[0U])) {
        if ((0x00000100U & vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[0U])) {
            if ((0x00000080U & vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[0U])) {
                vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__logic_result 
                    = (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[4U])) 
                        << 0x00000022U) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[3U])) 
                                            << 2U) 
                                           | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[2U])) 
                                              >> 0x0000001eU)));
            } else if ((0x00000040U & vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[0U])) {
                vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__logic_result 
                    = (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[4U])) 
                        << 0x00000022U) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[3U])) 
                                            << 2U) 
                                           | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[2U])) 
                                              >> 0x0000001eU)));
            } else if ((0x00000020U & vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[0U])) {
                vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__logic_result 
                    = (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[4U])) 
                        << 0x00000022U) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[3U])) 
                                            << 2U) 
                                           | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[2U])) 
                                              >> 0x0000001eU)));
            } else {
                vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__logic_result 
                    = ((((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[4U])) 
                         << 0x00000022U) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[3U])) 
                                             << 2U) 
                                            | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[2U])) 
                                               >> 0x0000001eU))) 
                       & (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[2U])) 
                           << 0x00000022U) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[1U])) 
                                               << 2U) 
                                              | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[0U])) 
                                                 >> 0x0000001eU))));
                vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__logic_nzcv 
                    = ((1U & (IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__logic_nzcv)) 
                       | (((4U & ((IData)((vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__logic_result 
                                           >> 0x3fU)) 
                                  << 2U)) | ((0ULL 
                                              == vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__logic_result) 
                                             << 1U)) 
                          << 1U));
                vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__logic_nzcv 
                    = (0x0eU & (IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__logic_nzcv));
            }
        } else if ((0x00000080U & vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[0U])) {
            if ((0x00000040U & vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[0U])) {
                if ((0x00000020U & vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[0U])) {
                    vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__logic_result 
                        = ((((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[4U])) 
                             << 0x00000022U) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[3U])) 
                                                 << 2U) 
                                                | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[2U])) 
                                                   >> 0x0000001eU))) 
                           & (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[2U])) 
                               << 0x00000022U) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[1U])) 
                                                   << 2U) 
                                                  | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[0U])) 
                                                     >> 0x0000001eU))));
                    vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__logic_nzcv 
                        = ((1U & (IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__logic_nzcv)) 
                           | (((4U & ((IData)((vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__logic_result 
                                               >> 0x3fU)) 
                                      << 2U)) | ((0ULL 
                                                  == vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__logic_result) 
                                                 << 1U)) 
                              << 1U));
                    vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__logic_nzcv 
                        = (0x0eU & (IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__logic_nzcv));
                } else {
                    vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__logic_result 
                        = (~ (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[2U])) 
                               << 0x00000022U) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[1U])) 
                                                   << 2U) 
                                                  | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[0U])) 
                                                     >> 0x0000001eU))));
                }
            } else {
                vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__logic_result 
                    = ((0x00000020U & vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[0U])
                        ? ((((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[4U])) 
                             << 0x00000022U) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[3U])) 
                                                 << 2U) 
                                                | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[2U])) 
                                                   >> 0x0000001eU))) 
                           | (~ (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[2U])) 
                                  << 0x00000022U) | 
                                 (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[1U])) 
                                   << 2U) | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[0U])) 
                                             >> 0x0000001eU)))))
                        : ((((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[4U])) 
                             << 0x00000022U) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[3U])) 
                                                 << 2U) 
                                                | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[2U])) 
                                                   >> 0x0000001eU))) 
                           ^ (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[2U])) 
                               << 0x00000022U) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[1U])) 
                                                   << 2U) 
                                                  | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[0U])) 
                                                     >> 0x0000001eU)))));
            }
        } else {
            vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__logic_result 
                = ((0x00000040U & vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[0U])
                    ? ((0x00000020U & vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[0U])
                        ? ((((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[4U])) 
                             << 0x00000022U) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[3U])) 
                                                 << 2U) 
                                                | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[2U])) 
                                                   >> 0x0000001eU))) 
                           | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[2U])) 
                               << 0x00000022U) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[1U])) 
                                                   << 2U) 
                                                  | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[0U])) 
                                                     >> 0x0000001eU))))
                        : (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[4U])) 
                            << 0x00000022U) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[3U])) 
                                                << 2U) 
                                               | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[2U])) 
                                                  >> 0x0000001eU))))
                    : (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[4U])) 
                        << 0x00000022U) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[3U])) 
                                            << 2U) 
                                           | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[2U])) 
                                              >> 0x0000001eU))));
        }
    } else {
        vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__logic_result 
            = ((0x00000100U & vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[0U])
                ? (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[4U])) 
                    << 0x00000022U) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[3U])) 
                                        << 2U) | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[2U])) 
                                                  >> 0x0000001eU)))
                : ((0x00000080U & vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[0U])
                    ? ((0x00000040U & vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[0U])
                        ? ((0x00000020U & vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[0U])
                            ? ((((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[4U])) 
                                 << 0x00000022U) | 
                                (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[3U])) 
                                  << 2U) | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[2U])) 
                                            >> 0x0000001eU))) 
                               & (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[2U])) 
                                   << 0x00000022U) 
                                  | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[1U])) 
                                      << 2U) | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[0U])) 
                                                >> 0x0000001eU))))
                            : (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[4U])) 
                                << 0x00000022U) | (
                                                   ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[3U])) 
                                                    << 2U) 
                                                   | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[2U])) 
                                                      >> 0x0000001eU))))
                        : (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[4U])) 
                            << 0x00000022U) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[3U])) 
                                                << 2U) 
                                               | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[2U])) 
                                                  >> 0x0000001eU))))
                    : (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[4U])) 
                        << 0x00000022U) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[3U])) 
                                            << 2U) 
                                           | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__issue_entry[2U])) 
                                              >> 0x0000001eU)))));
    }
    vlSelfRef.tb_ozone_backend__DOT__adder__DOT__add_value_valid = 1U;
    vlSelfRef.tb_ozone_backend__DOT__adder__DOT__add_flags_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder__DOT__add_br_valid = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder__DOT__add_br_taken = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder__DOT__add_br_target = 0ULL;
    if ((1U & (~ (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U] 
                  >> 0x00000010U)))) {
        if ((0x00008000U & vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U])) {
            if ((1U & (~ (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U] 
                          >> 0x0000000eU)))) {
                if ((1U & (~ (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U] 
                              >> 0x0000000dU)))) {
                    if ((0x00001000U & vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U])) {
                        if ((1U & (~ (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U] 
                                      >> 0x0000000bU)))) {
                            vlSelfRef.tb_ozone_backend__DOT__adder__DOT__add_value_valid = 0U;
                            vlSelfRef.tb_ozone_backend__DOT__adder__DOT__add_br_valid = 1U;
                            vlSelfRef.tb_ozone_backend__DOT__adder__DOT__add_br_taken 
                                = (1U & ((0x00000040U 
                                          & vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U])
                                          ? ((0x00000020U 
                                              & vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U])
                                              ? ((1U 
                                                  & (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U] 
                                                     >> 4U)) 
                                                 || (1U 
                                                     & ((8U 
                                                         & vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U])
                                                         ? 
                                                        ((vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U] 
                                                          >> 9U) 
                                                         | ((1U 
                                                             & (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U] 
                                                                >> 0x0000000aU)) 
                                                            != 
                                                            (1U 
                                                             & (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U] 
                                                                >> 7U))))
                                                         : 
                                                        ((~ 
                                                          (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U] 
                                                           >> 9U)) 
                                                         & ((1U 
                                                             & (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U] 
                                                                >> 0x0000000aU)) 
                                                            == 
                                                            (1U 
                                                             & (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U] 
                                                                >> 7U)))))))
                                              : ((0x00000010U 
                                                  & vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U])
                                                  ? 
                                                 ((8U 
                                                   & vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U])
                                                   ? 
                                                  ((1U 
                                                    & (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U] 
                                                       >> 0x0000000aU)) 
                                                   != 
                                                   (1U 
                                                    & (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U] 
                                                       >> 7U)))
                                                   : 
                                                  ((1U 
                                                    & (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U] 
                                                       >> 0x0000000aU)) 
                                                   == 
                                                   (1U 
                                                    & (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U] 
                                                       >> 7U))))
                                                  : 
                                                 ((8U 
                                                   & vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U])
                                                   ? (IData)(
                                                             (0x00000100U 
                                                              != 
                                                              (0x00000300U 
                                                               & vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U])))
                                                   : (IData)(
                                                             (0x00000100U 
                                                              == 
                                                              (0x00000300U 
                                                               & vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U]))))))
                                          : ((0x00000020U 
                                              & vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U])
                                              ? ((0x00000010U 
                                                  & vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U])
                                                  ? 
                                                 ((8U 
                                                   & vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U])
                                                   ? 
                                                  (~ 
                                                   (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U] 
                                                    >> 7U))
                                                   : 
                                                  (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U] 
                                                   >> 7U))
                                                  : 
                                                 ((8U 
                                                   & vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U])
                                                   ? 
                                                  (~ 
                                                   (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U] 
                                                    >> 0x0000000aU))
                                                   : 
                                                  (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U] 
                                                   >> 0x0000000aU)))
                                              : ((0x00000010U 
                                                  & vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U])
                                                  ? 
                                                 ((8U 
                                                   & vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U])
                                                   ? 
                                                  (~ 
                                                   (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U] 
                                                    >> 8U))
                                                   : 
                                                  (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U] 
                                                   >> 8U))
                                                  : 
                                                 ((8U 
                                                   & vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U])
                                                   ? 
                                                  (~ 
                                                   (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U] 
                                                    >> 9U))
                                                   : 
                                                  (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U] 
                                                   >> 9U))))));
                            vlSelfRef.tb_ozone_backend__DOT__adder__DOT__add_br_target 
                                = ((((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[5U])) 
                                     << 0x0000003cU) 
                                    | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[4U])) 
                                        << 0x0000001cU) 
                                       | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[3U])) 
                                          >> 4U))) 
                                   + (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[3U])) 
                                       << 0x0000003cU) 
                                      | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[2U])) 
                                          << 0x0000001cU) 
                                         | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[1U])) 
                                            >> 4U))));
                        }
                    }
                }
            }
        } else if ((0x00004000U & vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U])) {
            if ((1U & (~ (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U] 
                          >> 0x0000000dU)))) {
                if ((1U & (~ (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U] 
                              >> 0x0000000cU)))) {
                    vlSelfRef.tb_ozone_backend__DOT__adder__DOT__add_value_valid = 0U;
                    vlSelfRef.tb_ozone_backend__DOT__adder__DOT__add_br_valid = 1U;
                    vlSelfRef.tb_ozone_backend__DOT__adder__DOT__add_br_taken = 1U;
                    vlSelfRef.tb_ozone_backend__DOT__adder__DOT__add_br_target 
                        = ((0x00000800U & vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U])
                            ? ((((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[5U])) 
                                 << 0x0000003cU) | 
                                (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[4U])) 
                                  << 0x0000001cU) | 
                                 ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[3U])) 
                                  >> 4U))) + (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[3U])) 
                                               << 0x0000003cU) 
                                              | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[2U])) 
                                                  << 0x0000001cU) 
                                                 | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[1U])) 
                                                    >> 4U))))
                            : ((((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[5U])) 
                                 << 0x0000003cU) | 
                                (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[4U])) 
                                  << 0x0000001cU) | 
                                 ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[3U])) 
                                  >> 4U))) + (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[3U])) 
                                               << 0x0000003cU) 
                                              | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[2U])) 
                                                  << 0x0000001cU) 
                                                 | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[1U])) 
                                                    >> 4U)))));
                }
            }
        } else if ((0x00002000U & vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U])) {
            if ((1U & (~ (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U] 
                          >> 0x0000000cU)))) {
                vlSelfRef.tb_ozone_backend__DOT__adder__DOT__add_value_valid = 0U;
            }
        }
        if ((1U & (~ (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U] 
                      >> 0x0000000fU)))) {
            if ((1U & (~ (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U] 
                          >> 0x0000000eU)))) {
                if ((0x00002000U & vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U])) {
                    if ((1U & (~ (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U] 
                                  >> 0x0000000cU)))) {
                        vlSelfRef.tb_ozone_backend__DOT__adder__DOT__add_flags_valid = 1U;
                    }
                } else if ((0x00001000U & vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U])) {
                    if ((0x00000800U & vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U])) {
                        vlSelfRef.tb_ozone_backend__DOT__adder__DOT__add_flags_valid = 1U;
                    }
                } else if ((0x00000800U & vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U])) {
                    vlSelfRef.tb_ozone_backend__DOT__adder__DOT__add_flags_valid = 1U;
                }
            }
        }
    }
    __Vtemp_2[0U] = (IData)((((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[5U])) 
                              << 0x0000003cU) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[4U])) 
                                                  << 0x0000001cU) 
                                                 | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[3U])) 
                                                    >> 4U))));
    __Vtemp_2[1U] = (IData)(((((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[5U])) 
                               << 0x0000003cU) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[4U])) 
                                                   << 0x0000001cU) 
                                                  | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[3U])) 
                                                     >> 4U))) 
                             >> 0x00000020U));
    __Vtemp_2[2U] = 0U;
    __Vtemp_3[0U] = (IData)((((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[3U])) 
                              << 0x0000003cU) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[2U])) 
                                                  << 0x0000001cU) 
                                                 | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[1U])) 
                                                    >> 4U))));
    __Vtemp_3[1U] = (IData)(((((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[3U])) 
                               << 0x0000003cU) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[2U])) 
                                                   << 0x0000001cU) 
                                                  | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[1U])) 
                                                     >> 4U))) 
                             >> 0x00000020U));
    __Vtemp_3[2U] = 0U;
    VL_ADD_W(3, __Vtemp_4, __Vtemp_2, __Vtemp_3);
    tb_ozone_backend__DOT__adder__DOT__add_result_ext[0U] 
        = __Vtemp_4[0U];
    tb_ozone_backend__DOT__adder__DOT__add_result_ext[1U] 
        = __Vtemp_4[1U];
    tb_ozone_backend__DOT__adder__DOT__add_result_ext[2U] 
        = (1U & __Vtemp_4[2U]);
    tb_ozone_backend__DOT__adder__DOT__add_carry = 
        (1U & tb_ozone_backend__DOT__adder__DOT__add_result_ext[2U]);
    tb_ozone_backend__DOT__adder__DOT__add_overflow 
        = (((1U & (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[5U] 
                   >> 3U)) == (1U & (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[3U] 
                                     >> 3U))) & ((tb_ozone_backend__DOT__adder__DOT__add_result_ext[1U] 
                                                  >> 0x0000001fU) 
                                                 != 
                                                 (1U 
                                                  & (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[5U] 
                                                     >> 3U))));
    __Vtemp_6[0U] = 1U;
    __Vtemp_6[1U] = 0U;
    __Vtemp_6[2U] = 0U;
    __Vtemp_7[0U] = (IData)((((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[5U])) 
                              << 0x0000003cU) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[4U])) 
                                                  << 0x0000001cU) 
                                                 | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[3U])) 
                                                    >> 4U))));
    __Vtemp_7[1U] = (IData)(((((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[5U])) 
                               << 0x0000003cU) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[4U])) 
                                                   << 0x0000001cU) 
                                                  | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[3U])) 
                                                     >> 4U))) 
                             >> 0x00000020U));
    __Vtemp_7[2U] = 0U;
    __Vtemp_8[0U] = (IData)((~ (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[3U])) 
                                 << 0x0000003cU) | 
                                (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[2U])) 
                                  << 0x0000001cU) | 
                                 ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[1U])) 
                                  >> 4U)))));
    __Vtemp_8[1U] = (IData)(((~ (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[3U])) 
                                  << 0x0000003cU) | 
                                 (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[2U])) 
                                   << 0x0000001cU) 
                                  | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[1U])) 
                                     >> 4U)))) >> 0x00000020U));
    __Vtemp_8[2U] = 0U;
    VL_ADD_W(3, __Vtemp_9, __Vtemp_7, __Vtemp_8);
    VL_ADD_W(3, __Vtemp_10, __Vtemp_6, __Vtemp_9);
    tb_ozone_backend__DOT__adder__DOT__sub_result_ext[0U] 
        = __Vtemp_10[0U];
    tb_ozone_backend__DOT__adder__DOT__sub_result_ext[1U] 
        = __Vtemp_10[1U];
    tb_ozone_backend__DOT__adder__DOT__sub_result_ext[2U] 
        = (1U & __Vtemp_10[2U]);
    tb_ozone_backend__DOT__adder__DOT__sub_carry = 
        (1U & tb_ozone_backend__DOT__adder__DOT__sub_result_ext[2U]);
    tb_ozone_backend__DOT__adder__DOT__sub_overflow 
        = (((1U & (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[5U] 
                   >> 3U)) != (1U & (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[3U] 
                                     >> 3U))) & ((tb_ozone_backend__DOT__adder__DOT__sub_result_ext[1U] 
                                                  >> 0x0000001fU) 
                                                 != 
                                                 (1U 
                                                  & (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[5U] 
                                                     >> 3U))));
    vlSelfRef.tb_ozone_backend__DOT__adder__DOT__add_result 
        = ((((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[5U])) 
             << 0x0000003cU) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[4U])) 
                                 << 0x0000001cU) | 
                                ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[3U])) 
                                 >> 4U))) + (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[3U])) 
                                              << 0x0000003cU) 
                                             | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[2U])) 
                                                 << 0x0000001cU) 
                                                | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[1U])) 
                                                   >> 4U))));
    vlSelfRef.tb_ozone_backend__DOT__adder__DOT__add_nzcv = 0U;
    if ((0x00010000U & vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U])) {
        vlSelfRef.tb_ozone_backend__DOT__adder__DOT__add_result 
            = ((((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[5U])) 
                 << 0x0000003cU) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[4U])) 
                                     << 0x0000001cU) 
                                    | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[3U])) 
                                       >> 4U))) + (
                                                   ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[3U])) 
                                                    << 0x0000003cU) 
                                                   | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[2U])) 
                                                       << 0x0000001cU) 
                                                      | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[1U])) 
                                                         >> 4U))));
    } else if ((0x00008000U & vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U])) {
        if ((0x00004000U & vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U])) {
            vlSelfRef.tb_ozone_backend__DOT__adder__DOT__add_result 
                = ((((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[5U])) 
                     << 0x0000003cU) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[4U])) 
                                         << 0x0000001cU) 
                                        | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[3U])) 
                                           >> 4U))) 
                   + (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[3U])) 
                       << 0x0000003cU) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[2U])) 
                                           << 0x0000001cU) 
                                          | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[1U])) 
                                             >> 4U))));
        } else if ((0x00002000U & vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U])) {
            vlSelfRef.tb_ozone_backend__DOT__adder__DOT__add_result 
                = ((((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[5U])) 
                     << 0x0000003cU) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[4U])) 
                                         << 0x0000001cU) 
                                        | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[3U])) 
                                           >> 4U))) 
                   + (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[3U])) 
                       << 0x0000003cU) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[2U])) 
                                           << 0x0000001cU) 
                                          | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[1U])) 
                                             >> 4U))));
        } else if ((0x00001000U & vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U])) {
            if ((0x00000800U & vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U])) {
                vlSelfRef.tb_ozone_backend__DOT__adder__DOT__add_result 
                    = ((((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[5U])) 
                         << 0x0000003cU) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[4U])) 
                                             << 0x0000001cU) 
                                            | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[3U])) 
                                               >> 4U))) 
                       + (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[3U])) 
                           << 0x0000003cU) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[2U])) 
                                               << 0x0000001cU) 
                                              | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[1U])) 
                                                 >> 4U))));
            }
        } else {
            vlSelfRef.tb_ozone_backend__DOT__adder__DOT__add_result 
                = ((((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[5U])) 
                     << 0x0000003cU) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[4U])) 
                                         << 0x0000001cU) 
                                        | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[3U])) 
                                           >> 4U))) 
                   + (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[3U])) 
                       << 0x0000003cU) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[2U])) 
                                           << 0x0000001cU) 
                                          | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[1U])) 
                                             >> 4U))));
        }
    } else if ((0x00004000U & vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U])) {
        if ((0x00002000U & vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U])) {
            vlSelfRef.tb_ozone_backend__DOT__adder__DOT__add_result 
                = ((((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[5U])) 
                     << 0x0000003cU) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[4U])) 
                                         << 0x0000001cU) 
                                        | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[3U])) 
                                           >> 4U))) 
                   + (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[3U])) 
                       << 0x0000003cU) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[2U])) 
                                           << 0x0000001cU) 
                                          | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[1U])) 
                                             >> 4U))));
        } else if ((0x00001000U & vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U])) {
            vlSelfRef.tb_ozone_backend__DOT__adder__DOT__add_result 
                = ((((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[5U])) 
                     << 0x0000003cU) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[4U])) 
                                         << 0x0000001cU) 
                                        | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[3U])) 
                                           >> 4U))) 
                   + (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[3U])) 
                       << 0x0000003cU) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[2U])) 
                                           << 0x0000001cU) 
                                          | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[1U])) 
                                             >> 4U))));
        }
    } else if ((0x00002000U & vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U])) {
        if ((0x00001000U & vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U])) {
            vlSelfRef.tb_ozone_backend__DOT__adder__DOT__add_result 
                = ((0x00000800U & vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U])
                    ? ((((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[5U])) 
                         << 0x0000003cU) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[4U])) 
                                             << 0x0000001cU) 
                                            | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[3U])) 
                                               >> 4U))) 
                       + (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[3U])) 
                           << 0x0000003cU) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[2U])) 
                                               << 0x0000001cU) 
                                              | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[1U])) 
                                                 >> 4U))))
                    : ((((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[5U])) 
                         << 0x0000003cU) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[4U])) 
                                             << 0x0000001cU) 
                                            | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[3U])) 
                                               >> 4U))) 
                       + (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[3U])) 
                           << 0x0000003cU) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[2U])) 
                                               << 0x0000001cU) 
                                              | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[1U])) 
                                                 >> 4U)))));
        } else if ((0x00000800U & vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U])) {
            vlSelfRef.tb_ozone_backend__DOT__adder__DOT__add_result 
                = (((QData)((IData)(tb_ozone_backend__DOT__adder__DOT__add_result_ext[1U])) 
                    << 0x00000020U) | (QData)((IData)(tb_ozone_backend__DOT__adder__DOT__add_result_ext[0U])));
            vlSelfRef.tb_ozone_backend__DOT__adder__DOT__add_nzcv 
                = ((1U & (IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__add_nzcv)) 
                   | (((4U & ((IData)((vlSelfRef.tb_ozone_backend__DOT__adder__DOT__add_result 
                                       >> 0x3fU)) << 2U)) 
                       | (((0ULL == vlSelfRef.tb_ozone_backend__DOT__adder__DOT__add_result) 
                           << 1U) | (IData)(tb_ozone_backend__DOT__adder__DOT__add_carry))) 
                      << 1U));
            vlSelfRef.tb_ozone_backend__DOT__adder__DOT__add_nzcv 
                = ((0x0eU & (IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__add_nzcv)) 
                   | (IData)(tb_ozone_backend__DOT__adder__DOT__add_overflow));
        } else {
            vlSelfRef.tb_ozone_backend__DOT__adder__DOT__add_result 
                = (((QData)((IData)(tb_ozone_backend__DOT__adder__DOT__sub_result_ext[1U])) 
                    << 0x00000020U) | (QData)((IData)(tb_ozone_backend__DOT__adder__DOT__sub_result_ext[0U])));
            vlSelfRef.tb_ozone_backend__DOT__adder__DOT__add_nzcv 
                = ((1U & (IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__add_nzcv)) 
                   | (((4U & ((IData)((vlSelfRef.tb_ozone_backend__DOT__adder__DOT__add_result 
                                       >> 0x3fU)) << 2U)) 
                       | (((0ULL == vlSelfRef.tb_ozone_backend__DOT__adder__DOT__add_result) 
                           << 1U) | (IData)(tb_ozone_backend__DOT__adder__DOT__sub_carry))) 
                      << 1U));
            vlSelfRef.tb_ozone_backend__DOT__adder__DOT__add_nzcv 
                = ((0x0eU & (IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__add_nzcv)) 
                   | (IData)(tb_ozone_backend__DOT__adder__DOT__sub_overflow));
        }
    } else if ((0x00001000U & vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U])) {
        if ((0x00000800U & vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U])) {
            vlSelfRef.tb_ozone_backend__DOT__adder__DOT__add_result 
                = (((QData)((IData)(tb_ozone_backend__DOT__adder__DOT__sub_result_ext[1U])) 
                    << 0x00000020U) | (QData)((IData)(tb_ozone_backend__DOT__adder__DOT__sub_result_ext[0U])));
            vlSelfRef.tb_ozone_backend__DOT__adder__DOT__add_nzcv 
                = ((1U & (IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__add_nzcv)) 
                   | (((4U & ((IData)((vlSelfRef.tb_ozone_backend__DOT__adder__DOT__add_result 
                                       >> 0x3fU)) << 2U)) 
                       | (((0ULL == vlSelfRef.tb_ozone_backend__DOT__adder__DOT__add_result) 
                           << 1U) | (IData)(tb_ozone_backend__DOT__adder__DOT__sub_carry))) 
                      << 1U));
            vlSelfRef.tb_ozone_backend__DOT__adder__DOT__add_nzcv 
                = ((0x0eU & (IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__add_nzcv)) 
                   | (IData)(tb_ozone_backend__DOT__adder__DOT__sub_overflow));
        } else {
            vlSelfRef.tb_ozone_backend__DOT__adder__DOT__add_result 
                = ((((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[5U])) 
                     << 0x0000003cU) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[4U])) 
                                         << 0x0000001cU) 
                                        | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[3U])) 
                                           >> 4U))) 
                   - (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[3U])) 
                       << 0x0000003cU) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[2U])) 
                                           << 0x0000001cU) 
                                          | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[1U])) 
                                             >> 4U))));
        }
    } else if ((0x00000800U & vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[0U])) {
        vlSelfRef.tb_ozone_backend__DOT__adder__DOT__add_result 
            = (((QData)((IData)(tb_ozone_backend__DOT__adder__DOT__add_result_ext[1U])) 
                << 0x00000020U) | (QData)((IData)(tb_ozone_backend__DOT__adder__DOT__add_result_ext[0U])));
        vlSelfRef.tb_ozone_backend__DOT__adder__DOT__add_nzcv 
            = ((1U & (IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__add_nzcv)) 
               | (((4U & ((IData)((vlSelfRef.tb_ozone_backend__DOT__adder__DOT__add_result 
                                   >> 0x3fU)) << 2U)) 
                   | (((0ULL == vlSelfRef.tb_ozone_backend__DOT__adder__DOT__add_result) 
                       << 1U) | (IData)(tb_ozone_backend__DOT__adder__DOT__add_carry))) 
                  << 1U));
        vlSelfRef.tb_ozone_backend__DOT__adder__DOT__add_nzcv 
            = ((0x0eU & (IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__add_nzcv)) 
               | (IData)(tb_ozone_backend__DOT__adder__DOT__add_overflow));
    } else {
        vlSelfRef.tb_ozone_backend__DOT__adder__DOT__add_result 
            = ((((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[5U])) 
                 << 0x0000003cU) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[4U])) 
                                     << 0x0000001cU) 
                                    | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[3U])) 
                                       >> 4U))) + (
                                                   ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[3U])) 
                                                    << 0x0000003cU) 
                                                   | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[2U])) 
                                                       << 0x0000001cU) 
                                                      | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__adder__DOT__issue_entry[1U])) 
                                                         >> 4U))));
    }
    vlSelfRef.tb_ozone_backend__DOT__cdb_broadcast[0U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__cdb_broadcast[1U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__cdb_broadcast[2U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__cdb_broadcast[3U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__cdb_broadcast[4U] = 0U;
    vlSelfRef.tb_ozone_backend__DOT__adder_granted = 0U;
    vlSelfRef.tb_ozone_backend__DOT__logic_granted = 0U;
    tb_ozone_backend__DOT__cdb__DOT__unnamedblk1__DOT__winner = 0U;
    tb_ozone_backend__DOT__cdb__DOT__unnamedblk1__DOT__best_age = 0U;
    if ((0x00400000U & vlSelfRef.tb_ozone_backend__DOT__adder__DOT__result[4U])) {
        tb_ozone_backend__DOT__cdb__DOT__unnamedblk1__DOT__winner = 1U;
        tb_ozone_backend__DOT__cdb__DOT__unnamedblk1__DOT__best_age 
            = (0x0000003fU & (((vlSelfRef.tb_ozone_backend__DOT__adder__DOT__result[4U] 
                                << 0x00000010U) | (vlSelfRef.tb_ozone_backend__DOT__adder__DOT__result[4U] 
                                                   >> 0x00000010U)) 
                              - (IData)(vlSelfRef.tb_ozone_backend__DOT__rob__DOT__head)));
    }
    if (((vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__result[4U] 
          >> 0x00000016U) & ((0U == (IData)(tb_ozone_backend__DOT__cdb__DOT__unnamedblk1__DOT__winner)) 
                             | ((IData)(tb_ozone_backend__DOT__cdb__DOT__logic_age) 
                                < (IData)(tb_ozone_backend__DOT__cdb__DOT__unnamedblk1__DOT__best_age))))) {
        tb_ozone_backend__DOT__cdb__DOT__unnamedblk1__DOT__winner = 2U;
        tb_ozone_backend__DOT__cdb__DOT__unnamedblk1__DOT__best_age 
            = tb_ozone_backend__DOT__cdb__DOT__logic_age;
    }
    if ((4U & (IData)(tb_ozone_backend__DOT__cdb__DOT__unnamedblk1__DOT__winner))) {
        if ((2U & (IData)(tb_ozone_backend__DOT__cdb__DOT__unnamedblk1__DOT__winner))) {
            vlSelfRef.tb_ozone_backend__DOT__cdb_broadcast[0U] = 0U;
            vlSelfRef.tb_ozone_backend__DOT__cdb_broadcast[1U] = 0U;
            vlSelfRef.tb_ozone_backend__DOT__cdb_broadcast[2U] = 0U;
            vlSelfRef.tb_ozone_backend__DOT__cdb_broadcast[3U] = 0U;
            vlSelfRef.tb_ozone_backend__DOT__cdb_broadcast[4U] = 0U;
        } else {
            vlSelfRef.tb_ozone_backend__DOT__cdb_broadcast[0U] = 0U;
            vlSelfRef.tb_ozone_backend__DOT__cdb_broadcast[1U] = 0U;
            vlSelfRef.tb_ozone_backend__DOT__cdb_broadcast[2U] = 0U;
            vlSelfRef.tb_ozone_backend__DOT__cdb_broadcast[3U] = 0U;
            vlSelfRef.tb_ozone_backend__DOT__cdb_broadcast[4U] = 0U;
        }
    } else if ((2U & (IData)(tb_ozone_backend__DOT__cdb__DOT__unnamedblk1__DOT__winner))) {
        if ((1U & (IData)(tb_ozone_backend__DOT__cdb__DOT__unnamedblk1__DOT__winner))) {
            vlSelfRef.tb_ozone_backend__DOT__cdb_broadcast[0U] = 0U;
            vlSelfRef.tb_ozone_backend__DOT__cdb_broadcast[1U] = 0U;
            vlSelfRef.tb_ozone_backend__DOT__cdb_broadcast[2U] = 0U;
            vlSelfRef.tb_ozone_backend__DOT__cdb_broadcast[3U] = 0U;
            vlSelfRef.tb_ozone_backend__DOT__cdb_broadcast[4U] = 0U;
        } else {
            vlSelfRef.tb_ozone_backend__DOT__cdb_broadcast[0U] 
                = vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__result[0U];
            vlSelfRef.tb_ozone_backend__DOT__cdb_broadcast[1U] 
                = vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__result[1U];
            vlSelfRef.tb_ozone_backend__DOT__cdb_broadcast[2U] 
                = vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__result[2U];
            vlSelfRef.tb_ozone_backend__DOT__cdb_broadcast[3U] 
                = vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__result[3U];
            vlSelfRef.tb_ozone_backend__DOT__cdb_broadcast[4U] 
                = vlSelfRef.tb_ozone_backend__DOT__logic_fu__DOT__result[4U];
            vlSelfRef.tb_ozone_backend__DOT__logic_granted = 1U;
        }
    } else if ((1U & (IData)(tb_ozone_backend__DOT__cdb__DOT__unnamedblk1__DOT__winner))) {
        vlSelfRef.tb_ozone_backend__DOT__cdb_broadcast[0U] 
            = vlSelfRef.tb_ozone_backend__DOT__adder__DOT__result[0U];
        vlSelfRef.tb_ozone_backend__DOT__cdb_broadcast[1U] 
            = vlSelfRef.tb_ozone_backend__DOT__adder__DOT__result[1U];
        vlSelfRef.tb_ozone_backend__DOT__cdb_broadcast[2U] 
            = vlSelfRef.tb_ozone_backend__DOT__adder__DOT__result[2U];
        vlSelfRef.tb_ozone_backend__DOT__cdb_broadcast[3U] 
            = vlSelfRef.tb_ozone_backend__DOT__adder__DOT__result[3U];
        vlSelfRef.tb_ozone_backend__DOT__cdb_broadcast[4U] 
            = vlSelfRef.tb_ozone_backend__DOT__adder__DOT__result[4U];
        vlSelfRef.tb_ozone_backend__DOT__adder_granted = 1U;
    } else {
        vlSelfRef.tb_ozone_backend__DOT__cdb_broadcast[0U] = 0U;
        vlSelfRef.tb_ozone_backend__DOT__cdb_broadcast[1U] = 0U;
        vlSelfRef.tb_ozone_backend__DOT__cdb_broadcast[2U] = 0U;
        vlSelfRef.tb_ozone_backend__DOT__cdb_broadcast[3U] = 0U;
        vlSelfRef.tb_ozone_backend__DOT__cdb_broadcast[4U] = 0U;
    }
    vlSelfRef.tb_ozone_backend__DOT__src1_value = (
                                                   ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__rob__DOT__rob_entries
                                                                    [vlSelfRef.tb_ozone_backend__DOT__src1_rob_idx][8U])) 
                                                    << 0x00000033U) 
                                                   | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__rob__DOT__rob_entries
                                                                       [vlSelfRef.tb_ozone_backend__DOT__src1_rob_idx][7U])) 
                                                       << 0x00000013U) 
                                                      | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__rob__DOT__rob_entries
                                                                         [vlSelfRef.tb_ozone_backend__DOT__src1_rob_idx][6U])) 
                                                         >> 0x0000000dU)));
    vlSelfRef.tb_ozone_backend__DOT__src2_value = (
                                                   ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__rob__DOT__rob_entries
                                                                    [vlSelfRef.tb_ozone_backend__DOT__src2_rob_idx][8U])) 
                                                    << 0x00000033U) 
                                                   | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__rob__DOT__rob_entries
                                                                       [vlSelfRef.tb_ozone_backend__DOT__src2_rob_idx][7U])) 
                                                       << 0x00000013U) 
                                                      | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__rob__DOT__rob_entries
                                                                         [vlSelfRef.tb_ozone_backend__DOT__src2_rob_idx][6U])) 
                                                         >> 0x0000000dU)));
    vlSelfRef.tb_ozone_backend__DOT__src2_ready = (1U 
                                                   & (vlSelfRef.tb_ozone_backend__DOT__rob__DOT__rob_entries
                                                      [vlSelfRef.tb_ozone_backend__DOT__src2_rob_idx][6U] 
                                                      >> 7U));
    if (((vlSelfRef.tb_ozone_backend__DOT__cdb_broadcast[4U] 
          >> 0x00000016U) & ((0x0000003fU & (vlSelfRef.tb_ozone_backend__DOT__cdb_broadcast[4U] 
                                             >> 0x00000010U)) 
                             == (IData)(vlSelfRef.tb_ozone_backend__DOT__src2_rob_idx)))) {
        vlSelfRef.tb_ozone_backend__DOT__src2_value 
            = (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__cdb_broadcast[4U])) 
                << 0x00000030U) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__cdb_broadcast[3U])) 
                                    << 0x00000010U) 
                                   | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__cdb_broadcast[2U])) 
                                      >> 0x00000010U)));
        vlSelfRef.tb_ozone_backend__DOT__src2_ready = 1U;
    }
    vlSelfRef.tb_ozone_backend__DOT__src1_ready = (1U 
                                                   & (vlSelfRef.tb_ozone_backend__DOT__rob__DOT__rob_entries
                                                      [vlSelfRef.tb_ozone_backend__DOT__src1_rob_idx][6U] 
                                                      >> 7U));
    if (((vlSelfRef.tb_ozone_backend__DOT__cdb_broadcast[4U] 
          >> 0x00000016U) & ((0x0000003fU & (vlSelfRef.tb_ozone_backend__DOT__cdb_broadcast[4U] 
                                             >> 0x00000010U)) 
                             == (IData)(vlSelfRef.tb_ozone_backend__DOT__src1_rob_idx)))) {
        vlSelfRef.tb_ozone_backend__DOT__src1_value 
            = (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__cdb_broadcast[4U])) 
                << 0x00000030U) | (((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__cdb_broadcast[3U])) 
                                    << 0x00000010U) 
                                   | ((QData)((IData)(vlSelfRef.tb_ozone_backend__DOT__cdb_broadcast[2U])) 
                                      >> 0x00000010U)));
        vlSelfRef.tb_ozone_backend__DOT__src1_ready = 1U;
    }
}

VL_ATTR_COLD void Vtb_ozone_backend___024root___eval_stl(Vtb_ozone_backend___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ozone_backend___024root___eval_stl\n"); );
    Vtb_ozone_backend__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered[0U])) {
        Vtb_ozone_backend___024root___stl_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD bool Vtb_ozone_backend___024root___eval_phase__stl(Vtb_ozone_backend___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ozone_backend___024root___eval_phase__stl\n"); );
    Vtb_ozone_backend__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtb_ozone_backend___024root___eval_triggers_vec__stl(vlSelf);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_ozone_backend___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vtb_ozone_backend___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        Vtb_ozone_backend___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

bool Vtb_ozone_backend___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_ozone_backend___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ozone_backend___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vtb_ozone_backend___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge tb_ozone_backend.clk)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(negedge tb_ozone_backend.rst_n)\n");
    }
    if ((1U & (IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
    if ((1U & (IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @(negedge tb_ozone_backend.clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_ozone_backend___024root___ctor_var_reset(Vtb_ozone_backend___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ozone_backend___024root___ctor_var_reset\n"); );
    Vtb_ozone_backend__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->tb_ozone_backend__DOT__clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11046589287069461668ull);
    vlSelf->tb_ozone_backend__DOT__rst_n = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6781087124684929126ull);
    vlSelf->tb_ozone_backend__DOT__src1_addr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 11168146042625881562ull);
    vlSelf->tb_ozone_backend__DOT__src2_addr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 1903625911441247940ull);
    VL_SCOPED_RAND_RESET_W(71, vlSelf->tb_ozone_backend__DOT__src1_status, __VscopeHash, 4008234054798283697ull);
    VL_SCOPED_RAND_RESET_W(71, vlSelf->tb_ozone_backend__DOT__src2_status, __VscopeHash, 4374055578097424999ull);
    vlSelf->tb_ozone_backend__DOT__disp_wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17517490934215132014ull);
    vlSelf->tb_ozone_backend__DOT__disp_wr_addr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 3347211894414530737ull);
    vlSelf->tb_ozone_backend__DOT__disp_rob_idx = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 5146362197334389606ull);
    vlSelf->tb_ozone_backend__DOT__disp_nzcv_wr_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14691205060191135274ull);
    vlSelf->tb_ozone_backend__DOT__disp_nzcv_rob_idx = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 14590531660017865259ull);
    vlSelf->tb_ozone_backend__DOT__src1_rob_idx = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 9187033253551543716ull);
    vlSelf->tb_ozone_backend__DOT__src2_rob_idx = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 12087269008610595504ull);
    vlSelf->tb_ozone_backend__DOT__src1_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14026918981395065124ull);
    vlSelf->tb_ozone_backend__DOT__src1_value = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 15150635704326251005ull);
    vlSelf->tb_ozone_backend__DOT__src2_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15845313212652364569ull);
    vlSelf->tb_ozone_backend__DOT__src2_value = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 11623203280475366598ull);
    vlSelf->tb_ozone_backend__DOT__rob_alloc_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 45097406949319728ull);
    vlSelf->tb_ozone_backend__DOT__alloc_has_dest = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2433501457959885958ull);
    VL_SCOPED_RAND_RESET_W(280, vlSelf->tb_ozone_backend__DOT__alloc_data, __VscopeHash, 12572624602266484903ull);
    vlSelf->tb_ozone_backend__DOT__commit_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15492745065624615778ull);
    vlSelf->tb_ozone_backend__DOT__commit_reg_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15567626567420018747ull);
    vlSelf->tb_ozone_backend__DOT__commit_reg_addr = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 64405600613891283ull);
    vlSelf->tb_ozone_backend__DOT__commit_reg_value = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 14144520039087869675ull);
    vlSelf->tb_ozone_backend__DOT__commit_nzcv_en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2786889478442463113ull);
    vlSelf->tb_ozone_backend__DOT__commit_nzcv_value = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 930089468878234701ull);
    vlSelf->tb_ozone_backend__DOT__adder_alloc_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 631618843548595063ull);
    VL_SCOPED_RAND_RESET_W(165, vlSelf->tb_ozone_backend__DOT__adder_alloc_entry, __VscopeHash, 6992912446506572251ull);
    vlSelf->tb_ozone_backend__DOT__adder_full = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6747051580419411336ull);
    vlSelf->tb_ozone_backend__DOT__adder_granted = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 227847606288345819ull);
    vlSelf->tb_ozone_backend__DOT__logic_alloc_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3671449590845243380ull);
    VL_SCOPED_RAND_RESET_W(159, vlSelf->tb_ozone_backend__DOT__logic_alloc_entry, __VscopeHash, 15110726258763704869ull);
    vlSelf->tb_ozone_backend__DOT__logic_full = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9285588370867218714ull);
    vlSelf->tb_ozone_backend__DOT__logic_granted = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 3874314517398457859ull);
    VL_SCOPED_RAND_RESET_W(151, vlSelf->tb_ozone_backend__DOT__cdb_broadcast, __VscopeHash, 4503679263541014240ull);
    vlSelf->tb_ozone_backend__DOT__regstate__DOT____Vlvbound_h6817daf0__0 = 0;
    vlSelf->tb_ozone_backend__DOT__regstate__DOT____Vlvbound_h687da136__0 = 0;
    vlSelf->tb_ozone_backend__DOT__regstate__DOT____Vlvbound_hc878112f__0 = 0;
    vlSelf->tb_ozone_backend__DOT__regstate__DOT____Vlvbound_h733992fd__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 31; ++__Vi0) {
        VL_SCOPED_RAND_RESET_W(71, vlSelf->tb_ozone_backend__DOT__regstate__DOT__gp_reg[__Vi0], __VscopeHash, 7242134015930662035ull);
    }
    VL_SCOPED_RAND_RESET_W(71, vlSelf->tb_ozone_backend__DOT__regstate__DOT__nzcv_reg, __VscopeHash, 6825844094615241139ull);
    for (int __Vi0 = 0; __Vi0 < 64; ++__Vi0) {
        VL_SCOPED_RAND_RESET_W(280, vlSelf->tb_ozone_backend__DOT__rob__DOT__rob_entries[__Vi0], __VscopeHash, 6649958237959581275ull);
    }
    vlSelf->tb_ozone_backend__DOT__rob__DOT__head = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 14192331468565020391ull);
    vlSelf->tb_ozone_backend__DOT__rob__DOT__tail = VL_SCOPED_RAND_RESET_I(6, __VscopeHash, 9093780523789537048ull);
    vlSelf->tb_ozone_backend__DOT__rob__DOT__count = VL_SCOPED_RAND_RESET_I(7, __VscopeHash, 3743251537708345781ull);
    vlSelf->tb_ozone_backend__DOT__rob__DOT__head_can_commit = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 2835322646877807332ull);
    vlSelf->tb_ozone_backend__DOT__rob__DOT__do_alloc = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 14628576982873691539ull);
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        VL_SCOPED_RAND_RESET_W(165, vlSelf->tb_ozone_backend__DOT__adder__DOT__entries[__Vi0], __VscopeHash, 10988686157122342829ull);
    }
    VL_SCOPED_RAND_RESET_W(151, vlSelf->tb_ozone_backend__DOT__adder__DOT__result, __VscopeHash, 2117296756689953916ull);
    vlSelf->tb_ozone_backend__DOT__adder__DOT__fu_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 1440740444093658007ull);
    vlSelf->tb_ozone_backend__DOT__adder__DOT__issue_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18318138047249501657ull);
    VL_SCOPED_RAND_RESET_W(165, vlSelf->tb_ozone_backend__DOT__adder__DOT__issue_entry, __VscopeHash, 16100923014717832264ull);
    vlSelf->tb_ozone_backend__DOT__adder__DOT__add_result = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 5333764998284903580ull);
    vlSelf->tb_ozone_backend__DOT__adder__DOT__add_value_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13751970478943483405ull);
    vlSelf->tb_ozone_backend__DOT__adder__DOT__add_nzcv = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 6869383164027015453ull);
    vlSelf->tb_ozone_backend__DOT__adder__DOT__add_flags_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17590639812406269200ull);
    vlSelf->tb_ozone_backend__DOT__adder__DOT__add_br_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12224808850980026695ull);
    vlSelf->tb_ozone_backend__DOT__adder__DOT__add_br_taken = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 13835471627067058017ull);
    vlSelf->tb_ozone_backend__DOT__adder__DOT__add_br_target = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 8987178514731911320ull);
    vlSelf->tb_ozone_backend__DOT__adder__DOT__unnamedblk5__DOT__i = 0;
    vlSelf->tb_ozone_backend__DOT__adder__DOT__unnamedblk6__DOT__i = 0;
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        VL_SCOPED_RAND_RESET_W(159, vlSelf->tb_ozone_backend__DOT__logic_fu__DOT__entries[__Vi0], __VscopeHash, 14956699073234419308ull);
    }
    VL_SCOPED_RAND_RESET_W(151, vlSelf->tb_ozone_backend__DOT__logic_fu__DOT__result, __VscopeHash, 1926796983350965830ull);
    vlSelf->tb_ozone_backend__DOT__logic_fu__DOT__fu_ready = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 4571485574679102921ull);
    vlSelf->tb_ozone_backend__DOT__logic_fu__DOT__issue_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10351827305461652001ull);
    VL_SCOPED_RAND_RESET_W(159, vlSelf->tb_ozone_backend__DOT__logic_fu__DOT__issue_entry, __VscopeHash, 13426234499449175591ull);
    vlSelf->tb_ozone_backend__DOT__logic_fu__DOT__logic_result = VL_SCOPED_RAND_RESET_Q(64, __VscopeHash, 10065791249436146596ull);
    vlSelf->tb_ozone_backend__DOT__logic_fu__DOT__logic_value_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17206484935852410521ull);
    vlSelf->tb_ozone_backend__DOT__logic_fu__DOT__logic_nzcv = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 144722631849119266ull);
    vlSelf->tb_ozone_backend__DOT__logic_fu__DOT__logic_flags_valid = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 12494234216626169310ull);
    vlSelf->tb_ozone_backend__DOT__logic_fu__DOT__unnamedblk5__DOT__i = 0;
    vlSelf->tb_ozone_backend__DOT__logic_fu__DOT__unnamedblk6__DOT__i = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VstlTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggeredAcc[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__tb_ozone_backend__DOT__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__tb_ozone_backend__DOT__rst_n__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
    vlSelf->__Vi = 0;
}
