#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int threshold = 5;

void merge(int x[], int a[], int b[], int m, int n) {
    int i = 0;
    int j = 0;
    int k = 0;
    while (k < m + n) {
        if (a[i] < b[j]) {
            x[k] = a[i];
            i++;
        } else {
            x[k] = b[j];
            j++;
        }
        k++;
    }
}

int copy(int x[], int y[],int i, int n) {
    int k = 0;
    for (; i < n; i++) {
        y[k] = x[i];
        k++;
    }
}

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

void merge_Sort(int x[], int n) {
    int a[MAX], b[MAX];
    int k;
    if (n < threshold) insertion_Sort(x, n);
    else {
        copy(x, a, 0, n/2);
        k = n - n/2;
        copy(x, b, n/2, n);
        merge_Sort(a, n/2);
        merge_Sort(b, k);
        merge(x,a,b,n/2,n);
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

    merge_Sort(x, n);
    for (i = 0; i < n; i++) {
        printf("%d  ",x[i]);
    }
}