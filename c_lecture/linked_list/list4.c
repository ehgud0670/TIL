# include <stdio.h>
# include <stdlib.h>

typedef struct node{
  int data;
  struct node *next;
} Node;

Node head = { 0 , &head };  

/*
void insert_front(Node *head,Node *temp,int data){
  
  temp -> data = data;

  temp -> next = head->next; // head는 처음에 null 이다.   
  head -> next = temp;
}
*/

void insert_front(Node *node, Node *temp, int data ){
 
  temp -> data = data;
  temp -> next = node -> next;
  node -> next = temp;

}

void print_list(Node *phead){

  Node *current = phead->next;
  printf("<head>");
  while(current != phead){ //연결리스트의 끝이 NULL 이면 프로그램(컴퓨터)자체가 꺼져버릴 수 있기 때문에 끝을 tail로 표현하는 것이 맞다.
                            // 끝을 tail로 두면 에러가 나더라도 프로그램(컴퓨터)자체는 꺼지지 않아서 모든 작업들이 날라가지 않기 때문이다.
                            //(컴퓨터가 꺼지면 데이터가 날라갈 수 있다.)
    printf("-<%d>", current -> data);
    current = current -> next;
	}
	printf("\n");

}

int main(){

 int i;
 int data;
 Node node[10];
 for(i=0;i<5;i++){
 	 scanf("%d", &data);
 	 insert_front(&head, node+i, data);
  }

  print_list(&head);
  return 0;
}
