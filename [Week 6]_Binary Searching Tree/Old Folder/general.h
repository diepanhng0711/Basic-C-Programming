#include<stdio.h>
#include<stdlib.h>

typedef int KeyType;

typedef struct Node {
    KeyType key;
    struct Node *left, *right;
}   NodeType;   

typedef NodeType *TreeType;

TreeType Search(KeyType x, TreeType root) {
    if (root == NULL) return NULL;  //không tìm thấy
    else if (root->key == x) return root;   //tìm thấy x
    else if (root->key < x) return Search(x, root -> right);
    else Search(x, root->left);
}

TreeType InsertNode(KeyType x, TreeType root) {
    if (root == NULL) {
        //Tạo node mới cho phần tử x
        root = (NodeType *) malloc (sizeof(NodeType));
        (root)->key = x;
        (root)->left = NULL;
        (root)->right = NULL;
        return root;
    } else if (x < (root)->key) return InsertNode(x, (root)->left); //thêm vào bên trái
    else if (x > (root)->key) return InsertNode(x, (root)->right);  //thêm vào bên phải
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

void MakeNullTree(TreeType *T){
  (*T) = NULL;
}

int EmptyTree(TreeType T){
  return T == NULL;
}

TreeType LeftChild(TreeType n){
  if(n != NULL) return n->left;
  else return NULL;
}

TreeType RightChild(TreeType n){
  if(n != NULL) return n->right;
  else return NULL;
}

NodeType *Create_Node(KeyType NewData){
  NodeType *N = NULL;
  N = (NodeType *) malloc(sizeof(NodeType));

  if(N != NULL){
    N->left = NULL;
    N->right = NULL;
    N->key = NewData;
  }
  return N;
}

int IsLeaf(TreeType n){
  if(n != NULL)
    return (LeftChild(n) == NULL) && (RightChild(n) == NULL);
  else return -1;
}

int nb_nodes(TreeType T){
  if(EmptyTree(T)) return 0;
  else return 1+nb_nodes(LeftChild(T))+nb_nodes(RightChild(T));
}

TreeType createfrom2(KeyType v, TreeType l, TreeType r){
  TreeType N;
  N = (NodeType *) malloc(sizeof(NodeType));
  N->key=v;
  N->left=l;
  N->right=r;
  return N;
}

TreeType Add_Left(TreeType *Tree, KeyType NewData){
  NodeType *NewNode = Create_Node(NewData);
  if(NewNode == NULL) return (NewNode);
  if(*Tree == NULL)
    *Tree = NewNode;
  else{
    NodeType *Lnode = *Tree;
    while(Lnode->left != NULL)
      Lnode = Lnode->left;
    Lnode->left = NewNode;
  }

  return (NewNode);
}

TreeType Add_Right(TreeType *Tree, KeyType NewData){
  NodeType *NewNode = Create_Node(NewData);
    if(*Tree == NULL)
    *Tree = NewNode;
  else{
    NodeType *Rnode = *Tree;
    while(Rnode->right != NULL)
      Rnode = Rnode->right;
    Rnode->right = NewNode;
  }

  return (NewNode);
}

void freetree(TreeType tree){
    if (tree!=NULL) {
        freetree(tree->left);
        freetree(tree->right);
        free((void *) tree);
    }
}