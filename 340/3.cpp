#include<bits/stdc++.h>
using namespace std;

long long arr[110];
long long n;

long long memo[110][110];
long long base[110][110];

long long solve(long long idx,long long num)
{
    long long i,j,k;

    if(idx==n)
    {
        if(num==1)
            return 1;
        return 0;
    }

    if(num>1)
        return 0;

    if(base[idx][num]==1)
        return memo[idx][num];
    base[idx][num]=1;

    if(num==1)
    {
        if(arr[idx]==1)
            return memo[idx][num]=0;
        return memo[idx][num]=solve(idx+1,0) + solve(idx+1,num);
    }

    if(arr[idx]==1)
        return memo[idx][num]=solve(idx+1,1) + solve(idx+1,0);
    return memo[idx][num]=solve(idx+1,0);
}

int main()
{
    long long i,j,k;

    scanf("%lld",&n);

    for(i=0;i<n;i++)
        scanf("%lld",&arr[i]);
    long long ans=solve(0,0);
    printf("%lld\n",ans);

    return 0;
}

