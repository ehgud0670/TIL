# chapter 7
## 반복실행을 명령하는 반복문

* 반복의 대상이 하나의 문장이라면 중괄호는 생략 가능하다.

07-1 while문
```c
# include <stdio.h>

int main(void){
	int num=0;

	while(num<5){  // () 안이 반복 조건. 참이어야만 반복문 실행.
		printf("hello world! %d\n", num); // {} 안의 코드가 반복할 내용.
		num++;
	}

	return 0;
}
```

07-2 do-while문



07-3 for문
