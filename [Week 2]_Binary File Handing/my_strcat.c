#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 80

char *my_strcat(char *str1, char *str2){
    int len1, len2;
    char *result;

    len1 = strlen(str1);
    len2 = strlen(str2);

    result = (char*) malloc((len1 + len2 +1) * sizeof(char));
    
    if (result == NULL) {
        printf("Memory Allocation Failed!\n");
        return NULL;
    }

    strcpy(result, str1);
    strcpy(result + len1, str2);

    return result;
}

int main()
{
    char s1[MAX + 1], s2[MAX + 1];
    char *cat_str;

    printf("Please enter two string:\n");
    gets(s1);
    gets(s2);

    cat_str = my_strcat(s1, s2);
    if (cat_str == NULL) {
        printf("Memory Allocation Failed!\n");
        return 1;
    }

    printf("The concatenation of %s & %s is %s\n", s1, s2, cat_str);
    return 0;
}