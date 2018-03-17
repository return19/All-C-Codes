#include<bits/stdc++.h>
using namespace std;

long long k;
long long dp[101000];
long long ans[101000];
long long M = 1e9 + 7;
long long solve(long long n){
    long long i,j;

    if(n == 0)
        return 1;
    if(n < 0)
        return 0;

    if(dp[n]!=-1)
        return dp[n];

    return dp[n] = (solve(n-1) + solve(n-k))%M;
}

int main()
{
    long long i,j;
    long long test;
    long long x,y;

    scanf("%lld%lld",&test,&k);

    for(i=0;i<=100010;i++)
        dp[i]=-1;

    for(i=1;i<=100010;i++){
        ans[i] = (ans[i-1] + solve(i))%M;
    }

    for(i=0;i<test;i++){
        scanf("%lld%lld",&x,&y);

        printf("%lld\n",(ans[y] - ans[x-1] + M)%M);
    }
    return 0;
}
