#include<bits/stdc++.h>
using namespace std;

long long arr[110];

int main()
{
    long long i,j,k;
    long long n,m;
    long long x,y,z;

    scanf("%lld%lld",&n,&m);

    for(i=0;i<m;i++){
        scanf("%lld%lld%lld",&x,&y,&z);

        arr[x]-=z;
        arr[y]+=z;
    }

    long long ans=0;

    for(i=0;i<=n;i++){
        if(arr[i]>=0)
            ans += arr[i];
    }

    printf("%lld\n",ans);
    return 0;
}
