#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;

typedef struct Node{
    ElementType Element;
    struct Node *Next;
} Node;

typedef Node *Position;

typedef struct{
    Position Front, Rear;
} Queue;

void MakeNullQueue(Queue *Q){
    Q->Front = NULL;
    Q->Rear = NULL;
}

Node *makeNewNode(ElementType e){
    Node *New = (Node *) malloc(sizeof(Node));
    New->Next = NULL;
    New->Element = e;
    return New;
}

int isEmptyQueue(Queue Q){
    return Q.Front == NULL;
}

void EnQueue(ElementType X, Queue *Q){
    Node *New = makeNewNode(X);

    if(Q->Front == NULL){
        Q->Front = New;
        Q->Rear = New;
        return;
    }
    Q->Rear->Next = New;
    Q->Rear = Q->Rear->Next;
}

ElementType DeQueue(Queue *Q){
    ElementType e;
    Position tmp;

    if(!isEmptyQueue(*Q)){
        e = Q->Front->Element;
        tmp = Q->Front;
        Q->Front = Q->Front->Next;
        free(tmp);
        return e;
    }
    else printf("Queue NULL!\n");
}

void FreeQueue(Queue *Q){
    Node *tmp;
    while (!isEmptyQueue(*Q))
    {
        tmp = Q->Front;
        Q->Front=Q->Front->Next;
        free(tmp);
    }
}
