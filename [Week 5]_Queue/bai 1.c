#include "stacklist.h"
#include "stacklist_undo.h"
int main()
{
  StackType *top = NULL;
  Undo *undo = NULL;
  int key, x;
  elementT tmp;

  printf("---MENU---\n"
         "1. Add 1 integer to the stack\n"
         "2. View top\n"
         "3. Remove 1 integer element from stack\n"
         "4. Undo\n"
         "5. Exit\n");

  while (1)
  {
    printf("Please enter your selection: ");
    scanf("%d%*c", &key);
    if (isEmpty(top) && (key== 2 || key== 3))
    {
      printf("overflow\n");
      continue;
    }

    if (isEmpty2(undo) && key== 4)
    {
      printf("Can't undo!\n");
      continue;
    }

    switch (key)
    {
    case 1:
      printf("Input x: ");
      scanf("%d", &x);
      push(x, &top);
      push2(data(0, x), &undo);
      break;
    case 2:
      printf("%d\n", peek(top));
      break;
    case 3:
      x = pop(&top);
      push2(data(1, x), &undo);
      break;
    case 4:
      tmp = pop2(&undo);
      if(tmp.t[0] == 1){
        push(tmp.t[1], &top);
      }
      else
      {
        pop(&top);
      }
      break;
    case 5:
      freeStack(&top);
      freeStack2(&undo);
      printf("    Exit !\n");
      exit(0);
    default:
      break;
    }
  };
  return 0;
}
