#include"general.h"

int main(){
int a[10]={4,9,5,100,26,-
18,13,77,1,34};
int i;
TreeType root;
for(i=0;i<10;i++)
InsertNode(a[i], &root);
InOrderPrint(root);
return 0;
}