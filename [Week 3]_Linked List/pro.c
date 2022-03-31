#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"lib.h"

int main()
{
    phoneaddress addr = read_Node();
    root = make_New_Node(addr);
    display_Note(root);
    
}