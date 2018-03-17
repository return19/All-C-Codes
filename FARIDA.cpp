#include<bits/stdc++.h>
using namespace std;

long long n;
long long arr[1100];
long long dp[1100];

long long max2(long long x,long long y)
{
    if(x>y)
        return x;
    else
        return y;
}

long long find_dp()
{
    long long i,j,k;

    dp[0]=0;
    dp[1]=arr[1];

    for(i=2;i<=n;i++)
    {
        dp[i]=max2(dp[i-1],dp[i-2]+arr[i]);
    }

    return dp[n];

}

int main()
{
    long long test,i,j,k;
    long long ans;

    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        scanf("%lld",&n);

        for(j=1;j<=n;j++)
        {
            scanf("%lld",&arr[j]);
        }

        ans=0;
        ans=find_dp();

        printf("Case %lld: %lld\n",i+1,ans);

    }

    return 0;
}
