#include<stdio.h>
#include<stdlib.h>
#define MAX 100

void swap(int *a, int *b, int *tmp) {
    *tmp = *a;
    *a = *b;
    *b = *tmp;
}

void quick_Sort(int x[], int left, int right) {
    int pivot, i, j;
    int tmp;
    if (left < right) {
        i = left;
        j = right + 1;
        pivot = x[left];
        do {
            do i++; while (x[i] < pivot);
            do j--; while (x[j] > pivot);
            if (i < j) swap(&x[i], &x[j], &tmp);
        } while (i < j);
        swap(&x[left], &x[i], &tmp);
        quick_Sort(x, left, j - 1);
        quick_Sort(x, j + 1, right);
    }
}

int main()
{
    int x[MAX], n, i;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n); 

    for (i = 0; i < n; i++) {
        printf("x[%d] = ", i);
        scanf("%d", &x[i]);
    }

    quick_Sort(x, 0, 4);
    for (i = 0; i < n; i++) {
        printf("%d  ",x[i]);
    }
}