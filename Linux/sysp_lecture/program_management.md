# Program Management

## Overview 

* Preprocessor
<br>: Textual replacement on the input files(= 단순 치환 )
<br>: #define(매크로 상수 , 매크로함수 ), #includes  등등 # 붙은 코드들 <br>=> 빠르다.

* Compiler
<br>: Syntax check 
<br>: Code generation 

* Assembler
<br>: Machine code translation
<br>: 어셈블리어 -> 기계어(10101011...)로 변환

* Linker
<br>: Combine **multiple object codes and associated libraries** to excutables  


## Object code 

* gcc -c option 
=> -c 는 linking 하기 전까지 compile하는 명령어다.

* Object code 
<br>=> object code file은 기계어로 된 구문들과 명령어들로 이루어져 있다.
<br>=> 그러나 오브젝트 코드는 바로 실행되지 않는다. **-> linking required!**

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




