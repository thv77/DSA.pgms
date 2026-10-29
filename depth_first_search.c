#include <stdio.h>
#define MAX 10
int main(void) {
    int a[MAX][MAX],stack[MAX],visited[MAX]={0},n,start,i,j,top=-1,v;
    printf("Number of vertices (1-10): ");if(scanf("%d",&n)!=1||n<1||n>MAX)return 1;
    printf("Enter adjacency matrix:\n");for(i=0;i<n;i++)for(j=0;j<n;j++)scanf("%d",&a[i][j]);
    printf("Starting vertex (0-%d): ",n-1);if(scanf("%d",&start)!=1||start<0||start>=n)return 1;
    stack[++top]=start;visited[start]=1;printf("DFS: ");
    while(top>=0){v=stack[top--];printf("%d ",v);for(i=n-1;i>=0;i--)if(a[v][i]&&!visited[i]){stack[++top]=i;visited[i]=1;}}
    puts("");return 0;
}