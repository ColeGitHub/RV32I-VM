#ifndef BRANCH_H
#define BRANCH_H

#include "riscv.h"

enum // branch funct3 codes
{
    BEQ  = 0,
    BNE  = 1,
    BLT  = 4,
    BGE  = 5,
    BLTU = 6,
    BGEU = 7
};

void (*branch_lookup[8])(RISCVM*, uint32_t);

void init_branch_lookup(void);
void branch_handle(RISCVM* vm, uint32_t instr);
void beq(RISCVM* vm, uint32_t instr);
void bne(RISCVM* vm, uint32_t instr);
void blt(RISCVM* vm, uint32_t instr);
void bge(RISCVM* vm, uint32_t instr);
void bltu(RISCVM* vm, uint32_t instr);
void bgeu(RISCVM* vm, uint32_t instr);

#endif
