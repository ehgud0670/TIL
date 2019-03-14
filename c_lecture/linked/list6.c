# include <stdio.h>
# include <stdlib.h>

// 또 다른 함수의 호출


typedef struct node{
  int data;
  struct node *prev;
  struct node *next;
} Node;

void insert_node(Node *node, Node *new, Node *temp, int data );

Node head1 = { 0 , &head1 , &head1 };  
Node head2 = { 0 , &head2 , &head2 };  

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

void insert_node(Node *node, Node *new, Node *temp, int data ){ //이것 자체가 성립이 안되는 구나.
  
   temp -> data = data;
  //link
   temp -> prev = node; // 여기 자체에서 포인터로 멤버를 참조하기 때문에 call by reference가 유지된다.  
   temp -> next = new; // new = node -> next
   new -> prev = temp; 
   new =  temp;

   printf("head's data: %d \n", node -> data);
   printf("temp's data: %d \n", temp -> data);
   printf("head's next data: %d \n", new -> data);
   printf("\n");
}


void insert_rear(Node *node, Node *temp, int data ){
 
  insert_node(node, node -> next, temp, data );
}

void insert_front(Node *node, Node *temp, int data ){ 
  
  insert_node(node, node -> prev, temp, data);
}

void print_list(Node *phead){

  Node *current = phead->next;
  printf("<head>");
  int count =0;
  while(1){ //연결리스트의 끝이 NULL 이면 프로그램(컴퓨터)자체가 꺼져버릴 수 있기 때문에 끝을 tail로 표현하는 것이 맞다.
                            // 끝을 tail로 두면 에러가 나더라도 프로그램(컴퓨터)자체는 꺼지지 않아서 모든 작업들이 날라가지 않기 때문이다.
                            //(컴퓨터가 꺼지면 데이터가 날라갈 수 있다.)
    if(count>=3)
      break;
    printf("-<%d>", current -> data);
    current = current -> next;
    count++;
	}
	printf("\n");

}

int main(){

 int i;
 int data;
 Node node1[10];
 Node node2[10];
 for(i=0;i<3;i++){
 	 scanf("%d", &data);
  	insert_rear(&head1, node1+i, data); //node의 인자 값 전달 방식이 call by reference 이므로 
 	 // insert_front(&head2, node2+i, data); //insert_rear 와 insert_front의 node 전송을 서로 다른 변수로 하자.
  }

  print_list(&head1);
 // print_list(&head2);
  return 0;
}
