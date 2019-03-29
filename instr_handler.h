#ifndef INSTR_HANDLER_H
#define INSTR_HANDLER_H

#include <stdio.h>

#include "riscv.h"
#include "load_store.h"
#include "branch.h"
#include "arith.h"
#include "fence.h"
#include "riscv_sys.h"

enum // OP Codes
{
    LUI     = 0x0D,
    AUIPC   = 0x05, 
    JAL     = 0x1B,
    JALR    = 0x19,   
    BRANCH  = 0x18,
    LOAD    = 0x00,
    STORE   = 0x08,
    IMM_ART = 0x04,
    ART     = 0x0C,
    FENCE   = 0x03,
    SYS     = 0x1C
};

// Lookup Table for OP Codes
void (*opcode_lookup[29])(RISCVM*, uint32_t);

// Function Declarations
void init_opcode_lookup(void);
void handle(RISCVM* vm, uint32_t instr);
void lui(RISCVM* vm, uint32_t instr);
void auipc(RISCVM* vm, uint32_t instr);
void jal(RISCVM* vm, uint32_t instr);
void jalr(RISCVM* vm, uint32_t instr);
void illegal_opcode(RISCVM* vm, uint32_t instr);
#endif
