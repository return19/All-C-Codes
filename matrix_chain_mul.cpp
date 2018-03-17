#include<bits/stdc++.h>
using namespace std;

int p[110];

int dp[110][110];

int solve(int x,int y)
{
    int i,j,k;

    if(x+1==y)
    {
        return 0;
    }
    else if(x+2==y)
    {
        return p[x]*p[x+1]*p[y];
    }

    int ans=INT_MAX;

    for(i=x+1;i<y;i++)
    {
        ans=min(ans, solve(x,i) + solve(i,y) + p[x]*p[i]*p[y]);
    }

    //cout<<x<<" "<<y<<" : "<<ans<<endl;

    return ans;
}

int main()
{
    int i,j,k;
    int n;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&p[i]);
    }

    int ans=solve(0,n-1);

    printf("%d\n",ans);

    return 0;
}
