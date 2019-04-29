# TLS ( Thread Local Storage)
## 스레드 

 TLS란 **스레드 별로 다른 값을 가지는 전역변수**를 말한다. <br>

 스택에 잡히는 지역 변수는 스레드마다 별도의 스택을 사용하므로 당연히 다른 값을 가지지만 
**(일반) 전역 변수의 경우에는 모든 스레드가 공유하므로 접근 시 race condtion이 생길 수 있다.** <br>

### => 따라서 스레드마다 개별적으로 사용할 수 있는(thread-local) 변수를 사용하여 안정성 및 성능을 높일 수 있다. 



### C언어, 리눅스에서의 TLS 예제.
```java
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>

# define FALSE 0
# define TRUE 1

__thread int flag = FALSE;
int global=0; 

void *random_game(void *arg){
	flag= rand()%2; 
  global++;	
  sleep(1);
  if(flag){
    printf("꽝이 아니네요 flag: %d\n", flag);
	}
	else{
		printf("땡! 당신은 꽝입니다! flag: %d\n", flag);
	}

	printf("global: %d \n\n", global);
}


int main(){
	int i;
	pthread_t thread[4];

	for(i=0; i<4; i++){
		pthread_create(thread+i, NULL, random_game, NULL); 
	}

	for(i=0; i<4; i++){
		pthread_join(thread[i], NULL);
	}


	return 0; 
}
```

### Java에서의 TLS 예제   : ThreadLocal 클래스 사용하기


ThreadLocalExample.java <br>
```java
import static java.lang.Thread.sleep;

public class ThreadLocalExample {

	public static void main(String[] args) {

		Thread[] thread = new RandomThread[3];
		for (int i = 0; i < 3; i++) {
			thread[i] = new RandomThread();
			thread[i].start();
		}
		for (int i = 0; i < 3; i++) {
			try {
				thread[i].join();
			} catch (InterruptedException e) {
				e.printStackTrace();
			}

		}
	}

}
```

RandomThread.java<br>
```
public class RandomThread extends Thread {
	private static ThreadLocal<Integer> integerThreadLocal =
		new ThreadLocal<>();

	@Override
		public void run() {
			int local = (int) (Math.random() * 1000);
			integerThreadLocal.set(local);
			try {
				sleep(1000);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
			System.out.println("Thread local: " + integerThreadLocal.get());

		}

}
```
