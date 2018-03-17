#include<bits/stdc++.h>
using namespace std;


int arr[1010][1010];


int dp[1010][1010];

int main()
{
    int i,j,k;
    int test,n,m;

    scanf("%d",&test);

    for(int t=0;t<test;t++)
    {

        scanf("%d%d",&m,&n);

        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&arr[i][j]);
            }
        }

        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                dp[i][j]=0;
            }
        }

        int r,d;

        for(i=m-1;i>=0;i--)
        {
            for(j=n-1;j>=0;j--)
            {
               r=INT_MIN;
               d=INT_MIN;

                if(i!=m)
                {
                	for(int k=m-1;k>i;k--)
                    {

                		if(arr[i][j]>=arr[k][j])
                            d = max(d,dp[k][j]);
                	}
                }

                if(j!=n)
                {
                	for(k=n-1;k>j;k--)
                	{
                		if(arr[i][j]<=arr[i][k])
                		{
                			r=max(r,dp[i][k]);
                		}
                	}
                }


                dp[i][j] = max(max(r,d),dp[i][j]);

                dp[i][j]=dp[i][j]+1;

            }
        }

        int max1 = INT_MIN;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(max1<dp[i][j])
                    max1 = dp[i][j];
            }
        }

        int cnt = 0;


        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                if(dp[i][j] == max1)
                    {
                        cnt++;
                    }
            }

        }

        printf("%d %d\n",max1,cnt);
    }

    return 0;
}









