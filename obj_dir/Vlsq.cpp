// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vlsq__pch.h"

//============================================================
// Constructors

Vlsq::Vlsq(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vlsq__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vlsq::Vlsq(const char* _vcname__)
    : Vlsq(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vlsq::~Vlsq() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vlsq___024root___eval_debug_assertions(Vlsq___024root* vlSelf);
#endif  // VL_DEBUG
void Vlsq___024root___eval_static(Vlsq___024root* vlSelf);
void Vlsq___024root___eval_initial(Vlsq___024root* vlSelf);
void Vlsq___024root___eval_settle(Vlsq___024root* vlSelf);
void Vlsq___024root___eval(Vlsq___024root* vlSelf);

void Vlsq::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vlsq::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vlsq___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vlsq___024root___eval_static(&(vlSymsp->TOP));
        Vlsq___024root___eval_initial(&(vlSymsp->TOP));
        Vlsq___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vlsq___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vlsq::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty(); }

uint64_t Vlsq::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vlsq::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vlsq___024root___eval_final(Vlsq___024root* vlSelf);

VL_ATTR_COLD void Vlsq::final() {
    Vlsq___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vlsq::hierName() const { return vlSymsp->name(); }
const char* Vlsq::modelName() const { return "Vlsq"; }
unsigned Vlsq::threads() const { return 1; }
void Vlsq::prepareClone() const { contextp()->prepareClone(); }
void Vlsq::atClone() const {
    contextp()->threadPoolpOnClone();
}
