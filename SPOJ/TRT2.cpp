#include<bits/stdc++.h>
using namespace std;

long long arr[2010];

long long dp[2010][2010];

long long n;


int max2(int x,int y)
{
    if(x>y)
        return x;
    else
        return y;
}

long long solve_dp()
{
    long long i,j,k;
    long long age=1;
    long long ans=0;

    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n-k+1;i++)
        {
            j=i+k-1;

            dp[i][j]=max2(dp[i][j-1]+arr[j]*(n-(j-i)),arr[i]*(n-(j-i))+dp[i+1][j]);
        }
    }

    return dp[1][n];

}

int main()
{
    long long test,i,j,k;
    long long ans;

    scanf("%lld",&n);

    for(i=1;i<=n;i++)
    {
        scanf("%lld",&arr[i]);
    }

    ans=solve_dp();

    printf("%lld\n",ans);

    return 0;
}












