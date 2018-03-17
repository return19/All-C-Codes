#include<bits/stdc++.h>
using namespace std;

long long dp[11][10000010];
long long cost[20];
long long w[20];

long long max2(long long x,long long y)
{
    if(x>y)
        return x;
    else
        return y;
}


long long dp_f(long long n,long long k)
{
    long long i,j;

    for(i=0;i<=n;i++)
        dp[i][0]=0;

    for(i=0;i<=k;i++)
        dp[0][i]=0;

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=k;j++)
        {
            if(cost[i-1]>j)
                dp[i][j]=dp[i-1][j];
            else
            {
                dp[i][j]=max2(dp[i-1][j],w[i-1]+dp[i-1][j-cost[i-1]]);
            }
        }
    }

    return dp[n][k];
}


int main()
{
    long long test,i,j,n,k,x,t;
    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        scanf("%lld%lld",&n,&k);
        for(j=0;j<n;j++)
        {
            scanf("%lld%lld",&cost[j],&w[j]);
        }
        //
        t=dp_f(n,k);
        /*for(x=0;x<=n;x++)
        {
            for(j=0;j<=k;j++)
                cout<<dp[x][j]<<" ";
            cout<<endl;
        }*/
        printf("%lld\n",t);
    }
        return 0;
}




