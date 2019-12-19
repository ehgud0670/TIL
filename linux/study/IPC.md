# IPC(Inter-Process Communication)

* IPC(프로세스 간 통신)이란 프로세스들 사이에 서로 데이터를 주고받는 행위 또는 그에 대한 방법이나 경로를 뜻한다. 

같은 컴퓨터의 프로세스 간 통신, 다른 컴퓨터의 프로세스의 통신 모두 IPC 라고 한다. => **모든 프로세스 간 통신을 IPC라고 한다.**<br>

프로세스는 자신만의 주소를 갖는다. 즉 할당된 메모리에 대하여 완벽히 독립적이고, 따라서 다른 프로세스와 메모리를 공유하지 않는다.<br>

따라서 독립되어 있는 만큼 프로세스끼리 데이터를 공유하기 힘들고 서로 통신하기 힘들다. 그래서 리눅스는 커널이 IPC를 프로세스들은 IPC를 통해 **프로세스 간 통신**을 할수 있게 된다. <br>

 IPC의 방식들은 Message Queues, Shared Memory, Socket, Signal 등등이 있다. <br>

> Message Queues 
: Message Passing의 방식 중의 하나.
: 두 개( 그 이상)의 프로세스는 공통의 시스템 message queue에 대한 접근 을 통해 정보를 교환할 수 있다.<br>
: sending process는 큐에 메세지를 놓을 수 있고, 다른 프로세스는 큐를 통해 메세지를 읽을 수 있다.<br>
: 프로세스는 큐에 접근 권한을 얻기 위해서는 공통의 key를 공유해야 한다. 

> Shared Memory

> Socket 

> Signal 

리눅스의 signal은 커널이 process에게 어떤 event가 발생했음을 알리는 **비동기적인 신호**이다.<br> 
그리고 메세지패싱과는 달리 signal은 특정 데이터를 보낼 수 없고 어떤 상황이 발생했음을 알려주는 신호만을 보낼 수 있다. <br>

