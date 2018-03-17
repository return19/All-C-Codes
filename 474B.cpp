#include<bits/stdc++.h>
using namespace std;

long long arr[101000];

int main()
{
    long long i,j,k;
    long long n;
    long long q;
    long long x,y;

    scanf("%lld",&n);

    for(i=1;i<=n;i++)
    {
        scanf("%lld",&arr[i]);
        arr[i]+=arr[i-1];
    }

    scanf("%lld",&q);

    for(i=0;i<q;i++)
    {
        scanf("%lld",&x);

        long long ans=lower_bound(arr+1,arr+n+1,x) - arr;

        printf("%lld\n",ans);
    }


    return 0;
}
