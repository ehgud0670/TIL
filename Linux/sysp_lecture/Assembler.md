# Assembler(1)

## Overview 

* System S/W for translating programs written in assembly language to machine codes 

  * Most assemblers are very much alike, in this sense.

* Machine Dependent Features

  * Depend on machine instruction formats and addressing modes

* Machine Independent Features

  * Have no direct relation to machine architecture

## SIC assembler language program

### Two passes over the source program

> forward reference 가 문제다!

* The 1st pass just scans the source program for **label definitions** and **assign addresses.**
=> 처음부터 끝까지 쭉 스캐닝 한다. 모른건 넘어가고. 

* The 2nd pass performs most of **the actual translation previously described**


## Three Types of Records 

* Header record
  * H

* Text record
  * T

* End record
  * E 

## 2-pass Assembler

> Pass 1 : Define symbols

* **Read a statement** in a line of assembly code 
* **Assign an address** to this statement : increment N ( word addressing or byte addressing) ( 주소 할당하기 ) 
* **Save address values** assigned to **all labels (in symbol tables)** for use in pass 2 
* Perform some processing of assembler directives, such as **constant declaration or space reservation**

=> Pass1 usually writes an intermediate file( 중간 파일 ) that contains each source statement together with its assigned address, error indicators, etc.

> Pass 2 : Assemble instructions & generate object program 

* **Read in a line of code** : Intermediate file created in the 1 st pass is used as the input to the 2 nd pass

* Translate operation code, **using OP code Table**

* Change labels to addresses, **using Symbol Table**

* **Perform processing of assembler directives** not done during pass 1 
* **Produce object program** 

### 1. Operational Code Table(OPTAB)

* Contain mnemonic op code and its machine language equivalent.
<br>=> Also, it may contain variable-sized instruction format and length ( for more complex assemblers ) 

* In pass 1 , it is used to look up and validate(확인하다) mnemonic codes.
* In pass 2 , used to translate the op codes to machine language.
* Usually organized as a hash table 
  * key : mnemonic code
  * Fast retrieval with a minimum of searching
  * Once prepared , the OPTAB is not changed 

### 2. Symbol Table (SYMTAB)

* Include name and value (address) for each label in the source program, together with flags(error condition).

* In pass 1, labels are entered into SYMTAB with their assigned addresses (from LOCCTR : location counter)

* In pass 2, symbols used as operands are looked up in SYMBOL to obtain the addresses to be inserted in the assembled instructions.

* Usually hash table

## Machine-dependent Features

* Assembler depends on instruction format and addressing mode.

> "@"

=> Indirect addressing

> "+"

=> Format 4 instruction (extended format)

> "#"

=> Immediate addressing
