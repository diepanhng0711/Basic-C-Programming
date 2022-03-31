#include"BST.h"

int main()
{
    TreeType Tree;
    int x[100];
    int i = 0;
    while(i < 6) {
        printf("Nhap phan tu bat ky: ");
        scanf("%d", &x);
        Insert_Node(x[i], &Tree);
        i++;
    }

    inOrderPrint(Tree);

    /*printf("The height of the tree: %d \n", height(Tree));
    printf("The number of leafs in the tree: %d \n", numLeaf(Tree));
    printf("The number of interal nodes: %d \n", numInternalNode(Tree));
    printf("The number of right children: %d \n", countRightChild(Tree));*/
}