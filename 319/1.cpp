#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long i,j,k;
    long long n,x;
    scanf("%lld%lld",&n,&x);
    long long ans=0;

    for(i=1;i<=n;i++)
    {
        if(x%i==0 && x/i <=n)
            ans++;
    }

    printf("%lld\n",ans);
    return 0;
}
