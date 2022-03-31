#include<stdio.h>
#include<string.h>
#define MAX 269

void Replace_Char(char s[], char c1, char c2){
    int i;
    for (i = 0; s[i] != '\0'; i++){
        if (s[i] == c1) s[i] = c2;
    }
}

void Replace_Two_Chars(char s[], char s1[], char s2[]){
    int i;
    for (i = 0; s[i+1]!= '\0'; i++){
        if (s[i] == s1[0] && s[i + 1] == s1[1]) {
            s[i] = s2[0];
            s[i + 1] = s2[1];
        }
    }
}

int main()
{
    char c1, c2, s1[3], s2[3], x[MAX], y[MAX];
    
    //Enter the string
    printf("Please enter the string: ");
    fgets(x, MAX, stdin);

    //Enter two char
    printf("Please enter the first char: ");
    scanf("%c%*c",&c1);
    fflush(stdin);
    printf("Please enter the second char: ");
    scanf("%c%*c",&c2);

    //Call the function to replace 1 character
    Replace_Char(x, c1, c2);

    printf("The string now is: %s\n\n",x);

    //Enter two 2 characters strings 
    printf("Please enter the string: ");
    fgets(y, MAX, stdin);

    printf("Please enter the first two characters: ");
    scanf("%s%*c",s1);
    printf("Please enter two characters to replace two following characters: ");
    scanf("%s%*c",s2);

    //Call the function to replace 2 characters
    Replace_Two_Chars(y, s1, s2);

    printf("The string now is: %s\n\n",y);
    return 0;
}