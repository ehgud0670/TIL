# SIC/XE Machine Architecture


* A **hypothetical computer** that includes the h/w features most often found on real machines, while avoiding unusual or irrelevant complexities.
<br>=> Separated from any specific implementation details, in order to understand the basic concepts of a piece of system software.

* Two versions with upward compatibility

1. SIC : the standard model
2. SIC/XE : the eXtra Equipment (or Expensive) model 

## SIC Machine Architecture

### 1. Memory

* Consists of 8-bit bytes; word : 3-bytes (i.e., 24bits)
* Maximum memory available : 32KB (i.e., 2^15 bytes)

### 2. Registers 

* 5 special purposed registers ( A, X, L, PC, SW)

1. A(0) : Accumulator
2. X(1) : Index register 
3. L(2) : Linkage register
4. PC(8) : Program Counter
5. SW(9) : Status Word

### 3.Data Formats

* Integers are stored as 24-bit binary numbers.
* Characters are stored using 8-bit ASCII codes.
* **No floating-point hardware**

### 4. Machine Instruction Formats 

| opcode | x | address | 
|--------|---|---------|
| 8bits  | 1bit | 15bits |
=> 총 24bits (1 word)

> Addressing Modes

* Direct addressing mode , when the flag bit, x = 0.
<br> => Target Address = address

* Indexed addressing mode , when the flag bit , x = 1.
<br> => Target Address = address + (X)

### 5. Instruction Set

* **Load** and **Store** registers : LDA, LDX, STA , STX, etc.
<br>=> LDA m ? A <- (m..m+2), where A, **m indicate a memory address** and register A, respectively.
<br>=> STA m? m..m+2 <- (A)

* Integer Arithmetic operations : ADD, SUB , MUL, DIV
<br>=> ADD m ? A <- (A) + (m..m+2)
<br>=> SUB m ? A <- (A) - (m..m+2)

* Comparision : COMP
<br>=> COMP m ? (A) : (m..m+2), meaning that it compares the value in register A with **a word** in memory, and **sets a condition code (CC) to indicate the result (<, =, or >)**

* Instruction Set (Continued)

  * Conditional jump : JLT, JEQ, JGT
    * JLT m : PC <- m if CC set to <
    <br> => These instructions test the setting of CC, and jump accordingly

  * Subroutine linkage: JSUB, RSUB
    * JSUB m ? L <- (PC); PC <- m
    <br> JSUB jumps to the subroutine, placing the return address in register L 
    * RSUB ? PC <- (L)
    <br> RSUB returns by jumping to the address contained in **register L**

### Input and Output 

* Performed by transferring 1 byte at a time to or from the rightmost 8 bits of register A
* Each device is assigned a unique 8-bit code
* 3 instructions: TD (test device), RD (read data) , WD (write data)
  * TD m , meaning that it tests if the device specified by (m) is ready to
send or receive a byte of data
  * RD m ? A [rightmost byte] ? data from device specified by (m)
  * WD m ? Device specified by (m) <- (A) [rightmost byte]

## SIC / XE Architecture

### Memory 

* Maximum meomory available : 1 MB (2^20 bytes)

### Registers 

* R registers at SIC ( A, X, L, PC, SW) + 4 additional ones (B, S, T and F)
  
  * **B (3) : Base register - used for addressing**
  * S(4) and T(5) : General working register - no special use
  * F(6) : Floating-point accumulator ( 48bits )

* Data Formats 

  * The same data formats as the standard version
  * **48-bit floating-point data type**, in addition

### Instruction Formats 

* Format 1 : No memory reference **(1 byte)**
<br> => opcode(8bit)? ????. ???? ?????. 
* Format 2 : No memory reference **(2 bytes)**, for register operations
<br> => register ? register ?? instruction. ???? ?????. 
<br> 8bit (opcode) + 4bit( register number ) + 4bit ( register number ) 

* Format 3 : Relative addressing **(3 bytes)**
=> Flag e = 0

| opcode | n | i | x | b | p | e | address | 
|--------|---|---|---|---|---|---|---------|
| 6bits  | 1bits | 1bits | 1bits | 1bits | 1bits | 1bits | 12bits |


* Format 4 : Address field extension to 20 bits **(4 bytes)**
<br>=> extended feild ? ??. 

| opcode | n | i | x | b | p | e | address | 
|--------|---|---|---|---|---|---|---------|
| 6bits  | 1bits | 1bits | 1bits | 1bits | 1bits | 1bits | 20bits |

: flag 'e'? **extended(???)** ? ????. 

> Addressing Modes 

* Relative addressing modes ( e = 0 ) for Format 3
  
  * Base relative addressing, when b = 1, p = 0 : TA = (B) + disp/addr
  * PC relative addressing, when b = 0, p = 1 : TA = (PC) + disp/addr 


* Direct addressing mode for Format 3 & 4 ( flag e = 0 || e = 1) 

  * b = p = 0 : TA = disp/addr

=> These addressing modes can be combined **with indexed addressing, when x=1,** the term (X) is added in the target address calculation.


* i and n bits in Format 3 and 4 are used to specify how the
target address is used.

  * i=1, n=0: immediate addressing, **no memory reference**, target address is used as operand value (????)

  * i=0, n=1: indirect addressing
  <br>=> ??

  * i=0, n=0: simple addressing for SIC

  * i= 1, n=1: simple addressing for SIC/XE

* If n=0 and i=0, b, p, and e are used as address fields (for upward compatible)
<br>=> SIC version 

* Indexing cannot be used with **immediate** or **indirect**
addressing mode.

### Instruction Set

* All instructions on standard version
* Load and Store registers: LDB, STB, etc.
* Floating-point arithmetic operations: ADDF, SUBF, MULF, DIVF
  * ADDF m ? F <- (F) + (m..m+5)
* Register-to-register instructions: RMO, ADDR, SUBR, MULR, DIVR
  * RMO r1, r2 ? r2 <- r1
  * ADDR r1, r2 ? r2 <- r2 + r1 

* Supervisor call : SVC 
  * SVC n
  => Generate SVC interrupt for communication with OS

### 3 types of functional statements: 

* Instructions: translated by the assembler into one or more bytes of object code, which executed at run time

* **Directives : tells the assembler to take some action.**

* Macro : "shorthand" for a sequence of other statements.

## CISC (Complex Instruction Set Computers)

* Large and complicated instruction sets provided

* Several different instruction formats and length

* Many different addressing modes

* Implementation in h/w tends to be complex 

## RISC (Reduced Instruction Set Computers)

* Small number of machine instructions, instruction formats, and addressing modes

* A standard, fixed instruction length , and single-cycle execution 

* Advantages:
  * simplify the design of processors
  * faster and less expensive processor developement
  * greater reliability, faster instruction execution times


