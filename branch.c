#include <stdio.h>
#include "branch.h"

// creating lookup table 
void init_branch_lookup() 
{
    branch_lookup[BEQ] = beq;
    branch_lookup[BNE] = bne;
    branch_lookup[BLT] = blt;
    branch_lookup[BGE] = bge;
    branch_lookup[BLTU] = bltu;
    branch_lookup[BGEU] = bltu;
}

void branch_handle(RISCVM* vm, uint32_t instr)
{
    // Get bits [14:12] to get funct3 code,
    // use code in lookup table
    uint8_t funct3 = (instr >> 12) & 0x7;
    (branch_lookup[funct3])(vm, instr);
}

void beq(RISCVM* vm, uint32_t instr)
{
    printf("Arrived at BEQ\n");
}

void bne(RISCVM* vm, uint32_t instr)
{
    printf("Arrived at BNE\n");
}

void blt(RISCVM* vm, uint32_t instr)
{
    printf("Arrived at BNE\n");
}

void bge(RISCVM* vm, uint32_t instr)
{
    printf("Arrived at BNE\n");
}

void bltu(RISCVM* vm, uint32_t instr)
{
    printf("Arrived at BNE\n");
}

void bgeu(RISCVM* vm, uint32_t instr)
{
    printf("Arrived at BNE\n");
}
