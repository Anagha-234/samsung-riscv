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

# Task 4: Functional Simulation of RISC-V Core
Objective: Perform a functional simulation of the given RISC-V Core Verilog netlist and testbench, verify the core’s correct operation, capture the simulation waveforms, and upload the results to GitHub.

Steps Completed:

Download Files:
Downloaded the Verilog netlist for the RISC-V Core from the provided “RISC-V Core Verilog Netlist.”
Downloaded the corresponding testbench from “Testbench for RISC-V Core.”

Set Up Simulation Environment:
Confirmed that the simulation tools are installed:
Icarus Verilog (iverilog) for compiling and running the simulation.
GTKWave for waveform viewing.
$ sudo apt update && upgrade
$ sudo apt install iverilog
$ sudo apt install gtkwave
$ iverilog
$ gtkwave

Using direct raw file links, you can use wget or curl to download files.
$ wget --no-check-certificate https://raw.githubusercontent.com/vinayrayapati/rv32i/refs/heads/main/iiitb_rv32i.v
$ wget --no-check-certificate https://raw.githubusercontent.com/vinayrayapati/rv32i/refs/heads/main/iiitb_rv32i_tb.v 

Loaded both the Verilog netlist and testbench into the simulation environment.
$ iverilog -o iiitb_rv32i iiitb_rv32i_tb.v iiitb_rv32i.v
$ vvp iiitb_rv32i
$ gtkwave iiitb_rv32i.vsd 

Add Relevant Signals:
Expand the module tree in the SST (Signal Selection Tree) panel.
Drag and drop important signals (e.g., clk, RN, NPC, WB_OUT) into the Waves panel.
PC (Program Counter):
This signal tells us which instruction is currently being fetched or is in a particular stage of the pipeline (often the fetch or write-back stage, depending on the design). In a 5-stage pipeline, the PC is usually passed along the pipeline stages.
WB_OUT (Write-Back Output):
This signal represents the final result of an instruction after it has been processed through all pipeline stages. For an arithmetic instruction like an addition, WB_OUT should hold the computed result.

Observation of output waveform
1. Instruction 1 at address 0x1000:
add r6, r2, r1
Expected behavior: Adds the contents of registers r2 and r1, storing the result in r6.

2. Instruction 2 at address 0x1004:
sub r3, r4, r5
Expected behavior: Subtracts r5 from r4 and stores the result in r3.

3. Instruction 3 at address 0x1008:
and r7, r8, r9
Expected behavior: Bitwise AND of r8 and r9, result stored in r7.

4. Instruction 4 at address 0x100C:
or r10, r1, r2
Expected behavior: Bitwise OR of r1 and r2, with the result stored in r10.

5. Instruction 5 at address 0x1010:
xor r11, r3, r4
Expected behavior: Bitwise XOR of r3 and r4, storing the result in r11.

6. Instruction 6 at address 0x1014:
slt r12, r5, r6
Expected behavior: Sets r12 to 1 if r5 is less than r6; otherwise, sets r12 to 0.

7. Instruction 7 at address 0x1018:
sll r13, r7, r1
Expected behavior: Shifts r7 left logically by the number of bits specified in r1; result stored in r13.

8. Instruction 8 at address 0x101C:
srl r14, r8, r2
Expected behavior: Shifts r8 right logically by the number of bits specified in r2; result stored in r14.

9. Instruction 9 at address 0x1020:
addi r15, r9, 10
Expected behavior: Adds the immediate value 10 to r9 and stores the result in r15.

10. Instruction 10 at address 0x1024:
andi r16, r10, 0xFF
Expected behavior: Performs a bitwise AND between r10 and the immediate 0xFF, storing the result in r16.

11. Instruction 11 at address 0x1028:
ori r17, r11, 0x1F
Expected behavior: Performs a bitwise OR between r11 and the immediate 0x1F, with the result stored in r17.

12. Instruction 12 at address 0x102C:
xori r18, r12, 0xA
Expected behavior: Performs a bitwise XOR between r12 and the immediate 0xA, with the result stored in r18.

13. Instruction 13 at address 0x1030:
lui r19, 0x1000
Expected behavior: Loads the upper 20 bits of r19 with 0x1000 (effectively setting r19 to 0x10000000 if the lower 12 bits are zero).

And observed full 5-stage instruction pipeline and pc-increment description waveform.

# Task 5: Documentation and Repository Update

## 📌 Overview
Task 5 focuses on updating the project repository with proper documentation, visuals, and pin details to ensure clarity and completeness.

## 📌 Project Name and Overview
**Project Name:** Button Press Counter on VSDSquadron Mini (RISC-V Board)

**Overview:** This project implements a button press counter using the **built-in button** available on the VSDSquadron Mini RISC-V Board. The button is connected to **GPIOA Pin 2**, and every button press is counted and displayed via **UART**. This approach eliminates the need for an external button and ensures ease of testing directly on the board.

---

## 🔹 Components Required
- **VSDSquadron Mini RISC-V Board** (with built-in button)

---

## 📌 Circuit Connection
Since the button is inbuilt, no external wiring is required. However, for reference, the table below details the key connections:

| **Pin**         | **Board Pin** | **Description** |
|----------------|-------------|----------------|
| **Button**     | GPIOA_2     | Built-in button input (Active Low) |
| **GND**        | GND         | Common ground connection |
| **UART_TX**    | PA9         | Serial output for debugging |
| **UART_RX**    | PA10        | Serial input (optional) |

---


