#include<bits/stdc++.h>
using namespace std;

long long n,k;
long long memo[1010][2];
long long M = 1e9 + 7;

long long solve(long long idx,long long cur){

    if(cur==1 && k==0) return 0;

    if(idx==n-1 || idx==n)
        return 1;

    if(memo[idx][cur]!=-1)
        return memo[idx][cur];

    long long i,j;
    long long ans=0;
    if(cur==1){
        for(i=1;idx+i<=n && i<=k;i++){
            ans = (ans + solve(idx+i,1-cur))%M;
        }
    } else {
        ans = (solve(idx+1,cur) + solve(idx+1,1-cur))%M;
    }
    return memo[idx][cur] = ans;
}

int main()
{
    long long i,j;

    scanf("%lld%lld",&n,&k);

    for(i=0;i<=n;i++)
        for(j=0;j<=1;j++)
            memo[i][j] = -1;

    long long ans = (solve(0,0) + solve(0,1))%M;
    printf("%lld\n",ans);

    return 0;
}
