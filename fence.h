#ifndef FENCE_H
#define FENCE_H

#include <stdio.h>

#include "riscv.h"

enum // Fence funct3 codes
{
    FENCE_ = 0,
    FENCEI = 1
};

void (*fence_lookup[2])(RISCVM*, uint32_t);

void init_fence_lookup(void);
void fence_handle(RISCVM* vm, uint32_t instr);

void fence(RISCVM* vm, uint32_t instr);
void fencei(RISCVM* vm, uint32_t instr);
void illegal_fence_funct3(RISCVM* vm, uint32_t instr);

#endif

