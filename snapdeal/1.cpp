#include<bits/stdc++.h>
using namespace std;

long long M=1000000007;

long long arr[2510][2510];

long long dp[2510][2510];
long long d[2510][2510];
long long u[2510][2510];
long long l[2510][2510];

long long n,m;

int main()
{
    long long i,j,k;

    scanf("%d%d",&n,&m);

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            scanf("%d",&arr[i][j]);
            dp[i][j]=0;
        }
    }

    dp[1][1]=arr[1][1];
    d[1][1]=arr[1][1];

    for(i=2;i<=n;i++)
    {
        arr[i][1]=(dp[i-1][1]*arr[i][1])%M;
        dp[i][1] = (dp[i-1][1] + arr[i][1])%M;
        l[i][1]=arr[i][1];
        d[i][1]=arr[i][1];
    }

    for(j=2;j<=m;j++)
    {
        arr[1][j] = (arr[1][j] * dp[1][j-1])%M;
        dp[1][j] = (arr[1][j] + dp[1][j-1])%M;
        u[1][j]=arr[1][j];
        d[1][j]=arr[1][j];

    }
    long long temp;

    for(i=2;i<=n;i++)
    {
        for(j=2;j<=m;j++)
        {
            temp = arr[i][j];

            arr[i][j] = (temp*u[i-1][j] + (temp*l[i][j-1] + temp*d[i-1][j-1])%M)%M;
            d[i][j]= (arr[i][j] + d[i-1][j-1])%M;
            l[i][j]=(arr[i][j] + l[i][j-1])%M;
            u[i][j]=(arr[i][j] + u[i-1][j])%M;
        }
    }

   /* for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }*/

    printf("%d\n",arr[n][m]);



    return 0;
}







