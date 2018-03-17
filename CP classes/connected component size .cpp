/*
    Given a grid consisting of '*' and '.'
    where '.' denotes water and '*' denotes a land
    adjacent '.'s are connected and the connected component forms a lake

    How many minimum number of '.'s need to converted to '*' such
    that total number of lakes are exactly k.

    Input :
    5 4 1
    ****
    *..*
    ****
    **.*
    ..**

    Output :

*/

#include<bits/stdc++.h>
using namespace std;

int n,m;
char arr[51][51];
vector<int> cc;

int move_x[4] = {-1,1,0,0};
int move_y[4] = {0,0,-1,1};
int vis[51][51];

int check(int x,int y){
    if(x>=0 && x<n && y>=0 && y<m)
        return 1;
    return 0;
}

// Returns the size of connected component
int dfs(int x,int y){
    vis[x][y]=1;
    int sz=0;
    int i,j,k;
    for(i=0;i<4;i++){
        int tx = x + move_x[i];
        int ty = y + move_y[i];
        if( check(tx,ty) && !vis[tx][ty] && arr[tx][ty]=='.' )
            sz += dfs(tx,ty);
    }
    return (sz+1);
}

int main()
{
    int i,j,k;
    int x,y;

    scanf("%d%d%d",&n,&m,&k);

    for(i=0;i<n;i++)
        scanf("%s",arr[i]);

    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
           if(!vis[i][j] && arr[i][j]=='.')
            {
                cc.push_back(dfs(i,j));
            }
    sort(cc.begin(),cc.end(),greater<int>()); // sort in non-increasing

   // for(i=0;i<cc.size();i++)
     //   cout<<cc[i]<<" ";
    //cout<<endl;

    int ans=0;
    for(i=k;i<cc.size();i++){
        ans+= cc[i];
    }

    printf("%d\n",ans);

    return 0;
}












