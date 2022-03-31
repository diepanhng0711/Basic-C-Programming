#include "queueList.h"

ElementType getElement(){
    ElementType e;
    printf("Element: ");
    scanf("%c%*c", &e);
    return e;
}

int main()
{
    Queue Q;
    printf("Create QUEUE NULL!\n");

    MakeNull_Queue(&Q);

    char c;
    printf("Enter Element! Enter ~ to exit!!!\n");

    int i = 1;
    while (i < 6)
    {
        EnQueue(getElement(), &Q);
        i++;
    }

    printf("Print All Element Of Queue!\n");
    while(!isEmptyQueue(Q)){
        printf("%c\n", DeQueue(&Q));
    }

    return 0;
}
