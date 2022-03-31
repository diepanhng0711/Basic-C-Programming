#include<stdio.h>
#include<math.h>

int int_sum(int n) {
    if (n == 0) return 0;
    return n + int_sum(n - 1);
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("Sum = %d", int_sum(n));
    return 0;
}