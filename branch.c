#include <stdio.h>
#include "branch.h"

// creating lookup table 
void init_branch_lookup() 
{
    printf("Making branch lookup table...\n");
    branch_lookup[BEQ] = beq;
    branch_lookup[BNE] = bne;
    branch_lookup[BLT] = blt;
    branch_lookup[BGE] = bge;
    branch_lookup[BLTU] = bltu;
    branch_lookup[BGEU] = bltu;

    branch_lookup[2] = illegal_branch_funct3;
    branch_lookup[3] = illegal_branch_funct3;
}

int branch_handle(RISCVM* vm, uint32_t instr)
{
    // Get bits [14:12] to get funct3 code,
    // use code in lookup table
    uint8_t funct3 = (instr >> 12) & 0x7;
    if (funct3 > 7) {
        return illegal_branch_funct3(vm, instr);
    } else {
        return (branch_lookup[funct3])(vm, instr);
    }
}

int beq(RISCVM* vm, uint32_t instr)
{
    printf("Arrived at BEQ\n");
    return 0;
}

int bne(RISCVM* vm, uint32_t instr)
{
    printf("Arrived at BNE\n");
    return 0;
}

int blt(RISCVM* vm, uint32_t instr)
{
    printf("Arrived at BLT\n");
    return 0;
}

int bge(RISCVM* vm, uint32_t instr)
{
    printf("Arrived at BGE\n");
    return 0;
}

int bltu(RISCVM* vm, uint32_t instr)
{
    printf("Arrived at BLTU\n");
    return 0;
}

int bgeu(RISCVM* vm, uint32_t instr)
{
    printf("Arrived at BGEU\n");
    return 0;
}

int illegal_branch_funct3(RISCVM* vm, uint32_t instr)
{
   printf("Error: illegal branch funct3 code\nPC: %x\nInstruction: %x\n", vm->registers[xPC], instr);
   return 1;
}
