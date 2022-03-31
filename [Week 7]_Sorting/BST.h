#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int key;
    struct Node *left, *right;
} NodeType;

typedef struct Node *TreeType;

//tạo cây NULL
void make_NULL_Tree(TreeType *Tree) {
    (*Tree) = NULL;
}

//Kiểm tra cây NULL?
int isEmpty_Tree(TreeType Tree) {
    return (Tree == NULL);
}

//Tạo node mới
NodeType *create_Node(int data) {
    NodeType *New = (NodeType *) malloc(sizeof(NodeType));
    if (New == NULL) {
        printf("Dynamic memory allocation failed!\n");
        return;
    } else {
        New->key = data;
        New->left = NULL;
        New->right = NULL;
    }

    return New;
}

//Hàm search
TreeType Search(int data, TreeType Tree) {
    if (Tree == NULL) return NULL;
    else if (Tree->key == data) return Tree;
    else if (Tree->key < data) return Search(data, Tree->left);
    else return Search(data, Tree->right);
}

//Hàm insert 1 node bất kỳ vào cây
//Lưu ý: Không tồn tại 2 nodes có key giống nhau trong cây tìm kiếm nhị phân
void Insert_Node(int data, TreeType *Tree) {
    if (*Tree == NULL) {
       *Tree = create_Node(data);
    } else if (data > (*Tree)->key) Insert_Node(data, &(*Tree)->right);
    else Insert_Node(data, &(*Tree)->left);
}

//Con trái
TreeType Left_Child(TreeType Tree) {
    if(Tree != NULL) return Tree->left;
    else return NULL;
}

//Con phải
TreeType Right_Child(TreeType Tree) {
    if(Tree != NULL) return Tree->right;
    else return NULL;
}

//Có phải Lá không?
int isLeaf(TreeType Tree) {
    if(Tree != NULL) {
        return ((Left_Child(Tree) == NULL) && (Right_Child(Tree) == NULL));
    } else return -1;
}

//Thêm Node trái nhất
TreeType Add_Left(TreeType *Tree, int data) {
    NodeType *New = create_Node(data);
    if (New == NULL) {
        printf("Dynamic memory allocation failed!\n");
        return;
    }
    if (*Tree == NULL) *Tree = New;
    else {
        NodeType *left_node = *Tree;
        while (left_node->left != NULL) left_node = left_node->left;
        left_node->left = New;
    }
    return New;
}

//Thêm Node phải nhất
TreeType Add_Right(TreeType *Tree, int data) {
    NodeType *New = create_Node(data);
    if (New == NULL) {
        printf("Dynamic memory allocation failed!\n");
        return;
    }
    if (*Tree == NULL) *Tree = New;
    else {
        NodeType *right_node = *Tree;
        while (right_node->left != NULL) right_node = right_node->left;
        right_node->left = New;
    }
    return New;
}

//Số node của cây
int num_of_Nodes(TreeType Tree) {
    if (isEmpty_Tree(Tree)) return 0;
    return 1 + num_of_Nodes(Left_Child(Tree)) + num_of_Nodes(Right_Child(Tree));
}

//Tạo 1 cây từ 2 cây con
TreeType create_Node_From_2_Sub(int data, TreeType left, TreeType right) {
    TreeType New = (NodeType *) malloc (sizeof(NodeType));
    New->key = data;
    New->left = left;
    New->right = right;
    return New;
}

//Preorder Traversal
//Duyệt cây theo thứ tự trước NODE -> LEFT -> RIGHT  _  << NLR >>  _
void pre_Order_Print(TreeType Tree) {
    if (Tree != NULL) {
        printf("%4d  ", Tree->key);
        pre_Order_Print(Tree->left);
        pre_Order_Print(Tree->right);
    }
}

//Postorder Traversal
//Duyệt cây theo thứ tự sau LEFT -> RIGHT -> NODE  _  << LRN >>  _
void post_Order_Print(TreeType Tree) {
    if (Tree != NULL) {
        post_Order_Print(Tree->left);
        post_Order_Print(Tree->right);
        printf("%4d  ", Tree->key);
    }
}

//Inorder Traversal
//Duyệt cây theo thứ tự giữa LEFT -> NODE -> RIGHT  _  << LNR >>  _
void in_Order_Print(TreeType Tree) {
    if (Tree != NULL) {
        in_Order_Print(Tree->left);
        printf("%4d  ", Tree->key);
        in_Order_Print(Tree->right);
    }
}