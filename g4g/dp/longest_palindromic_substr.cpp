#include<bits/stdc++.h>
using namespace std;

char str[1100];

int n;

int dp[1100][1100];
int flag[1100][1100];

int max2(int x,int y)
{
    if(x>y)
        return x;
    return y;

}

int find_long_palin()
{
    int i,j,k;

    n=strlen(str);

    for(i=0;i<n;i++)
    {
        dp[i][i]=1;
        flag[i][i]=1;
    }

    for(int gap=2;gap<=n;gap++)
    {
        for(i=0;i<n-gap+1;i++)
        {
            j=i+gap-1;

            if(i+1==j)
            {
                if(str[i]==str[j])
                {
                    flag[i][j]=1;
                    dp[i][j]=2;
                }
                else
                {
                    dp[i][j]=1;
                    flag[i][j]=0;
                }
                continue;

            }

            if(str[i]==str[j])
            {
                if(flag[i+1][j-1]==1)
                {
                    dp[i][j]=2+dp[i+1][j-1];
                    flag[i][j]=1;
                }
                else
                {
                    dp[i][j]=max2(dp[i+1][j],dp[i][j-1]);
                    flag[i][j]=0;
                }
            }
            else
            {
                dp[i][j]=max2(dp[i+1][j],dp[i][j-1]);
                flag[i][j]=0;
            }
        }
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    return dp[0][n-1];
}

int main()
{
    int i,j,k;

    scanf("%s",str);

    int ans=find_long_palin();

    printf("%d\n",ans);

    return 0;
}
