#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ft first
#define sd second

int n,m;
vector< pair<int,int> > g[101000];
int vis[101000];

pair<int,int> dfs(int x){
    vis[x]=1;
    int t=x;
    int ans=0;

    for(int i=0;i<g[x].size();i++){
        if(!vis[ g[x][i].ft ]){
            pair<int,int> temp = dfs(g[x][i].ft);
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
    int i,j,k;
    int x,y,z;

    scanf("%d%d",&n,&m);

    for(i=0;i<m;i++){
        scanf("%d%d%d",&x,&y,&z);
        x--;
        y--;
        g[x].push_back(mp(y,z));
        g[y].push_back(mp(x,z));
    }

    pair<int,int> ans1 = dfs(0);

    for(i=0;i<n;i++)
        vis[i]=0;

    pair<int,int> ans2 = dfs(ans1.sd);
    printf("%d\n",ans2.ft);

    return 0;
}
