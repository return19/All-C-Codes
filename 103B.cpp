#include<bits/stdc++.h>
using namespace std;

int n,m;

vector< vector<int> > adj(110);

int vis[110];

int f=1;

void dfs(int x,int p)
{
    int i,j,k;

    vis[x]=1;

    for(i=0;i<adj[x].size();i++)
    {
        if(adj[x][i]==p)
            continue;

        if(vis[adj[x][i]]==1)
        {
           // cout<<"here"<<x<<" "<<p<<" "<<adj[x][i]<<endl;
            f--;
            continue;
        }

        dfs(adj[x][i],x);
    }
}

int main()
{
    int i,j,k;
    int x,y;

    scanf("%d%d",&n,&m);

    for(i=0;i<m;i++)
    {
        scanf("%d%d",&x,&y);

        x--;    y--;

        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    f=2;

    dfs(0,-1);

    if(f!=0)
    {
        printf("NO\n");
        return 0;
    }

    for(i=0;i<n;i++)
        if(vis[i]==0)
        {
            printf("NO\n");
            return 0;
        }

    printf("FHTAGN!\n");

    return 0;
}










