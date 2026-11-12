#include <stdio.h>

int main(void)
{
    int n, i, j, a[10], key, temp;
    int first, last, mid, flag = 0;

    printf("Enter the limit of the array (1-10): ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 10) {
        printf("Invalid array size.\n");
        return 1;
    }

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        if (scanf("%d", &a[i]) != 1) {
            printf("Invalid input.\n");
            return 1;
        }
    }

    /* Sort the array using bubble sort */
    for (j = 1; j < n; j++) {
        for (i = 0; i < n - j; i++) {
            if (a[i] > a[i + 1]) {
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
    }

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    printf("\nEnter the element to search: ");
    if (scanf("%d", &key) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    /* Binary search */
    first = 0;
    last = n - 1;

    while (first <= last) {
        mid = (first + last) / 2;

        if (a[mid] == key) {
            printf("Element found at position %d.\n", mid + 1);
            flag = 1;
            break;
        } else if (a[mid] > key) {
            last = mid - 1;
        } else {
            first = mid + 1;
        }
    }

    if (flag == 0) {
        printf("Element not found.\n");
    }

    return 0;
}
