#include<bits/stdc++.h>
using namespace std;

long long arr[10010];
long long dp[10010][10010];
long long m[10010][10010];
long long n;
void init()
{
    long long l,i,j,k,temp,min1;


        for(j=0;j<n;j++){
             m[j][j]=0;
             dp[j][j]=arr[j];
        }

        for(l=1;l<n;l++)
        {
            for(i=0;i<n-l;i++)
            {
                j=i+l;
                min1=10000000000;
                for(k=i;k<=j-1;k++)
                {
                    temp=m[i][k]+m[k+1][j]+dp[i][k]*dp[k+1][j];

                    if(min1>temp)
                    {
                        min1=temp;
                        m[i][j]=temp;
                        dp[i][j]=(dp[i][k]+dp[k+1][j])%100;
                    }
                }
            }
        }



}

int main()
{
    long long i,j;
    while(scanf("%lld",&n)>0)
    {
        for(i=0;i<n;i++)
        {
            scanf("%lld",&arr[i]);
        }
        init();
        printf("%lld\n",m[0][n-1]);
    }
    return 0;
}
