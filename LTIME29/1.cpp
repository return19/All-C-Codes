#include<bits/stdc++.h>
using namespace std;

long long arr[210][210];


int main()
{
    long long test,t,i,j,k;
    long long n,m,s;
    long long x,y;

    scanf("%lld",&test);

    for(t=0;t<test;t++)
    {
        scanf("%lld%lld",&n,&m);
        scanf("%lld",&s);

        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                scanf("%lld",&arr[i][j]);
            }
        }

        for(i=1;i<=n;i++)
        {
            for(j=0;j<=m;j++)
            {
                arr[i][j] += arr[i-1][j] + arr[i][j-1] - arr[i-1][j-1];
            }
        }

        long long ans=0;

        for(x=1;x<=n;x++)
        {
            for(y=1;y<=m;y++)
            {
                for(i=x;i<=n;i++)
                {
                    for(j=y;j<=m;j++)
                    {
                        if(arr[i][j]-arr[x-1][j] - arr[i][y-1] + arr[x-1][y-1]<=s)
                            ans++;

                    }
                }
            }
        }

        printf("%lld\n",ans);
    }

    return 0;
}









