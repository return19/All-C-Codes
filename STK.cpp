#include<bits/stdc++.h>
using namespace std;

int n,k;
int arr[3100];
int memo[3100][3100][2];

int solve(int idx,int t,int q){
    if(idx==n-1)
        return 0;

    if(memo[idx][t][q]!=-1)
        return memo[idx][t][q];

    if(q==1){
        int nt = arr[idx+1]-arr[idx] +solve(idx+1,t,q);
        int tk = solve(idx+1,t,0);
        return memo[idx][t][q]=max(tk,nt);
    }else{ // q==0
        int tk,nt;
        if(t==k){
            return memo[idx][t][q]=0;
        }else{
            tk = arr[idx+1]-arr[idx] + solve(idx+1,t+1,1);
            nt = solve(idx+1,t,0);
            return memo[idx][t][q]=max(nt,tk);
        }
    }
}

int main()
{
    int i,j;
    int test,t;

    scanf("%d",&test);

    for(t=0;t<test;t++)
    {
        scanf("%d%d",&n,&k);

        for(i=0;i<=n;i++)
            for(j=0;j<=k+1;j++)
                for(int x=0;x<=1;x++)
                    memo[i][j][x]=-1;

        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);
        int ans=solve(0,0,0);
        printf("%d\n",ans);
    }
    return 0;
}
