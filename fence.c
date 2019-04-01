#include "fence.h"

void init_fence_lookup()
{
    printf("Making fence lookup table...\n");
    fence_lookup[FENCE_] = fence;
    fence_lookup[FENCEI] = fencei;
}

int fence_handle(RISCVM* vm, uint32_t instr)
{
    uint8_t funct3 = (instr >> 12) & 0x7;
    if (funct3 > 1) {
        return illegal_fence_funct3(vm, instr);
    } else {
        return (fence_lookup[funct3])(vm, instr);
    }
}

int fence(RISCVM* vm, uint32_t instr)
{
    printf("Arrived at FENCE\n");
    return 0;
}

int fencei(RISCVM* vm, uint32_t instr)
{
    printf("Arrived at FENCEI\n");
    return 0;
}

int illegal_fence_funct3(RISCVM* vm, uint32_t instr)
{
   printf("Error: illegal fence funct3 code\nPC: %x\nInstruction: %x\n", vm->registers[xPC], instr);
   return 1;
}
