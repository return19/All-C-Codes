#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ft first
#define sd second

int n,m;
vector<int> v[201000];
int vis[201000];
int c[201000];

int ver=1;
set<int> s;

// just create par[] array and initialize it with -1
int par[201000];
int root(int v){return par[v] < 0 ? v : (par[v] = root(par[v]));}
void merge_dsu(int x,int y){	//	x and y are some tools (vertices)
        if((x = root(x)) == (y = root(y)))     return ;
	if(par[y] < par[x])	// balancing the height of the tree
		swap(x, y);
	par[x] += par[y];
	par[y] = x;
}


pair<int,int> dfs(int x){
    vis[x] = ver;
    c[x] = 1;

    int i,j,k;
    int ans1=0,ans2=1;

    for(i=0;i<v[x].size();i++){
        if(!vis[v[x][i]]){
            pair<int,int> temp = dfs(v[x][i]);
            ans1 = ans1|temp.ft;
            ans2 += temp.sd;
        } else if(vis[v[x][i]] != ver){
            s.insert(root(vis[v[x][i]]));
            //vis[v[x][i]]=ver;
        } else if(c[v[x][i]])
            ans1=1;
    }
    c[x] = 0;
    return mp(ans1,ans2);
}

int main(){
    int i,j,k;
    int x,y;
    scanf("%d%d",&n,&m);

    for(i=0;i<m;i++){
        scanf("%d%d",&x,&y);
        x--;    y--;
        v[x].push_back(y);
    }

    for(i=0;i<n;i++)
        par[i]=-1;

    int ans=0;

    for(i=0;i<n;i++){
        if(!vis[i]){
            pair<int,int> temp = dfs(i);

            if(temp.ft == 1){
                ans += temp.sd;
            } else {
                ans += temp.sd -1;
            }
            ans += s.size();
            for(set<int>::iterator it = s.begin();it!=s.end();it++){
                merge_dsu(ver,*it);
            }
            s.clear();
            ver++;
        }
    }

    printf("%d\n",ans);

    return 0;
}
