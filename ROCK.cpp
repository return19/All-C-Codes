#include<bits/stdc++.h>
using namespace std;

int cum_sum[210];
int arr[210];
int n;

int dp[210][210];

int max2(int x,int y)
{
    if(x>y)
        return x;
    else
        return y;
}

void find_dp()
{
    int i,j,k,ans2;
    int x,y;

    memset(dp,0,sizeof(dp));

    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n-k+1;i++)
        {
            j=i+k-1;

            if(i==j)
            {
                dp[i][j]=arr[i];
            }
            else
            {
                ans2=0;
                if(cum_sum[j]-cum_sum[i-1]>(j-i+1)/2)
                {
                    ans2=j-i+1;
                }
               // cout<<"hi : "<<i<<" "<<j<<endl;
                for(x=i;x<j;x++)
                {
                    ans2=max2(ans2,dp[i][x]+dp[x+1][j]);
                }

                dp[i][j]=ans2;
            }
        }
    }

    /*for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }*/
}

int main()
{
    int test,i,j,k;
    int temp;
    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        memset(cum_sum,0,sizeof(cum_sum));

        scanf("%d",&n);

        for(j=1;j<=n;j++)
        {
            scanf("%1d",&temp);
            arr[j]=temp;
            cum_sum[j]=cum_sum[j-1]+temp;
        }

        find_dp();

        printf("%d\n",dp[1][n]);
    }

    return 0;
}
