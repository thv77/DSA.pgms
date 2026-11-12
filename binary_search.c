#include <stdio.h>

int main(void)
{
    int n, i, a[10], key, flag = 0;
    int j, temp, first, last, mid;

    printf("Enter the limit of the array: ");
    scanf("%d", &n);

    printf("Enter the %d elements: ", n);

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

    printf("Enter the key: ");
    scanf("%d", &key);

    first = 0;
    last = n - 1;

    while (first <= last)
    {
        mid = (first + last) / 2;

        if (a[mid] == key)
        {
            printf("The element is found in %d", mid + 1);
            flag = 1;
            break;
        }
        else if (a[mid] > key)
        {
            last = mid - 1;
        }
        else
        {
            first = mid + 1;
        }
    }

    if (flag == 0)
    {
        printf("The element is not found");
    }

    return 0;
}

