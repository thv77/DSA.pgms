#include <stdio.h>
int main(void) {
    int a[100],n,i,j,key;
    printf("Enter array size (1-100): ");if(scanf("%d",&n)!=1||n<1||n>100)return 1;
    printf("Enter elements: ");for(i=0;i<n;i++)scanf("%d",&a[i]);
    for(i=1;i<n;i++){key=a[i];j=i-1;while(j>=0&&a[j]>key){a[j+1]=a[j];j--;}a[j+1]=key;}
    printf("Sorted array: ");for(i=0;i<n;i++)printf("%d ",a[i]);puts("");return 0;
}