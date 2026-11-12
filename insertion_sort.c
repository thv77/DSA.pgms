#include <stdio.h>

int main(void)
{
    int a[20], n, i, j, key, temp;

    printf("Enter the limit of the array: ");
    scanf("%d", &n);

    printf("Enter the %d elements: ", n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (i = 1; i < n; i++)
    {
        key = a[i];
        j = i - 1;

        while (j > -1 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }

        a[j + 1] = key;
    }

    printf("The sorted array is:\n");

    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }

    printf("\n");

    return 0;
}

