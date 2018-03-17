#include<bits/stdc++.h>
using namespace std;

int n;

int graph[101000];
double val[101000];

int visited[101000];
double ans=0,temp;

void dfs1(int x,int st)
{
    if(x==st)
    {
        return;
    }


    temp=temp*(val[x]/100);

    dfs1(graph[x],st);
}

void dfs(int x,int t)
{
    visited[x]=t;

    if(!visited[graph[x]])
    {
        dfs(graph[x],t);
    }
    else if(visited[graph[x]]==t)
    {
        temp=(val[x]/100);

        dfs1(graph[x],x);

        ans=ans+temp;
    }
}

int main()
{

    int i,j,k;

    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
        scanf("%d%lf",&graph[i],&val[i]);
    }

    j=1;

    for(i=1;i<=n;i++)
    {

        if(!visited[i])
        {
            temp=1;
            dfs(i,j);
            j++;
        }
    }

    printf("%.2lf\n",ans);


    return 0;
}












