#include<bits/stdc++.h>
using namespace std;

int n,m;

int t;

char a[2010];
char b[2010];

int memo[2010][2010];

int solve(int x,int y)
{
    int i,j,k;

    if(memo[x][y]!=-1)
        return memo[x][y];

    if(x==n)
    {
        int ans=0;

        for(i=y;i<m;i++)
            ans+=t;

        return memo[x][y]=ans;
    }

    if(y==m)
    {
        int ans=0;

        for(i=x;i<n;i++)
            ans+=t;

        return memo[x][y]=ans;
    }

    return memo[x][y]=min( min(solve(x+1,y) + t,solve(x,y+1) +t),solve(x+1,y+1) + abs( a[x]-b[y] ) );
}

int main()
{
    int i,j,k;

    scanf("%s",a);
    scanf("%s",b);

    scanf("%d",&t);

    n=strlen(a);
    m=strlen(b);

    for(i=0;i<=n;i++)
        for(j=0;j<=m;j++)
            memo[i][j]=-1;

    int ans=solve(0,0);

    printf("%d\n",ans);

    return 0;
}
