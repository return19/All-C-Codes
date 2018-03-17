#include<bits/stdc++.h>
using namespace std;

long long arr[101000];

long long max2(long long x,long long y)
{
    if(x>y)
        return x;
    return y;
}

int main()
{
    long long test,i,j,k;
    long long n;
    long long ans;
    long long m;

    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        scanf("%lld",&n);

        ans=0;

        for(j=1;j<=n;j++)
        {
            scanf("%lld",&arr[j]);
        }

        for(j=1;j<=n;j++)
        {
            ans=ans+max2(arr[j]-arr[j-1],0);
        }

        printf("%lld\n",ans);
    }

    return 0;
}
