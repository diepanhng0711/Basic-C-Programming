#include "stackRec.h"

int main(){
  int a[] = {6,5,8,9,15,10,67,8};
  int i;
  StackType s;
  initialize(&s);
  for(i = 0; i < 8; i++) push(a[i], &s);

  printf("Pop all elements from stack!\n");
  while(!isEmpty(s)){
    printf("%d  -  top: %d\n", pop(&s), s.top);
    printf("top: %d\n", s.top);
  }

  return 0;
}