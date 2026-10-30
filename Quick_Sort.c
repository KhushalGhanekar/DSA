
#include <stdio.h>
#include <conio.h>

int a[100], n;

void quickSort(int low, int high)
{
    int pivot, i, j, temp;

    if (low < high)
    {
        pivot = a[high];
        i = low - 1;

        for (j = low; j < high; j++)
        {
            if (a[j] <= pivot)
            {
                i++;

                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }

        temp = a[i+1];
        a[i+1] = a[high];
        a[high] = temp;

        quickSort(low, i);
        quickSort(i+2, high);
    }
}

void display()
{
    int i;

    printf("\nArray: ");

    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
}

void main()
{
    int ch, i;

    clrscr();

    n = 0;

    do
    {
        printf("\n\n1.Enter Elements");
        printf("\n2.Quick Sort");
        printf("\n3.Display");
        printf("\n4.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1:
                printf("\nEnter number of elements: ");
                scanf("%d", &n);

                if (n <= 0 || n > 100)
                {
                    printf("\nInvalid Size");
                    n = 0;
                }
                else
                {
                    printf("\nEnter elements:\n");

                    for (i = 0; i < n; i++)
                        scanf("%d", &a[i]);
                }
                break;

            case 2:
                if (n == 0)
                    printf("\nEnter Elements First");
                else
                {
                    quickSort(0, n-1);
                    printf("\nArray Sorted Successfully");
                }
                break;

            case 3:
                if (n == 0)
                    printf("\nArray is Empty");
                else
                    display();
                break;

            case 4:
                printf("\nExiting");
                break;

            default:
                printf("\nInvalid Choice");
        }

    } while(ch != 4);

    getch();
}
