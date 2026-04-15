// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_ozone_cdb.h for the primary calling header

#include "Vtb_ozone_cdb__pch.h"

VlCoroutine Vtb_ozone_cdb___024root___eval_initial__TOP__Vtiming__0(Vtb_ozone_cdb___024root* vlSelf);

void Vtb_ozone_cdb___024root___eval_initial(Vtb_ozone_cdb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ozone_cdb___024root___eval_initial\n"); );
    Vtb_ozone_cdb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtb_ozone_cdb___024root___eval_initial__TOP__Vtiming__0(vlSelf);
}

VlCoroutine Vtb_ozone_cdb___024root___eval_initial__TOP__Vtiming__0(Vtb_ozone_cdb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ozone_cdb___024root___eval_initial__TOP__Vtiming__0\n"); );
    Vtb_ozone_cdb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ tb_ozone_cdb__DOT__failures;
    tb_ozone_cdb__DOT__failures = 0;
    CData/*0:0*/ __Vtask_tb_ozone_cdb__DOT__check_bit__1__got;
    __Vtask_tb_ozone_cdb__DOT__check_bit__1__got = 0;
    CData/*0:0*/ __Vtask_tb_ozone_cdb__DOT__check_bit__1__expected;
    __Vtask_tb_ozone_cdb__DOT__check_bit__1__expected = 0;
    CData/*0:0*/ __Vtask_tb_ozone_cdb__DOT__check_bit__2__got;
    __Vtask_tb_ozone_cdb__DOT__check_bit__2__got = 0;
    CData/*0:0*/ __Vtask_tb_ozone_cdb__DOT__check_bit__2__expected;
    __Vtask_tb_ozone_cdb__DOT__check_bit__2__expected = 0;
    CData/*0:0*/ __Vtask_tb_ozone_cdb__DOT__check_bit__3__got;
    __Vtask_tb_ozone_cdb__DOT__check_bit__3__got = 0;
    CData/*0:0*/ __Vtask_tb_ozone_cdb__DOT__check_bit__3__expected;
    __Vtask_tb_ozone_cdb__DOT__check_bit__3__expected = 0;
    VlWide<5>/*150:0*/ __Vfunc_tb_ozone_cdb__DOT__make_req__4__Vfuncout;
    VL_ZERO_W(151, __Vfunc_tb_ozone_cdb__DOT__make_req__4__Vfuncout);
    CData/*5:0*/ __Vfunc_tb_ozone_cdb__DOT__make_req__4__tag;
    __Vfunc_tb_ozone_cdb__DOT__make_req__4__tag = 0;
    QData/*63:0*/ __Vfunc_tb_ozone_cdb__DOT__make_req__4__value;
    __Vfunc_tb_ozone_cdb__DOT__make_req__4__value = 0;
    VlWide<5>/*150:0*/ __Vfunc_tb_ozone_cdb__DOT__make_req__4__req;
    VL_ZERO_W(151, __Vfunc_tb_ozone_cdb__DOT__make_req__4__req);
    CData/*0:0*/ __Vtask_tb_ozone_cdb__DOT__check_bit__5__got;
    __Vtask_tb_ozone_cdb__DOT__check_bit__5__got = 0;
    CData/*0:0*/ __Vtask_tb_ozone_cdb__DOT__check_bit__5__expected;
    __Vtask_tb_ozone_cdb__DOT__check_bit__5__expected = 0;
    CData/*5:0*/ __Vtask_tb_ozone_cdb__DOT__check_tag__6__got;
    __Vtask_tb_ozone_cdb__DOT__check_tag__6__got = 0;
    CData/*5:0*/ __Vtask_tb_ozone_cdb__DOT__check_tag__6__expected;
    __Vtask_tb_ozone_cdb__DOT__check_tag__6__expected = 0;
    CData/*0:0*/ __Vtask_tb_ozone_cdb__DOT__check_bit__7__got;
    __Vtask_tb_ozone_cdb__DOT__check_bit__7__got = 0;
    CData/*0:0*/ __Vtask_tb_ozone_cdb__DOT__check_bit__7__expected;
    __Vtask_tb_ozone_cdb__DOT__check_bit__7__expected = 0;
    CData/*0:0*/ __Vtask_tb_ozone_cdb__DOT__check_bit__8__got;
    __Vtask_tb_ozone_cdb__DOT__check_bit__8__got = 0;
    CData/*0:0*/ __Vtask_tb_ozone_cdb__DOT__check_bit__8__expected;
    __Vtask_tb_ozone_cdb__DOT__check_bit__8__expected = 0;
    VlWide<5>/*150:0*/ __Vfunc_tb_ozone_cdb__DOT__make_req__10__Vfuncout;
    VL_ZERO_W(151, __Vfunc_tb_ozone_cdb__DOT__make_req__10__Vfuncout);
    CData/*5:0*/ __Vfunc_tb_ozone_cdb__DOT__make_req__10__tag;
    __Vfunc_tb_ozone_cdb__DOT__make_req__10__tag = 0;
    QData/*63:0*/ __Vfunc_tb_ozone_cdb__DOT__make_req__10__value;
    __Vfunc_tb_ozone_cdb__DOT__make_req__10__value = 0;
    VlWide<5>/*150:0*/ __Vfunc_tb_ozone_cdb__DOT__make_req__10__req;
    VL_ZERO_W(151, __Vfunc_tb_ozone_cdb__DOT__make_req__10__req);
    VlWide<5>/*150:0*/ __Vfunc_tb_ozone_cdb__DOT__make_req__11__Vfuncout;
    VL_ZERO_W(151, __Vfunc_tb_ozone_cdb__DOT__make_req__11__Vfuncout);
    CData/*5:0*/ __Vfunc_tb_ozone_cdb__DOT__make_req__11__tag;
    __Vfunc_tb_ozone_cdb__DOT__make_req__11__tag = 0;
    QData/*63:0*/ __Vfunc_tb_ozone_cdb__DOT__make_req__11__value;
    __Vfunc_tb_ozone_cdb__DOT__make_req__11__value = 0;
    VlWide<5>/*150:0*/ __Vfunc_tb_ozone_cdb__DOT__make_req__11__req;
    VL_ZERO_W(151, __Vfunc_tb_ozone_cdb__DOT__make_req__11__req);
    CData/*5:0*/ __Vtask_tb_ozone_cdb__DOT__check_tag__12__got;
    __Vtask_tb_ozone_cdb__DOT__check_tag__12__got = 0;
    CData/*5:0*/ __Vtask_tb_ozone_cdb__DOT__check_tag__12__expected;
    __Vtask_tb_ozone_cdb__DOT__check_tag__12__expected = 0;
    CData/*0:0*/ __Vtask_tb_ozone_cdb__DOT__check_bit__13__got;
    __Vtask_tb_ozone_cdb__DOT__check_bit__13__got = 0;
    CData/*0:0*/ __Vtask_tb_ozone_cdb__DOT__check_bit__13__expected;
    __Vtask_tb_ozone_cdb__DOT__check_bit__13__expected = 0;
    CData/*0:0*/ __Vtask_tb_ozone_cdb__DOT__check_bit__14__got;
    __Vtask_tb_ozone_cdb__DOT__check_bit__14__got = 0;
    CData/*0:0*/ __Vtask_tb_ozone_cdb__DOT__check_bit__14__expected;
    __Vtask_tb_ozone_cdb__DOT__check_bit__14__expected = 0;
    VlWide<5>/*150:0*/ __Vfunc_tb_ozone_cdb__DOT__make_req__16__Vfuncout;
    VL_ZERO_W(151, __Vfunc_tb_ozone_cdb__DOT__make_req__16__Vfuncout);
    CData/*5:0*/ __Vfunc_tb_ozone_cdb__DOT__make_req__16__tag;
    __Vfunc_tb_ozone_cdb__DOT__make_req__16__tag = 0;
    QData/*63:0*/ __Vfunc_tb_ozone_cdb__DOT__make_req__16__value;
    __Vfunc_tb_ozone_cdb__DOT__make_req__16__value = 0;
    VlWide<5>/*150:0*/ __Vfunc_tb_ozone_cdb__DOT__make_req__16__req;
    VL_ZERO_W(151, __Vfunc_tb_ozone_cdb__DOT__make_req__16__req);
    VlWide<5>/*150:0*/ __Vfunc_tb_ozone_cdb__DOT__make_req__17__Vfuncout;
    VL_ZERO_W(151, __Vfunc_tb_ozone_cdb__DOT__make_req__17__Vfuncout);
    CData/*5:0*/ __Vfunc_tb_ozone_cdb__DOT__make_req__17__tag;
    __Vfunc_tb_ozone_cdb__DOT__make_req__17__tag = 0;
    QData/*63:0*/ __Vfunc_tb_ozone_cdb__DOT__make_req__17__value;
    __Vfunc_tb_ozone_cdb__DOT__make_req__17__value = 0;
    VlWide<5>/*150:0*/ __Vfunc_tb_ozone_cdb__DOT__make_req__17__req;
    VL_ZERO_W(151, __Vfunc_tb_ozone_cdb__DOT__make_req__17__req);
    CData/*5:0*/ __Vtask_tb_ozone_cdb__DOT__check_tag__18__got;
    __Vtask_tb_ozone_cdb__DOT__check_tag__18__got = 0;
    CData/*5:0*/ __Vtask_tb_ozone_cdb__DOT__check_tag__18__expected;
    __Vtask_tb_ozone_cdb__DOT__check_tag__18__expected = 0;
    CData/*0:0*/ __Vtask_tb_ozone_cdb__DOT__check_bit__19__got;
    __Vtask_tb_ozone_cdb__DOT__check_bit__19__got = 0;
    CData/*0:0*/ __Vtask_tb_ozone_cdb__DOT__check_bit__19__expected;
    __Vtask_tb_ozone_cdb__DOT__check_bit__19__expected = 0;
    CData/*0:0*/ __Vtask_tb_ozone_cdb__DOT__check_bit__20__got;
    __Vtask_tb_ozone_cdb__DOT__check_bit__20__got = 0;
    CData/*0:0*/ __Vtask_tb_ozone_cdb__DOT__check_bit__20__expected;
    __Vtask_tb_ozone_cdb__DOT__check_bit__20__expected = 0;
    VlWide<5>/*150:0*/ __Vfunc_tb_ozone_cdb__DOT__make_req__22__Vfuncout;
    VL_ZERO_W(151, __Vfunc_tb_ozone_cdb__DOT__make_req__22__Vfuncout);
    CData/*5:0*/ __Vfunc_tb_ozone_cdb__DOT__make_req__22__tag;
    __Vfunc_tb_ozone_cdb__DOT__make_req__22__tag = 0;
    QData/*63:0*/ __Vfunc_tb_ozone_cdb__DOT__make_req__22__value;
    __Vfunc_tb_ozone_cdb__DOT__make_req__22__value = 0;
    VlWide<5>/*150:0*/ __Vfunc_tb_ozone_cdb__DOT__make_req__22__req;
    VL_ZERO_W(151, __Vfunc_tb_ozone_cdb__DOT__make_req__22__req);
    VlWide<5>/*150:0*/ __Vfunc_tb_ozone_cdb__DOT__make_req__23__Vfuncout;
    VL_ZERO_W(151, __Vfunc_tb_ozone_cdb__DOT__make_req__23__Vfuncout);
    CData/*5:0*/ __Vfunc_tb_ozone_cdb__DOT__make_req__23__tag;
    __Vfunc_tb_ozone_cdb__DOT__make_req__23__tag = 0;
    QData/*63:0*/ __Vfunc_tb_ozone_cdb__DOT__make_req__23__value;
    __Vfunc_tb_ozone_cdb__DOT__make_req__23__value = 0;
    VlWide<5>/*150:0*/ __Vfunc_tb_ozone_cdb__DOT__make_req__23__req;
    VL_ZERO_W(151, __Vfunc_tb_ozone_cdb__DOT__make_req__23__req);
    VlWide<5>/*150:0*/ __Vfunc_tb_ozone_cdb__DOT__make_req__24__Vfuncout;
    VL_ZERO_W(151, __Vfunc_tb_ozone_cdb__DOT__make_req__24__Vfuncout);
    CData/*5:0*/ __Vfunc_tb_ozone_cdb__DOT__make_req__24__tag;
    __Vfunc_tb_ozone_cdb__DOT__make_req__24__tag = 0;
    QData/*63:0*/ __Vfunc_tb_ozone_cdb__DOT__make_req__24__value;
    __Vfunc_tb_ozone_cdb__DOT__make_req__24__value = 0;
    VlWide<5>/*150:0*/ __Vfunc_tb_ozone_cdb__DOT__make_req__24__req;
    VL_ZERO_W(151, __Vfunc_tb_ozone_cdb__DOT__make_req__24__req);
    VlWide<5>/*150:0*/ __Vfunc_tb_ozone_cdb__DOT__make_req__25__Vfuncout;
    VL_ZERO_W(151, __Vfunc_tb_ozone_cdb__DOT__make_req__25__Vfuncout);
    CData/*5:0*/ __Vfunc_tb_ozone_cdb__DOT__make_req__25__tag;
    __Vfunc_tb_ozone_cdb__DOT__make_req__25__tag = 0;
    QData/*63:0*/ __Vfunc_tb_ozone_cdb__DOT__make_req__25__value;
    __Vfunc_tb_ozone_cdb__DOT__make_req__25__value = 0;
    VlWide<5>/*150:0*/ __Vfunc_tb_ozone_cdb__DOT__make_req__25__req;
    VL_ZERO_W(151, __Vfunc_tb_ozone_cdb__DOT__make_req__25__req);
    CData/*5:0*/ __Vtask_tb_ozone_cdb__DOT__check_tag__26__got;
    __Vtask_tb_ozone_cdb__DOT__check_tag__26__got = 0;
    CData/*5:0*/ __Vtask_tb_ozone_cdb__DOT__check_tag__26__expected;
    __Vtask_tb_ozone_cdb__DOT__check_tag__26__expected = 0;
    CData/*0:0*/ __Vtask_tb_ozone_cdb__DOT__check_bit__27__got;
    __Vtask_tb_ozone_cdb__DOT__check_bit__27__got = 0;
    CData/*0:0*/ __Vtask_tb_ozone_cdb__DOT__check_bit__27__expected;
    __Vtask_tb_ozone_cdb__DOT__check_bit__27__expected = 0;
    CData/*0:0*/ __Vtask_tb_ozone_cdb__DOT__check_bit__28__got;
    __Vtask_tb_ozone_cdb__DOT__check_bit__28__got = 0;
    CData/*0:0*/ __Vtask_tb_ozone_cdb__DOT__check_bit__28__expected;
    __Vtask_tb_ozone_cdb__DOT__check_bit__28__expected = 0;
    CData/*0:0*/ __Vtask_tb_ozone_cdb__DOT__check_bit__29__got;
    __Vtask_tb_ozone_cdb__DOT__check_bit__29__got = 0;
    CData/*0:0*/ __Vtask_tb_ozone_cdb__DOT__check_bit__29__expected;
    __Vtask_tb_ozone_cdb__DOT__check_bit__29__expected = 0;
    CData/*0:0*/ __Vtask_tb_ozone_cdb__DOT__check_bit__30__got;
    __Vtask_tb_ozone_cdb__DOT__check_bit__30__got = 0;
    CData/*0:0*/ __Vtask_tb_ozone_cdb__DOT__check_bit__30__expected;
    __Vtask_tb_ozone_cdb__DOT__check_bit__30__expected = 0;
    // Body
    tb_ozone_cdb__DOT__failures = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__adder_req[0U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__adder_req[1U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__adder_req[2U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__adder_req[3U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__adder_req[4U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__logic_req[0U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__logic_req[1U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__logic_req[2U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__logic_req[3U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__logic_req[4U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__fpu_req[0U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__fpu_req[1U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__fpu_req[2U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__fpu_req[3U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__fpu_req[4U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__mem_req[0U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__mem_req[1U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__mem_req[2U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__mem_req[3U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__mem_req[4U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__rob_head = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_ozone_backend.sv", 
                                         53);
    vlSelfRef.__Vtask_tb_ozone_cdb__DOT__check_bit__1__label = "idle cdb valid"s;
    __Vtask_tb_ozone_cdb__DOT__check_bit__1__expected = 0U;
    __Vtask_tb_ozone_cdb__DOT__check_bit__1__got = 
        (1U & (vlSelfRef.tb_ozone_cdb__DOT__cdb_broadcast[4U] 
               >> 0x00000016U));
    if (VL_UNLIKELY((((IData)(__Vtask_tb_ozone_cdb__DOT__check_bit__1__got) 
                      != (IData)(__Vtask_tb_ozone_cdb__DOT__check_bit__1__expected))))) {
        tb_ozone_cdb__DOT__failures = ((IData)(1U) 
                                       + tb_ozone_cdb__DOT__failures);
        VL_WRITEF_NX("[FAIL] %@ expected=%0b got=%0b\n",0,
                     -1,&(vlSelfRef.__Vtask_tb_ozone_cdb__DOT__check_bit__1__label),
                     1,(IData)(__Vtask_tb_ozone_cdb__DOT__check_bit__1__expected),
                     1,__Vtask_tb_ozone_cdb__DOT__check_bit__1__got);
    }
    vlSelfRef.__Vtask_tb_ozone_cdb__DOT__check_bit__2__label = "idle adder grant"s;
    __Vtask_tb_ozone_cdb__DOT__check_bit__2__expected = 0U;
    __Vtask_tb_ozone_cdb__DOT__check_bit__2__got = vlSelfRef.tb_ozone_cdb__DOT__adder_granted;
    if (VL_UNLIKELY((((IData)(__Vtask_tb_ozone_cdb__DOT__check_bit__2__got) 
                      != (IData)(__Vtask_tb_ozone_cdb__DOT__check_bit__2__expected))))) {
        tb_ozone_cdb__DOT__failures = ((IData)(1U) 
                                       + tb_ozone_cdb__DOT__failures);
        VL_WRITEF_NX("[FAIL] %@ expected=%0b got=%0b\n",0,
                     -1,&(vlSelfRef.__Vtask_tb_ozone_cdb__DOT__check_bit__2__label),
                     1,(IData)(__Vtask_tb_ozone_cdb__DOT__check_bit__2__expected),
                     1,__Vtask_tb_ozone_cdb__DOT__check_bit__2__got);
    }
    vlSelfRef.__Vtask_tb_ozone_cdb__DOT__check_bit__3__label = "idle logic grant"s;
    __Vtask_tb_ozone_cdb__DOT__check_bit__3__expected = 0U;
    __Vtask_tb_ozone_cdb__DOT__check_bit__3__got = vlSelfRef.tb_ozone_cdb__DOT__logic_granted;
    if (VL_UNLIKELY((((IData)(__Vtask_tb_ozone_cdb__DOT__check_bit__3__got) 
                      != (IData)(__Vtask_tb_ozone_cdb__DOT__check_bit__3__expected))))) {
        tb_ozone_cdb__DOT__failures = ((IData)(1U) 
                                       + tb_ozone_cdb__DOT__failures);
        VL_WRITEF_NX("[FAIL] %@ expected=%0b got=%0b\n",0,
                     -1,&(vlSelfRef.__Vtask_tb_ozone_cdb__DOT__check_bit__3__label),
                     1,(IData)(__Vtask_tb_ozone_cdb__DOT__check_bit__3__expected),
                     1,__Vtask_tb_ozone_cdb__DOT__check_bit__3__got);
    }
    __Vfunc_tb_ozone_cdb__DOT__make_req__4__value = 0x0000000000000055ULL;
    __Vfunc_tb_ozone_cdb__DOT__make_req__4__tag = 5U;
    VL_ZERO_W(151, __Vfunc_tb_ozone_cdb__DOT__make_req__4__Vfuncout);
    VL_ZERO_W(151, __Vfunc_tb_ozone_cdb__DOT__make_req__4__req);
    __Vfunc_tb_ozone_cdb__DOT__make_req__4__req[0U] = 0U;
    __Vfunc_tb_ozone_cdb__DOT__make_req__4__req[1U] = 0U;
    __Vfunc_tb_ozone_cdb__DOT__make_req__4__req[2U] = 0U;
    __Vfunc_tb_ozone_cdb__DOT__make_req__4__req[3U] = 0U;
    __Vfunc_tb_ozone_cdb__DOT__make_req__4__req[4U] = 0U;
    __Vfunc_tb_ozone_cdb__DOT__make_req__4__req[2U] 
        = ((0x0000ffffU & __Vfunc_tb_ozone_cdb__DOT__make_req__4__req[2U]) 
           | ((IData)(__Vfunc_tb_ozone_cdb__DOT__make_req__4__value) 
              << 0x00000010U));
    __Vfunc_tb_ozone_cdb__DOT__make_req__4__req[3U] 
        = (((IData)(__Vfunc_tb_ozone_cdb__DOT__make_req__4__value) 
            >> 0x00000010U) | ((IData)((__Vfunc_tb_ozone_cdb__DOT__make_req__4__value 
                                        >> 0x00000020U)) 
                               << 0x00000010U));
    __Vfunc_tb_ozone_cdb__DOT__make_req__4__req[4U] 
        = (0x007fffffU & (0x00400000U | (((IData)((__Vfunc_tb_ozone_cdb__DOT__make_req__4__value 
                                                   >> 0x00000020U)) 
                                          >> 0x00000010U) 
                                         | ((IData)(__Vfunc_tb_ozone_cdb__DOT__make_req__4__tag) 
                                            << 0x00000010U))));
    __Vfunc_tb_ozone_cdb__DOT__make_req__4__Vfuncout[0U] 
        = __Vfunc_tb_ozone_cdb__DOT__make_req__4__req[0U];
    __Vfunc_tb_ozone_cdb__DOT__make_req__4__Vfuncout[1U] 
        = __Vfunc_tb_ozone_cdb__DOT__make_req__4__req[1U];
    __Vfunc_tb_ozone_cdb__DOT__make_req__4__Vfuncout[2U] 
        = __Vfunc_tb_ozone_cdb__DOT__make_req__4__req[2U];
    __Vfunc_tb_ozone_cdb__DOT__make_req__4__Vfuncout[3U] 
        = __Vfunc_tb_ozone_cdb__DOT__make_req__4__req[3U];
    __Vfunc_tb_ozone_cdb__DOT__make_req__4__Vfuncout[4U] 
        = __Vfunc_tb_ozone_cdb__DOT__make_req__4__req[4U];
    vlSelfRef.tb_ozone_cdb__DOT__adder_req[0U] = __Vfunc_tb_ozone_cdb__DOT__make_req__4__Vfuncout[0U];
    vlSelfRef.tb_ozone_cdb__DOT__adder_req[1U] = __Vfunc_tb_ozone_cdb__DOT__make_req__4__Vfuncout[1U];
    vlSelfRef.tb_ozone_cdb__DOT__adder_req[2U] = __Vfunc_tb_ozone_cdb__DOT__make_req__4__Vfuncout[2U];
    vlSelfRef.tb_ozone_cdb__DOT__adder_req[3U] = __Vfunc_tb_ozone_cdb__DOT__make_req__4__Vfuncout[3U];
    vlSelfRef.tb_ozone_cdb__DOT__adder_req[4U] = __Vfunc_tb_ozone_cdb__DOT__make_req__4__Vfuncout[4U];
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_ozone_backend.sv", 
                                         94);
    vlSelfRef.__Vtask_tb_ozone_cdb__DOT__check_bit__5__label = "single winner valid"s;
    __Vtask_tb_ozone_cdb__DOT__check_bit__5__expected = 1U;
    __Vtask_tb_ozone_cdb__DOT__check_bit__5__got = 
        (1U & (vlSelfRef.tb_ozone_cdb__DOT__cdb_broadcast[4U] 
               >> 0x00000016U));
    if (VL_UNLIKELY((((IData)(__Vtask_tb_ozone_cdb__DOT__check_bit__5__got) 
                      != (IData)(__Vtask_tb_ozone_cdb__DOT__check_bit__5__expected))))) {
        tb_ozone_cdb__DOT__failures = ((IData)(1U) 
                                       + tb_ozone_cdb__DOT__failures);
        VL_WRITEF_NX("[FAIL] %@ expected=%0b got=%0b\n",0,
                     -1,&(vlSelfRef.__Vtask_tb_ozone_cdb__DOT__check_bit__5__label),
                     1,(IData)(__Vtask_tb_ozone_cdb__DOT__check_bit__5__expected),
                     1,__Vtask_tb_ozone_cdb__DOT__check_bit__5__got);
    }
    vlSelfRef.__Vtask_tb_ozone_cdb__DOT__check_tag__6__label = "single winner tag"s;
    __Vtask_tb_ozone_cdb__DOT__check_tag__6__expected = 5U;
    __Vtask_tb_ozone_cdb__DOT__check_tag__6__got = 
        (0x0000003fU & (vlSelfRef.tb_ozone_cdb__DOT__cdb_broadcast[4U] 
                        >> 0x00000010U));
    if (VL_UNLIKELY((((IData)(__Vtask_tb_ozone_cdb__DOT__check_tag__6__got) 
                      != (IData)(__Vtask_tb_ozone_cdb__DOT__check_tag__6__expected))))) {
        tb_ozone_cdb__DOT__failures = ((IData)(1U) 
                                       + tb_ozone_cdb__DOT__failures);
        VL_WRITEF_NX("[FAIL] %@ expected tag=%0# got=%0#\n",0,
                     -1,&(vlSelfRef.__Vtask_tb_ozone_cdb__DOT__check_tag__6__label),
                     6,(IData)(__Vtask_tb_ozone_cdb__DOT__check_tag__6__expected),
                     6,__Vtask_tb_ozone_cdb__DOT__check_tag__6__got);
    }
    vlSelfRef.__Vtask_tb_ozone_cdb__DOT__check_bit__7__label = "single adder grant"s;
    __Vtask_tb_ozone_cdb__DOT__check_bit__7__expected = 1U;
    __Vtask_tb_ozone_cdb__DOT__check_bit__7__got = vlSelfRef.tb_ozone_cdb__DOT__adder_granted;
    if (VL_UNLIKELY((((IData)(__Vtask_tb_ozone_cdb__DOT__check_bit__7__got) 
                      != (IData)(__Vtask_tb_ozone_cdb__DOT__check_bit__7__expected))))) {
        tb_ozone_cdb__DOT__failures = ((IData)(1U) 
                                       + tb_ozone_cdb__DOT__failures);
        VL_WRITEF_NX("[FAIL] %@ expected=%0b got=%0b\n",0,
                     -1,&(vlSelfRef.__Vtask_tb_ozone_cdb__DOT__check_bit__7__label),
                     1,(IData)(__Vtask_tb_ozone_cdb__DOT__check_bit__7__expected),
                     1,__Vtask_tb_ozone_cdb__DOT__check_bit__7__got);
    }
    vlSelfRef.__Vtask_tb_ozone_cdb__DOT__check_bit__8__label = "single logic grant"s;
    __Vtask_tb_ozone_cdb__DOT__check_bit__8__expected = 0U;
    __Vtask_tb_ozone_cdb__DOT__check_bit__8__got = vlSelfRef.tb_ozone_cdb__DOT__logic_granted;
    if (VL_UNLIKELY((((IData)(__Vtask_tb_ozone_cdb__DOT__check_bit__8__got) 
                      != (IData)(__Vtask_tb_ozone_cdb__DOT__check_bit__8__expected))))) {
        tb_ozone_cdb__DOT__failures = ((IData)(1U) 
                                       + tb_ozone_cdb__DOT__failures);
        VL_WRITEF_NX("[FAIL] %@ expected=%0b got=%0b\n",0,
                     -1,&(vlSelfRef.__Vtask_tb_ozone_cdb__DOT__check_bit__8__label),
                     1,(IData)(__Vtask_tb_ozone_cdb__DOT__check_bit__8__expected),
                     1,__Vtask_tb_ozone_cdb__DOT__check_bit__8__got);
    }
    vlSelfRef.tb_ozone_cdb__DOT__adder_req[0U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__adder_req[1U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__adder_req[2U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__adder_req[3U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__adder_req[4U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__logic_req[0U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__logic_req[1U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__logic_req[2U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__logic_req[3U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__logic_req[4U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__fpu_req[0U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__fpu_req[1U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__fpu_req[2U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__fpu_req[3U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__fpu_req[4U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__mem_req[0U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__mem_req[1U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__mem_req[2U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__mem_req[3U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__mem_req[4U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__rob_head = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_ozone_backend.sv", 
                                         53);
    vlSelfRef.tb_ozone_cdb__DOT__rob_head = 0x0aU;
    __Vfunc_tb_ozone_cdb__DOT__make_req__10__value = 0x0000000000000012ULL;
    __Vfunc_tb_ozone_cdb__DOT__make_req__10__tag = 0x0cU;
    VL_ZERO_W(151, __Vfunc_tb_ozone_cdb__DOT__make_req__10__Vfuncout);
    VL_ZERO_W(151, __Vfunc_tb_ozone_cdb__DOT__make_req__10__req);
    __Vfunc_tb_ozone_cdb__DOT__make_req__10__req[0U] = 0U;
    __Vfunc_tb_ozone_cdb__DOT__make_req__10__req[1U] = 0U;
    __Vfunc_tb_ozone_cdb__DOT__make_req__10__req[2U] = 0U;
    __Vfunc_tb_ozone_cdb__DOT__make_req__10__req[3U] = 0U;
    __Vfunc_tb_ozone_cdb__DOT__make_req__10__req[4U] = 0U;
    __Vfunc_tb_ozone_cdb__DOT__make_req__10__req[2U] 
        = ((0x0000ffffU & __Vfunc_tb_ozone_cdb__DOT__make_req__10__req[2U]) 
           | ((IData)(__Vfunc_tb_ozone_cdb__DOT__make_req__10__value) 
              << 0x00000010U));
    __Vfunc_tb_ozone_cdb__DOT__make_req__10__req[3U] 
        = (((IData)(__Vfunc_tb_ozone_cdb__DOT__make_req__10__value) 
            >> 0x00000010U) | ((IData)((__Vfunc_tb_ozone_cdb__DOT__make_req__10__value 
                                        >> 0x00000020U)) 
                               << 0x00000010U));
    __Vfunc_tb_ozone_cdb__DOT__make_req__10__req[4U] 
        = (0x007fffffU & (0x00400000U | (((IData)((__Vfunc_tb_ozone_cdb__DOT__make_req__10__value 
                                                   >> 0x00000020U)) 
                                          >> 0x00000010U) 
                                         | ((IData)(__Vfunc_tb_ozone_cdb__DOT__make_req__10__tag) 
                                            << 0x00000010U))));
    __Vfunc_tb_ozone_cdb__DOT__make_req__10__Vfuncout[0U] 
        = __Vfunc_tb_ozone_cdb__DOT__make_req__10__req[0U];
    __Vfunc_tb_ozone_cdb__DOT__make_req__10__Vfuncout[1U] 
        = __Vfunc_tb_ozone_cdb__DOT__make_req__10__req[1U];
    __Vfunc_tb_ozone_cdb__DOT__make_req__10__Vfuncout[2U] 
        = __Vfunc_tb_ozone_cdb__DOT__make_req__10__req[2U];
    __Vfunc_tb_ozone_cdb__DOT__make_req__10__Vfuncout[3U] 
        = __Vfunc_tb_ozone_cdb__DOT__make_req__10__req[3U];
    __Vfunc_tb_ozone_cdb__DOT__make_req__10__Vfuncout[4U] 
        = __Vfunc_tb_ozone_cdb__DOT__make_req__10__req[4U];
    vlSelfRef.tb_ozone_cdb__DOT__adder_req[0U] = __Vfunc_tb_ozone_cdb__DOT__make_req__10__Vfuncout[0U];
    vlSelfRef.tb_ozone_cdb__DOT__adder_req[1U] = __Vfunc_tb_ozone_cdb__DOT__make_req__10__Vfuncout[1U];
    vlSelfRef.tb_ozone_cdb__DOT__adder_req[2U] = __Vfunc_tb_ozone_cdb__DOT__make_req__10__Vfuncout[2U];
    vlSelfRef.tb_ozone_cdb__DOT__adder_req[3U] = __Vfunc_tb_ozone_cdb__DOT__make_req__10__Vfuncout[3U];
    vlSelfRef.tb_ozone_cdb__DOT__adder_req[4U] = __Vfunc_tb_ozone_cdb__DOT__make_req__10__Vfuncout[4U];
    __Vfunc_tb_ozone_cdb__DOT__make_req__11__value = 0x0000000000000011ULL;
    __Vfunc_tb_ozone_cdb__DOT__make_req__11__tag = 0x0bU;
    VL_ZERO_W(151, __Vfunc_tb_ozone_cdb__DOT__make_req__11__Vfuncout);
    VL_ZERO_W(151, __Vfunc_tb_ozone_cdb__DOT__make_req__11__req);
    __Vfunc_tb_ozone_cdb__DOT__make_req__11__req[0U] = 0U;
    __Vfunc_tb_ozone_cdb__DOT__make_req__11__req[1U] = 0U;
    __Vfunc_tb_ozone_cdb__DOT__make_req__11__req[2U] = 0U;
    __Vfunc_tb_ozone_cdb__DOT__make_req__11__req[3U] = 0U;
    __Vfunc_tb_ozone_cdb__DOT__make_req__11__req[4U] = 0U;
    __Vfunc_tb_ozone_cdb__DOT__make_req__11__req[2U] 
        = ((0x0000ffffU & __Vfunc_tb_ozone_cdb__DOT__make_req__11__req[2U]) 
           | ((IData)(__Vfunc_tb_ozone_cdb__DOT__make_req__11__value) 
              << 0x00000010U));
    __Vfunc_tb_ozone_cdb__DOT__make_req__11__req[3U] 
        = (((IData)(__Vfunc_tb_ozone_cdb__DOT__make_req__11__value) 
            >> 0x00000010U) | ((IData)((__Vfunc_tb_ozone_cdb__DOT__make_req__11__value 
                                        >> 0x00000020U)) 
                               << 0x00000010U));
    __Vfunc_tb_ozone_cdb__DOT__make_req__11__req[4U] 
        = (0x007fffffU & (0x00400000U | (((IData)((__Vfunc_tb_ozone_cdb__DOT__make_req__11__value 
                                                   >> 0x00000020U)) 
                                          >> 0x00000010U) 
                                         | ((IData)(__Vfunc_tb_ozone_cdb__DOT__make_req__11__tag) 
                                            << 0x00000010U))));
    __Vfunc_tb_ozone_cdb__DOT__make_req__11__Vfuncout[0U] 
        = __Vfunc_tb_ozone_cdb__DOT__make_req__11__req[0U];
    __Vfunc_tb_ozone_cdb__DOT__make_req__11__Vfuncout[1U] 
        = __Vfunc_tb_ozone_cdb__DOT__make_req__11__req[1U];
    __Vfunc_tb_ozone_cdb__DOT__make_req__11__Vfuncout[2U] 
        = __Vfunc_tb_ozone_cdb__DOT__make_req__11__req[2U];
    __Vfunc_tb_ozone_cdb__DOT__make_req__11__Vfuncout[3U] 
        = __Vfunc_tb_ozone_cdb__DOT__make_req__11__req[3U];
    __Vfunc_tb_ozone_cdb__DOT__make_req__11__Vfuncout[4U] 
        = __Vfunc_tb_ozone_cdb__DOT__make_req__11__req[4U];
    vlSelfRef.tb_ozone_cdb__DOT__logic_req[0U] = __Vfunc_tb_ozone_cdb__DOT__make_req__11__Vfuncout[0U];
    vlSelfRef.tb_ozone_cdb__DOT__logic_req[1U] = __Vfunc_tb_ozone_cdb__DOT__make_req__11__Vfuncout[1U];
    vlSelfRef.tb_ozone_cdb__DOT__logic_req[2U] = __Vfunc_tb_ozone_cdb__DOT__make_req__11__Vfuncout[2U];
    vlSelfRef.tb_ozone_cdb__DOT__logic_req[3U] = __Vfunc_tb_ozone_cdb__DOT__make_req__11__Vfuncout[3U];
    vlSelfRef.tb_ozone_cdb__DOT__logic_req[4U] = __Vfunc_tb_ozone_cdb__DOT__make_req__11__Vfuncout[4U];
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_ozone_backend.sv", 
                                         105);
    vlSelfRef.__Vtask_tb_ozone_cdb__DOT__check_tag__12__label = "age compare winner"s;
    __Vtask_tb_ozone_cdb__DOT__check_tag__12__expected = 0x0bU;
    __Vtask_tb_ozone_cdb__DOT__check_tag__12__got = 
        (0x0000003fU & (vlSelfRef.tb_ozone_cdb__DOT__cdb_broadcast[4U] 
                        >> 0x00000010U));
    if (VL_UNLIKELY((((IData)(__Vtask_tb_ozone_cdb__DOT__check_tag__12__got) 
                      != (IData)(__Vtask_tb_ozone_cdb__DOT__check_tag__12__expected))))) {
        tb_ozone_cdb__DOT__failures = ((IData)(1U) 
                                       + tb_ozone_cdb__DOT__failures);
        VL_WRITEF_NX("[FAIL] %@ expected tag=%0# got=%0#\n",0,
                     -1,&(vlSelfRef.__Vtask_tb_ozone_cdb__DOT__check_tag__12__label),
                     6,(IData)(__Vtask_tb_ozone_cdb__DOT__check_tag__12__expected),
                     6,__Vtask_tb_ozone_cdb__DOT__check_tag__12__got);
    }
    vlSelfRef.__Vtask_tb_ozone_cdb__DOT__check_bit__13__label = "age compare logic grant"s;
    __Vtask_tb_ozone_cdb__DOT__check_bit__13__expected = 1U;
    __Vtask_tb_ozone_cdb__DOT__check_bit__13__got = vlSelfRef.tb_ozone_cdb__DOT__logic_granted;
    if (VL_UNLIKELY((((IData)(__Vtask_tb_ozone_cdb__DOT__check_bit__13__got) 
                      != (IData)(__Vtask_tb_ozone_cdb__DOT__check_bit__13__expected))))) {
        tb_ozone_cdb__DOT__failures = ((IData)(1U) 
                                       + tb_ozone_cdb__DOT__failures);
        VL_WRITEF_NX("[FAIL] %@ expected=%0b got=%0b\n",0,
                     -1,&(vlSelfRef.__Vtask_tb_ozone_cdb__DOT__check_bit__13__label),
                     1,(IData)(__Vtask_tb_ozone_cdb__DOT__check_bit__13__expected),
                     1,__Vtask_tb_ozone_cdb__DOT__check_bit__13__got);
    }
    vlSelfRef.__Vtask_tb_ozone_cdb__DOT__check_bit__14__label = "age compare adder loses"s;
    __Vtask_tb_ozone_cdb__DOT__check_bit__14__expected = 0U;
    __Vtask_tb_ozone_cdb__DOT__check_bit__14__got = vlSelfRef.tb_ozone_cdb__DOT__adder_granted;
    if (VL_UNLIKELY((((IData)(__Vtask_tb_ozone_cdb__DOT__check_bit__14__got) 
                      != (IData)(__Vtask_tb_ozone_cdb__DOT__check_bit__14__expected))))) {
        tb_ozone_cdb__DOT__failures = ((IData)(1U) 
                                       + tb_ozone_cdb__DOT__failures);
        VL_WRITEF_NX("[FAIL] %@ expected=%0b got=%0b\n",0,
                     -1,&(vlSelfRef.__Vtask_tb_ozone_cdb__DOT__check_bit__14__label),
                     1,(IData)(__Vtask_tb_ozone_cdb__DOT__check_bit__14__expected),
                     1,__Vtask_tb_ozone_cdb__DOT__check_bit__14__got);
    }
    vlSelfRef.tb_ozone_cdb__DOT__adder_req[0U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__adder_req[1U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__adder_req[2U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__adder_req[3U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__adder_req[4U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__logic_req[0U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__logic_req[1U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__logic_req[2U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__logic_req[3U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__logic_req[4U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__fpu_req[0U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__fpu_req[1U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__fpu_req[2U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__fpu_req[3U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__fpu_req[4U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__mem_req[0U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__mem_req[1U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__mem_req[2U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__mem_req[3U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__mem_req[4U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__rob_head = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_ozone_backend.sv", 
                                         53);
    vlSelfRef.tb_ozone_cdb__DOT__rob_head = 0x3eU;
    __Vfunc_tb_ozone_cdb__DOT__make_req__16__value = 0x0000000000000063ULL;
    __Vfunc_tb_ozone_cdb__DOT__make_req__16__tag = 0x3fU;
    VL_ZERO_W(151, __Vfunc_tb_ozone_cdb__DOT__make_req__16__Vfuncout);
    VL_ZERO_W(151, __Vfunc_tb_ozone_cdb__DOT__make_req__16__req);
    __Vfunc_tb_ozone_cdb__DOT__make_req__16__req[0U] = 0U;
    __Vfunc_tb_ozone_cdb__DOT__make_req__16__req[1U] = 0U;
    __Vfunc_tb_ozone_cdb__DOT__make_req__16__req[2U] = 0U;
    __Vfunc_tb_ozone_cdb__DOT__make_req__16__req[3U] = 0U;
    __Vfunc_tb_ozone_cdb__DOT__make_req__16__req[4U] = 0U;
    __Vfunc_tb_ozone_cdb__DOT__make_req__16__req[2U] 
        = ((0x0000ffffU & __Vfunc_tb_ozone_cdb__DOT__make_req__16__req[2U]) 
           | ((IData)(__Vfunc_tb_ozone_cdb__DOT__make_req__16__value) 
              << 0x00000010U));
    __Vfunc_tb_ozone_cdb__DOT__make_req__16__req[3U] 
        = (((IData)(__Vfunc_tb_ozone_cdb__DOT__make_req__16__value) 
            >> 0x00000010U) | ((IData)((__Vfunc_tb_ozone_cdb__DOT__make_req__16__value 
                                        >> 0x00000020U)) 
                               << 0x00000010U));
    __Vfunc_tb_ozone_cdb__DOT__make_req__16__req[4U] 
        = (0x007fffffU & (0x00400000U | (((IData)((__Vfunc_tb_ozone_cdb__DOT__make_req__16__value 
                                                   >> 0x00000020U)) 
                                          >> 0x00000010U) 
                                         | ((IData)(__Vfunc_tb_ozone_cdb__DOT__make_req__16__tag) 
                                            << 0x00000010U))));
    __Vfunc_tb_ozone_cdb__DOT__make_req__16__Vfuncout[0U] 
        = __Vfunc_tb_ozone_cdb__DOT__make_req__16__req[0U];
    __Vfunc_tb_ozone_cdb__DOT__make_req__16__Vfuncout[1U] 
        = __Vfunc_tb_ozone_cdb__DOT__make_req__16__req[1U];
    __Vfunc_tb_ozone_cdb__DOT__make_req__16__Vfuncout[2U] 
        = __Vfunc_tb_ozone_cdb__DOT__make_req__16__req[2U];
    __Vfunc_tb_ozone_cdb__DOT__make_req__16__Vfuncout[3U] 
        = __Vfunc_tb_ozone_cdb__DOT__make_req__16__req[3U];
    __Vfunc_tb_ozone_cdb__DOT__make_req__16__Vfuncout[4U] 
        = __Vfunc_tb_ozone_cdb__DOT__make_req__16__req[4U];
    vlSelfRef.tb_ozone_cdb__DOT__adder_req[0U] = __Vfunc_tb_ozone_cdb__DOT__make_req__16__Vfuncout[0U];
    vlSelfRef.tb_ozone_cdb__DOT__adder_req[1U] = __Vfunc_tb_ozone_cdb__DOT__make_req__16__Vfuncout[1U];
    vlSelfRef.tb_ozone_cdb__DOT__adder_req[2U] = __Vfunc_tb_ozone_cdb__DOT__make_req__16__Vfuncout[2U];
    vlSelfRef.tb_ozone_cdb__DOT__adder_req[3U] = __Vfunc_tb_ozone_cdb__DOT__make_req__16__Vfuncout[3U];
    vlSelfRef.tb_ozone_cdb__DOT__adder_req[4U] = __Vfunc_tb_ozone_cdb__DOT__make_req__16__Vfuncout[4U];
    __Vfunc_tb_ozone_cdb__DOT__make_req__17__value = 1ULL;
    __Vfunc_tb_ozone_cdb__DOT__make_req__17__tag = 1U;
    VL_ZERO_W(151, __Vfunc_tb_ozone_cdb__DOT__make_req__17__Vfuncout);
    VL_ZERO_W(151, __Vfunc_tb_ozone_cdb__DOT__make_req__17__req);
    __Vfunc_tb_ozone_cdb__DOT__make_req__17__req[0U] = 0U;
    __Vfunc_tb_ozone_cdb__DOT__make_req__17__req[1U] = 0U;
    __Vfunc_tb_ozone_cdb__DOT__make_req__17__req[2U] = 0U;
    __Vfunc_tb_ozone_cdb__DOT__make_req__17__req[3U] = 0U;
    __Vfunc_tb_ozone_cdb__DOT__make_req__17__req[4U] = 0U;
    __Vfunc_tb_ozone_cdb__DOT__make_req__17__req[2U] 
        = ((0x0000ffffU & __Vfunc_tb_ozone_cdb__DOT__make_req__17__req[2U]) 
           | ((IData)(__Vfunc_tb_ozone_cdb__DOT__make_req__17__value) 
              << 0x00000010U));
    __Vfunc_tb_ozone_cdb__DOT__make_req__17__req[3U] 
        = (((IData)(__Vfunc_tb_ozone_cdb__DOT__make_req__17__value) 
            >> 0x00000010U) | ((IData)((__Vfunc_tb_ozone_cdb__DOT__make_req__17__value 
                                        >> 0x00000020U)) 
                               << 0x00000010U));
    __Vfunc_tb_ozone_cdb__DOT__make_req__17__req[4U] 
        = (0x007fffffU & (0x00400000U | (((IData)((__Vfunc_tb_ozone_cdb__DOT__make_req__17__value 
                                                   >> 0x00000020U)) 
                                          >> 0x00000010U) 
                                         | ((IData)(__Vfunc_tb_ozone_cdb__DOT__make_req__17__tag) 
                                            << 0x00000010U))));
    __Vfunc_tb_ozone_cdb__DOT__make_req__17__Vfuncout[0U] 
        = __Vfunc_tb_ozone_cdb__DOT__make_req__17__req[0U];
    __Vfunc_tb_ozone_cdb__DOT__make_req__17__Vfuncout[1U] 
        = __Vfunc_tb_ozone_cdb__DOT__make_req__17__req[1U];
    __Vfunc_tb_ozone_cdb__DOT__make_req__17__Vfuncout[2U] 
        = __Vfunc_tb_ozone_cdb__DOT__make_req__17__req[2U];
    __Vfunc_tb_ozone_cdb__DOT__make_req__17__Vfuncout[3U] 
        = __Vfunc_tb_ozone_cdb__DOT__make_req__17__req[3U];
    __Vfunc_tb_ozone_cdb__DOT__make_req__17__Vfuncout[4U] 
        = __Vfunc_tb_ozone_cdb__DOT__make_req__17__req[4U];
    vlSelfRef.tb_ozone_cdb__DOT__logic_req[0U] = __Vfunc_tb_ozone_cdb__DOT__make_req__17__Vfuncout[0U];
    vlSelfRef.tb_ozone_cdb__DOT__logic_req[1U] = __Vfunc_tb_ozone_cdb__DOT__make_req__17__Vfuncout[1U];
    vlSelfRef.tb_ozone_cdb__DOT__logic_req[2U] = __Vfunc_tb_ozone_cdb__DOT__make_req__17__Vfuncout[2U];
    vlSelfRef.tb_ozone_cdb__DOT__logic_req[3U] = __Vfunc_tb_ozone_cdb__DOT__make_req__17__Vfuncout[3U];
    vlSelfRef.tb_ozone_cdb__DOT__logic_req[4U] = __Vfunc_tb_ozone_cdb__DOT__make_req__17__Vfuncout[4U];
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_ozone_backend.sv", 
                                         115);
    vlSelfRef.__Vtask_tb_ozone_cdb__DOT__check_tag__18__label = "wrap winner"s;
    __Vtask_tb_ozone_cdb__DOT__check_tag__18__expected = 0x3fU;
    __Vtask_tb_ozone_cdb__DOT__check_tag__18__got = 
        (0x0000003fU & (vlSelfRef.tb_ozone_cdb__DOT__cdb_broadcast[4U] 
                        >> 0x00000010U));
    if (VL_UNLIKELY((((IData)(__Vtask_tb_ozone_cdb__DOT__check_tag__18__got) 
                      != (IData)(__Vtask_tb_ozone_cdb__DOT__check_tag__18__expected))))) {
        tb_ozone_cdb__DOT__failures = ((IData)(1U) 
                                       + tb_ozone_cdb__DOT__failures);
        VL_WRITEF_NX("[FAIL] %@ expected tag=%0# got=%0#\n",0,
                     -1,&(vlSelfRef.__Vtask_tb_ozone_cdb__DOT__check_tag__18__label),
                     6,(IData)(__Vtask_tb_ozone_cdb__DOT__check_tag__18__expected),
                     6,__Vtask_tb_ozone_cdb__DOT__check_tag__18__got);
    }
    vlSelfRef.__Vtask_tb_ozone_cdb__DOT__check_bit__19__label = "wrap adder grant"s;
    __Vtask_tb_ozone_cdb__DOT__check_bit__19__expected = 1U;
    __Vtask_tb_ozone_cdb__DOT__check_bit__19__got = vlSelfRef.tb_ozone_cdb__DOT__adder_granted;
    if (VL_UNLIKELY((((IData)(__Vtask_tb_ozone_cdb__DOT__check_bit__19__got) 
                      != (IData)(__Vtask_tb_ozone_cdb__DOT__check_bit__19__expected))))) {
        tb_ozone_cdb__DOT__failures = ((IData)(1U) 
                                       + tb_ozone_cdb__DOT__failures);
        VL_WRITEF_NX("[FAIL] %@ expected=%0b got=%0b\n",0,
                     -1,&(vlSelfRef.__Vtask_tb_ozone_cdb__DOT__check_bit__19__label),
                     1,(IData)(__Vtask_tb_ozone_cdb__DOT__check_bit__19__expected),
                     1,__Vtask_tb_ozone_cdb__DOT__check_bit__19__got);
    }
    vlSelfRef.__Vtask_tb_ozone_cdb__DOT__check_bit__20__label = "wrap logic loses"s;
    __Vtask_tb_ozone_cdb__DOT__check_bit__20__expected = 0U;
    __Vtask_tb_ozone_cdb__DOT__check_bit__20__got = vlSelfRef.tb_ozone_cdb__DOT__logic_granted;
    if (VL_UNLIKELY((((IData)(__Vtask_tb_ozone_cdb__DOT__check_bit__20__got) 
                      != (IData)(__Vtask_tb_ozone_cdb__DOT__check_bit__20__expected))))) {
        tb_ozone_cdb__DOT__failures = ((IData)(1U) 
                                       + tb_ozone_cdb__DOT__failures);
        VL_WRITEF_NX("[FAIL] %@ expected=%0b got=%0b\n",0,
                     -1,&(vlSelfRef.__Vtask_tb_ozone_cdb__DOT__check_bit__20__label),
                     1,(IData)(__Vtask_tb_ozone_cdb__DOT__check_bit__20__expected),
                     1,__Vtask_tb_ozone_cdb__DOT__check_bit__20__got);
    }
    vlSelfRef.tb_ozone_cdb__DOT__adder_req[0U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__adder_req[1U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__adder_req[2U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__adder_req[3U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__adder_req[4U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__logic_req[0U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__logic_req[1U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__logic_req[2U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__logic_req[3U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__logic_req[4U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__fpu_req[0U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__fpu_req[1U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__fpu_req[2U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__fpu_req[3U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__fpu_req[4U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__mem_req[0U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__mem_req[1U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__mem_req[2U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__mem_req[3U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__mem_req[4U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__rob_head = 0U;
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_ozone_backend.sv", 
                                         53);
    vlSelfRef.tb_ozone_cdb__DOT__rob_head = 0x14U;
    __Vfunc_tb_ozone_cdb__DOT__make_req__22__value = 0x0000000000000024ULL;
    __Vfunc_tb_ozone_cdb__DOT__make_req__22__tag = 0x18U;
    VL_ZERO_W(151, __Vfunc_tb_ozone_cdb__DOT__make_req__22__Vfuncout);
    VL_ZERO_W(151, __Vfunc_tb_ozone_cdb__DOT__make_req__22__req);
    __Vfunc_tb_ozone_cdb__DOT__make_req__22__req[0U] = 0U;
    __Vfunc_tb_ozone_cdb__DOT__make_req__22__req[1U] = 0U;
    __Vfunc_tb_ozone_cdb__DOT__make_req__22__req[2U] = 0U;
    __Vfunc_tb_ozone_cdb__DOT__make_req__22__req[3U] = 0U;
    __Vfunc_tb_ozone_cdb__DOT__make_req__22__req[4U] = 0U;
    __Vfunc_tb_ozone_cdb__DOT__make_req__22__req[2U] 
        = ((0x0000ffffU & __Vfunc_tb_ozone_cdb__DOT__make_req__22__req[2U]) 
           | ((IData)(__Vfunc_tb_ozone_cdb__DOT__make_req__22__value) 
              << 0x00000010U));
    __Vfunc_tb_ozone_cdb__DOT__make_req__22__req[3U] 
        = (((IData)(__Vfunc_tb_ozone_cdb__DOT__make_req__22__value) 
            >> 0x00000010U) | ((IData)((__Vfunc_tb_ozone_cdb__DOT__make_req__22__value 
                                        >> 0x00000020U)) 
                               << 0x00000010U));
    __Vfunc_tb_ozone_cdb__DOT__make_req__22__req[4U] 
        = (0x007fffffU & (0x00400000U | (((IData)((__Vfunc_tb_ozone_cdb__DOT__make_req__22__value 
                                                   >> 0x00000020U)) 
                                          >> 0x00000010U) 
                                         | ((IData)(__Vfunc_tb_ozone_cdb__DOT__make_req__22__tag) 
                                            << 0x00000010U))));
    __Vfunc_tb_ozone_cdb__DOT__make_req__22__Vfuncout[0U] 
        = __Vfunc_tb_ozone_cdb__DOT__make_req__22__req[0U];
    __Vfunc_tb_ozone_cdb__DOT__make_req__22__Vfuncout[1U] 
        = __Vfunc_tb_ozone_cdb__DOT__make_req__22__req[1U];
    __Vfunc_tb_ozone_cdb__DOT__make_req__22__Vfuncout[2U] 
        = __Vfunc_tb_ozone_cdb__DOT__make_req__22__req[2U];
    __Vfunc_tb_ozone_cdb__DOT__make_req__22__Vfuncout[3U] 
        = __Vfunc_tb_ozone_cdb__DOT__make_req__22__req[3U];
    __Vfunc_tb_ozone_cdb__DOT__make_req__22__Vfuncout[4U] 
        = __Vfunc_tb_ozone_cdb__DOT__make_req__22__req[4U];
    vlSelfRef.tb_ozone_cdb__DOT__adder_req[0U] = __Vfunc_tb_ozone_cdb__DOT__make_req__22__Vfuncout[0U];
    vlSelfRef.tb_ozone_cdb__DOT__adder_req[1U] = __Vfunc_tb_ozone_cdb__DOT__make_req__22__Vfuncout[1U];
    vlSelfRef.tb_ozone_cdb__DOT__adder_req[2U] = __Vfunc_tb_ozone_cdb__DOT__make_req__22__Vfuncout[2U];
    vlSelfRef.tb_ozone_cdb__DOT__adder_req[3U] = __Vfunc_tb_ozone_cdb__DOT__make_req__22__Vfuncout[3U];
    vlSelfRef.tb_ozone_cdb__DOT__adder_req[4U] = __Vfunc_tb_ozone_cdb__DOT__make_req__22__Vfuncout[4U];
    __Vfunc_tb_ozone_cdb__DOT__make_req__23__value = 0x0000000000000022ULL;
    __Vfunc_tb_ozone_cdb__DOT__make_req__23__tag = 0x16U;
    VL_ZERO_W(151, __Vfunc_tb_ozone_cdb__DOT__make_req__23__Vfuncout);
    VL_ZERO_W(151, __Vfunc_tb_ozone_cdb__DOT__make_req__23__req);
    __Vfunc_tb_ozone_cdb__DOT__make_req__23__req[0U] = 0U;
    __Vfunc_tb_ozone_cdb__DOT__make_req__23__req[1U] = 0U;
    __Vfunc_tb_ozone_cdb__DOT__make_req__23__req[2U] = 0U;
    __Vfunc_tb_ozone_cdb__DOT__make_req__23__req[3U] = 0U;
    __Vfunc_tb_ozone_cdb__DOT__make_req__23__req[4U] = 0U;
    __Vfunc_tb_ozone_cdb__DOT__make_req__23__req[2U] 
        = ((0x0000ffffU & __Vfunc_tb_ozone_cdb__DOT__make_req__23__req[2U]) 
           | ((IData)(__Vfunc_tb_ozone_cdb__DOT__make_req__23__value) 
              << 0x00000010U));
    __Vfunc_tb_ozone_cdb__DOT__make_req__23__req[3U] 
        = (((IData)(__Vfunc_tb_ozone_cdb__DOT__make_req__23__value) 
            >> 0x00000010U) | ((IData)((__Vfunc_tb_ozone_cdb__DOT__make_req__23__value 
                                        >> 0x00000020U)) 
                               << 0x00000010U));
    __Vfunc_tb_ozone_cdb__DOT__make_req__23__req[4U] 
        = (0x007fffffU & (0x00400000U | (((IData)((__Vfunc_tb_ozone_cdb__DOT__make_req__23__value 
                                                   >> 0x00000020U)) 
                                          >> 0x00000010U) 
                                         | ((IData)(__Vfunc_tb_ozone_cdb__DOT__make_req__23__tag) 
                                            << 0x00000010U))));
    __Vfunc_tb_ozone_cdb__DOT__make_req__23__Vfuncout[0U] 
        = __Vfunc_tb_ozone_cdb__DOT__make_req__23__req[0U];
    __Vfunc_tb_ozone_cdb__DOT__make_req__23__Vfuncout[1U] 
        = __Vfunc_tb_ozone_cdb__DOT__make_req__23__req[1U];
    __Vfunc_tb_ozone_cdb__DOT__make_req__23__Vfuncout[2U] 
        = __Vfunc_tb_ozone_cdb__DOT__make_req__23__req[2U];
    __Vfunc_tb_ozone_cdb__DOT__make_req__23__Vfuncout[3U] 
        = __Vfunc_tb_ozone_cdb__DOT__make_req__23__req[3U];
    __Vfunc_tb_ozone_cdb__DOT__make_req__23__Vfuncout[4U] 
        = __Vfunc_tb_ozone_cdb__DOT__make_req__23__req[4U];
    vlSelfRef.tb_ozone_cdb__DOT__logic_req[0U] = __Vfunc_tb_ozone_cdb__DOT__make_req__23__Vfuncout[0U];
    vlSelfRef.tb_ozone_cdb__DOT__logic_req[1U] = __Vfunc_tb_ozone_cdb__DOT__make_req__23__Vfuncout[1U];
    vlSelfRef.tb_ozone_cdb__DOT__logic_req[2U] = __Vfunc_tb_ozone_cdb__DOT__make_req__23__Vfuncout[2U];
    vlSelfRef.tb_ozone_cdb__DOT__logic_req[3U] = __Vfunc_tb_ozone_cdb__DOT__make_req__23__Vfuncout[3U];
    vlSelfRef.tb_ozone_cdb__DOT__logic_req[4U] = __Vfunc_tb_ozone_cdb__DOT__make_req__23__Vfuncout[4U];
    __Vfunc_tb_ozone_cdb__DOT__make_req__24__value = 0x0000000000000025ULL;
    __Vfunc_tb_ozone_cdb__DOT__make_req__24__tag = 0x19U;
    VL_ZERO_W(151, __Vfunc_tb_ozone_cdb__DOT__make_req__24__Vfuncout);
    VL_ZERO_W(151, __Vfunc_tb_ozone_cdb__DOT__make_req__24__req);
    __Vfunc_tb_ozone_cdb__DOT__make_req__24__req[0U] = 0U;
    __Vfunc_tb_ozone_cdb__DOT__make_req__24__req[1U] = 0U;
    __Vfunc_tb_ozone_cdb__DOT__make_req__24__req[2U] = 0U;
    __Vfunc_tb_ozone_cdb__DOT__make_req__24__req[3U] = 0U;
    __Vfunc_tb_ozone_cdb__DOT__make_req__24__req[4U] = 0U;
    __Vfunc_tb_ozone_cdb__DOT__make_req__24__req[2U] 
        = ((0x0000ffffU & __Vfunc_tb_ozone_cdb__DOT__make_req__24__req[2U]) 
           | ((IData)(__Vfunc_tb_ozone_cdb__DOT__make_req__24__value) 
              << 0x00000010U));
    __Vfunc_tb_ozone_cdb__DOT__make_req__24__req[3U] 
        = (((IData)(__Vfunc_tb_ozone_cdb__DOT__make_req__24__value) 
            >> 0x00000010U) | ((IData)((__Vfunc_tb_ozone_cdb__DOT__make_req__24__value 
                                        >> 0x00000020U)) 
                               << 0x00000010U));
    __Vfunc_tb_ozone_cdb__DOT__make_req__24__req[4U] 
        = (0x007fffffU & (0x00400000U | (((IData)((__Vfunc_tb_ozone_cdb__DOT__make_req__24__value 
                                                   >> 0x00000020U)) 
                                          >> 0x00000010U) 
                                         | ((IData)(__Vfunc_tb_ozone_cdb__DOT__make_req__24__tag) 
                                            << 0x00000010U))));
    __Vfunc_tb_ozone_cdb__DOT__make_req__24__Vfuncout[0U] 
        = __Vfunc_tb_ozone_cdb__DOT__make_req__24__req[0U];
    __Vfunc_tb_ozone_cdb__DOT__make_req__24__Vfuncout[1U] 
        = __Vfunc_tb_ozone_cdb__DOT__make_req__24__req[1U];
    __Vfunc_tb_ozone_cdb__DOT__make_req__24__Vfuncout[2U] 
        = __Vfunc_tb_ozone_cdb__DOT__make_req__24__req[2U];
    __Vfunc_tb_ozone_cdb__DOT__make_req__24__Vfuncout[3U] 
        = __Vfunc_tb_ozone_cdb__DOT__make_req__24__req[3U];
    __Vfunc_tb_ozone_cdb__DOT__make_req__24__Vfuncout[4U] 
        = __Vfunc_tb_ozone_cdb__DOT__make_req__24__req[4U];
    vlSelfRef.tb_ozone_cdb__DOT__fpu_req[0U] = __Vfunc_tb_ozone_cdb__DOT__make_req__24__Vfuncout[0U];
    vlSelfRef.tb_ozone_cdb__DOT__fpu_req[1U] = __Vfunc_tb_ozone_cdb__DOT__make_req__24__Vfuncout[1U];
    vlSelfRef.tb_ozone_cdb__DOT__fpu_req[2U] = __Vfunc_tb_ozone_cdb__DOT__make_req__24__Vfuncout[2U];
    vlSelfRef.tb_ozone_cdb__DOT__fpu_req[3U] = __Vfunc_tb_ozone_cdb__DOT__make_req__24__Vfuncout[3U];
    vlSelfRef.tb_ozone_cdb__DOT__fpu_req[4U] = __Vfunc_tb_ozone_cdb__DOT__make_req__24__Vfuncout[4U];
    __Vfunc_tb_ozone_cdb__DOT__make_req__25__value = 0x0000000000000021ULL;
    __Vfunc_tb_ozone_cdb__DOT__make_req__25__tag = 0x15U;
    VL_ZERO_W(151, __Vfunc_tb_ozone_cdb__DOT__make_req__25__Vfuncout);
    VL_ZERO_W(151, __Vfunc_tb_ozone_cdb__DOT__make_req__25__req);
    __Vfunc_tb_ozone_cdb__DOT__make_req__25__req[0U] = 0U;
    __Vfunc_tb_ozone_cdb__DOT__make_req__25__req[1U] = 0U;
    __Vfunc_tb_ozone_cdb__DOT__make_req__25__req[2U] = 0U;
    __Vfunc_tb_ozone_cdb__DOT__make_req__25__req[3U] = 0U;
    __Vfunc_tb_ozone_cdb__DOT__make_req__25__req[4U] = 0U;
    __Vfunc_tb_ozone_cdb__DOT__make_req__25__req[2U] 
        = ((0x0000ffffU & __Vfunc_tb_ozone_cdb__DOT__make_req__25__req[2U]) 
           | ((IData)(__Vfunc_tb_ozone_cdb__DOT__make_req__25__value) 
              << 0x00000010U));
    __Vfunc_tb_ozone_cdb__DOT__make_req__25__req[3U] 
        = (((IData)(__Vfunc_tb_ozone_cdb__DOT__make_req__25__value) 
            >> 0x00000010U) | ((IData)((__Vfunc_tb_ozone_cdb__DOT__make_req__25__value 
                                        >> 0x00000020U)) 
                               << 0x00000010U));
    __Vfunc_tb_ozone_cdb__DOT__make_req__25__req[4U] 
        = (0x007fffffU & (0x00400000U | (((IData)((__Vfunc_tb_ozone_cdb__DOT__make_req__25__value 
                                                   >> 0x00000020U)) 
                                          >> 0x00000010U) 
                                         | ((IData)(__Vfunc_tb_ozone_cdb__DOT__make_req__25__tag) 
                                            << 0x00000010U))));
    __Vfunc_tb_ozone_cdb__DOT__make_req__25__Vfuncout[0U] 
        = __Vfunc_tb_ozone_cdb__DOT__make_req__25__req[0U];
    __Vfunc_tb_ozone_cdb__DOT__make_req__25__Vfuncout[1U] 
        = __Vfunc_tb_ozone_cdb__DOT__make_req__25__req[1U];
    __Vfunc_tb_ozone_cdb__DOT__make_req__25__Vfuncout[2U] 
        = __Vfunc_tb_ozone_cdb__DOT__make_req__25__req[2U];
    __Vfunc_tb_ozone_cdb__DOT__make_req__25__Vfuncout[3U] 
        = __Vfunc_tb_ozone_cdb__DOT__make_req__25__req[3U];
    __Vfunc_tb_ozone_cdb__DOT__make_req__25__Vfuncout[4U] 
        = __Vfunc_tb_ozone_cdb__DOT__make_req__25__req[4U];
    vlSelfRef.tb_ozone_cdb__DOT__mem_req[0U] = __Vfunc_tb_ozone_cdb__DOT__make_req__25__Vfuncout[0U];
    vlSelfRef.tb_ozone_cdb__DOT__mem_req[1U] = __Vfunc_tb_ozone_cdb__DOT__make_req__25__Vfuncout[1U];
    vlSelfRef.tb_ozone_cdb__DOT__mem_req[2U] = __Vfunc_tb_ozone_cdb__DOT__make_req__25__Vfuncout[2U];
    vlSelfRef.tb_ozone_cdb__DOT__mem_req[3U] = __Vfunc_tb_ozone_cdb__DOT__make_req__25__Vfuncout[3U];
    vlSelfRef.tb_ozone_cdb__DOT__mem_req[4U] = __Vfunc_tb_ozone_cdb__DOT__make_req__25__Vfuncout[4U];
    co_await vlSelfRef.__VdlySched.delay(0x00000000000003e8ULL, 
                                         nullptr, "tb/tb_ozone_backend.sv", 
                                         127);
    vlSelfRef.__Vtask_tb_ozone_cdb__DOT__check_tag__26__label = "all valid winner"s;
    __Vtask_tb_ozone_cdb__DOT__check_tag__26__expected = 0x15U;
    __Vtask_tb_ozone_cdb__DOT__check_tag__26__got = 
        (0x0000003fU & (vlSelfRef.tb_ozone_cdb__DOT__cdb_broadcast[4U] 
                        >> 0x00000010U));
    if (VL_UNLIKELY((((IData)(__Vtask_tb_ozone_cdb__DOT__check_tag__26__got) 
                      != (IData)(__Vtask_tb_ozone_cdb__DOT__check_tag__26__expected))))) {
        tb_ozone_cdb__DOT__failures = ((IData)(1U) 
                                       + tb_ozone_cdb__DOT__failures);
        VL_WRITEF_NX("[FAIL] %@ expected tag=%0# got=%0#\n",0,
                     -1,&(vlSelfRef.__Vtask_tb_ozone_cdb__DOT__check_tag__26__label),
                     6,(IData)(__Vtask_tb_ozone_cdb__DOT__check_tag__26__expected),
                     6,__Vtask_tb_ozone_cdb__DOT__check_tag__26__got);
    }
    vlSelfRef.__Vtask_tb_ozone_cdb__DOT__check_bit__27__label = "all valid mem grant"s;
    __Vtask_tb_ozone_cdb__DOT__check_bit__27__expected = 1U;
    __Vtask_tb_ozone_cdb__DOT__check_bit__27__got = vlSelfRef.tb_ozone_cdb__DOT__mem_granted;
    if (VL_UNLIKELY((((IData)(__Vtask_tb_ozone_cdb__DOT__check_bit__27__got) 
                      != (IData)(__Vtask_tb_ozone_cdb__DOT__check_bit__27__expected))))) {
        tb_ozone_cdb__DOT__failures = ((IData)(1U) 
                                       + tb_ozone_cdb__DOT__failures);
        VL_WRITEF_NX("[FAIL] %@ expected=%0b got=%0b\n",0,
                     -1,&(vlSelfRef.__Vtask_tb_ozone_cdb__DOT__check_bit__27__label),
                     1,(IData)(__Vtask_tb_ozone_cdb__DOT__check_bit__27__expected),
                     1,__Vtask_tb_ozone_cdb__DOT__check_bit__27__got);
    }
    vlSelfRef.__Vtask_tb_ozone_cdb__DOT__check_bit__28__label = "all valid adder loses"s;
    __Vtask_tb_ozone_cdb__DOT__check_bit__28__expected = 0U;
    __Vtask_tb_ozone_cdb__DOT__check_bit__28__got = vlSelfRef.tb_ozone_cdb__DOT__adder_granted;
    if (VL_UNLIKELY((((IData)(__Vtask_tb_ozone_cdb__DOT__check_bit__28__got) 
                      != (IData)(__Vtask_tb_ozone_cdb__DOT__check_bit__28__expected))))) {
        tb_ozone_cdb__DOT__failures = ((IData)(1U) 
                                       + tb_ozone_cdb__DOT__failures);
        VL_WRITEF_NX("[FAIL] %@ expected=%0b got=%0b\n",0,
                     -1,&(vlSelfRef.__Vtask_tb_ozone_cdb__DOT__check_bit__28__label),
                     1,(IData)(__Vtask_tb_ozone_cdb__DOT__check_bit__28__expected),
                     1,__Vtask_tb_ozone_cdb__DOT__check_bit__28__got);
    }
    vlSelfRef.__Vtask_tb_ozone_cdb__DOT__check_bit__29__label = "all valid logic loses"s;
    __Vtask_tb_ozone_cdb__DOT__check_bit__29__expected = 0U;
    __Vtask_tb_ozone_cdb__DOT__check_bit__29__got = vlSelfRef.tb_ozone_cdb__DOT__logic_granted;
    if (VL_UNLIKELY((((IData)(__Vtask_tb_ozone_cdb__DOT__check_bit__29__got) 
                      != (IData)(__Vtask_tb_ozone_cdb__DOT__check_bit__29__expected))))) {
        tb_ozone_cdb__DOT__failures = ((IData)(1U) 
                                       + tb_ozone_cdb__DOT__failures);
        VL_WRITEF_NX("[FAIL] %@ expected=%0b got=%0b\n",0,
                     -1,&(vlSelfRef.__Vtask_tb_ozone_cdb__DOT__check_bit__29__label),
                     1,(IData)(__Vtask_tb_ozone_cdb__DOT__check_bit__29__expected),
                     1,__Vtask_tb_ozone_cdb__DOT__check_bit__29__got);
    }
    vlSelfRef.__Vtask_tb_ozone_cdb__DOT__check_bit__30__label = "all valid fpu loses"s;
    __Vtask_tb_ozone_cdb__DOT__check_bit__30__expected = 0U;
    __Vtask_tb_ozone_cdb__DOT__check_bit__30__got = vlSelfRef.tb_ozone_cdb__DOT__fpu_granted;
    if (VL_UNLIKELY((((IData)(__Vtask_tb_ozone_cdb__DOT__check_bit__30__got) 
                      != (IData)(__Vtask_tb_ozone_cdb__DOT__check_bit__30__expected))))) {
        tb_ozone_cdb__DOT__failures = ((IData)(1U) 
                                       + tb_ozone_cdb__DOT__failures);
        VL_WRITEF_NX("[FAIL] %@ expected=%0b got=%0b\n",0,
                     -1,&(vlSelfRef.__Vtask_tb_ozone_cdb__DOT__check_bit__30__label),
                     1,(IData)(__Vtask_tb_ozone_cdb__DOT__check_bit__30__expected),
                     1,__Vtask_tb_ozone_cdb__DOT__check_bit__30__got);
    }
    if (VL_UNLIKELY(((0U != tb_ozone_cdb__DOT__failures)))) {
        VL_WRITEF_NX("[%0t] %%Fatal: tb_ozone_backend.sv:135: Assertion failed in %Ntb_ozone_cdb: tb_ozone_cdb failed with %0d failures\n",0,
                     64,VL_TIME_UNITED_Q(1000),-9,vlSymsp->name(),
                     32,tb_ozone_cdb__DOT__failures);
        VL_STOP_MT("tb/tb_ozone_backend.sv", 135, "", false);
    }
    VL_WRITEF_NX("tb_ozone_cdb passed\n",0);
    VL_FINISH_MT("tb/tb_ozone_backend.sv", 139, "");
    co_return;
}

void Vtb_ozone_cdb___024root___eval_triggers_vec__act(Vtb_ozone_cdb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ozone_cdb___024root___eval_triggers_vec__act\n"); );
    Vtb_ozone_cdb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VactTriggered[0U] = (QData)((IData)(vlSelfRef.__VdlySched.awaitingCurrentTime()));
}

bool Vtb_ozone_cdb___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ozone_cdb___024root___trigger_anySet__act\n"); );
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

void Vtb_ozone_cdb___024root___act_sequent__TOP__0(Vtb_ozone_cdb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ozone_cdb___024root___act_sequent__TOP__0\n"); );
    Vtb_ozone_cdb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*5:0*/ tb_ozone_cdb__DOT__dut__DOT__logic_age;
    tb_ozone_cdb__DOT__dut__DOT__logic_age = 0;
    CData/*5:0*/ tb_ozone_cdb__DOT__dut__DOT__fpu_age;
    tb_ozone_cdb__DOT__dut__DOT__fpu_age = 0;
    CData/*2:0*/ tb_ozone_cdb__DOT__dut__DOT__unnamedblk1__DOT__winner;
    tb_ozone_cdb__DOT__dut__DOT__unnamedblk1__DOT__winner = 0;
    CData/*5:0*/ tb_ozone_cdb__DOT__dut__DOT__unnamedblk1__DOT__best_age;
    tb_ozone_cdb__DOT__dut__DOT__unnamedblk1__DOT__best_age = 0;
    // Body
    tb_ozone_cdb__DOT__dut__DOT__logic_age = (0x0000003fU 
                                              & (((vlSelfRef.tb_ozone_cdb__DOT__logic_req[4U] 
                                                   << 0x00000010U) 
                                                  | (vlSelfRef.tb_ozone_cdb__DOT__logic_req[4U] 
                                                     >> 0x00000010U)) 
                                                 - (IData)(vlSelfRef.tb_ozone_cdb__DOT__rob_head)));
    tb_ozone_cdb__DOT__dut__DOT__fpu_age = (0x0000003fU 
                                            & (((vlSelfRef.tb_ozone_cdb__DOT__fpu_req[4U] 
                                                 << 0x00000010U) 
                                                | (vlSelfRef.tb_ozone_cdb__DOT__fpu_req[4U] 
                                                   >> 0x00000010U)) 
                                               - (IData)(vlSelfRef.tb_ozone_cdb__DOT__rob_head)));
    vlSelfRef.tb_ozone_cdb__DOT__cdb_broadcast[0U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__cdb_broadcast[1U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__cdb_broadcast[2U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__cdb_broadcast[3U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__cdb_broadcast[4U] = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__adder_granted = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__logic_granted = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__fpu_granted = 0U;
    vlSelfRef.tb_ozone_cdb__DOT__mem_granted = 0U;
    tb_ozone_cdb__DOT__dut__DOT__unnamedblk1__DOT__winner = 0U;
    tb_ozone_cdb__DOT__dut__DOT__unnamedblk1__DOT__best_age = 0U;
    if ((0x00400000U & vlSelfRef.tb_ozone_cdb__DOT__adder_req[4U])) {
        tb_ozone_cdb__DOT__dut__DOT__unnamedblk1__DOT__winner = 1U;
        tb_ozone_cdb__DOT__dut__DOT__unnamedblk1__DOT__best_age 
            = (0x0000003fU & (((vlSelfRef.tb_ozone_cdb__DOT__adder_req[4U] 
                                << 0x00000010U) | (vlSelfRef.tb_ozone_cdb__DOT__adder_req[4U] 
                                                   >> 0x00000010U)) 
                              - (IData)(vlSelfRef.tb_ozone_cdb__DOT__rob_head)));
    }
    if (((vlSelfRef.tb_ozone_cdb__DOT__logic_req[4U] 
          >> 0x00000016U) & ((0U == (IData)(tb_ozone_cdb__DOT__dut__DOT__unnamedblk1__DOT__winner)) 
                             | ((IData)(tb_ozone_cdb__DOT__dut__DOT__logic_age) 
                                < (IData)(tb_ozone_cdb__DOT__dut__DOT__unnamedblk1__DOT__best_age))))) {
        tb_ozone_cdb__DOT__dut__DOT__unnamedblk1__DOT__winner = 2U;
        tb_ozone_cdb__DOT__dut__DOT__unnamedblk1__DOT__best_age 
            = tb_ozone_cdb__DOT__dut__DOT__logic_age;
    }
    if (((vlSelfRef.tb_ozone_cdb__DOT__fpu_req[4U] 
          >> 0x00000016U) & ((0U == (IData)(tb_ozone_cdb__DOT__dut__DOT__unnamedblk1__DOT__winner)) 
                             | ((IData)(tb_ozone_cdb__DOT__dut__DOT__fpu_age) 
                                < (IData)(tb_ozone_cdb__DOT__dut__DOT__unnamedblk1__DOT__best_age))))) {
        tb_ozone_cdb__DOT__dut__DOT__unnamedblk1__DOT__winner = 3U;
        tb_ozone_cdb__DOT__dut__DOT__unnamedblk1__DOT__best_age 
            = tb_ozone_cdb__DOT__dut__DOT__fpu_age;
    }
    if (((vlSelfRef.tb_ozone_cdb__DOT__mem_req[4U] 
          >> 0x00000016U) & ((0U == (IData)(tb_ozone_cdb__DOT__dut__DOT__unnamedblk1__DOT__winner)) 
                             | ((0x0000003fU & (((vlSelfRef.tb_ozone_cdb__DOT__mem_req[4U] 
                                                  << 0x00000010U) 
                                                 | (vlSelfRef.tb_ozone_cdb__DOT__mem_req[4U] 
                                                    >> 0x00000010U)) 
                                                - (IData)(vlSelfRef.tb_ozone_cdb__DOT__rob_head))) 
                                < (IData)(tb_ozone_cdb__DOT__dut__DOT__unnamedblk1__DOT__best_age))))) {
        tb_ozone_cdb__DOT__dut__DOT__unnamedblk1__DOT__winner = 4U;
    }
    if ((4U & (IData)(tb_ozone_cdb__DOT__dut__DOT__unnamedblk1__DOT__winner))) {
        if ((2U & (IData)(tb_ozone_cdb__DOT__dut__DOT__unnamedblk1__DOT__winner))) {
            vlSelfRef.tb_ozone_cdb__DOT__cdb_broadcast[0U] = 0U;
            vlSelfRef.tb_ozone_cdb__DOT__cdb_broadcast[1U] = 0U;
            vlSelfRef.tb_ozone_cdb__DOT__cdb_broadcast[2U] = 0U;
            vlSelfRef.tb_ozone_cdb__DOT__cdb_broadcast[3U] = 0U;
            vlSelfRef.tb_ozone_cdb__DOT__cdb_broadcast[4U] = 0U;
        } else if ((1U & (IData)(tb_ozone_cdb__DOT__dut__DOT__unnamedblk1__DOT__winner))) {
            vlSelfRef.tb_ozone_cdb__DOT__cdb_broadcast[0U] = 0U;
            vlSelfRef.tb_ozone_cdb__DOT__cdb_broadcast[1U] = 0U;
            vlSelfRef.tb_ozone_cdb__DOT__cdb_broadcast[2U] = 0U;
            vlSelfRef.tb_ozone_cdb__DOT__cdb_broadcast[3U] = 0U;
            vlSelfRef.tb_ozone_cdb__DOT__cdb_broadcast[4U] = 0U;
        } else {
            vlSelfRef.tb_ozone_cdb__DOT__cdb_broadcast[0U] 
                = vlSelfRef.tb_ozone_cdb__DOT__mem_req[0U];
            vlSelfRef.tb_ozone_cdb__DOT__cdb_broadcast[1U] 
                = vlSelfRef.tb_ozone_cdb__DOT__mem_req[1U];
            vlSelfRef.tb_ozone_cdb__DOT__cdb_broadcast[2U] 
                = vlSelfRef.tb_ozone_cdb__DOT__mem_req[2U];
            vlSelfRef.tb_ozone_cdb__DOT__cdb_broadcast[3U] 
                = vlSelfRef.tb_ozone_cdb__DOT__mem_req[3U];
            vlSelfRef.tb_ozone_cdb__DOT__cdb_broadcast[4U] 
                = vlSelfRef.tb_ozone_cdb__DOT__mem_req[4U];
            vlSelfRef.tb_ozone_cdb__DOT__mem_granted = 1U;
        }
    } else if ((2U & (IData)(tb_ozone_cdb__DOT__dut__DOT__unnamedblk1__DOT__winner))) {
        if ((1U & (IData)(tb_ozone_cdb__DOT__dut__DOT__unnamedblk1__DOT__winner))) {
            vlSelfRef.tb_ozone_cdb__DOT__cdb_broadcast[0U] 
                = vlSelfRef.tb_ozone_cdb__DOT__fpu_req[0U];
            vlSelfRef.tb_ozone_cdb__DOT__cdb_broadcast[1U] 
                = vlSelfRef.tb_ozone_cdb__DOT__fpu_req[1U];
            vlSelfRef.tb_ozone_cdb__DOT__cdb_broadcast[2U] 
                = vlSelfRef.tb_ozone_cdb__DOT__fpu_req[2U];
            vlSelfRef.tb_ozone_cdb__DOT__cdb_broadcast[3U] 
                = vlSelfRef.tb_ozone_cdb__DOT__fpu_req[3U];
            vlSelfRef.tb_ozone_cdb__DOT__cdb_broadcast[4U] 
                = vlSelfRef.tb_ozone_cdb__DOT__fpu_req[4U];
            vlSelfRef.tb_ozone_cdb__DOT__fpu_granted = 1U;
        } else {
            vlSelfRef.tb_ozone_cdb__DOT__cdb_broadcast[0U] 
                = vlSelfRef.tb_ozone_cdb__DOT__logic_req[0U];
            vlSelfRef.tb_ozone_cdb__DOT__cdb_broadcast[1U] 
                = vlSelfRef.tb_ozone_cdb__DOT__logic_req[1U];
            vlSelfRef.tb_ozone_cdb__DOT__cdb_broadcast[2U] 
                = vlSelfRef.tb_ozone_cdb__DOT__logic_req[2U];
            vlSelfRef.tb_ozone_cdb__DOT__cdb_broadcast[3U] 
                = vlSelfRef.tb_ozone_cdb__DOT__logic_req[3U];
            vlSelfRef.tb_ozone_cdb__DOT__cdb_broadcast[4U] 
                = vlSelfRef.tb_ozone_cdb__DOT__logic_req[4U];
            vlSelfRef.tb_ozone_cdb__DOT__logic_granted = 1U;
        }
    } else if ((1U & (IData)(tb_ozone_cdb__DOT__dut__DOT__unnamedblk1__DOT__winner))) {
        vlSelfRef.tb_ozone_cdb__DOT__cdb_broadcast[0U] 
            = vlSelfRef.tb_ozone_cdb__DOT__adder_req[0U];
        vlSelfRef.tb_ozone_cdb__DOT__cdb_broadcast[1U] 
            = vlSelfRef.tb_ozone_cdb__DOT__adder_req[1U];
        vlSelfRef.tb_ozone_cdb__DOT__cdb_broadcast[2U] 
            = vlSelfRef.tb_ozone_cdb__DOT__adder_req[2U];
        vlSelfRef.tb_ozone_cdb__DOT__cdb_broadcast[3U] 
            = vlSelfRef.tb_ozone_cdb__DOT__adder_req[3U];
        vlSelfRef.tb_ozone_cdb__DOT__cdb_broadcast[4U] 
            = vlSelfRef.tb_ozone_cdb__DOT__adder_req[4U];
        vlSelfRef.tb_ozone_cdb__DOT__adder_granted = 1U;
    } else {
        vlSelfRef.tb_ozone_cdb__DOT__cdb_broadcast[0U] = 0U;
        vlSelfRef.tb_ozone_cdb__DOT__cdb_broadcast[1U] = 0U;
        vlSelfRef.tb_ozone_cdb__DOT__cdb_broadcast[2U] = 0U;
        vlSelfRef.tb_ozone_cdb__DOT__cdb_broadcast[3U] = 0U;
        vlSelfRef.tb_ozone_cdb__DOT__cdb_broadcast[4U] = 0U;
    }
}

void Vtb_ozone_cdb___024root___eval_act(Vtb_ozone_cdb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ozone_cdb___024root___eval_act\n"); );
    Vtb_ozone_cdb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered[0U])) {
        Vtb_ozone_cdb___024root___act_sequent__TOP__0(vlSelf);
    }
}

void Vtb_ozone_cdb___024root___eval_nba(Vtb_ozone_cdb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ozone_cdb___024root___eval_nba\n"); );
    Vtb_ozone_cdb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VnbaTriggered[0U])) {
        Vtb_ozone_cdb___024root___act_sequent__TOP__0(vlSelf);
    }
}

void Vtb_ozone_cdb___024root___timing_resume(Vtb_ozone_cdb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ozone_cdb___024root___timing_resume\n"); );
    Vtb_ozone_cdb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VactTriggered[0U])) {
        vlSelfRef.__VdlySched.resume();
    }
}

void Vtb_ozone_cdb___024root___trigger_orInto__act_vec_vec(VlUnpacked<QData/*63:0*/, 1> &out, const VlUnpacked<QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ozone_cdb___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((IData)(1U) + n);
    } while ((0U >= n));
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_ozone_cdb___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag);
#endif  // VL_DEBUG

bool Vtb_ozone_cdb___024root___eval_phase__act(Vtb_ozone_cdb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ozone_cdb___024root___eval_phase__act\n"); );
    Vtb_ozone_cdb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_ozone_cdb___024root___eval_triggers_vec__act(vlSelf);
    Vtb_ozone_cdb___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VactTriggered, vlSelfRef.__VactTriggeredAcc);
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_ozone_cdb___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vtb_ozone_cdb___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = Vtb_ozone_cdb___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        vlSelfRef.__VactTriggeredAcc.fill(0ULL);
        Vtb_ozone_cdb___024root___timing_resume(vlSelf);
        Vtb_ozone_cdb___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_ozone_cdb___024root___eval_phase__inact(Vtb_ozone_cdb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ozone_cdb___024root___eval_phase__inact\n"); );
    Vtb_ozone_cdb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VinactExecute;
    // Body
    __VinactExecute = vlSelfRef.__VdlySched.awaitingZeroDelay();
    if (__VinactExecute) {
        VL_FATAL_MT("tb/tb_ozone_backend.sv", 4, "", "ZERODLY: Design Verilated with '--no-sched-zero-delay', but #0 delay executed at runtime");
    }
    return (__VinactExecute);
}

void Vtb_ozone_cdb___024root___trigger_clear__act(VlUnpacked<QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ozone_cdb___024root___trigger_clear__act\n"); );
    // Locals
    IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((IData)(1U) + n);
    } while ((1U > n));
}

bool Vtb_ozone_cdb___024root___eval_phase__nba(Vtb_ozone_cdb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ozone_cdb___024root___eval_phase__nba\n"); );
    Vtb_ozone_cdb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtb_ozone_cdb___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        Vtb_ozone_cdb___024root___eval_nba(vlSelf);
        Vtb_ozone_cdb___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

void Vtb_ozone_cdb___024root___eval(Vtb_ozone_cdb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ozone_cdb___024root___eval\n"); );
    Vtb_ozone_cdb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    IData/*31:0*/ __VnbaIterCount;
    // Body
    __VnbaIterCount = 0U;
    do {
        if (VL_UNLIKELY(((0x00000064U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            Vtb_ozone_cdb___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
            VL_FATAL_MT("tb/tb_ozone_backend.sv", 4, "", "DIDNOTCONVERGE: NBA region did not converge after '--converge-limit' of 100 tries");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        vlSelfRef.__VinactIterCount = 0U;
        do {
            if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VinactIterCount)))) {
                VL_FATAL_MT("tb/tb_ozone_backend.sv", 4, "", "DIDNOTCONVERGE: Inactive region did not converge after '--converge-limit' of 100 tries");
            }
            vlSelfRef.__VinactIterCount = ((IData)(1U) 
                                           + vlSelfRef.__VinactIterCount);
            vlSelfRef.__VactIterCount = 0U;
            do {
                if (VL_UNLIKELY(((0x00000064U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                    Vtb_ozone_cdb___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
                    VL_FATAL_MT("tb/tb_ozone_backend.sv", 4, "", "DIDNOTCONVERGE: Active region did not converge after '--converge-limit' of 100 tries");
                }
                vlSelfRef.__VactIterCount = ((IData)(1U) 
                                             + vlSelfRef.__VactIterCount);
                vlSelfRef.__VactPhaseResult = Vtb_ozone_cdb___024root___eval_phase__act(vlSelf);
            } while (vlSelfRef.__VactPhaseResult);
            vlSelfRef.__VinactPhaseResult = Vtb_ozone_cdb___024root___eval_phase__inact(vlSelf);
        } while (vlSelfRef.__VinactPhaseResult);
        vlSelfRef.__VnbaPhaseResult = Vtb_ozone_cdb___024root___eval_phase__nba(vlSelf);
    } while (vlSelfRef.__VnbaPhaseResult);
}

#ifdef VL_DEBUG
void Vtb_ozone_cdb___024root___eval_debug_assertions(Vtb_ozone_cdb___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_ozone_cdb___024root___eval_debug_assertions\n"); );
    Vtb_ozone_cdb__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
