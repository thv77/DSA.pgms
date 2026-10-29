#include <stdio.h>
#define MAX 10
int main(void) {
    int a[MAX][MAX],q[MAX],visited[MAX]={0},n,start,i,j,front=0,rear=0,v;
    printf("Number of vertices (1-10): ");if(scanf("%d",&n)!=1||n<1||n>MAX)return 1;
    printf("Enter adjacency matrix:\n");for(i=0;i<n;i++)for(j=0;j<n;j++)scanf("%d",&a[i][j]);
    printf("Starting vertex (0-%d): ",n-1);if(scanf("%d",&start)!=1||start<0||start>=n)return 1;
    q[rear++]=start;visited[start]=1;printf("BFS: ");
    while(front<rear){v=q[front++];printf("%d ",v);for(i=0;i<n;i++)if(a[v][i]&&!visited[i]){q[rear++]=i;visited[i]=1;}}
    puts("");return 0;
}