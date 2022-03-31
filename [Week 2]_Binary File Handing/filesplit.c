#include<stdio.h>
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
      int count = 0;
      FILE *fptr, *fptr1, *fptr2;

      int flag = SUCCESS;

    n = atoi(argv[2]);
    //Check the validity of argc
    if (argc != 5) {
        printf("Syntax error!\nMust be: .\\filesplit <file1> offset <file2> <file3>\n");
        flag = FAIL;
        return flag;
    }

    //Open phonebook.dat
    if ((fptr = fopen(argv[1],"rb")) == NULL){
		printf("Can not open %s.\n", argv[1]);
		flag = FAIL;
    } else if ((fptr1 = fopen(argv[3],"wb")) == NULL){
		printf("Can not open %s.\n", argv[3]);
		flag = FAIL;
    } else if ((fptr2 = fopen(argv[4],"wb")) == NULL){
		printf("Can not open %s.\n", argv[4]);
		flag = FAIL;
    }

    //Memory Allocation for Phoneaddress Variable!
    phoneaddress *add = (phoneaddress *) malloc(n * sizeof(phoneaddress));
    phoneaddress *tmp_add = (phoneaddress *) malloc(sizeof(phoneaddress));

    while(fread(tmp_add, sizeof(phoneaddress), 1, fptr) != 0){
    count++;
    }

    free(tmp_add);
    flag = SUCCESS;
    rewind(fptr);

    //Read data from file1 then write data to file 2!
    fread(add, sizeof(phoneaddress), n, fptr); 
    fwrite(add, sizeof(phoneaddress), n, fptr1);
    printf(" %d addresses have been written to file1 <%s>\n", n, argv[3]);
    fclose(fptr1);

    int rest = count - n;

    //Read the rest data from file 1 again to write them down to file 3! 
    add = (phoneaddress *) realloc (add, rest * sizeof(phoneaddress));
    fread(add, sizeof(phoneaddress), rest, fptr);
    fwrite(add, sizeof(phoneaddress), rest, fptr2); 
    printf(" %d addresses have been written to file2 <%s>\n", rest, argv[4]);
    free(add);
    fclose(fptr2);
    fclose(fptr);   

    return flag;
}