## Client


1. socket()
: creates an endpoint for communication and returns a descriptor <br>
: Client도 역시 서버처럼 소켓을 만들어야 한다. <br>

2. connect()
: attempts to make a connection to another socket<br>
: 서버에게 연결을 요청하는 함수 <br>
: 연결을 요청하는 함수 connect()을 사용하려면 **서버의 이름(주소)를 connect()의 인자로 넣어야한다.**<br>

3. Call read() and/or write()
: similar to an ordinary file. <br>
: read()/ write()을 이용해 데이터를 주거니 받거니 하면 된다.<br>

