#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#define MAX 500000

void sequential_Search(int a[], int x) {
    int i = 0;
    while (a[i] != x && i < MAX)
    {
        i++;
    }

    if (i < MAX) {
        printf("The element %d is found at index %d\n", a[i], i);
    } else {
        printf("Cannot find %d!\n", x);
    }   
}

void sequential_Search_using_Sentinel(int a[], int x) {
    int i = 0;
    int flag_sentinel = 0;
    for (i = 0; i < MAX; i++) {
        if (a[i] = x) {
            flag_sentinel = 1;
            break;
        }
    }

    if (flag_sentinel == 1) {
        printf("The element %d is found at index %d\n", a[i], i);
    } else if (flag_sentinel == 0) {
        printf("Sentinel met! Cannot find %d!\n", x);
    }   
}

void binary_Search(int a[], int l, int r, int x) {
    if (r >= l) {
        int m = l + (r - l) / 2;
        
        if (a[m] == x) printf("The element %d is found at index %d\n", a[m], m);

        if (a[m] > x) binary_Search(a, l, m - 1, x);

        if (a[m] < x) binary_Search(a, m + 1, r, x);
    } else {
        printf("Cannot find %d!\n", x);
    }
}

int main()
{
    int a[MAX], i, n, key;
    clock_t start, end;
    double tSeqSearch, tSeqSearchSentinel, tBinSearch;
    for (i = 0; i < MAX; i++)
    {
        a[i] = 2 * i + 3;
    }

    printf("Please enter the number which you want to search: ");
    scanf("%d%*c", &n);
    
    while(1) {

        printf("------- MENU -------\n");
        printf("1. Sequential Search\n");
        printf("2. Sequential Search using Sentinel\n");
        printf("3. Binary Search\n");
        printf("4. Exit the program\n");

        printf("Please enter your selection: ");
        scanf("%d%*c", &key);
        switch(key) {
            case 1:
                printf("1. Sequential Search\n");
                //sequential_Search
                start = clock();
                sequential_Search(a, n);
                end = clock();
                tSeqSearch = ((double)(end - start)) / CLOCKS_PER_SEC;

                printf("Time to run Sequential Search: %.10lf s\n",tSeqSearch);
                break;
            case 2:
                //sequential_Search_using_Sentinel
                start = clock();
                sequential_Search_using_Sentinel(a, n);
                end = clock();
                tSeqSearchSentinel = ((double)(end - start)) / CLOCKS_PER_SEC;
            
                printf("Time to run Sequential Search Using Sentinel: %.10lf s\n",tSeqSearchSentinel);
                break;
            case 3:
                //binary_Search
                start = clock();
                binary_Search(a, 0, MAX - 1, n);
                end = clock();
                tBinSearch = ((double)(end - start)) / CLOCKS_PER_SEC;

                printf("Time to run Binary Search: %.10lf s\n",tBinSearch);
                break;
            case 4:
                printf("4.You've chosen: Exit the program\n");
                exit(0);
            default:
                printf("Wrong selection!\n");
                break;
        }        
    }
}