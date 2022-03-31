#include"BST.h"

int main(){
    int a[10] = {4,9,5,100,26,-18,13,77,1,34};
    int i;
    TreeType root;
    for(i = 0 ;i < 10 ; i++) Insert_Node(a[i], &root);
    inOrderPrint(root);
    return 0;
}
