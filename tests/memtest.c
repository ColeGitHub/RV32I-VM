#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>

#include "riscv.h"


int main()
{
    RISCVM vm_struct = init_vm();  
    RISCVM* vm = &vm_struct;

    if (vm_struct.memory == NULL || vm_struct.registers == NULL) {
        printf("VM does not have enough memory.  Exiting...\n");
        return 1;
    } else {
        printf("Memory allocated.\n");
    }
    
    int address;
    uint32_t value;
    uint8_t byte;
  
    printf("Starting word read/write tests...\n");
    // Word read/write
    for (int i = 0; i < 2500; i++) {
        address = (uint32_t) (i * 4);
        vm->registers[x1] = address;
        mem_write_word( vm, address, x1 );
    }

    for (int i = 0; i < 2500; i++) {
        address = (uint32_t) (i * 4);
        mem_read_word( vm, address, x1 );
        value = address;
        if (vm->registers[x1] != value ){
            printf("Incorrect word write at address %d.  Exiting...", address);
            free_vm(vm_struct);
            return 1;
        }
    }

    printf("Word read/write tests complete.\n");
    printf("Starting half word writes...\n");

    // Half Word read/write
    for (int i = 0; i < 5000; i++) {
        address = (uint32_t) (i * 2);
        vm->registers[x1] = address & 0xFFFF;
        mem_write_half_word( vm, address, x1 );
    }

    printf("Half word write complete.\nStarting half word read zero ext...\n");
    for (int i = 0; i < 5000; i++) {
        address = (uint32_t) (i * 2);
        mem_read_half_word( vm, address, x1, 0);
        value = address & 0xFFFF;
        if (vm->registers[x1] != value ){
            printf("Incorrect half word write at address %d.  Exiting...", address);
            free_vm(vm_struct);
            return 1;
        }
    }

    printf("Half word read U complete.\nStarting half word read sign ext...\n");
    

    for (int i = 0; i < 5000; i++) {
        address = (uint32_t) (i * 2);
        mem_read_half_word( vm, address, x1, 1);
        address &= 0xFFFF;

        value = address & 0xFFFF;

        if ((value >> 15) & 1) {
            value |= 0xFFFF0000;
        }

        if (vm->registers[x1] != value ){
            printf("Incorrect half word write at address %d.  Exiting...", address);
            free_vm(vm_struct);
            return 1;
        }
    }

    printf("Half word read/write tests complete.\n");

    printf("Starting byte read/write tests...\n");

    // Byte read/write
    for (int i = 0; i < 10000; i++) {
        address = (uint32_t) i;
        vm->registers[x1] = address & 0xFF;
        mem_write_byte( vm, address, x1 );
    }

    for (int i = 0; i < 10000; i++) {
        address = (uint32_t) i;
        mem_read_byte( vm, address, x1, 0);
        value = address & 0xFF;
        if (vm->registers[x1] != value ){
            printf("Incorrect byte write at address %d.  Exiting...", address);
            free_vm(vm_struct);
            return 1;
        }
    }

    for (int i = 0; i < 10000; i++) {
        address = (uint32_t) i;
        mem_read_byte( vm, address, x1, 1);
        value = address & 0xFF;

        if ((value >> 7) & 1) {
            value |= 0xFFFFFF00;
        }

        if (vm->registers[x1] != value ){
            printf("Incorrect byte write at address %d.  Exiting...", address);
            free_vm(vm_struct);
            return 1;
        }
    }
    printf("Byte read/write tests complete.\n");
    free_vm(vm_struct);
    return 0;
}

