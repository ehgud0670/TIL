
## Server

1. socket()
: creates an endpoint for communication and returns a descriptor<br>
: 소켓 생성하는 함수로, 서버든 클라이언트든 둘다 소켓을 생성해야 한다.

2. bind()
: to bind a path or internet address to a socket<br>
: assigning a name to a socket<br>
: when a socket is created, it exists in a name space (address family) but has no name assigned.<br>
: 자신의 이름(도메인 주소: ip,port이거나 unix 도메인이면 path)을 소켓에 묶는 함수. 즉 소켓에 자신의 이름을 할당하는 함수. <br>

path의 글자 수 가 14이거나 더 적은 경우의 unix 도메인 소켓을 사용할 때 bind()의 모습<br>
```c
# include <sys/socket.h>

bind(sd, (struct sockaddr * )&addr, length);
```

path의 길이가 14를 초과하는 경우의 unix 도메인 소켓을 사용할 때 bind()의 모습<br>
```c
# include <sys/un.h>

bind(sd,(struct sockaddr_un*)&addr, length);
```

internet 도메인 소켓을 사용할 때 bind()의 모습<br>
```
# include <netinet/in.h>

bind(sd,(struct sockaddr_in*)&addr ,length);
```

3. listen()
: specifying a queue limit for incoming connections and then the connections are accepted later with accept().<br>
: Repeat until a connection is coming.<br>
: 서버는 데이터를 받을 준비를 먼저 하는데 그것이 바로 listen()함수가 한다. listen()함수는 client의 요청을 받는다. 그리고 client의 요청들을 메세지 큐에 정렬한다.<br>

4. accept()
: fork() a child process that performs reads and/or writes as per ordinary file.
: client의 요청이 들어온 후에 수락하는 함수가 accept()이다.<br>
: 서버는 하나고 클라이언트가 여러개인 경우가 많은데, 서버는 accept()을 하면서 fork()을 실행하여 자식 프로세스가 accept()이후의 일들을 수행하게 하고(client와 주고받는 것), 자기 자신은 여전히 listen()으로 남아 다른 client를 기다린다. 또 오면 또 fork()를 한다.  

