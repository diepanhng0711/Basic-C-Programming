#include<stdio.h>
#define MaxLength 100

typedef int ElementType;
typedef struct Queue_t {
    ElementType Elements[MaxLength];
    int Front, Rear;
} Queue;

void MakeNull_Queue(Queue *Q) {
    Q -> Front = -1;
    Q -> Rear = -1;
}

int Empty_Queue(Queue Q) {
    return (Q.Front == -1);
}

int Full_Queue(Queue Q) {
    return (Q.Rear - Q.Front + 1 == MaxLength);
}

void EnQueue(ElementType X, Queue *Q) {
    if (!Full_Queue(*Q)) {
        if(Empty_Queue(*Q)) {
            Q -> Front = 0;
        }

        Q -> Rear = (Q -> Rear + 1);
        Q -> Elements[Q->Rear] = X;
        // Q->Elements[++(Q->Rear)] = X;
    }
    else printf("Queue is Full!\n");
}

ElementType DeQueue(Queue *Q) {
    ElementType e;
    if (!Empty_Queue(*Q)) {
        e = Q -> Elements[Q -> Front];
        Q -> Front = Q -> Front + 1;
        if (Q -> Front > Q -> Rear) MakeNull_Queue(Q); //Queue become empty!
        return e;
    }
    else
    {
        printf("Queue is empty!\n");
    }    
}

