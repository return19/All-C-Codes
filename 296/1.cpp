#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long i,j,k;
    long long n,m;
    scanf("%lld%lld",&n,&m);

    long long ans=0;

    if(n==m)
    {
        printf("1\n");
        return 0;
    }

    while(1)
    {
        if(n%m==0)
        {
            ans += n/m;
            break;
        }
        ans += n/m;
        long long x=n%m;
        long long y=m;
        n=max(x,y);
        m=min(x,y);
        if(n==m)
        {
            ans++;
            break;
        }
    }
      printf("%lld\n",ans);

    return 0;
}
