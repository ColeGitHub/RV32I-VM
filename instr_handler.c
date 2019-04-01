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

int handle(RISCVM* vm, uint32_t instr)
{
    uint8_t opcode = instr & 0x7F;
   
    // Boundary check of opcode before sending to 
    // lookup table
    if (opcode < 3 || (opcode >> 2) > 28) { 
        return illegal_opcode(vm, instr);
    } else {
        opcode = opcode >> 2;
        return (opcode_lookup[opcode])(vm, instr);
    }
}

int lui(RISCVM* vm, uint32_t instr)
{
    printf("LUI called\n");
    return 0;
}

int auipc(RISCVM* vm, uint32_t instr)
{
    printf("AUIPC called\n");
    return 0;
}

int jal(RISCVM* vm, uint32_t instr)
{
    printf("JAL called\n");
    return 0;
}

int jalr(RISCVM* vm, uint32_t instr)
{
    printf("JALR called\n");
    return 0;
}

int illegal_opcode(RISCVM* vm, uint32_t instr)
{
    printf("Error: illegal opcode\nPC: %x\nInstruction: %x\n", vm->registers[xPC], instr);
    return 1;
}
