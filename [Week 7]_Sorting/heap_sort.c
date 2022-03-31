#include<stdio.h>
#include<stdlib.h>
#define MAX 100

void swap(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void adjust(int x[], int root, int n) {
    int child, rootkey;
    int tmp;
    tmp = x[root];
    rootkey = x[root];
    child = 2 *root;
    while (child <= n) {
        if((child < n) && (x[child] < x[child+1])) child++;
        if (rootkey > x[child]) break;
        else {
            x[child/2] = x[child];
            child*= 2;
        }
    }
    x[child/2] = tmp;
}

void heap_Sort(int x[], int n) {
    int i, j;
    int tmp;
    for (i = n/2; i > 0; i--) adjust(x, i, n);
    for (i = n - 1; i > 0; i--) {
        swap(&x[1], &x[i+1]);
        adjust(x, 1 ,i);
    }
}

int main() 
{
    int i;
    int a[10] = {26, 5, 77, 1, 61, 11, 59, 15, 48, 19};

    heap_Sort(a, 10);

    for (i = 0; i < 10; i++) {
        printf("%d  ",a[i]);
    }
}