#include<bits/stdc++.h>
using namespace std;

long long N;

long long min2(long long x,long long y)
{
    if(x<y)
        return x;
    else
        return y;
}

long long solve(long long n,long long idx)
{
    if(idx==N+1)
        return 1;

    long long i,sum=0;

    for(i=1;i<=n+1;i++)
    {
        if(i!=n+1)
            sum+=solve(n,idx+1);
        else
            sum+=solve(n+1,idx+1);
    }

    return sum;
}

int main()
{
    long long test,i,j,k;

    scanf("%lld",&test);

    for(i=0;i<test;i++)
    {
        scanf("%lld",&N);

        cout<<solve(0,1)<<endl;
    }

    return 0;
}
