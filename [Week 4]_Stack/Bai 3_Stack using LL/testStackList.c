#include"stackList.h"

int main()
{
    int i;
    StackType *top;
    int a[] = {5,6,8,7,10,12,16,23,30};
    for (i = 0; i < 9; i++)
    {
        push(a[i], &top);
    }

    while (!isEmpty(top))
    {
        printf("%d\n", pop(&top));
    }
    return 0;
}