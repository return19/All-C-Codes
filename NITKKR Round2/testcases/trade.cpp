#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> g[101000];
int vis[101000];

void dfs(int x){
    vis[x]=1;
    int i;
    for(i=0;i<g[x].size();i++){
        if(!vis[g[x][i]])
            dfs(g[x][i]);
    }
}

int main()
{
    freopen("input09.txt","r",stdin);
    freopen("output09.txt","w",stdout);
    int i,j,k;
    int x,y;
    scanf("%d%d",&n,&k);
    for(i=0;i<k;i++){
        scanf("%d%d",&x,&y);
        x--;    y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    int ans=0;

    for(i=0;i<n;i++)
        if(!vis[i]){
            ans++;
            dfs(i);
        }

    printf("%d\n",ans-1);


    return 0;
}
