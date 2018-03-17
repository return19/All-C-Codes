#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ft first
#define sd second

long long vis[101000];
long long n;

vector< pair<long long,long long> > g[101000];

pair<long long,long long> dfs(long long x){
    vis[x]=1;
    long long i,j,k;
    long long mx=0,v;

    for(i=0;i<g[x].size();i++){
        if(!vis[g[x][i].ft]){
            pair<long long,long long> temp=dfs(g[x][i].ft);
            temp.sd += g[x][i].sd;
            if(mx<temp.sd){
                mx=temp.sd;
                v=temp.ft;
            }
        }
    }

    if(mx==0){
        return mp(x,0);
    }
    return mp(v,mx);
}

int main()
{
    long long i,j,k;
    long long test,t;
    long long x,y,z;
    scanf("%lld",&test);

    for(t=0;t<test;t++)
    {
        scanf("%lld",&n);

        for(i=0;i<n;i++)
            g[i].resize(0);

        for(i=0;i<n-1;i++){
            scanf("%lld%lld%lld",&x,&y,&z);
            x--;    y--;
            g[x].push_back(mp(y,z));
            g[y].push_back(mp(x,z));
        }

        for(i=0;i<n;i++)    vis[i]=0;
        pair<long long,long long> p=dfs(0);
        for(i=0;i<n;i++)    vis[i]=0;
        p=dfs(p.ft);

        printf("%lld\n",p.sd);
    }
    return 0;
}












