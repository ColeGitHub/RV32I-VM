#ifndef ARITHMETIC_H
#define ARITHMETIC_H

#include <stdio.h>

#include "riscv.h"

enum // arithmetic funct3 codes
{
    ADD = 0,
    SLL = 1,
    SLT = 2,
    SLTU = 3,
    XOR = 4,
    SR = 5,
    OR = 6,
    AND = 7
};

int (*arith_lookup[8])(RISCVM*, uint32_t, uint8_t);

void init_arith_lookup(void);
int arith_handle(RISCVM* vm, uint32_t instr);

int add(RISCVM* vm, uint32_t instr, uint8_t imm_flag);
int sll(RISCVM* vm, uint32_t instr, uint8_t imm_flag);
int slt(RISCVM* vm, uint32_t instr, uint8_t imm_flag);
int sltu(RISCVM* vm, uint32_t instr, uint8_t imm_flag);
int _xor(RISCVM* vm, uint32_t instr, uint8_t imm_flag);
int sr(RISCVM* vm, uint32_t instr, uint8_t imm_flag);
int _or(RISCVM* vm, uint32_t instr, uint8_t imm_flag);
int _and(RISCVM* vm, uint32_t instr, uint8_t imm_flag);

int illegal_arith_funct3(RISCVM* vm, uint32_t instr);


#endif
