#include<bits/stdc++.h>
using namespace std;

long long arr[101000];
long long csum[101000];
long long n;
long long m;

int main()
{
    long long test,i,j,k;
    long long t;

    scanf("%lld",&n);

    for(i=1;i<=n;i++)
    {
        scanf("%lld",&arr[i]);
    }

    sort(arr+1,arr+n+1);

    csum[0]=0;

    for(i=1;i<=n;i++)
        csum[i]=csum[i-1] + arr[i];

    scanf("%lld",&m);

    long long x;

    for(i=0;i<m;i++)
    {
        scanf("%lld",&x);

        long long foo=ceil(((double)n)/(x+1));

        printf("%lld\n",csum[foo]);
    }

    return 0;
}








