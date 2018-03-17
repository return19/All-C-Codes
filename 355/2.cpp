#include<bits/stdc++.h>
using namespace std;

long long arr[101000];

int main()
{
    long long i,j;
    long long n,h,k;
    long long ans=0;

    scanf("%lld%lld%lld",&n,&h,&k);

    for(i=0;i<n;i++){
        scanf("%lld",&arr[i]);
    }

    i=0;
    long long cur=0;

    while(i<n || cur!=0){
        while(i<n && cur+arr[i]<=h)
        {
            cur+=arr[i];
            i++;
        }

        if(i==n){
            ans += cur/k;
            if(cur%k!=0)
                ans++;
            break;
        }

        if(cur<=k){
            cur=0;
            ans++;
            continue;
        }

        ans += cur/k;
        cur=cur%k;
    }

    printf("%lld\n",ans);

    return 0;
}
