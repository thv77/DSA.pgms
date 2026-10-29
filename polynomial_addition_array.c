#include <stdio.h>
int main(void) {
    int n, i, a[10], b[10], c[10];
    printf("Enter the highest order of the polynomials (0-9): ");
    if (scanf("%d", &n) != 1 || n < 0 || n > 9) return 1;
    printf("Enter coefficients of first polynomial, highest power first: ");
    for (i=0; i<=n; i++) scanf("%d", &a[i]);
    printf("Enter coefficients of second polynomial, highest power first: ");
    for (i=0; i<=n; i++) scanf("%d", &b[i]);
    for (i=0; i<=n; i++) c[i]=a[i]+b[i];
    printf("Result: ");
    for (i=0; i<=n; i++) {
        printf("%dx^%d", c[i], n-i);
        if (i<n) printf(" + ");
    }
    printf("\n");
    return 0;
}