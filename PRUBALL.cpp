#include<bits/stdc++.h>
using namespace std;
#define MAX 10000000000
long long f,e;
long long dp[10010][10010];

long long max2(long long x,long long y)
{
    if(x>y)
        return x;
    else
        return y;
}

void init()
{
    long long i,j,k,temp;

    for(i=1;i<=e;i++)
    {
        dp[i][0]=0;
        dp[i][1]=1;
    }
    for(j=1;j<=f;j++)
    {
        dp[1][j]=j;
    }

    for(i=2;i<=e;i++)
    {
        for(j=2;j<=f;j++)
        {
            dp[i][j]=MAX;
            for(k=1;k<=j;k++)
            {
                temp=1+max2(dp[i-1][k-1],dp[i][j-k]);
                if(dp[i][j]>temp)
                    dp[i][j]=temp;
            }
        }
    }

}

int main()
{
    long long test,i,j,sac;
    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        scanf("%lld%lld%lld",&sac,&e,&f);
        init();
        printf("%lld %lld\n",sac,dp[e][f]);
    }

    return 0;
}
