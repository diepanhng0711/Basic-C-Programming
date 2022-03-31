#include<stdio.h>
#include<math.h>

int print_Number(int n){
    static int i = 1;
    if (n < 1) return;
    printf("%d ",i);
    i++;
    return print_Number(n - 1);
}

int main()
{
    int n;
    scanf("%d", &n);
    print_Number(n);
    return 0;
}