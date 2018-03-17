#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ft first
#define sd second

int n,m;

int arr[210][210];

int ans[210][210];
int vis[210][210];

int move_x[4]={-1,1,0,0};
int move_y[4]={0,0,-1,1};

int check(int x,int y){
    if(x>=0 && x<n && y>=0 && y<m)
        return 1;
    return 0;
}

queue< pair< int,pair<int,int> > > q;

void solve(){
    int i,j,k;

    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            if(arr[i][j]==1)
            {
                q.push(mp(0,mp(i,j)));
                ans[i][j]=0;
                vis[i][j]=1;
            }
    while(!q.empty()){
        pair<int,pair<int,int> > p = q.front();
        q.pop();

        int x,y,val;
        x=p.sd.ft;
        y=p.sd.sd;
        val=p.ft;

        for(i=0;i<4;i++){
            int tx= x + move_x[i];
            int ty= y + move_y[i];

            if(!check(tx,ty))
                continue;

            if(vis[tx][ty]) continue;

            vis[tx][ty]=1;
            ans[tx][ty]=val+1;
            q.push(mp(val+1,mp(tx,ty)));
        }
    }
}

int main()
{
    int i,j,k;
    int test,t;

    scanf("%d",&test);

    for(t=0;t<test;t++)
    {
        scanf("%d%d",&n,&m);

        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                scanf("%1d",&arr[i][j]);
        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                vis[i][j]=0;

        solve();

        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
                printf("%d ",ans[i][j]);
            printf("\n");
        }

    }
    return 0;
}
