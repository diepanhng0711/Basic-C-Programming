#include<stdio.h>
#include<math.h>
#include<string.h>

void towers(int n, char cot1, char cot3, char cot2){
    if (n == 1) {
        printf("Chuyen 1 dia tu cot 1 sang cot 3!\n");
        return;
    }
    towers(n - 1,cot1, cot2, cot3);
    printf("Chuyen %d dia tu cot 1 sang cot 3!\n",n-1);
    towers(n -1, cot3, cot2, cot1);
}

int main()
{
    int num;
    printf("Mhap so dia : ");   
    scanf("%d", &num);
    printf("The sequence of moves involved in the Tower of Hanoi are :\n");
    towers(num, 'A', 'C', 'B');
    return 0;
}