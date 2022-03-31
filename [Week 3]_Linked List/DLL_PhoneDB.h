#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>

int i;

typedef struct phoneinfo {
    char model[45];
    char memory[5];
    char size[6];
    char price[10];
} phoneinfo;

struct list_phoneinfo
{
    phoneinfo inf;
    struct list_phoneinfo *next; 
    struct list_phoneinfo *prev; 
};

typedef struct list_phoneinfo node_phoneinfo;

node_phoneinfo* make_New_Node(phoneinfo inf){
    node_phoneinfo* new = (node_phoneinfo*) malloc(sizeof(node_phoneinfo));
    new->inf = inf;
    new->next = NULL;
    new->prev = NULL;
    return new;
}

phoneinfo read_Node() {
    phoneinfo tmp;
    printf("Nhap Model: ");
    scanf("%s%*c",tmp.model);
    printf("Nhap Memory: ");
    scanf("%s%*c",tmp.memory);
    printf("Nhap Screen Size: ");
    scanf("%s%*c",tmp.size);
    printf("Nhap Gia: ");
    scanf("%s%*c",tmp.price);
    return tmp;
}

void MakeNull_List(node_phoneinfo **root, node_phoneinfo **tail, node_phoneinfo **cur) {
    (*root)= NULL;
    (*tail)= NULL; 
    (*cur)= NULL;
}

void insert_At_Head(phoneinfo inf, node_phoneinfo **root, node_phoneinfo **tail, node_phoneinfo **cur) {
    node_phoneinfo *new = make_New_Node(inf);
    if (*root == NULL) {
        *root = new;
        *tail = new;
        *cur = new;
        return;
    }
    new -> next = *root;
    (*root) -> prev = new;
    *root = new;
    *cur = *root;
}

void append(phoneinfo inf, node_phoneinfo **root, node_phoneinfo **tail, node_phoneinfo **cur) {
    node_phoneinfo *new = make_New_Node(inf);
    if (root == NULL) {
        *root = new;
        *tail = new;
        *cur = new;
        return;
    } else {
    (*tail) -> next =  new;
    new -> prev = *tail;
    *tail = new;
    *cur = *tail;
    }
}

void insert_After_Current_Position(phoneinfo inf, node_phoneinfo **root, node_phoneinfo **tail, node_phoneinfo **cur) {
    node_phoneinfo *new = make_New_Node(inf);
    if (*root == NULL) {
        *root = new;
        *tail = new;
        *cur = new;
        return;
    } else if (*cur == NULL) {
        printf("Current pointer is NULL!\n");
        return;
    } else {
        new -> next = (*cur) ->next;
        (*cur) -> next = new;
        if ((*cur) ->next ->next != NULL) {
            (*cur) ->next ->next ->prev = new;
        }
        new ->prev = (*cur);
        *cur = new;
    }
}

void insert_Before_Currrent_Position(phoneinfo inf,node_phoneinfo **root, node_phoneinfo **tail, node_phoneinfo **cur) {
    node_phoneinfo *new = make_New_Node(inf);
    if (*cur == NULL) {
        printf("Current pointer is NULL!\n");
        return;
    } else if (*root == NULL) {
        *root = new;
        *tail = new;
        *cur = new;
        return;
    } else {
        new -> next = (*cur);
        new -> prev = (*cur) -> prev;
        if (*cur == *root) {
            *root = new;
        } else {
        (*cur) -> prev ->next = new;
        }
        (*cur) ->prev = new;
        *cur = new;
    }
}

void insert_At_Position(phoneinfo inf, int n,node_phoneinfo **root, node_phoneinfo **tail, node_phoneinfo **cur) {
    *cur = *root;
    for (i = 0; i < n; i++) {
        (*cur) = (*cur) -> next;
    }
    if (*cur == *root) insert_At_Head(inf, root, tail, cur);
    else if (*cur == *tail) append(inf, root, tail, cur);
    else insert_After_Current_Position(inf, root, tail, cur);
}

/* void delete_List(node_phoneinfo *p) {
    if (root == NULL) printf("Empty List!\n");
    else {
        if (p == root) root = root -> next;
        else p -> prev -> next = p -> next;
        if (p->next != NULL) p -> next ->prev = p -> prev; 
        else tail = p -> prev; // if p is tail 
        free(p);
    }
} */

void display_Node(node_phoneinfo *ptr) {
    if(ptr == NULL) {
        printf("Loi con tro NULL!\n");
        return;
    }
    phoneinfo tmp = ptr -> inf;
    printf("%s  -  %s  -  %s  -  %s\n", tmp.model, tmp.memory, tmp.size, tmp.price, ptr -> next); 
}

void travesing_A_List(node_phoneinfo **root) {
    node_phoneinfo *ptr;
    for (ptr = *root; ptr != NULL; ptr = ptr -> next) {
        display_Node(ptr);
    }
}

void freeing_A_List(node_phoneinfo **root) {
    node_phoneinfo *to_free = *root;
    while(to_free != NULL) {
        (*root) = (*root) -> next;
        free(to_free);
        to_free = *root;
    }
}

void delete_First_Element(node_phoneinfo **root, node_phoneinfo **tail, node_phoneinfo **cur) {
    node_phoneinfo *del = *root;
    if (del == NULL) {
        printf("Empty Double Linked List!\n");
        return;
    }
    *root = (*root) -> next;
    free(del);
    *cur = *root;
}

void delete_Last_Element(node_phoneinfo **root, node_phoneinfo **tail, node_phoneinfo **cur) {
    node_phoneinfo *tmp, *del, *ptr;
    for (ptr = *root; ptr->next != NULL; ptr = ptr -> next) {
        continue;
    }
    *tail = ptr;
    if (*tail == NULL) {
        printf("Tail pointer is null!\n");
        return;
    }
    *cur = *tail;
    if (*root == *tail) delete_First_Element(root, tail, cur);
    else {
        tmp = (*tail) -> prev;
        del = *tail;
        tmp -> next = NULL;
        *tail = tmp;
        free(del);
        *cur = *tail;
    }
}

void delete_Current_Element(node_phoneinfo **root, node_phoneinfo **tail, node_phoneinfo **cur){
    if (*cur == NULL) {
        printf("Current pointer is null!\n");
        return;
    }
    if (*cur == *root) delete_First_Element(root, tail, cur);
    else {
        node_phoneinfo *tmp = (*cur) -> next;
        (*cur)->prev->next = (*cur)->next;
        if ((*cur)->next != NULL) (*cur)->next->prev = (*cur)->prev;
        free(*cur);
        *cur = tmp;
        if (*cur == NULL) *cur = *root;
    }
}

void delete_At_Element(int n, node_phoneinfo **root, node_phoneinfo **tail, node_phoneinfo **cur){
    *cur = *root;
    for (i = 0; i < n; i++) {
        (*cur) = (*cur) -> next;
    }
    if (*cur == *root) delete_First_Element(root, tail, cur);
    else if (*cur == *tail) delete_Last_Element(root, tail, cur);
    else delete_Current_Element(root, tail, cur);
}

void search_And_Update(node_phoneinfo **root, node_phoneinfo **cur, node_phoneinfo **tail) {
    char name[100];
    int i = 0, flag = 0;
    printf("Search by Model: ");
    scanf("%s%*c", name);
    for (*cur = *root; *cur != NULL; *cur = (*cur)->next)
    {
        i++;
        if (strcmp(((*cur)->inf).model, name) == 0) {
            printf("Cap nhat phan tu thu %d", i+1);
            printf("Model: ");
            scanf("%s%*c", ((*cur)->inf).model);
            printf("Memory: ");
            scanf("%s%*c", (((*cur)->inf).memory));
            printf("Screen size: ");
            scanf("%s%*c", (((*cur)->inf).size));
            printf("Price: ");
            scanf("%s%*c", (((*cur)->inf).price));
            flag++;
        }
    }
    if (flag == 0) printf("Cannot find model <%s>\n\n", name);
}

node_phoneinfo *list_Reverse(node_phoneinfo **root, node_phoneinfo **tail, node_phoneinfo **cur) {
    node_phoneinfo *tmp = NULL, *ptr;
    if (*root == NULL) {
        printf("Empty Double Linked List!\n");
        return;
    }

    //for (ptr = *root; ptr->next != NULL; ptr = ptr -> next) {
    //    continue;
    //}
    //*tail = ptr;

    *tail = *root;
    for (*cur = *root; *cur != NULL;*cur = (*cur)->prev) {
        tmp = (*cur)->next;
        (*cur)->next = (*cur)->prev;
        (*cur)->prev = tmp;
    }

    for (*cur = *tail; *cur != NULL; *cur = (*cur)->prev) {
        tmp = *cur;
    }
  
    *root = tmp;
    return *root;
}   

void save_to_Text(node_phoneinfo *root, char *filename) {
    FILE *fptr = fopen(filename, "w+");
    if (fptr == NULL) {
        printf("Cannot open %s\n", filename);
        return;
    }
    node_phoneinfo *tmp;
    for (tmp = root; tmp != NULL; tmp = tmp->next) {
        fprintf(fptr, "%s %s %s %s\n", (tmp->inf).model, (tmp->inf).memory, (tmp->inf).size, (tmp->inf).price);
        printf("%s  -  %s  -  %s  -  %s\n", (tmp->inf).model, (tmp->inf).memory, (tmp->inf).size, (tmp->inf).price);
    }
    printf("File saved successfully!\n");
    fclose(fptr);
}