#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct phoneaddress_t{
    char name[20];
    char tel[15];
    char email[25];
} phoneaddress;

struct AddressList{
    phoneaddress address;
    struct AddressList *next;
};

typedef struct AddressList node_Address;

node_Address *root, *cur, *prev;

node_Address *make_New_Node(phoneaddress address){
    node_Address *new = (node_Address*) malloc(sizeof(node_Address));
    new -> address = address;
    new -> next = NULL;
    return new;
}

phoneaddress read_Node(){
    phoneaddress addr;
    printf("Enter the name: ");
    fgets(addr.name, 20, stdin);
    printf("Enter the telephone: ");
    fgets(addr.tel, 15, stdin);
    printf("Enter the email: ");
    fgets(addr.email, 25, stdin);
    return addr;
}

void display_Note(node_Address *ptr){
    if (ptr == NULL) {
        printf("The pointer now is NULL\n");
        return;
    }
    phoneaddress info = ptr ->address;
    printf("%s%s%s%p\n", info.name, info.tel, info.email);
}

void insert_At_Head(phoneaddress addr){
    node_Address *new = make_New_Node(addr);
    new -> next = root;
    root = new;
    cur = root;
}

void insert_After_Current_Position(phoneaddress addr){
    node_Address *new = make_New_Node(addr);
    if (root == NULL) {
        root = new;
        cur = root;
    } else {
        new->next = cur->next;
        cur->next = new;
        // prev == cur;
        cur = cur->next;
    }
}

void insert_Before_Current_Position(phoneaddress addr){
    
    node_Address *new = make_New_Node(addr);
    if (root == NULL) {
        root = new;
        cur = root;
        prev = NULL;
    } else {
        node_Address *tmp = root;
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
    node_Address* del = root;
    del = del->next;
    free(del);
    cur = root;
}

void delete_Current_Element(){
    if (cur ==  root) delete_First_Element();
    else {
        node_Address *tmp = root;
        while (tmp->next != cur && cur != NULL){
            tmp = tmp->next;
            prev = tmp;
        }
        prev->next = cur->next;
        free(cur);
        cur = prev->next;
    }

}

node_Address *list_Reverse(node_Address *root){
    cur = prev = NULL;
    while (root != NULL) {
        cur = root;
        root = root->next;
        cur->next = prev;
        prev = cur;
    }
    return prev;
}

int main()
{
    int i;
    phoneaddress addr = read_Node();
    root = make_New_Node(addr);
    display_Note(root);

    for (i = 0; i < 5; i++) {
        addr = read_Node();
        insert_At_Head(addr);
        display_Note(root);
    }

    
}