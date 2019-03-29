#include "fence.h"

void init_fence_lookup()
{
    printf("Making fence lookup table...\n");
    fence_lookup[FENCE_] = fence;
    fence_lookup[FENCEI] = fencei;
}

void fence_handle(RISCVM* vm, uint32_t instr)
{
    uint8_t funct3 = (instr >> 12) & 0x7;
    if (funct3 > 1) {
        illegal_fence_funct3(vm, instr);
    } else {
        (fence_lookup[funct3])(vm, instr);
    }
}

void fence(RISCVM* vm, uint32_t instr)
{
    printf("Arrived at FENCE\n");
}

void fencei(RISCVM* vm, uint32_t instr)
{
    printf("Arrived at FENCEI\n");
}

void illegal_fence_funct3(RISCVM* vm, uint32_t instr)
{
   printf("Error: illegal fence funct3 code\nPC: %x\nInstruction: %x\n", vm->registers[xPC], instr);
   free_vm(*vm);
   vm = NULL;
}
