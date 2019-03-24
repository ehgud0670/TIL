# include <stdio.h>
# include <stdlib.h>

typedef int (*PERR)[3];

PERR foo() {
   
   static int  arr[2][3]={0,}; 
   printf( "%ld \n", sizeof(arr));
   return arr; // 배열의 이름이므로 리터값 int (*) [3]
}
int main(){

	printf("%ld \n",sizeof(PERR));
  foo();
/*
  int *arr1 =(int*)malloc(sizeof(PERR)) ;
  int i,j;
  
  arr1 = *(foo());

  for(i=0;i<2; i++){
  	for(j=0;j<3;j++){
      printf("%d ",arr1[i]);
		}
		printf("\n");
  }
  */
  return 0;

} 
