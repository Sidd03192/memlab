// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_memsys_v2.h for the primary calling header

#ifndef VERILATED_VTB_MEMSYS_V2_STD_H_
#define VERILATED_VTB_MEMSYS_V2_STD_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_memsys_v2__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_memsys_v2_std final {
  public:

    // INTERNAL VARIABLES
    Vtb_memsys_v2__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vtb_memsys_v2_std();
    ~Vtb_memsys_v2_std();
    void ctor(Vtb_memsys_v2__Syms* symsp, const char* namep);
    void dtor();
    VL_UNCOPYABLE(Vtb_memsys_v2_std);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
