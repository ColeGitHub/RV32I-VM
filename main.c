#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>

#include "riscv.h"
#include "instr_handler.h"


// BRANCH LOOKUP TEST
int main()
{
    printf("Starting VM...\n");

    // Initialize Virtual Machine Memory
    RISCVM vm_struct = init_vm();  
    RISCVM* vm = &vm_struct;
    
    // Check for proper memory allocation, exit on error

    if (vm_struct.memory == NULL || vm_struct.registers == NULL) {
        printf("VM does not have enough memory.  Exiting...\n");
        return 1;
    } else {
        printf("Memory allocated.\n");
    }

    init_opcode_lookup();
    
    uint32_t instr_test[43] = {
        0x37, // LUI
        0x17, // AUIPC
        0x6F, // JAL
        0x67, // JALR
        0x0063, // BEQ
        0x1063, // BNE
        0x4063, // BLT
        0x5063, // BGE
        0x6063, // BLTU
        0x7063, // BGEU
        0x0003, // LB
        0x1003, // LH
        0x2003, // LW
        0x4003, // LBU
        0x5003, // LHU
        0x0023, // SB
        0x1023, // SH
        0x2023, // SW
        0x0013, // ADDI
        0x2013, // SLTI
        0x3013, // SLTIU
        0x4013, // XORI
        0x6013, // ORI
        0x7013, // ANDI
        0x1013, // SLLI
        0x5013, // SRI
        0x0033, // ADD
        0x2033, // SLT
        0x3033, // SLTU
        0x4033, // XOR
        0x6033, // OR
        0x7033, // AND
        0x1033, // SLL
        0x5033, // SR
        0x000F, // FENCE
        0x100F, // FENCEI
        0x0073, // E INSTR (ECALL/EBREAK)
        0x1073, // CSRRW
        0x2073, // CSRRS
        0x3073, // CSRRC
        0x5073, // CSRRWI
        0x6073, // CSRRSI
        0x7073  // CSRRCI
    };

    for (int i = 0; i < 43; i++) {
        printf("Testing instruction %x: ", instr_test[i]);
        fflush(stdout);
        if (handle(vm, instr_test[i])) {
            free_vm(vm_struct);
            return 1;
        }
    }       
      
    // Free memory and exit
    free_vm(vm_struct);
    return 0;
}

