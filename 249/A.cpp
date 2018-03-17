#include<bits/stdc++.h>
using namespace std;


int main()
{
    long long n,m,i,j,k;
    long long ans=1;
    long long x;
    long long cap;

    scanf("%lld%lld",&n,&m);
    cap=m;
    for(i=0;i<n;i++)
    {

        scanf("%lld",&x);

        if(cap>=x){
            cap=cap-x;
        }
        else
        {
            ans++;
            cap=m;
            cap=cap-x;
        }
    }

    printf("%lld\n",ans);

    return 0;
}
