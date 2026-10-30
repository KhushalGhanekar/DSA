
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left, *right;
};

struct node *root = NULL;

struct node* insert(struct node *r, int x)
{
    if (r == NULL)
    {
        r = (struct node *)malloc(sizeof(struct node));
        r->data = x;
        r->left = r->right = NULL;
    }
    else if (x < r->data)
        r->left = insert(r->left, x);
    else if (x > r->data)
        r->right = insert(r->right, x);

    return r;
}

struct node* minimum(struct node *r)
{
    while (r->left != NULL)
        r = r->left;

    return r;
}

struct node* deleteNode(struct node *r, int x)
{
    struct node *temp;

    if (r == NULL)
        return NULL;

    if (x < r->data)
        r->left = deleteNode(r->left, x);
    else if (x > r->data)
        r->right = deleteNode(r->right, x);
    else
    {
        if (r->left == NULL)
        {
            temp = r->right;
            free(r);
            return temp;
        }
        else if (r->right == NULL)
        {
            temp = r->left;
            free(r);
            return temp;
        }

        temp = minimum(r->right);
        r->data = temp->data;
        r->right = deleteNode(r->right, temp->data);
    }

    return r;
}

void search(struct node *r, int x)
{
    if (r == NULL)
        printf("\nElement Not Found");
    else if (r->data == x)
        printf("\nElement Found");
    else if (x < r->data)
        search(r->left, x);
    else
        search(r->right, x);
}

void inorder(struct node *r)
{
    if (r != NULL)
    {
        inorder(r->left);
        printf("%d ", r->data);
        inorder(r->right);
    }
}

void preorder(struct node *r)
{
    if (r != NULL)
    {
        printf("%d ", r->data);
        preorder(r->left);
        preorder(r->right);
    }
}

void postorder(struct node *r)
{
    if (r != NULL)
    {
        postorder(r->left);
        postorder(r->right);
        printf("%d ", r->data);
    }
}

void main()
{
    int ch, x;

    clrscr();

    do
    {
        printf("\n\n1.Insert");
        printf("\n2.Delete");
        printf("\n3.Search");
        printf("\n4.Inorder");
        printf("\n5.Preorder");
        printf("\n6.Postorder");
        printf("\n7.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                printf("\nEnter value: ");
                scanf("%d", &x);
                root = insert(root, x);
                break;

            case 2:
                printf("\nEnter value: ");
                scanf("%d", &x);
                root = deleteNode(root, x);
                break;

            case 3:
                printf("\nEnter value: ");
                scanf("%d", &x);
                search(root, x);
                break;

            case 4:
                printf("\nInorder: ");
                inorder(root);
                break;

            case 5:
                printf("\nPreorder: ");
                preorder(root);
                break;

            case 6:
                printf("\nPostorder: ");
                postorder(root);
                break;

            case 7:
                printf("\nExiting");
                break;

            default:
                printf("\nInvalid Choice");
        }

    } while(ch != 7);

    getch();
}
