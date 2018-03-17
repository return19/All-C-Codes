#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ft first
#define sd second

long long par[1010];
long long n,m,c;

vector< pair< long long,pair<long long,long long> > > e;

long long root(long long x){
    if(par[x]<0)
        return x;
    return par[x]=root(par[x]);
}

void merge_dsu(long long x,long long y)
{
    x=root(x);
    y=root(y);
    if(x==y)
        return;
    if(par[x]>par[y])
        swap(x,y);
    par[x]+=par[y];
    par[y]=x;
}

int main()
{
    long long i,j,k;
    long long t,test;
    long long x,y,z;

    scanf("%lld",&test);

    for(t=0;t<test;t++)
    {
        scanf("%lld%lld%lld",&c,&n,&m);
        for(i=0;i<n;i++)
            par[i]=-1;

        e.resize(0);
        for(i=0;i<m;i++){
            scanf("%lld%lld%lld",&x,&y,&z);
            x--;    y--;
            e.push_back(mp(z,mp(x,y)));
        }

        sort(e.begin(),e.end());

        long long ans=0;

        for(i=0;i<m;i++){
            x=e[i].sd.ft;
            y=e[i].sd.sd;
            z=e[i].ft;

            if(root(x)!=root(y)){
                ans += z;
                merge_dsu(x,y);
            }
        }

        printf("%lld\n",ans*c);
    }
    return 0;
}















