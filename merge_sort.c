#include <stdio.h>
#define MAX 100
int temp[MAX];
void merge(int a[],int l,int m,int r){int i=l,j=m+1,k=l;while(i<=m&&j<=r)temp[k++]=(a[i]<=a[j])?a[i++]:a[j++];while(i<=m)temp[k++]=a[i++];while(j<=r)temp[k++]=a[j++];for(i=l;i<=r;i++)a[i]=temp[i];}
void mergesort(int a[],int l,int r){if(l<r){int m=l+(r-l)/2;mergesort(a,l,m);mergesort(a,m+1,r);merge(a,l,m,r);}}
int main(void){int a[MAX],n,i;printf("Enter array size (1-%d): ",MAX);if(scanf("%d",&n)!=1||n<1||n>MAX)return 1;printf("Enter elements: ");for(i=0;i<n;i++)scanf("%d",&a[i]);mergesort(a,0,n-1);printf("Sorted array: ");for(i=0;i<n;i++)printf("%d ",a[i]);puts("");return 0;}