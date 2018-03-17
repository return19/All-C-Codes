#include<bits/stdc++.h>
using namespace std;


long long MOD2=1000000007;
long long M3=1000000007;
long long abs1(long long x)
{
    if(x>=0)
        return x;
    return x*(-1);
}
 long long fact[3000010];
 long long rev_fact[3000010];

 long long countFact( long long n,  long long p)
{
     long long k=0;
    while (n>=p)
    {
        k+=n/p;
        n/=p;
    }
    return k;
}

/* This function calculates (a^b)%MOD */
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

long long factMOD(long long n, long long MOD)
{
    long long res = 1;
    while (n > 0)
    {
        for (long long i=2, m=n%MOD; i<=m; i++)
            res = (res * i) % MOD;
        if ((n/=MOD)%2 > 0)
            res = MOD - res;
    }
    return res;
}

long long C(long long n, long long r, long long MOD)
{
    if (countFact(n, MOD) > countFact(r, MOD) + countFact(n-r, MOD))
        return 0;

    return (factMOD(n, MOD) *
            ((modInverse(factMOD(r, MOD), MOD) *
            modInverse(factMOD(n-r, MOD), MOD)) % MOD)) % MOD;
}

void calc()
{
    long long i,j,k;
    long long val=1;
    fact[0]=fact[1]=1;

    for(i=2;i<2000010;i++)
    {
        fact[i]=(fact[i-1]*i)%M3;
        //rev_fact[i]=(rev_fact[i-1]*modInverse(i,M3))%M3;
    }
}

int main()
{
    long long test,i,j,x,y;
    long long n,k;
    long long t,val,abs_val;
    long long p,q,sum;
    calc();
    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        sum=0;
        scanf("%lld%lld",&n,&k);

        for(x=1;x<=n;x++)
        {
            for(y=1;y<=n;y++)
            {
                p=abs1(k);
                q=abs1(x-y);
                //val=p*q+1;
                //cout<<0<<","<<x<<" | "<<k<<","<<y<<" : ";
                //cout<<"val : "<<val<<endl;
                sum=(sum+((fact[p+q]*modInverse(fact[q],M3))%MOD2)*modInverse(fact[p],M3))%1000000007;
            }
        }

        printf("%lld\n",sum);
    }

    return 0;
}
