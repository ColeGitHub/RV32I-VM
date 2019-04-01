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
int (*load_lookup[6])(RISCVM*, uint32_t);
int (*store_lookup[3])(RISCVM*, uint32_t);

// Init and Handle
void init_ls_lookup(void);
int load_handle(RISCVM* vm, uint32_t instr);
int store_handle(RISCVM* vm, uint32_t instr);

// Load/Store Ops
int lb(RISCVM* vm, uint32_t instr);
int lh(RISCVM* vm, uint32_t instr);
int lw(RISCVM* vm, uint32_t instr);
int lbu(RISCVM* vm, uint32_t instr);
int lhu(RISCVM* vm, uint32_t instr);
int sb(RISCVM* vm, uint32_t instr);
int sh(RISCVM* vm, uint32_t instr);
int sw(RISCVM* vm, uint32_t instr);
int illegal_mem_funct3(RISCVM* vm, uint32_t instr);

#endif
