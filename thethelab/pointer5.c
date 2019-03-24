# include <stdio.h>

void plusArr(int (*arr)[2], int len){

 int i,j;
 
 for( i =0 ; i<len; i++)
   for (j=0; j<2; j++)
      arr[i][j]+=10; // 명심하자.
}


int main(){

  int arr[3][2] = {0,};
  int i,j;
  int n = sizeof(arr)/sizeof(arr[0]);
  plusArr(arr,n);

  for(i =0; i<n; i++)
  	for(j=0; j<2; j++)
  	   printf("%d \n",arr[i][j]);


  return 0;
}
