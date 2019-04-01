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

int (*sys_lookup[8])(RISCVM*, uint32_t);

void init_sys_lookup(void);
int sys_handle(RISCVM* vm, uint32_t instr);

int e_instr(RISCVM* vm, uint32_t instr);
int csrrw(RISCVM* vm, uint32_t instr);
int csrrs(RISCVM* vm, uint32_t instr);
int csrrc(RISCVM* vm, uint32_t instr);
int csrrwi(RISCVM* vm, uint32_t instr);
int csrrsi(RISCVM* vm, uint32_t instr);
int csrrci(RISCVM* vm, uint32_t instr);
int illegal_sys_funct3(RISCVM* vm, uint32_t instr);

#endif
