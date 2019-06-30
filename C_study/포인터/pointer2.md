## 포인터란?

* 포인터 

=> 포인터는 주소를 담을 수 있는 타입.
<br>int -> int\*
<br>char -> char\*
<br>double -> double\*

* 주의 ! 포인터를 쓸때 \*를 c언어는 변수의 이름 왼편에 두고 c++은 타입의 오른편에 둔다. 명심 또 명심!

```c
# include <stdio.h>

int main(){

  int a = 5; 
  int *ptr1 = &a;

  char b = 'b';
  char *ptr2 = &b;

  double c = 4.7;
  double *ptr3 = &c;

  return 0;

  printf("a = %d \n", *ptr1);
  printf("b = %c \n", *ptr2);
  printf("c = %f \n", *ptr3);
}


```
