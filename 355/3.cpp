#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ft first
#define sd second

int n,m,p;
int arr[310][310];

int memo[300][300][300];

queue< pair< pair<int,int>,pair<int,int> > > q;

int move_x[10]={-1,1,0,0};
int move_y[10]={0,0,-1,1};

int check(int x,int y){
    if(x>=0 && x<n && y>=0 && y<m)
        return 1;
    return 0;
}

int bfs(){
    int i,j,k;

    q.push(mp(mp(0,0),mp(0,0)));

    int c=0;
    int res=INT_MAX;

    while(!q.empty()){
        int x,y,num;
        pair< pair<int,int>,pair<int,int> > p1;
        p1=q.front();
        q.pop();

        x=p1.ft.ft;
        y=p1.ft.sd;
        num=p1.sd.ft;
        int val=p1.sd.sd;

        for(i=0;i<4;i++){
            int tx=move_x[i] + x;
            int ty=move_y[i] + y;

            if(!check(tx,ty))
                continue;

            if(memo[tx][ty][num]<=val+1)
                continue;

            if(arr[tx][ty]!=num+1)
                memo[tx][ty][num]=val+1;
            else
                memo[tx][ty][num]=val+1;

            if(num+1==p && arr[tx][ty]==p)
                res=min(res,val+1);

            if(arr[tx][ty]!=num+1)
                q.push(mp(mp(tx,ty),mp(num,val+1)));
            else if(arr[tx][ty]==num+1)
                q.push(mp(mp(tx,ty),mp(num+1,val+1)));
        }
    }

    return res;
}

int main()
{
    int i,j,k;
    scanf("%d%d%d",&n,&m,&p);

    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            for(k=0;k<=p;k++)
                memo[i][j][k]=INT_MAX;

    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            scanf("%d",&arr[i][j]);

    int ans=bfs();

    printf("%d\n",ans);

    return 0;
}

