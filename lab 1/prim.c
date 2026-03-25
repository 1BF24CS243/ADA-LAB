#include<stdio.h>
#define INF 999

int main()
{
    int n,i,j;
    int cost[10][10];
    int visited[10]={0};
    int min,a,b,u,v,ne=1,mincost=0;

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    printf("Enter cost matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
                cost[i][j]=INF;
        }
    }

    visited[0]=1;

    printf("\nEdges in MST:\n");

    while(ne < n)
    {
        min=INF;

        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(cost[i][j] < min)
                {
                    if(visited[i] != 0)
                    {
                        min = cost[i][j];
                        a=u=i;
                        b=v=j;
                    }
                }
            }
        }

        if(visited[u]==0 || visited[v]==0)
        {
            printf("%d edge (%d -> %d) = %d\n",ne++,a,b,min);
            mincost += min;
            visited[b]=1;
        }

        cost[a][b]=cost[b][a]=INF;
    }

    printf("\nMinimum cost = %d\n",mincost);

    return 0;
}
