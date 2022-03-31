#include<stdio.h>
#include<stdlib.h>

int main(void)
{
    int i,n, *p;
    printf("How many numbers do you want to enter?\n");
    scanf("%d",&n);

    //Allocate an int array of the proper size
    p = (int *) malloc(n * sizeof(int));
    if (p == NULL){
        printf("Memory allocation failed!");
        return 1;
    }

    //Get the numbers from the user
    printf("Please enter numbers now:\n");
    for (i = 0; i < n; i++){
        scanf("%d",&p[i]);
    }

    //Display them in reverse
    printf("The numbers in reverse order are: \n");
    for(i = n - 1; i >= 0; i--){
        printf("%d ",p[i]);
    }

    printf("\n");
    free(p);
    return 0;
}