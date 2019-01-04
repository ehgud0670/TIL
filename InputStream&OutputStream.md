# InputStream
> 바이트 기반 입력 스트림의 최상위 클래스로 추상 클래스이다. 최상위 클래스이므로 
> FiledInputStream, BufferdInputStream, DataInputStream, 모두 InputStream 클래스를 상속하고 있다.
 
- 메소드 표

 |리턴 타입   | 메소드 | 설명 |
  |-----------| -------|----- |
  |int        |read()	 | 입력 스트림으로부터 1바이트를 읽고 읽은 바이트를 리턴한다.  |
  |int 			    |read(byte[] b)|	입력 스트림으로부터 읽은 바이트드을 매개값으로 주어진 byte[] b에 저장하고 실제로 읽은 바이트 수를 리턴한다. |
  |int 			    |read(byte[] b, int off, int len)|	입력 스트림으로부터 len개의 바이트만큼 읽고 매개값으로 주어진 바이트 배열 b[off]부터 len개까지 저장한다. 그리고 실제로 읽은 바이트 수인 1en개를 리턴한다. 만약 len개를 모두 읽지 못하면 실제로 읽은 바이트 수를 리턴한다. | 
  |void			    |close()|		사용한 시스템 자원을 반납하고 입력 스트림을 닫는다. |
  


# OutputStream
> 바이트 기반 출력 스트림의 최상위 클래스로 추상 클래스이다. 최상위 클래스이므로 
> FiledOutputStream, BufferdOutputStream, DataOutputStream, 모두 OutputStream 클래스를 상속하고 있다.
 
- 메소드 표

|리턴 타입   | 메소드 | 설명 |
  |-----------| -------|----- |
  |void        | write(int b)	 | 출력 스트림으로 1바이트를 보낸다.(b의 끝 1바이트)  |
  |void 			    |  write(byte[] b)| 출력 스트림으로 주어진 byte[] b의 모든 바이트를 보낸다. |
  |void			    | write(byte[] b, int off, int len)| 출력 스트림으로 주어진 byte[] b[off]부터 len개까지의 바이트를 보낸다. | 
  |void			    |flush()| 버퍼에 잔류하는 모든 바이트를 출력한다. |
  |void      |close()  | 사용한 시스템 자원을 반납하고 출력 스트림을 닫는다. |
 
  
