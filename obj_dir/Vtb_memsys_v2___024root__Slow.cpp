// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_memsys_v2.h for the primary calling header

#include "Vtb_memsys_v2__pch.h"

void Vtb_memsys_v2___024root___ctor_var_reset(Vtb_memsys_v2___024root* vlSelf);

Vtb_memsys_v2___024root::Vtb_memsys_v2___024root(Vtb_memsys_v2__Syms* symsp, const char* namep)
    : __VdlySched{*symsp->_vm_contextp__}
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vtb_memsys_v2___024root___ctor_var_reset(this);
}

void Vtb_memsys_v2___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtb_memsys_v2___024root::~Vtb_memsys_v2___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
