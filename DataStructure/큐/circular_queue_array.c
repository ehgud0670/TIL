#include <stdio.h>

# define QUEUE_SIZE 5
# define TRUE 1
# define FALSE 0

int queue[QUEUE_SIZE]={-1,};

int front = 0;
int rear  =  0;

int isQueueEmpty(){

  return front == rear ? TRUE : FALSE;

}

int isQueueFull(){

  return (rear+1)%(QUEUE_SIZE) == front ? TRUE : FALSE;
}

void enqueue(int data){

   if(isQueueFull() == TRUE){
     printf("------queue is full------\n");
     return;
	 }
	 rear = (rear+1)%QUEUE_SIZE;
   queue[rear] = data;

}

int dequeue(){
  
  if(isQueueEmpty() == TRUE){
    printf("------queue is empty------\n");
	  return -1;
	}
	front = (front+1)%QUEUE_SIZE;
	int data = queue[front];
  queue[front] = -1;
}

void printQueue(){

  int i;
  printf("Order : first - in\n");
  for(i= 0; i<QUEUE_SIZE; i++){
	   int data = queue[i];
	   if(data != -1){ 
	     printf("%d ", queue[i]);
		 }
	}
	printf("\n");
}

int main(){
  int i;
  for(i=0;i<QUEUE_SIZE;i++){
    enqueue(i);
	}
  printQueue();

  for(i=0;i<QUEUE_SIZE-1;i++){
    dequeue(i);
	}
  printQueue();

  printf("rear : %d \n", rear);
  enqueue(10);
  printQueue();
  
  return 0;
}
