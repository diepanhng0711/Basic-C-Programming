#include<stdio.h>
enum {SUCCESS, FAIL};

void Double_Space(FILE *fin, FILE *fout){
    int c;
    while ((c = fgetc(fin)) != EOF) {
        fputc(c, fout);
        if (c == '\n') fputc('\n',fout);
        putchar(c);
    }   
}

int main()
{
    FILE *fptr1, *fptr2;
    char filename1[] = "lab1.txt";
    char filename2[] = "lab1space.txt";
    int flag = SUCCESS;

    if ((fptr1 = fopen(filename1,"r")) == NULL) {
        printf("Cannot open %s.\n",filename1);
        flag = FAIL;
    } else if ((fptr2 = fopen(filename2,"w")) == NULL) {
        printf("Cannot open %s.\n",filename2);
        flag = FAIL;
    } else {
        Double_Space(fptr1, fptr2);
        fclose(fptr2);
        fclose(fptr1);
    }

    return flag;
}