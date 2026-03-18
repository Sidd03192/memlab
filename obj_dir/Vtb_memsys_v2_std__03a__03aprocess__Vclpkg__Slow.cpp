// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_memsys_v2.h for the primary calling header

#include "Vtb_memsys_v2__pch.h"

void Vtb_memsys_v2_std__03a__03aprocess__Vclpkg___ctor_var_reset(Vtb_memsys_v2_std__03a__03aprocess__Vclpkg* vlSelf);

Vtb_memsys_v2_std__03a__03aprocess__Vclpkg::Vtb_memsys_v2_std__03a__03aprocess__Vclpkg() = default;
Vtb_memsys_v2_std__03a__03aprocess__Vclpkg::~Vtb_memsys_v2_std__03a__03aprocess__Vclpkg() = default;

void Vtb_memsys_v2_std__03a__03aprocess__Vclpkg::ctor(Vtb_memsys_v2__Syms* symsp, const char* namep) {
    vlSymsp = symsp;
    vlNamep = strdup(Verilated::catName(vlSymsp->name(), namep));
    // Reset structure values
    Vtb_memsys_v2_std__03a__03aprocess__Vclpkg___ctor_var_reset(this);
}

void Vtb_memsys_v2_std__03a__03aprocess__Vclpkg::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

void Vtb_memsys_v2_std__03a__03aprocess__Vclpkg::dtor() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
