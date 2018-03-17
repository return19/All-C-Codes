#include<bits/stdc++.h>
using namespace std;

unsigned long long dp[15][100];

void cal_dp()
{
    unsigned long long i,j,k;
    unsigned long long  sum=0;


    for(i=1;i<15;i++)
    {
        dp[i][0]=1;
    }

    for(i=2;i<15;i++)
    {
        for(j=1;j<100&&j<=(i*(i-1))/2;j++)
        {
            sum=0;

            for(k=0;k<i&&j-k>=0;k++)
            {
                sum=sum+dp[i-1][j-k];
            }

            dp[i][j]=sum;
        }
    }
}


int main()
{
    unsigned long long test,i,j,k;
    unsigned long long a,b;

    cal_dp();

    scanf("%llu",&test);

    /*for(i=0;i<15;i++)
    {
        for(j=0;j<15;j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/

    for(i=0;i<test;i++)
    {
        scanf("%llu%llu",&a,&b);

        printf("%llu\n",dp[a][b]);
    }

    return 0;
}
