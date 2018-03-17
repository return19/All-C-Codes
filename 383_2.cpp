#include<bits/stdc++.h>
using namespace std;

long long arr[201000];

long long temp[201000];

int main()
{
    long long i,j,k;
    long long n;

    scanf("%lld",&n);

    for(i=0;i<n;i++)
    {
        scanf("%lld",&arr[i]);
    }

    long long cnt=0;

    for(i=0;i<n;i++)
    {
        temp[i]+=cnt;

        if(arr[i]==1)
            cnt++;
    }

    cnt=0;

    for(i=n-1;i>=0;i--)
    {
        temp[i]+=cnt;

        if(arr[i]==0)
            cnt++;
    }

    long long ans=0;
    long long sub=0;

    for(i=0;i<n;i++)
    {
        temp[i] -= sub;
        if(arr[i]==1)
            ans += temp[i];

        if(arr[i]==1)
            sub++;
    }

    sub=0;

    for(i=n-1;i>=0;i--)
    {
        temp[i] -= sub;
        if(arr[i]==0)
            ans += temp[i];

        if(arr[i]==0)
            sub++;
    }

    printf("%lld\n",ans);


    return 0;
}














