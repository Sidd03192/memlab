OTE: THIS IS A GROUP PROJECT.
FORM SELF-SELECTED GROUPS OF FOUR OR FIVE.
This lab has a lot of moving pieces, so please start early.

Definition
In this lab, you will be implement a memory subsystem for an out-of-order processor. You are encouraged to validate this using Verilator, but your final design is expected to be running on FPGA. Considering that you do not have the rest of the processor yet, you will be working with memory traces.

Specification
Hierarchy

Your memory hierarchy consists of the following components.

A combined load-store queue (LSQ) with 16 entries.
"Combined" means that there is a single hardware buffer which contains both loads and stores.
A PIVT non-blocking write-back L1 data cache.
2 MSHRs, 512B capacity, 2-way, 2-cycle latency.
A PIPT non-blocking write-back L2 data cache .
4 MSHRs, 4KiB capacity, 4-way, 5-cycle latency.
An L1 dTLB
16 entries, fully associative, 1-cycle latency.
Caches are inclusive (the contents of L1 are also in L2). All blocks are 64B. Your memory will have a 1GB physical memory and a 48-bit virtual memory. Replacement policy must be either LRU (using either the
bits method) or pseudo-LRU (using the tree LRU method) for all caches and TLB.

Traces

The traces are specified in binary according to the following SystemVerilog pseudocode:

typedef enum logic[2:0] {
OP_MEM_LOAD = 0, // perform a memory load
OP_MEM_STORE = 1, // send a memory store
OP_MEM_RESOLVE = 2, // resolve an unresolved address
OP_TLB_FILL = 4 // fill a line of the TLB
} op_e;
logic [120:0] trace_line;
op_e trace_op = trace_line[54:52];
logic [3:0] trace_id = trace_line[51:48];
logic [47:0] trace_vaddr = trace_line[47:0];
logic trace_vaddr_is_valid = trace_line[55]; // only relevant to mem operations
logic trace_value_is_valid = trace_line[120]; // only relevant to store operations
logic [63:0] trace_value = trace_line[119:56]; // only relevant to store operations
logic [29:0] trace_tlb_paddr = trace_line[85:56]; // only relevant to TLB fill operations
Remember that register renaming tracks register dependences while maintaining RAW; it does not track dependencies between the effective addresses of loads and stores. This is what the LSQ is used for.

To simulate out-of-order effects, memory operations come with valid bits as well as an ID for bookkeeping. LOADs and STOREs enter the queue in order, but their effective addresses may be resolved out-of-order. For stores, the value may also be resolved out-of-order. In this case, a RESOLVE operation will appear with the same ID as the previous memory op. Once resolved, dependences between effective addresses can be checked, and run freely.

You're encouraged to simulate this using Verilator, but the final demo must be running on FPGAs. On Verilator, physical memory can be simulated with a large array of bytes. On the FPGA, physical memory will be accessed using the DRAM controller. You will reuse the modules you make in future labs.

All work is expected to be done at the RTL level.

Logistics
Work in groups of four or five. You must not do this assignment individually. You must remain in your chosen group for the duration of the assignment.
Traces as well as results (dumps of the cache on trace completion, etc.) will be given at the start of week 2.
This assignment is worth 100 points. The base design is worth only 90 points. You may implement additional features to earn extra credit.
Grading
On the base design, you will get full credit (90 points) immediately if the TA is able to reproduce traces which conform to the gold standard using your design on an FPGA. Otherwise, partial credit will be given according to the following breakdown.

(30 points) LSQ
(20 points) Data caches
(20 points) TLB
(20 points) FPGA
Extra Credit [Subject to change or update]

(15 points) Use separate load and store queues rather than a combined queue.
(15 points) Make the data caches pipelined in addition to being non-blocking.
(20 points) Use a different replacement policy than LRU. Record data to show its performance in comparison to baseline algorithm in terms of misses per kilo instructions (MPKI). Good candidates are RRIP policies. Ask the teaching staff if you'd like more pointers here.
(20 points) Add a prefetcher. Record data data to show its performance in comparison to no prefetcher in terms of misses per kilo instructions (MPKI). Good candidates are stride prefetchers. Ask the teaching staff if you'd like more pointers here.
(30 points) Make your design parameterized.
Submission
You'll submit a zip file or tarball containing at least:

Your SystemVerilog file(s)
Your design's raw binary (.rbf) file.
Your design's device tree (.dtb) file.
Your C file(s) for sending traces to the FPGA.
Some sort of README or Makefile explaining how the TA can reproduce your results.
Tips and Resources
When dealing with communication between modules, it's useful to follow a protocol so no one speaks out of turn. In the floating point lab, you used a ready-valid protocolLinks to an external site.. Feel free to use this protocol again.
In this hierarchy, a module may receive requests from both higher and lower in the hierarchy at the same time (with L1 being the highest level cache). As a rule of thumb, when arbitrating, prioritize going up the hierarchy. This prevents deadlock.
The FPGAs have limited resources, and Quartus can report your usage statistics as a percentage.
This DE10 Nano guide on GitHubLinks to an external site. has section called "SDRAM communication".
The Wikipedia page for SDRAM control signalsLinks to an external site. and its child pages are a good general reference. Prefer the guide above for DE10 specific-information.
