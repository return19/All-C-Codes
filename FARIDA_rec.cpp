#include<bits/stdc++.h>
using namespace std;

long long n;

long long dp[11000];

long long arr[11000];

long long max2(long long x,long long y)
{
    if(x>y)
        return x;
    else
        return y;
}

long long cal()
{
    long long i,j,k;

    dp[0]=arr[0];

    dp[1]=max2(arr[0],arr[1]);


    for(i=2;i<n;i++)
        dp[i]=max2(dp[i-1],dp[i-2]+arr[i]);

    return dp[n-1];

}

int main()
{
    long long test,i,j,k;

    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        scanf("%lld",&n);

        for(j=0;j<n;j++)
        {
            dp[j]=0;
            scanf("%lld",&arr[j]);
        }

        printf("Case %lld: %lld\n",i+1,cal());

    }

    return 0;
}
