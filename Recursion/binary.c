#include<stdio.h>
#include<string.h>

int dec_To_Bin(int n) {
    if (n == 0) return 0;
    return n % 2 + 10* dec_To_Bin(n / 2);
}

int main()
{
    printf("%d\n",dec_To_Bin(255));
    return 0;
}