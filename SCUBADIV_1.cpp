#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ft first
#define sd second
#define MAX 99999999999999999

long long n;
long long ox,ni;

vector< pair< pair<long long,long long>,long long> > v;

long long memo[1010][310][510];

long long solve(long long idx,long long co,long long cn)
{
    if(idx==n)
    {
        if(co>=ox && cn>= ni)
            return 0;
        return MAX;
    }

    if(co>=ox && cn>=ni)
        return 0;

    if(memo[idx][co][cn]!=-1)
        return memo[idx][co][cn];

    long long tk,nt;

    tk= v[idx].sd + solve(idx+1,co + v[idx].ft.ft,cn + v[idx].ft.sd);
    nt= solve(idx+1,co,cn);

    return memo[idx][co][cn]=min(tk,nt);
}

int main()
{
    long long i,j,k;
    long long test,t;
    long long x,y,z;

    scanf("%lld",&test);

    for(t=0;t<test;t++)
    {
        scanf("%lld%lld",&ox,&ni);
        scanf("%lld",&n);
        v.resize(0);

        for(i=0;i<n;i++)
        {
            scanf("%lld%lld%lld",&x,&y,&z);
            v.push_back(mp(mp(x,y),z));
        }

        for(i=0;i<=n;i++)
            for(j=0;j<=21;j++)
                for(k=0;k<=79;k++)
                    memo[i][j][k]=-1;

        long long ans=solve(0,0,0);
        printf("%lld\n",ans);
    }
    return 0;
}














