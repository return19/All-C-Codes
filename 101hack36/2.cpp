#include<bits/stdc++.h>
using namespace std;

long long fact[1010000];
long long M=1e9 +7;

int main()
{
    long long i,j,k;
    long long n,m;

    fact[0]=fact[1]=1;

    for(i=2;i<1000010;i++)
        fact[i] = (fact[i-1]*i)%M;

    scanf("%lld%lld",&n,&m);

    long long ans=1;

    for(i=1;i<=n;i++)
    {
        ans = (ans * (fact[min(i,m)]))%M;
    }

    for(j=1;j<m;j++)
    {
        ans = (ans * (fact[min(j,n)]))%M;
    }

    printf("%lld\n",ans);

    return 0;
}
