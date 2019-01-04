# InputStream
> 바이트 기반 입력 스트림의 최상위 클래스로 추상 클래스이다. 최상위 클래스이므로 
> FiledInputStream, BufferdInputStream, DataInputStream, 모두 InputStream 클래스를 상속하고 있다.
 
- 메소드 표

  |리턴 타입 | 메소드 | 설명 |
  |-------- | -------|----- |
  read()
  read(byte[] b)
  read(byte[] b, int off, int len)
  close()
  
| 왼쪽 정렬 | 가운데 정렬 | 오른쪽 정렬 |
|:--------|:--------:|--------:|
| 내용 11 | 내용 12 | 내용 13 |
| 내용 21 | 내용 22 | 내용 23 |

# OutputStream
> 바이트 기반 출력 스트림의 최상위 클래스로 추상 클래스이다. 최상위 클래스이므로 
> FiledOutputStream, BufferdOutputStream, DataOutputStream, 모두 OutputStream 클래스를 상속하고 있다.
 
- 메소드
  write(int b)
  write(byte[] b)
  write(byte[] b, int off, int len)
  flush()
  close()
  
