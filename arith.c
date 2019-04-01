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

int arith_handle(RISCVM* vm, uint32_t instr)
{
    // Get bits [14:12] to get funct3 code,
    // use code in lookup table
    uint8_t funct3 = (instr >> 12) & 0x7;
    uint8_t imm_flag = (instr >> 5) | 0x0;

    if (funct3 > 7) {
        return illegal_arith_funct3(vm, instr);
    } else {
        return (arith_lookup[funct3])(vm, instr, imm_flag);
    }
}

int add(RISCVM* vm, uint32_t instr, uint8_t imm_flag)
{
    // Remember to include condition for r-type SUB
    printf("Arrived at ADD\n");
    return 0;
}

int sll(RISCVM* vm, uint32_t instr, uint8_t imm_flag)
{
    printf("Arrived at SLL\n");
    return 0;
}

int slt(RISCVM* vm, uint32_t instr, uint8_t imm_flag)
{
    printf("Arrived at SLT\n");
    return 0;
}

int sltu(RISCVM* vm, uint32_t instr, uint8_t imm_flag)
{
    printf("Arrived at SLTU\n");
    return 0;
}

int _xor(RISCVM* vm, uint32_t instr, uint8_t imm_flag)
{
    printf("Arrived at XOR\n");
    return 0;
}

int sr(RISCVM* vm, uint32_t instr, uint8_t imm_flag)
{
    // Remember to add functionality for logical/arithmetic shift
    printf("Arrived at SR\n");
    return 0;
}

int _or(RISCVM* vm, uint32_t instr, uint8_t imm_flag)
{
    printf("Arrived at OR\n");
    return 0;
}

int _and(RISCVM* vm, uint32_t instr, uint8_t imm_flag)
{
    printf("Arrived at AND\n");
    return 0;
}

int illegal_arith_funct3(RISCVM* vm, uint32_t instr)
{
   printf("Error: illegal arith funct3 code\nPC: %x\nInstruction: %x\n", vm->registers[xPC], instr);
   return 1;
}
