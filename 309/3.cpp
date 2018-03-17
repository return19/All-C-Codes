#include<bits/stdc++.h>
using namespace std;

long long fact[10100];
long long rev_fact[10100];

long long MOD=1000000007;
long long M3=1000000007;

long long pow(long long a, long long b, long long MOD) {
long long x = 1, y = a;
    while(b > 0) {
        if(b%2 == 1) {
            x=(x*y)%M3;
            if(x>MOD) x%=MOD;
        }
        y = (y*y)%M3;
        if(y>MOD) y%=MOD;
        b /= 2;
    }
    return x;
}

long long modInverse(long long a, long long m) {
    return pow(a,m-2,m)%M3;
}


void calc()
{
    long long i,j,k;

    fact[0]=fact[1]=1;
    rev_fact[0]=rev_fact[1]=1;

    for(i=2;i<10010;i++)
    {
        fact[i]=(fact[i-1]*i)%MOD;
        rev_fact[i]=(rev_fact[i-1]*modInverse(i,M3))%M3;
    }
}

long long arr[11000];
long long sum[11000];

int main()
{
    long long i,j,k;
    long long n;

    calc();

    scanf("%lld",&n);

    for(i=0;i<n;i++)
    {
        scanf("%lld",&arr[i]);
    }

    /*sum[0]=arr[0];

    for(i=1;i<n;i++)
    {
        sum[i]=sum[i-1]+sum[i];
    }*/

    long long ans=1;
    long long c=1;

    for(i=0;i<n;i++)
    {
        for(j=0;j<arr[i]-1;j++)
        {
            ans=(ans*c)%MOD;
            c++;
        }
        c++;
    }

    //cout<<"init : "<<ans<<endl;

    for(i=0;i<n;i++)
    {
        ans=(ans*rev_fact[arr[i]-1])%MOD;
    }

    printf("%lld\n",ans%MOD);


    return 0;
}












