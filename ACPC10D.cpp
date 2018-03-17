#include<bits/stdc++.h>
using namespace std;

long long n;
long long arr[100100][3];

long long dp[100100][3];

long long min2(long long x,long long y)
{
    if(x<y)
        return x;
    else
        return y;
}

long long cal_dp()
{
    long long i,j,k;

    dp[0][1]=arr[0][1];
    dp[0][2]=arr[0][1]+arr[0][2];

    dp[1][0]=arr[0][1]+arr[1][0];
    dp[1][1]=arr[1][1]+min2(min2(dp[1][0],dp[0][1]),dp[0][2]);
    dp[1][2]=arr[1][2]+min2(min2(dp[1][1],dp[0][1]),dp[0][2]);

    for(i=2;i<n;i++)
    {
        for(j=0;j<3;j++)
        {
            if(j==0)
            {
                dp[i][j]=arr[i][j]+min2(dp[i-1][j],dp[i-1][j+1]);
            }
            else if(j==1)
            {
                dp[i][j]=arr[i][j]+min2(min2(dp[i][j-1],dp[i-1][j-1]),min2(dp[i-1][j],dp[i-1][j+1]));
            }
            else
            {
                dp[i][j]=arr[i][j]+min2(min2(dp[i][j-1],dp[i-1][j-1]),dp[i-1][j]);
            }
        }
    }

    return dp[n-1][1];
}


int main()
{
    long long test=0,i,j,k;
    long long ans;

    scanf("%lld",&n);

    while(n!=0)
    {
        test++;
        for(i=0;i<n;i++)
        {
            for(j=0;j<3;j++)
            {
                scanf("%lld",&arr[i][j]);
            }
        }

        ans=cal_dp();

        printf("%lld. %lld\n",test,ans);


        scanf("%lld",&n);
    }

    return 0;
}
