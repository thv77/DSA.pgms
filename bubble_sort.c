#include <stdio.h>

void main()
{
    int n, a[100], i, j, temp;

    printf("enter the limit:");
    scanf("%d", &n);

    printf("enter the %d numbers:", n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    for (j = 1; j < n; j++)
    {
        for (i = 0; i < n - j; i++)
        {
            if (a[i] > a[i + 1])
            {
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
    }

    printf("The sorted array is:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
}
