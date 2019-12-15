# include <stdio.h>
# include <stdlib.h>

# define VERTEX_NUM 5
# define TRUE 1
# define FALSE 0

void add_next(int v1, int v2 );

/*******Node*********/
struct Node {

	int vertex_num;
	struct Node *next;
}; 

struct Node *graph[VERTEX_NUM]; 
/*******Node*********/


/**********Stack**********/
struct Stack{

	struct Node *arr[VERTEX_NUM];

};

struct Stack stack;
int size = VERTEX_NUM;
int index_num = 0;

void initStack(){
	int i;
	for(i = size == VERTEX_NUM? 0: size/2; i<size; i++){
		stack.arr[i] = NULL;
	}
}

void push(struct Node *data){

	if(index_num == size){
		size = 2*size;
		initStack();
	} 
	stack.arr[index_num++] = data;
}

struct Node* (pop()){
	if(index_num == 0){
		printf("no data\n");
		return NULL;
	} 
	struct Node *data = stack.arr[--index_num];
	stack.arr[index_num] = NULL;
	return data;
}

struct Node* (peek()){
	if(index_num == 0){
		printf("no data\n");
		return NULL;
	} 

	return stack.arr[index_num-1];

}

// return 1 if the stack is empty
// 				0 otherwise
int isStackEmpty(){
	int i;
	int count = 0;
	for(i=0;i<size;i++){
		if(stack.arr[i] == NULL){
			break;
		}
		count++;
	}

	return count == 0 ? TRUE : FALSE ; 
}
/**********Stack**********/

/**********List***********/

void addEdge(int v1, int v2, int reverse){

	add_next( v1 , v2 );
	if(reverse == 1){
		add_next( v2 , v1 );
	}
}

void add_next(int v1, int v2 ){

	struct Node *new = (struct Node*)malloc(sizeof(struct Node));
	new -> vertex_num = v2;
	new -> next = NULL;


	if(graph[v1] == NULL){
		graph[v1] = new;
	} else {

		struct Node *current = graph[v1];

		while(1){

			if(current -> next == NULL){
				current -> next = new;
				break;
			}
			current = current-> next;
		}
	}

}


void printLists(){

	int i;
	for(i=0;i<VERTEX_NUM; i++){
		printf("vertex %d : ",i); 

		struct Node *current = graph[i];
		if(current == NULL){
			printf("None \n");
		} else {

			while(current){
				printf("%d ", current -> vertex_num);
				current = current -> next;
			}
			printf("\n");
		}
	}
}

void showAdjacentVertex(int v){

	struct Node *current = graph[v];

	printf("%d's adjacent Node : ", v);
	while(current){
		printf("%d ", current -> vertex_num);
		current = current -> next;
	}
	printf("\n");

}
/**********List***********/
int visited[VERTEX_NUM];
int j = 0;

void doDFS(int vertex_num){

	initStack();
	
	visited[j++] = vertex_num;	
	push(graph[vertex_num]);
	while(isStackEmpty() == FALSE){
		struct Node *node = peek(); 

		int check;
		while(node){
			check = FALSE;

			int node_num = node -> vertex_num; 

			int i;
			for(i=0;i<j;i++){
				if(visited[i] == node_num){
					check = TRUE;
					break;
				}
			}
			if(check == FALSE){
				visited[j++] = node_num; 
				push(graph[node_num]);
				break;
			} 
			node = node -> next;
		} 
		if(check == TRUE){
			pop();   
		}

	}


}

int main(){

	int i;

	addEdge(0,1,1);
	addEdge(0,4,1);
	addEdge(0,2,1);
	addEdge(3,4,1);

	printLists();
	showAdjacentVertex(0);

	// Depth First Search
  doDFS(0);
	
	printf("\n");
	printf("DFS\n");
	printf("visited: ");
	for(i=0;i<j;i++){
		printf("%d ", visited[i]);
	}
	printf("\n");
	return 0;
}
