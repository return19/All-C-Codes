#include<bits/stdc++.h>
using namespace std;

long long n,count1;
long long dp[1010][1010];

void init()
{
    count1=0;
    long long i,j,k;
    for(i=0;i<=n;i++)
        dp[i][i]=1;
    for(i=0;i<=n;i++)
        dp[i][0]=1;
    for(i=2;i<=n;i++)
    {
        for(j=1;j<i;j++)
        {
            dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
            if(dp[i][j]==n)
                count1++;
        }
    }
}

int main()
{
    long long test,i,j,k;
    scanf("%lld",&test);
    for(i=0;i<test;i++)
    {
        scanf("%lld",&n);
        init();
        printf("%lld\n",count1);
        for(j=0;j<=n;j++)
        {
            for(k=0;k<=j;k++)
            {
                if(dp[j][k]==n)
                {
                    printf("(%lld,%lld) ",j,k);
                }
            }
        }
        printf("\n");
    }

    return 0;
}
