#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ft first
#define sd second

int n,m;
int xt,yt;
int a,b;

vector<int> move_x;
vector<int> move_y;
/*
vector<int> move_x1;
vector<int> move_y1;

int check(int x,int y){
    if(x>=1 && x<=n && y>=1 && y<=m)
        return 1;
    return 0;
}



queue< pair< pair<int,int>,int > > q;

int solve(){
    int i,j,k;

    q.push(mp(mp(xt,yt),0));

    while(!q.empty()){
        pair< pair<int,int>,int > p;
        p=q.front();
        q.pop();

        int x=p.ft.ft;
        int y=p.ft.sd;
        int val=p.sd;

        for(i=0;i<4;i++){
            int tx=x + move_x1[i];
            int ty=y + move_y1[i];

            if(!check(tx,ty))
                continue;
            if((tx==1&&(ty==m||ty==1))||(ty==1&&(tx==1||tx==n))||(tx==n && ty==m))
                return val+1;
            q.push(mp(mp(tx,ty),val+1));
        }
    }
    return -1;
}*/

int res(int x,int y){
    int dx,dy;
    dx=abs(x-xt);
    dy=abs(y-yt);

    if(dx%a!=0 || dy%b!=0)
        return INT_MAX;
    dx=dx/a;
    dy=dy/b;

    if(abs(dx-dy)%2!=0)
        return INT_MAX;
    return max(dx,dy);
}

int main()
{
    int i,j,k;
    scanf("%d%d%d%d%d%d",&n,&m,&xt,&yt,&a,&b);

    if((xt==1&& yt==1)||(xt==1&& yt==m)||(xt==n&& yt==1)||(xt==n&& yt==m))
    {
        cout<<0<<endl;
        return 0;
    }
    if((xt+a>n && xt-a<=0)||(yt+b>m&& yt-b<=0))
    {
        printf("Poor Inna and pony!\n");
        return 0;
    }

   /* move_x1.push_back(a); move_y1.push_back(b);
    move_x1.push_back(-1*a); move_y1.push_back(-1*b);
    move_x1.push_back(a); move_y1.push_back(-1*b);
    move_x1.push_back(-1*a); move_y1.push_back(b);
*/
     move_x.push_back(1); move_y.push_back(m);
    move_x.push_back(n); move_y.push_back(1);
    move_x.push_back(1); move_y.push_back(1);
    move_x.push_back(n); move_y.push_back(m);


  //  int ans=solve();

    //printf("%d\n",ans);

    int ans=INT_MAX;

    for(i=0;i<4;i++){
        ans=min(ans,res(move_x[i],move_y[i]));
    }

    if(ans==INT_MAX)
        printf("Poor Inna and pony!\n");
    else
        printf("%d\n",ans);

    return 0;
}










