#include<bits/stdc++.h>
using namespace std;

long long arr[201000];

int main()
{
    long long i,j,k;
    long long n;

    scanf("%lld",&n);

    for(i=0;i<n;i++)
    {
        scanf("%lld",&arr[i]);
    }

    long long ans=abs(arr[0]);

    for(i=1;i<n;i++)
    {
        ans += abs(arr[i-1]-arr[i]);
    }

    printf("%lld\n",ans);

    return 0;
}
















