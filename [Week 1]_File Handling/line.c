#include<stdio.h>
#define MAX 81
enum {SUCCESS, FAIL};

void LineReadWrite(FILE *fin, FILE *fout){
    char line[MAX];
    while (fgets(line, MAX, fin) != NULL) {
        fputs(line, fout);
    }
}

int main()
{
    FILE *fptr1, *fptr2;
    char filename1[] = "lab1.txt";
    char filename2[] = "lab1line.txt";
    int flag = SUCCESS;

    if ((fptr1 = fopen(filename1,"r")) == NULL) {
        printf("Cannot open %s.\n",filename1);
        flag = FAIL;
    } else if ((fptr2 = fopen(filename2,"w")) == NULL) {
        printf("Cannot open %s.\n",filename2);
        flag = FAIL;
    } else {
        LineReadWrite(fptr1, fptr2);
        fclose(fptr2);
        fclose(fptr1);
    }

    return flag;
}