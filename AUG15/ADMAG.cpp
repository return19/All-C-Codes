#include<bits/stdc++.h>
using namespace std;


unsigned long long fib[1100];
unsigned long long fib_cum[1100];

void precomp()
{
    unsigned long long i,j,k;

    fib[0]=1;
    fib[1]=1;

    for(i=2;i<=100;i++)
    {
        fib[i]=fib[i-1]+fib[i-2];
    }

    fib_cum[0]=1;

    for(i=1;i<=100;i++)
    {
        fib_cum[i]=fib[i]+fib_cum[i-1];
    }

    //cout<<fib[100]<<" "<<fib_cum[100]<<endl;

}

int main()
{
    unsigned long long test,i,j,k;
    unsigned long long n;
    scanf("%llu",&test);

    precomp();

    for(i=0;i<test;i++)
    {
        scanf("%llu",&n);

        for(j=0;j<=100;j++)
        {
            if(fib_cum[j]>=n)
                break;
        }

        printf("%llu\n",j+1);
    }

    return 0;
}
