# include <stdio.h>
# include <stdlib.h>

# define VERTEX_NUM 4

void add_next(int v1, int v2 );

struct Node {

	int vertex_num;
	struct Node *next;

};

struct Node *graph[4]; 

void addEdge(int v1, int v2){

	add_next( v1 , v2 );
	add_next( v2 , v1 );

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
	for(i=0;i<4;i++){
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
int main(){

	int i;

	addEdge(0,1);
	addEdge(0,2);
	addEdge(0,3);
	printLists();
	showAdjacentVertex(0);


}
