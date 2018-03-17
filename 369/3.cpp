#include<bits/stdc++.h>
using namespace std;

long long n,m,k;
long long p[1010][1010];
long long arr[1010];
long long memo[110][110][110];

long long solve(long long idx,long long tk,long long c){
    if(idx==n){
        if(tk==k){
            return 0;
        }
        return LLONG_MAX;
    }

    if(tk>k)
        return LLONG_MAX;

    if(memo[idx][tk][c]!=-1)
        return memo[idx][tk][c];

    long long i,j;
    long long ans=LLONG_MAX;
    if(arr[idx]==0){
        for(i=1;i<=m;i++){
            if(i==c){
                long long t = solve(idx+1,tk,c);
                if(t!=LLONG_MAX)
                    ans = min( t+ p[idx][c],ans);
            } else {
                long long t = solve(idx+1,tk+1,i);
                if(t!=LLONG_MAX)
                    ans = min(t+p[idx][i],ans);
            }
        }
    }else {
        if(arr[idx]==c)
            ans = min(ans,solve(idx+1,tk,c));
        else
            ans = min(ans,solve(idx+1,tk+1,arr[idx]));
    }
    return memo[idx][tk][c] =  ans;
}

int main()
{
    long long i,j;
    scanf("%lld%lld%lld",&n,&m,&k);
    for(i=0;i<n;i++)
        scanf("%lld",&arr[i]);
    for(i=0;i<n;i++)
        for(j=1;j<=m;j++)
            scanf("%lld",&p[i][j]);

    for(i=0;i<=n;i++)
        for(j=0;j<=k;j++)
            for(long long x=0;x<=m;x++)
                memo[i][j][x]=-1;

    long long ans = LLONG_MAX;
    if(arr[0]==0){
        for(i=1;i<=m;i++)
        {
            long long t = solve(1,1,i);
            if(t!=LLONG_MAX)
                ans = min(ans,t+p[0][i]);
        }
    } else {
        long long t = solve(1,1,arr[0]);
        if(t!=LLONG_MAX)
            ans = min(ans,t);
    }
    if(ans !=LLONG_MAX)
        printf("%lld\n",ans);
    else
        printf("-1\n");
    return 0;
}








