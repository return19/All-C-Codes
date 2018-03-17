#include<bits/stdc++.h>
using namespace std;

vector<int> g[110000];

int min_sz=0;
int min_count=0;

int visited[110000];
int color[110000];
int nb[110000];


void dfs(int x,int c)
{
    int i,j;
    int t=1;
    visited[x]=1;

    if(c==1)
    {
        color[x]=1;
        t=2;
    }
    else
        color[x]=2;

    for(i=0;i<g[x].size();i++)
    {
        nb[x]++;

        if(visited[g[x][i]]!=0&&color[g[x][i]]==color[x])
            {min_count++;
                cout<<x<<" "<<g[x][i]<<endl;
            }

        if(!visited[g[x][i]])
        {
            dfs(g[x][i],t);
        }
    }
}

int main()
{
    int i,j,k;
    int n,m;
    int x,y;

    scanf("%d%d",&n,&m);

    for(i=0;i<m;i++)
    {
        scanf("%d%d",&x,&y);

        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    if(m==0)
    {
        printf("%d %d\n",3,(n*(n-1)*(n-2))/6);
        return 0;
    }


    for(i=0;i<n;i++)
    {
        if(visited[i]==0)
        {
            dfs(i,1);
        }
    }

    if(min_count!=0)
    {
        printf("%d %d\n",0,min_count);
        return 0;
    }


    int ans=0;
    int ct=0,ct2=0;

    for(i=0;i<n;i++)
    {
        if(nb[i]>=2)
        {
            ct++;
            ans=ans+(nb[i]*(nb[i]-1))/2;

        }

        if(nb[i]==1)
            ct2++;
    }

    if(ct==0)
    {
        printf("%d %d\n",2,ct2*(n-2));
        return 0;
    }

    printf("%d %d\n",1,ans);



    return 0;
}













