#include<bits/stdc++.h>
using namespace std;
#include<vector>
#define M3 1000003

long long fact[1000010];
long long rev_fact[1000010];

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

void calc()
{
    long long i,j,k;
    long long val=1;
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

    /*long long n,r,p;
    while (scanf("%lld%lld%lld",&n,&r,&p))
    {
          printf("%lld\n",C(n,r,p));
    }*/

    long long test,N,n,m,i,j,k,p;
    long long l,r;
    long long ans;
    long long prev,prev_j;

    calc();

    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        scanf("%lld%lld%lld",&N,&l,&r);

        p=r-l+1;

        /*if(p>=M3)
        {
            printf("0\n");
            continue;
        }*/

        ans=0;
        prev=1;
        prev_j=1;
        for(j=1;j<=N;j++)
        {
            if(p+j-1>=M3)
                break;

            ans=(ans+(fact[p+j-1]*rev_fact[j])%M3)%M3;
        }
        if(p<=M3)
            ans=ans*rev_fact[p-1];

        printf("%lld\n",ans%M3);
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
