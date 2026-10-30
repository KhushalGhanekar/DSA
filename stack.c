
#include <stdio.h>
#include <conio.h>
#define MAX 5

int stack[MAX], top = -1;

void push()
{
    int x;

    if (top == MAX - 1)
        printf("\nStack Overflow");
    else
    {
        printf("\nEnter element: ");
        scanf("%d", &x);
        top++;
        stack[top] = x;
        printf("Element inserted");
    }
}

void pop()
{
    if (top == -1)
        printf("\nStack Underflow");
    else
    {
        printf("\nDeleted element: %d", stack[top]);
        top--;
    }
}

void peek()
{
    if (top == -1)
        printf("\nStack is Empty");
    else
        printf("\nTop element: %d", stack[top]);
}

void display()
{
    int i;

    if (top == -1)
        printf("\nStack is Empty");
    else
    {
        printf("\nStack elements: ");

        for (i = top; i >= 0; i--)
            printf("%d ", stack[i]);
    }
}

void main()
{
    int ch;

    clrscr();

    do
    {
        printf("\n\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Peek");
        printf("\n4.Display");
        printf("\n5.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: printf("\nExiting"); break;
            default: printf("\nInvalid Choice");
        }

    } while(ch != 5);

    getch();
}
