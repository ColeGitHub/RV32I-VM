
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

int load_handle(RISCVM* vm, uint32_t instr)
{
    uint8_t funct3 = (instr >> 12) & 0x7;
    if (funct3 > 5) {
        return illegal_mem_funct3(vm, instr);
    } else {
        return (load_lookup[funct3])(vm, instr);
    }

}

int store_handle(RISCVM* vm, uint32_t instr)
{
    uint8_t funct3 = (instr >> 12) & 0x7;
    if (funct3 > 5) {
        return illegal_mem_funct3(vm, instr);
    } else {
        return (store_lookup[funct3])(vm, instr);
    }
}

int lb(RISCVM* vm, uint32_t instr)
{
    printf("Arrived at LB\n");    
    return 0;
}

int lh(RISCVM* vm, uint32_t instr)
{
    printf("Arrived at LH\n");    
    return 0;
}

int lw(RISCVM* vm, uint32_t instr)
{
    printf("Arrived at LW\n");    
    return 0;
}

int lbu(RISCVM* vm, uint32_t instr)
{
    printf("Arrived at LBU\n");    
    return 0;
}

int lhu(RISCVM* vm, uint32_t instr)
{
    printf("Arrived at LHU\n");
    return 0;
}

int sb(RISCVM* vm, uint32_t instr)
{
    printf("Arrived at SB\n");
    return 0;
}

int sh(RISCVM* vm, uint32_t instr)
{
    printf("Arrived at SH\n");
    return 0;
}

int sw(RISCVM* vm, uint32_t instr)
{
    printf("Arrived at SW\n");
    return 0;
}

int illegal_mem_funct3(RISCVM* vm, uint32_t instr)
{
   printf("Error: illegal load/store funct3 code\nPC: %x\nInstruction: %x\n", vm->registers[xPC], instr);
   return 1;
}
