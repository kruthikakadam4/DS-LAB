
#include <stdio.h>
#define max 4
int queue[max];
int front = -1, rear = -1;
void enqueue()
{
    int num;
    if ((front == rear + 1) || (front == 0 && rear == max - 1))
    {
        printf("Queue Overflow\n");
        return;
    }
    printf("Enter an element:");
    scanf("%d", &num);
    if (front == -1 && rear == -1)
        front = rear = 0;
    else if (rear == max - 1 && front != 0)
        rear = 0;
    else
        rear++;
    queue[rear] = num;
}
void dequeue()
{
    int num;
    if (front == -1)
    {
        printf("Queue Underflow\n");
        return;
    }
    num = queue[front];
    printf("%d deleted\n", num);
    if (front == rear)
        front = rear = -1;
    else if (front == max - 1)
        front = 0;
    else
        front++;
}
void display()
{
    int i;
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are:\n");
    for (i = front; i != rear; i = (i + 1) % max)
    {
        printf("%d ", queue[i]);
    }
    printf("%d\n", queue[rear]);
}
int main()
{
    int ch;
    printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
    while (1)
    {
        printf("Enter your choice:");
        scanf("%d", &ch);
        switch (ch)
        {
            case 1:enqueue();
            break;
             case 2:dequeue();
             break;
            case 3:display();
            break;
            case 4:printf("Exiting...\n");
            return 0;
            default:printf("Invalid choice\n");
        }
    }
    return 0;
}
