#include "stackStruct.h"

int main(){
    StackType s1, s2, subtract;
    int carry = 0;
    int c1, c2, i;
    initialize(&s1);
    initialize(&s2);
    initialize(&subtract);
  
    char tmp[MAX];
    printf("x1 = ");
    scanf("%s%*c", tmp);
    for(i = 0; i < strlen(tmp); i++) push(tmp[i] - '0', &s1);
    printf("x2 = ");
    scanf("%s%*c", tmp);
    for(i = 0; i < strlen(tmp); i++) push(tmp[i] - '0', &s2);

    while(!isEmpty(s1) || !isEmpty(s2)){
        if((c1 = pop(&s1)) == -999999) c1 = 0;
        if((c2 = pop(&s2)) == -999999) c2 = 0;
        if(c1 - c2 - carry < 0){
            int x = -1 *(c1 - c2 - carry);
            push(x, &subtract);
            carry = -1;
        } else{
            push(c1 - c2 - carry, &subtract);
            carry = 0;
        }
    }

    if(carry == -1) {
        printf("%c",'-');
        while(!isEmpty(subtract)) printf("%d", pop(&subtract));
    } else {
        while(!isEmpty(subtract)) printf("%d", pop(&subtract));
    }

    printf("\n");
}