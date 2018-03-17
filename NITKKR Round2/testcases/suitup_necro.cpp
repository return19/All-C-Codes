#include<bits/stdc++.h>
using namespace std;

struct node{
    int x;
    int y;
    int s;
    int mk;

    node(int _x,int _y,int _s, int _m){
        x = _x;
        y = _y;
        s = _s;
        mk = _m;
    }
};

//map< pair< pair<int,int>  , int> , int> dp;
int dp[600][600][20];

string a[1000];
int m,n;
int sx,sy;
int movx[4] = {0,1,0,-1};
int movy[4] = {1,0,-1,0};

int main()
{
     freopen("input00.txt","r",stdin);
    cin>>m>>n;
    cin>>sx>>sy;
    sx--;
    sy--;

    for(int i=0;i<m;i++)
        cin>>a[i];

    int msk = 0;

//    memset(dp,INT_MAX,sizeof dp);

    for(int i=0;i<m+10;i++)
        for(int j=0;j<n+10;j++)
            for(int k=0;k<18;k++)
                dp[i][j][k] = INT_MAX;

    if(a[sx][sy]=='P')
        msk = 1;
    else if(a[sx][sy]=='S')
        msk = 2;
    else if(a[sx][sy]=='T')
        msk = 4;
    else if(a[sx][sy]=='C')
        msk = 8;

    queue<node> q;

    q.push(node(sx,sy,0,msk));
    dp[sx][sy][msk] = 0;

    node p(0,0,0,0);
    while(!q.empty()){
        p = q.front();
        q.pop();

        if(p.mk == 15)
            break;

        for(int i=0;i<4;i++){
            int nx = p.x + movx[i];
            int ny = p.y + movy[i];

            if(nx>=0 && nx<m && ny>=0 && ny<n){
                if(a[nx][ny]=='P')
                    msk = p.mk|1;
                else if(a[nx][ny]=='S')
                    msk = p.mk|2;
                else if(a[nx][ny]=='T')
                    msk = p.mk|4;
                else if(a[nx][ny]=='C')
                    msk = p.mk|8;

                if(dp[nx][ny][msk] > (p.s+1)){
                    q.push(node(nx,ny,p.s+1,msk));
                    dp[nx][ny][msk] = p.s+1;
                }
            }
        }
    }

    if(p.mk == 15)
        cout<<p.s<<endl;
    else
        cout<<-1<<endl;

    return 0;
}
