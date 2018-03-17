#include <stdio.h>
#include <string.h>



int vis[128][128];
char grid[128][128];
char word[32];
int m, n;
int l;

int move_x[10]={-1,1,0,0,-1,-1,1,1};
int move_y[10]={0,0,1,-1,-1,1,1,-1};

int check(int x,int y){
    if(x>=0 && x< m && y>=0 && y<n)
        return 1;
    return 0;
}

int dfs(int x,int y,int k){
    int i,j;
    vis[x][y]=1;

    if(k==l-1)
        return 1;

    for(i=0;i<8;i++){
        int tx = x + move_x[i];
        int ty = y + move_y[i];

        if(!check(tx,ty) || vis[tx][ty])
            continue;
        if(grid[tx][ty] == word[k+1] && dfs(tx,ty,k+1))
            return 1;
    }
    vis[x][y]=0;
    return 0;
}

/* Using int instead of bool. Return 0 to signify false, and 1 to signify true. */
int findWordInAGrid(char grid[128][128], int m, int n, char word[32]) {
    int i,j,k;
    for(i=0;i<m;i++)
        for(j=0;j<n;j++)
            vis[i][j]=0;

    l = strlen(word);

    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++){
            if(grid[i][j]==word[0] && dfs(i,j,0))
                return 1;
        }
    }
    return 0;
}

int main() {

    int k;
    int i, j;

    scanf("%d%d",&m,&n);
    for(i=0;i<m;i++) scanf("%s",grid[i]);
    scanf("%d",&k);
    while(k--) {
        scanf("%s",word);
        printf("%s\n",findWordInAGrid(grid, m, n, word) ? "true" : "false");
    }
    return 0;
}
