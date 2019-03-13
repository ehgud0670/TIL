#ifndef __D_LINKED_LIST_H__
#define __D_LINKED_LIST_H__

# include <stdio.h>
# include <stdlib.h>

# define TRUE 1
# define FALSE 0

typedef int Ldata;

typedef struct _node{
  
  Ldata data;
  struct _node *next;
}Node;


typedef struct _linkedlist{
  Node * head;
  Node * cur;
  Node * before;
  int numofData;
  int (*comp)(Ldata d1, Ldata d2);
} LinkedList;

typedef LinkedList llist;

void ListInit(llist * plist);
void Linsert(llist * plist, Ldata data);

int Lfirst(llist *plist, Ldata *pdata);
int Lnext(llist *plist, Ldata * pdata);

Ldata Lremove(llist * plist);
int Lcount(llist * plist);

void SetSortRule(llist * plist, int (*comp) (Ldata d1, Ldata d2));

# endif
