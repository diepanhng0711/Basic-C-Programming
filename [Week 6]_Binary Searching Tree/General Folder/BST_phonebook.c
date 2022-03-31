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


int main(int argc, char *argv[])
{
    FILE *fptr;
    phoneaddress add[MAX];
    int i, n, irc;
    int flag = SUCCESS;

    if (argc != 2) {
        printf("Syntax error!\n");
        flag = FAIL;
    }

    //Enter contacts
    printf("How many contacts do you want to enter?: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("--No.%d student:\n", i+1);
        printf("Name:   "); 
        scanf("%s%*c",add[i].name);
        printf("Tel:    "); 
        scanf("%s%*c",add[i].tel);
        printf("Email:  "); 
        scanf("%s%*c",add[i].email);
    }

    //Check the validity of argv[1]
    if ((fptr = fopen(argv[1],"w+b")) == NULL) {
        printf("Cannot open %s!\n",argv[1]);
        flag = FAIL;
    }

    irc = fwrite(add, sizeof(phoneaddress), n, fptr);
    printf("fwrite return code = %d",irc);
    fclose(fptr);

    //Read data from argv[1] again
    if ((fptr = fopen(argv[1],"rb")) == NULL) {
        printf("Cannot open %s!\n",argv[1]);
        flag = FAIL;
    }
    
    irc = fread(add, sizeof(phoneaddress), n, fptr);
    printf("fread return code = %d", irc);

    for (i = 0; i < n; i++) {
        printf("%s-",add[i].name);
        printf("%s-",add[i].tel);
        printf("%s\n",add[i].email);
    }

    fclose(fptr);
    return flag;
}