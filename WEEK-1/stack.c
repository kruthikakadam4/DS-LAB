#include<stdio.h>
#define max 5
int stack[max];
int top = -1;

void push()
{
    int value;
    if(top == max-1)
        printf("Stack overflow");
    else
    {
        printf("Enter the element to be pushed in the stack:");
        scanf("%d",&value);
        top++;
        stack[top] = value;
        printf("%d pushed into the stack\n",value);
    }
}

void pop()
{
    int value;
    if(top == -1)
        printf("Stack underflow\n");
    else
    {
        value = stack[top];
        top--;
        printf("%d popped from the stack\n",value);
    }
}

void display()
{
    int i;
    if(top == -1)
        printf("Stack is empty\n");
    else
    {
        printf("The stack elements are:\n");
        for(i=top;i>=0;i--)
            printf("%d ",stack[i]);
    }
}

int main()
{
    while(1)
    {
        int ch;
        printf("\n Stack Menu: \n1.Push \n2.Pop \n3.Display \n4.Exit\n Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: push();
                    break;
            case 2: pop();
                    break;
            case 3: display();
                    break;
            case 4: printf("Exiting...");
                    return 0;
        }
    }
    return 0;
}