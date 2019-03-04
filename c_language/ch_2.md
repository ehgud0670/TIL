# chapter2 
## 프로그램의 기본 구성

2-1 함수(Function)
 (1) 기본
 => 3x + 4 = y 에서 x에 1을 대입하면 y=7이 되고, x에 2을 대입하면 y=10이 된다.
   이때 x를 입력, yfmf 출력이라 할때 적절한 입력과 그에 따른 출력이 존재하는 것을 함수(Function)이라 한다. 
 
 (2) main 함수
 => C언어에서 제일 먼저 호출되는 함수는 main 함수이다. 프로그램이 실행되자마자 컴퓨터는 main이라는 이름의 함수를 호출하므로 C로 작성한 모든 프로그램엔 main이라는 함수가 반드시 있어야 한다.
 (3) 함수 구조
 ```c
 int  main (void) 
 ```
:함수의 반환 형태(return type) , 함수이름, 함수의 입력 형태
 ```c
 int main(void)
 {
 	 printf("Hello\n");
   
 }
```

2-2 주석(Comments)

