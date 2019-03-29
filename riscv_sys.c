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

void sys_handle(RISCVM* vm, uint32_t instr)
{
    // Get bits [14:12] to get funct3 code,
    // use code in lookup table
    uint8_t funct3 = (instr >> 12) & 0x7;
    if (funct3 > 7) {
        illegal_sys_funct3(vm, instr);
    } else {
        (sys_lookup[funct3])(vm, instr);
    }
}

void e_instr(RISCVM* vm, uint32_t instr)
{
    // Add functionality for ecall/ebreak
    printf("Arrived at E Instruction\n");
}

void csrrw(RISCVM* vm, uint32_t instr)
{
    printf("Arrived at csrrw\n");
}

void csrrs(RISCVM* vm, uint32_t instr)
{
    printf("Arrived at csrrs\n");
}
void csrrc(RISCVM* vm, uint32_t instr)
{
    printf("Arrived at csrrc\n");
}
void csrrwi(RISCVM* vm, uint32_t instr)
{
    printf("Arrived at csrrwi\n");
}
void csrrsi(RISCVM* vm, uint32_t instr)
{
    printf("Arrived at csrrsi\n");
}
void csrrci(RISCVM* vm, uint32_t instr)
{
    printf("Arrived at csrrci\n");
}

void illegal_sys_funct3(RISCVM* vm, uint32_t instr)
{
   printf("Error: illegal sys funct3 code\nPC: %x\nInstruction: %x\n", vm->registers[xPC], instr);
   free_vm(*vm);
   vm = NULL;
}
