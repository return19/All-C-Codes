#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long i,j,k;
    long long n;
    long long test,t;

    scanf("%lld",&test);

    for(t=0;t<test;t++)
    {
        scanf("%lld",&n);
        n--;

        long long x=n/3;
        long long y=n/5;
        long long z=n/15;

        x= 3*(x)*(x+1)/2;
        y= 5*(y)*(y+1)/2;
        z= 15*(z)*(z+1)/2;

        long long ans=x+y-z;
        printf("%lld\n",ans);
    }


    return 0;
}
