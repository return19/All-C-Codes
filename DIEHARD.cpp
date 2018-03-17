#include<bits/stdc++.h>
using namespace std;

long long dp[2100][2100];

long long max2(long long x,long long y)
{
    if(x>y)
        return x;
    else
        return y;
}


long long find_it(long long h,long long a)
{
    long long ans1=0;
    long long ans2=0;

    if(h-5>0&&a-10>0)
    {
        ans1=2+find_it(h-5+3,a-10+2);
    }

    if(h-20>0)
    {
        ans2=2+find_it(h-20+3,a+5+2);
    }

    return max2(ans1,ans2);
}

void find_dp()
{
    long long i,j,k;
    long long ans1,ans2;

    for(i=1;i<=2000;i++)
    {
        for(j=1;j<=2000;j++)
        {
            ans1=0;
            ans2=0;

            if(i-5>0&&j-10>0)
            {
                ans1=2+dp[i-5+3][j-10+2];
            }

            if(i-20>0)
            {
                ans2=2+dp[i-20+3][j+5+2];
            }

            dp[i][j]=max2(ans1,ans2);

        }
    }

    /*for(i=0;i<=h;i++)
    {
        cout<<i<<" ";
        for(j=0;j<=a;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }*/

    //return dp[h][a];
}

int main()
{
    long long test,i,j,k;
    long long h,a;
    long long ans;

    find_dp();
    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {

        scanf("%lld%lld",&h,&a);

        ans=1+dp[h+3][a+2];

        printf("%lld\n",ans);
    }

    return 0;
}
