
#include "load_store.h"

void init_ls_lookup()
{
    printf("Making load/store lookup table...\n");
    load_lookup[LB] = lb;
    load_lookup[LH] = lh;
    load_lookup[LW] = lw;
    load_lookup[LBU] = lbu;
    load_lookup[LHU] = lhu;

    store_lookup[SB] = sb;
    store_lookup[SH] = sh;
    store_lookup[SW] = sw;
}

void load_handle(RISCVM* vm, uint32_t instr)
{
    uint8_t funct3 = (instr >> 12) & 0x7;
    if (funct3 > 5) {
        illegal_mem_funct3(vm, instr);
    } else {
        (load_lookup[funct3])(vm, instr);
    }

}

void store_handle(RISCVM* vm, uint32_t instr)
{
    uint8_t funct3 = (instr >> 12) & 0x7;
    if (funct3 > 5) {
        illegal_mem_funct3(vm, instr);
    } else {
        (store_lookup[funct3])(vm, instr);
    }
}

void lb(RISCVM* vm, uint32_t instr)
{
    printf("Arrived at LB\n");    
}

void lh(RISCVM* vm, uint32_t instr)
{
    printf("Arrived at LH\n");    
}

void lw(RISCVM* vm, uint32_t instr)
{
    printf("Arrived at LW\n");    
}

void lbu(RISCVM* vm, uint32_t instr)
{
    printf("Arrived at LBU\n");    
}

void lhu(RISCVM* vm, uint32_t instr)
{
    printf("Arrived at LHU\n");
}

void sb(RISCVM* vm, uint32_t instr)
{
    printf("Arrived at SB\n");
}

void sh(RISCVM* vm, uint32_t instr)
{
    printf("Arrived at SH\n");
}

void sw(RISCVM* vm, uint32_t instr)
{
    printf("Arrived at SW\n");
}

void illegal_mem_funct3(RISCVM* vm, uint32_t instr)
{
   printf("Error: illegal load/store funct3 code\nPC: %x\nInstruction: %x\n", vm->registers[xPC], instr);
   free_vm(*vm);
   vm = NULL;
}
