#include<bits/stdc++.h>
using namespace std;

long long v1,v2,d,n;

long long memo[110][11000];
long long base[110][11000];

long long solve(long long idx,long long sp)
{
    if(idx==n-1)
    {
        if(sp==v2)
            return v2;

        return LLONG_MIN;
    }

    if(sp<0)
        return LLONG_MIN;

    if(base[idx][sp]==1)
        return memo[idx][sp];

    base[idx][sp]=1;

    long long i,j;

    long long ans=LLONG_MIN;

    for(i=(-1*d);i<=d;i++)
    {
        ans=max(ans,solve(idx+1,sp+i));
    }

    return memo[idx][sp]=ans+sp;
}

int main()
{
    long long i,j,k;

    scanf("%lld%lld",&v1,&v2);

    scanf("%lld%lld",&n,&d);

    long long ans=solve(0,v1);

    printf("%lld\n",ans);

    return 0;
}
