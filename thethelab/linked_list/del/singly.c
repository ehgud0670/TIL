# include <stdio.h>
# include <stdlib.h>  // sysyem()

# define NUM 5

typedef struct node{
  int data;
  struct node *next;

}Node;

Node head={0,&head};

void delete_rear(Node *node){

  Node *delNode = node -> next;
  Node *delNodeNext = delNode -> next;
 
  node -> next = delNodeNext;
  delNode -> next = NULL;
}

void delete_rear2(Node *node, int order){
  order -=1; // 앞에꺼 선택
  int i;
  for(i=0; i<order; i++){
  	node = node ->next;
  }
  Node *delNode = node -> next;
  Node *delNodeNext = delNode -> next;
 
  node -> next = delNodeNext;
  delNode -> next = NULL;
}

void insert_rear(Node *node, Node *temp){ 
  
  temp -> next = node->next;
  node -> next = temp;

}

void print_list(Node *head){
  Node *current = head->next;
  
  printf("<head>");
  while(current != head){
//    system("clear");
    printf("-<%d>", current->data);
    current = current -> next;
  }
  printf("\n\n");
}

int main(){
  Node *HEAD = &head;
  Node node[NUM];
  int i;
  int order;

  for(i=0; i<NUM; i++){
    node[i].data = i+1;
    insert_rear(&head, node+i);
	}

	printf("노드 10개 삽입: ");
  print_list(&head);
  
  delete_rear(&head);
	printf("head쪽 노드 1개 제거: ");
  print_list(&head);
 
  Node *cur = (HEAD)->next;
  delete_rear(cur);
	printf("연결리스트의 2번째 노드 제거: ");
  print_list(&head);
  do{
  printf("몇번째 노드를 제거하시겠습니까? 숫자를 입력하세요. (0입력시 나가기)\n");
  scanf("%d", &order);

  if(HEAD -> next == HEAD){
    printf("error ! 더이상 삭제할 노드가 없습니다. \n");
    break;
	}
  delete_rear2(HEAD, order);
	printf("연결리스트의 %d번째 노드 제거: ", order);
  print_list(&head);
  }while(order != 0);

  return 0;
}
