#include<bits/stdc++.h>
using namespace std;

long long s[101000];
long long arr[101000];

long long check_pal(long long n)
{
    long long x=0;

    long long t=n;

    while(t!=0)
    {
        x=x*10 + t%10;
        t=t/10;
    }

    if(x==n)
        return 1;
    return 0;
}

void pre()
{
    long long i,j,k;

    for(i=0;i<=100010;i++)
    {
        if(check_pal(i))
            s[i]=1;
    }

    s[0]=1;

    for(i=1;i<100010;i++)
    {
        arr[i]=arr[i-1];

        if(s[i]==1)
            arr[i]+=i;
    }

}

int main()
{
    long long i,j,k;
    long long t,test;
    long long l,r;

    pre();
    scanf("%lld",&test);

    for(t=0;t<test;t++)
    {
        scanf("%lld%lld",&l,&r);

        printf("%lld\n",arr[r]-arr[l-1]);
    }

    return 0;
}







