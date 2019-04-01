#ifndef ARITHMETIC_H
#define ARITHMETIC_H

#include <stdio.h>

#include "riscv.h"

#define IMM_SIZE 12

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

typedef struct instr_args {
    uint8_t rd;
    uint8_t rs1;
    uint8_t imm_flag;
} instr_args;


int (*arith_lookup[8])(RISCVM*, uint32_t, instr_args*);

void init_arith_lookup(void);
int arith_handle(RISCVM* vm, uint32_t instr);

int add(RISCVM* vm, uint32_t instr, instr_args* args);
int sll(RISCVM* vm, uint32_t instr, instr_args* args);
int slt(RISCVM* vm, uint32_t instr, instr_args* args);
int sltu(RISCVM* vm, uint32_t instr, instr_args* args);
int _xor(RISCVM* vm, uint32_t instr, instr_args* args);
int sr(RISCVM* vm, uint32_t instr, instr_args* args);
int _or(RISCVM* vm, uint32_t instr, instr_args* args);
int _and(RISCVM* vm, uint32_t instr, instr_args* args);

int illegal_arith_funct3(RISCVM* vm, uint32_t instr);


#endif
