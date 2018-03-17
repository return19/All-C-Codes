#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ft first
#define sd second

vector< pair<int,int> > g[101000];
int n;
int vis[101000];
int dfs(int x,int y,int &res){
    if(x==y)    return 0;
    vis[x]=1;
    int i,j,k;
    int ans=INT_MIN;
    for(i=0;i<g[x].size();i++)
    {
        if(!vis[g[x][i].ft]){
            int temp=dfs(g[x][i].ft,y,res);
            if(temp!=INT_MIN)
                ans=max(ans,g[x][i].sd + temp);
        }
    }

   // cout<<x+1<<" "<<ans<<endl;
    res=max(res,ans);
    if(ans==INT_MIN)
        return ans;
    return max(0,ans);
}

int main()
{
    int i,j,k;
    int q;
    int x,y,z;

    scanf("%d%d",&n,&q);

    for(i=0;i<n-1;i++){
        scanf("%d%d%d",&x,&y,&z);
        x--;
        y--;
        g[x].push_back(mp(y,z));
        g[y].push_back(mp(x,z));
    }

    for(i=0;i<q;i++){
        scanf("%d%d",&x,&y);
        x--;    y--;
        memset(vis,0,sizeof(vis));
        int ans=0;
        dfs(x,y,ans);
        printf("%d\n",ans);
    }
    return 0;
}
