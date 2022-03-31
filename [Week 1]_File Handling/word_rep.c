#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    int i,n;
    n = atoi(argv[2]);

    if (argc != 3) {
        printf("Wrong Syntax!\nMust be '\'replicate <height> <width>!\n");
        return 1;
    }

    if (n <= 0) {
        printf("Invalid value!");
        return 1;
    }

    for (i = 0; i < n; i++){
        printf("%s",argv[1]);
    }

    return 0;
}