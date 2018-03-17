#include<bits/stdc++.h>
using namespace std;

long long n,m;
char s[4]={'D','I','M','A'};
char arr[1010][1010];
long long vis[1010][1010];
long long memo[1010][1010];

long long move_x[4]={-1,1,0,0};
long long move_y[4]={0,0,-1,1};

long long check(long long x,long long y){
    if(x>=0 && x<n && y>=0 && y<m)
        return 1;
    return 0;
}

long long dfs(long long x,long long y,long long t)
{
    vis[x][y]=1;
    long long i,j,k;
    long long ans=0;

    for(i=0;i<4;i++)
    {
        long long tx=x + move_x[i];
        long long ty=y + move_y[i];

        if(!check(tx,ty))   continue;
        if(arr[tx][ty]==s[(t+1)%4]){
            if(vis[tx][ty]==1){
                return LLONG_MAX;
            }else if(memo[tx][ty]!=-1){
                ans=max(ans,memo[tx][ty]);
            }
            else{
                long long temp=dfs(tx,ty,(t+1)%4);
                if(temp==LLONG_MAX)   return LLONG_MAX;
                ans=max(ans,temp);
            }
        }
    }
    if(arr[x][y]=='A')
        ans++;
    vis[x][y]=0;
    return memo[x][y]=ans;
}

int main()
{
    long long i,j,k;
    scanf("%lld%lld",&n,&m);

    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            memo[i][j]=-1;

    for(i=0;i<n;i++)
        scanf("%s",arr[i]);

    long long ans=0;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            if(memo[i][j]==-1 && arr[i][j]=='D')
            {
                ans=max(ans,dfs(i,j,0));
                if(ans==LLONG_MAX)
                {
                    printf("Poor Inna!\n");
                    return 0;
                }
            }
    if(ans==0)
    {
        printf("Poor Dima!\n");
    }else
        printf("%lld\n",ans);

    return 0;
}
