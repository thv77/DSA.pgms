/* Linear Search in C
 * Searches for a key in an array and reports every matching position.
 */
#include <stdio.h>

int main(void)
{
    int n, i, key, found = 0;
    int a[10];

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

    printf("Enter the key: ");
    if (scanf("%d", &key) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    for (i = 0; i < n; i++) {
        if (a[i] == key) {
            printf("%d is found at position %d\n", key, i + 1);
            found = 1;
        }
    }

    if (!found) {
        printf("%d is not found.\n", key);
    }

    return 0;
}
