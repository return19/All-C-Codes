#include<bits/stdc++.h>
using namespace std;

long long M=1e9 +7;
map< long long,long long> memo;

long long power(long long x,long long y){
    if(y==0)
        return 1;
    if(y==1)
        return x;
    long long hf=power(x,y/2);

    if(y&1) return (((hf*hf)%M)*x)%M;
    return (hf*hf)%M;
}

int main()
{
    long long i,j,k;
    long long n;
    long long test,t,x;

    scanf("%lld",&test);

    for(t=0;t<test;t++)
    {
        scanf("%lld",&n);
        memo.clear();
        for(i=0;i<n;i++)
        {
            scanf("%lld",&x);

            memo[x];
        }

        long long ans=power(n,memo.size());
        printf("%lld\n",ans);
    }
    return 0;
}

