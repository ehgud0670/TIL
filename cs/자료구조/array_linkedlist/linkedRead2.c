# include <stdio.h>
# include <stdlib.h>

# define true 1

typedef struct _node{
  int data;
  struct _node *next;
}Node;

int main(){

  // 초기화
  Node *Head = NULL;
  Node *Tail = NULL;
  Node *Cur = NULL;
  Node *newNode = NULL;

  int readData;
  int readCount;

  
  //양의 정수입력
  while(true){

    printf("양의 정수를 입력하세요: ");
    scanf("%d", &readData);

    if(readData<1)
    	break;

    newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = readData;
    newNode -> next = NULL; // 구조체 변수의 포인터 값은 null 로 초기화 안해도 값이 null 인지.


  
    if(Head == NULL)
    	Head = newNode;
    else // Head != NULL 
		  Tail-> next = newNode; 
  
		Tail = newNode;

	}

  printf("\n");

  // Node의 value들 값 출력.  Cur 사용하기
  Cur = Head;
  printf("node's value: %d\n", Cur -> data);
  
  while(Cur -> next != NULL){
    Cur = Cur ->next;
    printf("node's value: %d\n", Cur -> data); 

	}
  printf("\n");

  //Node들 해체하기.
  Node *delNode = Head;
  Node *delNodeNext = delNode -> next;

  printf("해체 될 Node 의 Value 값: %d \n", delNode -> data);
  free(delNode);
  printf("해체되었습니다. \n");

  while(delNode -> next != NULL ){
    
    delNode = delNodeNext; // tail  //null
    delNodeNext = delNodeNext -> next; //null //잘못된 메모리 참조 (Segmentaion Error)
   
   printf("해체 될 Node 의 Value 값: %d \n", delNode -> data);
    free(delNode);
    printf("해체되었습니다. \n");
	}
  printf("\n");

  return 0;
}

