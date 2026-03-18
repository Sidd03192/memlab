// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTB_MEMSYS_V2__SYMS_H_
#define VERILATED_VTB_MEMSYS_V2__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vtb_memsys_v2.h"

// INCLUDE MODULE CLASSES
#include "Vtb_memsys_v2___024root.h"
#include "Vtb_memsys_v2___024unit.h"
#include "Vtb_memsys_v2_std.h"
#include "Vtb_memsys_v2_std__03a__03asemaphore__Vclpkg.h"
#include "Vtb_memsys_v2_std__03a__03aprocess__Vclpkg.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) Vtb_memsys_v2__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtb_memsys_v2* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vtb_memsys_v2___024root        TOP;
    Vtb_memsys_v2_std              TOP__std;
    Vtb_memsys_v2_std__03a__03aprocess__Vclpkg TOP__std__03a__03aprocess__Vclpkg;
    Vtb_memsys_v2_std__03a__03asemaphore__Vclpkg TOP__std__03a__03asemaphore__Vclpkg;

    // CONSTRUCTORS
    Vtb_memsys_v2__Syms(VerilatedContext* contextp, const char* namep, Vtb_memsys_v2* modelp);
    ~Vtb_memsys_v2__Syms();

    // METHODS
    const char* name() const { return TOP.vlNamep; }
};

#endif  // guard
