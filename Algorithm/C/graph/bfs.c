#include <stdio.h>
#include <stdlib.h>

#define VERTEX_NUM 7
#define QUEUE_SIZE 6 
#define TRUE 1
#define FALSE 0

int isQueueEmpty();
int isQueueFull();

struct Node {

	int v;
	struct Node *next;
};

struct Node *graph[VERTEX_NUM];


// if visited, visited[i] = 1
//  otherwise, visited[i] = 0    
int visited[VERTEX_NUM];

// related queue
int queue[QUEUE_SIZE];

int front = 0;
int rear = 0;

void enqueue(int v){

	if(isQueueFull() == TRUE){
		printf("----queue is full----\n");
		return;
	}
	rear = (rear + 1) % QUEUE_SIZE;
	queue[rear] = v;
}

int dequeue(){

	if(isQueueEmpty() == TRUE){
		printf("----queue is empty----\n");
		return -1;
	}
	front = (front + 1) % QUEUE_SIZE;
	int v = queue[front];
	queue[front] == -1;
	return v;
} 

int isQueueEmpty(){

	return rear == front ? TRUE : FALSE;

}

int isQueueFull(){

	return (rear + 1) % QUEUE_SIZE == front ? TRUE : FALSE;   

}

void printQueue(){
	int i;
	// rear의 인덱스가 front의 인덱스보다 작을 수 있으므로(원형 큐라서)
	// 따라서 그냥 전체를 검사하고 -1인 경우를 제외한다. 
	for(i = 0; i < QUEUE_SIZE; i++){
		int v = queue[i];
		if(v != -1){
			printf("%d ",v);
		}
	}
	printf("\n");
}

// related graph

void add_next(int v1,int v2){

	struct Node *new = (struct Node*)malloc(sizeof(struct Node));
	new -> v = v2;
	new -> next = NULL;

	struct Node *cur = graph[v1];

	if(!cur){
		graph[v1] = new;  
	} else {

		while(1){
			if(!cur -> next){
				cur -> next = new;
				break;
			}
			cur = cur -> next; 
		}
	}

}

void addEdge(int v1, int v2, int reverse){

	add_next(v1,v2);
	if(reverse == TRUE){
		add_next(v2,v1);
	}
}

void printLists(){
	int i;
	for(i=0; i<VERTEX_NUM; i++){
		printf("vertex %d :", i);
		struct Node *cur = graph[i];
		while(cur){
			printf("%d ", cur -> v);
			cur = cur -> next;
		}
		printf("\n");
	}
	printf("\n");
}

void showAdjacentVertex(int v){

	printf("vertex %d :", v);

	struct Node *cur = graph[v];
	while(cur){
		printf("%d ", cur -> v);
		cur = cur -> next;
	}
	printf("\n");

}

void enqueueAdjacentVertex(int vertex_num){

	struct Node *cur = graph[vertex_num];

	while(cur){
		int v = cur -> v;
		int i;
		int equalCheck = FALSE;
		// check v is already visited 
		if(visited[v] == FALSE){
		// check v is already in the queue 
			for(i=0;i<QUEUE_SIZE;i++){
				if(v == queue[i]){
					equalCheck = TRUE;
					break;
				}
			}
		  if(equalCheck == FALSE){
			  enqueue(v);
		  }
		}
		cur = cur -> next;
	}


}

void doBFS(int v){

	enqueue(v);

	while(isQueueEmpty() == FALSE){

		int vertex_num = dequeue();
		visited[vertex_num] = TRUE;
		printf("visited vertex: %d \n",vertex_num);

		enqueueAdjacentVertex(vertex_num);

	}
}

int main(){

	addEdge(0,4,TRUE);
	addEdge(0,5,TRUE);
	addEdge(0,6,TRUE);
	addEdge(4,1,TRUE);
	addEdge(5,2,TRUE);
	addEdge(6,3,TRUE);

	printLists();  
	doBFS(0); 


	return 0;
}
