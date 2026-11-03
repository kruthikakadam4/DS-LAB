#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
void deletebeginning(struct Node **head)
{

    struct Node *temp;
    if(*head==NULL)
    {

        printf("Linked list is empty\n");
        return;
    }
    temp=*head;
    *head=
    (*head)->next;
    printf("Deleted %d\n",temp->data);
    free(temp);

}

void deleteend(struct Node **head)
{
  struct Node *temp,*prev;
    if(*head==NULL)
    {

        printf("Linked list is empty\n");
        return;
    }
    if( (*head)->next==NULL)
    {
        temp=*head;
        *head=NULL;
        printf("Deleted %d\n",temp->data);
        free(temp);
        return;

    }
    temp=*head;
    prev=NULL;
    while(temp->next!=NULL)
    {
        prev=temp;
        temp=temp->next;

    }
    prev->next=NULL;
    printf("Deleted %d\n",temp->data);
    free(temp);


}

void deletespecifiedele(struct Node **head,int ele)
{
   struct Node *temp,*prev;
    if(*head==NULL)
    {

        printf("Linked list is empty\n");
        return;
    }
    if((*head)->data==ele)
    {
        deletebeginning(head);
        return;
    }
    temp=*head;
    prev=NULL;
    while(temp!=NULL  && temp->data!=ele)
    {
        prev=temp;
        temp=temp->next;

    }
    if(temp==NULL)
    {
        printf("Element not found to delete\n");
        return;
    }
    prev->next=temp->next;
    printf("Deleted %d\n",temp->data);
    free(temp);
}
void createlist(struct Node **head,int n)
{
    struct Node *newnode,*temp;
    int i,value;
    for(i=1;i<=n;i++)
    {
        printf("Enter data for node%d:",i);
        scanf("%d",&value);
        newnode=(struct Node *)malloc(sizeof(struct Node));
        if(newnode==NULL)
        {
            printf("Memory allocation failed\n");
            return;
        }
        newnode->data=value;
        newnode->next=NULL;
        if(*head==NULL)
        {
            *head=newnode;

        }
        else
        {

        temp=*head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
       }
    }
}
void displaylist(struct Node *head)
{
    struct Node *temp=head;
    if(temp==NULL)
    {
        printf("Linked list is empty\n");
        return;
    }
    while(temp!=NULL)
    {
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");

}
int main()
{
    struct Node *head=NULL;
    int n,choice,ele;
    printf("Enter number of nodes:");
    scanf("%d",&n);
    if(n<0)
    {
        printf("Invalid number of nodes\n");
        return 1;
    }
    createlist(&head,n);
    printf("\nOriginal linked list:");
    displaylist(head);
    printf("\n1.Delete from beginning\n2.Delete specified element\n3.Delete from the end\n4.Display\n5.Exit\n");
    while(1)
    {
        printf("\nEnter a choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:deletebeginning(&head);
                   break;
            case 2:printf("Enter element to delete:");
                   scanf("%d",&ele);
                   deletespecifiedele(&head,ele);
                   break;
            case 3:deleteend(&head);
                   break;
            case 4:printf("Linked list:");
                   displaylist(head);
                   break;
            case 5:printf("Exiting...\n");
                   return 0;
            default:printf("Invalid choice.\n");

        }
    }
    return 0;
}


