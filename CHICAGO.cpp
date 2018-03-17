#include<bits/stdc++.h>
using namespace std;

#define INT_MAX1 -10

double graph[210][210];

double dist[210];

int visited[210];

int n;

void dijkstra()
{
    int i,j,k;
    double max1;
    int max1_index;
    int u,v;

    memset(dist,INT_MAX1,sizeof(dist));
    memset(visited,0,sizeof(visited));

    dist[0]=1;

    for(i=0;i<n-1;i++)
    {
        max1=INT_MAX1;
        for(j=0;j<n;j++)
        {
            if(!visited[j]&&max1<dist[j])
            {
                max1=dist[j];
                max1_index=j;
            }
        }

        u=max1_index;

        visited[u]=1;

        for(j=0;j<n;j++)
        {
            if(!visited[j]&&graph[j][u]&&u!=INT_MAX1&&graph[j][u]*dist[u]>dist[j])
            {
                dist[j]=dist[u]*graph[j][u];
            }
        }
    }

}

int main()
{
    int m,i,j,k;
    double ans;
    int temp1,temp2,pr;


    scanf("%d",&n);

    while(n!=0){

            memset(graph,0,sizeof(graph));

        scanf("%d",&m);

        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&temp1,&temp2,&pr);

            temp1--;
            temp2--;

            graph[temp1][temp2]=(double)pr/100;
            graph[temp2][temp1]=(double)pr/100;
        }

        dijkstra();

       /* for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
                printf("%lf ",graph[i][j]);
            cout<<endl;
        }

        for(i=0;i<n;i++)
        {
            printf("%lf ",dist[i]);
        }*/

        printf("%.6lf percent\n",dist[n-1]*100);

        scanf("%d",&n);

    }

    return 0;
}
