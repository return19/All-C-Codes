#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007

long long phi_cal(long long x)
 {
   long long ret = 1,i,pow;
   for (i = 2; x != 1; i++)
   {
     pow = 1;

     if(i > sqrt(x))
        break;

     while (!(x%i))
     {
       x /= i;
       pow *= i;
     }

     ret *= (pow - (pow/i));

    }
    if(x!=1)ret*=(x-1);
        return ret;
}

int main()
{
    long long test,k,i,j;
    long long n;

    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        scanf("%lld%lld",&n,&k);

        if(k==0)
        {
            printf("%lld\n",phi_cal(n)%MOD);
        }
        else if(k==1)
        {
            long long t;
            t=phi_cal(n);

            if(t%2==0)
            {
                t=t/2;
                printf("%lld\n",((t%MOD)*(n%MOD))%MOD);
                continue;
            }
            printf("%lld\n",((t%MOD)*((n/2)%MOD))%MOD);
        }
    }
   /* cin>>t;
    while(t--)
    {
           long long n;
           cin>>n;
           cout<<phi_cal(n)<<endl;
    }*/
    return 0;
}
