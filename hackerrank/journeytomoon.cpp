#include<bits/stdc++.h>
using namespace std;

long long n,m;

vector<long long> graph[110000];

long long visited[110000];

long long cc[110000],CC=-1;

long long tot=0;

void dfs(long long x)
{
    long long i,j,k;

    visited[x]=1;
    tot++;

    for(i=0;i<graph[x].size();i++)
    {
        if(!visited[graph[x][i]])
        {
            dfs(graph[x][i]);
        }
    }
}

int main()
{

    long long i,j,k;
    long long x,y;


    scanf("%lld%lld",&n,&m);

    for(i=0;i<m;i++)
    {
        scanf("%lld%lld",&x,&y);

        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    for(i=0;i<n;i++)
    {
        if(!visited[i])
        {
            tot=0;
            dfs(i);

            cc[++CC]=tot;
           // cout<<tot<<" ";
        }
    }



    long long sum=0;
    long long ans=0;

    for(i=0;i<=CC;i++)
    {
        sum=sum+cc[i];

        ans=ans+(n-sum)*cc[i];
    }

    printf("%lld\n",ans);



    return 0;
}


















