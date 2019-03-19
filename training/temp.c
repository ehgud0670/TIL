
int compare1(const void *a,const void *b){

  return  *((int*)a) - *((int*)b); // 오름차순
}

int compare2(const void *a,const void *b){
  
  return  *((int*)b) - *((int*)a); // 내림차순
}
