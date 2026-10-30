
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev, *next;
};

struct node *head = NULL;

void insertBeg()
{
    struct node *newnode;

    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("\nMemory not available");
        return;
    }

    printf("\nEnter data: ");
    scanf("%d", &newnode->data);

    newnode->prev = NULL;
    newnode->next = head;

    if (head != NULL)
        head->prev = newnode;

    head = newnode;
}

void insertEnd()
{
    struct node *newnode, *temp;

    newnode = (struct node *)malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("\nMemory not available");
        return;
    }

    printf("\nEnter data: ");
    scanf("%d", &newnode->data);

    newnode->next = NULL;

    if (head == NULL)
    {
        newnode->prev = NULL;
        head = newnode;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newnode;
        newnode->prev = temp;
    }
}

void deleteNode()
{
    struct node *temp;
    int x;

    printf("\nEnter value to delete: ");
    scanf("%d", &x);

    temp = head;

    while (temp != NULL && temp->data != x)
        temp = temp->next;

    if (temp == NULL)
        printf("\nElement not found");
    else
    {
        if (temp->prev != NULL)
            temp->prev->next = temp->next;
        else
            head = temp->next;

        if (temp->next != NULL)
            temp->next->prev = temp->prev;

        free(temp);
        printf("\nNode deleted");
    }
}

void display()
{
    struct node *temp, *last;

    temp = head;
    last = NULL;

    if (head == NULL)
    {
        printf("\nList is Empty");
        return;
    }

    printf("\nForward: ");

    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        last = temp;
        temp = temp->next;
    }

    printf("NULL");

    printf("\nBackward: ");

    while (last != NULL)
    {
        printf("%d <-> ", last->data);
        last = last->prev;
    }

    printf("NULL");
}

void main()
{
    int ch;

    clrscr();

    do
    {
        printf("\n\n1.Insert Beginning");
        printf("\n2.Insert End");
        printf("\n3.Delete");
        printf("\n4.Display");
        printf("\n5.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: insertBeg(); break;
            case 2: insertEnd(); break;
            case 3: deleteNode(); break;
            case 4: display(); break;
            case 5: printf("\nExiting"); break;
            default: printf("\nInvalid Choice");
        }

    } while(ch != 5);

    getch();
}
