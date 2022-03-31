#include<stdio.h>
#define MAX 269

int Int_Array_Comparision(int x[], int y[]){
    int i, n1, n2, check;
    //Enter two integer arrays
    printf("Please enter the first Int Array: \n");
    printf("The number of elements = ");
    scanf("%d",&n1);
    for (i = 0; i < n1; i++){
        printf("\nx[%d] = ",i);
        scanf("%d",&x[i]);
    }

    printf("\n\n");

    printf("Please enter the second Int Array: \n");
    printf("The number of elements = ");
    scanf("%d",&n2);
    for (i = 0; i < n2; i++){
        printf("\ny[%d] = ",i);
        scanf("%d",&y[i]);
    }

    //Comparision
    if(n1 != n2) return 0;

    for(i = 0; i < n1; i++){
        if (x[i] == y[i]) check = 1;
        else {
            check = 0;
            break;
        }
    }

    if(check == 1) return 1;

    for(i = 0; i < n1; i++){
        if (x[i] == y[n1- 1- i]) check = -1;
        else {
            check = 0;
            break;
        }
    }
    
    if(check == -1) return -1;
    return 0;
}

int main()
{
    int x[MAX],y[MAX];
    int i,n;

    //Call the function
    printf("\n\nValue returned = %d",Int_Array_Comparision(x,y));

    return 0;
}