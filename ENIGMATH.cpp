#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a,long long b)
{
    if (b)
        return gcd(b, a % b);
    else
        return a;
}
/*
long long gcd(long long a,long long b)
{
    while(a!=b)
    {
        if(a>b)
        {
            return gcd(a-b,b);
        }
        else
        {
            return gcd(a,b-a);
        }
    }
    return a;
}*/

int main()
{
    long long test,i,j,k,a,b;
    long long x;

    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        scanf("%lld%lld",&a,&b);

        x=gcd(a,b);

        printf("%lld %lld\n",b/x,a/x);
    }

    return 0;
}









