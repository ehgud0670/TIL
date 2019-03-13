# include <stdio.h>
# include <stdlib.h>

struct Node{
  
  int data;
  struct Node *next;
};

struct Node *head= NULL;

void linsert(struct Node *temp, int data){
    
  temp = (struct Node*)malloc(sizeof(struct Node));
  //값 넣기
  temp -> data = data;
  //linked 하기
  temp -> next = head; //처음엔 NULL. head가 처음엔 null이었으니깐.
  head = temp;
  
}




int main(){
  
  struct Node node[10];
  int i;
  //정수 10개 전송

  for(i=0; i<10; i++){
    linsert(&node[i],i+1);    
	}
	
  for(i=0; i<10; i++){
     printf("%d \n",node[i].data);  // 내가 보기엔 call by reference로 될 것 같은데 왜 안되는 지 물어보기
	}
  	

  return 0;
}
