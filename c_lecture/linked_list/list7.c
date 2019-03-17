# include <stdio.h>
# include <stdlib.h>

// 또 다른 함수의 호출


typedef struct node{
  int data;
  struct node *prev;
  struct node *next;
} Node;


Node head = { 0 , &head , &head };  

/*
void insert_rear(Node *node, Node *temp, int data ){
 
  temp -> data = data;

  //link
  temp -> prev = node;
  temp -> next = node -> next;
  node -> next -> prev = temp; 
  node -> next = temp;

}

void insert_front(Node *node, Node *temp, int data ){ 
  
  temp -> data = data;

  //link
  temp -> prev = node -> prev;
  temp -> next = node;
  node -> prev -> next = temp; 
  node -> prev = temp;

}
*/

void insert_node(Node *prev, Node *next, Node *new){

  new -> prev = prev;
  new -> next = next;
  next -> prev = new;
  prev -> next = new;
}


void insert_rear(Node *node, Node *new ){
 
  insert_node(node, node ->next,new);
}

void insert_front(Node *node, Node *new){ 
  
  insert_node(node->prev,node , new);
}

void print_list(Node *head){

  Node *current = head->next;
  printf("<head>");
  while(current!=head){ //연결리스트의 끝이 NULL 이면 프로그램(컴퓨터)자체가 꺼져버릴 수 있기 때문에 끝을 tail(head)로 표현하는 것이 맞다.
                            // 끝을 tail로 두면 에러가 나더라도 프로그램(컴퓨터)자체는 꺼지지 않아서 모든 작업들이 날라가지 않기 때문이다.
                            //(컴퓨터가 꺼지면 데이터가 날라갈 수 있다.)
    printf("-<%d>", current -> data);
    current = current -> next;
	}
	printf("\n");

}

int main(){

 int i;
 Node node[10];
 for(i=0;i<5;i++){
 	  node[i].data = i+1;
  	insert_rear(&head, node+i); //node의 인자 값 전달 방식이 call by reference 이므로 
 	 // insert_front(&head2, node2+i, data); //insert_rear 와 insert_front의 node 전송을 서로 다른 변수로 하자.
  }

  print_list(&head);
  return 0;
}
