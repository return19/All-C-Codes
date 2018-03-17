#include<bits/stdc++.h>
using namespace std;

long long n;
long long arr[101000];
long long mx[101000];
long long mn[101000];

int main()
{
    long long i,j,k;

    scanf("%lld",&n);
    for(i=1;i<=n;i++)
        scanf("%lld",&arr[i]);

    for(i=1;i<=n;i++)
        mx[i]=max(arr[i],mx[i-1]);

    mn[n+1]=LLONG_MAX;
    for(i=n;i>=1;i--)
    {
        mn[i]=min(arr[i],mn[i+1]);
    }

    long long ans=1;

    for(i=1;i<n;i++)
    {
        if(mx[i]<=mn[i+1])
            ans++;
    }

    printf("%lld\n",ans);

    return 0;
}








