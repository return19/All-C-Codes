#include<bits/stdc++.h>
using namespace std;

long long table[2010][2010];
long long ans[2010][2010];

long long M=1000000000;

long long n,m;

void solve()
{
    long long i,j,k;
    long long sum=0;
    table[1][1]=1;

    for(i=0;i<=2005;i++)
        table[i][0]=1;

    for(i=1;i<=2004;i++)
    {
        sum=0;
        for(j=0;j<=i;j++)
        {
            sum=(sum+table[i][j])%M;
            if(j==i-1)
                table[i][j+1]=sum;
            table[i+1][j]=sum;
        }
    }

   /* for(i=0;i<8;i++)
    {
        for(j=0;j<=i;j++)
            cout<<table[i][j]<<" ";
        cout<<endl;
    }
    */
}


long long solve1()
{
    long long i,j,k;
    long long sum;

    for(j=0;j<=m;j++)
    {
        ans[1][j]=table[m][j];
    }

    for(i=1;i<=n;i++)
    {
        ans[i][0]=1;
    }

    for(i=1;i<n;i++)
    {
        sum=1;
        for(j=1;j<=m;j++)
        {
            sum=(sum+ans[i][j])%M;
            ans[i+1][j]=(sum*ans[1][j])%M;
        }
    }

    /*for(i=1;i<=n;i++)
    {
        for(j=0;j<=m;j++)
            cout<<ans[i][j]<<" ";
        cout<<endl;
    }*/

    sum=0;
    for(j=0;j<=m;j++)
        sum=(sum+ans[n][j])%M;

    return sum;

}

int main()
{
    long long test,i,j,k;
    long long ans;
    solve();

    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        scanf("%lld%lld",&n,&m);

        ans=solve1();
        printf("%lld\n",ans);
    }


    return 0;
}















