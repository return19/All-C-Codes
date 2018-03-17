#include<bits/stdc++.h>
using namespace std;

int n;

char arr[3][110];
int memo[3][110];
int check(int x,int y)
{
    if( (x>=0 && x<3 && y<n && arr[x][y]=='.') || (x>=0 && x<3 && y>=n) )
        return 1;
    return 0;
}

int solve(int x,int y)
{
    if(y>=n)
        return 1;

    if(memo[x][y]!=-1)
        return memo[x][y];

    int u=0,r=0,d=0;

    if(check(x,y+1) && check(x-1,y+1) && check(x-1,y+3))
        u=solve(x-1,y+3);
    if(check(x,y+1) &&check(x,y+3))
        r=solve(x,y+3);
    if(check(x,y+1) && check(x+1,y+1) &&check(x+1,y+3))
        d=solve(x+1,y+3);

    return memo[x][y]=((u|r)|d);
}

int main()
{
    int i,j,k;
    int test,t;
    scanf("%d",&test);

    for(t=0;t<test;t++){

        scanf("%d%d",&n,&k);

        for(i=0;i<3;i++)
            for(j=0;j<=n;j++)
                memo[i][j]=-1;

        for(i=0;i<3;i++)
            scanf("%s",arr[i]);

        int ans;
        if(arr[0][0]=='s')
            ans=solve(0,0);
        else if(arr[1][0]=='s')
            ans=solve(1,0);
        else
            ans=solve(2,0);

        if(ans)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
