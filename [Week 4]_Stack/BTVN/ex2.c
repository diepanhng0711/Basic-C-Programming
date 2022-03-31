#include"stackStruct_char.h"
#include<stdbool.h>

int precedence(char x)
{
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/' || x == '%')
        return 2;

    return 3;
}

void enterExpression(char express[])
{
    printf("Enter arithmetic expressions in infix notation: ");
    scanf("%s%*c", express);
}

void Infix_to_Postfix(char infix[], char postfix[])
{
    int i = 0, j = 0;
    StackType s;
    initialize(&s);
    char x;

    for (i = 0; i < strlen(infix); i++)
    {
        if (infix[i] >= '0' && infix[i] <= '9')
        {
            postfix[j] = infix[i];
            j++;
        }
        else if (infix[i] == '(')
        {
            push(infix[i], &s);
        }
        else if (infix[i] == ')')
        {
            while ((x = pop(&s)) != '(')
            {
                postfix[j] = x;
                j++;
            }
        }
        else
        {
            while (precedence(infix[i]) <= precedence(peek(s)) && !isEmpty(s))
            {
                postfix[j++] = pop(&s);
            }
            push(infix[i], &s);
        }
    }
    while (!isEmpty(s))
    {
        postfix[j++] = pop(&s);
    }
    postfix[j++] = '\0';
}

void calculate(char postfix[]){
    StackType s;
    initialize(&s);
    int x1, x2, x,i;

    for (i = 0; postfix[i] != '\0'; i++)
    {
        if(postfix[i] >= '0' && postfix[i] <= '9'){
            push(postfix[i] - '0', &s);
        }
        else
        {
            x1 = pop(&s);
            x2 = pop(&s);

            switch (postfix[i])
            {
            case '+':
                x = x2 + x1;
                break;
            case '-':
                x = x2 - x1;
                break;
            case '*':
                x = x2 * x1;
                break;
            case '/':
                x = x2 / x1;
                break;
            case '%':
                x = x2 % x1;
                break;
            default:
                break;
            }

            push(x, &s);
        }
    }

    printf("%d\n", pop(&s));
}

int main(int argc, char const *argv[])
{
    int key;
    StackType s;
    char infix[50], postfix[50];
    while (true)
    {
        printf("------ MENU ------\n"
               "1. Enter arithmetic expressions in infix notation\n"
               "2. Change to postfix\n"
               "3. Calculating value\n"
               "4. Exit the program\n"
               "Please Select: ");
        scanf("%d%*c", &key);
        
        switch (key)
        {
        case 1:
            enterExpression(infix);
            break;
        case 2:
            Infix_to_Postfix(infix, postfix);
            printf("%s\n", postfix);
            break;
        case 3:
            calculate(postfix);
            break;
        case 4:
            printf("Exit the program\n");
            return 0;
            break;
        default:
            printf("Wrong selection!\n");
            break;
        }
    }
}
