#include<stdio.h>
#include<math.h>
#include<string.h>

void swap(int n, char a, char b) {
    printf("Chuyen dia thu %d tu cot %c sang cot %c!\n",n, a, b); 
}

void towers(int n, char cot1, char cot2, char cot3){
    if (n == 1) {
        swap(n, cot1, cot3);
        return;
    }
    towers(n - 1,cot1, cot3, cot2);         //cot3 trung gian. Chuyen n-1 dia tu coc dau sang coc trung gian        A->B
    swap(n, cot1, cot3);                    //Chuyen dia thu n tu coc dau sang coc dich                             A->C
    towers(n -1, cot2, cot1, cot3);         //Chuyen n-1 dia tu coc trung gian sang coc dich (xuat hien de quy)     B->C
}

int main()
{
    int num;
    printf("Nhap so dia : ");   
    scanf("%d", &num);
    printf("Ket qua :\n\n");
    towers(num, 'A', 'B', 'C');
    return 0;
}