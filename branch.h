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

int (*branch_lookup[8])(RISCVM*, uint32_t);

void init_branch_lookup(void);
int branch_handle(RISCVM* vm, uint32_t instr);

int beq(RISCVM* vm, uint32_t instr);
int bne(RISCVM* vm, uint32_t instr);
int blt(RISCVM* vm, uint32_t instr);
int bge(RISCVM* vm, uint32_t instr);
int bltu(RISCVM* vm, uint32_t instr);
int bgeu(RISCVM* vm, uint32_t instr);
int illegal_branch_funct3(RISCVM* vm, uint32_t instr);

#endif
