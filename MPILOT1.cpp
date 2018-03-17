#include<bits/stdc++.h>
using namespace std;

#define MAX 99999999

int arr[10100][2];

int n;

int dp[10100][5100];

/*int solve(int idx,int num)
{
    int i,j,k;

    if(idx==n){
        if(num==0)
            return 0;
        return MAX;
    }

    if(base[idx][num]==1)
        return memo[idx][num];
    base[idx][num]=1;

    int tk=MAX,nt=MAX;

    tk=arr[idx][0] + solve(idx+1,num+1);

    if(num!=0)
        nt=arr[idx][1] + solve(idx+1,num-1);

    return memo[idx][num]=min(tk,nt);
}
*/
int main()
{
    int i,j,k;

    scanf("%d",&n);

    for(i=n;i>0;i--)
    {
        scanf("%d%d",&arr[i][0],&arr[i][1]);
    }

    //int ans=solve(0,0);

    dp[1][1]=arr[1][0];
    dp[1][0]=MAX;

    for(i=2;i<=n;i++)
    {
        for(j=0;j<=i&&j<=n/2;j++)
        {
            if(j==0)
                dp[i][j]=arr[i][1] + dp[i-1][j+1];
            else if(j==i)
                dp[i][j]=arr[i][0] + dp[i-1][j-1];
            else
                dp[i][j]=min(arr[i][0]+dp[i-1][j-1],arr[i][1]+dp[i-1][j+1]);
        }
        dp[i][j]=MAX;
    }

    printf("%d\n",dp[n][0]);

    return 0;
}
