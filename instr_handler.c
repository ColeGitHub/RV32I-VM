#include <stdio.h>

#include "instr_handler.h"

void init_opcode_lookup()
{
    // create opcode lookup table
    opcode_lookup[LUI] = lui;
    opcode_lookup[AUIPC] = auipc;
    opcode_lookup[JAL] = jal;
    opcode_lookup[JALR] = jalr; 
    opcode_lookup[BRANCH] = branch_handle;
    opcode_lookup[LOAD] = load_handle;
    opcode_lookup[STORE] = store_handle;
    opcode_lookup[IMM_ART] = arithmetic_handle;
    opcode_lookup[ART] = arithmetic_handle;
    opcode_lookup[FENCE] = fence_handle;
    opcode_lookup[SYS] = sys_handle;

    init_branch_lookup();
    init_load_lookup();
    init_store_lookup();
    init_arithmetic_lookup();
    init_sys_lookup();
}

void handle(RISCVM* vm, uint32_t instr)
{
    int opcode = (instr >> 2) & 0x1F;
    (opcode_lookup[opcode])(vm, instr);
}

void lui(RISCVM* vm, uint32_t instr)
{
    printf("LUI called\n");
}

void auipc(RISCVM* vm, uint32_t instr)
{
    printf("AUIPC called\n");
}

void jal(RISCVM* vm, uint32_t instr)
{
    printf("JAL called\n");
}

void jalr(RISCVM* vm, uint32_t instr)
{
    printf("JALR called\n");
}

void illegal_opcode(RISCVM* vm, uint32_t instr)
{
    printf("Error: illegal opcode\nPC: %x\nInstruction: %x\n", vm->registers[xPC], instr);
    free_vm(*vm);
    vm = NULL;
}
