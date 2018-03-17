#include<bits/stdc++.h>
using namespace std;

map<long long,long long> sum;
map<long long,long long> dif;

map<long long,long long>::iterator it;

int main()
{
    long long i,j,k;
    long long n;
    long long x,y;
    scanf("%lld",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lld%lld",&x,&y);

        sum[x+y]++;
        dif[x-y]++;
    }

    long long ans=0;

    for(it=sum.begin();it!=sum.end();it++)
    {
        ans += (it->second)*(it->second - 1)/2;
    }

    for(it=dif.begin();it!=dif.end();it++)
    {
        ans += (it->second)*(it->second - 1)/2;
    }
    printf("%lld\n",ans);

    return 0;
}
