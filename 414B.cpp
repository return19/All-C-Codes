#include<bits/stdc++.h>
using namespace std;

long long n,k;
long long memo[2010][2010];
long long M = 1e9 + 7;

long long solve(long long idx,long long cur){
    if(idx == k-1){
        return 1;
    }

    if(cur > n)
        return 0;

    if(memo[idx][cur]!=-1)
        return memo[idx][cur];

    long long ans = 0;

    for(long long i=cur;i<=n;i+=cur){
        ans = (ans + solve(idx+1,i))%M;
    }
    return memo[idx][cur] = ans;
}

int main()
{
    long long i,j;
    scanf("%lld%lld",&n,&k);
    long long ans=0;

    for(i=0;i<=k;i++)
        for(j=0;j<=n;j++)
            memo[i][j] = -1;

    for(i=1;i<=n;i++){
        ans = (ans + solve(0,i))%M;
    }

    printf("%lld\n",ans%M);
    return 0;
}
