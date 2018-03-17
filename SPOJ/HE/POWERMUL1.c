#include<stdio.h>
long long arr[100010];
long long MOD;
/*long long power(long long a,long long b)
{
    long long r=1,i;
    for(i=1;i<=b;i++)
    {
        r=(r*a)%MOD;
    }
    return r;
}*/
long long power(long long a, long long b)
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
long long calc(long long a,long long b)
{
    long long i;
    arr[0]=1;
    arr[1]=1;
    for(i=2;i<=a;i++)
    {
        arr[i]=(arr[i-1]*power(i,i))%MOD;
    }
    return arr[a];
}

int main()
{
    long long test,a,ans,i,b;
    scanf("%lld",&test);
    for(i=0;i<test;i++)
    {
         scanf("%lld%lld%lld",&a,&MOD,&b);
         ans=calc(a,b);
         printf("%lld\n",ans);
    }

    return 0;
}
