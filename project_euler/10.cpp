#include<bits/stdc++.h>
using namespace std;

long long s[1010000];
long long csum[1010000];

void solve()
{
    long long i,j,k;

    s[0]=s[1]=1;

    for(i=2;i<1000100;i++)
    {
        if(s[i]==0)
        {
            k=2;

            for(j=i*2;j<1000100;j=i*k)
            {
                s[j]=1;

                k++;
            }
        }
    }

    for(i=2;i<1000100;i++)
    {
        if(s[i]==0)
        {
            csum[i]=i;
        }

        csum[i]+=csum[i-1];
    }
}

int main()
{
    long long test,i,j,k,t;
    long long n;

    scanf("%lld",&test);

    solve();

    for(t=0;t<test;t++)
    {
        scanf("%lld",&n);

        printf("%lld\n",csum[n]);
    }

    return 0;
}










