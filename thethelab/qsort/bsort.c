# include <stdio.h>
# include <stdlib.h>


void swap( char* a , char* b, size_t size){   //char를 쓴 이유 : sizeof(char)가  1바이트로 가장 작은 자료형 단위이기 때문에 char을 사용한다.
  int i;
  char* temp= malloc(size);  //포인터로서 변수에 다가가야 하기 때문에 임시 변수인 temp도 자료형 char*로 하여 동적할당 시켜야 한다.
                             // 직접 변수로서 temp를 선언하지 말것을 명심하자. char temp(X!)
  for(i=0; i<size;i++){
    temp[i] = a[i];  //포인터로 변수를 직접 참조해 변수를 바꿔야 한다. [명심!]
    a[i] = b[i];
    b[i] = temp[i];
	}
   
  free(temp);

}

void bsort(const void *arr, int n, size_t size, int compare(const void*, const void* )){
  int i,j;
  for(i=0; i<n-1; i++){
  	for(j=i+1; j<n; j++){
       if( compare( (char*)arr +i*size , (char*)arr +j*size ) >0)
           swap((char*)arr + i*size, (char*)arr +j*size, size);
		}
  }
}

//오름차순
int int_compare( const void *a, const void *b){
  return *(int*)a - *(int*)b;
  
}

int main(){
  int i;
  long arr[10] = {5,7,9,0,1,4,2,6,3,8};
  bsort(arr, 10, sizeof(long), int_compare);
 
  for(i=0; i<10; i++)
    printf("%ld ", arr[i]);
  printf("\n");
  return 0;
}
