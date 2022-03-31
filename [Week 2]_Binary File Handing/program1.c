#include <stdio.h>
#include <stdlib.h>

// typedef struct
// {
// 	char vietnamese[60];
// 	char english[60];
// } Tu;

int main()
{
    FILE *f = fopen("vnedict.dat", "rb");
    if (f == NULL)
        return 1;

    char tmp[300];
    for (int i = 0; i < 54374; i++)
    {
        /* code */
        fread(tmp, sizeof(char), 300, f);
        printf("%s\n", tmp);
    }
    fclose(f);
}