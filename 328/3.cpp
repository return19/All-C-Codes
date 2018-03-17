#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long i,j,k;
    long long t,a,b,res,gcd_a;
    scanf("%lld%lld%lld",&t,&a,&b);

    long long mn=min(a-1,b-1);
    long long gcd_res=__gcd(a,b);

    if((double)a/gcd_res > (double)t/b)
    {
        //cout<<"h"<<endl;
        res=min(t,mn);
    }else{
        gcd_res =(a/gcd_res)*b;
        res=mn + mn*((t/gcd_res)-1) + (t/gcd_res)-1;
        res += min(mn+1,t-gcd_res*(t/gcd_res)+1);
    }

    gcd_a=__gcd(res,t);
    t/=gcd_a;
    res/=gcd_a;

    printf("%lld/%lld\n",res,t);
    return 0;
}














