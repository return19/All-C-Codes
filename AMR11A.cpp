#include<bits/stdc++.h>
using namespace std;

int n,m;

int arr[1010][1010];
int dp[1010][1010];

int solve()
{
    int i,j,k;

    dp[n-1][m-1]=0;

    for(i=n-2;i>=0;i--)
    {
        dp[i][m-1]=dp[i+1][m-1]+arr[i][m-1];

        if(dp[i][m-1]>=0)
            dp[i][m-1]=0;
    }

    for(j=m-2;j>=0;j--)
    {
        dp[n-1][j]=dp[n-1][j+1]+arr[n-1][j];

        if(dp[n-1][j]>=0)
            dp[n-1][j]=0;
    }

    for(i=n-2;i>=0;i--)
    {
        for(j=m-2;j>=0;j--)
        {
            dp[i][j]=arr[i][j] + max(dp[i+1][j],dp[i][j+1]);

            if(dp[i][j]>=0)
                dp[i][j]=0;
        }
    }

   /* for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }*/

    if(dp[0][0]<=0)
        return dp[0][0]*(-1)+1;

    return 1;
}

int main()
{
    int i,j,k;
    int test,t;

    scanf("%d",&test);

    for(t=0;t<test;t++)
    {
        scanf("%d%d",&n,&m);

        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                scanf("%d",&arr[i][j]);
            }
        }

        int ans=solve();

        printf("%d\n",ans);
    }

    return 0;
}
