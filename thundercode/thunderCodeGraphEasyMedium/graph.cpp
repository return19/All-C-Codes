#include<bits/stdc++.h>
using namespace std;

vector<long long> graph[101000];

long long vis[101000];

void dfs(long long x){
    vis[x]=1;
    long long i;
    for(i=0;i<graph[x].size();i++){
        if(!vis[ graph[x][i] ])
            dfs(graph[x][i]);
    }
}

int main()
{
    freopen("input10.txt","r",stdin);
    freopen("output10.txt","w",stdout);
    long long i,j,k;
    long long n,m;
    long long cost;
    long long x,y;

    scanf("%lld%lld",&n,&m);
    scanf("%lld",&cost);

    for(i=0;i<m;i++){
        scanf("%lld%lld",&x,&y);
        x--;    y--;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    long long ans=0;

    for(i=0;i<n;i++){
        if(!vis[i]){
            ans++;
            dfs(i);
        }
    }

    printf("%lld\n",(ans-1)*cost);

    return 0;
}
