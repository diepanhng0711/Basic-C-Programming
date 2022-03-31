#include<stdio.h>
#define MAX 50
typedef int Eltype;
typedef Eltype StackType[MAX];
int top;

void initialize(StackType stack);
int isEmpty(StackType stack);
int isFull(StackType stack);
void push(Eltype el, StackType stack);
Eltype pop(StackType stack);
Eltype peek(StackType stack);

void initialize(StackType stack) {
    top = 0;
}

int isEmpty(StackType stack) {
    return (top == 0);
}

int isFull(StackType stack) {
    return (top == MAX);
}

void push(Eltype el, StackType stack) {
    if(isFull(stack)) printf("Stack Overflowed!\n");
    else stack[top++] = el;
}

Eltype pop(StackType stack) {
    if(isEmpty(stack)) {
        printf("Empty stack!\n");
        return -999999;
    }
    else return stack[--top];
}

Eltype peek(StackType stack) {
    if(isEmpty(stack)) {
        printf("Empty stack!\n");
        return -999999;
    }
    else return stack[top-1];
}
