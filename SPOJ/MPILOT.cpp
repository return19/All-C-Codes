#include<bits/stdc++.h>
using namespace std;

long long c[10100];

long long a[10100];

long long dp[2][10100];

long long n;

long long min2(long long x,long long y)
{
    if(x<y)
        return x;
    else
        return y;
}

long long solve_dp()
{
    long long i,j,k,x,y;

    dp[1][1]=c[1];

    for(i=2;i<=n;i++)
    {
        x=i%2;
        y=!x;
        for(j=0;j<=i;j++)
        {
            if(j==0)
            {
                dp[x][j]=dp[y][j+1]+a[i];
            }
            else if(j==i)
            {
                dp[x][j]=dp[y][j-1]+c[i];
            }
            else
            {
                dp[x][j]=min2(dp[y][j-1]+c[i],dp[y][j+1]+a[i]);
            }
        }
    }

    return dp[n%2][0];
}


int main()
{
    long long i,j,k;
    long long ans;


    scanf("%lld",&n);

    for(i=n;i>0;i--)
    {
        scanf("%lld%lld",&c[i],&a[i]);
    }

    ans=solve_dp();

    printf("%lld\n",ans);

    return 0;
}
