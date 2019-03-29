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

   
      
    // Free memory and exit
    free_vm(vm_struct);
    return 0;
}

