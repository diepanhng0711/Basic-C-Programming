#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>

typedef struct phoneinfo {
    char model[45];
    char memory[5];
    char size[6];
    char price[10];
} phoneinfo;

typedef struct node_phoneinfo {
    phoneinfo p_inf;
    node_phoneinfo *next;
    node_phoneinfo *prev;
} node_phoneinfo;

typedef node_phoneinfo *doublelist;

doublelist head, tail, cur;

void make_NullList(doublelist *root, doublelist *cur, doublelist *tail){
    (*root) = NULL;
    (*tail) = NULL;
    (*cur) = NULL;
}

node_phoneinfo* make_New_Node(phoneinfo p_inf){
	node_phoneinfo* new = (node_phoneinfo*) malloc(sizeof(node_phoneinfo));
	new->p_inf=p_inf;
	new->next =NULL;
	new->prev =NULL;
	return new;
}

void insert_After_Current(phoneinfo p_inf, doublelist *root, doublelist *cur, doublelist *tail) {
    node_phoneinfo *new = make_New_Node;
    if (root == NULL) {
        *root = new;
        *tail = new;
        *cur = *root;
    } else {
        new -> next = (*cur) -> next;
        new->next=(*cur)->next;
	    if ((*cur)->next!=NULL)(*cur)->next->prev=new; 
        else *tail = new;
        (*cur)->next = new;
        new->prev=*cur;
 		*cur = new;
    if (new->next==NULL) *tail = new;
    }
}

/*void insertBeforeCurrent(phoneinfo p_inf, doublelist *root, doublelist *cur, doublelist *tail) {

	 node_phoneinfo* new = makeNewNode(p_inf);
    if (root == NULL) {
		root = new;
		cur = root;
		prev = NULL;
	} else {
   	
		new->next=cur;
    	if (cur==root) {
			root = new;
		}
		else prev->next = new;
		cur = new;
	}
}*/
