# include <stdio.h>
# include <stdlib.h>

struct Node{
  
  int data;
  struct Node *next;
};


void linsert(struct Node *head, int data){
    
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
void lprint(struct Node *head){
  struct Node *current = head;
  while(current){
    printf("%d", current -> data);
    current = current -> next;
	}
  getchar();
}
struct Node *head= NULL;

int main(){
  
  int i;
  //정수 10개 전송

  for(i=0; i<10; i++){
    linsert(head,i+1);
    lprint(head);
	}
  	

  return 0;
}
