#include<bits/stdc++.h>
using namespace std;

int n,m;
int k; // 1<=k<=10
int arr[11][11];
int sweet[11][11];
int openCost[110];
int spell[10];
int cost; // 1<=cost<=100

int dp[15][15][150][15][15];

int solve(int idx,int num,int cost,int spl,int totSpell){
    if(idx == n)
        return 0;
    if(num == m+1)
        return solve(idx+1,0,cost,0,totSpell);

    if(dp[idx][num][cost][spl][totSpell]!=-1)
        return dp[idx][num][cost][spl][totSpell];

    if(num == 0){
        int tk = 0, nt = 0;
        if(cost >= openCost[idx])
            tk = solve(idx,num+1,cost-openCost[idx],spl,totSpell);
        nt = solve(idx+1,num,cost,spl,totSpell);
        return dp[idx][num][cost][spl][totSpell] = max(tk,nt);

    } else {

        int ans = solve(idx,num+1,cost,spl,totSpell);
        int i;
        for(i=1;i-1+spl<=spell[idx] && i-1+totSpell <= k && cost>= arr[idx][num]*i ;i++){
          //  cout<<"idx:"<<idx<<" i:"<<i<<endl;
           // cout<<num<<endl;
            ans = max(ans,sweet[idx][num]*i + solve(idx,num+1,cost - arr[idx][num]*i,spl + i-1, totSpell + i-1));
        }
        return dp[idx][num][cost][spl][totSpell] = ans;
    }
}

int main()
{
    freopen("input08.txt","r",stdin);
    freopen("output08.txt","w",stdout);
    int i,j;
    scanf("%d%d%d%d",&n,&m,&cost,&k);

    for(i=0;i<=n;i++)
        for(j=0;j<=m+1;j++)
            for(int x=0;x<=cost;x++)
                for(int y=0;y<=11;y++)
                    for(int z=0;z<=k;z++)
                        dp[i][j][x][y][z]=-1;


    for(i=0;i<n;i++){
        scanf("%d",&openCost[i]);
    }
    for(i=0;i<n;i++)
        scanf("%d",&spell[i]);
    for(i=0;i<n;i++){
        arr[i][0] = openCost[i];
        for(j=1;j<=m;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    for(i=0;i<n;i++)
        for(j=1;j<=m;j++)
            scanf("%d",&sweet[i][j]);

    int ans=solve(0,0,cost,0,0);
    printf("%d\n",ans);
    return 0;
}
