# chapter 9
## C언어의 핵심, 함수
09-1 함수의 정의 및 선언
Divide and Conquer:
=> main 하나의 함수로만 코드를 짜지말고 여러 개의 함수를 만들어 코드를 짜는 것이 효율적이다.

함수 유형:
1. 전달인자(o), 반환값(o)
```c
  int Add(int num1, int num2){ // int : 반환형 Add : 함수의 이름 (int num1, int num2): 매개변수
  	int result = num1 + num2 ; 

  	return result; // 값의 반환 
	}
  // 함수 호출시 전달할 수 있는 인자의 수는 여러 개지만, 반환할 수 있는 수는 딱 한가지라는 것을 명심하자.
```	

2. 전달인자(o), 반환값(x)
```c
 void showNum(int num){    // void 의 뜻 : 빈.
		  printf("num : %d",num );
 	  }
```
3. 전달인자(x), 반환값(o)
```c
 int scanfNum(void){
   int num;
   scanf("%d", &num);
   
   return num;
 }
``` 
4. 전달인자(x), 반환값(x)
```c
void getPrint(void){
  printf("Hello,\n");
  printf("Hello my friends\n");

}
```

* return;
: return 에 아무것없이 ;만 있을 경우 값의 반환는 없고, 함수만 빠져나감을 알 수 있다. 

함수의 선언: 컴파일러에게 이런 함수가 있다고 알려주는 것
: 컴파일러는 컴파일 도중 코드에서 함수의 호출이 나올 경우,자신이 지금껏 컴파일했던 내용중에 그 함수가 있는 지 찾는다.
그리고 만약에 없으면 경고를 준다.(warnning: implicit declaration of function ‘Increment’)
따라서 main함수 뒤에 특정 함수가 나오면, main에서 그 특정함수는 컴파일이 안되어 있으므로 경고를 받을 수 있다.
하지만 함수를 선언하면 컴파일러에게 이런 함수가 뒤에 나옴을 알려주므로 이 문제를 해결할 수 있다.
```c
#include <stdio.h>

int Increment(int n); // 함수의 선언. 매개변수의 이름은 생략 가능하다. 

int main(void){
  int num=2;
  num = Increment(num);
  return 0;
}

int Increment(int n){
  n++;
  return n;
}
```
09-2 지역변수(Local Variable)
: (1)지역변수는 함수의 중괄호 안에 있는 변수를 일컫는데 <br>
  지역변수가 유효한 범위는 자기가 포함된 중괄호(자신의 함수)까지만이다.<br>
  (2)그리고 지역변수는 자신의 영역을 벗어나면 자동으로 소멸된다.(호출될때마다 새롭게 할당된다는 뜻)<br>
  (3)지역 변수는 메모리 영역 'code','data','heap','stack' 중에 stack이라는 메모리 영역에 할당된다 <br>
  (4)지역 변수는 접시에 쌓듯이 할당된다.(stack: First-In-Last-Out)

  예시 <br>
```c
# include <stdio.h>

void printTen(void)
{
	int b=10;
	printf("b: %d \n", b);
}

int main(void){
  int a =1;
  printf("a: %d \n", a);

  return 0;
}
```
첫번째: main 함수의 호출<br>
=> main 함수가 선언되면 변수 a가 선언되고, 따라서 메모리 stack 영역에서 a라는 변수가 할당되고 1로 초기화된다. <br> 
두번째: printTen함수의 호출과 종료(반환)<br>
=> 메모리 stack영역에서 b라는 변수가 할당되어 쌓이고(FILO), 10으로 초기화된다.<br>
   이후 printTen 함수가 종료되고 main 함수로 돌아가게 되면 , printTen의 지역변수 b도 stack영역에서 사라지게 된다.(FIL0)
마지막 : main 함수의 종료 (반환)
=> main 함수의 마지막 문장 return 0;을 실행하고 main함수는 종료되고, 동시에 main 함수의 지역변수 a도 stack 영역에서 사라지게된다.
  
다양한 형태의 지역변수 : 반복문이나 조건문<br>
```c
for( int cnt=0; cnt<3; cnt++)
{
  int num=0;
  num++;
  printf("num : %d\n", num);
}
```
=> for문은 중괄호의 진입과 탈출을 반복하면서 이뤄지고 있는데,<br>
  따라서 for문의 변수 num은 메모리상에 할당되고 소멸됨을 반복함을 알 수 있다.<br>
```c

int num=1;

if (num==1)
{
  int num = 7;
  num+=10;
  printf("if문 내 지역변수 num: %d \n", num);
}
printf("if 문 밖 지역변수 num: %d \n", num);
```
=> 같은 이름의 변수더라도 if 문안의 printf문은 if 문의 지역변수 num을 택하고,
if 문 밖의 printf문은 main함수의 지역변수 num을 택한다. (유효부분을 잘 생각하자.)<br>

09-3 전역변수(Global Variable), static 변수, register 변수


09-4 재귀함수에 대한 이해(Recursive)

