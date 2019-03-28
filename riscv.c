#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "riscv.h"

RISCVM init_vm() 
{
    RISCVM vm = {};
    vm.memory = malloc(MEM_SIZE * sizeof *vm.memory);
    vm.registers = malloc(REGISTER_COUNT * sizeof *vm.registers);

    return vm;
}

void free_vm(RISCVM vm)
{
    free(vm.memory);
    free(vm.registers);
}

uint32_t sign_ext(uint32_t x, int bit_count)
{
    if ((x >> (bit_count - 1)) & 1) {
        x |= (0xFFFFFFFF << bit_count);
    }
    return x;
}

void mem_read_word( RISCVM* vm, int address, int reg )
{
    // Loads 32 bit word into register "reg"
    // Takes advantage of conversion of four
    // consecutive uint8_t in memory to one
    // uint32_t

    uint32_t val; 
    uint32_t* val_ptr;
    
    if ( (address + 3) > (MEM_SIZE - 1)) {
        printf("ERROR: invalid memory access during mem_read_word()"); 
        printf(", continuing without writing to x%d\n", reg);
    } else {
        val_ptr = (uint32_t*) (vm->memory + address);
        val = *val_ptr; 
        vm->registers[reg] = val;
    }

}

void mem_read_half_word( RISCVM* vm, uint32_t address, int reg, int sign_flag )
{
    // Loads 16 bit "half world" into the lower 16 bits
    // of register "reg"
    uint32_t val;
    uint32_t* val_ptr;

    if ( (address + 1) > (MEM_SIZE - 1)) {
        printf("ERROR: invalid memory access during mem_read_half_word()"); 
        printf(", continuing without writing to x%d\n", reg);
    } else {
        val_ptr = (uint32_t*) (vm->memory + address);
        val = *val_ptr & 0x0000FFFF;

        if (sign_flag) {
            val = sign_ext(val, 16);
        } 

        vm->registers[reg] = val;
    }        
}

void mem_read_byte( RISCVM* vm, uint32_t address, int reg, int sign_flag )
{
    // Loads 8 bits into the lower 8 bits
    // of register "reg"
    uint32_t val = 0x000000FF;

    if (address > (MEM_SIZE - 1)) {
        printf("ERROR: invalid memory access during mem_read_byte()"); 
        printf(", continuing without writing to x%d\n", reg);
    } else {
        val &= (uint32_t) vm->memory[address];

        if (sign_flag) {
            val = sign_ext(val, 8);
        }

        vm->registers[reg] = val;
    }
}


void mem_write_word( RISCVM* vm, int address, int reg )
{
    // Writes a 32 bit word to four consecutive addresses
    // in memory
    uint8_t address_byte;
    int offset;
    uint32_t word = vm->registers[reg];
    
    if ( (address + 3) > (MEM_SIZE - 1) ){
        printf("ERROR: invalid memory access during mem_write_word()"); 
        printf(", continuing without writing to memory\n");
    } else {
        for (int i = 0; i < 4; i++) {
            offset = (uint32_t) i;     
            address_byte = (uint8_t) ((word >> (i * 8)) & 0xFF);
            vm->memory[address + offset] = address_byte;
        } 
    }
}

void mem_write_half_word( RISCVM* vm, uint32_t address, int reg )
{
    // Writes half a word to two consecutive addresses in memory
    uint8_t address_byte;
    uint32_t offset, word = vm->registers[reg];

    if ( (address + 1) > (MEM_SIZE - 1) ){
        printf("ERROR: invalid memory access during mem_write_half_word()"); 
        printf(", continuing without writing to memory\n");
    } else {
        for (int i = 0; i < 2; i++) {
            offset = (uint32_t) i;     
            address_byte = (uint8_t) (word >> (i * 8)) & 0xFF;
            vm->memory[address + offset] = address_byte;
        }
    }
}

void mem_write_byte( RISCVM* vm, uint32_t address, int reg )
{
    // Writes a byte to one address in memory
    uint32_t word = vm->registers[reg];
    
    if ( address > (MEM_SIZE - 1) ){
        printf("ERROR: invalid memory access during mem_write_byte()"); 
        printf(", continuing without writing to memory\n");
    } else {
        vm->memory[address] = (uint8_t) (word & 0xFF);
    }
}

void reg_write(RISCVM* vm, uint32_t value, int reg)
{
    if (reg > 0 && reg < REGISTER_COUNT) {
        vm->registers[reg] = value;
    } else {
        printf("Error: Illegal write to register x%d. Skipping write operation...\n", reg);
    }
}

uint32_t reg_read(RISCVM* vm, int reg)
{
    if (reg >= 0 && reg < REGISTER_COUNT) {
        return vm->registers[reg];
    } else {
        printf("Error: Illegal read from register x%d. Skipping read operation...\n", reg);
        return 0;
    }
}
