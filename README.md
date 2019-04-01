# RV32I-VM: Virtual Machine for the RISC V 32-Bit Base Integer Instruction Set

This is a virtual implementation of the RISC-V 32-bit base integer instruction set outlined in chapter 2 of the [RISC-V User-Level ISA Specification](https://riscv.org/specifications/).
It's currently in the works but the idea is to pass a program assembled into RISC-V binary (or possibly an assembly file if I can find/make an assembler) and run it like any RISC-V architecture would.

### Todos
 
 - Implement branch instructions
 - Implement arithmetic instructions (R-type and I-type)
 - Implement system instructions (fence, ecall/ebreak, atomics)
 - Implement load/store instructions
 - Implement lui, auipc, jal, jalr
