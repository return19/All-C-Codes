#include<bits/stdc++.h>
using namespace std;

long long n,k;

long long arr[110];

long long memo[110][110];

long long solve(long long idx,long long sum)
{
    if(idx==2*n)
    {
        if(sum==0)
            return 1;
        return 0;
    }

    if(arr[idx]==1)
        return solve(idx+1,sum+1);

    if(memo[idx][sum]!=-1)
        return memo[idx][sum];


    if(sum==0)
        return memo[idx][sum]=solve(idx+1,sum+1);

    return memo[idx][sum]=solve(idx+1,sum+1) + solve(idx+1,sum-1);
}

int main()
{
    long long test,t,i,j,k;
    long long temp;

    scanf("%lld",&test);

    for(t=0;t<test;t++)
    {
        scanf("%lld%lld",&n,&k);

        for(i=0;i<2*n;i++){
            arr[i]=0;
        }

        for(i=0;i<=2*n;i++)
            for(j=0;j<=2*n;j++)
                memo[i][j]=-1;

        for(i=0;i<k;i++)
        {
            scanf("%lld",&temp);

            arr[temp-1]=1;
        }

        long long ans=solve(0,0);

        printf("%lld\n",ans);
    }

    return 0;
}
