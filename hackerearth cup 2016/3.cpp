#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ft first
#define sd second

long long n;
long long ans=0;
long long vis[501000];
long long M = 1e9 + 7;
vector< pair<long long,long long> > g[501000];

long long dfs(long long x){
    vis[x]=1;
    long long res=0;
    vector<long long> ch;
    vector<long long> cs;
    long long i,j;
    for(i=0;i<g[x].size();i++){
        if(!vis[g[x][i].ft]){
            long long temp = (g[x][i].sd + (g[x][i].sd*dfs(g[x][i].ft))%M)%M;
            ch.push_back(temp);
            cs.push_back(temp);
            res = (res + temp)%M;
        }
    }
    /*cout<<x<<endl;
    for(i=0;i<ch.size();i++)
        cout<<ch[i]<<" ";
    cout<<endl;*/
    long long nc = ch.size();
    for(i=nc-2;i>=0;i--){
        cs[i]= (cs[i] + cs[i+1])%M;
    }

    for(i=0;i<nc-1;i++){
        ans  = (ans + (ch[i]*cs[i+1])%M)%M;
    }
    if(nc)
        ans = (ans + cs[0])%M;

    return res;
}

int main()
{
    long long i,j,k;
    long long x,y,z;
    scanf("%lld",&n);
    for(i=0;i<n-1;i++){
        scanf("%lld%lld%lld",&x,&y,&z);
        x--;    y--;
        g[x].push_back(mp(y,z));
        g[y].push_back(mp(x,z));
    }

    dfs(0);
    printf("%lld\n",ans%M);

    return 0;
}















