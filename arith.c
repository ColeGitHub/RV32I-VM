#include <stdio.h>
#include "arith.h"

// creating lookup table 
void init_arith_lookup() 
{
    printf("Making arithmetic lookup table...\n");
    arith_lookup[ADD] = add;
    arith_lookup[SLL] = sll;
    arith_lookup[SLT] = slt;
    arith_lookup[SLTU] = sltu;
    arith_lookup[XOR] = _xor;
    arith_lookup[SR] = sr;
    arith_lookup[OR] = _or;
    arith_lookup[AND] = _and;
}

void arith_handle(RISCVM* vm, uint32_t instr)
{
    // Get bits [14:12] to get funct3 code,
    // use code in lookup table
    uint8_t funct3 = (instr >> 12) & 0x7;
    uint8_t imm_flag = (instr >> 5) | 0x0;

    if (funct3 > 7) {
        illegal_arith_funct3(vm, instr);
    } else {
        (arith_lookup[funct3])(vm, instr, imm_flag);
    }
}

void add(RISCVM* vm, uint32_t instr, uint8_t imm_flag)
{
    // Remember to include condition for r-type SUB
    printf("Arrived at ADD\n");
}

void sll(RISCVM* vm, uint32_t instr, uint8_t imm_flag)
{
    printf("Arrived at SLL\n");
}

void slt(RISCVM* vm, uint32_t instr, uint8_t imm_flag)
{
    printf("Arrived at SLT\n");
}

void sltu(RISCVM* vm, uint32_t instr, uint8_t imm_flag)
{
    printf("Arrived at SLTU\n");
}

void _xor(RISCVM* vm, uint32_t instr, uint8_t imm_flag)
{
    printf("Arrived at XOR\n");
}

void sr(RISCVM* vm, uint32_t instr, uint8_t imm_flag)
{
    // Remember to add functionality for logical/arithmetic shift
    printf("Arrived at SR\n");
}

void _or(RISCVM* vm, uint32_t instr, uint8_t imm_flag)
{
    printf("Arrived at OR\n");
}

void _and(RISCVM* vm, uint32_t instr, uint8_t imm_flag)
{
    printf("Arrived at AND\n");
}

void illegal_arith_funct3(RISCVM* vm, uint32_t instr)
{
   printf("Error: illegal arith funct3 code\nPC: %x\nInstruction: %x\n", vm->registers[xPC], instr);
   free_vm(*vm);
   vm = NULL;
}
