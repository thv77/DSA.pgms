#include <stdio.h>

#define MAX_SIZE 100

int main(void)
{
    int a[MAX_SIZE], n, i, j, min_index, temp;

    printf("Enter array size (1-%d): ", MAX_SIZE);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_SIZE) {
        printf("Invalid array size.\n");
        return 1;
    }

    printf("Enter elements: ");
    for (i = 0; i < n; i++) {
        if (scanf("%d", &a[i]) != 1)
            return 1;
    }

    for (i = 0; i < n - 1; i++) {
        min_index = i;

        for (j = i + 1; j < n; j++) {
            if (a[j] < a[min_index])
                min_index = j;
        }

        temp = a[i];
        a[i] = a[min_index];
        a[min_index] = temp;
    }

    printf("Sorted array: ");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);

    printf("\n");
    return 0;
}
