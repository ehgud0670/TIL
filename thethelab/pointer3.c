// decay
// 배열의 이름은 배열의 첫번째 element의 주소를 가리킨다. 
// 배열의 이름이란 특징때문에 decay가 발생한다.

# include <stdio.h>

void add(int *arr){ // 배열의 이름을 보냈으므로 
  int i;
  for( i =0 ; i<3; i++) // 보통 c버전은 c89버전이다. 하지만 for(int i = 0; i<3;i++)은 c99버전이므로 안쓰는 것이 좋다.
  {
  	arr[i]+=10;
	}
  printf("add() / %ld\n", sizeof(arr));// 8	

}


int main(void){

  int  arr[3] ={1,2,3};
  int i;

  // add(&arr[0]);
  add(arr);// 배열은 다른 변수 타입과 다르게 주소값을 보낼 때 배열의 이름을 인자로 보낸다. 
  // 왜냐하면 배열의 이름이 곧 주소값을 나타내기 때문이다. 
  // 평소에는 배열의 역할을 하다가 배열의 이름은 포인터의 역할을 하기 때문에 
  // 배열의 역할에서 조금 변형되었다고, 의미가 변했다고 하는 것을 'decay' 되었다고 한다. 
    
  
  for(i=0; i<3; i++)
  	printf("%d \n", arr[i]);
  
  printf("main() / %ld\n" ,sizeof(arr)); // 12

  return 0;
}
