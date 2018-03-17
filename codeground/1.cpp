#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ft first
#define sd second

char arr[61][61];

int n,m;
int sx,sy;
int c;

int dp[61][61][1<<17];

map< pair<int,int>,int > memo;

int mx[5] = {-1,1,0,0};
int my[5] = {0,0,-1,1};

void maskit(int &mask,int pos){
    mask = mask|(1<<pos);
}

int isMasked(int mask,int pos){
    if(mask & (1<<pos))
        return 1;
    return 0;
}

int check(int x,int y){
    if(x>=0&& x<n && y>=0 && y<m)
        return 1;
    return 0;
}

int solve(int x,int y,int mask,int val){
    if(mask == (1<<c)-1)
        return 1;

    int i,j,k;
    int ans=INT_MAX;
    for(i=0;i<4;i++){
        int tx = x + mx[i];
        int ty = y + my[i];

        if(!check(tx,ty))
            continue;
        if(arr[tx][ty]=='G')
            continue;
        int temp = mask;
        if(arr[tx][ty]=='X')
            maskit(temp,memo[mp(tx,ty)]);

        if(dp[tx][ty][temp] > val+1){
            dp[tx][ty][temp] = val+1;
            int t = solve(tx,ty,temp,val+1);
            if(t!=INT_MAX)
                ans = min(ans,t);
        }
    }
    if(ans==INT_MAX)
        return INT_MAX;
    return ans+1;
}

int bfs(){
    queue< pair< pair<int,int>,pair<int,int>  > > q;
    int i,j,k;
    dp[sx][sy][0] = 0;
    q.push(mp( mp(sx,sy),mp(0,0) ));

    while(!q.empty()){
        pair< pair<int,int>,pair<int,int> > p = q.front();
        q.pop();

        int x = p.ft.ft;
        int y = p.ft.sd;
        int mask = p.sd.ft;
        int val = p.sd.sd;

        for(i=0;i<4;i++){
            int tx = x + mx[i];
            int ty = y + my[i];

            if(check(tx,ty)){
                if(arr[tx][ty]=='G')
                    continue;
                if(arr[tx][ty]=='X'){
                    if(isMasked(mask,memo[mp(tx,ty)]) && dp[tx][ty][mask] > val+1){
                        dp[tx][ty][mask]=val+1;
                        q.push(mp( mp(tx,ty),mp(mask,val+1) ));
                    } else if( !isMasked(mask,memo[mp(tx,ty)])){
                        int temp = mask;
                        maskit(temp,memo[mp(tx,ty)]);

                        if(temp == (1<<c)-1){
                            return val+1;
                        }

                        if(dp[tx][ty][temp] > val+1){
                            dp[tx][ty][temp]=val+1;
                            q.push(mp( mp(tx,ty),mp(temp,val+1) ));
                        }
                    }
                } else {
                    if(dp[tx][ty][mask] > val+1){
                         dp[tx][ty][mask]=val+1;
                         q.push(mp( mp(tx,ty),mp(mask,val+1) ));
                    }
                }
            }
        }
    }
    return INT_MAX;
}

int main()
{
    int i,j,k;
    int test,t;
    scanf("%d",&test);

    for(t=0;t<test;t++){

        memo.clear();

        scanf("%d%d",&m,&n);

        c=0;
        for(i=0;i<n;i++){
            scanf("%s",arr[i]);

            for(j=0;j<m;j++){
                if(arr[i][j]=='B'){
                    sx=i;
                    sy=j;
                }

                if(arr[i][j]=='X'){
                    memo[mp(i,j)]= c++;
                }
            }
        }

        for(i=0;i<n;i++)
            for(j=0;j<m;j++)
                for(k=0;k<(1<<(c));k++)
                    dp[i][j][k]=INT_MAX;

        int ans = solve(sx,sy,0,0);

        /*int ans=INT_MAX;
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                ans = min(ans,dp[i][j][(1<<c)-1]);
            }
        }*/

        if(ans==INT_MAX){
            printf("-1\n");
        }else{
            printf("%d\n",ans-1);
        }
    }
    return 0;
}


// http://ideone.com/xssO6k






