#include<bits/stdc++.h>
using namespace std;

char str[1010];
int memo[1010][1010];
int n;

int solve(int idx,int sum){
    if(idx==n)
        if(sum==0)
            return 0;
        else
            return INT_MIN;

    if(memo[idx][sum]!=-1)
        return memo[idx][sum];

    int ans=0;
    if(sum==0){
        if(str[idx]=='(')
            ans = max(solve(idx+1,sum+1)+1 , solve(idx+1,sum));
        else
            ans = solve(idx+1,sum);
    } else {
        if(str[idx]=='(')
            ans = max(solve(idx+1,sum+1)+1, solve(idx+1,sum));
        else
            ans = max(solve(idx+1,sum-1) +1, solve(idx+1,sum));
    }
    return memo[idx][sum] = ans;
}

int main()
{
    int i,j,k;
    int test,t;
    scanf("%d",&test);
    for(t=0;t<test;t++){
        scanf("%s",str);
        n = strlen(str);

        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                memo[i][j] = -1;
        int ans = solve(0,0);
        if(ans<0)
            ans=0;
        printf("%d\n",ans);
    }
    return 0;
}
