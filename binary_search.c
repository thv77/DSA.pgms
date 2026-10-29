/* Binary search on an ascending sorted array. */
#include <stdio.h>

#define MAX_SIZE 100

int main(void)
{
    int a[MAX_SIZE], n, i, key, low, high, mid;

    printf("Enter array size (1-%d): ", MAX_SIZE);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_SIZE) {
        printf("Invalid array size.\n");
        return 1;
    }

    printf("Enter %d elements in ascending order: ", n);
    for (i = 0; i < n; i++) {
        if (scanf("%d", &a[i]) != 1)
            return 1;
        if (i > 0 && a[i] < a[i - 1]) {
            printf("Elements must be in ascending order.\n");
            return 1;
        }
    }

    printf("Enter value to search: ");
    if (scanf("%d", &key) != 1)
        return 1;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = low + (high - low) / 2;
        if (a[mid] == key) {
            printf("%d found at position %d.\n", key, mid + 1);
            return 0;
        }
        if (a[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    printf("%d not found.\n", key);
    return 0;
}
