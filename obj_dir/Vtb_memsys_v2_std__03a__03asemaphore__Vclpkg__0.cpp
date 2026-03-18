// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_memsys_v2.h for the primary calling header

#include "Vtb_memsys_v2__pch.h"

Vtb_memsys_v2_std__03a__03asemaphore::Vtb_memsys_v2_std__03a__03asemaphore(Vtb_memsys_v2__Syms* __restrict vlSymsp, IData/*31:0*/ keyCount) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vtb_memsys_v2_std__03a__03asemaphore::new\n"); );
    // Body
    _ctor_var_reset(vlSymsp);
    this->__PVT__m_keyCount = keyCount;
}

void Vtb_memsys_v2_std__03a__03asemaphore::__VnoInFunc_put(Vtb_memsys_v2__Syms* __restrict vlSymsp, IData/*31:0*/ keyCount) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vtb_memsys_v2_std__03a__03asemaphore::__VnoInFunc_put\n"); );
    // Body
    this->__PVT__m_keyCount = (this->__PVT__m_keyCount 
                               + keyCount);
}

VlCoroutine Vtb_memsys_v2_std__03a__03asemaphore::__VnoInFunc_get(Vtb_memsys_v2__Syms* __restrict vlSymsp, IData/*31:0*/ keyCount) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vtb_memsys_v2_std__03a__03asemaphore::__VnoInFunc_get\n"); );
    // Body
    VL_KEEP_THIS;
    while (VL_LTS_III(32, this->__PVT__m_keyCount, keyCount)) {
        if (VL_LTS_III(32, this->__PVT__m_keyCount, keyCount)) {
            CData/*0:0*/ __VdynTrigger_he678b5df__0;
            __VdynTrigger_he678b5df__0 = 0;
            __VdynTrigger_he678b5df__0 = 0U;
            while ((1U & (~ (IData)(__VdynTrigger_he678b5df__0)))) {
                co_await vlSymsp->TOP.__VdynSched.evaluation(
                                                             nullptr, 
                                                             "@([true] (std::semaphore.m_keyCount >= std::semaphore.keyCount))", 
                                                             "/usr/local/share/verilator/include/verilated_std.sv", 
                                                             113);
                this->__Vtrigprevexpr_he0771350__0 
                    = VL_GTES_III(32, this->__PVT__m_keyCount, keyCount);
                __VdynTrigger_he678b5df__0 = this->__Vtrigprevexpr_he0771350__0;
                vlSymsp->TOP.__VdynSched.anyTriggered(__VdynTrigger_he678b5df__0);
            }
            co_await vlSymsp->TOP.__VdynSched.resumption(
                                                         nullptr, 
                                                         "@([true] (std::semaphore.m_keyCount >= std::semaphore.keyCount))", 
                                                         "/usr/local/share/verilator/include/verilated_std.sv", 
                                                         113);
        }
    }
    this->__PVT__m_keyCount = (this->__PVT__m_keyCount 
                               - keyCount);
    co_return;}

void Vtb_memsys_v2_std__03a__03asemaphore::__VnoInFunc_try_get(Vtb_memsys_v2__Syms* __restrict vlSymsp, IData/*31:0*/ keyCount, IData/*31:0*/ &try_get__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vtb_memsys_v2_std__03a__03asemaphore::__VnoInFunc_try_get\n"); );
    // Body
    {
        if (VL_GTES_III(32, this->__PVT__m_keyCount, keyCount)) {
            this->__PVT__m_keyCount = (this->__PVT__m_keyCount 
                                       - keyCount);
            try_get__Vfuncrtn = 1U;
            goto __Vlabel0;
        }
        try_get__Vfuncrtn = 0U;
        __Vlabel0: ;
    }
}

void Vtb_memsys_v2_std__03a__03asemaphore::_ctor_var_reset(Vtb_memsys_v2__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vtb_memsys_v2_std__03a__03asemaphore::_ctor_var_reset\n"); );
    // Body
    (void)vlSymsp;  // Prevent unused variable warning
    __PVT__m_keyCount = 0;
    __Vtrigprevexpr_he0771350__0 = 0;
}

std::string VL_TO_STRING(const VlClassRef<Vtb_memsys_v2_std__03a__03asemaphore>& obj) {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vtb_memsys_v2_std__03a__03asemaphore::VL_TO_STRING\n"); );
    // Body
    return (obj ? obj->to_string() : "null");
}

std::string Vtb_memsys_v2_std__03a__03asemaphore::to_string() const {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vtb_memsys_v2_std__03a__03asemaphore::to_string\n"); );
    // Body
    return ("'{"s + to_string_middle() + "}");
}

std::string Vtb_memsys_v2_std__03a__03asemaphore::to_string_middle() const {
    VL_DEBUG_IF(VL_DBG_MSGF("+            Vtb_memsys_v2_std__03a__03asemaphore::to_string_middle\n"); );
    // Body
    std::string out;
    out += "m_keyCount:" + VL_TO_STRING(__PVT__m_keyCount);
    return (out);
}
