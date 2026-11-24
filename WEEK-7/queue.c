
#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *next;
};

struct node *front=NULL;
struct node *rear=NULL;

void enqueue(int ele)
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    if (newnode==NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newnode->data=ele;
    newnode->next=NULL;
    if(rear==NULL)
    {
        front=newnode;
        rear=newnode;
    }
    else
    {
      rear->next=newnode;
      rear=newnode;

    }
    printf("%d inserted\n",ele);
}

void dequeue()
{
    struct node *temp;
    if(front==NULL)
    {
        printf("Queue underflow\n" );
        return;
    }
    temp=front;
    front=front->next;
    if(front==NULL)
    {
     rear=NULL;
    }
    printf("%d deleted\n",temp->data);
    free(temp);
}

void display()
{
    struct node *temp=front;
    if(temp==NULL)
    {
        printf("Queue empty\n" );
        return;
    }
    printf("Queue elements are:");
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
    printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
    while(1)
    {
        printf("\nEnter a choice:");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:printf("Enter an element:");
               scanf("%d",&ele);
               enqueue(ele);
               break;
        case 2:dequeue();
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
