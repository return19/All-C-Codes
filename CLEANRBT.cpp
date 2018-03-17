#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ft first
#define sd second

char arr[21][21];
int n,m;
int sx,sy;
int cnt;
queue< pair< pair<int,int>,pair<int,int> > > q;

map<  pair<int,int>,int > dirt;

void setbit(int &mask,int pos){
    mask = mask | (1<<pos);
}

int isset(int mask,int pos){
    if(mask & (1<<pos))
        return 1;
    return 0;
}

int memo[21][21][1200];

int move_x[4]={-1,1,0,0};
int move_y[4]={0,0,-1,1};

int check(int x,int y){
    if(x>=0 && x<n && y>=0 && y<m)
        return 1;
    return 0;
}

int solve(){
    int i,j,k;

    while(!q.empty())
        q.pop();

    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            for(k=0;k<1200;k++)
                memo[i][j][k]=0;

    q.push(mp(mp(sx,sy),mp(0,0)));
    memo[sx][sy][0]=1;

    while(!q.empty()){
        pair< pair<int,int>,pair<int,int> > p = q.front();
        q.pop();
        int x,y,mask,val;
        x=p.ft.ft;
        y=p.ft.sd;
        mask=p.sd.ft;
        val=p.sd.sd;

        for(i=0;i<4;i++){
            int tx,ty;
            tx=x + move_x[i];
            ty=y + move_y[i];

            if(!check(tx,ty))
                continue;
            if(arr[tx][ty]=='x')
                continue;
            int temp=mask;
            if(arr[tx][ty]=='*'){
                setbit(temp,dirt[mp(tx,ty)]);
                if(temp+1 == (1<<cnt)){
                    //cout<<temp+1<<endl;
                    return val+1;
                }
            }

            if(memo[tx][ty][temp]!=0)
                continue;
            memo[tx][ty][temp]=1;
            q.push(mp(mp(tx,ty),mp(temp,val+1)));
        }
    }
    return -1;
}

int main()
{
    int i,j,k;
    scanf("%d%d",&m,&n);

    while(n!=0 && m!=0){
            dirt.clear();

        for(i=0;i<n;i++)
            scanf("%s",arr[i]);

        int d=0;
        cnt=0;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++){
                if(arr[i][j]=='o'){
                    sx=i;
                    sy=j;
                }else if(arr[i][j]=='*'){
                    dirt[mp(i,j)]=d++;
                    cnt++;
                }
            }
        }

        int ans=solve();
        printf("%d\n",ans);
        scanf("%d%d",&m,&n);
    }

    return 0;
}









