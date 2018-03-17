#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ft first
#define sd second

long long ttime[51][51];
long long cost[51][51];
long long n,t;

long long dp[51][1010];

pair<long long,long long> solve(){
    long long i,j,k;
    pair<long long,long long> ans; // cost,ttime
    ans.ft = LLONG_MAX;
    ans.sd = LLONG_MAX;
    queue< pair< long long,pair<long long,long long> > > q;//x,cost,ttime

    q.push(mp(0,mp(0,0)));
    while(!q.empty()){
        pair< long long,pair<long long,long long> > p = q.front();
        q.pop();

        long long x = p.ft;
        long long c = p.sd.ft;
        long long tm = p.sd.sd;

        for(i=0;i<n;i++){
            long long tc = c + cost[x][i];
            long long ttm = tm + ttime[x][i];

            if(ttm > t)
                continue;

            if(i==n-1){
                if(ans.ft > tc){
                    ans.ft = tc;
                    ans.sd = ttm;
                }else if(ans.ft == tc && ans.sd > ttm){
                    ans.sd = ttm;
                }
                continue;
            }

            if(tc < dp[i][ttm]){
                dp[i][ttm] = tc;
                q.push(mp(i,mp(tc,ttm)));
            }
        }
    }
    return ans;
}

int main()
{
    long long i,j,k;
    scanf("%lld%lld",&n,&t);

    while(n!=0 && t!=0){
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                scanf("%lld",&ttime[i][j]);

        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                scanf("%lld",&cost[i][j]);

        for(i=0;i<n;i++)
            for(j=0;j<=t;j++)
                dp[i][j]=LLONG_MAX;

        pair<long long,long long> ans = solve();
        printf("%lld %lld\n",ans.ft,ans.sd);

        scanf("%lld%lld",&n,&t);
    }

    return 0;
}










