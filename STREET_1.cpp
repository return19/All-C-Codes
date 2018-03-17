#include<bits/stdc++.h>
using namespace std;

long long n,k,t;
long long arr[101000];

long long memo[510][510];
long long base[510][510];

long long solve(long long idx,long long b)
{
    if(idx==n)
    {
        return 0;
    }

    if(b==0)
        return 0;

    if(base[idx][b]==1)
        return memo[idx][b];
    base[idx][b]=1;

    long long i,j;
    long long mn=LLONG_MAX;
    long long ans=solve(idx+1,b);

    for(i=idx;i<n && i< idx+t;i++)
    {
        mn=min(mn,arr[i]);
        ans=max(ans,mn*(i-idx+1) + solve(i+1,b-1));
    }

    return memo[idx][b]=ans;
}

int main()
{
    long long i,j,k;
    scanf("%lld%lld%lld",&n,&k,&t);

    for(i=0;i<n;i++)
        scanf("%lld",&arr[i]);
    long long ans=solve(0,k);
    printf("%lld\n",ans);

    return 0;
}
