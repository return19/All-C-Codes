#include<bits/stdc++.h>
using namespace std;

long long arr[101000];

long long dp[101000];

int main()
{
    long long test,i,j,k,t;

    long long mx;

    long long n;

    scanf("%lld",&test);

    for(t=0;t<test;t++)
    {
        scanf("%lld",&n);

        for(i=0;i<n;i++)
        {
            scanf("%lld",&arr[i]);
        }

        dp[0]=dp[1]=0;

        mx=0;

        for(i=2;i<n;i++)
        {
            if(arr[i] == arr[i-1] + arr[i-2]){
                dp[i]=1;
                dp[i] += dp[i-1];
            }
            else
                dp[i]=0;



            mx=max(mx,dp[i]);
        }

        /*for(i=0;i<n;i++)
            cout<<dp[i]<<" ";
        cout<<endl;*/

        if(n>2)
            printf("%lld\n",mx+2);
        else
            printf("%lld\n",n);
    }

    return 0;
}
