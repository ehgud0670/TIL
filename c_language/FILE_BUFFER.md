## FILE 구조체 와 버퍼링 정책.

### FILE
```c
// FILE
// => 열린 파일의 정보를 가지고 있다. (스트림이다.)
//   : File Descriptor
// => 버퍼링을 한다.
//   : printf -> fprintf(stdout)
