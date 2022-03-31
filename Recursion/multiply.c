#include<stdio.h>
#include<math.h>

int multiply(int x, int y) {
    if (x == 0 || y == 0) return 0;
    if (x == 1) return y;
    if (x == -1) return -y;
    if (x > 1) return y + multiply(x - 1, y);
    if (x < -1) {
        x = -x;
        return (-y) + multiply(x - 1, -y);
    } 
}

int main()
{
    int x, y;
    printf("Nhap 2 so x va y: \n");
    scanf("%d", &x);
    scanf("%d", &y);
    printf("x * y = %d", multiply(x, y));
    return 0;
}