#include<bits/stdc++.h>
using namespace std;

long long arr[1010000];

int main()
{
    long long i,j,k;
    long long n;
    long long xr = 0;

    scanf("%lld",&n);
    for(i=0;i<n;i++){
        scanf("%lld",&arr[i]);
        xr = xr ^ arr[i];
    }

    long long ans = xr;

    for(i=0;i<n;i++){
        long long temp = xr ^ arr[i];
        ans = min(ans,temp);
    }

    printf("%lld\n",ans);
    return 0;
}
