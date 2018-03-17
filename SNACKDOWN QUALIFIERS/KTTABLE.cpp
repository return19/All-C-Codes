#include<bits/stdc++.h>
using namespace std;

long long arr[101000];

int main()
{
    long long i,j,k;
    long long test,t;
    long long n;
    long long x,y,z;

    scanf("%lld",&test);

    for(t=0;t<test;t++){
        scanf("%lld",&n);

        for(i=0;i<n;i++)
            scanf("%lld",&arr[i]);

        long long ans=0;
        long long p=0;
        for(i=0;i<n;i++){
            scanf("%lld",&x);

            if(arr[i]-p>=x)
                ans++;
            p=arr[i];
        }

        printf("%lld\n",ans);
    }
    return 0;
}















