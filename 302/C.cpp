#include<bits/stdc++.h>
using namespace std;

long long n;
long long m;
long long b;
long long M;

long long bugs[60100];

//map< pair<pair<long long,long long>,long long>,long long > memo;

long long dp[10][510][510];

long long solve(long long x,long long y,long long z)// x=programmer  y= line  z= current bugs
{
    if(z>b)
        return 0;

    if(x==n)
    {
        if(y<=m)
            return 0;
        else
        {
            return 1;
        }
    }

    if(y>m)
        return 1;

        if(memo[x][y][z]!=-1)
            return memo[x][y][z];

    //if(memo.find(make_pair(make_pair(x,y),z))!=memo.end())
      //  return memo[make_pair(make_pair(x,y),z)];

    long long ans1= solve(x,y+1,z+bugs[x]);
    //long long ans2=solve(x+1,y+1,z+bugs[x]);

    long long ans3 = solve(x+1,y,z);

    //cout<<x<<" "<<y<<" "<<z<<" : "<<ans1<<" "<<ans2<<" "<<ans3<<endl;

    return memo[x][y][z]=(ans1 + ans3)%M;
}

int main()
{
    long long test,i,j,k;
    long long t;

    //scanf("%d",&test);

    test=1;

    for(t=0;t<test;t++)
    {
        //memo.clear();

        scanf("%lld%lld%lld%lld",&n,&m,&b,&M);

        for(i=0;i<n;i++)
            scanf("%lld",&bugs[i]);

        //long long ans=solve(0,1,0);


        for(j=0;j<=m;j++)
            for(k=0;k<=b;k++)
                dp[0][j][k]=0;

        for(i=0;i<=n;i++)
            for(k=0;k<=b;k++)
                dp[i%2][0][k]=1;

         for(i=1;i<=n;i++)
         {
             for(j=1;j<=m;j++)
             {
                 for(k=0;k<=b;k++)
                 {
                     dp[i%2][j][k]=0;
                     if(k-bugs[i-1]>=0)
                        dp[i%2][j][k]=dp[i%2][j-1][k-bugs[i-1]];
                    dp[i%2][j][k] =(dp[i%2][j][k]+ dp[(i+1)%2][j][k])%M;
                 }
             }
         }

        printf("%lld\n",dp[n%2][m][b]%M);
    }

    return 0;
}
