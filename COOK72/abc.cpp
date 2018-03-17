#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ft first
#define sd second

pair< pair<int,int>,int > cirlces[1010]; // x,y, radnius

vector<int> g[1010];
int vis[1010];
int tx1[1010], tx2[1010],ty1[1010],ty2[1010];

int dist(int x,int y,int a,int b){
    return sqrt( (x-a)*(x*a) + (y-b)*(y-b) );
}

pair< pair<int,int>, pair<int,int> > dfs( int x ){
    vis[x] =1;
    int tx1c=0,tx2c=0,ty1c=0,ty2c=0;

    tx1c = tx1[x];
    tx2c = tx2[x];
    ty1c = ty1[x];
    ty2c = ty2[x];

    int i,j,k;

    for(i=0;i<g[x].size();i++){

        if(!vis[ g[x][i] ]){

            pair<  pair<int,int>, pair<int,int> > p = dfs( g[x][i] );
            tx1c += p.ft.ft;
            tx2c += p.ft.sd;
            ty1c += p.sd.ft;
            ty2c += p.sd.sd;
        }
    }
    return mp( mp(tx1c,tx2c),mp(ty1c,ty2c) );
}

int isPossible(int x, int y){
    int i,j,k;

    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(dist( circles[i].ft.ft,circles[i].ft.sd, circles[j].ft.ft, circles[j].ft.sd ) <= circles[i].sd + circles[j].sd){

                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }

    for(i=0;i<n;i++){

        int tx,ty;
        int r = circles[i].sd;
        tx = circle[i].ft.ft;
        ty = circles[i].ft.sd;

        if(tx + r >= x)
            tx1[i]=1;
        if(tx - r <= 0)
            tx2[i] = 1;
        if(ty + r >=y )
            ty2[i] = 1;
        if(ty - r <=0)
            ty1[i] = 1;
    }

    for(i=0;i<n;i++){
        if(!vis[i]){
            pair< pair< pair<int,int>, pair<int,int> > > p = dfs(i); // tx1,tx2,ty1,ty2

            if(p.ft.ft & p.sd.ft)
                return true;
            if(p.ft.ft & p.ft.sd)
                return true;
            if(p.ft.ft & p.sd.sd)
                return true;
        }
    }
    return false;
}

int main()
{
    int i,j,k;

    return 0;
}
