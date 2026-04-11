| Opcode | uOPs                          | Notes                | Exceptions |
|--------|-------------------------------|----------------------|------------|
| LDUR   | AGU+RD                        |                      | Yes        |
| STUR   | AGU+WR                        |                      | Yes        |
| MOVK   | AND+OR                        |                      |            |
| MOVZ   | OR w/ XZR                     |                      |            |
| ADRP   | AND+ADD                       |                      |            |
| ADD    | ADD                           |                      |            |
| ADDS   | SHIFT+(ADD w/ flags)          |                      |            |
| CMN    | pseudo for ADDS               |                      |            |
| SUB    | ADD                           |                      |            |
| SUBS   | SHIFT+(ADD w/ flags)          |                      |            |
| CMP    | pseudo for SUBS               |                      |            |
| MVN    | pseudo for ORN                |                      |            |
| ORN    | SHIFT+(XOR w/ 1)+OR           |                      |            |
| ORR    | SHIFT+OR                      |                      |            |
| EOR    | SHIFT+XOR                     |                      |            |
| ANDS   | SHIFT+(AND w/ flags)          |                      |            |
| TST    | pseudo for ANDS               |                      |            |
| LSL    | pseudo for UBFM               |                      |            |
| LSL    | pseudo for LSLV               |                      |            |
| LSR    | pseudo for UBFM               |                      |            |
| LSR    | pseudo for LSRV               |                      |            |
| UBFM   | LSL or LSR                    | uop chosen in D      |            |
| SBFM   | ASR                           |                      |            |
| LSLV   | LSL                           |                      |            |
| LSRV   | LSR                           |                      |            |
| ASRV   | ASR                           |                      |            |
| ASR    | pseudo for ASRV               |                      |            |
| ASR    | pseudo for SBFM               |                      |            |
| B      | ADD                           | Speculative          |            |
| B.cond | COND_CHECK & ADD              | Speculative          |            |
| BL     | ADD & ADD                     | Speculative          |            |
| RET    | OR w/ XZR                     | Speculative          |            |
| NOP    | n/a                           |                      |            |
| ERET   | (OR w/ XZR) & (OR w/ XZR)     | On spl reg           | Yes        |
| MRS    | OR w/ XZR                     |                      | Yes        |
| MSR    | OR w/ XZR                     |                      | Yes        |
| SVC    | OR w/ XZR                     | On spl reg           | Yes        |
| LDUR   | AGU+RD                        |                      | Yes        |
| STUR   | AGU+WR                        |                      | Yes        |
| FMOV   | OR w/ XZR                     |                      |            |
| FNEG   | XOR                           |                      |            |
| FADD   | NAN_CHECK+FADD                |                      |            |
| FMUL   | NAN_CHECK+FMUL                |                      |            |
| FSUB   | NAN_CHECK+XOR+FADD            |                      |            |
| FCMP   | NAN_CHECK+(ADD w/ flags)      |                      | Yes        |