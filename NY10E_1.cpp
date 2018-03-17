#include<bits/stdc++.h>
using namespace std;

long long memo[65][10];

long long solve(long long n,long long k)
{
    if(n==0)
        return 1;

    if(memo[n][k]!=-1)
        return memo[n][k];

    long long ans=0;
    long long i;

    for(i=k;i<=9;i++)
    {
        ans+=solve(n-1,i);
    }

    return memo[n][k]=ans;
}

int main()
{
    long long i,j,k;

    long long test,t;

    long long n;

    scanf("%lld",&test);

    for(i=0;i<65;i++)
        for(j=0;j<10;j++)
            memo[i][j]=-1;

    for(t=0;t<test;t++)
    {
        scanf("%lld%lld",&j,&n);

        long long ans=solve(n,0);

        printf("%lld %lld\n",j,ans);
    }

    return 0;
}








