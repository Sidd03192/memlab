// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_ozone_backend.h for the primary calling header

#include "Vtb_ozone_backend__pch.h"

void Vtb_ozone_backend___024root___ctor_var_reset(Vtb_ozone_backend___024root* vlSelf);

Vtb_ozone_backend___024root::Vtb_ozone_backend___024root(Vtb_ozone_backend__Syms* symsp, const char* namep)
    : __VdlySched{*symsp->_vm_contextp__}
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vtb_ozone_backend___024root___ctor_var_reset(this);
}

void Vtb_ozone_backend___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtb_ozone_backend___024root::~Vtb_ozone_backend___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
