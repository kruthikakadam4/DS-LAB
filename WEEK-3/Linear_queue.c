#include<stdio.h>
#define max 4
int q[max];
int front=-1;
int rear=-1;
void insert()
{
    int ele;
    if(rear==max-1)
    {
        printf("Queue overflow\n");
        return;
    }
    else
    {
        printf("Enter an element:");
        scanf("%d",&ele);
        if(front==-1)
            front=0;
        rear=rear+1;
        q[rear]=ele;
    }

printf("%d inserted into queue\n",ele);

}
int delete()
{
  int ele;
  if(front==-1||front>rear)
    {
    printf("Queue underflow\n");
    return -1;
    }
  else
    {
        ele=q[front];
        front=front+1;
    }
    printf("%d deleted from queue\n",ele);
}
void display()
{
  int i;
  if(front==-1||front>rear)
  {
    printf("Queue empty\n");
    return;
  }
  else
    {
        printf("Queue elements are:");
        for(i=front;i<=rear;i++)
        {
            printf("%d ",q[i]);
        }
        printf("\n");

   }
}
int main()
{
    int ch;
    printf("Queue menu:\n1.Insert\n2.Delete\n3.Display\n4.Exit\n");
    while(1)
    {
      printf("Enter your choice:");
      scanf("%d",&ch);
      switch(ch)
      {
      case 1:insert();
        break;
      case 2:delete();
        break;
      case 3:display();
        break;
      case 4:printf("Exiting...");
             return 0;
      default:printf("Invalid choice.\n");
      }
    }
    return 0;
}


