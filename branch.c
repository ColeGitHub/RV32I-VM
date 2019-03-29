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

void branch_handle(RISCVM* vm, uint32_t instr)
{
    // Get bits [14:12] to get funct3 code,
    // use code in lookup table
    uint8_t funct3 = (instr >> 12) & 0x7;
    if (funct3 > 7) {
        illegal_branch_funct3(vm, instr);
    } else {
        (branch_lookup[funct3])(vm, instr);
    }
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

void illegal_branch_funct3(RISCVM* vm, uint32_t instr)
{
   printf("Error: illegal branch funct3 code\nPC: %x\nInstruction: %x\n", vm->registers[xPC], instr);
   free_vm(*vm);
   vm = NULL;
}
