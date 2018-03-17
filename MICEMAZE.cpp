#include<bits/stdc++.h>
using namespace std;

int n,e,t,m;

int graph[110][110];

int dist[110];

int vis[110];

int main()
{
    int i,j,k;
    int x,y,z;

    scanf("%d%d%d%d",&n,&e,&t,&m);

    e--;

    for(i=0;i<m;i++)
    {
        scanf("%d%d%d",&x,&y,&z);

        x--;
        y--;

        if(graph[x][y]==0)
            graph[x][y]=z;
        else
            graph[x][y]=min(graph[x][y],z);
    }

    for(i=0;i<n;i++)
        dist[i]=INT_MAX;

    dist[e]=0;

    int mn=INT_MAX;
    int mn_idx;

    for(i=0;i<n;i++)
    {
        mn=INT_MAX;

        for(j=0;j<n;j++)
        {
            if(mn>dist[j] && !vis[j])
            {
                mn=dist[j];
                mn_idx=j;
            }
        }

        if(mn==INT_MAX)
            break;

        vis[mn_idx]=1;

        for(j=0;j<n;j++)
        {
            if(!vis[j] && graph[j][mn_idx] &&dist[j]>dist[mn_idx] + graph[j][mn_idx])
            {
                dist[j]=dist[mn_idx] + graph[j][mn_idx];
            }
        }
    }

    int ans=0;

    for(i=0;i<n;i++)
    {
        if(dist[i]<=t)
            ans++;
    }

    printf("%d\n",ans);

    return 0;
}












