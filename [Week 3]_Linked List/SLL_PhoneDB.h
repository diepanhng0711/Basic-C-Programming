#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include<math.h>
#include<stdbool.h>
#define MAX 500

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
};

typedef struct list_phoneinfo node_phoneinfo;

node_phoneinfo *root, *cur, *prev;

node_phoneinfo *make_New_Node(phoneinfo inf) {
    node_phoneinfo *new = (node_phoneinfo *) malloc (sizeof(node_phoneinfo));
    new -> inf = inf;
    new -> next = NULL;
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

void display_Node(node_phoneinfo *ptr) {
    if(ptr == NULL) {
        printf("Loi con tro NULL!\n");
        return;
    }
    phoneinfo tmp = ptr -> inf;
    printf("%s  -  %s  -  %s  -  %s\n", tmp.model, tmp.memory, tmp.size, tmp.price, ptr -> next); 
}

void insert_At_Head(phoneinfo inf) {
    node_phoneinfo *new = make_New_Node(inf);
    new -> next = root;
    root = new;
    cur = root;
}

void insert_After_Current_Position(phoneinfo inf) {
    node_phoneinfo *new = make_New_Node(inf);
    if (cur == NULL) {
        if (root == NULL) {
        //Nếu danh sách rỗng
        root = new;
        cur = root;
        } else {
        //Không tồn tại cur
        printf("Khong tim thay node hien tai!\n");
        return;
        }
    } else {
        new -> next = cur -> next;
        cur -> next = new;
        cur = cur -> next;
    }
}

void insert_Before_Current_Position(phoneinfo inf) {
    node_phoneinfo *new = make_New_Node(inf);
    if (root == NULL) {
        //Nếu danh sách rỗng
        root = new;
        cur = root;
        prev = NULL;
    } else {
        new -> next = cur;
        if (cur == root) {
            root = new;
        } else {
        //Tìm con trỏ prev
        node_phoneinfo *tmp = root;
        while (tmp != NULL && tmp -> next != cur && cur != NULL)  tmp = tmp -> next;
        prev = tmp;
        prev -> next = new;
        }
        cur = new;
    }
}

void travesing_A_List() {
    node_phoneinfo *ptr;
    for (ptr = root; ptr != NULL; ptr = ptr -> next) {
        display_Node(ptr);
    }
    cur = root;
}

void freeing_A_List() {
    node_phoneinfo *to_free = root;
    while(to_free != NULL) {
        root = root -> next;
        free(to_free);
        to_free = root;
    }
}

void delete_First_Element() {
    node_phoneinfo *del = root;
    if (del == NULL) return;
    root = root -> next;
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

node_phoneinfo *list_Reverse(node_phoneinfo *root) {
    node_phoneinfo *tmp_cur, *tmp_prev, *tmp_root;
    tmp_cur = tmp_prev = NULL;
    while (root != NULL) {
        tmp_cur = root;
        root = root->next;
        if (tmp_prev == NULL) tmp_cur->next = NULL;
        else tmp_cur->next = tmp_prev;
        tmp_prev = tmp_cur;
    }
    return tmp_prev;
}

void insert_At_Position(node_phoneinfo *root ,phoneinfo inf, int n) {
    cur = root;
    for (i = 0; i < n; i++) {
        prev = cur;
        cur = cur->next;
    }
    insert_After_Current_Position(inf);
}

void delete_At_Element(int n){
    cur = root;
    for (i = 0; i < n; i++) {
        prev = cur;
        cur = cur->next;
    }
    delete_Current_Element();
}

node_phoneinfo *spilt(node_phoneinfo *r, int n1, int n2)
{
    node_phoneinfo *root1 = NULL;
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
    cur = root;
    return root1;
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

void save_to_Text_2(node_phoneinfo *root, int n, char *filename) {
    int i;
    FILE *fptr = fopen(filename, "w+");
    if (fptr == NULL) {
        printf("Cannot open %s\n", filename);
        return;
    }
    node_phoneinfo *tmp = root;
    for (i = 0; i < n; i++) {
        fprintf(fptr, "%s %s %s %s\n", (tmp->inf).model, (tmp->inf).memory, (tmp->inf).size, (tmp->inf).price);
        printf("%s  -  %s  -  %s  -  %s\n", (tmp->inf).model, (tmp->inf).memory, (tmp->inf).size, (tmp->inf).price);
        tmp = tmp->next;
    }
    printf("File saved successfully!\n");
    fclose(fptr);
}