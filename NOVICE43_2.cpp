#include<bits/stdc++.h>
using namespace std;

map< pair<long long,long long>,long long > memo;

long long solve(long long n,long long mx)
{
    long long i,j,k;

    if(n==0)
        return 1;

    if(memo.find(make_pair(n,mx))!=memo.end())
        return memo[make_pair(n,mx)];

    long long sum=0;

    for(i=0;i<=mx;i++)
    {
        sum += solve(n-1,max(i+1,mx));
    }

    return memo[make_pair(n,mx)]=sum;
}

int main()
{
    long long test,i,j,k;

    long long n;

    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        scanf("%lld",&n);

        long long ans = solve(n,0);

        printf("%lld\n",ans);
    }

    return 0;
}
