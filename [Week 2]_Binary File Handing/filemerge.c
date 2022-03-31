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
      int i,n,irc;
      int count_irc = 0;
      int flag = SUCCESS;
      FILE *fptr, *fptr1, *fptr2;
      phoneaddress add[MAX];

    //Check the validity of argc
    if (argc != 4) {
        printf("Syntax error!\nMust be: .\\filemerge <file1> <file2> <file3>\n");
        flag = FAIL;
        return flag;
    }

    //Open phonebook.dat
    if ((fptr = fopen(argv[1],"rb")) == NULL){
		printf("Can not open %s.\n", argv[1]);
		flag = FAIL;
    } else if ((fptr1 = fopen(argv[2],"rb")) == NULL){
		printf("Can not open %s.\n", argv[2]);
		flag = FAIL;
    } else if ((fptr2 = fopen(argv[3],"w+b")) == NULL){
		printf("Can not open %s.\n", argv[3]);
		flag = FAIL;
    }

    //Read data from file1 the write them down to file3
	  while (irc = fread(add, sizeof(phoneaddress), 1, fptr) != 0) {
      fwrite(add, sizeof(phoneaddress), 1, fptr2);
    }
    fclose(fptr2);
    fclose(fptr);


    if ((fptr2 = fopen(argv[3],"ab")) == NULL){
		printf("Can not open %s.\n", argv[3]);
		flag = FAIL;
    }

    //Read data from file2 the write them down to file3
    while (irc = fread(add, sizeof(phoneaddress), 1, fptr1) != 0) {
      fwrite(add, sizeof(phoneaddress), 1, fptr2);
    }
    free(add);
    fclose(fptr2);
    fclose(fptr1);
    

    return flag;
}