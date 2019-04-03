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

