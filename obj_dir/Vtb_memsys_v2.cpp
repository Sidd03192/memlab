// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtb_memsys_v2__pch.h"

//============================================================
// Constructors

Vtb_memsys_v2::Vtb_memsys_v2(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtb_memsys_v2__Syms(contextp(), _vcname__, this)}
    , __PVT__std{vlSymsp->TOP.__PVT__std}
    , std__03a__03asemaphore__Vclpkg{vlSymsp->TOP.std__03a__03asemaphore__Vclpkg}
    , std__03a__03aprocess__Vclpkg{vlSymsp->TOP.std__03a__03aprocess__Vclpkg}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vtb_memsys_v2::Vtb_memsys_v2(const char* _vcname__)
    : Vtb_memsys_v2(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtb_memsys_v2::~Vtb_memsys_v2() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtb_memsys_v2___024root___eval_debug_assertions(Vtb_memsys_v2___024root* vlSelf);
#endif  // VL_DEBUG
void Vtb_memsys_v2___024root___eval_static(Vtb_memsys_v2___024root* vlSelf);
void Vtb_memsys_v2___024root___eval_initial(Vtb_memsys_v2___024root* vlSelf);
void Vtb_memsys_v2___024root___eval_settle(Vtb_memsys_v2___024root* vlSelf);
void Vtb_memsys_v2___024root___eval(Vtb_memsys_v2___024root* vlSelf);

void Vtb_memsys_v2::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtb_memsys_v2::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtb_memsys_v2___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtb_memsys_v2___024root___eval_static(&(vlSymsp->TOP));
        Vtb_memsys_v2___024root___eval_initial(&(vlSymsp->TOP));
        Vtb_memsys_v2___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtb_memsys_v2___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vtb_memsys_v2::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t Vtb_memsys_v2::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vtb_memsys_v2::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtb_memsys_v2___024root___eval_final(Vtb_memsys_v2___024root* vlSelf);

VL_ATTR_COLD void Vtb_memsys_v2::final() {
    Vtb_memsys_v2___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtb_memsys_v2::hierName() const { return vlSymsp->name(); }
const char* Vtb_memsys_v2::modelName() const { return "Vtb_memsys_v2"; }
unsigned Vtb_memsys_v2::threads() const { return 1; }
void Vtb_memsys_v2::prepareClone() const { contextp()->prepareClone(); }
void Vtb_memsys_v2::atClone() const {
    contextp()->threadPoolpOnClone();
}
