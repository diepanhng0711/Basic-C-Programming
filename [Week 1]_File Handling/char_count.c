#include<stdio.h>
#include<string.h>
#define ALPHA 26

void AlphaCount(char s[], int count[ALPHA]){
    int i;
    for (i = 0; i < (strlen(s) - 1); i++){
        if (s[i] <= 'z' && s[i] >= 'a') count[s[i] - 'a']++;
        if (s[i] <= 'Z' && s[i] >= 'A') count[s[i] - 'A']++;
    }
}


int main()
{
    int i;
    int count[ALPHA] = {0};
    char s[50];

    //Enter a string
    printf("Please enter a string: ");
    fgets(s, 50, stdin);

    //Call the alphabet-counting function
    AlphaCount(s,count);

    for (i = 0; i < ALPHA; i++){
        if (count[i] == 0) continue;
        if (count[i] == 1) printf("The letter \'%c\' appears 1 time!\n", 'a'+i);
        else printf("The letter \'%c\' appears %d times!\n", 'a'+i, count[i]);
    }

    //Exit the program!
    return 0;
}