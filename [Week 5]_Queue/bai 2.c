#include "queue_list.h"
#include "libDLL_W11.h"

typedef struct
{
    int id;
    int memory;
} program;

typedef program ElementType;

typedef struct Node
{
    ElementType Element;
    struct Node *Next;
} Node;

void create(Queue *q, doublelist *root, doublelist *tail, int *currentPro, int numParralel, int maxMem)
{
    int memory = 0, id = 0, sumMemCurrent = 0;
    printf("Create new program: \n");
    printf("The memory size of program? ");
    scanf("%d%*c", &memory);
    printf("Program ID? ");
    scanf("%d%*c", &id);

    node *p;
    for (p = *root; p != NULL; p = p->next)
    {
        if (id == (p->ele).id)
        {
            printf("Trung id %d voi program khac\n", id);
            return;
        }
    }

    Node *curr;
    for (curr = q->Front; curr != NULL; curr = curr->Next)
    {
        if (id == (curr->Element).id)
        {
            printf("ID %d voi program khac\n", id);
            return;
        }
    }

    program tmp;
    tmp.id = id;
    tmp.memory = memory;

    if (*currentPro >= numParralel)
    {
        EnQueue(tmp, q);
        printf("Enqueue!\n");
        return;
    }
    else
    {
        for (p = *root; p != NULL; p = p->next)
        {
            sumMemCurrent += (p->ele).memory;
        }

        if (tmp.memory + sumMemCurrent > maxMem)
        {
            EnQueue(tmp, q);
            printf("Enqueue!\n");
        }
        else
        {
            append(tmp, root, tail);
            (*currentPro)++;
            printf("Success!\n");
        }
    }
}

void deleteElementInQueue(Queue *q, Node **cur)
{
    Node *tmp;
    int delHead = 0;
    for (tmp = q->Front;; tmp = tmp->Next)
    {
        if (q->Front == *cur)
        {
            delHead = 1;
            break;
        }
        else if (tmp->Next == *cur)
        {
            delHead = 0;
            break;
        }
    }
    if (!delHead)
    {
        Node *to_free = tmp->Next;
        tmp->Next = tmp->Next->Next;
        free(to_free);
    }
    else
    {
        tmp = q->Front;
        q->Front = q->Front->Next;
        free(tmp);
    }
}

void kill(Queue *q, doublelist *root, doublelist *tail, int *currentPro, int numParralel, int maxMem)
{
    int idKill, sumMemCurrent = 0;
    printf("Kill Process: Process ID? ");
    scanf("%d%*c", &idKill);
    int exist = 0;
    node *p = NULL;
    Node *cur = NULL;

    for (p = *root; p != NULL; p = p->next)
    {
        sumMemCurrent += (p->ele).memory;
    }

    p = NULL;

    for (p = *root; p != NULL; p = p->next)
    {
        if (idKill == (p->ele).id)
        {
            exist = 1;
            break;
        }
    }

    if (p == NULL)
    {
        for (cur = q->Front; cur != NULL; cur = cur->Next)
        {
            if (idKill == (cur->Element).id)
            {
                exist = 1;
                break;
            }
        }
    }

    if (exist)
    {
        if (p != NULL)
        {
            sumMemCurrent -= (p->ele).memory;
            deleteCurrentElement(root, &p, tail);
            (*currentPro)--;
            printf("Success!\n");
        }
        else if (cur != NULL)
        {
            deleteElementInQueue(q, &cur);
            printf("Success!\n");
        }
    }
    else
    {
        printf("ID ko ton tai!\n");
        return;
    }

    int memoryDequeue = 0;
    if (!isEmptyQueue(*q))
    {
        memoryDequeue = (q->Front->Element).memory;
        if (sumMemCurrent + memoryDequeue <= maxMem && *currentPro < numParralel)
        {
            ElementType tmp = DeQueue(q);
            append(tmp, root, tail);
            (*currentPro)++;
        }
    }
    else
    {
        MakeNullQueue(q);
    }
    
}

void show(Queue q, doublelist root)
{
    printf("ID\tMemory\tQueue\n");
    traverseListFromRoot(root);

    while (!isEmptyQueue(q))
    {
        printf("%d\t\t%d\n", ((q.Front)->Element).id, ((q.Front)->Element).memory);
        q.Front = (q.Front)->Next;
    }
}

int main(int argc, char const *argv[])
{
    int numParallel, maxMem, select, currentPro = 0;

    Queue q;
    MakeNullQueue(&q);

    printf("Number of parallel process: ");
    scanf("%d%*c", &numParallel);

    doublelist pFirstProgram = NULL, tail = NULL;

    printf("Memory Capacity (MB): ");
    scanf("%d%*c", &maxMem);

    printf("\tMENU\n"
           "1. Create new program\n"
           "2. Kill a program by id\n"
           "3. Show status\n"
           "4. Exit\n");
    while (1)
    {
        printf("--> Select: ");
        scanf("%d%*c", &select);

        switch (select)
        {
        case 1:
            create(&q, &pFirstProgram, &tail, &currentPro, numParallel, maxMem);
            break;
        case 2:
            kill(&q, &pFirstProgram, &tail, &currentPro, numParallel, maxMem);
            break;
        case 3:
            show(q, pFirstProgram);
            break;
        case 4:
            FreeQueue(&q);
            FreeList(&pFirstProgram);
            printf("\tBye! Bye!\n");
            exit(0);
            break;
        default:
            break;
        }
    }
    return 0;
}
