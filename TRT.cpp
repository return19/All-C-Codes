#include<bits/stdc++.h>
using namespace std;

long long arr[2010];
long long dp[2010][2010];

long long n;

long long max2(long long x,long long y)
{
    if(x>y)
        return x;
    else
        return y;
}

long long init()
{
    long long i,j,k;

    for(k=0;k<n;k++)
    {

        for(i=0;i<n-k;i++)
        {
            j=k+i;

            if(i!=j)
                dp[i][j]=max2(arr[i]*(n-(j-i))+dp[i+1][j],arr[j]*(n-(j-i))+dp[i][j-1]);
            else
                dp[i][j]=arr[i]*n;
        }
    }
    return dp[0][n-1];

}

int main()
{
    long long i,j,k,ans;

    scanf("%lld",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld",&arr[i]);
    }

    ans=init();

    /*for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
            cout<<dp[i][j]<<"\t";
        cout<<endl;
    }*/

    printf("%lld\n",ans);



    return 0;
}
