#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long arr[11];

long long ans=0;

long long memo[5010][5010];

long long solve(long long sum,long long cur)
{
    if(sum==n)
    {
        return cur;
    }

    if(memo[sum][cur]!=-2)
        return memo[sum][cur];

    long long i,ans=-1;
    for(i=0;i<m;i++)
    {
        if(sum+cur+arr[i]<=n)
            ans=max(ans,solve(sum+cur+arr[i],cur+arr[i]));
    }
    return memo[sum][cur]=ans;
}

int main()
{
    long long i,j,k;
    long long test,t;

    scanf("%lld",&test);

    for(t=0;t<test;t++)
    {
        scanf("%lld%lld",&n,&m);

        for(i=0;i<m;i++)
            scanf("%lld",&arr[i]);

        for(i=0;i<=n;i++)
            for(j=0;j<=n;j++)
                memo[i][j]=-2;

        long long ans=solve(0,0);
        printf("%lld\n",ans);
    }
    return 0;
}
