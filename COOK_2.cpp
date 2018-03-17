#include<bits/stdc++.h>
using namespace std;


long long dp[1010][1010];
long long min2(long long x,long long y)
{
    if(x<y)
        return x;
    else
        return y;
}

int main()
{
    long long test,i,j,k,n,d,sum;
    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        sum=0;
        scanf("%lld%lld",&n,&d);
        if(n==1){
            d=d-1;
            sum=sum+(d*(d+1)*(2*d+1))/6;
            printf("%lld\n",sum);
        }
        else
        {
            for(k=0;k<d;k++)
            {
                dp[0][k]=(0^k)*(0+k);
            }
            for(j=1;j<d;j++)
            {
                for(k=0;k<d;k++)
                {
                    if(k==0)
                    {
                        dp[j][k]=dp[j-1][k]+(j^k)*(j+k);
                    }
                    else
                    {
                        dp[j][k]=(j^k)*(j+k) + min2(dp[j-1][k],dp[j][k-1]);
                    }
                }
            }
            printf("%lld\n",dp[d-1][d-1]);
        }

    }
    return 0;
}
