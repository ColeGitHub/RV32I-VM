#ifndef LOAD_STORE_H
#define LOAD_STORE_H

#include <stdio.h>

#include "riscv.h"
#include "load_store.h"

enum // Load funct3 codes
{
    LB  = 0,
    LH  = 1,
    LW  = 2,
    LBU = 4,
    LHU = 5
};

enum // Store funct3 codes
{
    SB = 0,
    SH = 1,
    SW = 2
};

// Funct3 Lookup tables
void (*load_lookup[6])(RISCVM*, uint32_t);
void (*store_lookup[3])(RISCVM*, uint32_t);

// Init and Handle
void init_ls_lookup(void);
void load_handle(RISCVM* vm, uint32_t instr);
void store_handle(RISCVM* vm, uint32_t instr);

// Load/Store Ops
void lb(RISCVM* vm, uint32_t instr);
void lh(RISCVM* vm, uint32_t instr);
void lw(RISCVM* vm, uint32_t instr);
void lbu(RISCVM* vm, uint32_t instr);
void lhu(RISCVM* vm, uint32_t instr);
void sb(RISCVM* vm, uint32_t instr);
void sh(RISCVM* vm, uint32_t instr);
void sw(RISCVM* vm, uint32_t instr);
void illegal_mem_funct3(RISCVM* vm, uint32_t instr);
#endif
