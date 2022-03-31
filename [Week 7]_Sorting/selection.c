#include<stdio.h>
#include<stdlib.h>
#define MAX 100

void swap(int *a, int *b) {
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void selection_Sort(int x[], int n) {
    int i, j, min, tmp;
    for (i = 0; i < n - 1; i++) {
        min = i;
        for (j = i+1; j <= n-1; j++) {
            if (x[j] < x[min]) min = j;
        }
        swap(&x[i], &x[min]);
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

    selection_Sort(x,n);
    for (i = 0; i < n; i++) {
        printf("%d  ",x[i]);
    }
}