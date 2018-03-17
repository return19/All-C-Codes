#include<bits/stdc++.h>
using namespace std;

int arr[1010000];
int n,m;

int memo[1010][1010][2];

int solve(int idx,int sum,int f)
{
    if(idx==n)
    {
        if(sum==0 && f)
            return 1;
        return 0;
    }

    if(memo[idx][sum][f]!=-1)
        return memo[idx][sum][f];

    int tk,nt;

    tk=solve(idx+1,(sum + arr[idx])%m,1);
    nt=solve(idx+1,sum,f);

    return memo[idx][sum][f]=tk|nt;
}

int main()
{
    int i,j,k;
    scanf("%d%d",&n,&m);

    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    if(n>=m)
    {
        printf("YES\n");
    }
    else
    {
        for(i=0;i<=m;i++)
            for(j=0;j<=m;j++)
                for(k=0;k<2;k++)
                    memo[i][j][k]=-1;

        if(solve(0,0,0))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

