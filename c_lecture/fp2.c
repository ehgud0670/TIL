# include <stdio.h>

int sub(int n1,int n2){

  return n1-n2;

}

//함수인데 반환형이 반환타입이 int이고 매개변수가 int 형 2개인 함수의 포인터.
int (*p())(int n1,int n2){

 return sub;  //함수의 이름은 그 함수의 주소값이다.  
}


int main(){

  int num1 =5;
  int num2 =3;
  
  printf("result = %d\n", sub(num1,num2));
  
  printf("result = %d\n", p()(num1,num2));  //방법1: 함수로 접근해서 해결한 방법.
  printf("result = %d\n", (*p())(num1,num2));  //방법2: 함수의 이름(주소값)으로  접근해서 해결한 방법.

  return 0;
}
