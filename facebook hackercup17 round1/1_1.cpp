#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long arr[310][310];
long long dp[310][310];

long long solve(long long idx,long long cur){
    if(idx==n)
        return 0;

    if(dp[idx][cur]!=-1)
        return dp[idx][cur];

    long long ans = LLONG_MAX;
    long long i,j;
    if(cur!=0)
        ans = min(ans,solve(idx+1,cur-1));

    for(j=0;j<m && (j+cur+1)<=(n-idx);j++){
        ans = min(ans,arr[idx][j] + (j+1)*(j+1) +
                      solve(idx+1,(cur+j+1)-1));
    }
    return dp[idx][cur]=ans;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    long long i,j,k;
    long long test,t;

    scanf("%lld",&test);

    for(t=0;t<test;t++){
        scanf("%lld%lld",&n,&m);

        for(i=0;i<=n;i++)
            for(j=0;j<=m;j++)
                dp[i][j]=-1;

        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                scanf("%lld",&arr[i][j]);

        for(i=0;i<n;i++)
            sort(arr[i],arr[i]+m);

        for(i=0;i<n;i++)
            for(j=1;j<m;j++)
                arr[i][j] += arr[i][j-1];

        long long ans = solve(0,0);
        printf("Case #%lld: %lld\n",t+1,ans);
    }

    return 0;
}
