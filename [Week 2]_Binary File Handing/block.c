#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
enum {SUCCESS, FAIL};
#define MAX 80

void block_Read_Write(FILE *fin, FILE *fout){
    int n;
    char line[MAX +1];
    while (!feof(fin)) {
        n = fread(line, sizeof(char), MAX, fin);
        line[n * sizeof(char)] = '\0';
        
        printf("%s",line);
        fwrite(line, sizeof(char), n, fout);
    }
}

int main(void)
{
    FILE *fptr1, *fptr2;
    char filename1[] = "lab1.txt";
    char filename2[] = "lab1a.txt";
    int flag = SUCCESS;

    if ((fptr1 = fopen(filename1,"r")) == NULL) {
        printf("Cannot open %s.\n",filename1);
        flag = FAIL;
    } else if ((fptr2 = fopen(filename2,"w")) == NULL) {
        printf("Cannot open %s.\n",filename1);
        flag = FAIL;
    } else {
        block_Read_Write(fptr1, fptr2);
        fclose(fptr2);
        fclose(fptr1);
    }

    return flag;
}