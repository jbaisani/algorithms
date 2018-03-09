#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>

struct Node {
  int key;
  Node *prev;
  Node *next;
};

Node *nil;

void insert(int key){
  Node *x = (Node*)malloc(sizeof(Node));
  x->key = key;
  x->next = nil->next;
  nil->next->prev = x;
  x->prev = nil;
  nil->next = x;
}

Node* listSearch(int key){
  Node *cur = nil->next;
  while (cur != nil && cur->key != key) {
    cur = cur->next;
  }
  return cur;
}

void deleteNode(Node *t){
  if (t == nil) {
    return ;
  }

  t->prev->next = t->next;
  t->next->prev = t->prev;
  free(t);
}

void deleteKey(int key){
  deleteNode(listSearch(key));
}

void deleteLast(){
  deleteNode(nil->prev);
}

void deleteFirst(){
  deleteNode(nil->next);
}

void init(){
  nil = (Node*)malloc(sizeof(Node));
  nil->prev = nil;
  nil->next = nil;
}

void printList(){
  Node* cur = nil->next;
  int isf = 0;
  while (1) {
    if (cur == nil) {
      break;
    }

    if (isf++ > 0) {
      printf(" ");
    }

    printf("%d", cur->key);
    cur = cur->next;
  }
  printf("\n");
}



int main(int argc, char const *argv[]) {
  int key, n;
  int size = 0;

  char com[20];

  int np = 0;
  int nd = 0;

  scanf("%d", &n);

  init();

  for(int i = 0; i < n; i++){
    scanf("%s%d", com, &key);
    if (com[0] == 'i') {
      insert(key);
      np++;
      size++;
    }else if (com[0] == 'd') {
      if (strlen(com) > 6) {
        if (com[6] == 'F') {
          deleteFirst();
        }else if (com[6] == 'L') {
          deleteLast();
        }
      }else{
        deleteKey(key);
        nd++;
      }
      size--;
    }
  }

  printList();

  return 0;
}
