#include <stdio.h>
#include <ctype.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char ch)
{
    stack[++top] = ch;
}

char pop()
{
    return stack[top--];
}

int priority(char ch)
{
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '+' || ch == '-')
        return 1;
    return 0;
}

int main()
{
    char infix[MAX], postfix[MAX];
    int i = 0, k = 0;
    char ch;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    while (infix[i] != '\0')
    {
        ch = infix[i];
        i++;

        if (ch == '(')
            push(ch);

        else if (isalnum(ch))
            postfix[k++] = ch;

        else if (ch == ')')
        {
            while (top != -1 && stack[top] != '(')
                postfix[k++] = pop();

            if (top == -1)
            {
                printf("Invalid expression\n");
                return 0;
            }

            pop();
        }

        else
        {
            while (top != -1 && priority(stack[top]) >= priority(ch))
                postfix[k++] = pop();

            push(ch);
        }
    }

    while (top != -1)
    {
        if (stack[top] == '(')
        {
            printf("Invalid expression\n");
            return 0;
        }

        postfix[k++] = pop();
    }

    postfix[k] = '\0';

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
