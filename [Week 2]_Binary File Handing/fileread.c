#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 500

enum {SUCCESS, FAIL};

typedef struct phonebook {
      char name[20];
      char tel[11];
      char email[25];
} phoneaddress;

int main(int argc, char *argv[])
{
      char c;
      int irc;
      int i = 0;
      int count = 0;
      int flag = SUCCESS;
      FILE *fptr;

    //Check the validity of argc
    if (argc != 2) {
        printf("Syntax error!\nMust be: .\\fileread <file>\n");
        flag = FAIL;
        return flag;
    }

    //Open phonebook.dat
    if ((fptr = fopen(argv[1],"rb")) == NULL){
		printf("Can not open %s.\n", argv[1]);
		flag = FAIL;
    }

    //Read all data from the file once then allocate memory for values readed from that file
    phoneaddress *tmp_add = (phoneaddress* ) malloc (sizeof(phoneaddress));
	  while (irc = fread(tmp_add, sizeof(phoneaddress), 1, fptr) != 0) {
        count++;
    }

    free(tmp_add);
    rewind(fptr);
    
    phoneaddress *add = (phoneaddress *) malloc (count * sizeof(phoneaddress));
    while (irc = fread(add, sizeof(phoneaddress), 1, fptr) != 0) {
        printf("%20s-   ",add[i].name);
        printf("%11s-   ",add[i].tel);
        printf("%25s\n",add[i].email);
    }

    printf(" The file <%s> has %d addresses!\n", argv[1], count);
    free(add);
    fclose(fptr);   

    return flag;
}