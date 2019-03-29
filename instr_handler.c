#include "instr_handler.h"

void init_opcode_lookup()
{
    printf("Making opcode lookup table...\n");
    // This initializes the opcode lookup table
    // by first filling all elements with 
    // illegal opcode function then overwriting
    // indices using legal opcodes with actual
    // functions
    for (int i = 0; i < 29; i++)
    {
        opcode_lookup[i] = illegal_opcode;
    }

    // Overwrite with legal opcodes table 
    opcode_lookup[LUI] = lui;
    opcode_lookup[AUIPC] = auipc;
    opcode_lookup[JAL] = jal;
    opcode_lookup[JALR] = jalr; 
    opcode_lookup[BRANCH] = branch_handle;
    opcode_lookup[LOAD] = load_handle;
    opcode_lookup[STORE] = store_handle;
    opcode_lookup[IMM_ART] = arith_handle;
    opcode_lookup[ART] = arith_handle;
    opcode_lookup[FENCE] = fence_handle;
    opcode_lookup[SYS] = sys_handle;

    init_branch_lookup();
    init_ls_lookup();
    init_fence_lookup();
    init_arith_lookup();
    init_sys_lookup();
}

void handle(RISCVM* vm, uint32_t instr)
{
    uint8_t opcode = (instr >> 2) & 0x1F;
    if (opcode > 28) {
        illegal_opcode(vm, instr);
    } else {
        (opcode_lookup[opcode])(vm, instr);
    }
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
