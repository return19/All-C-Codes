#include<bits/stdc++.h>
using namespace std;

vector<int> g[1000010];
vector<int> c[1000010];
int vis[1000010];
int arr[1000010];
int cno;
int ans[1000010];

vector<int> v[1000010];

void dfs(int x){
    vis[x]=1;
    c[cno].push_back(x);
    v[cno].push_back(arr[x]);
    int i;

    for(i=0;i<g[x].size();i++){
        if(!vis[g[x][i]])
            dfs(g[x][i]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    int i,j,k;
    int n,m;
    int x,y;
    cin>>n>>m;

    for(i=0;i<n;i++){
        cin>>arr[i];
        ans[i]=i+1;
    }

    for(i=0;i<m;i++){
        cin>>x>>y;
        x--;    y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    for(i=0;i<n;i++){
        if(!vis[i]){
            dfs(i);
            sort(v[cno].begin(),v[cno].end());
            sort(c[cno].begin(),c[cno].end(),greater<int>());

            for(i=0;i<v[cno].size();i++){
                ans[c[cno][i]]=v[cno][i];
            }
            cno++;
        }
    }

    for(i=0;i<n;i++)
       cout<<ans[i]<<" ";
    cout<<endl;
    return 0;
}

