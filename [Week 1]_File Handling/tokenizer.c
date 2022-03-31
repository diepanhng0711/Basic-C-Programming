#include<stdio.h>
#include<string.h>
#define MAX 269

int main()
{
    int i;
    char s[MAX];

    printf("Please enter the string: ");
    fgets(s, MAX, stdin);

    printf("---Tokenizer: \n");
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] == ' ') {
            if (s[i - 1] == ' ') continue;
            else printf("\n");
        } else {
            printf("%c",s[i]);
        }
    }
    return 0;
}