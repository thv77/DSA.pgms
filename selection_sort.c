#include <stdio.h>

int main(void)
{
    int a[20], i, j, loc, min, n, temp;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter the %d elements: ", n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n; i++)
    {
        min = a[i];
        loc = i;

        for (j = i + 1; j < n; j++)
        {
            if (a[j] < min)
            {
                min = a[j];
                loc = j;
            }
        }

        temp = a[i];
        a[i] = min;
        a[loc] = temp;
    }

    printf("The sorted array is:\n");

    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }

    printf("\n");

    return 0;
}

