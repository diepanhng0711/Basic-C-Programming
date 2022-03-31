#include<stdio.h>
#include<stdlib.h>

typedef int KeyType;

typedef struct Node {
    int key;
    struct Node  *left, *right;
} NodeType;

typedef NodeType *TreeType;

void Insert_Node(int x, TreeType *Tree) {
    if (*Tree == NULL) {
        *Tree = (NodeType *) malloc(sizeof(NodeType));
        (*Tree)->key = x;
        (*Tree)->left = NULL;
        (*Tree)->right = NULL;
    }
    else if (x < (*Tree)->key) Insert_Node(x, &(*Tree)->left);
    else if (x > (*Tree)->key) Insert_Node(x, &(*Tree)->right);
}

void inOrderPrint(TreeType Tree) {
    inOrderPrint(Tree->left);
    printf("%d\n",Tree->key);
    inOrderPrint(Tree->right);
}

void DeleteNode(KeyType x,TreeType *root){
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

KeyType DeleteMin(TreeType *root) {
    KeyType k;
    if ((*root)->left == NULL){
        k=(*root)->key;
        (*root) = (*root)->right;
        return k;
    }
    else return DeleteMin(&(*root)->left);
}
