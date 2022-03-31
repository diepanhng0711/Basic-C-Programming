#include"stackArr.h"

int main()
{
    int a[6] = {4, 7, 1, -9, 26, 13};
    int i;
    StackType s;
    initialize(s);
    for (i = 0; i < 6; i++) {
        push(a[i],s);
    }
    printf("\nPop all elements in stack!\n");
    while (!isEmpty(s))
    {
        printf("%d\n",pop(s));
    }
    printf("\n");
    return 0;
}