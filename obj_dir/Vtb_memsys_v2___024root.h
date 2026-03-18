// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_memsys_v2.h for the primary calling header

#ifndef VERILATED_VTB_MEMSYS_V2___024ROOT_H_
#define VERILATED_VTB_MEMSYS_V2___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"
class Vtb_memsys_v2_std;
class Vtb_memsys_v2_std__03a__03aprocess__Vclpkg;
class Vtb_memsys_v2_std__03a__03asemaphore__Vclpkg;


class Vtb_memsys_v2__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_memsys_v2___024root final {
  public:
    // CELLS
    Vtb_memsys_v2_std* __PVT__std;
    Vtb_memsys_v2_std__03a__03asemaphore__Vclpkg* std__03a__03asemaphore__Vclpkg;
    Vtb_memsys_v2_std__03a__03aprocess__Vclpkg* std__03a__03aprocess__Vclpkg;

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ tb_memsys_v2__DOT__clk;
        CData/*0:0*/ tb_memsys_v2__DOT__rst_n;
        CData/*0:0*/ tb_memsys_v2__DOT__trace_valid;
        CData/*0:0*/ tb_memsys_v2__DOT__trace_ready;
        CData/*0:0*/ tb_memsys_v2__DOT__mem_req_valid;
        CData/*0:0*/ tb_memsys_v2__DOT__mem_req_is_write;
        CData/*0:0*/ tb_memsys_v2__DOT__mem_req_ready;
        CData/*0:0*/ tb_memsys_v2__DOT__mem_resp_valid;
        CData/*0:0*/ tb_memsys_v2__DOT__stopped_by_limit;
        CData/*0:0*/ tb_memsys_v2__DOT__reached_eof;
        CData/*0:0*/ tb_memsys_v2__DOT__dut__DOT__lsq_trace_valid;
        CData/*0:0*/ tb_memsys_v2__DOT__dut__DOT__tlb_ready;
        CData/*0:0*/ tb_memsys_v2__DOT__dut__DOT__tlb_valid;
        CData/*0:0*/ tb_memsys_v2__DOT__dut__DOT__is_tlb_fill_now;
        CData/*0:0*/ tb_memsys_v2__DOT__dut__DOT__lsq_valid_to_l1;
        CData/*2:0*/ tb_memsys_v2__DOT__dut__DOT__lsq_issue_op;
        CData/*0:0*/ tb_memsys_v2__DOT__dut__DOT__lsq_sq_ready;
        CData/*0:0*/ tb_memsys_v2__DOT__dut__DOT__issue_buf_valid;
        CData/*2:0*/ tb_memsys_v2__DOT__dut__DOT__issue_buf_op;
        CData/*0:0*/ tb_memsys_v2__DOT__dut__DOT__launch_issue_now;
        CData/*0:0*/ tb_memsys_v2__DOT__dut__DOT__tlb_start;
        CData/*0:0*/ tb_memsys_v2__DOT__dut__DOT__l2_l1_wb_ack;
        CData/*0:0*/ tb_memsys_v2__DOT__dut__DOT__l1_l2_req_valid;
        CData/*0:0*/ tb_memsys_v2__DOT__dut__DOT__l2_l1_data_valid;
        CData/*2:0*/ tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_head;
        CData/*2:0*/ tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_tail;
        CData/*2:0*/ tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_head;
        CData/*2:0*/ tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_tail;
        CData/*0:0*/ tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_found;
        CData/*2:0*/ tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_found_entry;
        CData/*0:0*/ tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__is_unresolved_store;
        CData/*0:0*/ tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found;
        CData/*2:0*/ tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_found_entry;
        CData/*0:0*/ tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_unresolved;
        CData/*0:0*/ tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__is_unresolved_load;
        CData/*0:0*/ tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unresolved_val_store;
        CData/*2:0*/ tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk13__DOT__unnamedblk14__DOT__idx;
        CData/*2:0*/ tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk15__DOT__unnamedblk16__DOT__idx;
        CData/*0:0*/ tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk17__DOT__resolve_done;
        CData/*2:0*/ tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk17__DOT__unnamedblk18__DOT__unnamedblk19__DOT__idx;
        CData/*0:0*/ tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk20__DOT__resolve_done;
        CData/*2:0*/ tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk20__DOT__unnamedblk21__DOT__unnamedblk22__DOT__idx;
        CData/*2:0*/ tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk23__DOT__unnamedblk24__DOT__idx;
        CData/*2:0*/ tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__unnamedblk25__DOT__unnamedblk26__DOT__idx;
        CData/*3:0*/ tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__hit_index;
        CData/*3:0*/ tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__free_index;
        CData/*0:0*/ tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__hit_found;
        CData/*3:0*/ tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__lru;
        CData/*2:0*/ tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__state;
        CData/*1:0*/ tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__curr_index;
        CData/*0:0*/ tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__curr_is_write;
        CData/*2:0*/ tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__curr_word_offset;
        CData/*0:0*/ tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__mshr_dup;
        CData/*0:0*/ tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__mshr_dup_idx;
        CData/*0:0*/ tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__evict_way_l;
        CData/*0:0*/ tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__mshr_install_done;
        CData/*0:0*/ tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_head;
        CData/*0:0*/ tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_tail;
        CData/*1:0*/ tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_count;
        CData/*0:0*/ tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_push;
        CData/*0:0*/ tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_pop;
        CData/*0:0*/ tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_empty;
        CData/*0:0*/ tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_full;
        CData/*0:0*/ tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__victim_dirty;
    };
    struct {
        CData/*0:0*/ tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__mshr_full;
        CData/*0:0*/ tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__mshr_free_idx;
        CData/*0:0*/ tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__hit;
        CData/*0:0*/ tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__hit_way;
        CData/*0:0*/ tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_issued_one;
        CData/*1:0*/ tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_head;
        CData/*1:0*/ tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_tail;
        CData/*2:0*/ tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_count;
        CData/*0:0*/ tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_push;
        CData/*0:0*/ tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_pop;
        CData/*0:0*/ tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_full;
        CData/*0:0*/ tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__req_hit;
        CData/*1:0*/ tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__req_hit_way;
        CData/*0:0*/ tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_dup;
        CData/*0:0*/ tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_full_l2;
        CData/*1:0*/ tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_free_idx;
        CData/*0:0*/ tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_hit;
        CData/*1:0*/ tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_hit_way;
        CData/*1:0*/ tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_victim_way;
        CData/*0:0*/ tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_found_invalid;
        CData/*0:0*/ tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_victim_dirty;
        CData/*0:0*/ tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_is_lru;
        CData/*0:0*/ tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_install_done;
        CData/*3:0*/ tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_inst_index;
        CData/*1:0*/ tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_inst_victim;
        CData/*0:0*/ tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_inst_found_invalid;
        CData/*0:0*/ tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_inst_victim_dirty;
        CData/*0:0*/ tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_inst_is_lru;
        CData/*0:0*/ __Vdly__tb_memsys_v2__DOT__dut__DOT__lsq_valid_to_l1;
        CData/*2:0*/ __Vdly__tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_tail;
        CData/*2:0*/ __Vdly__tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__state;
        CData/*1:0*/ __Vdly__tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_count;
        CData/*2:0*/ __Vdly__tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_count;
        CData/*0:0*/ __VdlySet__tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_vaddr__v0;
        CData/*1:0*/ __VdlyVal__tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_state__v0;
        CData/*2:0*/ __VdlyDim0__tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_state__v0;
        CData/*0:0*/ __VdlySet__tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_vaddr__v1;
        CData/*2:0*/ __VdlyDim0__tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_state__v1;
        CData/*0:0*/ __VdlySet__tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_vaddr__v2;
        CData/*2:0*/ __VdlyDim0__tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_state__v2;
        CData/*0:0*/ __VdlySet__tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_vaddr__v3;
        CData/*2:0*/ __VdlyDim0__tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_state__v3;
        CData/*0:0*/ __VdlySet__tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_vaddr__v4;
        CData/*2:0*/ __VdlyDim0__tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_state__v4;
        CData/*0:0*/ __VdlySet__tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_vaddr__v5;
        CData/*2:0*/ __VdlyDim0__tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_state__v5;
        CData/*0:0*/ __VdlySet__tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_vaddr__v6;
        CData/*2:0*/ __VdlyDim0__tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_state__v6;
        CData/*0:0*/ __VdlySet__tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_vaddr__v7;
        CData/*2:0*/ __VdlyDim0__tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_state__v7;
        CData/*0:0*/ __VdlySet__tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_vaddr__v8;
        CData/*2:0*/ __VdlyDim0__tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_state__v8;
        CData/*2:0*/ __VdlyDim0__tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_state__v9;
        CData/*0:0*/ __VdlySet__tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_state__v9;
        CData/*0:0*/ __VdlySet__tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_state__v10;
        CData/*0:0*/ __VdlySet__tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__mshr_state__v0;
        CData/*0:0*/ __VdlySet__tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__mshr_state__v1;
        CData/*0:0*/ __VdlySet__tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__mshr_paddr__v0;
        CData/*0:0*/ __VdlyDim0__tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__mshr_state__v2;
        CData/*0:0*/ __VdlySet__tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__mshr_block__v0;
        CData/*0:0*/ __VdlySet__tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__mshr_block__v1;
        CData/*0:0*/ __VdlySet__tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__mshr_state__v5;
        CData/*0:0*/ __VdlySet__tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_block__v0;
        CData/*0:0*/ __VdlySet__tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_block__v1;
    };
    struct {
        CData/*0:0*/ __VdlySet__tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_block__v2;
        CData/*0:0*/ __VdlySet__tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_block__v3;
        CData/*0:0*/ __VdlySet__tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_state__v4;
        CData/*0:0*/ __VdlySet__tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_state__v5;
        CData/*0:0*/ __VdlySet__tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_state__v6;
        CData/*0:0*/ __VdlySet__tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_state__v7;
        CData/*1:0*/ __VdlyDim0__tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_state__v8;
        CData/*0:0*/ __VdlySet__tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_state__v8;
        CData/*0:0*/ __VdlySet__tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_state__v9;
        CData/*0:0*/ __VdlySet__tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_state__v10;
        CData/*0:0*/ __VdlySet__tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_state__v11;
        CData/*0:0*/ __VdlySet__tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_state__v12;
        CData/*0:0*/ __VdlySet__tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__set_valids__v5;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_memsys_v2__DOT__clk__0;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_memsys_v2__DOT__rst_n__0;
        VlWide<4>/*120:0*/ tb_memsys_v2__DOT__trace_data;
        IData/*29:0*/ tb_memsys_v2__DOT__mem_req_addr;
        VlWide<16>/*511:0*/ tb_memsys_v2__DOT__mem_req_wdata;
        IData/*29:0*/ tb_memsys_v2__DOT__mem_resp_paddr;
        VlWide<16>/*511:0*/ tb_memsys_v2__DOT__mem_resp_rdata;
        IData/*31:0*/ tb_memsys_v2__DOT__cycle_ctr;
        IData/*31:0*/ tb_memsys_v2__DOT__checker_error_cnt;
        IData/*31:0*/ tb_memsys_v2__DOT__records_seen;
        IData/*31:0*/ tb_memsys_v2__DOT__records_sent;
        IData/*31:0*/ tb_memsys_v2__DOT__timeout_cycles;
        IData/*31:0*/ tb_memsys_v2__DOT__backing_memory__DOT__free_idx;
        VlWide<16>/*511:0*/ tb_memsys_v2__DOT__backing_memory__DOT__read_line;
        VlWide<4>/*120:0*/ tb_memsys_v2__DOT__drive_trace__DOT__packet;
        IData/*29:0*/ tb_memsys_v2__DOT__dut__DOT__tlb_result_paddr;
        IData/*29:0*/ tb_memsys_v2__DOT__dut__DOT__l1_l2_wb_paddr;
        VlWide<16>/*511:0*/ tb_memsys_v2__DOT__dut__DOT__l1_l2_wb_data;
        IData/*29:0*/ tb_memsys_v2__DOT__dut__DOT__l1_l2_req_paddr;
        IData/*29:0*/ tb_memsys_v2__DOT__dut__DOT__l2_l1_data_paddr;
        VlWide<16>/*511:0*/ tb_memsys_v2__DOT__dut__DOT__l2_l1_data;
        VlWide<16>/*511:0*/ tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__install_block;
        IData/*29:0*/ tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_push_paddr;
        VlWide<16>/*511:0*/ tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_push_data;
        IData/*29:0*/ tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__victim_paddr;
        VlWide<16>/*511:0*/ tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__victim_data;
        IData/*29:0*/ tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_push_paddr;
        VlWide<16>/*511:0*/ tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_push_data;
        IData/*19:0*/ tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_inst_tag;
        IData/*31:0*/ __Vdly__tb_memsys_v2__DOT__cycle_ctr;
        IData/*31:0*/ __VactIterCount;
        QData/*47:0*/ tb_memsys_v2__DOT__dut__DOT__lsq_vaddr_to_l1;
        QData/*63:0*/ tb_memsys_v2__DOT__dut__DOT__lsq_wdata_to_l1;
        QData/*47:0*/ tb_memsys_v2__DOT__dut__DOT__issue_buf_vaddr;
        QData/*63:0*/ tb_memsys_v2__DOT__dut__DOT__issue_buf_wdata;
        QData/*47:0*/ tb_memsys_v2__DOT__dut__DOT__tlb_vaddr_mux;
        QData/*63:0*/ tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__curr_wdata;
        VlUnpacked<CData/*7:0*/, 16> tb_memsys_v2__DOT__trace_buffer;
        VlUnpacked<CData/*2:0*/, 64> tb_memsys_v2__DOT__shadow_op;
        VlUnpacked<QData/*47:0*/, 64> tb_memsys_v2__DOT__shadow_vaddr;
        VlUnpacked<CData/*0:0*/, 64> tb_memsys_v2__DOT__shadow_vaddr_valid;
        VlUnpacked<QData/*63:0*/, 64> tb_memsys_v2__DOT__shadow_value;
        VlUnpacked<CData/*0:0*/, 64> tb_memsys_v2__DOT__shadow_value_valid;
        VlUnpacked<CData/*3:0*/, 64> tb_memsys_v2__DOT__shadow_id;
        VlUnpacked<IData/*31:0*/, 64> tb_memsys_v2__DOT__shadow_access_idx;
        VlUnpacked<CData/*0:0*/, 2048> tb_memsys_v2__DOT__tlb_map_valid;
        VlUnpacked<QData/*35:0*/, 2048> tb_memsys_v2__DOT__tlb_map_vpn;
        VlUnpacked<IData/*17:0*/, 2048> tb_memsys_v2__DOT__tlb_map_ptag;
        VlUnpacked<CData/*0:0*/, 32768> tb_memsys_v2__DOT__expected_valid;
        VlUnpacked<IData/*29:0*/, 32768> tb_memsys_v2__DOT__expected_paddr;
    };
    struct {
        VlUnpacked<QData/*47:0*/, 32768> tb_memsys_v2__DOT__expected_vaddr;
        VlUnpacked<QData/*63:0*/, 32768> tb_memsys_v2__DOT__expected_value;
        VlUnpacked<IData/*31:0*/, 32768> tb_memsys_v2__DOT__expected_last_access;
        VlUnpacked<CData/*0:0*/, 8192> tb_memsys_v2__DOT__line_valid;
        VlUnpacked<IData/*29:0*/, 8192> tb_memsys_v2__DOT__line_addr;
        VlUnpacked<VlWide<16>/*511:0*/, 8192> tb_memsys_v2__DOT__line_data;
        VlUnpacked<CData/*0:0*/, 32> tb_memsys_v2__DOT__pending_valid;
        VlUnpacked<IData/*29:0*/, 32> tb_memsys_v2__DOT__pending_addr;
        VlUnpacked<IData/*31:0*/, 32> tb_memsys_v2__DOT__pending_count;
        VlUnpacked<CData/*1:0*/, 8> tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_state;
        VlUnpacked<QData/*47:0*/, 8> tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_vaddr;
        VlUnpacked<CData/*3:0*/, 8> tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_id;
        VlUnpacked<CData/*7:0*/, 8> tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__lq_before_vec;
        VlUnpacked<CData/*2:0*/, 8> tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_state;
        VlUnpacked<QData/*47:0*/, 8> tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_vaddr;
        VlUnpacked<QData/*63:0*/, 8> tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_wdata;
        VlUnpacked<CData/*3:0*/, 8> tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_id;
        VlUnpacked<CData/*7:0*/, 8> tb_memsys_v2__DOT__dut__DOT__u_lsq__DOT__sq_before_vec;
        VlUnpacked<QData/*54:0*/, 16> tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__ways;
        VlUnpacked<SData/*15:0*/, 16> tb_memsys_v2__DOT__dut__DOT__u_tlb__DOT__lrumat;
        VlUnpacked<VlUnpacked<VlWide<16>/*511:0*/, 2>, 4> tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__set_contents;
        VlUnpacked<VlUnpacked<IData/*21:0*/, 2>, 4> tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__tags;
        VlUnpacked<CData/*1:0*/, 4> tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__set_valids;
        VlUnpacked<CData/*1:0*/, 4> tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__set_dirty;
        VlUnpacked<CData/*1:0*/, 2> tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__mshr_state;
        VlUnpacked<IData/*29:0*/, 2> tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__mshr_paddr;
        VlUnpacked<CData/*1:0*/, 2> tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__mshr_index;
        VlUnpacked<VlWide<16>/*511:0*/, 2> tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__mshr_block;
        VlUnpacked<CData/*7:0*/, 2> tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__mshr_store_mask;
        VlUnpacked<VlWide<16>/*511:0*/, 2> tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__mshr_store_data;
        VlUnpacked<IData/*29:0*/, 2> tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_paddr_q;
        VlUnpacked<VlWide<16>/*511:0*/, 2> tb_memsys_v2__DOT__dut__DOT__u_l1__DOT__wb_data_q;
        VlUnpacked<VlUnpacked<VlWide<16>/*511:0*/, 4>, 16> tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__set_contents;
        VlUnpacked<VlUnpacked<IData/*19:0*/, 4>, 16> tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__tags;
        VlUnpacked<CData/*3:0*/, 16> tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__set_valids;
        VlUnpacked<CData/*3:0*/, 16> tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__set_dirty;
        VlUnpacked<VlUnpacked<VlUnpacked<CData/*0:0*/, 4>, 4>, 16> tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__lru_matrix;
        VlUnpacked<CData/*1:0*/, 4> tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_state;
        VlUnpacked<IData/*29:0*/, 4> tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_paddr;
        VlUnpacked<VlWide<16>/*511:0*/, 4> tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_block;
        VlUnpacked<CData/*0:0*/, 4> tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__mshr_mem_issued;
        VlUnpacked<IData/*29:0*/, 4> tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_paddr_q;
        VlUnpacked<VlWide<16>/*511:0*/, 4> tb_memsys_v2__DOT__dut__DOT__u_l2__DOT__wb_data_q;
        VlUnpacked<QData/*63:0*/, 1> __VstlTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
        VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;
    };
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h510b650d__0;
    VlTriggerScheduler __VtrigSched_h510b654c__0;
    VlDynamicTriggerScheduler __VdynSched;

    // INTERNAL VARIABLES
    Vtb_memsys_v2__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vtb_memsys_v2___024root(Vtb_memsys_v2__Syms* symsp, const char* namep);
    ~Vtb_memsys_v2___024root();
    VL_UNCOPYABLE(Vtb_memsys_v2___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
