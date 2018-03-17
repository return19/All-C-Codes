#include<bits/stdc++.h>
using namespace std;

long long b,n;

long long fee_min;

long long p[10010],fn[10010];

long long dp[1010][1010];
//long long fee[1010][1010];

long long max2(long long x,long long y)
{
    if(x>y)
        return x;
    else
        return y;
}

void init()
{
    long long i,j,k,taken,not_taken;
    fee_min=99999999999;
//    fn_max=-99999999;

    for(i=0;i<=n;i++)
        dp[i][0]=0;

    for(j=0;j<=b;j++)
    {
        dp[0][j]=0;
    }

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=b;j++)
        {
            if(p[i-1]>j){
                dp[i][j]=dp[i-1][j];
                //fee[i][j]=fee[i-1][j];
            }
            else
            {
                dp[i][j]=max2(dp[i-1][j],fn[i-1]+dp[i-1][j-p[i-1]]);


            }

            /*if(fn_max==dp[i][j]&&fee[i][j]<fee_min)
            {
                fee_min=fee[i][j];
            }
            else if(fn_max<dp[i][j])
            {
                fn_max=dp[i][j];
                fee_min=fee[i][j];
            }*/
        }
    }

}


int main()
{
    long long i,j,k;

    scanf("%lld%lld",&b,&n);

    while(b!=0&&n!=0)
    {


        for(i=0;i<n;i++)
        {
            scanf("%lld%lld",&p[i],&fn[i]);
        }

        init();


        ///////////


        /*for(i=0;i<=n;i++)
        {
            for(j=0;j<=b;j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }*/
        ///////////

        for(i=b;i>0;i--)
        {
            if(dp[n][i]<dp[n][b])
                break;
            fee_min=i;
        }

        printf("%lld %lld\n",fee_min,dp[n][b]);

        scanf("%lld%lld",&b,&n);
    }

    return 0;
}
