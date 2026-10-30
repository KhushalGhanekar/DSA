
#include <stdio.h>
#include <conio.h>
#define MAX 5

int q[MAX], front = -1, rear = -1;

void enqueue()
{
    int x;

    if (rear == MAX - 1)
        printf("\nQueue Overflow");
    else
    {
        printf("\nEnter element: ");
        scanf("%d", &x);

        if (front == -1)
            front = 0;

        rear++;
        q[rear] = x;

        printf("Element inserted");
    }
}

void dequeue()
{
    if (front == -1)
        printf("\nQueue Underflow");
    else
    {
        printf("\nDeleted element: %d", q[front]);

        if (front == rear)
            front = rear = -1;
        else
            front++;
    }
}

void display()
{
    int i;

    if (front == -1)
        printf("\nQueue is Empty");
    else
    {
        printf("\nQueue elements: ");

        for (i = front; i <= rear; i++)
            printf("%d ", q[i]);
    }
}

void main()
{
    int ch;

    clrscr();

    do
    {
        printf("\n\n1.Enqueue");
        printf("\n2.Dequeue");
        printf("\n3.Display");
        printf("\n4.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: printf("\nExiting"); break;
            default: printf("\nInvalid Choice");
        }

    } while(ch != 4);

    getch();
}
