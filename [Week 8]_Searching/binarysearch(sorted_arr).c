#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int binarySearch(int list[], int size, int key) {
    int mid, left = 0;
    int right = size - 1;

    while (left <= right) {
        mid = (left + right) / 2;
        if (list[mid] == key) return mid;
        else if (key < list[mid]) right = mid - 1;
        else left = mid + 1;
    }
    return -1;
}

int binarySearch_Recursion(int list[], int left, int right, int key) {
    if (left <= right) {
        int mid = (left + right) / 2;

        if (list[mid] == key) return mid;

        if (key < list[mid]) return binarySearch_Recursion(list, left, (mid - 1), key);

        return binarySearch_Recursion(list, (mid + 1), right, key);
    }
    return -1;
}

int main() {
    int choice;
    int n;
    int key;
    int index;

    printf("\nEnter the number of array elements: ");
    scanf("%d", &n);
    int *arr = (int*) malloc(sizeof(int) * n);

    printf("\nEnter array elements: \n");
    for (int i = 0; i < n; i ++) {
        printf("arr[%d] = ", i);
        scanf("%d%*c", &arr[i]);
    }

    printf("\nPlease enter the value you wanna find in this array: ");
    scanf("%d%*c", &key);
    printf("\n");

    // Selecting BS function
    while(1) {
        printf("===> What type of Binary Searching do you wanna try?\n");
        printf("  1. Binary Searching\n");
        printf("  2. Binary Searching using Recursion\n");
        printf("  3. Exit the program\n\n");

        printf("<?> Please enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("-->1. Binary Searching\n");
            index = binarySearch(arr, n, key);
            printf("<=> Index = %d\n", index);
            break;
        case 2:
            printf("-->2. Binary Searching using Recursion\n");
            index = binarySearch_Recursion(arr, 0, (n - 1), key);
            printf("<=> Index = %d\n", index);
            break;
        case 3:
            printf("-->3. Exit the program\n");
            printf("Have a good day!!!\n");
            exit(0);
        default:
            printf("-->WRONG CHOICE!!!\n");
            break;
        }
    }
    return 0;
}