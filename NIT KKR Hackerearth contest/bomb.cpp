#include<bits/stdc++.h>
using namespace std;

long long arr[101000];
long long tp[101000];
long long range[101000];
long long n;

long long memo[101000];

long long solve(long long idx){
    long long i,j,k;
    if(idx>=n)
        return 0;

    if(memo[idx]!=-1)
        return memo[idx];

    if(tp[idx]==-1)
        return memo[idx] = solve(idx+1);

    long long nxt = min(n,idx+range[idx]);
    long long x = nxt-idx;
    long long ans= max(solve(idx+1),x*arr[idx] - x*(x-1)/2 + solve(nxt));

    for(i=idx+1;i<n && i<idx+range[idx];i++){
        if(tp[i]==tp[idx]){
            x = i-idx;
            ans = max(ans,x*arr[idx] - x*(x-1)/2 + solve(i));
        }
    }
    return memo[idx] = ans;
}

int main()
{
    long long i,j,k;
    scanf("%lld",&n);
    for(i=0;i<n;i++)
        scanf("%lld",&arr[i]);
    for(i=0;i<n;i++)
        scanf("%lld",&tp[i]);
    for(i=0;i<n;i++)
        scanf("%lld",&range[i]);

    for(i=0;i<n;i++)
        memo[i]=-1;

    printf("%lld\n",solve(0));

    return 0;
}
