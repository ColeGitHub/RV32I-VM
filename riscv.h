// Header File for RISC-V VM
//


#ifndef RISCV_H
#define RISCV_H

#include <stdlib.h>
#include <stdint.h>


#define MEM_SIZE 10000 

enum // Registers
{
    x0 = 0, // Zero register
    x1,     // Return addr
    x2,     // Stack pointer
    x3,     // Global pointer
    x4,     // Thread pointer
    x5,     // tmp/alt link reg
    x6,     // tmp
    x7,     // tmp
    x8,     // Saved/frame pointer
    x9,     // saved
    x10,    // func args/rtn vals
    x11,    // " 
    x12,    // func args
    x13,    // "
    x14,    // "
    x15,    // "
    x16,    // "
    x17,    // "
    x18,    // saved
    x19,    // "
    x20,    // "
    x21,    // "
    x22,    // "
    x23,    // "
    x24,    // "
    x25,    // "
    x26,    // "
    x27,    // "
    x28,    // tmp
    x29,    // "
    x30,    // "
    x31,    // "
    xPC,    // Program Counter
    REGISTER_COUNT
};

typedef struct RISCVM
{
    uint32_t* registers;
    uint8_t* memory;
    
} RISCVM;


RISCVM init_vm(void);
void free_vm(RISCVM vm);
uint32_t sign_ext(uint32_t x, int bit_count);

int mem_read_word( RISCVM* vm, int address, int reg );
int mem_read_half_word( RISCVM* vm, uint32_t address, int reg, int sign_flag );
int mem_read_byte( RISCVM* vm, uint32_t address, int reg, int sign_flag );
int mem_write_word( RISCVM* vm, int address, int reg );
int mem_write_half_word( RISCVM* vm, uint32_t address, int reg );
int mem_write_byte( RISCVM* vm, uint32_t address, int reg );

void reg_write(RISCVM* vm, uint32_t value, int reg);
uint32_t reg_read(RISCVM* vm, int reg);

#endif
