#include <stdio.h>
#include "branch.h"

void beq(RISCVM* vm, uint32_t instr)
{
    printf("Arrived at BEQ");
}

void bne(RISCVM* vm, uint32_t instr)
{
    printf("Arrived at BNE");
}

void blt(RISCVM* vm, uint32_t instr)
{
    printf("Arrived at BNE");
}

void bge(RISCVM* vm, uint32_t instr)
{
    printf("Arrived at BNE");
}

void bltu(RISCVM* vm, uint32_t instr)
{
    printf("Arrived at BNE");
}

void bgeu(RISCVM* vm, uint32_t instr)
{
    printf("Arrived at BNE");
}
