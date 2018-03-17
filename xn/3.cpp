#include<bits/stdc++.h>
using namespace std;

unsigned long long fib[5100000];
unsigned long long fib_sum[5100000];

unsigned long long ans[5100000];

unsigned long long M=1299709;

void cal_fib()
{
    unsigned long long i,j;

    fib[0]=0;
    fib[1]=1;

    for(i=2;i<=5000110;i++)
    {
        fib[i]=(fib[i-1]+fib[i-2])%M;
    }

    fib_sum[0]=0;

    for(i=1;i<=5000110;i++)
        fib_sum[i]=(fib_sum[i-1]+fib[i])%M;


    ans[0]=0;
    ans[1]=0;

    for(i=2;i<=5000110;i++)
    {
        ans[i]=(ans[i-1]+(fib_sum[i-1]*fib[i])%M)%M;


    }

    for(i=1;i<=5000110;i++)
    {
        ans[i]=(ans[i]+ans[i-1])%M;

    }



}

int main()
{
    unsigned long long test,i,j,k;

    unsigned long long l,r;

    scanf("%llu",&test);

    cal_fib();

    for(i=0;i<test;i++)
    {
        scanf("%llu%llu",&l,&r);

        printf("%llu\n",ans[r]-ans[l-1]);
    }


    return 0;
}
