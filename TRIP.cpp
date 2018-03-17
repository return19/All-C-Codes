#include<bits/stdc++.h>
using namespace std;

char a[1010];
char b[1010];

int n,m;

int ans;

map< string , int > memo;
map< string , int >::iterator it;

void solve(int x,int y,string str)
{
    if(x==n||y==m)
    {
        if(str.length()==ans)
            memo[str];
        return;
    }

    if(a[x]==b[y])
    {
        solve(x+1,y+1,str + a[x]);
    }
    else
    {
        solve(x+1,y,str);
        solve(x,y+1,str);
    }
}

int dp[1010][1010];

int main()
{

    int test,t,i,j,k;

    scanf("%d",&test);

    for(t=0;t<test;t++)
    {
        scanf("%s",a);
        scanf("%s",b);

        n=strlen(a);
        m=strlen(b);

        for(i=0;i<=n;i++)
            dp[i][0]=0;

        for(j=0;j<=m;j++)
            dp[0][j]=0;

        for(i=1;i<=n;i++)
            for(j=1;j<=m;j++)
            {
                if(a[i-1]==b[j-1])
                    dp[i][j]=dp[i-1][j-1] + 1;
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }

            ans=dp[n][m];

        solve(0,0,"");

        for(it=memo.begin();it!=memo.end();it++)
            cout<<it->first<<endl;

        memo.clear();
    }

    return 0;
}
