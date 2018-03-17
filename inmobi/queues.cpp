#include<bits/stdc++.h>
using namespace std;

long long arr[1010000];

int main()
{
    long long test,i,j,k,t;

    long long n,sum;

    scanf("%lld",&test);

    for(t=0;t<test;t++)
    {
        scanf("%lld",&n);

        for(i=0;i<n;i++)
            scanf("%lld",&arr[i]);

        sort(arr,arr+n);

        long long ans=0;

        sum=0;

        for(i=0;i<n;i++)
        {
            if(sum>arr[i])
                continue;

            ans++;

            sum += arr[i];
        }

        printf("%lld\n",ans);
    }

    return 0;
}








