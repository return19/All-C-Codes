#include<bits/stdc++.h>
using namespace std;

int cap[10100];
int as[10100];

int memo[10100][5100];

int n;

int solve(int idx,int sum)
{
    if(idx==n)
      return 0;

    if(memo[idx][sum]!=0)
        return memo[idx][sum];

    if(sum==0)
    {
        return memo[idx][sum]=cap[idx] + solve(idx+1,sum+1);
    }
    else if(sum==n/2)
    {
        return memo[idx][sum]=as[idx] + solve(idx+1,sum-1);
    }
    else
        return memo[idx][sum]=min( cap[idx]+solve(idx+1,sum+1) , as[idx]+solve(idx+1,sum-1) );
}

int main()
{
    int i,j,k;

    scanf("%d",&n);

    for(i=n-1;i>=0;i--)
    {
        scanf("%d%d",&cap[i],&as[i]);
    }

    int ans=solve(0,0);

    printf("%d\n",ans);

    return 0;
}
