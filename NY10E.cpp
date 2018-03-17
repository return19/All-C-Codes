#include<bits/stdc++.h>
using namespace std;

long long dp[11][100];

void init()
{
    long long i,j,k,sum;

    for(i=0;i<=9;i++)
    {
        dp[i][0]=1;
    }
    dp[10][0]=10;

    for(j=1;j<=64;j++)
    {
        sum=0;

        for(i=0;i<=10;i++)
        {
            if(i==10)
            {
                dp[10][j]=sum;
                continue;
            }

            if(i==0)
            {
                dp[0][j]=dp[10][j-1];
                sum=sum+dp[i][j];
                continue;
            }

            dp[i][j]=dp[i-1][j]-dp[i-1][j-1];

            sum=sum+dp[i][j];
        }
    }
}

int main()
{
    long long test,i,j,k,n,ans;

    scanf("%lld",&test);
    init();

    for(i=0;i<test;i++)
    {
        scanf("%lld%lld",&n,&n);

        printf("%lld %lld\n",i+1,dp[10][n-1]);
    }

    return 0;
}
