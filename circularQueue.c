
#include <stdio.h>
#include <conio.h>
#define MAX 5

int q[MAX], front = -1, rear = -1;

void enqueue()
{
    int x;

    if ((rear + 1) % MAX == front)
        printf("\nQueue is Full");
    else
    {
        printf("\nEnter element: ");
        scanf("%d", &x);

        if (front == -1)
            front = rear = 0;
        else
            rear = (rear + 1) % MAX;

        q[rear] = x;

        printf("Element inserted");
    }
}

void dequeue()
{
    if (front == -1)
        printf("\nQueue is Empty");
    else
    {
        printf("\nDeleted element: %d", q[front]);

        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % MAX;
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
        i = front;

        while(1)
        {
            printf("%d ", q[i]);

            if (i == rear)
                break;

            i = (i + 1) % MAX;
        }
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
