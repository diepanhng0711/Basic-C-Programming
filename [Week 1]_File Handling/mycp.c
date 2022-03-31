#include<stdio.h>
#include<string.h>

void Copy(FILE *fin, FILE *fout){
    int c;
    while ((c = fgetc(fin)) != EOF) {
        fputc(c, fout);
        putchar(c);
    }
}

int main(int argc, char *argv[])
{
    FILE *fptr1, *fptr2;

    if (argc != 3) {
        printf("Syntax error!\nMust be: .\\mycp a1.txt a2.txt");
        return 1;
    }

    if ((fptr1 = fopen(argv[1],"r")) == NULL) {
        printf("Cannot open %s.\n",argv[1]);
        return 1;
    } else if ((fptr2 = fopen(argv[2],"w")) == NULL) {
        printf("Cannot open %s.\n",argv[2]);
        return 1;
    } else {
        Copy(fptr1, fptr2);
        fclose(fptr2);
        fclose(fptr1);
    }

    return 0;
}