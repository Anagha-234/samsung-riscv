# Samsung-RISC-V 
This repository contains the work related to various tasks based on RISC-V instruction analysis and simulation. The tasks involve understanding and working with the RISC-V toolchain, compiling C programs, optimizing code using different compiler flags, and decoding RISC-V instructions.

# Task 1: Setting Up the RISC-V Toolchain
Objective: Set up the RISC-V toolchain on my machine.
Steps:
Created a GitHub repository named "samsung-riscv".
Installed the RISC-V toolchain using the VDI link from the provided PDF.
Followed setup steps from the C-based and RISC-V-based lab videos.
Captured snapshots of the setup process and uploaded them.

# Task 2: RISC-V Optimization Flags and Object Dump Analysis
A simple C program was written to compute a basic task (Approximation of sine wave).
The program was compiled using RISC-V GCC/SPIKE with two different optimization flags: -O1 and -Ofast.
The RISC-V object dumps for both optimization levels were generated and analyzed to observe the differences in the resulting machine code.
Key Learning:
Optimization flags -O1 and -Ofast have a significant impact on the efficiency and performance of the generated machine code.
The object dumps were analyzed to understand how the compiler optimizes the program under different optimization levels.

# Task 3: RISC-V Instruction Breakdown and 32-Bit Encoding
Objective: Identify and decode 15 unique RISC-V instructions and determine their 32-bit instruction codes.
Steps:
Reviewed RISC-V documentation to understand instruction types (R, I, S, B, U, J).
Analyzed the riscv-objdump output to find 15 unique instructions.
Decoded each instruction into its 32-bit binary encoding and explained the components (opcode, funct3, funct7, etc.).
Uploaded the decoded instructions and explanations to the repository.
