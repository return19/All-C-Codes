#include<bits/stdc++.h>
using namespace std;
#define MAX 20000000

long long dp[5010][5010];
long long n,m;

long long min2(long long x,long long y)
{
    if(x<y)
        return x;
    else
        return y;
}

long long min3(long long x,long long y,long long z)
{
    return (min(min(x,y),z));
}


long long cal_min()
{
    long long i,j,least=MAX;
    for(i=1;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(j==0)
            {
                dp[i][j]+=min2(dp[i-1][j],dp[i-1][j+1]);
            }
            else if(j==m-1)
            {
                dp[i][j]+=min2(dp[i-1][j-1],dp[i-1][j]);
            }
            else
            {
                dp[i][j]+=min3(dp[i-1][j-1],dp[i-1][j],dp[i-1][j+1]);
            }
        }
    }
    for(i=0;i<m;i++)
    {
        if(least>dp[n-1][i])
        {
            least=dp[n-1][i];
        }
    }

    return least;
}

int main()
{
    long long i,j;
    scanf("%lld%lld",&n,&m);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            scanf("%lld",&dp[i][j]);
        }
    }
    printf("%lld\n",cal_min());
    return 0;
}









