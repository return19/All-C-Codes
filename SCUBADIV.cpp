#include<bits/stdc++.h>
using namespace std;

int n,o,k;

int ox[10100];
int ni[10100];
int w[10100];

int memo[1010][310][510];

int solve(int x,int osum,int nsum)
{
    int i,j;

    if(x==k)
    {
        if(osum>=o&&nsum>=n)
            return 0;
        return INT_MAX;
    }

    if(osum>=o&&nsum>=n)
        return 0;

    if(memo[x][osum][nsum]!=-1)
        return memo[x][osum][nsum];

    int t,nt;

    t=solve(x+1,osum + ox[x], nsum + ni[x]);

    nt=solve(x+1,osum,nsum);

    if(t==INT_MAX&&nt==INT_MAX)
        return memo[x][osum][nsum]=INT_MAX;

    if(t==INT_MAX)
    {
        return memo[x][osum][nsum]=nt;
    }
    else if(nt==INT_MAX)
        return memo[x][osum][nsum]=(t + w[x]);
    else
        return memo[x][osum][nsum]=min(t+w[x],nt);
}

int main()
{
    int i,j;
    int x,y,z;
    int test,t;

    scanf("%d",&test);

    for(t=0;t<test;t++)
    {
        //memo.clear();

        scanf("%d%d",&o,&n);

        for(i=0;i<1010;i++)
        {
            for(j=0;j<300;j++)
            {
                for(x=0;x<500;x++)
                    memo[i][j][x]=-1;
            }
        }

        scanf("%d",&k);

        for(i=0;i<k;i++)
        {
            scanf("%d%d%d",&x,&y,&z);

            ox[i]=x;
            ni[i]=y;
            w[i]=z;
        }

        int ans=solve(0,0,0);

        printf("%d\n",ans);

    }

    return 0;
}
