#include"BST.h"

int main()
{
    int a[10]={4,9,5,100,26,-18,13,77,1,34};
    int i;
    TreeType root;
    make_NULL_Tree(&root);
    for(i=0;i<10;i++) Insert_Node(a[i], &root);
    in_Order_Print(root);
    printf("\n");
    pre_Order_Print(root);
    printf("\n");
    post_Order_Print(root);
    printf("\n");
    printf("The height of the tree = %d", Height(root));
    printf("\n");
    printf("The number of nodes of the tree = %d", num_of_Nodes(root));
    printf("\n");
    printf("The number of leaf of the tree = %d", num_of_Leaf(root));
    printf("\n");
    return 0;
}