#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long test,n,k,t,f,i,j;
    long long x;
    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        scanf("%lld%lld%lld%lld",&n,&k,&t,&f);
        x=(f-n)/(k-1);

        printf("%lld\n",n+k*x);

    }

    return 0;
}
