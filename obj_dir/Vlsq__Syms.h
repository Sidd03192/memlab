// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VLSQ__SYMS_H_
#define VERILATED_VLSQ__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vlsq.h"

// INCLUDE MODULE CLASSES
#include "Vlsq___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) Vlsq__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vlsq* const __Vm_modelp;
    VlDeleter __Vm_deleter;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vlsq___024root                 TOP;

    // CONSTRUCTORS
    Vlsq__Syms(VerilatedContext* contextp, const char* namep, Vlsq* modelp);
    ~Vlsq__Syms();

    // METHODS
    const char* name() const { return TOP.vlNamep; }
};

#endif  // guard
