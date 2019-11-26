# Input Output

## Streams

* Any input or output transaction can be viewed as **a flow of bytes(= stream)** from a source to a destination.
* (2) The OS creates and manages streams based upon **the function calls** made by the program.

=> fopen, fread, fclose �� f�� ���� �Լ��� system call�� �ƴ� function call�̴�.

## O/S automatically creates three streams 

* Standard in (stdin)
=> it connects **keyboard** to program

* Standard out (stdout)
=> it connects program to **display(monitor)**

* Standard error (stderr)
=> It connects program to a secondary display that is intended only for displaying errors
<br>=> stderr stream is intended as a backup output stream for programs

## Buffers 

* **Temporary storage** between **sender and receiver of bytes on a stream**

> Why buffers?

* Buffers are storage or the ��middle men�� between two
communication devices

=> What if the sender puts bytes into the stream **faster than the receiver can handle?** : so buffer is required!

=> What if a program is **in the middle of a calculation** and is not prepared to receive any bytes? : so buffer is required!

* The buffer stores the bytes until the program is ready

## Flushing

* The act of emptying out the temporary storage
=> ���ۿ� �ִ� ������ �������

> How to flush a buffer?

* Block buffering (=Full buffering)
<br>=> The buffer is flushed when it receives **a certain amount of data (e.g. 1KB, 16KB, 64KB, etc...)**
<br> : �Ϲ� ����
* Line buffering
<br>The buffer is flushed when it receives **a newline character(��\n��)**
<br>ex: printf,scanf �� , stdin, stdout

* Unbuffered
<br>The buffer doesn��t act as a buffer and is flushed every bytes
: stderr �� ���۸��� ���� �ʴ´�. 


## Pipes  ( �����̷��� ���� )

* Used in contexts where streams are **reconnected to alternate sources or destinations**

* The process of connecting and reconnecting streams is referred to as piping, or pipelining


> Three piplining symbols 

* O/S automatically creates three streams for every running program.

* **Most shells** provide the ability to **redirect those streams** at startup

| Symbol | Stream reconnetion |
|---------|-------------------|
|  <     | standard in comes from the given file | 
|  >     | standard out goes to the given file | 
|  \|     | standard out from the first program goes to standard in for the second program |




