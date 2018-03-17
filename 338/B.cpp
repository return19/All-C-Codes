#include<bits/stdc++.h>
using namespace std;

long long n,m;
vector< vector<long long> > adj(101000);
long long vis[101000];
long long done[101000],dist[101000];

long long mx=INT_MIN;

void dfs(long long x,long long sz)
{
    vis[x]=1;
    done[x]=1;
    long long i,j,k;
    sz++;

    mx=max(mx,sz*adj[x].size());

    for(i=0;i<adj[x].size();i++)
    {
        if(!vis[adj[x][i]] && adj[x][i]>x){
            dfs(adj[x][i],sz);
        }

    }
    vis[x]=0;
}

int main()
{
    long long i,j,k;
    long long x,y;
    scanf("%lld%lld",&n,&m);


    for(i=0;i<m;i++)
    {
        scanf("%lld%lld",&x,&y);
        x--;
        y--;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    long long ans=0;

    for(i=0;i<n;i++)
    {
        for(j=0;j<adj[i].size();j++)
        {
            if(adj[i][j]>i && dist[adj[i][j]]<dist[i]+1)
                dist[adj[i][j]]=dist[i]+1;
        }
    }

    for(i=0;i<n;i++)
    {
        ans=max(ans,(dist[i]+1)*adj[i].size());
    }

    printf("%lld\n",ans);

    return 0;
}
