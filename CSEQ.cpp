#include<bits/stdc++.h>
using namespace std;
#include<vector>
#define M3 1000003

unsigned long long fact[1000010];
unsigned long long rev_fact[1000010];

unsigned long long countFact(unsigned long long n, unsigned long long p)
{
    unsigned long long k=0;
    while (n>=p)
    {
        k+=n/p;
        n/=p;
    }
    return k;
}

/* This function calculates (a^b)%MOD */
unsigned long long pow(unsigned long long a, unsigned long long b, unsigned long long MOD) {
unsigned long long x = 1, y = a;
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

unsigned long long modInverse(unsigned long long a, unsigned long long m) {
    return pow(a,m-2,m)%M3;
}

unsigned long long factMOD(unsigned long long n, unsigned long long MOD)
{
    unsigned long long res = 1;
    while (n > 0)
    {
        for (unsigned long long i=2, m=n%MOD; i<=m; i++)
            res = (res * i) % MOD;
        if ((n/=MOD)%2 > 0)
            res = MOD - res;
    }
    return res;
}

unsigned long long C(unsigned long long n, unsigned long long r, unsigned long long MOD)
{
    if (countFact(n, MOD) > countFact(r, MOD) + countFact(n-r, MOD))
        return 0;

    return (factMOD(n, MOD) *
            ((modInverse(factMOD(r, MOD), MOD) *
            modInverse(factMOD(n-r, MOD), MOD)) % MOD)) % MOD;
}

void calc()
{
    unsigned long long i,j,k;
    unsigned long long val=1;
    fact[1]=modInverse(1,M3);
    rev_fact[0]=rev_fact[1]=1;

    for(i=2;i<1000010;i++)
    {
        fact[i]=(fact[i-1]*i)%M3;
        rev_fact[i]=(rev_fact[i-1]*modInverse(i,M3))%M3;
    }
}

int main()
{

    /*unsigned long long n,r,p;
    while (scanf("%lld%lld%lld",&n,&r,&p))
    {
          printf("%lld\n",C(n,r,p));
    }*/

    unsigned long long test,N,n,m,i,j,k,p;
    unsigned long long l,r;
    unsigned long long ans;
    unsigned long long prev,prev_j;

    calc();

    scanf("%llu",&test);

    //cout<<combinations(2,1,M3)<<endl;;

    for(i=0;i<test;i++)
    {
        scanf("%llu%llu%llu",&N,&l,&r);

        p=r-l+1;

        /*if(p>=M3)
        {
            printf("0\n");
            continue;
        }*/

        ans=0;
        prev=1;
        prev_j=1;

        if(p<M3||N<M3){
            for(j=1;j<=N;j++)
            {
                //if(p+j-1>=M3)
                  //  break;

                ans=(ans+(fact[p+j-1]*rev_fact[j])%M3)%M3;
            }
            //if(p<=M3)
                ans=ans*rev_fact[p-1];

                //printf("%lld\n",ans%M3);
        }
        else
        {
            ans=C(p+N,N,M3)-1;
            //cout<<"here"<<endl;
            if(ans<0)
                ans=0;
        }
        printf("%llu\n",ans%M3);
    }

/*    for(i=0;i<test;i++){
        scanf("%lld%lld%lld",&n,&l,&r);
        N=l-r+1;
        ans=C(N,1,1000003);
        cout<<"ans1 : "<<ans<<endl;
        prev=1;
        for(j=1;j<=N;j++)
        {

            ans=ans+ans*prev*((N+j)/(j+1));
            prev=prev*((N+j)/(j+1));
        }

        printf("%lld\n",ans);
    }*/

}
