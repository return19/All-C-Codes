#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long test,i,j,k,t;

    long long n;

    long long ans;

    scanf("%lld",&test);

    for(t=0;t<test;t++)
    {
        scanf("%lld",&n);

        long long ans= 3*n*n*n*n + 2*n*n*n - 3*n*n - 2*n;
        ans /= 12;

        printf("%lld\n",ans);
    }

    return 0;
}
