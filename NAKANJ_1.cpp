#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ft first
#define sd second

int sx,sy,ex,ey;

int vis[10][10];
queue< pair<int, pair<int,int> > > q;

int move_x[8]={-2,-2,2,2,1,-1,1,-1};
int move_y[8]={-1,1,-1,1,-2,-2,2,2};

int check(int x,int y){
    if(x>=0 && x<8 && y>=0 && y<8)
        return 1;
    return 0;
}

int solve()
{
    while(!q.empty())   q.pop();

    int i,j,k;
    q.push(mp(0,mp(sx,sy)));
    vis[sx][sy]=1;

    if(sx== ex && sy==ey)   return 0;

    while(!q.empty()){
        pair< int,pair<int,int> > p =q.front();
        q.pop();

        int x,y,val;
        x=p.sd.ft;
        y=p.sd.sd;
        val=p.ft;

        for(i=0;i<8;i++)
        {
            int tx,ty;
            tx= x + move_x[i];
            ty= y + move_y[i];

            if(!check(tx,ty))   continue;
            if(vis[tx][ty])     continue;

            if(tx==ex && ty==ey)
                return val+1;

            vis[tx][ty]=1;
            q.push(mp(val+1,mp(tx,ty)));
        }
    }
    return -1;
}

int main()
{
    int i,j,k;
    int test,t;
    string s;

    scanf("%d",&test);

    for(t=0;t<test;t++)
    {
        cin>>s;
        sx=s[0]-'a';
        sy=s[1]-'0'-1;
        cin>>s;
        ex=s[0]-'a';
        ey=s[1]-'0'-1;

        for(i=0;i<10;i++)
            for(j=0;j<10;j++)
                vis[i][j]=0;

        int ans=solve();
        printf("%d\n",ans);
    }
    return 0;
}
