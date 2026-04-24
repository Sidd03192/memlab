// Compatibility shim so memsys/lsq can import ooo_pkg::*
// All types live in ozone_pkg; this package re-exports them.
package ooo_pkg;
    localparam int ROB_IDX_WIDTH = ozone_pkg::ROB_IDX_WIDTH;
    typedef ozone_pkg::cdb_broadcast_t cdb_broadcast_t;
endpackage
