#include<bits/stdc++.h>
using namespace std;

int arr[110][110];

int dp[110][110];
int c[110][100];

int n,m;
int ans;

int solve()
{
    int i,j,k;


    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            dp[i][j]=0;
    }

    dp[n-1][m-1]=1;

    for(j=m-2;j>=0;j--)
    {
        for(k=j+1;k<m;k++){
            if(arr[n-1][k]>arr[n-1][j])
            {
                dp[n-1][j]=max(dp[n-1][j+1]+1);
            }
            else
            {
                dp[n-1][j]=1;
            }
        }
    }

    for(i=n-2;i>=0;i--)
    {
        if(arr[i+1][m-1]<arr[i][m-1])
        {
            dp[i][m-1]=dp[i+1][m-1]+1;
        }
        else
        {
            dp[i][m-1]=1;
        }
    }

    int r,d;

    for(i=n-2;i>=0;i--)
    {
        for(j=m-2;j>=0;j--)
        {
            r=INT_MIN;
            d=INT_MIN;

            if(arr[i+1][j]<arr[i][j])
            {
                d=dp[i+1][j]+1;
            }

            if(arr[i][j+1]>arr[i][j])
            {
                r=dp[i][j+1]+1;
            }

            dp[i][j]=max(d,r);
        }
    }

    int max1=INT_MIN;
    int sum=0;

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            //cout<<dp[i][j]<<" ";

            max1=max(max1,dp[i][j]);
        }

        //cout<<endl;
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(dp[i][j]==max1)
                sum++;
        }
    }

    ans=max1;

    return sum;

}

int main()
{
    int test,i,j,k;



    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        scanf("%d%d",&n,&m);

        for(j=0;j<n;j++)
        {
            for(k=0;k<m;k++)
            {
                scanf("%d",&arr[j][k]);
            }
        }


        int f=solve();

        printf("%d %d\n",ans,f);


    }


    return 0;
}
