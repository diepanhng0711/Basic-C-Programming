#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int sequential_search(char *items, char key) {
    register int t;

    for(t = 0; t < strlen(items); t++) {
        if (key == items[t]) return t;
    }
    return -1;
}

int main() {
    char *str = (char*) malloc(sizeof(char)*20);

    printf("Please enter the string: ");
    //fgets(str, 20, stdin);
    gets(str);
    
    int index = sequential_search(str, 'n');

    printf("Length of str = %d\n", strlen(str));
    printf("Index = %d", index);
}