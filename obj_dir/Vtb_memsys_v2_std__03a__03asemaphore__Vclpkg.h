// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_memsys_v2.h for the primary calling header

#ifndef VERILATED_VTB_MEMSYS_V2_STD__03A__03ASEMAPHORE__VCLPKG_H_
#define VERILATED_VTB_MEMSYS_V2_STD__03A__03ASEMAPHORE__VCLPKG_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_memsys_v2__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_memsys_v2_std__03a__03asemaphore__Vclpkg final {
  public:

    // INTERNAL VARIABLES
    Vtb_memsys_v2__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vtb_memsys_v2_std__03a__03asemaphore__Vclpkg();
    ~Vtb_memsys_v2_std__03a__03asemaphore__Vclpkg();
    void ctor(Vtb_memsys_v2__Syms* symsp, const char* namep);
    void dtor();
    VL_UNCOPYABLE(Vtb_memsys_v2_std__03a__03asemaphore__Vclpkg);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


class Vtb_memsys_v2__Syms;

class Vtb_memsys_v2_std__03a__03asemaphore : public virtual VlClass {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ __Vtrigprevexpr_he0771350__0;
    IData/*31:0*/ __PVT__m_keyCount;
    VlCoroutine __VnoInFunc_get(Vtb_memsys_v2__Syms* __restrict vlSymsp, IData/*31:0*/ keyCount);
    void __VnoInFunc_put(Vtb_memsys_v2__Syms* __restrict vlSymsp, IData/*31:0*/ keyCount);
    void __VnoInFunc_try_get(Vtb_memsys_v2__Syms* __restrict vlSymsp, IData/*31:0*/ keyCount, IData/*31:0*/ &try_get__Vfuncrtn);
  private:
    void _ctor_var_reset(Vtb_memsys_v2__Syms* __restrict vlSymsp);
  public:
    Vtb_memsys_v2_std__03a__03asemaphore(Vtb_memsys_v2__Syms* __restrict vlSymsp, IData/*31:0*/ keyCount);
    std::string to_string() const;
    std::string to_string_middle() const;
    ~Vtb_memsys_v2_std__03a__03asemaphore() {}
};

std::string VL_TO_STRING(const VlClassRef<Vtb_memsys_v2_std__03a__03asemaphore>& obj);

#endif  // guard
