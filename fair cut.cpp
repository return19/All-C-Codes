#include<bits/stdc++.h>
using namespace std;

long long n,k;
long long arr[3010];
long long memo[3010][3010];

long long solve(long long idx,long long tk){

    if(tk>k)
        return LLONG_MAX;

    if(idx==n){
        if(tk==k)
            return 0;
        return LLONG_MAX;
    }

    if(memo[idx][tk]!=-1)
        return memo[idx][tk];

    long long ans=LLONG_MAX;
    long long taken = idx-tk;

    long long take = solve(idx+1,tk+1);
    long long ntake = solve(idx+1,tk);

    if(ntake!=LLONG_MAX)
        ans = min(ans, ntake + tk*arr[idx] - (k-tk)*arr[idx]);
    if(take!=LLONG_MAX)
        ans = min(ans, take + (taken)*arr[idx] - (n-k-taken)*arr[idx]);
    return memo[idx][tk] = ans;
}

int main()
{
    long long i,j;
    scanf("%lld%lld",&n,&k);
    for(i=0;i<n;i++)
        scanf("%lld",&arr[i]);

    sort(arr,arr+n);

    for(i=0;i<=n;i++)
        for(j=0;j<=n;j++)
            memo[i][j]=-1;

    long long ans = solve(0,0);
    printf("%lld\n",ans);

    return 0;
}
