// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vlsq.h for the primary calling header

#include "Vlsq__pch.h"

void Vlsq___024root___ctor_var_reset(Vlsq___024root* vlSelf);

Vlsq___024root::Vlsq___024root(Vlsq__Syms* symsp, const char* namep)
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vlsq___024root___ctor_var_reset(this);
}

void Vlsq___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vlsq___024root::~Vlsq___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
