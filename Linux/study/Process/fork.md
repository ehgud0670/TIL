# fork() 함수

- 기능

: fork() 는 **자식 프로세스**를 만드는 함수이다. 

- 사용법
```
    # include <unistd.h>
    
    pid_t fork(void);
```
- 설명
1. fork()는 부모 프로세스와는 **단지 PID와 PPID만이 다른 자식 프로세스를 만든다.** 그리고 자원 사용량을 0으로 맞춘다. 파일락(lock)과 시그널 팬딩(pending)은 상속받지 않는다.  
2. 리눅스에서 fork()는 **Copy-On-Write 페이지들을 사용하여 수행되며**, fork의 유일한 단점은 부모 프로세스의 페이지 테이블을 복사하고 자식 프로세스에 대한 task 구조체를 만들기 위해 필요한 시간과 메모리이다.  **즉, 부모를 복사해서 자식 프로세스가 생기는 것이므로 프로세스끼리 서로 독립적이다.** 
3.  getpid(), getppid()는 각각 자신의 프로세스 id, 부모의 프로세스 id를 반환한다. 

 

용어 설명 

- PID :  PID(Process Identification Number): 프로세스 각각을 구별할 수 있는 id 값.
- PPID : PPID(Parent Process Identification Number)는 프로세스를 만든 **부모 프로세스의 PID를 나타내는 값**이다. 프로세스의 PID가 PPID로 할당된다. (쉘 프롬프트에서 명령어를 입력하여 프로그램을 실행했다면 쉘이 부모 프로세스가 되어 쉘의 PID가 프로세스의 PPID로 할당된다.)
- 시그널 팬딩(pending) : 대기중인 시그널들을 말한다.
```
    # include <stdio.h>
    # include <stdlib.h>
    # include <unistd.h>
    
    int main(){
    
      int i;
      pid_t fork_ret;
    
      fork_ret = fork();
      //fork()는 부모 프로세스라면 자식의 pid값 (>0)을 반환하고, 
      // 자식 프로세스라면 0을 반환한다. 
      // 따라서 위의 코드 fork_ret >0 이면 부모 프로세스를 나타내고, 
      // fork_ret = 0 이면 자식 프로세스를 나타낸다.
      // 또 fork()가 실패하면 -1을 반환하므로 pid가 -1이면 비정상 종료하게 해야 한다.  
      if(fork_ret > 0 ){ //부모 프로세스 
        printf("parent process. \n");
        exit(0); // return 0 
      }else if(fork_ret == 0){ //자식 프로세스 
        printf("child process. \n");
        exit(0);
      }else{
        perror("fork");
        exit(1);// return 1   :0을 제외한 main의 리턴값은 비정상 종료를 나타낸다. => 커널에 보내짐.
      }
    }
```
- perror() : 오류 메세지를 stderr로 출력하는 함수. string이 NULL이 아니고 널 문자를 가리키지 않는 경우, string에서 지정된 스트링은 표준 오류 스트림(stderr)으로 출력되고 **콜론과 간격이 이어진다. errno의 값과 연관된 메세지가 출력된 다음 줄 바꾸기 문자가 이어진다.**

**fork()를 하면 독립적인 자식 프로세스가 하나 더 생김을 알 수 있다.  또, fork() 직후 부모와 자식은 pid와 ppid만이 다르고 이외의 것은 같다.**
