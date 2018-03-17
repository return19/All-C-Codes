#include<bits/stdc++.h>
using namespace std;

long long n;

long long memo[150][150][20];
long long base[150][150][20];

long long solve(
                long long x,long long y,long long k)
{

    long long i,j;
    if(k==0)
    {
        if(x==100 && y==100)
            return 1;
        return 0;
    }

    if(base[x][y][k]==1)
        return memo[x][y][k];
    base[x][y][k]=1;
    long long ans= solve(x-1,y-1,k-1);
    ans+= solve(x-1,y+1,k-1);
    ans+= solve(x+1,y-1,k-1);
    ans+= solve(x+1,y+1,k-1);
    ans+= solve(x,y-2,k-1);
    ans+= solve(x,y+2,k-1);
    return memo[x][y][k]=ans;

}

int main()
{
    long long i,j,k;
    long long test,t;
    scanf("%lld",&test);
    for(t=0;t<test;t++)
    {
        scanf("%lld",&n);
        long long ans=solve(100,100,n);
        printf("%lld\n",ans);
    }

    return 0;
}
