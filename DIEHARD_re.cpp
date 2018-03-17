#include<bits/stdc++.h>
using namespace std;

long long memo[2110][2110][4];

long long solve(long long h,long long a,long long cur_state)
{
    if(h<=0||a<=0)
        return 0;

    if(memo[h][a][cur_state]!=-1)
        return memo[h][a][cur_state];

    if(cur_state==1)
    {
        return memo[h][a][cur_state]=1+max(solve(h-5,a-10,2),solve(h-20,a+5,3));
    }
    else if(cur_state==2||cur_state==3)
    {
        return memo[h][a][cur_state]=1+solve(h+3,a+2,1);
    }

    return memo[h][a][cur_state]=solve(h+3,a+2,1);

}

int main()
{
    long long test,t,i,j,k;
    long long h,a;

    scanf("%lld",&test);

    for(t=0;t<test;t++)
    {
        scanf("%lld%lld",&h,&a);

        for(i=0;i<=h+210;i++)
            for(j=0;j<=a+210;j++)
                for(k=0;k<=3;k++)
                    memo[i][j][k]=-1;

        long long ans=solve(h,a,0);

        printf("%lld\n",ans);
    }

    return 0;
}
