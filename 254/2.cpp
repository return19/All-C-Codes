#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long graph[110][110];

long long power(long long a,long long b)
{
    if(b==0)
    {
        return 1;
    }
    else if(b==1)
    {
        return a;
    }

    long long x=power(a,b/2);

    if(b&1)
        return x*x*a;
    return x*x;
}

long long visited[110];

void dfs(long long x)
{
    long long i,j,k;

    visited[x]=1;

    for(i=1;i<=n;i++)
    {
        if(!visited[i]&&graph[x][i])
            dfs(i);
    }
}


int main()
{

    long long i,j,k;
    scanf("%lld%lld",&n,&m);

    for(i=0;i<m;i++)
    {
        scanf("%lld%lld",&j,&k);

        graph[j][k]=1;
        graph[k][j]=1;

    }

    long long pro=1,count1=0;

    for(i=1;i<=n;i++)
    {
        if(!visited[i])
        {
            dfs(i);
            count1++;
        }
    }

    //cout<<"count : "<<count1<<endl;


    printf("%lld\n",power(2,n)/power(2,count1));

    return 0;
}
