# include <stdio.h>  // 스탠다드 입출력 (파일 입출력 등등...)
# include <stdlib.h> // malloc(), free()

# define true 1
// 연결리스트의 특징: 메모리 할당에 대해서 유연하다. 정적(static)이지 않고 동적(dynamic)이다.
typedef struct _node {
  int data;
  struct _node *next;
}Node;

int main(){

  Node *head = NULL; // 연결리스트의 첫번째 노드를 가리키는 포인터이면서 노드 선언.
  Node *tail = NULL; // 연결리스트의 마지막 노드를 가리키는 포인터이면서 노드 선언.
  Node *cur= NULL;   // 연결리스트의 현재 노드를 가리키는 포인터이면서 노드 선언.

  Node *newNode = NULL; // 연결리스트의 새로운 노드를 가리키는 포인터를 선언.
  int readData;
 
 // 데이터를 입력 받는 과정 
 while(true){
  printf("자연수 입력: ");
  scanf("%d", &readData);
  if(readData<1)
  	break;
  
  //노드의 추가 과정.
  newNode =(Node*)malloc(sizeof(Node));
  newNode -> data = readData;
  newNode -> next = NULL; // 이렇게 꼭 NULL로 초기화해야 되는지. 선언만 하면 안되는지 물어보기.
  // 어차피 초기화안해도 next는 NULL이지 않을지 물어보자.
  if(head == NULL)
  	head = newNode;
  else // head != NULL
  	tail->next = newNode;

  tail = newNode;

 }
 printf("\n");

 //입력 받은 데이터의 출력과정
 printf("입력 받은 데이터의 전체 출력 \n");
 if(head == NULL)
 	 printf("저장된 자연수가 존재 x");
 else{
 	 cur = head; // 현재 노드는 헤드 노드로 할당.
   printf("%d ", cur->data);

   while(cur->next != NULL){
     cur = cur -> next;
     printf("%d ", cur->data);
	 }
 }
  printf("\n\n");


  // 메모리의 해체 과정
  if(head == NULL){ 
    return 0; // 해체할 노드가 존재하지 않는다.
  }
  else{
    Node *delNode = head;
    Node *delNextNode = head -> next;
   
    printf("%d를 삭제합니다. \n", delNode -> data);
    free(delNode);
    
    while(delNextNode != NULL){ // 두번째 이후 노드 삭제.
      
      delNode = delNextNode;
      delNextNode = delNextNode->next;
     
      printf("%d를 삭제합니다. \n", delNode -> data );
      free(delNode);
    }
  }
  return 0;
}
