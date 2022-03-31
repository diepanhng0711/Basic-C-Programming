#include"queueArraynStruct.h"
int main(int argc, char const *argv[])
{
    Queue Q;

    int c, i;
    char select;
    int tmp;

    printf("Khoi tao Queue!\n");
    MakeNull_Queue(&Q);

    printf("Them phan tu cho Queue!\n");

    for (i = 0; i < 10; i++)
    {
        printf("Enter element: ");
        scanf("%d%*c", &c);
        EnQueue(c, &Q);
    }

    do
    {
        printf("Queue full!!! Co muon nhap tiep (y/n)? ");
        scanf("%c%*c", &select);

        if (select == 'y')
        {
            printf("Enter element: ");
            scanf("%d%*c", &c);
            tmp = DeQueue(&Q);
            printf("Front: %d\n", tmp);
            EnQueue(c, &Q);
        }

    } while (select != 'n');
    

    // while (1)
    // {
    //     printf("Enter element(~ : exit): ");
    //     scanf("%c%*c", &c);
    //     if (c != '~')
    //         EnQueue(c, &Q);
    //     else
    //         break;
    // }
    return 0;
}
