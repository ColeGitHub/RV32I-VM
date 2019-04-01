#include <stdio.h>
#include "arith.h"

// creating lookup table 
void init_arith_lookup() 
{
    printf("Making arithmetic lookup table...\n");
    arith_lookup[ADD] = add;
    arith_lookup[SLL] = sll;
    arith_lookup[SLT] = slt;
    arith_lookup[SLTU] = sltu;
    arith_lookup[XOR] = _xor;
    arith_lookup[SR] = sr;
    arith_lookup[OR] = _or;
    arith_lookup[AND] = _and;
}

int arith_handle(RISCVM* vm, uint32_t instr)
{
    // Get bits [14:12] to get funct3 code,
    // use code in lookup table
    uint8_t funct3 = (instr >> 12) & 0x7;

    instr_args ia = {};
    ia.rd = vm->registers[(instr >> 7) & 0x1F];
    ia.rs1 = vm->registers[(instr >> 15) & 0x1F];
    ia.imm_flag = (instr >> 5) | 0x0;

    if (funct3 > 7) {
        return illegal_arith_funct3(vm, instr);
    } else {
        return (arith_lookup[funct3])(vm, instr, &ia);
    }
}

int add(RISCVM* vm, uint32_t instr, instr_args* args)
{
    // Runs ADD, ADDI, or SUB depending on whether 
    // the instruction is I-Type or R-Type and also
    // depending on funct7 (bit 30) value
    printf("Arrived at ADD\n");
    uint8_t rs2;
    uint32_t val;

    if (args->imm_flag) {
        // Imm Add
        val = reg_read(vm, args->rs1) + sign_ext((instr >> 20), IMM_SIZE);
    } else {
        rs2 = (instr >> 20) & 0x1F;

        if (instr >> 30) {
            // Subtraction 
            val = reg_read(vm, args->rs1) - reg_read(vm, rs2);
        } else {
            // Addition
            val = reg_read(vm, args->rs1) + reg_read(vm, rs2);
        }
    }
    
    reg_write(vm, args->rd, val);
    return 0;
}

int sll(RISCVM* vm, uint32_t instr, instr_args* args)
{
    // Shift Left Logical
    
    printf("Arrived at SLL\n");
    uint8_t rs2;
    uint32_t val;

    if (args->imm_flag) {
        // Imm Shift Left Logical
        val = reg_read(vm, args->rs1) << (instr >> 20);
    } else {
        // R Shift Left Logical
        rs2 = (instr >> 20) & 0x1F;
        val = reg_read(vm, args->rs1) << reg_read(vm, rs2);
    }

    reg_write(vm, args->rd, val);
    return 0;
}

int slt(RISCVM* vm, uint32_t instr, instr_args* args)
{
    // Set Less Than Operation

    printf("Arrived at SLT\n");
    uint8_t rs2;
    int val;

    if (args->imm_flag) {
        // Imm Set Less Than
        val = sign_ext((instr >> 20), IMM_SIZE);
    } else {
        // R Set Less Than
        rs2 = (instr >> 20) & 0x1F;
        val = reg_read(vm, rs2);
    }
    
    if (reg_read(vm, args->rs1) < val) {
        reg_write(vm, args->rd, 1);
    } else {
        reg_write(vm, args->rd, 0);
    }
    
    return 0;
}

int sltu(RISCVM* vm, uint32_t instr, instr_args* args)
{
    // Set Less Than Unsigned

    printf("Arrived at SLTU\n");

    uint8_t rs2;
    uint32_t val;

    if (args->imm_flag) {
        // Imm Set Less Than
        val = (instr >> 20);
    } else {
        // R Set Less Than
        rs2 = (instr >> 20) & 0x1F;
        val = reg_read(vm, rs2);
    }
    
    if (reg_read(vm, args->rs1) < val) {
        reg_write(vm, args->rd, 1);
    } else {
        reg_write(vm, args->rd, 0);
    }
    
    return 0;
}

int _xor(RISCVM* vm, uint32_t instr, instr_args* args)
{
    // XOR 

    printf("Arrived at XOR\n");

    uint8_t rs2;
    uint32_t val;

    if (args->imm_flag) {
        // Imm XOR
        val = sign_ext((instr >> 20), IMM_SIZE);
    } else {
        // R XOR
        rs2 = (instr >> 20) & 0x1F;
        val = reg_read(vm, rs2);
    }

    val ^= reg_read(vm, args->rs1); 
    reg_write(vm, args->rd, val);
    return 0;
}

int sr(RISCVM* vm, uint32_t instr, instr_args* args)
{
    // Handles logical/arithmetic shift right
    
    printf("Arrived at SR\n");

    uint32_t val, shamt = (instr >> 20) & 0x1F;
    int signed_rs1;

    // If not imm, change shamt
    if (!(args->imm_flag)) {
        shamt = reg_read(vm, shamt); 
    }

    // If arithmetic shift...
    if (instr >> 30) {
        // Arithmetic Shift
        signed_rs1 = (int) (reg_read(vm, args->rs1)); 
        val = (uint32_t) (signed_rs1 >> shamt); 
    } else {
        val = reg_read(vm, args->rs1) >> shamt;
    }
    
    reg_write(vm, args->rd, val);
    return 0;
}

int _or(RISCVM* vm, uint32_t instr, instr_args* args)
{
    printf("Arrived at OR\n");
    uint8_t rs2;
    uint32_t val;

    if (args->imm_flag) {
        // Imm OR
        val = sign_ext((instr >> 20), IMM_SIZE);
    } else {
        // R OR 
        rs2 = (instr >> 20) & 0x1F;
        val = reg_read(vm, rs2);
    }

    val |= reg_read(vm, args->rs1); 
    reg_write(vm, args->rd, val);
    return 0;
}

int _and(RISCVM* vm, uint32_t instr, instr_args* args)
{
    printf("Arrived at AND\n");

    uint8_t rs2;
    uint32_t val;

    if (args->imm_flag) {
        // Imm AND 
        val = sign_ext((instr >> 20), IMM_SIZE);
    } else {
        // R AND 
        rs2 = (instr >> 20) & 0x1F;
        val = reg_read(vm, rs2);
    }

    val &= reg_read(vm, args->rs1); 
    reg_write(vm, args->rd, val);
    return 0;
}

int illegal_arith_funct3(RISCVM* vm, uint32_t instr)
{
   printf("Error: illegal arith funct3 code\nPC: %x\nInstruction: %x\n", vm->registers[xPC], instr);
   return 1;
}
