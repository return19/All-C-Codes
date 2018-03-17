#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long i,j,k;
    long long n;
    long long x,y,z;
    long long mnx=LLONG_MAX,mxx=LLONG_MIN,mny=LLONG_MAX,mxy=LLONG_MIN;
    scanf("%lld",&n);

    for(i=0;i<n;i++){
        scanf("%lld%lld",&x,&y);

        mnx=min(mnx,x);
        mxx=max(mxx,x);
        mny=min(mny,y);
        mxy=max(mxy,y);
    }

    printf("%lld\n",min(mxx-mnx,mxy-mny));
    return 0;
}
