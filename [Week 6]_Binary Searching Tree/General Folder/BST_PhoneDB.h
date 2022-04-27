#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

typedef struct phoneinfo {
    char model[45];
    char memory[5];
    char size[6];
    char price[10];
} phoneinfo;

typedef phoneinfo KeyType;
typedef struct Node{
    KeyType key;
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
NodeType *create_Node(KeyType data) {
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
TreeType Search(char* name, TreeType Tree) {
    if (Tree == NULL) return NULL;
    else if (strcmp((Tree->key).model, name) == 0) return Tree;
    else if (strcmp((Tree->key).model, name) < 0) return Search(name, Tree->right);
    else return Search(name, Tree->left);
}

//Hàm insert 1 node bất kỳ vào cây
//Lưu ý: Không tồn tại 2 nodes có key giống nhau trong cây tìm kiếm nhị phân
void Insert_Node(KeyType data, TreeType *Tree) {
    if (*Tree == NULL) {
       *Tree = create_Node(data);
    } else if (strcmp(((*Tree)->key).model,data.model) < 0) Insert_Node(data, &(*Tree)->right);
    else Insert_Node(data, &(*Tree)->left);
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


//Xóa node Trái nhất
KeyType Delete_Min(TreeType *Tree) {
    KeyType k;
    if ((*Tree)->left == NULL) {
        k = (*Tree)->key;
        (*Tree) = (*Tree)->right;
        return k;
    }
    else return Delete_Min(&(*Tree)->left);
}

//Tìm node Trái nhất
TreeType min_Node(TreeType Tree) {
    TreeType cur = Tree;

    while (cur && cur->left != NULL) cur = cur->left;

    return cur;
}

//Xóa một node trong cây
void Delete_Node (KeyType k, TreeType *Tree){
    if(*Tree != NULL){
        if (strcmp(((*Tree)->key).model, k.model) > 0) Delete_Node(k, &(*Tree)->left);
        else if (strcmp(((*Tree)->key).model, k.model) < 0) Delete_Node(k, &(*Tree)->right);
        else if ((*Tree)->left == NULL && (*Tree)->right == NULL) *Tree = NULL;
        else if ((*Tree)->left == NULL) (*Tree) = (*Tree)->right;
        else if ((*Tree)->right == NULL) (*Tree) = (*Tree)->left;
            else (*Tree)->key = Delete_Min(&(*Tree)->right);
        }
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
TreeType Add_Left(TreeType *Tree, KeyType data) {
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
TreeType Add_Right(TreeType *Tree, KeyType data) {
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
TreeType create_Node_From_2_Sub(KeyType data, TreeType left, TreeType right) {
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
        printf("%s  -  %s  -  %s  -  %s\n", Tree->key.model, Tree->key.memory, Tree->key.size, Tree->key.price); 
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
        printf("%s  -  %s  -  %s  -  %s\n", Tree->key.model, Tree->key.memory, Tree->key.size, Tree->key.price); 
    }
}

//Inorder Traversal
//Duyệt cây theo thứ tự giữa LEFT -> NODE -> RIGHT  _  << LNR >>  _
void in_Order_Print(TreeType Tree) {
    if (Tree != NULL) {
        in_Order_Print(Tree->left);
        printf("%s  -  %s  -  %s  -  %s\n", Tree->key.model, Tree->key.memory, Tree->key.size, Tree->key.price);
        in_Order_Print(Tree->right);
    }
}

//RNL Traversal
//Duyệt cây theo thứ tự giữa RIGHT -> NODE -> LEFT  _  << RNL >>  _
void RNL_Order_Print(TreeType Tree) {
    if (Tree != NULL) {
        RNL_Order_Print(Tree->right);
        printf("%s  -  %s  -  %s  -  %s\n", Tree->key.model, Tree->key.memory, Tree->key.size, Tree->key.price);
        RNL_Order_Print(Tree->left);
    }
}

int max(int a, int b) {
    return a >= b? a : b;
}

int Height(TreeType Tree) {
    if (Tree == NULL) return 0;
    return 1 + max(Height(Tree->left),Height(Tree->right));
}

int num_of_Leaf(TreeType Tree) {
    if (Tree == NULL) return 0;
    if (isLeaf(Tree)) {
        return 1;
    }
    return num_of_Leaf(Tree->left) + num_of_Leaf(Tree->right);
}

//Giải phóng bộ nhớ cấp phát động cho cây nhị phân tìm kiếm BST
void free_Tree(TreeType *Tree) {
    if((*Tree)->left == NULL && (*Tree)->right == NULL){
        free(*Tree);
    }
    free_Tree(&(*Tree)->left);
    free_Tree(&(*Tree)->right);
}

//Postorder Save to Text
//Ghi dữ liệu cây vào file theo thứ tự sau LEFT -> RIGHT -> NODE  _  << LRN >>  _
void post_Order_Save(TreeType Tree) {
    FILE *fptr = fopen("PhoneDB_out.txt", "a");
    if (fptr == NULL) {
        printf("Cannot open %s\n", "PhoneDB_out.txt");
        return;
    }
    
    if (Tree != NULL) {
        post_Order_Save(Tree->left);
        post_Order_Save(Tree->right); 
        fprintf(fptr, "%s  %s  %s  %s\n", Tree->key.model, Tree->key.memory, Tree->key.size, Tree->key.price);
    }
        

    fclose(fptr);
}

//Inorder Save to Text
//Ghi dữ liệu cây vào file theo thứ tự giữa LEFT -> NODE -> RIGHT  _  << LNR >>  _
void in_Order_Save(TreeType Tree) {
    FILE *fptr = fopen("PhoneDB_out.txt", "a");
    if (fptr == NULL) {
        printf("Cannot open %s\n", "PhoneDB_out.txt");
        return;
    }
    
    if (Tree != NULL) {
        in_Order_Save(Tree->left);
        fprintf(fptr, "%s  %s  %s  %s\n", Tree->key.model, Tree->key.memory, Tree->key.size, Tree->key.price);
        in_Order_Save(Tree->right); 
    }

    fclose(fptr);
}

//Preorder Save to Text
//Ghi dữ liệu cây vào file theo thứ tự trước NODE -> LEFT -> RIGHT  _  << NLR >>  _
void pre_Order_Save(TreeType Tree) {
    FILE *fptr = fopen("PhoneDB_out.txt", "a");
    if (fptr == NULL) {
        printf("Cannot open %s\n", "PhoneDB_out.txt");
        return;
    }
    
    if (Tree != NULL) {
        fprintf(fptr, "%s  %s  %s  %s\n", Tree->key.model, Tree->key.memory, Tree->key.size, Tree->key.price);
        pre_Order_Save(Tree->left);
        pre_Order_Save(Tree->right); 
    }

    fclose(fptr);
}

