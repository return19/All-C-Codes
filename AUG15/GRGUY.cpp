#include<bits/stdc++.h>
using namespace std;
#define INT_MAX 999999999
char str[2][201000];

int dp[2][201000];

int main()
{
    int test,i,j,k;
    int n;

    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        scanf("%s",str[0]);
        scanf("%s",str[1]);

        n=strlen(str[0]);

        if(str[0][0]=='.')
            dp[0][0]=0;
        else
            dp[0][0]=INT_MAX;


        if(str[1][0]=='.')
            dp[1][0]=0;
        else
            dp[1][0]=INT_MAX;

        for(j=1;j<n;j++)
        {
            for(k=0;k<2;k++)
            {
                if(str[k][j]=='#')
                    dp[k][j]=INT_MAX;
                else
                {
                    dp[k][j]=min(min(dp[k][j-1],dp[(k+1)%2][j-1]+1),INT_MAX);
                }
            }
        }

        if(dp[0][n-1]==INT_MAX&&dp[1][n-1]==INT_MAX)
        {
            printf("No\n");
        }
        else
        {
            printf("Yes\n%d\n",min(dp[0][n-1],dp[1][n-1]));
        }


    }

    return 0;
}











