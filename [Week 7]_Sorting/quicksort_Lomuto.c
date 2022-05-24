#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//----------------------------------------------------------------
// Thuật toán Quicksort
// O(n): nlogn
// Trường hợp tồi nhất: n^2

/*
 * THUẬT TOÁN SẮP XẾP NHANH (QUICKSORT) - PHÂN HOẠCH LOMUTO
 * Ý tưởng thuật toán:
 * - Đặt pivot(chốt) tại phần tử cuối cùng của dãy
 * - Chỉ số i bắt đầu từ l - 1 (left - 1)
 * - Bắt đầu thực hiện phân vùng Partition với dãy a, l, r Partition(a, l, r)
 * - Duyệt từ phần tử đầu tiên của dãy (l) với chỉ số j
 * - Nếu a[j] > pivot => i++ (++i), sau đó thực hiện swap a[j] với a[i]
 *    =>> Mục đích, tạo ra: || phân vùng trái với các phần tử nhỏ hơn pivot
                            || phân vùng phải với các phần tử lớn hơn pivot
 * - Sau khi phân vùng xong, i++ (++i) rồi thực hiện swap để đưa pivot vào giữa 2 phân vùng
 * - Lúc này, phân vùng trái luôn nhỏ hơn pivot, phân vùng phải luôn lớn hơn pivot
 * - Thực hiện đệ quy thuật toán Quicksort với 2 phân vùng trái: Quicksort(a, l, pivot - 1) và phân vùng Quicksort(a, pivot + 1, r) 
 */

//NHƯỢC ĐIỂM: nếu dãy đã sắp xếp tăng dần, dãy vẫn tiếp tục phân vùng và sắp xếp

void swap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int partition (int a[], int l, int r) {
    int pivot = a[r];

    int i = l -1;
    int j;

    for (j = l; j < r; j++) {
        if (a[j] < pivot) {
            i++;
            swap(&a[i], &a[j]);
        }
    }

    //Đưa pivot về giữa 2 phân vùng
    i++;
    swap(&a[i], &a[r]);
    return i;
}

//Thuật toán Quicksort
void quicksort (int a[], int l, int r) {
    if (l >= r) return ;

    int p = partition(a, l, r);
    quicksort(a, l, p - 1);
    quicksort(a, p + 1, r);
}

int main() {
    int n;
    srand(time(NULL));
    
    printf("Nhap vao so phan tu cua mang can thuc hien Quicksort: ");
    scanf("%d", &n);

    int a[n];
    int i;
    //Cú pháp random trong khoảng [min, max]: a = min + rand()% (max + 1 - min)
    for (i = 0; i < n; i++) {
        a[i] = -100 + rand() % (100 + 1 - (-100));
    }

    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    quicksort(a, 0, n - 1);
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}