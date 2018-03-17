#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ft first
#define sd second

long long n,m;
vector< pair<long long,long long> > g[101000];
long long vis[101000];

pair<long long,long long> dfs(long long x){
    vis[x]=1;
    long long t=x;
    long long ans=0;

    for(long long i=0;i<g[x].size();i++){
        if(!vis[ g[x][i].ft ]){
            pair<long long,long long> temp = dfs(g[x][i].ft);
            if(temp.ft + g[x][i].sd > ans)
            {
                ans = temp.ft + g[x][i].sd;
                t = temp.sd;
            }
        }
    }
    return mp(ans,t);
}

int main()
{
   // freopen("input09.txt","r",stdin);
    //freopen("output09.txt","w",stdout);
    long long i,j,k;
    long long x,y,z;

    scanf("%lld%lld",&n,&m);

    for(i=0;i<m;i++){
        scanf("%lld%lld%lld",&x,&y,&z);
        x--;
        y--;
        g[x].push_back(mp(y,z));
        g[y].push_back(mp(x,z));
    }

    pair<long long,long long> ans1 = dfs(0);

    for(i=0;i<n;i++)
        vis[i]=0;

    pair<long long,long long> ans2 = dfs(ans1.sd);
    printf("%lld\n",ans2.ft);

    return 0;
}
