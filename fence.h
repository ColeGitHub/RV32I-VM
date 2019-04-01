#ifndef FENCE_H
#define FENCE_H

#include <stdio.h>

#include "riscv.h"

enum // Fence funct3 codes
{
    FENCE_ = 0,
    FENCEI = 1
};

int (*fence_lookup[2])(RISCVM*, uint32_t);

void init_fence_lookup(void);
int fence_handle(RISCVM* vm, uint32_t instr);

int fence(RISCVM* vm, uint32_t instr);
int fencei(RISCVM* vm, uint32_t instr);
int illegal_fence_funct3(RISCVM* vm, uint32_t instr);

#endif

