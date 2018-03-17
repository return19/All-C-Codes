#include<bits/stdc++.h>
using namespace std;

long long g[101000];
long long vis[101000];
long long sup[101000];

void dfs(long long x){
    if(vis[x])
        return;
    vis[x]=1;

    if(g[x]!=0){
        dfs(g[x]);
        sup[x]=1+sup[g[x]];
    }
}

int main()
{
    long long i,j,k;
    long long test,t;
    long long n;
    long long x,y,z;

    scanf("%lld",&test);

    for(t=0;t<test;t++){
        scanf("%lld",&n);

        for(i=1;i<=n;i++){
            scanf("%lld",&x);
            g[i]=x;
        }

        for(i=1;i<=n;i++){
            vis[i]=0;
            sup[i]=0;
        }
        for(i=1;i<=n;i++){
            if(!vis[i]){
                dfs(i);
            }
        }
        long long ans=0;
        for(i=1;i<=n;i++)
            ans += sup[i];
        printf("%lld %lld\n",ans,n*(n-1)/2 - ans);
    }
    return 0;
}
