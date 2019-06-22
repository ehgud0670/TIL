# include <stdio.h>

# define true 1
# define false 0
/*
배열은 메모리의 특징이 정적이어서(길이의 변경이 불가능해서) 메모리의 길이를 변경하는 것이
불가능하다.

배열의 element를 넘으면 아래와 같은 에러가 발생한다.(메모리에 유연하지 못하다.)

*** stack smashing detected ***: <unknown> terminated
Aborted (core dumped)

*/
int main(){
  
  int arr[10];
  int readCount = 0;
  int readData;
  int i;

  while(1){
  	/*
    if(readCount >=9)
    	break;
		*/
    printf("자연수 입력: ");
    scanf("%d", &readData);

    if(readData<1)
    	break;

    arr[readCount++] = readData;
  }
  
  for(i=0; i<readCount; i++)
  	printf("%d ",arr[i]);
  printf("\n");
  return 0;
}
