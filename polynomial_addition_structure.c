#include <stdio.h>
#define MAX 10
struct term { int coeff, exp; };
int main(void) {
    struct term a[MAX], b[MAX], c[2*MAX];
    int n, m, i=0, j=0, k=0;
    printf("Number of terms in first polynomial (1-%d): ", MAX);
    if (scanf("%d",&n)!=1 || n<1 || n>MAX) return 1;
    printf("Enter coefficient and exponent for each term in descending exponent order:\n");
    for (i=0;i<n;i++) scanf("%d%d",&a[i].coeff,&a[i].exp);
    printf("Number of terms in second polynomial (1-%d): ", MAX);
    if (scanf("%d",&m)!=1 || m<1 || m>MAX) return 1;
    printf("Enter coefficient and exponent for each term in descending exponent order:\n");
    for (i=0;i<m;i++) scanf("%d%d",&b[i].coeff,&b[i].exp);
    i=0; j=0;
    while (i<n && j<m) {
        if (a[i].exp==b[j].exp) { c[k]=(struct term){a[i].coeff+b[j].coeff,a[i].exp}; i++; j++; }
        else if (a[i].exp>b[j].exp) c[k++]=a[i++];
        else c[k++]=b[j++];
        if (i<=n && j<=m && k<2*MAX && (i==n || j==m || a[i].exp!=b[j].exp)) { /* append handled below */ }
        if (k<2*MAX && (k==0 || c[k-1].exp!=c[k].exp)) k++;
    }
    while (i<n) c[k++]=a[i++];
    while (j<m) c[k++]=b[j++];
    printf("Sum: ");
    for (i=0;i<k;i++) if (c[i].coeff) printf("%dx^%d%s",c[i].coeff,c[i].exp,i==k-1?"":" + ");
    printf("\n");
    return 0;
}