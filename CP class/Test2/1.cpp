#include<bits/stdc++.h>
using namespace std;

int arr[10100];
int n;
int memo[10100][21][21];

int solve(int idx,int st,int prev){
    if(idx == n){
        if(st == 0)
            return 0;
        return 999999;
    }

    if(memo[idx][st][prev] != -1)
        return memo[idx][st][prev];

    int i,j,k;
    int ans=999999;
    for(i=st;i<=20;i++){
        if(arr[idx] - prev < i){
            ans = min(ans, i + solve(idx+1,0,i/2));
        } else {
            ans = min(ans, i + solve(idx+1, 2*(arr[idx]-prev-i), i/2));
        }
    }
    return memo[idx][st][prev] = ans;
}

int main()
{
    int i,j,k;
    scanf("%d",&n);

    for(i=0;i<n;i++)
        for(j=0;j<=20;j++)
            for(k=0;k<=20;k++)
                memo[i][j][k] = -1;

    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    int ans = solve(0,0,0);
    printf("%d\n",ans);

    return 0;
}
