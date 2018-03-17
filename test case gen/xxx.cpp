#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define LL long long
LL dp[1001][1001];
int main()
{
    int n,k; cin>>n>>k;
    dp[0][0]=1;
    dp[0][1]=1;
    for(int i=1;i<n;i++)
    {
        dp[i][0]=0;
        for(int j=0;j<=k;j++)
            {
            dp[i][0]+=dp[i-1][j];
            dp[i][0]%=MOD;
        }

        for(int j=1;j<=k;j++)
            {
            dp[i][j]=dp[i-1][j-1];
        }
    }

    LL ans=0;
    for(int j=0;j<=k;j++)
        {
        ans=(ans+dp[n-1][j])%MOD;
    }
    cout<<ans;
}
