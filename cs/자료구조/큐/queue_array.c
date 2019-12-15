#include <stdio.h>

# define SIZE 5

int queue[SIZE]={-1,};

int front = -1;
int rear = -1;

void enqueue(int data){

   if(rear == SIZE -1){
     printf("------queue is full------\n");
     return;
	 }
   queue[++rear] = data;

}

int dequeue(){
  
  if(front == rear){
    printf("------queue is empty------\n");
	  return -1;
	}
	int data = queue[++front];
  queue[front] = -1;
}

void printQueue(){

  int i;
  printf("Order : first - in\n");
  for(i= front+1; i<=rear; i++){
	   printf("%d ", queue[i]);
	}
	printf("\n");
}

int main(){
  int i;
  for(i=0;i<5;i++){
    enqueue(i);
	}
  printQueue();

  for(i=0;i<5;i++){
    dequeue(i);
	}
  printQueue();

  printf("rear : %d \n", rear);
  enqueue(10);

  return 0;
}
