#include<bits/stdc++.h>
using namespace std;
#define M 1000000007


/*long long find_count(long long runs,long long balls,long long wickets)
{
    long long i,j,k,ans=0;
    if(balls==0&&runs!=0)
        return 0;
    if(balls==0&&runs==0)
        return 1;

    ans=find_count(runs-0,balls-1,wickets);

    if(runs>=4)
        ans+=find_count(runs-4,balls-1,wickets);
    if(runs>=6)
        ans=ans+find_count(runs-6,balls-1,wickets);

    if(wickets>0)
    {
        ans=ans+find_count(runs,balls-1,wickets-1);
    }
    return ans;
}*/

long long dp[200010][310];
long long w[200010][310];
long long find_count(long long runs,long long balls,long long wickets)
{
    long long i,j,k,x,y;

    w[0][0]=wickets;
    for(i=1;i<=runs;i++)
    {
            dp[i][0]=0;
            w[i][0]=wickets;
    }

    dp[0][0]=1;
    for(i=0;i<=runs;i++)
    {
        for(j=1;j<=balls;j++)
        {
            dp[i][j]=(dp[i][j-1])%M;
            if(i>=4)
                dp[i][j]=(dp[i][j]+dp[i-4][j-1])%M;
            if(i>=6)
                dp[i][j]=(dp[i][j]+dp[i-6][j-1])%M;



            if(w[i][j-1]>0)
            {
                dp[i][j]=(dp[i][j]+dp[i][j-1])%M;
                w[i][j]=w[i][j-1];
            }
        }
    }

    return dp[runs][balls];
}


int main()
{
    long long test,i,j,k,r,b,l,ans;
    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        //memset(dp,0,sizeof(dp));

        scanf("%lld%lld%lld",&r,&b,&l);

        if(r>6*b||r%2!=0)
        {
            printf("0\n");
            continue;
        }


        ans=find_count(r,b,l);
        printf("%lld\n",ans);
    }


    return 0;
}
