#include<bits/stdc++.h>
using namespace std;

char a[1010],b[1010];
int n1,n2;
int k;

int memo[1010][1010];

int solve(int x,int y)
{
    int i,j;
    if(x==n1 || y==n2)
        return 0;

    if(memo[x][y]!=-1)
        return memo[x][y];

    int ans=max(solve(x+1,y),solve(x,y+1));

    for(i=0 ; x+i<n1 && y+i<n2 ; i++)
    {
        if(a[i+x]!=b[i+y])
            break;
        else
        {
            if(i>=k-1)
                ans=max(ans,(i+1) + solve(x+i+1,y+i+1));
        }
    }
    return memo[x][y]=ans;
}

int main()
{
    int i,j;
    int n;

    scanf("%d",&k);

    while(k!=0)
    {
        scanf("%s",a);
        scanf("%s",b);
        n1=strlen(a);
        n2=strlen(b);

        for(i=0;i<=n1;i++)
            for(j=0;j<=n2;j++)
                memo[i][j]=-1;

        int ans=solve(0,0);
        printf("%d\n",ans);
        scanf("%d",&k);
    }

    return 0;
}
















