#include<bits/stdc++.h>
using namespace std;

long long arr[1010];
map<long long,long long> memo;
map<long long,long long>::iterator it;
long long n;

long long dp[10010][10010][2];

long long solve(long long idx,long long cur,long long l)
{
    long long i,j,k;

    if(idx==n)
    {
        return 0;
    }

    if(dp[idx][cur][l]!=-1)
        return dp[idx][cur][l];

    if(l==0) //small
    {
        if(arr[idx]>cur)
            return dp[idx][cur][l]=solve(idx+1,cur,0);
        else
        {
            long long tk,nt;
            tk=solve(idx+1,arr[idx],1) +1;
            nt=solve(idx+1,cur,0);
            return dp[idx][cur][l]=max(tk,nt);
        }
    }
    else // large
    {
        if(arr[idx]<cur)
            return dp[idx][cur][l]=solve(idx+1,cur,1);
        else
        {
            long long tk,nt;
            tk=solve(idx+1,arr[idx],0)+1;
            nt=solve(idx+1,cur,1);
            return dp[idx][cur][l]=max(tk,nt);
        }
    }
}

int main()
{
    long long i,j,k;
    long long test,t;
    scanf("%lld",&test);
    for(t=0;t<test;t++)
    {
        scanf("%lld",&n);
        for(i=0;i<n;i++){
            scanf("%lld",&arr[i]);
            memo[arr[i]];
        }
        long long cnt=1;
        for(it=memo.begin();it!=memo.end();it++)
            memo[it->first]=cnt++;
        for(i=0;i<n;i++)
            arr[i]=memo[arr[i]];

        for(i=0;i<=n;i++)
            for(j=0;j<=n+10;j++)
            {
                dp[i][j][0]=-1;
                dp[i][j][1]=-1;
            }

        long long ans=max(solve(0,0,1),solve(0,cnt+1,0));

        printf("%lld\n",ans);
        memo.clear();
    }

    return 0;
}
