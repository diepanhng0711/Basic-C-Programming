#include <stdio.h>
#include <stdlib.h>

typedef int elementType;
typedef struct StackType_t{
  elementType element;
  struct StackType_t *next;
} StackType;

int isEmpty(StackType *top){
  return top == NULL;
}

elementType getData(){
  elementType tmp;
  printf("New element = ");scanf("%d", &tmp);
  return tmp;
}

StackType *makeNewNode(elementType ele){
  StackType *New = (StackType *) malloc(sizeof(StackType));
  if(New == NULL) return NULL;

  New->element = ele;
  New->next = NULL;
  return New;
}

void push(elementType ele, StackType **top){
  StackType *New = makeNewNode(ele);
  if(New == NULL){
    printf("Stack overflow");
    return;
  }
  
  New->next = *top;
  *top = New;
}

elementType pop(StackType **top){
  if (isEmpty(*top))
  {
    printf("Stack underflow");
    return -999999;
  }

  elementType a;
  StackType *del = *top;
  a = (*top) -> element;
  *top = (*top) -> next;
  free(del);
  return a;
}

elementType top(StackType *top){
  return top->element;
}

void freeStack(StackType **top){
  while (!isEmpty(*top))
  {
    pop(top);
  }
}