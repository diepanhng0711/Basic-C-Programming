#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct phone_tt {
  char model[50];
  char space[5];
  char size[5];
  char price[11];
} phoneinfo;

typedef phoneinfo elementType;

typedef struct Node {
  elementType inf;
  struct Node *next;
} Node;

Node *root = NULL, *cur = NULL, *prev = NULL;

elementType get_Data()
{
	elementType new;
	printf("Model: ");
	scanf("%s%*c", new.model);
	printf("Space: ");
	scanf("%s%*c", new.space);
	printf("Screen size: ");
	scanf("%s%*c", new.size);
	printf("Price: ");
	scanf("%s%*c", new.price);
	return new;
}

void display_Node(Node *p, int i)
{
	printf("%d  -  %s  -  %s  -  %s  -  %s\n", i, (p->inf).model, (p->inf).space, (p->inf).size, (p->inf).price);
}

Node *make_New_Node(elementType inf){
	Node *new = (Node*) malloc(sizeof(Node));
	new->inf = inf;
	new->next = NULL;
	return new;
}

void traverse_List() {
  Node *ptr;
  int i = 1;
  for (ptr = root; ptr != NULL; ptr = ptr->next)
  {
    display_Node(ptr, i);
    i++;
  }
}


void insert_At_Head(elementType inf) {
	Node *new = make_New_Node(inf);
	if (root == NULL) {
		root = new;
		cur = new;
	} else {
		new->next = root;
		root = new;
		cur = root;
	}
}

void insert_After_Current_Position(elementType inf) {
	Node *new = make_New_Node(inf);
	if (root == NULL) {
		root = new;
		cur = new;
	} else if (root != NULL && cur == NULL) return; //Khong tim thay con tro cur! 
	else {
		new->next = cur->next;
		cur->next = new;
		prev = cur;
		cur = cur->next;
	}
}

void insert_Before_Current_Position(elementType inf) {
	Node *new = make_New_Node(inf);
	if (root == NULL) {
		root = new;
		cur = new;
		prev = NULL;
	} else {
		Node *tmp = root;
		while (tmp != NULL && tmp->next != cur && cur != NULL)
		{
			tmp = tmp->next;
		}
		prev =tmp;

		new->next = cur;
    	if (cur == root){
      		root = new;
    		}
    	else {
      		prev->next = new;
    	}	
    	cur = new;
	}
}

void Free() {
  Node *to_free = root;
  while (to_free != NULL)
  {
    root = root->next;
    free(to_free);
    to_free = root;
  }
}

void delete_First_Element() {
  	if (root == NULL){
    	printf("root == NULL!\n");
    	return;
  	}

 	Node *tmp;
  	tmp = root;
	root = root->next;
	cur = root;
  	prev = NULL;
  	free(tmp);
}

void delete_Current_Element() {
  	if (cur == NULL)
		return;
	if (cur == root) delete_First_Element();
  	else {
    	prev->next = cur->next;
    	free(cur);
    	cur = prev->next;
    	if(cur == NULL) cur = root;
    	/*  cur = root; */ 
  	}
}

Node *list_Reverse(Node *root) {
  	Node *cur, *prev;
  	cur = prev = NULL;
  	while (root != NULL) {
    	cur = root;
    	root = root->next;
    	cur->next = prev;
    	prev = cur;
  	}
  	return prev;
}

Node *insert_At_Position(Node *root, elementType inf, int n) {
  	int i;
	cur = root;
  	for (i = 0; i < n; i++){
    	prev = cur;
    	cur = cur->next;
  	}

  	Node *new = (Node *)malloc(sizeof(Node));
 	new->inf = inf;
  	new->next = cur->next;
  	cur->next = new;
  	if (root == NULL) root = cur;
  	if (n == 0) insert_At_Head(inf);
  	prev = cur;
  	cur = cur->next;
  	return new;
}

Node *delete_At_Position(Node *r, int n) {
  	if (r == NULL) return r;

  	cur = r;
  	prev = NULL;
  	for (int i = 0; i < n; i++) {
    	prev = cur;
    	cur = cur->next;
  	}

  	if (cur == r) {
    	delete_First_Element();
    	return root;
  	}

  	Node *temp = cur;
  	prev->next = cur->next;
  	cur = cur->next;
  	if(cur == NULL){
    	cur = root;
    	prev = NULL;
  	}
  	free(temp);
  	return root;
}

Node *spilt(Node *r, int n1, int n2) {
  	int i;
	Node *root1 = NULL;
  	cur = r;
  	for (i = 0; i < n1; i++) {
    	prev = cur;
    	cur = cur->next;
  	}

  	root1 = cur;
  	for (i = 1; i < n2; i++) {
    	cur = cur->next;
  	}

  	prev->next = cur->next;
  	cur->next = NULL;
  	cur = prev->next;
  	return root1;
}

void save_to_Text(Node *r, char *filename)
{
  	FILE *fptr = fopen(filename, "w");
  	if (fptr == NULL)
  	{
    	printf("Khong the mo file %s\n", filename);
    	return;
  	}
  	Node *curr;
  	for (curr = r; curr != NULL; curr = curr->next)
  	{
    	fprintf(fptr, "%s\t%s\t%d%s\t%s\n", (curr->inf).model, (curr->inf).space, (curr->inf).size, (curr->inf).price);
    	printf("%d  -  %s  -  %s  -  %s  -  %s\n", (curr->inf).model, (curr->inf).space, (curr->inf).size, (curr->inf).price);
  	}
  	printf("File saved successfully!\n");
  	fclose(fptr);
}