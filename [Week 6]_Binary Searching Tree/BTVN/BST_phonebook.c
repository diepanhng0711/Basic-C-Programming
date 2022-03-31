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

#include"BST.h"

int main()
{

}