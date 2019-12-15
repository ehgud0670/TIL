# define FALSE 0
# define TRUE 1

// r은 remove 의 약자이다. 

int LFirst(llist *plist, Ldata *pdata){
  
  if(plist->head->next == NULL) //더미노드(헤드)의 next 값이 NULL이라면
    return FALSE; //반환할 데이터가 없음.
	
	plist -> before = plist ->head; // before는 더미 노드를 가리키게 함
  plist -> cur = plist -> head -> next; //cur은 첫번째 노드를 가리키게 함.

  *pdata = plist -> cur -> data;
  return TRUE; // 데이터 반환 성공. 

}

int LNext(llist *plist, Ldata *pdata){
  if(plist->cur->next == NULL) // cur 이후에 노드가 없다면,(cur의 next값이 null이라면)
    return FALSE;
  
  plist -> before = plist -> cur ; // cur이 가리키던 것을 before가 가리킴.
  plist -> cur = plist -> cur -> next; // cur 은 그 다음의 노드를 가리키게 한다. 

  *pdata = plist -> cur -> data;
  return TRUE; //데이터 반환 성공
}

Ldata LRemove(llist *plist){

  Node *rpos = plist -> cur;  // 소멸 대상의 주소값을 rpos에 저장.
  Ldata rdata = rpos -> data; // 소멸 대상의 데이터를 rdata에 저장.

  plist -> before -> next = plist->cur->next; // 소멸 대상을 연결리스트에서 제거
  plist -> cur = plist -> before; // cur 의 위치 재조정.

  free(rpos); // 연결리스트에서 제거된 노드 free()로 소멸시킴( 메모리 공간 자체가 없어짐)
  (plist -> numofData)--; // 저장된 데이터의 수 하나 감소
  return rdata;
}


