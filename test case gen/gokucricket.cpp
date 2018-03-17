#include<bits/stdc++.h>
using namespace std;

long long arr[101000];

int main()
{
    long long i,j,k;
    long long n;

    scanf("%lld%lld",&n,&k);
    for(i=0;i<n;i++)
        scanf("%lld",&arr[i]);

    long long ans=-1;
    for(i=0;i<n-1;i++){
        if(arr[i+1]-arr[i]>k){
            ans = arr[i]+k-1;
            break;
        }
    }
    if(ans==-1)
        ans = arr[n-1]+k-1;
    printf("%lld\n",ans-arr[0]+1);
    return 0;
}
