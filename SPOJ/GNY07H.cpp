#include<bits/stdc++.h>
using namespace std;

int dp[1100];

void solve()
{
    int i,j,k;

    dp[0]=0;
    dp[1]=1;
    dp[2]=5;
    dp[3]=11;

    for(i=4;i<1001;i++)
    {
        dp[i]=(8*dp[i-2]+2*dp[i-3]+dp[i-4]-8);
    }
}

int main()
{
    int test,i,j,k,n;

    scanf("%d",&test);

    solve();

    for(i=0;i<test;i++)
    {
        scanf("%d",&n);
        cout<<dp[n]<<endl;
    }

    return 0;
}
