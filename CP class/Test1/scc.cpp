#include<bits/stdc++.h>
using namespace std;

vector<int> g[101000];
vector<int> tg[101000];
int n,m;
stack<int> s;
int vis[101000];
int scc[101000];
int cur=1;

void dfs1(int x){
    vis[x]=1;
    int i;
    for(i=0;i<g[x].size();i++){
        if(!vis[g[x][i]])
            dfs1(g[x][i]);
    }
    s.push(x);
}

void dfs2(int x){
    vis[x]=1;
    scc[x] = cur;
    int i;
    for(i=0;i<tg[x].size();i++){
        if(!vis[tg[x][i]])
            dfs2(tg[x][i]);
    }
}

int main()
{
    int i,j,k;
    int x,y;

    scanf("%d%d",&n,&m);

    for(i=0;i<m;i++){
        scanf("%d%d",&x,&y);
        x--;    y--;
        g[x].push_back(y);
        tg[y].push_back(x);
    }

    for(i=0;i<n;i++){
        if(!vis[i])
            dfs1(i);
    }

    for(i=0;i<n;i++)
        vis[i]=0;

    while(!s.empty()){
        int x = s.top();
        s.pop();
        if(!vis[x]){
            dfs2(x);
            cur++;
        }
    }

    for(i=0;i<n;i++)
        cout<<scc[i]<<" ";
    cout<<endl;

    int q;
    scanf("%d",&q);

    for(i=0;i<q;i++){
        scanf("%d%d",&x,&y);
        x--;    y--;
        if(scc[x]==scc[y])
            printf("YES\n");
        else
            printf("NO\n");
    }



    return 0;
}













