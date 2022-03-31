#include<stdio.h>
#include<stdlib.h>
#define MAX 100

void insertion_Sort(int x[], int n) {
    int i, j;
    int next;
    for (i = 1; i < n; i++) {
        next = x[i];
        for (j = i-1; j >= 0 && (next < x[j]); j--) {
            x[j+1] = x[j];
        }
        x[j+1] = next;
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

    insertion_Sort(x, n);
    for (i = 0; i < n; i++) {
        printf("%d  ",x[i]);
    }
}