
#include<bits/stdc++.h>
using namespace std;

long long arr[1000100];
long long dp[1000100][71];
long long n;
long long logt[100010000];


long long min2(long long x,long long y)
{
    if(x<y)
        return x;
    else
        return y;
}

long long max2(long long x,long long y)
{
    if(x>y)
        return x;
    else
        return y;
}

void prepros()
{
    long long i,j,k;

    memset(dp,0,sizeof(dp));

    for(i=0;i<n;i++)
    {
        dp[i][0]=arr[i];
    }

    for(j=1;(1<<j)<=n;j++)
    {
        for(i=0;i+(1<<(j-1))<n;i++)
        {
            if(dp[i][j-1]>dp[i+(1<<(j-1))][j-1])
            {
                dp[i][j]=dp[i][j-1];
            }
            else
            {
                dp[i][j]=dp[i+(1<<(j-1))][j-1];
            }
        }
    }

    /*for(i=0;i<n;i++)
    {
        for(j=0;1<<j<=n;j++)
            cout<<dp[i][j]<<" ";
        cout<<endl;
    }*/
}

long long qry(long long a,long long b)
{
    long long i,j,k;

    long long sz=logt[b-a+1]/logt[2];

    long long ans=max2(dp[a][sz],dp[b-(1<<sz)+1][sz]);

    return ans;
}

int main()
{
    long long test,i,j,k;
    long long ans=0;
    long long q,a,b;
    long long m,x,y;
    long long l,r;
    long long z=0,z1;





        scanf("%lld",&n);

        for(z1=1;2*z1<=n+10;z1=z1*2)
        {
            logt[z1*2]=1;
        }

        for(z1=2;z1<=n+1;z1++)
        {
            if(logt[z1]==1)
            {
                z++;
            }

            logt[z1]=z;
        }

        for(j=0;j<n;j++)
        {
            scanf("%lld",&arr[j]);
        }

        prepros();

        scanf("%lld%lld%lld",&m,&x,&y);

        ans=qry(x,y);

        for(j=2;j<=m;j++)
        {
            x=(x+7)%(n-1);
            y=(y+11)%n;

            l=min2(x,y);
            r=max2(x,y);

            ans=ans+qry(l,r);
        }

        printf("%lld\n",ans);

       /* scanf("%d",&q);

        for(j=0;j<q;j++)
        {
            scanf("%d%d",&a,&b);

            ans=qry(a,b);
            printf("%d\n",ans);
        }*/


    return 0;
}
