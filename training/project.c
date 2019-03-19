# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "struct.h"
# include "func.h"

# define ROW 400
# define COL 15
# define MAX 10000
# define WORD_SIZE 100



/*
typedef struct car{
  
  char name[32];
  char kind[2][32];
  int retail_price;
  int dealer_cost;
  double engine_size;
  int weight;
  int width;

}Car;

typedef struct kind{
 
 int idx;
 char name[32];

}Kind;

*/

Node head1={&head1,&head1};  //CellDx
Node head2={&head2,&head2};  //Sports Car
Node head4={&head4,&head4};  //Wagon
Node head5={&head5,&head5};  //Minivan
Node head6={&head6,&head6};  //Pickup
Node head7={&head7,&head7};  //AWD
Node head8={&head8,&head8};  //RWD


int main(){

  Car car[ROW];
  Kind kind[10];
  int kcount;
  int car_count;
 
  int name;
  int RP;//Retail Price
  int DC;//Dealer Cost
  int ES;//EngineSize
  int weight;
  int width;
  
  
  int option;

  kcount = set_Head( &name,kind,&RP,&DC,&ES,&weight,&width);   
/*
  count = 0 ;
  while(fgets(string,MAX, stdin) != NULL){
    str[count] =(char*)malloc(sizeof(char)*MAX);
    strcpy(str[count],string);
    count++;
	}
	*/
 // Car *car;
  car_count=set_Car(car,name,kind,kcount,RP,DC,ES,weight,width);
  
  printf("총 %d개의 데이터가 로드되었습니다.\n", car_count);  
  //  fflush(stdout);
  // while(getchar()!=EOF);
//  fclose(stdin);
  //fopen(stdin,"r");

    // 첫번째
    printf("1. 검색\n"); 
    printf("2. 종료\n"); 
    printf("선택> "); 
    option=fgetc(stdin);
    putchar(option);
    /*
    scanf("%s",option);
    if(atoi(option) == 2)
  	  printf("break\n");
  	  */
/*
    // 두번째
    printf("선택> "); 
    fgets(option,5,stdin);

    // 세번째
    printf("선택> "); 
    scanf("%s",option);
   
    // 네번째 
    printf("파일로 저장하시겠습니까?\n");
    printf("1. 예 \n");
    printf("2. 아니오 \n");
    printf("선택> "); 
    scanf("%s",option);
*/  


  return 0;
}
