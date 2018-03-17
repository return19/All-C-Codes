#include<vector>
using namespace std;
#include<stdio.h>
long long calc_power(long long n,long long x,long long MOD);
/* This function calculates (a^b)%MOD */
long long power(long long a, long long b, long long MOD)
{
    long long x=1,y=a;
    while(b > 0)
    {
        if(b%2 == 1)
        {
            x=(x*y);
            if(x>MOD)
                x%=MOD;
        }
        y = (y*y);
        if(y>MOD)
            y%=MOD;
        b /= 2;
    }
    return x;
}


long long InverseEuler(long long n, long long MOD)
{
    return power(n,MOD-2,MOD);
}

long long C(long long n, long long r, long long MOD)
{

    vector<long long> f(n + 1,1);
    int i;
    f[0]=1;
    f[1]=1;
    for(i=2;i<=n;i++)
    {
        f[i]=(f[i-1]*power(i,i,MOD))%MOD;
       /* printf("%lld %lld\n",calc_power(i,i,MOD),f[i]);*/

    }

    return ((f[n]*((InverseEuler(f[r],MOD)*InverseEuler(f[n-r],MOD))%MOD))%MOD);

}

int main()
{
    long long test,n,r,m,q,i,j,ans;

    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        scanf("%lld%lld%lld",&n,&m,&q);
        for(j=0;j<q;j++)
        {
            scanf("%lld",&r);
            ans=C(n,r,m);
            printf("%lld\n",ans);
        }
    }
    return 0;

}




