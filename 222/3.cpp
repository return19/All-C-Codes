#include<bits/stdc++.h>
using namespace std;

char arr[510][510];
int n,m;

int check(int x,int y){
    if(x>=0 && x<n && y>=0 && y<m)
        return 1;
    return 0;
}

int move_x[4]={-1,1,0,0};
int move_y[4]={0,0,-1,1};

int vis[510][510];

void dfs(int x,int y,int &k){
    if(k<=0)    return;
    k--;
    vis[x][y]=1;
    int i,j;
    for(i=0;i<4;i++){
        int tx=x+move_x[i];
        int ty=y+move_y[i];
        if(!check(tx,ty) || arr[tx][ty]!='.' || vis[tx][ty]==1)
            continue;
        dfs(tx,ty,k);
    }
}

int main()
{
    int i,j,k;

    scanf("%d%d%d",&n,&m,&k);

    for(i=0;i<n;i++)
        scanf("%s",arr[i]);

    int s=0;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++)
            if(arr[i][j]=='.')
                s++;
    }
    int x=s-k;

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(arr[i][j]=='.'){
                dfs(i,j,x);

                for(i=0;i<n;i++)
                    for(j=0;j<m;j++)
                        if(arr[i][j]=='.' && vis[i][j]==0)
                            arr[i][j]='X';

                for(i=0;i<n;i++){
                    printf("%s\n",arr[i]);
                }

                return 0;
            }
        }
    }

    return 0;
}
















