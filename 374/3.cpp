#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ft first
#define sd second

int n,m;
long t;
pair<long,int> memo[5005][5005];
vector< pair<int,long> > g[5005];
vector<int> res;

/*int solve(int cur,int num,int tm){

    if(tm > t)
        return -1;

    if(idx==n-1){
        return 1;
    }

    if(memo[cur][num]<=tm)
        return -1;
    memo[cur][num]
    int ans=0;
    int i,j,k;
    for(i=0;i<g[cur].size();i++){
        ans = max(ans,solve(g[cur][i].ft,num+1,tm + ))
    }

}*/

int solve1(){
    int i,j,k;
    queue< pair< pair<int,int>,long > > q;
    int ans=0;

    q.push(mp(mp(0,1),0*1LL));
    while(!q.empty()){
        pair< pair<int,int>,long > p = q.front();
        q.pop();
        int cur = p.ft.ft;
        int val = p.ft.sd;
        long tm = p.sd;

        for(i=0;i<g[cur].size();i++){
            if(tm + g[cur][i].sd <=t && memo[g[cur][i].ft][val+1].ft >= tm + g[cur][i].sd ){
                memo[g[cur][i].ft][val+1].ft = tm + g[cur][i].sd;
                memo[g[cur][i].ft][val+1].sd = cur;
                if(g[cur][i].ft == n-1)
                    ans = max(ans,val+1);
                else
                    q.push(mp(mp(g[cur][i].ft,val+1),tm + g[cur][i].sd));
            }
        }
    }
    return ans;
}

int main()
{
    int i,j,k;
    int x,y;
    long z;
    scanf("%d%d%ld",&n,&m,&t);

    for(i=0;i<m;i++){
        scanf("%d%d%ld",&x,&y,&z);
        x--;    y--;
        g[x].push_back(mp(y,z));
    }

    for(i=0;i<=n;i++)
        for(j=0;j<=n;j++)
            memo[i][j].ft = 99999999999;

    int ans = solve1();
    printf("%d\n",ans);

    int cur=n-1;
    for(i=ans;i>0;i--){
        res.push_back(cur);
        cur = memo[cur][i].sd;
    }

    for(i=res.size()-1;i>=0;i--)
        cout<<res[i]+1<<" ";

    return 0;
}









