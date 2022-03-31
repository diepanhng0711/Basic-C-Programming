#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#define MAX 20 

enum {SUCCESS, FAIL};

//Phonebook Structure
typedef struct phonebook
{
    char name[20];
    char tel[11];
    char email[25];
} phoneaddress;

typedef struct Node {
    phoneaddress key;
    struct Node *left, *right;
} NodeType;

typedef NodeType *TreeType;

void Insert_Node(phoneaddress x, TreeType *Tree) {
    if (*Tree == NULL) {
        *Tree = (NodeType *) malloc(sizeof(NodeType));
        (*Tree)->key = x;
        (*Tree)->left = NULL;
        (*Tree)->right = NULL;
    }
    else if (strcmp(((*Tree)->key).email, x.email) < 0) Insert_Node(x, Tree->);
    else if (strcmp(((*Tree)->key).email, x.email) > 0) Insert_Node(x, (*Tree)->right);
}

void inOrderPrint(TreeType Tree) {
    inOrderPrint(Tree->left);
    printf("%d\n",Tree->key);
    inOrderPrint(Tree->right);
}

void DeleteNode(phoneaddress x,TreeType *root){
    if (*root!=NULL) {
        if (x < (*root)->key) DeleteNode(x, &(*root)->left);
        else if (x > (*root)->key) DeleteNode(x, &(*root)->right);
        else if ((*root)->left == NULL && (*root)->right == NULL)
            *root=NULL;
        else if ((*root)->left == NULL)
            *root = (*root)->right;
        else if ((*root)->right==NULL)
            *root = (*root)->left;
        else (*root)->key = DeleteMin(&(*root)->right);
    }
}

phoneaddress DeleteMin(TreeType *root) {
    phoneaddress k;
    if ((*root)->left == NULL){
        k=(*root)->key;
        (*root) = (*root)->right;
        return k;
    }
    else return DeleteMin(&(*root)->left);
}
