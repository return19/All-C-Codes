#include<bits/stdc++.h>
using namespace std;

long long n,s;

long long a[110];
long long b[110];
long long c[110];

//map< pair< pair<int,int>,int >,int > memo;

long long M=1000000007;

long long memo[110][110][20010];

long long memo2[110][110];

int add(int a,int b)
{
    if()
}

long long solve2(long long idx,long long cur_area)
{
    if(idx==n)
    {
        if(cur_area<=s)
            return 1;
        return 0;
    }

    if(cur_area>s)
        return 0;

    if(memo2[idx][cur_area]!=-1)
        return memo2[idx][cur_area];

    return memo2[idx][cur_area]=(solve2(idx,cur_area + a[idx]) + solve2(idx+1,cur_area))%M;
}

long long solve(long long idx,long long cur_area,long long cur_diff)
{
    if(idx==n)
    {
        if(cur_area<=s && cur_diff>10000)
            return 1;
        return 0;
    }

    //if(memo.find(make_pair(make_pair(idx,cur_area),cur_diff))!=memo.end())
      //  return memo[make_pair(make_pair(idx,cur_area),cur_diff)];

    if(cur_diff>=20000)
        return solve2(idx,cur_area);
    if(cur_diff<0)
        return 0;


    if(memo[idx][cur_area][cur_diff]!=-1)
        return memo[idx][cur_area][cur_diff];

    long long tk=0,nt=0;
    long long ans=0,i,j,k;


    for(i=1 ; a[idx]*i <= (s-cur_area) ; i++)
    {
        tk = (tk + solve(idx+1,cur_area + a[idx]*i,cur_diff +c[idx]*i - b[idx]*i))%M;
    }

    nt= solve(idx+1,cur_area,cur_diff);

    return memo[idx][cur_area][cur_diff]=((nt + tk)%M);


}


int main()
{
    long long test,i,j,k,t;

    long long x,y,z;

    scanf("%lld",&test);

    for(t=0;t<test;t++)
    {
        scanf("%lld%lld",&n,&s);

        for(i=0;i<n;i++)
        {
            scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
        }

        for(i=0;i<=n;i++)
            for(j=0;j<=s;j++)
                for(k=0;k<=20005;k++)
                    memo[i][j][k]=-1;

        for(i=0;i<=n;i++)
            for(j=0;j<=s;j++)
                memo2[i][j]=-1;

        long long ans=solve(0,0,10000)%M;

        printf("%lld\n",ans);

        //memo.clear();
    }

    return 0;
}
