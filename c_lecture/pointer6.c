# include <stdio.h>

int main(void){

  int arr[3] = {1,2,3};
  int i;
  for(i=0; i<3; i++)
    printf("arr[i]: %d \n", arr[i]);
  printf("\n");

  for(i=0; i<3; i++)
  	printf("*(arr+i): %d \n", *(arr+i));

  return 0;
}
