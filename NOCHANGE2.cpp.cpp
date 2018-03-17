
#include<bits/stdc++.h>
using namespace std;

long long arr[10];
long long csum[10];

long long dp[110000];

int main()
{
    long long n,k,i,j,p;

    scanf("%lld%lld",&n,&k);

    csum[0]=0;

    for(i=1;i<=k;i++)
    {
        scanf("%lld",&arr[i]);
        csum[i]=csum[i-1]+arr[i];
    }

    dp[0]=1;

    for(i=1;i*arr[1]<=n;i++)
        dp[i*arr[1]]=1;

    for(i=2;i<=k+1;i++)
    {
        for(j=csum[i-1];j<=n;j++)
        {
            dp[j]=dp[j]|dp[j-csum[i-1]];
        }
    }



    if(dp[n])
        printf("YES\n");
    else
        printf("NO\n");

    return 0;
}
