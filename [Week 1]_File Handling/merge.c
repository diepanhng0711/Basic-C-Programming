#include<stdio.h>
#include<string.h>
#define MAX 81
enum {SUCCESS, FAIL};

void LineMerge(FILE *f1, FILE *f2, FILE *fout){
    char line1[MAX], line2[MAX];
    while ((fgets(line1, MAX, f1) != NULL) && (fgets(line2, MAX, f2) != NULL)){
        fputs(line1, fout);
        fputs(line2, fout);
    }
    while (fgets(line1, MAX, f1) != NULL) fputs(line1, fout);
    while (fgets(line2, MAX, f2) != NULL) fputs(line2, fout);
}

int main(int argc, char *argv[])
{
    FILE *fptr1, *fptr2, *fptr3;
    int flag = SUCCESS;

    if (argc != 4) {
        printf("Syntax error!\nMust be: .\\merge <file1> <file2> <file3>\n");
        flag = FAIL;
    }

    if ((fptr1 = fopen(argv[1],"r")) == NULL) {
        printf("Cannot open %s.\n",argv[1]);
        flag = FAIL;
    } else if ((fptr2 = fopen(argv[2],"r")) == NULL) {
        printf("Cannot open %s.\n",argv[2]);
        flag = FAIL;
    } else if ((fptr3 = fopen(argv[3],"w")) == NULL) {
        printf("Cannot open %s.\n",argv[3]);
        flag = FAIL;
    } else {
        LineMerge(fptr1, fptr2, fptr3);
        fclose(fptr3);
        fclose(fptr1);
        fclose(fptr2);
        flag = SUCCESS;
    }

    return flag;
}