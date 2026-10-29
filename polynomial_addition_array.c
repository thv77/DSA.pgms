#include <stdio.h>

#define MAX_ORDER 9

int main(void)
{
    int first[MAX_ORDER + 1];
    int second[MAX_ORDER + 1];
    int sum[MAX_ORDER + 1];
    int order, i;

    printf("Enter the highest polynomial order (0-%d): ", MAX_ORDER);
    if (scanf("%d", &order) != 1 || order < 0 || order > MAX_ORDER) {
        printf("Invalid polynomial order.\n");
        return 1;
    }

    printf("Enter coefficients of the first polynomial, highest power first: ");
    for (i = 0; i <= order; i++) {
        if (scanf("%d", &first[i]) != 1)
            return 1;
    }

    printf("Enter coefficients of the second polynomial, highest power first: ");
    for (i = 0; i <= order; i++) {
        if (scanf("%d", &second[i]) != 1)
            return 1;
    }

    for (i = 0; i <= order; i++)
        sum[i] = first[i] + second[i];

    printf("Sum: ");
    for (i = 0; i <= order; i++) {
        printf("%dx^%d", sum[i], order - i);
        if (i < order)
            printf(" + ");
    }

    printf("\n");
    return 0;
}
