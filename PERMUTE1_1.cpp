#include<bits/stdc++.h>
using namespace std;

long long n,k;
long long memo[5010][110];
long long ismasked(long long mask,long long pos)
{
    if(pos==0)
    {
        return mask&1;
    }

    return (mask&(1<<pos));
}

void maskit(long long &mask,long long pos)
{
    if(pos==0)
        mask=mask|1;
    else
        mask=mask|(1<<pos);
}

long long solve(long long idx,long long mask,long long k)
{
    if(idx==n)
    {
        if(k==0)
            return 1;
        return 0;
    }

    long long i,j;
    long long cnt=0;
    long long ans=0;

    if(k<0)
        return 0;

    if(memo[mask][k]!=-1)
        return memo[mask][k];

    for(i=0;i<n;i++)
    {
        if(cnt>k)
            break;

        if(ismasked(mask,i))
            cnt++;
        else
        {
            long long temp=mask;
            maskit(temp,i);
            ans += solve(idx+1,temp,k-cnt);
        }
    }

    return memo[mask][k]=ans;
}
int main()
{
    long long i,j;
    long long test,t;

    scanf("%lld",&test);

    for(t=0;t<test;t++)
    {
        scanf("%lld%lld",&n,&k);

        for(i=0;i<5000;i++)
            for(j=0;j<=k+1;j++)
                memo[i][j]=-1;

        long long ans=solve(0,0,k);
        printf("%lld\n",ans);
    }
    return 0;
}
