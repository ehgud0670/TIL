# include <stdio.h>
# include <stdlib.h>

struct Node{
  
  int data;
  struct Node *next;
};


struct Node *head= NULL;

void linsert(int data){
    
  struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
  //값 넣기
  temp -> data = data;
    
  //연결짓기
  if(head == NULL)
  	head = temp;
  else{
  temp -> next = head; //처음엔 NULL. head가 처음엔 null이었으니깐.
  head = temp;
  }
}
void lprint(){
  struct Node *current = head; 
  
  while(current){
  	system("clear");
    printf("-<%d> ", current->data);
    current = current -> next;
	}
	getchar();
}

int main(){
  
  int i;
  //정수 10개 전송

  for(i=0; i<10; i++){
    linsert(i+1);
    lprint();
	}
  	

  return 0;
}
