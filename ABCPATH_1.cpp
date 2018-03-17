#include<bits/stdc++.h>
using namespace std;

char arr[110][110];

char str[110];

long long vis[110][110];

long long n,m;

long long movx[10]={0,-1,-1,-1,0,1,1,1};
long long movy[10]={-1,-1,0,1,1,1,0,-1};

long long memo[110][110];

long long check(long long x,long long y)
{
    if(x>=0&&x<n&&y>=0&&y<m)
        return 1;
    return 0;
}

long long solve(long long x,long long y)
{
    if(memo[x][y]!=-1)
        return memo[x][y];

    vis[x][y]=1;

    long long i,j,k;

    long long tx,ty;

    long long ans=0;

    for(i=0;i<8;i++)
    {
        tx=x+movx[i];
        ty=y+movy[i];

        if(vis[tx][ty] || !check(tx,ty))
            continue;

        if(arr[tx][ty]==arr[x][y] + 1)
            ans=max(ans,solve(tx,ty));
    }

    vis[x][y]=0;

    return memo[x][y]=ans+1;
}

int main()
{
    long long i,j,k;
    long long t=0;

    scanf("%lld%lld",&n,&m);

    while(n!=0&&m!=0)
    {
        for(i=0;i<n;i++)
        {
            scanf("%s",str);

            for(j=0;j<m;j++)
            {
                arr[i][j]=str[j];

                vis[i][j]=0;
                memo[i][j]=-1;
            }
        }

        long long ans=0;

        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(arr[i][j]=='A')
                    ans=max(ans,solve(i,j));
            }
        }
        t++;

        printf("Case %lld: %lld\n",t,ans);

        scanf("%lld%lld",&n,&m);
    }

    return 0;
}
