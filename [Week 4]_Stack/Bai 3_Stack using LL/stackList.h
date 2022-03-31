#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdbool.h>
#include<stdlib.h>

typedef int elementType;
typedef struct StackType {
    elementType element;
    struct StackType *next;
} StackType;

int isEmpty(StackType *top) {
    return (top == NULL);
}

StackType *make_New_Node(elementType el) {
    StackType *New = (StackType *) malloc(sizeof(StackType));
    if (New == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;
    }
    New ->element = el;
    New ->next = NULL;
    return New;
}

elementType getData() {
    elementType tmp;
    printf("New element = ");
    scanf("%d",&tmp);
    return tmp;
}

void push(elementType el, StackType **top) {
    StackType *New = make_New_Node(el);
    if (New == NULL) {
        printf("Stack overflowed!\n");
        return;
    }
    if (*top == NULL) {
        *top = New;
        (*top) -> next = NULL;
        return;
    }

    New -> next = *top;
    *top = New;
}

elementType pop(StackType **top) {
    if(isEmpty(*top)) {
        printf("Empty stack!\n")    ;
        return -1;
    }

    elementType data;
    StackType *ptr = *top;
    data = (*top) -> element;
    *top = (*top)->next;
    free(ptr);
    return data;
}

elementType top(StackType *top){
    return top -> element;
}

void freeStack(StackType **top) {
    while (!isEmpty(*top))
    {
        pop(top);
    }
}