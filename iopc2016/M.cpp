#include<bits/stdc++.h>
using namespace std;

unsigned long long n;

unsigned long long solve(unsigned long long x)
{
    unsigned long long i,j,k;
    unsigned long long lc=0,rc=0;

    unsigned long long l=x;
    while(l*2<=n)
    {
        l=l*2;
        lc++;
    }
    unsigned long long r=x;
    while(r*2 +1 <=n)
    {
        r=r*2 +1;
        rc++;
    }

    if(lc==rc)
        return (r-l+1);

    return ((n-l+1) + (r- n/2));
}

int main()
{
    unsigned long long i,j,k;
    unsigned long long test,t;
    unsigned long long q,x,y,z;
    scanf("%lld",&test);

    for(t=0;t<test;t++)
    {
        scanf("%lld%lld",&n,&q);

        for(i=0;i<q;i++)
        {
            scanf("%lld",&x);

            unsigned long long ans=solve(x);
            printf("%lld\n",ans);
        }
    }

    return 0;
}
