#include<bits/stdc++.h>
using namespace std;

long long agnes[2100];
long long boy[2100];

long long dp[2100][2100];

long long n_agnes,n_boy;

long long max2(long long x,long long y)
{
    if(x>y)
        return x;
    else
        return y;
}

long long init_dp()
{
    long long i,j,k;

    for(i=0;i<=n_agnes;i++)
    {
        for(j=0;j<=n_boy;j++)
        {
            if(i==0||j==0){
                dp[i][j]=0;
            }
            else if(agnes[i-1]==boy[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else
            {
                dp[i][j]=max2(dp[i-1][j],dp[i][j-1]);
            }

        }
    }
   /* cout<<"n_agnes : "<<n_agnes<<endl;
    cout<<"n_boy : "<<n_boy<<endl;

    for(i=0;i<n_agnes;i++)
    {
        for(j=0;j<n_boy;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }*/
    return dp[n_agnes][n_boy];


}

int main()
{
    long long test,i,j,k;
    long long temp;
    scanf("%lld",&test);
    long long max1=-999999;
    long long ans;
    for(i=0;i<test;i++)
    {
        max1=-999999;
        scanf("%lld",&temp);
        j=0;
        while(temp!=0)
        {
            agnes[j++]=temp;
            scanf("%lld",&temp);
        }
        n_agnes=j;

        scanf("%lld",&temp);

        while(temp!=0)
        {

            j=0;
            while(temp!=0)
            {
                boy[j++]=temp;
                scanf("%lld",&temp);
            }
            n_boy=j;

           /* for(j=0;j<n_agnes;j++)
                cout<<agnes[j]<<" ";
            cout<<endl;
             for(j=0;j<n_boy;j++)
                cout<<boy[j]<<" ";
            cout<<endl;*/

            ans=init_dp();
            if(max1<ans)
                max1=ans;
            scanf("%lld",&temp);
        }

        printf("%lld\n",max1);
    }

    return 0;
}











