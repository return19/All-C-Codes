#include<bits/stdc++.h>
using namespace std;

long long n,k;
long long arr[51];
long long memo[51][51];

long long solve(long long idx,long long sum)
{
    if(idx==2*n)
    {
        if(sum==0)
            return 1;
        return 0;
    }

    if(memo[idx][sum]!=-1)
        return memo[idx][sum];

    if(arr[idx]==1)
        return memo[idx][sum]=solve(idx+1,sum+1);

    long long o=0,c=0;

    if(sum==0)
    {
        return memo[idx][sum]=solve(idx+1,1);
    }else{
        o=solve(idx+1,sum+1);
        c=solve(idx+1,sum-1);
        return memo[idx][sum]=(o+c);
    }
}

int main()
{
    long long i,j;
    long long test,t;
    long long x;
    scanf("%lld",&test);

    for(t=0;t<test;t++)
    {
        scanf("%lld%lld",&n,&k);

        for(i=0;i<2*n;i++)
            arr[i]=0;

        for(i=0;i<2*n;i++)
            for(j=0;j<2*n;j++)
                memo[i][j]=-1;

        for(i=0;i<k;i++)
        {
            scanf("%lld",&x);
            arr[x-1]=1;
        }

        long long ans=solve(0,0);
        printf("%lld\n",ans);
    }
    return 0;
}
