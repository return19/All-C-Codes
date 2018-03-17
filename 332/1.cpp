#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long i,j,k;
    long long d1,d2,d3;

    scanf("%lld%lld%lld",&d1,&d2,&d3);

    long long ans=min(2*d1+2*d2,d1+d2+d3);
    ans=min(ans,min(2*d1+2*d3,2*d2+2*d3));

    printf("%lld\n",ans);

    return 0;
}
