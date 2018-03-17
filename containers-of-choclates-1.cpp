#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ft first
#define sd second

int n;
vector<int> g[101000];
int vis[101000];
map<int,int> memo;
map<int,int>::iterator it;

pair<int,int> dfs(int x,int t){
    vis[x]=1;
    int i,j,k;
    int one=0,zero=0;
    for(i=0;i<g[x].size();i++)
    {
        if(!vis[g[x][i]]){
            pair<int,int> temp=dfs(g[x][i],1-t);
            zero += temp.ft;
            one += temp.sd;
        }
    }

    if(t==0)
        return mp(zero+1,one);
    return mp(zero,one+1);
}

int main()
{
    int i,j,k;
    int test,t;
    int x,y;

    scanf("%d",&test);

    for(t=0;t<test;t++)
    {
        memo.clear();
        scanf("%d",&n);

        int mx=0;

        for(i=0;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            x--;    y--;
            g[x].push_back(y);
            g[y].push_back(x);

            mx=max(mx,max(x,y));
            memo[x]=1;
            memo[y]=1;
        }

        for(it=memo.begin();it!=memo.end();it++)
        {
            vis[it->first]=0;
        }

        int ans=0;
        for(it=memo.begin();it!=memo.end();it++){
            if(!vis[it->first]){
                pair<int,int> temp=dfs(it->first,0);
                if(temp.ft + temp.sd !=1){
                    ans = ans + max(temp.ft,temp.sd);
                }
            }
        }

        for(i=0;i<=mx;i++)
            g[i].resize(0);

        printf("Case %d: %d\n",t+1,ans);
    }
    return 0;
}














