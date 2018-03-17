#include<bits/stdc++.h>
using namespace std;

int n,m;
int par[1010000];
int root(int v){return par[v] < 0 ? v : (par[v] = root(par[v]));}
void merge_dsu(int x,int y){	//	x and y are some tools (vertices)
        if((x = root(x)) == (y = root(y)))     return ;
	if(par[y] < par[x])	// balancing the height of the tree
		swap(x, y);
	par[x] += par[y];
	par[y] = x;
}


char str[1010][1010];
int vis[1010][1010];
int chain[1010][1010];

int check(int x,int y){
    if(x>=0 && x<n && y>=0 && y<m)
        return 1;
    return 0;
}

map<char,int> move_x;
map<char,int> move_y;

void dfs(int x,int y,int cnt){
    vis[x][y]=1;
    chain[x][y]=cnt;
    int tx=x+move_x[str[x][y]];
    int ty=y+move_y[str[x][y]];
    if(check(tx,ty)){
        if(!vis[tx][ty]){
            dfs(tx,ty,cnt);
        }else{
            merge_dsu(cnt,chain[tx][ty]);
        }
    }
}

set<int> s;

int main(){
    int i,j,k;

    move_x['N']=-1;
    move_x['S']=1;
    move_x['W']=0;
    move_x['E']=0;

    move_y['N']=0;
    move_y['S']=0;
    move_y['W']=-1;
    move_y['E']=1;

    scanf("%d%d",&n,&m);

    for(i=0;i<1010000;i++)
        par[i]=-1;

    for(i=0;i<n;i++)
        scanf("%s",str[i]);

    int cnt=1;

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(!vis[i][j]){
                dfs(i,j,cnt);
                cnt++;
            }
        }
    }

    int ans=0;

    for(i=1;i<cnt;i++){
        s.insert(root(i));
    }

    printf("%d\n",s.size());

    return 0;
}












