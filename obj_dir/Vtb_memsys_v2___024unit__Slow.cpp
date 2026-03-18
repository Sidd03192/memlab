// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_memsys_v2.h for the primary calling header

#include "Vtb_memsys_v2__pch.h"

void Vtb_memsys_v2___024unit___ctor_var_reset(Vtb_memsys_v2___024unit* vlSelf);

Vtb_memsys_v2___024unit::Vtb_memsys_v2___024unit() = default;
Vtb_memsys_v2___024unit::~Vtb_memsys_v2___024unit() = default;

void Vtb_memsys_v2___024unit::ctor(Vtb_memsys_v2__Syms* symsp, const char* namep) {
    vlSymsp = symsp;
    vlNamep = strdup(Verilated::catName(vlSymsp->name(), namep));
    // Reset structure values
    Vtb_memsys_v2___024unit___ctor_var_reset(this);
}

void Vtb_memsys_v2___024unit::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

void Vtb_memsys_v2___024unit::dtor() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
