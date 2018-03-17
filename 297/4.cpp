#include<bits/stdc++.h>
using namespace std;

long long n,k,s;
long long arr[51];

long long fact[20];

long long solve(long long idx,long long k,long long sum)
{
    if(sum>s)
        return 0;
    if(idx==n)
    {
        if(sum==s)
            return 1;
        return 0;
    }


    if(arr[idx]>19)
    {
        return solve(idx+1,k,sum) + solve(idx+1,k,sum + arr[idx]);
    }
    long long nc=solve(idx+1,k,sum);
    long long cntk=solve(idx+1,k,sum + arr[idx]);

    long long ctk=0;
    if(k>0)
        ctk=solve(idx+1,k-1,sum + fact[arr[idx]]);

    return nc + cntk + ctk;
}

int main()
{
    long long i,j;
    scanf("%lld%lld%lld",&n,&k,&s);

    fact[0]=1;
    fact[1]=1;

    for(i=2;i<=18;i++)
        fact[i]=i*fact[i-1];

    for(i=0;i<n;i++)
        scanf("%lld",&arr[i]);

    long long ans=solve(0,k,0);
    printf("%lld\n",ans);

    return 0;
}
