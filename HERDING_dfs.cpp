#include<bits/stdc++.h>
using namespace std;

int n,m;
char arr[1010][1010];

map<char,int> move_x;
map<char,int> move_y;
int vis[1010][1010];
int chain[1010][1010];
int cn;
int check(int x,int y){
    if(x>=0 && x<n && y>=0 && y<m)
        return 1;
    return 0;
}

int dfs(int x,int y){
    int i,j,k;
    vis[x][y]=1;
    chain[x][y]=cn;

    int tx,ty;
    tx = x + move_x[arr[x][y]];
    ty = y + move_y[arr[x][y]];

  //  if(!check(tx,ty))
    //    return 1;

    if(vis[tx][ty]){
        if(chain[tx][ty]==cn)
            return 1;
        return 0;
    }
    return dfs(tx,ty);
}

int main()
{
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
    for(i=0;i<n;i++)
        scanf("%s",arr[i]);

    int ans=0;

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(!vis[i][j]){
                cn++;
                ans = ans + dfs(i,j);
            }
        }
    }

    printf("%d\n",ans);


    return 0;
}
