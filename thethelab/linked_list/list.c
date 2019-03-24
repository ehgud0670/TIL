# include <stdio.h>
# include <stdlib.h>

struct Node{
  
  int data;
  struct Node *next;
};

struct Node *head= NULL;

void linsert(struct Node *temp, int data){
  //temp = (struct Node*)malloc(sizeof(struct Node));   malloc을 쓰면 새로운 메모리를 할당하기 때문에 기존의 지역변수가
  // call by reference가 통하지 않은 것이다.
  temp -> data = data;
  //linked 하기
  temp -> next = head; //처음엔 NULL. head가 처음엔 null이었으니깐.
  head = temp;
  
}
void lprint(){
  struct Node *current = head;
  while(current){
    printf("%d ", current -> data);
    current = current -> next;
	}
}

int main(){
  
  struct Node node[10];
  int i;
  //정수 10개 전송

  for(i=0; i<10; i++){
    linsert(node + i,i+1);    
	}
	

	printf("노드 element 0~9까지 data 값: ");
  for(i=0; i<10; i++){
     printf("%d ",(node+i)->data);  // call by reference 안되는 이유 찾았다.
	}
  printf("\n\n");	

  printf("연결리스트 헤드부터 data 값: ");
  lprint();
  printf("\n\n");	

  return 0;
}
