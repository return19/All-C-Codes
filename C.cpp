#include<bits/stdc++.h>
using namespace std;

long long n,d;

long long memo[2010][2010][5];

long long solve(long long n,long long d,long long extra){
    if(n<0)
        return 0;
    if(n==0)
        return 1;

    if(memo[n][d][extra]!=-1)
        return memo[n][d][extra];

    long long ans=0;
    ans = solve(n-d-extra,d,extra);
    if(extra<=1){
        ans = ans + solve(n-d-extra-1,d,extra+1);
    }

    if(extra==0)
        ans = ans + solve(n-d-extra-2,d,extra+2);
    return memo[n][d][extra] = ans;
}

int main()
{
    long long i,j,k;
    long long test,t;

    scanf("%lld",&test);

    for(t=0;t<test;t++){
        scanf("%lld%lld",&n,&d);

        for(i=0;i<=n;i++)
            for(j=0;j<=n;j++)
                for(k=0;k<=3;k++)
                    memo[i][j][k]=-1;

        long long ans=0;
        for(i=d;i<=n;i+=d){
            ans = ans + solve(n-i,i,0);
        }
        printf("%lld\n",ans);
    }

    return 0;
}
