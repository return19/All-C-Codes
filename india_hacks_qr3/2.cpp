#include<bits/stdc++.h>
using namespace std;

long long graph[20][20];
long long n,p;

long long isset(long long mask,long long pos)
{
    if((mask & (1<<pos))>0)
        return 1;
    return 0;
}

void maskit(long long &mask,long long pos)
{
    mask= mask|(1<<pos);
}

long long solve(long long idx,long long mask)
{
    long long i,j,k;

    if(idx>n)
    {
        if(mask>0)
            return 1;
        return 0;
    }

    long long f=0;
    for(i=1;i<=n;i++)
    {
        if(graph[idx][i]==1 && isset(mask,i))
        {
            f=1;
            break;
        }
    }
    if(f==1)
    {
        return solve(idx+1,mask);
    }
    long long temp=mask;
    maskit(temp,idx);
    return solve(idx+1,mask) + solve(idx+1,temp);
}

int main()
{
    long long i,j,k;
    long long test,t;
    long long x,y;

    scanf("%lld",&test);
    for(t=0;t<test;t++)
    {
        scanf("%lld%lld",&n,&p);

        for(i=0;i<=n;i++)
            for(j=0;j<=n;j++)
                graph[i][j]=0;

        for(i=0;i<p;i++)
        {
            scanf("%lld%lld",&x,&y);
            graph[x][y]=1;
            graph[y][x]=1;
        }
        long long mask=0;
        long long ans=solve(1,mask);
        printf("%lld\n",ans);
    }

    return 0;
}
