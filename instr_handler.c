
#include "instr_handler.h"

void init_lookup()
{
    opcode_lookup[LUI] = utype_handle;
    opcode_lookup[AUIPC] = utype_handle;
    opcode_lookup[JAL] = utype_handle;
    opcode_lookup[JALR] = utype_handle; 
    opcode_lookup[BRANCH] = branch_handle;
    opcode_lookup[LOAD] = ls_handle;
    opcode_lookup[STORE] = ls_handle;
    opcode_lookup[IMM_ART] = arithmetic_handle;
    opcode_lookup[ART] = arithmetic_handle;
    opcode_lookup[FENCE] = fence_handle;
    opcode_lookup[SYS] = sys_handle;
}

void handle(RISCVM* vm, uint32_t instr)
{
    int opcode = (instr >> 2) & 0x1F;
    (opcode_lookup[opcode])(vm, instr);
}
