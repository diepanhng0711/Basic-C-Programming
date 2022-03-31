typedef struct node{
  ElementType ele;
  struct node *prev;
  struct node *next;
} node;

typedef node* doublelist;

node *makeNewNodeList(ElementType ele){
  node *new = (node *)malloc(sizeof(ElementType));
  new->ele = ele;
  new->prev = NULL;
  new->next = NULL;
  return new;
}

void deleteFirstElement(node **root, node **tail)
{
  if (*root == NULL)
  {
    printf("Con tro root NULL\n");
    return;
  }

  node *tmp;
  tmp = *root;
  *root = (*root)->next;
  free(tmp);
  if(*root == NULL){
    *tail = NULL;
  }
}

void deleteCurrentElement(node **root, node **cur, node **tail)
{
  if (*cur == NULL)
    return;
  if (*cur == *root)
  {
    deleteFirstElement(root, tail);
  }
  else
  {
    (*cur)->prev->next = (*cur)->next;
    if ((*cur)->next != NULL)
      (*cur)->next->prev = (*cur)->prev;
    else *tail = (*cur)->prev;
    free(*cur);
  }
}

void append(ElementType ele, doublelist *root, doublelist *tail){
  node *new = makeNewNodeList(ele);
  if(*root == NULL){
    *root = new;
    *tail = new;
  }
  else{
    (*tail)->next = new;
    new->prev = *tail;
    *tail = new;
  }
}

void displayNode(node *p)
{
  printf("%d\t%d\n", (p->ele).id, (p->ele).memory);
}

void traverseListFromRoot(node *root)
{
  node *p;
  for (p = root; p != NULL; p = p->next)
  {
    displayNode(p);
  }
}

void FreeList(node **root)
{
  node *to_free = *root;
  while (to_free != NULL)
  {
    *root = (*root)->next;
    free(to_free);
    to_free = *root;
  }
}
