#ifndef LOAD_STORE_H
#define LOAD_STORE_H

#include <stdint.h>

#include "riscv.h"
#include "load_store.h"

void ls_handle(RISCVM* vm, uint32_t instr);
void lb(RISCVM* vm, uint32_t instr);
void lh(RISCVM* vm, uint32_t instr);
void lw(RISCVM* vm, uint32_t instr);
void lbu(RISCVM* vm, uint32_t instr);
void lhu(RISCVM* vm, uint32_t instr);
void sb(RISCVM* vm, uint32_t instr);
void sh(RISCVM* vm, uint32_t instr);
void sw(RISCVM* vm, uint32_t instr);

#endif
