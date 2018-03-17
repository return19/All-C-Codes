#include<bits/stdc++.h>
using namespace std;

long long arr[1010000];

long long mrg(long long arr[],long long l,long long mid,long long r);

long long invcnt(long long arr[],long long l,long long r)
{
    if(l<r)
    {
        long long ans1,ans2;
        long long mid=l + (r-l)/2;

        ans1=invcnt(arr,l,mid);
        ans2=invcnt(arr,mid+1,r);

        return (ans1 + ans2 + mrg(arr,l,mid,r));
    }

    return 0;
}

long long mrg(long long arr[],long long l,long long mid,long long r)
{
    if(l>=r)
        return 0;

    long long i,j,k;
    long long temp[r-l+1];

    i=l;
    j=mid+1;
    k=-1;

    long long ans=0;

    while(i<=mid&&j<=r)
    {
        if(arr[i]<=arr[j])
            temp[++k]=arr[i++];
        else
        {
            temp[++k]=arr[j++];
            ans += mid-i+1;
        }
    }

    while(i<=mid)
        temp[++k]=arr[i++];

    while(j<=r)
        temp[++k]=arr[j++];

    for(i=0;i<=k;i++)
        arr[i+l]=temp[i];

    return ans;
}

int main()
{
    long long test,i,j,k,t;
    long long n;

    scanf("%lld",&test);

    for(t=0;t<test;t++)
    {
        scanf("%lld",&n);

        for(i=0;i<n;i++)
            scanf("%lld",&arr[i]);

        long long ans=invcnt(arr,0,n-1);

        printf("%lld\n",ans);
    }

    return 0;
}
