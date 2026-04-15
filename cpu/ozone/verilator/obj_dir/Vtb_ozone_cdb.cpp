// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtb_ozone_cdb__pch.h"

//============================================================
// Constructors

Vtb_ozone_cdb::Vtb_ozone_cdb(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtb_ozone_cdb__Syms(contextp(), _vcname__, this)}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vtb_ozone_cdb::Vtb_ozone_cdb(const char* _vcname__)
    : Vtb_ozone_cdb(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtb_ozone_cdb::~Vtb_ozone_cdb() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtb_ozone_cdb___024root___eval_debug_assertions(Vtb_ozone_cdb___024root* vlSelf);
#endif  // VL_DEBUG
void Vtb_ozone_cdb___024root___eval_static(Vtb_ozone_cdb___024root* vlSelf);
void Vtb_ozone_cdb___024root___eval_initial(Vtb_ozone_cdb___024root* vlSelf);
void Vtb_ozone_cdb___024root___eval_settle(Vtb_ozone_cdb___024root* vlSelf);
void Vtb_ozone_cdb___024root___eval(Vtb_ozone_cdb___024root* vlSelf);

void Vtb_ozone_cdb::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtb_ozone_cdb::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vtb_ozone_cdb___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vtb_ozone_cdb___024root___eval_static(&(vlSymsp->TOP));
        Vtb_ozone_cdb___024root___eval_initial(&(vlSymsp->TOP));
        Vtb_ozone_cdb___024root___eval_settle(&(vlSymsp->TOP));
        vlSymsp->__Vm_didInit = true;
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vtb_ozone_cdb___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vtb_ozone_cdb::eventsPending() { return !vlSymsp->TOP.__VdlySched.empty() && !contextp()->gotFinish(); }

uint64_t Vtb_ozone_cdb::nextTimeSlot() { return vlSymsp->TOP.__VdlySched.nextTimeSlot(); }

//============================================================
// Utilities

const char* Vtb_ozone_cdb::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vtb_ozone_cdb___024root___eval_final(Vtb_ozone_cdb___024root* vlSelf);

VL_ATTR_COLD void Vtb_ozone_cdb::final() {
    Vtb_ozone_cdb___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtb_ozone_cdb::hierName() const { return vlSymsp->name(); }
const char* Vtb_ozone_cdb::modelName() const { return "Vtb_ozone_cdb"; }
unsigned Vtb_ozone_cdb::threads() const { return 1; }
void Vtb_ozone_cdb::prepareClone() const { contextp()->prepareClone(); }
void Vtb_ozone_cdb::atClone() const {
    contextp()->threadPoolpOnClone();
}
