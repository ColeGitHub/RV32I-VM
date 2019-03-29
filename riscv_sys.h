#ifndef SYS_H
#define SYS_H 

#include <stdio.h>
#include "riscv.h"

enum // sys funct3 codes
{
    E = 0,
    CSRRW = 1,
    CSRRS = 2,
    CSRRC = 3,
    CSRRWI = 5,
    CSRRSI = 6,
    CSRRCI = 7
};

void (*sys_lookup[8])(RISCVM*, uint32_t);

void init_sys_lookup(void);
void sys_handle(RISCVM* vm, uint32_t instr);

void e_instr(RISCVM* vm, uint32_t instr);
void csrrw(RISCVM* vm, uint32_t instr);
void csrrs(RISCVM* vm, uint32_t instr);
void csrrc(RISCVM* vm, uint32_t instr);
void csrrwi(RISCVM* vm, uint32_t instr);
void csrrsi(RISCVM* vm, uint32_t instr);
void csrrci(RISCVM* vm, uint32_t instr);
void illegal_sys_funct3(RISCVM* vm, uint32_t instr);

#endif
