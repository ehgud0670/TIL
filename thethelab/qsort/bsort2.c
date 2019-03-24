# include <stdio.h>
# include <stdlib.h>

void swap( char* a , char* b, size_t size){   //char를 쓴 이유 : sizeof(char)가  1바이트로 가장 작은 자료형 단위이기 때문에 char을 사용한다.
  int i;
  char* temp = malloc(size);
  for(i=0; i<size;i++){
    temp[i] = a[i];
    a[i] = b[i];
    b[i] = temp[i];
	}
     

}

void bsort(void *arr, int n, size_t size, int compare(const void*, const void* )){
  int i,j;
  for(i=0; i<n-1; i++){
  	for(j=i+1; j<n; j++){
       if( compare( arr +i*size , arr +j*size ) >0)
           swap(arr + i*size, arr +j*size, size);
		}      // void* 형은 본래 offset에 대한 기준에 없어서(무) 포인터 연산이 불가 하다. 다라서 (char*)로 형변환 해야 하지만 gcc 가 void*를 포인터 +,- 연산에 대해서 char*로서 연산이 가능하게 해주므로
		       // 굳이 형변환 안해줘도 된다.
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
