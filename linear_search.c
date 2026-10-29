#include <stdio.h>

#define MAX_SIZE 100

int main(void)
{
    int a[MAX_SIZE], n, i, key;

    printf("Enter array size (1-%d): ", MAX_SIZE);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_SIZE) {
        printf("Invalid array size.\n");
        return 1;
    }

    printf("Enter %d elements: ", n);
    for (i = 0; i < n; i++) {
        if (scanf("%d", &a[i]) != 1)
            return 1;
    }

    printf("Enter value to search: ");
    if (scanf("%d", &key) != 1)
        return 1;

    for (i = 0; i < n; i++) {
        if (a[i] == key) {
            printf("%d found at position %d.\n", key, i + 1);
            return 0;
        }
    }

    printf("%d not found.\n", key);
    return 0;
}
