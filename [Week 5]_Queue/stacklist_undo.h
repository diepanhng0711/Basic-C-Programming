typedef struct
{
  int t[2];     // t[0] = 1 : push; t[0] = 0 : pop; t[1]: number is pushed or poped.
} elementT;

typedef struct Undo
{
  elementT element;
  struct Undo *next;
} Undo;

int isEmpty2(Undo *top){
  return top == NULL;
}

elementT data(int thaotac, int num){
  elementT dulieu;
  dulieu.t[0] = thaotac;
  dulieu.t[1] = num;
  return dulieu;
}

Undo *makeNewNode2(elementT ele){
  Undo *New = (Undo *) malloc(sizeof(Undo));
  if(New == NULL) return NULL;

  New->element = ele;
  New->next = NULL;
  return New;
}

void push2(elementT ele, Undo **top){
  Undo *New = makeNewNode2(ele);
  if(New == NULL){
    printf("Stack overflow");
    return;
  }
  
  New->next = *top;
  *top = New;
}

elementT pop2(Undo **top){
  elementT temp;
  if (isEmpty2(*top))
  {
    printf("Stack underflow");
    temp.t[0] = -1;
    temp.t[1] = -1;
    return temp;
  }

  elementT a;
  Undo *tmp = *top;
  *top = (*top)->next;
  a = tmp->element;
  free(tmp);
  return a;
}

elementT top2(Undo *top){
  if(!isEmpty2(top))  return top->element;
}

void freeStack2(Undo **top){
  while (!isEmpty2(*top))
  {
    pop2(top);
  }
}