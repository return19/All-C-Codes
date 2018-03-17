#include<bits/stdc++.h>
using namespace std;

char str[5100];
char opr[2600];

long long arr[2600];

long long dp[2600][2600];

long long dp1[2600][2600];

long long n;

long long min2(long long x,long long y)
{
    if(x<y)
        return x;
    else
        return y;
}

long long max2(long long x,long long y)
{
    if(x>y)
        return x;
    else
        return y;
}

long long solve_dp()
{
    long long i,j,k;
    long long x,y;
    long long min1;
    long long check;
    long long check1;

    for(i=1;i<=n;i++)
    {
        dp[i][i]=arr[i];

        dp1[i][i]=arr[i];
    }

    for(k=2;k<=n;k++)
    {
        for(i=1;i<=n-k+1;i++)
        {
            j=i+k-1;
            dp[i][j]=9999999999999999999999999;
            dp1[i][j]=-1;

            for(x=i;x<j;x++)
            {
                if(opr[x]=='+'){
                    check=dp[i][x]+dp[x+1][j];
                    check1=dp1[i][x]+dp1[x+1][j];

                    dp[i][j]=min2(dp[i][j],check);
                    dp1[i][j]=max2(dp1[i][j],check1);
                }
                else
                {
                    check=dp[i][x]*dp[x+1][j];
                    check1=dp1[i][x]*dp1[x+1][j];

                    dp[i][j]=min2(dp[i][j],check);
                    dp1[i][j]=max2(dp1[i][j],check1);
                }
            }
        }
    }

}

int main()
{
    long long test,i,j,k;
    long long x,y;
    long long ans,ans1;

    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        //memset(dp,0,sizeof(dp));
        //memset(dp1,0,sizeof(dp1));

        scanf("%s",str);

        j=0;    x=0;    y=0;
        while(str[j]!='\0')
        {
            if(j%2!=0) //odd
            {
                opr[++x]=str[j];
            }
            else
            {
                arr[++y]=str[j]-'0';
            }

            j++;
        }

        n=x+1;

        solve_dp();
        ans=dp[1][n];
        ans1=dp1[1][n];
        //ans to be included
        printf("%lld %lld\n",ans1,ans);
    }

    return 0;
}


