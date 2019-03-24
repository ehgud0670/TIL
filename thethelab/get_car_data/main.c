# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define MAX 512
# define ROW 400

# define ADD_ITEM(items,item,index) \
  (items) -> item[index/32] |= (1 << index % 32)
# define HAS_ITEM(items,item,index)  \
	(items) -> item[index/32] & (1 << index % 32)
# define REMOVE_ITEM(items,item,index) \
	(items) -> item[index/32] &= ~(1 << index % 32)

# define list_entry(ptr, type, member)  \
  (type*)((char*)ptr - (size_t)&(((type*)0)->member))

struct node{

  struct node *prev;
  struct node *next;

};

enum car_type{
  CELL_DX,
  SPORTS_CAR,
  SUV,
  WAGON,
  MINIVAN,
  PICKUP,
  AWD,
  RWD,
  MAX_ITEM_COUNT = 1024,
};

enum car_type types[8] = {
  CELL_DX,
  SPORTS_CAR,
  SUV,
  WAGON,
  MINIVAN,
  PICKUP,
  AWD,
  RWD
};

struct dataset{

  unsigned int offset[32];
};

struct car{
  
  char *name;
  struct dataset kind;
  int retail_price;
  int dealer_cost;
  double engine_size;
  int weight;
  int width;
  struct node links;
};

struct node head = {&head,&head};

//Vehicle Name,CellDx,Sports Car,SUV,Wagon,Minivan,Pickup,AWD,RWD,Retail Price,Dealer Cost,EngineSize,Weight,Width
void getKind(struct car *car, char **kind1, char **kind2){

  // type1
  if(HAS_ITEM(&car -> kind, offset, types[0]))
    *kind1 = strdup("CellDx");
  else if(HAS_ITEM(&car -> kind, offset, types[1]))
    *kind1 = strdup("Sports car");
  else if(HAS_ITEM(&car -> kind, offset, types[2]))
    *kind1 = strdup("SUV");
  else if(HAS_ITEM(&car -> kind, offset, types[3]))
    *kind1 = strdup("Wagon");
  else if(HAS_ITEM(&car -> kind, offset, types[4]))
    *kind1 = strdup("Minivan");
  else 
    *kind1 = strdup("Pickup");

  //type2
  if(HAS_ITEM(&car -> kind, offset, types[6]))
    *kind2 = strdup("AWD");
  else if(HAS_ITEM(&car -> kind, offset, types[7]))
    *kind2 = strdup("RWD");
  else //7 
    *kind2 = strdup("None");
}


void print_list(struct node *head){

	struct node *current = head->next;
  char *kind1;
  char *kind2;

  while(current != head){
    struct car *car = list_entry(current, struct car, links);
    getKind(car , &kind1, &kind2);
    printf("%s ", car->name);
    printf("%s ", kind1);
    printf("%s \n", kind2);

    current = current ->next;
	}
  free(kind1);
  free(kind2);
}
void __add_node(struct node *prev, struct node *next, struct node *new){

  new -> prev = prev;
  new -> next = next;
  prev -> next = new;
  next -> prev = new;

}

void add_front(struct node *head, struct node *new){

  __add_node(head->prev, head, new);

}

void add_next(struct node *head, struct node *new){

  __add_node(head, head->next, new);

}
struct car* make_car(char *buf){
  
  struct car *car;
  int i;
  char *p;


  car = (struct car*)malloc(sizeof(struct car));

  for(i=0,p=strtok(buf,",");p!=NULL;i++,p=strtok(NULL,",")){
     switch(i){
       case 0:
         car -> name = strdup(p);
         break;
     	 case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8:
         if(atoi(p) == 1)
           ADD_ITEM(&car->kind, offset, types[i-1]);
         break;
			 case 9:
			   car -> retail_price = atoi(p);
         break;
			 case 10:
			   car -> dealer_cost = atoi(p);
         break;
			 case 11:
			   car -> engine_size = atof(p);
         break;
			 case 12:
			   car -> weight = atoi(p);
         break;
			 case 13:
			   car -> width = atoi(p);
         break;
		 }   
	}

  return car;
}

int compare_idx;

int compare_ascending(const void *a , const void *b){
  
  struct car *num1 = *(struct car **)a;
  struct car *num2 = *(struct car **)b;
  
  switch(compare_idx-1){
    case 0:
      return num1 -> retail_price - num2 ->retail_price;
    case 1:
      return num1 -> dealer_cost - num2 -> dealer_cost;
    case 2:
      if (num1 -> engine_size > num2 -> engine_size)
      	return 1;
      else
      	return -1;
    case 3:
      return num1 -> weight - num2 -> weight;
    case 4:
      return num1 -> width - num2 -> width;
	}
}

int compare_descending(const void *a , const void *b){
  
  struct car *num1 = *(struct car **)a;
  struct car *num2 = *(struct car **)b;
  
  switch(compare_idx-1){
    case 0:
      return num2 -> retail_price - num1 ->retail_price;
    case 1:
      return num2 -> dealer_cost - num1 -> dealer_cost;
    case 2:
      if (num2 -> engine_size > num1 -> engine_size)
      	return 1;
      else
      	return -1;
    case 3:
      return num2 -> weight - num1 -> weight;
    case 4:
      return num2 -> width - num1 -> width;
	}

}

void print_car(struct car  **cars,int count, FILE  *snapshot){

  int i=0;
  char *kind1,*kind2;
  if(snapshot == NULL){
  	for(i=0;i<count; i++){
      getKind(cars[i], &kind1, &kind2);
      printf("%-40s ", cars[i]->name);
      printf("%-15s ", kind1);
      printf("%-15s ", kind2);
      printf("%-5d ", cars[i]->retail_price);
      printf("%-5d ", cars[i]->dealer_cost);
      printf("%-5f ", cars[i]->engine_size);
      printf("%-5d ", cars[i]->weight);
      printf("%-5d ", cars[i]->width);
      printf("\n");
     }
	}
	else{
  	for(i=0;i<count;i++){
      getKind(cars[i], &kind1, &kind2);
      fprintf(snapshot,"%-40s, ", cars[i]->name);
      fprintf(snapshot,"%-15s, ", kind1);
      fprintf(snapshot,"%-15s, ", kind2);
      fprintf(snapshot,"%-5d, ", cars[i]->retail_price);
      fprintf(snapshot,"%-5d, ", cars[i]->dealer_cost);
      fprintf(snapshot,"%-5f, ", cars[i]->engine_size);
      fprintf(snapshot,"%-5d, ", cars[i]->weight);
      fprintf(snapshot,"%-5d ", cars[i]->width);
      fprintf(snapshot,"\n");
		}
	}

	free(kind1);
	free(kind2);
}
void print_file(struct car **cars, int count){

  char file_name[32];
  
  printf("파일이름 > ");
  scanf("%s",file_name);
  
  FILE *snapshot = fopen(file_name,"w");
  print_car(cars,count,snapshot);
  fclose(snapshot);
}

int filter(struct car **cars, struct node *head, int sel_kind, int sel_info, int sel_flow){
  int count;
  struct node *current = head -> next;
  

  //1st filter
  count =0;
  while(current != head){
    struct car *car = list_entry(current,struct car, links);
    
    if(HAS_ITEM(&car->kind,offset, types[sel_kind-1]))
      cars[count++] = car;
    
    current = current -> next;
	}

	//2st filter
	compare_idx  = sel_info;
 
  if(sel_flow ==1)
  	qsort(cars, count, sizeof(struct car*), compare_ascending);
  else
  	qsort(cars, count, sizeof(struct car*), compare_ascending);

  return count;
}

int main(){

  //파일 열기
  FILE *fp;
  char buf[512];
  int i;
  struct car *car;
  struct car *cars[ROW];

  fp = fopen("car_data.csv", "r");
  
  i=0;
  while(fgets(buf,MAX,fp) != NULL){
    if(i++ == 0)
      continue;
    
    car = make_car(buf);

    add_front(&head, &car->links);
   
	}

  printf("총 %d 의 데이터가 로드되었습니다. \n", i-1);
  
  while(1){
    int option;
    int flag=0;
    int sel_kind;
    int sel_info;
    int sel_flow;
    int sel_save;
    
    printf("1.검색 \n");
    printf("2.종료 \n");
    printf("선택 > ");
    scanf("%d", &option);
  
//Vehicle Name,CellDx,Sports Car,SUV,Wagon,Minivan,Pickup,AWD,RWD,Retail Price,Dealer Cost,EngineSize,Weight,Width
    switch(option-1){
      case 0:
        printf("1.CellDx \n");
        printf("2.Sports car \n");
        printf("3.SUV \n");
        printf("4.Wagon \n");
        printf("5.Minivan \n");
        printf("6.Pickup \n");
        printf("7.AWD \n");
        printf("8.RWD \n");
        printf("선택 > ");
        scanf("%d", &sel_kind);
        
        printf("1.Retail Price \n");
        printf("2.Dealer Cost \n");
        printf("3.Engine Size \n");
        printf("4.Weight \n");
        printf("5.Width \n");
        printf("선택 > ");
        scanf("%d", &sel_info);

        printf("1.오름차순 정렬 \n");
        printf("2.내림차순 정렬 \n");
        printf("선택 > ");
        scanf("%d", &sel_flow);
        
        int count;
        count = filter( cars, &head, sel_kind , sel_info , sel_flow);
        print_car(cars,count,NULL);

        printf("파일로 저장하시겠습니까?\n");
        printf("1. 예\n");
        printf("2. 아니오\n");
        printf("선택 > ");
        scanf("%d", &sel_save);
        if(sel_save ==1){
        	print_file(cars,count);
				}
        break;
      case 1:
        flag =1;
        break;
  }
    if(flag ==1)
  	  break;
  
  }
  return 0;
}
