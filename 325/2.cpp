#include<bits/stdc++.h>
using namespace std;

int n;
int cross[110];
int adj[2][110];

int memo[2][61][2][61][2];

int solve(int x1,int y1,int x2,int y2,int chg)
{
    if(x1==1 && y1==n-1 && x2==1 && y2==n-1)
    {
        if(chg==1)
            return 0;
        return 99999999;
    }

    if(memo[x1][y1][x2][y2][chg]!=-1)
        return memo[x1][y1][x2][y2][chg];

    int rr=INT_MAX,rd=INT_MAX,dd=INT_MAX,dr=INT_MAX;

    if(y1+1<n && y2+1<n)
        rr=adj[x1][y1] + adj[x2][y2] + solve(x1,y1+1,x2,y2+1,chg);
    if(y1+1<n && x2+1<2)
        rd=adj[x1][y1] + cross[y2] + solve(x1,y1+1,x2+1,y2,1);
    if(x1+1<2 && x2+1<2)
        dd=cross[y1] + cross[y2] + solve(x1+1,y1,x2+1,y2,chg);
    if(x1+1<2 && y2+1<n)
        dr=cross[y1] + adj[x2][y2] + solve(x1+1,y1,x2,y2+1,1);

    return memo[x1][y1][x2][y2][chg]=min(min(rd,dr),min(rr,dd));
}

int main()
{
    int i,j,k;
    scanf("%d",&n);

    for(i=0;i<2;i++)
        for(j=0;j<n-1;j++)
            scanf("%d",&adj[i][j]);
    for(i=0;i<n;i++)
        scanf("%d",&cross[i]);

    for(i=0;i<2;i++)
        for(j=0;j<=n;j++)
            for(k=0;k<2;k++)
            for(int x=0;x<=n;x++){
                memo[i][j][k][x][0]=-1;
                memo[i][j][k][x][1]=-1;

            }

    int ans=solve(0,0,0,0,0);
    printf("%d\n",ans);

    return 0;
}
