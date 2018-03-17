#include<bits/stdc++.h>
using namespace std;

int n,m;

vector< vector<int> > adj(100100);
vector< vector<int> > rev(100100);

int vis[101000];
int cnt=1;
vector< vector<int> > scc(101000);

stack<int> s;

int ans[101000];

void dfs(int x)
{
    vis[x]=1;
    int i;
    for(i=0;i<adj[x].size();i++)
    {
        if(!vis[adj[x][i]])
            dfs(adj[x][i]);
    }

    s.push(x);
}

void dfs2(int x)
{
    vis[x]=1;
    scc[cnt].push_back(x);
    int i;

    for(i=0;i<rev[x].size();i++)
    {
        if(!vis[rev[x][i]])
            dfs2(rev[x][i]);
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
        x--;
        y--;
        adj[x].push_back(y);
        rev[y].push_back(x);
    }

    for(i=0;i<n;i++)
    {
        if(!vis[i])
            dfs(i);
    }

    for(i=0;i<n;i++)
        vis[i]=0;


    while(!s.empty())
    {
        int x=s.top();
        s.pop();

        if(!vis[x])
            dfs2(x);
        cnt++;
    }

    for(i=1;i<cnt;i++)
    {
        if(scc[i].size()>1)
        {
            for(j=0;j<scc[i].size();j++)
                ans[scc[i][j]]=1;
        }
    }

    for(i=0;i<n;i++)
        printf("%d ",ans[i]);

    return 0;
}





