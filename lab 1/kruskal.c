#include<stdio.h>
#define MAX 10

int parent[MAX];

int find(int i)
{
    while(parent[i])
        i = parent[i];
    return i;
}

int uni(int i,int j)
{
    if(i!=j)
    {
        parent[j]=i;
        return 1;
    }
    return 0;
}

int main()
{
    int n,i,j;
    int cost[MAX][MAX];
    int mincost=0;
    int ne=1,a,b,u,v,min;

    printf("Enter number of vertices: ");
    scanf("%d",&n);

    printf("Enter cost matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)
                cost[i][j]=999;
        }
    }

    printf("\nEdges in MST:\n");

    while(ne < n)
    {
        min=999;

        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(cost[i][j] < min)
                {
                    min = cost[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        }

        u = find(u);
        v = find(v);

        if(uni(u,v))
        {
            printf("%d edge (%d -> %d) = %d\n",ne++,a,b,min);
            mincost += min;
        }

        cost[a][b]=cost[b][a]=999;
    }

    printf("\nMinimum cost = %d\n",mincost);

    return 0;
}
