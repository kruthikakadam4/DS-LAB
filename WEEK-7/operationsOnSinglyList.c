#include<stdio.h>
#include<stdlib.h>

struct node{
int data;
struct node *next;
};

void create(struct node **head)
{
    struct node *newNode, *temp;
    int i,n,value;
    printf("Enter the number of nodes:");
    scanf("%d",&n);
    for (i = 1; i <= n; i++)
    {
        printf("Enter data for node %d: ", i);
        scanf("%d", &value);
        newNode = (struct node *)malloc(sizeof(struct node));
        if (newNode == NULL)
        {
            printf("Memory allocation failed!\n");
            return;
        }
        newNode->data = value;
        newNode->next = NULL;
        if (*head == NULL)
        {
            *head = newNode;
        }
        else
        {
            temp = *head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}

struct node* concat(struct node *head1,struct node *head2)
{
    struct node *temp;
    if(head1==NULL)
        return head2;
    if(head2==NULL)
        return head2;
    temp=head1;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=head2;
    return head1;

}

struct node* rev(struct node *head)
{
    struct node *prev=NULL;
    struct node *current=head;
    struct node *next;
    while(current!=NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    return prev;
}

struct node* sort(struct node *head)
{
  struct node *temp,*current;
  int swap;
  if(head==NULL)
    return head;

  for(temp=head;temp->next!=NULL;temp=temp->next)
  {
      for(current=temp->next;current!=NULL;current=current->next)
      {
          if(temp->data>current->data)
          {
              swap=temp->data;
              temp->data=current->data;
              current->data=swap;
          }
      }
  }
  return head;

}

void display(struct node *head)
{
    struct node *temp=head;
    if(temp==NULL)
    {
        printf("Queue empty\n" );
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
    struct node *head1=NULL;
    struct node *head2=NULL;
    int ch;
    printf("Create list 1:\n");
    create(&head1);
    display(head1);
    printf("Create list 2:\n");
    create(&head2);
    display(head2);
    printf("1.concatenate\n2.reverse\n3.sort\n4.Exit\n");
    while(1)
    {
        printf("\nEnter a choice:");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:head1=concat(head1,head2);
               printf("Concatenated list:");
               display(head1);
               break;
        case 2:head1=rev(head1);
               printf("Reversed list:");
               display(head1);
               break;
        case 3:head1=sort(head1);
               printf("Sorted list:");
               display(head1);
               break;
        case 4:printf("Exiting...");
               return 0;
        default:printf("Invalid choice\n");
        }
    }
    return 0;
}




