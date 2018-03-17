#include<bits/stdc++.h>
using namespace std;

vector<int> g[110000];

int visited[110000];
int visited1[110000];
int cc[110000];
int dia[110000];

int max_node;

int dfs(int x,int k)
{
    int i,j;
    int max1=1;

    visited[x]=1;
    cc[x]= k;
    for(i=0;i<g[x].size();i++)
    {
        if(!visited[g[x][i]])
        {
            dfs(g[x][i],k);
        }
    }


}

int max1=0;

void dfs2(int x,int k)
{
    int i,j;


    if(k>=max1)
    {
        max1=k;
        max_node=x;
    }

    visited2[x]=1;

    for(i=0;i<g[x].size();i++)
    {
        if(!visited[g[x][i]])
        {
            dfs(g[x][i],k+1);
        }
    }
}


int main()
{
    int n,m,q;
    int i,j,k;
    int x,y;

    scanf("%d%d%d",&n,&m,&q);

    for(i=0;i<m;i++)
    {
        scanf("%d%d",&x,&y);

        g[x].push_back(y);
        g[y].push_back(x);
    }

    k=0;

    for(i=0;i<n;i++)
    {
        if(!visited[i])
        {
            dfs(i,k);
            k++;
        }
    }

    return 0;
}
