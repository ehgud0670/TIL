#include <stdio.h>

void print_hanoi(int n , char from , char tmp , char to){
  
  if( n == 1){
    printf("%c 에서 %c 로 %d번째 원판을 옮긴다.\n" , from , to , n);
	} else {
   
    print_hanoi( n-1 , from , to , tmp );
    printf("%c 에서 %c 로 %d번째 원판을 옮긴다.\n", from, to , n);
    print_hanoi( n-1 , tmp , from , to );

	}
	

}

int main(){

  int num = 20;
  print_hanoi(num, 'A' , 'B' , 'C' ); 

}
