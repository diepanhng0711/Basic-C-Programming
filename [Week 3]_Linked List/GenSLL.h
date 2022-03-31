#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct phoneinfo {
    char model[45];
    char memory[5];
    char size[6];
    char price[10];
} phoneinfo;

typedef struct node_phoneinfo {
    phoneinfo p_inf;
    node_phoneinfo *next;
} node_phoneinfo;

node_phoneinfo *cur, *root, *prev;
phoneinfo p_inf;

node_phoneinfo *make_New_Node(phoneinfo p_inf) {
    node_phoneinfo *new = (node_phoneinfo *) malloc(sizeof(node_phoneinfo));
    new -> p_inf = p_inf;
    new -> next = NULL;
}

phoneinfo read_Node(phoneinfo p_inf[]) {
    
    
    return p_inf;
}

void display_Note(node_phoneinfo *ptr){
    if (ptr == NULL) {
        printf("The pointer now is NULL\n");
        return;
    }
    phoneinfo info = ptr -> p_inf;
    printf("%s\n%s\n%s\n%s\n%p\n\n", info.model, info.memory, info.size, info.price);
}

void insert_At_Head(phoneinfo p_inf){
    node_phoneinfo *new = make_New_Node(p_inf);
    new -> next = root;
    root = new;
    cur = root;
}

void insert_After_Current_Position(phoneinfo p_inf){
    node_phoneinfo *new = make_New_Node(p_inf);
    if (root == NULL) {
        //Case 1: No element exists in the single linked list
        root = new;
        cur = root;
    } else {
        //Case 2: The common case
        new->next = cur->next;
        cur->next = new;
        // prev == cur;
        cur = cur->next;
    }
}

void insert_Before_Current_Position(phoneinfo p_inf){
    
    node_phoneinfo *new = make_New_Node(p_inf);
    if (root == NULL) {
        root = new;
        cur = root;
        prev = NULL;
    } else {
        node_phoneinfo *tmp = root;
        while (tmp->next!=cur && cur !=NULL) {
			tmp=tmp->next;
	    prev = tmp;
        }

        new->next=cur;
    	if (cur==root) {
			root = new; 
		}
		else {
            prev->next = new;
		    cur = new;
        }
    }
}

void delete_First_Element(){
    node_phoneinfo* del = root;
    del = del->next;
    free(del);
    cur = root;
}

void delete_Current_Element(){
    if (cur ==  root) delete_First_Element();
    else {
        node_phoneinfo *tmp = root;
        while (tmp->next != cur && cur != NULL){
            tmp = tmp->next;
            prev = tmp;
        }
        prev->next = cur->next;
        free(cur);
        cur = prev->next;
    }

}

void traversingList(){
node_phoneinfo * p;
for ( p = root; p!= NULL; p = p->next ) 
  displayNode(p);
}


node_phoneinfo *list_Reverse(node_phoneinfo *root){
    cur = prev = NULL;
    while (root != NULL) {
        cur = root;
        root = root->next;
        cur->next = prev;
        prev = cur;
    }
    return prev;
}

node_phoneinfo * insertAtPosition(phoneinfo ad, int n){
	int i=0;
   node_phoneinfo* p = root; 
   node_phoneinfo* new;
   node_phoneinfo* prev = p;
	 if (n==0 || root==NULL) { 
		new = make_New_Node(ad); 
        new->next=root; 	
        root=new; cur= new; 
        return new; 
	 }
   while ((i<n) && (p->next!= NULL)) {
       prev=p; 
       p=p->next; 
       i++;
       } 
   if (i<n) prev = p; 
   new = make_New_Node(ad); 
   new->next = prev->next;
	 prev->next = new; cur = new;
	 return new;
}	

node_phoneinfo * deleteAtPosition(int n){
	int i=0;
   node_phoneinfo* p = root; 
   node_phoneinfo* del;
   node_phoneinfo* prev =p;
	 if (n==0 || root==NULL) { 
		del = root; 
        root=del->next; 
        cur= root; 
		free(del); 
        cur=root; 
        return root; 
	 }
   while ((i<n) && (p->next!= NULL)) {
       prev=p; 
       p=p->next; 
       i++;
       } 
   if (i<n) return root;
   prev->next = p->next;
	 free(p); 
	 cur=root; return root;
}	 



