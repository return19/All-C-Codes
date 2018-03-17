#include<bits/stdc++.h>
using namespace std;

int n,m;
char arr[110][110];
int vis[110][110];

int check(int x,int y){
    if(x>=0 && x<n && y>=0 && y<m)
        return 1;
    return 0;
}

int move_x[4] = {-1,1,0,0};
int move_y[4] = {0,0,-1,1};

int dfs(int x,int y){
    vis[x][y]=1;
    int ans=0;
    int i,j;
    for(i=0;i<4;i++){
        int tx = move_x[i] + x;
        int ty = move_y[i] + y;

        if(!check(tx,ty))
            continue;
        if(vis[tx][ty] || arr[tx][ty]=='#')
            continue;
        ans = ans + dfs(tx,ty);
    }
    return ans+1;
}

int main(){
    int i,j,k;
    int rt_emp,new_emp;
    int rt_head,new_head;

    scanf("%d%d",&n,&m);
    for(i=0;i<n;i++)
        scanf("%s",arr[i]);

    scanf("%d%d",&rt_emp,&new_emp);
    scanf("%d%d",&rt_head,&new_head);

    int ans=0;

    for(i=0;i<n;i++)
        for(j=0;j<m;j++){
            if(arr[i][j]=='B')
            {
                ans = rt_head*dfs(i,j) + new_head;
            }
        }

    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(!vis[i][j] && arr[i][j]!='#'){
                ans = ans + rt_emp*dfs(i,j) +new_emp;
            }
        }
    }

    printf("The total cost is %d.",ans);

    return 0;
}










