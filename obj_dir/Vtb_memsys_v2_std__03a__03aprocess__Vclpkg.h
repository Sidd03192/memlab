// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_memsys_v2.h for the primary calling header

#ifndef VERILATED_VTB_MEMSYS_V2_STD__03A__03APROCESS__VCLPKG_H_
#define VERILATED_VTB_MEMSYS_V2_STD__03A__03APROCESS__VCLPKG_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"
class Vtb_memsys_v2_std__03a__03aprocess;


class Vtb_memsys_v2__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_memsys_v2_std__03a__03aprocess__Vclpkg final {
  public:

    // INTERNAL VARIABLES
    Vtb_memsys_v2__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vtb_memsys_v2_std__03a__03aprocess__Vclpkg();
    ~Vtb_memsys_v2_std__03a__03aprocess__Vclpkg();
    void ctor(Vtb_memsys_v2__Syms* symsp, const char* namep);
    void dtor();
    VL_UNCOPYABLE(Vtb_memsys_v2_std__03a__03aprocess__Vclpkg);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
    void __VnoInFunc_killQueue(Vtb_memsys_v2__Syms* __restrict vlSymsp, VlQueue<VlClassRef<Vtb_memsys_v2_std__03a__03aprocess>> &processQueue);
    void __VnoInFunc_self(VlProcessRef vlProcess, Vtb_memsys_v2__Syms* __restrict vlSymsp, VlClassRef<Vtb_memsys_v2_std__03a__03aprocess> &self__Vfuncrtn);
};


class Vtb_memsys_v2__Syms;

class Vtb_memsys_v2_std__03a__03aprocess : public virtual VlClass {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ __Vtrigprevexpr_h68fcf865__0;
    VlProcessRef __PVT__m_process;
    VlCoroutine __VnoInFunc_await(Vtb_memsys_v2__Syms* __restrict vlSymsp);
    void __VnoInFunc_get_randstate(Vtb_memsys_v2__Syms* __restrict vlSymsp, std::string &get_randstate__Vfuncrtn);
    void __VnoInFunc_kill(Vtb_memsys_v2__Syms* __restrict vlSymsp);
    void __VnoInFunc_resume(Vtb_memsys_v2__Syms* __restrict vlSymsp);
    void __VnoInFunc_set_randstate(Vtb_memsys_v2__Syms* __restrict vlSymsp, std::string s);
    void __VnoInFunc_set_status(Vtb_memsys_v2__Syms* __restrict vlSymsp, IData/*31:0*/ s);
    void __VnoInFunc_status(Vtb_memsys_v2__Syms* __restrict vlSymsp, IData/*31:0*/ &status__Vfuncrtn);
    void __VnoInFunc_suspend(Vtb_memsys_v2__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset(Vtb_memsys_v2__Syms* __restrict vlSymsp);
  public:
    Vtb_memsys_v2_std__03a__03aprocess(Vtb_memsys_v2__Syms* __restrict vlSymsp);
    std::string to_string() const;
    std::string to_string_middle() const;
    ~Vtb_memsys_v2_std__03a__03aprocess() {}
};

std::string VL_TO_STRING(const VlClassRef<Vtb_memsys_v2_std__03a__03aprocess>& obj);


//*** Below code from `systemc in Verilog file
// From `systemc at /usr/local/share/verilator/include/verilated_std.sv:196:21

template<> template<>
inline bool VlClassRef<Vtb_memsys_v2_std__03a__03aprocess>::operator==(const VlClassRef<Vtb_memsys_v2_std__03a__03aprocess>& rhs) const {
    if (!m_objp && !rhs.m_objp) return true;
    if (!m_objp || !rhs.m_objp) return false;
    return m_objp->__PVT__m_process == rhs.m_objp->__PVT__m_process;
};
template<> template<>
inline bool VlClassRef<Vtb_memsys_v2_std__03a__03aprocess>::operator!=(const VlClassRef<Vtb_memsys_v2_std__03a__03aprocess>& rhs) const {
    if (!m_objp && !rhs.m_objp) return false;
    if (!m_objp || !rhs.m_objp) return true;
    return m_objp->__PVT__m_process != rhs.m_objp->__PVT__m_process;
};
template<> template<>
inline bool VlClassRef<Vtb_memsys_v2_std__03a__03aprocess>::operator<(const VlClassRef<Vtb_memsys_v2_std__03a__03aprocess>& rhs) const {
    if (!m_objp && !rhs.m_objp) return false;
    if (!m_objp || !rhs.m_objp) return false;
    return m_objp->__PVT__m_process < rhs.m_objp->__PVT__m_process;
};
//*** Above code from `systemc in Verilog file


#endif  // guard
