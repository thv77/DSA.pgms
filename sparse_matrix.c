#include <stdio.h>
int main(void) {
    int a[10][10], triplet[101][3], rows, cols, i, j, count=0, k=1;
    printf("Enter rows and columns (max 10 each): ");
    if (scanf("%d%d",&rows,&cols)!=2 || rows<1 || rows>10 || cols<1 || cols>10) return 1;
    printf("Enter matrix elements:\n");
    for (i=0;i<rows;i++) for (j=0;j<cols;j++) scanf("%d",&a[i][j]);
    for (i=0;i<rows;i++) for (j=0;j<cols;j++) if (a[i][j]!=0) count++;
    triplet[0][0]=rows; triplet[0][1]=cols; triplet[0][2]=count;
    for (i=0;i<rows;i++) for (j=0;j<cols;j++) if (a[i][j]!=0) {
        triplet[k][0]=i; triplet[k][1]=j; triplet[k][2]=a[i][j]; k++;
    }
    printf("Triplet representation (row\tcolumn\tvalue):\n");
    for (i=0;i<=count;i++) printf("%d\t%d\t%d\n",triplet[i][0],triplet[i][1],triplet[i][2]);
    return 0;
}