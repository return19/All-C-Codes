#include<bits/stdc++.h>
using namespace std;

long long arr[101000];
long long n;
// 0-->dp
// 1-->greedy
long long memo[1010][1010][2];
long long solve(long long l,long long r,long long turn)
{
    long long i,j,k;
    if(l>r)
    {
        return 0;
    }
    if(memo[l][r][turn]!=-1)
        return memo[l][r][turn];

    if(turn==0)
    {
        if(arr[l]<arr[r])
        {
            return memo[l][r][turn]=solve(l,r-1,1) - arr[r];
        }
        else
            return memo[l][r][turn]=solve(l+1,r,1) -arr[l];
    }
    long long lt,rt;
    lt=solve(l+1,r,0) + arr[l];
    rt=solve(l,r-1,0) + arr[r];
    return memo[l][r][turn]=max(lt,rt);
}

int main()
{
    long long i,j,k;
    scanf("%lld",&n);
    long long t=1;
    while(n!=0)
    {
        for(i=0;i<n;i++)
            scanf("%lld",&arr[i]);

        for(i=0;i<=n;i++)
            for(j=0;j<=n;j++)
        {
            memo[i][j][0]=-1;
            memo[i][j][1]=-1;
        }
        long long ans=solve(0,n-1,1);

        printf("In game %lld, the greedy strategy might lose by as many as %lld points.\n",t,ans);
        t++;
        scanf("%lld",&n);
    }
    return 0;
}
