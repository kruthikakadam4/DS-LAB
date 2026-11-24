#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *next;
};

struct node *top=NULL;

void push(int ele)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    if (newnode==NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newnode->data=ele;
    newnode->next=top;
    top=newnode;
    printf("%d pushed\n",ele);
}

void pop()
{
    struct node *temp;
    if(top==NULL)
    {
        printf("Stack underflow\n" );
        return;
    }
    temp=top;
    top=top->next;
    printf("%d popped\n",temp->data);
    free(temp);
}

void display()
{
    struct node *temp=top;
    if(temp==NULL)
    {
        printf("Stack empty\n" );
        return;
    }
    printf("Stack elements are:");
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main()
{
    int ch,ele;
    printf("1.Push\n2.Pop\n3.Display\n4.Exit\n");
    while(1)
    {
        printf("\nEnter a choice:");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:printf("Enter an element:");
               scanf("%d",&ele);
               push(ele);
               break;
        case 2:pop();
               break;
        case 3:display();
               break;
        case 4:printf("Exiting...");
               return 0;
        default:printf("Invalid choice\n");
        }
    }
    return 0;
}
