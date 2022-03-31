#include"queueArraynStruct.h"

int main()
{
    Queue Q;
    char c = '0';

    printf("Khoi tao Queue!\n");
    MakeNull_Queue(&Q);

    printf("Them phan tu cho Queue!\n");

    while(1){
        printf("Enter element(~ : exit): ");
        scanf("%c%*c", &c);
        if(c != '~') EnQueue(c, &Q);
        else break;
    }

    printf("Dequeue All Element!\n");
    while (!Empty_Queue(Q))
    {
        printf("%c\n", DeQueue(&Q));
    }
    
    return 0;
}
