// 더블 연결리스트 삭제 구현하기

# include <stdio.h>
# include <stdlib.h>

# define NUM 10 

typedef struct node{  
  int data;
  struct node * prev;
  struct node * next;

}Node;

Node head1 = {0, &head1,&head1};
Node head2 = {0, &head2,&head2};

void __del_node(Node *prev, Node *next, Node *delNode){

  prev-> next = next;
  next -> prev = prev;
  delNode -> prev = NULL;  //헤드를 삭제하면 큰일납니다. 
  delNode -> next = NULL;

}

void del_rear(Node *node){ 
//delNodeNext
 __del_node(node, node->next->next, node->next);
}

void del_front(Node *node){
//delNodePrev 
 __del_node(node->prev->prev , node , node->prev);
}

int del_order(Node *head){
  
  Node *current = head;
  int order;
  int i;

  printf("몇번째 노드를 제거하시겠습니까?\n:");
  scanf("%d",&order);
  if(order<=0){
  	printf("error! 0이하의 수는 입력하지 마십시오.\n");
  	return -1;
	}
  order -=1;  
  
  for( i=0; i<order; i++){
    current = current -> next;
	}
	if(current -> next == head){
	  printf("error! 헤드를 삭제하지마십시오.\n");
	  return -1;
	}
  del_rear(current);    

}
/*
void del_rear(Node *node){ 
	
 Node *delNode = node -> next;
 Node *delNodeNext= delNode -> next;

 node -> next = delNodeNext;
 delNodeNext -> prev = node;
 delNode -> prev = NULL;
 delNode -> next = NULL;
}

void del_front(Node *node){

 Node *delNode = node -> prev;
 Node *delNodePrev = delNode -> prev;
 
 delNodePrev -> next = node;
 node -> prev = delNodePrev;
 delNode -> prev = NULL;
 delNode -> next = NULL;
}
*/

void __add_node(Node *prev,Node *next, Node *new){
  
  new -> prev = prev;
  new -> next = next;
  prev -> next = new;
  next -> prev = new;

}

void add_rear(Node *node, Node *new){
//node ->next
  
  __add_node(node, node->next, new);
}

void add_front(Node *node, Node *new){
//node ->prev 
  
  __add_node(node->prev, node, new);
}

void add_order(Node *head){
//node ->prev
  int data;
  int order;
  int arrow;
  int i;

  //동적할당하여 노드 만들기
  Node *new =(Node*)malloc(sizeof(Node));
  Node *current = head;

  printf("추가 할 노드의 data값을 적으세요: ");
  scanf("%d", &data);
  new -> data = data;
  
  printf("앞에 추가할 건지 또는 뒤에 추가할 건지 입력하세요.(1-앞, 2-뒤)");
  scanf("%d", &arrow);
  
  if(arrow == 1)
    printf("몇번째 노드 앞에 추가하시겠습니까?\n:");
  else	
    printf("몇번째 노드 뒤에 추가하시겠습니까?\n:");
  scanf("%d",&order);

  
  for(i=0; i<order; i++)
  	current = current -> next;
  
  if(arrow ==1)
    add_front(current, new);
  else
  	add_rear(current, new);
}

/*
void insert_rear(Node *node, Node *new){

  new -> prev = node;
  new -> next = node -> next;
  node -> next -> prev = new; 
  node ->next = new;
}

void insert_front(Node *node, Node *new){

  new -> prev = node -> prev;  
  new -> next = node; 
  node -> prev -> next = new; 
  node -> prev = new;
}

*/


void print_list(Node *head, int number){
  Node *current = head -> next;
 
  printf("<head%d>", number);
  while(current != head){
    printf("-<%d>", current->data);
    current = current -> next;
	}
  printf("\n\n");
}



int main(){
  Node node_1 ={1,NULL}; 
  Node node_2 ={1,NULL}; 
//  Node *HEAD1 = &head1; 
//  Node *HEAD2 = &head2; 
  Node node1[NUM];
  Node node2[NUM];
  int i;
  int data; 

  printf("노드 10개 삽입: \n");
  for( i = 0; i< NUM ; i++){ 
  	node1[i].data = i+1;
    node2[i].data = i+1; 
    add_rear(&head1, node1+i);
    add_front(&head2, node2+i);
	}

  print_list(&head1,1);
  print_list(&head2,2);

  add_order(&head1);
  add_order(&head2);
  print_list(&head1,1);
  print_list(&head2,2);

  printf("head쪽 노드 2개 삭제: \n");	
	for(i=0;i<2; i++){
    del_rear(&head1);
    del_front(&head2);
	}

  print_list(&head1,1);
  print_list(&head2,2);

  if(del_order(&head1) == -1)
  	return -1;
  if(del_order(&head2) == -1)
  	return -1;
  
  print_list(&head1,1);
  print_list(&head2,2);
  return 0;
}
