#include<bits/stdc++.h>
using namespace std;

long long n,s;
long long arr[1010];
long long dp[1010][1010][2];

long long solve(long long idx,long long t,long long prev){
    if(idx >= n)
        return 0;

    if(dp[idx][t][prev]!=-1)
        return dp[idx][t][prev];

    long long ans=0;

    if(t>=1)
        ans = max(solve(idx+1,t-1,0), solve(idx+2,t-1,0));
    if(t>=1 && prev==0)
        ans = max(ans, solve(idx+3,t-1,1));
    return dp[idx][t][prev] = ans + arr[idx];
}

int main(){

   // freopen("input10.txt","r",stdin);
    //freopen("output10.txt","w",stdout);

    long long i,j,k;
    scanf("%lld%lld",&n,&s);

    for(i=0;i<=n;i++)
        for(j=0;j<=s;j++)
            for(k=0;k<2;k++)
                dp[i][j][k]=-1;

    for(i=0;i<n;i++)
        scanf("%lld",&arr[i]);

    long long ans = solve(0,s,0);

    printf("%lld\n",ans);

    return 0;
}
