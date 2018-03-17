#include<bits/stdc++.h>
using namespace std;
#define MAX 99999999999999

char arr[2][1010];
long long n;

//  0 --> X
//  1 --> Not guarded
//  2 --> Guarded

long long memo[1010][5][5];

long long solve(long long idx,long long u,long long d)
{
    //cout<<"here"<<endl;
    long long i,j,k;

    if(idx==n)
    {
        if(u==1 || d==1)
            return MAX;
        return 0;
    }

    if(arr[0][idx]=='X')
    {
        if(u==1)
            return MAX;
    }
    if(arr[1][idx]=='X')
    {
        if(d==1)
            return MAX;
    }

    if(memo[idx][u][d]!=-1)
        return memo[idx][u][d];

    long long u1=2,d1=2;

    if(u==0||u==1)
        u1=1;
    if(d==0||d==1)
        d1=1;

    if(arr[0][idx]=='X' && arr[1][idx]=='X')
    {
        return memo[idx][u][d]=solve(idx+1,0,0);
    }

    if(arr[0][idx]=='X')
    {
        return memo[idx][u][d]=min(solve(idx+1,0,d1),1+solve(idx+1,0,2));
    }
    else if(arr[1][idx]=='X')
    {
        return memo[idx][u][d]=min(solve(idx+1,u1,0),1+solve(idx+1,2,0));
    }
    else
    {
        long long ans=MAX;

        ans=min(ans,2+solve(idx+1,2,2));
        ans=min(ans,solve(idx+1,u1,d1));
        ans=min(ans,1+solve(idx+1,u,2));
        ans=min(ans,1+solve(idx+1,2,d));
        return memo[idx][u][d]=ans;
    }
}

int main()
{
    long long i,j,k;
    long long test,t;

    scanf("%lld",&test);

    for(t=0;t<test;t++)
    {
        scanf("%lld",&n);

        for(i=0;i<2;i++)
        {
            scanf("%s",arr[i]);
        }

        for(i=0;i<=n;i++)
            for(j=0;j<=2;j++)
                for(k=0;k<=2;k++)
                    memo[i][j][k]=-1;

        long long ans=solve(0,0,0);
        printf("Case #%lld: %lld\n",t+1,ans);
    }

    return 0;
}
