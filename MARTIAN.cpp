#include<bits/stdc++.h>
using namespace std;

int n,m;

int y[510][510];
int b[510][510];

int xsum[510][510];
int ysum[510][510];

int memo[510][510];

int solve(int x,int y)
{
    if(x==0||y==0)
        return 0;

    if(memo[x][y]!=-1)
        return memo[x][y];

    return memo[x][y]=max(solve(x-1,y) + xsum[x][y],solve(x,y-1) + ysum[x][y]);
}

int main()
{
    int i,j,k;

    scanf("%d%d",&n,&m);

    while(n!=0&&m!=0)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                memo[i][j]=-1;
                scanf("%d",&y[i][j]);
            }
        }

        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                scanf("%d",&b[i][j]);
            }
        }

        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                xsum[i][j]=xsum[i][j-1] + y[i][j];
            }
        }

        for(j=1;j<=m;j++)
        {
            for(i=1;i<=n;i++)
            {
                ysum[i][j]=ysum[i-1][j] + b[i][j];
            }
        }

        int ans=solve(n,m);

        printf("%d\n",ans);

        scanf("%d%d",&n,&m);
    }

    return 0;
}











