#include<stdio.h>
#include<string.h>

char find_first_Capital(char *c) {
    if (c[0] >= 'A' && c[0] <= 'Z')
    {
        return c[0];
    }
    else if (strlen(c) == 0)
    {
        return '\0';
    }
    return find_first_Capital(c + 1);
}

int main()
{
    printf("%c ", find_first_Capital("aDFasfaf"));
    return 0;
}