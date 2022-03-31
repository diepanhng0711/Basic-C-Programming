#include "stackRec.h"

int main(){
  StackType s1, s2, sum;
  int carry = 0;
  int c1, c2, i;
  initialize(&s1);
  initialize(&s2);
  initialize(&sum);
  
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
    if(c1 + c2 + carry >= 10){
      push(c1 + c2 + carry - 10, &sum);
      carry = 1;
    }
    else{
      push(c1 + c2 + carry, &sum);
      carry = 0;
    }
  }

  if(carry == 1) push(carry, &sum);

  while(!isEmpty(sum)) printf("%d", pop(&sum));
  printf("\n");
}
