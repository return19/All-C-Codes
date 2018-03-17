#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ft first
#define sd second

int arr[510][510];
int pos[510][510];
int vis[510][510];
int ans[510];
int n,s;
int hf;

queue< pair<pair<int,int>,int> > q;

int getSide(int x,int y){
    if(x<=hf){
        if(pos[x][y]%2==0){
            return -1; // up side
        }
        return 1; // down
    } else {
        if(pos[x][y]%2==0){
            return 1;
        }
        return -1;
    }
}

int check(int x,int y){
    if(x>=1 && x<510 && y>=1 && y<510 && arr[x][y]!=0)
        return 1;
    return 0;
}

int main()
{
    int i,j,k;
    int sx,sy;

    int c=1;
    scanf("%d%d",&n,&s);
    hf=n/2;

    int lf=hf,rt=hf;
    for(i=1;i<=hf;i++){
        for(j=lf;j<=rt;j++){
            if(c==s){
                sx=i;
                sy=j;
            }
            pos[i][j]=j-lf+1;
            arr[i][j]=c++;
        }
        lf--;
        rt++;
    }

    lf++;   rt--;
    for(i=hf+1;i<=n;i++){
        for(j=lf;j<=rt;j++){
            if(c==s){
                sx=i;
                sy=j;
            }
            pos[i][j]=j-lf+1;
            arr[i][j]=c++;
        }
        lf++;
        rt--;
    }

    /*for(i=1;i<=n;i++){
        for(j=1;j<=2*hf;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }*/

    vis[sx][sy]=1;
    ans[s]=0;
    q.push(mp(mp(sx,sy),0));

    while(!q.empty()){
        pair< pair<int,int>,int> p = q.front();
        q.pop();
        int x = p.ft.ft;
        int y = p.ft.sd;
        int val = p.sd;
        ans[arr[x][y]] = val;

        if(check(x,y-1) && !vis[x][y-1]){
            vis[x][y-1] = 1;
            q.push(mp(mp(x,y-1),val+1));
        }

        if(check(x,y+1) && !vis[x][y+1]){
            vis[x][y+1] = 1;
            q.push(mp(mp(x,y+1),val+1));
        }

        int temp = getSide(x,y);
        if(check(x+temp,y) && !vis[x+temp][y]){
            vis[x+temp][y] = 1;
            q.push(mp(mp(x+temp,y),val+1));
        }
    }

    for(i=1;i<c;i++)
        cout<<ans[i]<<" ";

    return 0;
}













