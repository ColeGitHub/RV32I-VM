#include <stdio.h>
#include "riscv_sys.h"

// creating lookup table 
void init_sys_lookup() 
{
    sys_lookup[E] = e_instr;
    sys_lookup[CSRRW] = csrrw;
    sys_lookup[CSRRS] = csrrs;
    sys_lookup[CSRRC] = csrrc;
    sys_lookup[CSRRWI] = csrrwi;
    sys_lookup[CSRRSI] = csrrsi;
    sys_lookup[CSRRCI] = csrrci;

    sys_lookup[4] = illegal_sys_funct3;
}

int sys_handle(RISCVM* vm, uint32_t instr)
{
    // Get bits [14:12] to get funct3 code,
    // use code in lookup table
    uint8_t funct3 = (instr >> 12) & 0x7;
    if (funct3 > 7) {
        return illegal_sys_funct3(vm, instr);
    } else {
        return (sys_lookup[funct3])(vm, instr);
    }
}

int e_instr(RISCVM* vm, uint32_t instr)
{
    // Add functionality for ecall/ebreak
    printf("Arrived at E Instruction\n");
    return 0;
}

int csrrw(RISCVM* vm, uint32_t instr)
{
    printf("Arrived at csrrw\n");
    return 0;
}

int csrrs(RISCVM* vm, uint32_t instr)
{
    printf("Arrived at csrrs\n");
    return 0;
}
int csrrc(RISCVM* vm, uint32_t instr)
{
    printf("Arrived at csrrc\n");
    return 0;
}
int csrrwi(RISCVM* vm, uint32_t instr)
{
    printf("Arrived at csrrwi\n");
    return 0;
}
int csrrsi(RISCVM* vm, uint32_t instr)
{
    printf("Arrived at csrrsi\n");
    return 0;
}
int csrrci(RISCVM* vm, uint32_t instr)
{
    printf("Arrived at csrrci\n");
    return 0;
}

int illegal_sys_funct3(RISCVM* vm, uint32_t instr)
{
   printf("Error: illegal sys funct3 code\nPC: %x\nInstruction: %x\n", vm->registers[xPC], instr);
   return 1;
}
