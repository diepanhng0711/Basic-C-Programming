#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 80

char *sub_Str(char *str, int off, int n){
    char *result;
    int i;
    int count = 0;

    for(i = off; i < strlen(str); i++){
        count++;
    }

    while (n > count || n <= 0){
        printf("Please enter the number:\n");
        scanf("%d",&n);
    }


    result = (char*) malloc((n - off + 1 +1) * sizeof(char));
    
    if (result == NULL) {
        printf("Memory Allocation Failed!\n");
        return NULL;
    }

    strncpy(result, (str + off), n);

    return result;
}

int main()
{
    char s[MAX + 1];
    int offset, number;
    char *new_str;

    printf("Please enter the string:\n");
    scanf("%s",s);
    printf("Please enter the offset index:\n");
    scanf("%d",&offset);
    printf("Please enter the number:\n");
    scanf("%d",&number);

    new_str = sub_Str(s, offset, number);
    if (new_str == NULL) {
        printf("Memory Allocation Failed!\n");
        return 1;
    }

    printf("The substring of %s is %s\n", s, new_str);
    return 0;
}
