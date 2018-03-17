#include<bits/stdc++.h>
using namespace std;

long long arr[201000];

int main()
{
    long long i,j,k;
    long long n;
    long long mn=LLONG_MAX;

    scanf("%lld",&n);

    for(i=0;i<n;i++)
    {
        scanf("%lld",&arr[i]);
        mn=min(mn,arr[i]);
    }

    long long ans=n*mn;

    for(i=0;i<n;i++)
        if(arr[i]==mn)
            arr[i]=1;
        else
            arr[i]=0;

    long long mx_s=LLONG_MIN;

    j=0;

    for(i=0;i<n;i++)
    {
        if(arr[i]==1)
        {
            j=i;
            break;
        }
    }

    k=j;

    for(i=j+1;i<n;i++)
    {
        if(arr[i]==1)
        {
            mx_s=max(mx_s,i-k-1);
            k=i;
        }
    }

    long long f=0,l=n;

    f=j;

    for(i=n-1;i>=0;i--)
        if(arr[i]==1)
            break;
    l=n-i-1;

    mx_s=max(mx_s,f+l);

    printf("%lld\n",ans + mx_s);

    return 0;
}











