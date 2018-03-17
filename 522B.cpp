#include<bits/stdc++.h>
using namespace std;

long long lmax[201000];
long long rmax[201000];

long long w[201000];
long long h[201000];

int main()
{
    long long i,j,k;
    long long n;
    long long wsum=0;

    scanf("%lld",&n);

    for(i=0;i<n;i++)
    {
        scanf("%lld%lld",&w[i],&h[i]);
        wsum+=w[i];
    }

    lmax[0]=h[0];
    rmax[n-1]=h[n-1];

    for(i=1,j=n-2;i<n;i++,j--)
    {
        lmax[i]=max(lmax[i-1],h[i]);
        rmax[j]=max(rmax[j+1],h[j]);
    }

    for(i=0;i<n;i++)
    {
        long long h=LLONG_MIN,wp=wsum-w[i];

        if(i!=0)
            h=max(h,lmax[i-1]);
        if(i!=n-1)
            h=max(h,rmax[i+1]);

        printf("%lld ",h*wp);
    }

    return 0;
}















