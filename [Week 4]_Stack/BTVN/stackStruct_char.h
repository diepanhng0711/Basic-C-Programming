#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 50
typedef char Eltype;
typedef struct StackRec {
    Eltype storage[MAX];
    int top;
} StackType;

void initialize(StackType *stack) {
    (*stack).top = 0;
}

int isEmpty(StackType stack) {
    return (stack.top == 0);
}

int isFull(StackType stack) {
    return (stack.top == MAX);
}

void push(Eltype el, StackType *stack) {
    if(isFull(*stack)) printf("Stack Overflowed!\n");
    else (*stack).storage[(*stack).top++] = el;
}

Eltype pop(StackType *stack) {
    if (isEmpty(*stack)) {
        printf("Empty stack!\n");
        return 0;
    }
    else return(*stack).storage[--(*stack).top];
}

Eltype peek(StackType stack) {
    if (isEmpty(stack)) {
        printf("Empty stack!\n");
        return 0;
    }
    else return stack.storage[stack.top-1];
}