# Socket
## 소켓

소켓은 IPC의 메세지 패싱 방식 중의 하나이다.
:소켓은 Point-to-point로 정의되는데, point-to-point는 **두 개의 프로세스간에 양방향 통신**을 의미한다.<br>
: Server and Client Model(서버는 기다리고 클라이언트가 뭔가를 보내고 서버는 그것을 받아서 응답을 하는 방식.)<br>
: Can be used for inter-process(한 컴퓨터의 내부 프로세스간에도 가능) and inter-system(완전 독립된 두개의 컴퓨터간에도 가능) communication.<br>

* Socket은 메세지 큐나 파이프와 달리 **다른 컴퓨터의 프로세스와도 통신이 가능하고,** 그래서 많이 쓰인다.

소켓을 사용하려면 상대방의 IP 주소와 Port 주소를 알아야 한다.<br>

       A ----->  B
     Client     Server (Serving 서빙하는 사람)
                Computer 주소 - IP 주소
                Process 주소 - Port 주소

