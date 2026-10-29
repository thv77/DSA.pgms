#include <stdio.h>
int main(void) {
    int a[100],n,i,j,key,temp,low,high,mid;
    printf("Enter array size (1-100): ");
    if(scanf("%d",&n)!=1||n<1||n>100)return 1;
    printf("Enter elements: "); for(i=0;i<n;i++)scanf("%d",&a[i]);
    for(i=0;i<n-1;i++)for(j=0;j<n-i-1;j++)if(a[j]>a[j+1]){temp=a[j];a[j]=a[j+1];a[j+1]=temp;}
    printf("Enter key to search: ");if(scanf("%d",&key)!=1)return 1;
    low=0;high=n-1;
    while(low<=high){mid=low+(high-low)/2;if(a[mid]==key){printf("Element found at position %d in sorted array\n",mid+1);return 0;}if(a[mid]<key)low=mid+1;else high=mid-1;}
    puts("Element not found");return 0;
}