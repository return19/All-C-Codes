#include<bits/stdc++.h>
using namespace std;

int n,e;
vector<int> g[101000];
vector<int> tg[101000];
int vis[101000];
stack<int> s;

vector<int> scc[101000];
int nscc[101000];
int sccno[101000];
int sno;
vector<int> ans;

void dfs(int x){
    vis[x]=1;
    int i,j,k;
    for(i=0;i<g[x].size();i++){
        if(!vis[g[x][i]]){
            dfs(g[x][i]);
        }
    }
    s.push(x);
}

void dfs1(int x){
    vis[x]=1;
    scc[sno].push_back(x);
    sccno[x]=sno;
    int i,j,k;

    for(i=0;i<tg[x].size();i++){
        if(vis[tg[x][i]] && sccno[tg[x][i]]!=sno){
            nscc[sccno[tg[x][i]]]=1;
        }else if(!vis[tg[x][i]]){
            dfs1(tg[x][i]);
        }
    }
}

int main()
{
    int i,j,k;
    int x,y,z;

    scanf("%d",&n);

    while(n!=0){
        scanf("%d",&e);

        for(i=0;i<n;i++)
        {
            g[i].resize(0);
            tg[i].resize(0);
            scc[i].resize(0);
            nscc[i]=0;
            sccno[i]=0;
        }
        ans.resize(0);

        for(i=0;i<e;i++){
            scanf("%d%d",&x,&y);
            x--;    y--;
            g[x].push_back(y);
            tg[y].push_back(x);
        }

        for(i=0;i<n;i++)    vis[i]=0;
        for(i=0;i<n;i++)
            if(!vis[i])
                dfs(i);
        for(i=0;i<n;i++)    vis[i]=0;

        sno=0;
        while(!s.empty()){
            x=s.top();
           // cout<<x<<endl;
            s.pop();
            if(!vis[x]){
                dfs1(x);
                sno++;
            }
        }

        for(i=0;i<sno;i++){

                /*for(j=0;j<scc[i].size();j++)
                    cout<<scc[i][j]+1<<" ";
                cout<<endl;*/
            if(!nscc[i]){
                for(j=0;j<scc[i].size();j++){
                    ans.push_back(scc[i][j]);
                }
            }
        }

        sort(ans.begin(),ans.end());

        for(i=0;i<ans.size();i++)
            printf("%d ",ans[i]+1);
        printf("\n");

        scanf("%d",&n);
    }

    return 0;
}
