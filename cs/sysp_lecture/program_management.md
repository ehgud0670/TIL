# Program Management

## Overview 

* Preprocessor
<br>: Textual replacement on the input files(= �ܼ� ġȯ )
<br>: #define(��ũ�� ��� , ��ũ���Լ� ), #includes  ��� # ���� �ڵ�� <br>=> ������.

* Compiler
<br>: Syntax check 
<br>: Code generation 

* Assembler
<br>: Machine code translation
<br>: ������� -> ����(10101011...)�� ��ȯ

* Linker
<br>: Combine **multiple object codes and associated libraries** to excutables  


## Object code 

* gcc -c option 
=> -c �� linking �ϱ� ������ compile�ϴ� ��ɾ��.

* Object code 
<br>=> object code file�� ����� �� ������� ��ɾ��� �̷���� �ִ�.
<br>=> �׷��� ������Ʈ �ڵ�� �ٷ� ������� �ʴ´�. **-> linking required!**

## Linking 

* The process of bringing together **multiple pieces of object code [and libraries]** and arranging them into **an executable file** 

* Object code files must be linked to become an executable program that **can run**


> Compiler options 

| Stop after ... | gcc flag | Output produced |
|----------------|----------|-----------------|
| preprocessing  | -E       | modified source (streamed to stdout) | 
| compiling      | -S       | assembly code (code.s)
| assembling     | -C       | object code(code.o) |
| linking        | **none** | excutable(a.out) |  


## Makefile

* Makefile(s) are text files written in a certain prescribed syntax.

* Together with Make Utility, it helps build a software from its
source files, a way to organize code, and its compilation and
linking

* If none of the files that are prerequisites have been changed since
the last time the program was compiled, no actions take place.

* For large software projects, using Makefiles can substantially
reduce build times if only a few source files have changed.

* For large software projects, using Makefiles can substantially
reduce build times if only a few source files have changed.




