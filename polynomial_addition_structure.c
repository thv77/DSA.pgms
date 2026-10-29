#include <stdio.h>

#define MAX_TERMS 20

typedef struct {
    int coefficient;
    int exponent;
} Term;

int read_polynomial(Term p[], const char *label)
{
    int n, i;
    printf("Number of terms in %s (1-%d): ", label, MAX_TERMS);
    if (scanf("%d", &n) != 1 || n < 1 || n > MAX_TERMS)
        return -1;

    printf("Enter each coefficient and exponent in descending exponent order:\n");
    for (i = 0; i < n; i++) {
        if (scanf("%d%d", &p[i].coefficient, &p[i].exponent) != 2)
            return -1;
        if (i > 0 && p[i].exponent >= p[i - 1].exponent) {
            printf("Exponents must be in strictly descending order.\n");
            return -1;
        }
    }
    return n;
}

int main(void)
{
    Term a[MAX_TERMS], b[MAX_TERMS], sum[2 * MAX_TERMS];
    int n, m, i = 0, j = 0, k = 0, first = 1;

    n = read_polynomial(a, "the first polynomial");
    if (n < 0) {
        printf("Invalid input.\n");
        return 1;
    }
    m = read_polynomial(b, "the second polynomial");
    if (m < 0) {
        printf("Invalid input.\n");
        return 1;
    }

    while (i < n && j < m) {
        if (a[i].exponent == b[j].exponent) {
            int coefficient = a[i].coefficient + b[j].coefficient;
            if (coefficient != 0) {
                sum[k].coefficient = coefficient;
                sum[k++].exponent = a[i].exponent;
            }
            i++;
            j++;
        } else if (a[i].exponent > b[j].exponent) {
            sum[k++] = a[i++];
        } else {
            sum[k++] = b[j++];
        }
    }
    while (i < n) sum[k++] = a[i++];
    while (j < m) sum[k++] = b[j++];

    printf("Sum: ");
    for (i = 0; i < k; i++) {
        if (sum[i].coefficient == 0)
            continue;
        if (!first && sum[i].coefficient > 0)
            printf(" + ");
        else if (!first)
            printf(" - ");
        else if (sum[i].coefficient < 0)
            printf("-");
        printf("%dx^%d", sum[i].coefficient < 0 ? -sum[i].coefficient : sum[i].coefficient,
               sum[i].exponent);
        first = 0;
    }
    if (first)
        printf("0");
    printf("\n");
    return 0;
}
