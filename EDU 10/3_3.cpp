#include<bits/stdc++.h>
using namespace std;

long long pos[1010000];
long long mx[1010000];

vector< pair<long long,long long> > v;

int main()
{
    long long i,j,k;
    long long n,m;
    long long x,y,z;

    scanf("%lld%lld",&n,&m);

    for(i=1;i<=n;i++)
    {
        scanf("%lld",&x);
        pos[x]=i;
    }

    for(i=0;i<m;i++)
    {
        scanf("%lld%lld",&x,&y);
        if(pos[x]>pos[y])   swap(x,y);
        x=pos[x];
        y=pos[y];
        mx[y]=max(mx[y],x);
    }

    long long ans=0;
    for(i=1;i<=n;i++)
    {
        mx[i]=max(mx[i],mx[i-1]);
        ans += i-mx[i];
    }

    printf("%lld\n",ans);

    return 0;
}











