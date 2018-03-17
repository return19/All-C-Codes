#include<bits/stdc++.h>
using namespace std;

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
}

int main()
{
    long long test,i,j,k;
    long long a,b;
    long long ans;

    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        scanf("%lld%lld",&a,&b);

        if(a>b)
        {
            ans=(a-b)/gcd(abs(a),abs(b));
        }
        else
        {
            ans=(b-a)/gcd(abs(a),abs(b));
        }

        printf("%lld\n",ans);
    }

    return 0;
}




