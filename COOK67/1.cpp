#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long i,j,k;
    long long test,t;
    long long d,n;

    scanf("%lld",&test);

    for(t=0;t<test;t++)
    {
        scanf("%lld%lld",&d,&n);

        long long ans=0;

        for(i=0;i<d;i++)
        {
            n=n*(n+1)/2;
        }
        printf("%lld\n",n);
    }

    return 0;
}
