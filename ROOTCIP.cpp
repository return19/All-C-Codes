#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long test,a,b,c,ans;
    long long i,j,k;
    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        scanf("%lld%lld%lld",&a,&b,&c);

        ans=a*a-2*(b);

        printf("%lld\n",ans);
    }

    return 0;
}
