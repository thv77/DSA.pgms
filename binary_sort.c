#include <stdio.h>
int main(void) {
    int a[100], n, i, j, temp;
    printf("Enter the size of array: ");
    if (scanf("%d", &n) != 1 || n < 1 || n > 100) return 1;
    printf("Enter the elements: ");
    for (i=0; i<n; i++) scanf("%d", &a[i]);
    for (i=0; i<n-1; i++)
        for (j=0; j<n-i-1; j++)
            if (a[j] > a[j+1]) { temp=a[j]; a[j]=a[j+1]; a[j+1]=temp; }
    printf("The sorted array: ");
    for (i=0; i<n; i++) printf("%d\t", a[i]);
    printf("\n");
    return 0;
}