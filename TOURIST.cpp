#include<bits/stdc++.h>
using namespace std;

long long n,m;

vector<string> v;
string s;
long long memo[110][110][110];

long long solve(long long x1,long long y1,long long x2,long long y2)
{
    if(x1==n || x2==n || y1==m || y2==m)
        return 0;

    if(v[x1][y1]=='#' || v[x2][y2]=='#')
        return 0;

    if(memo[x1][y1][x2]!=-1)
        return memo[x1][y1][x2];

    long long rr,rd,dr,dd;

    rr=solve(x1,y1+1,x2,y2+1);
    rd=solve(x1,y1+1,x2+1,y2);
    dr=solve(x1+1,y1,x2,y2+1);
    dd=solve(x1+1,y1,x2+1,y2);

    long long ans=max(max(rr,dd),max(rd,dr));

    if(x1==x2 && y1==y2)
    {
        if(v[x1][y1]=='*')
            return memo[x1][y1][x2]=1+ans;
        return memo[x1][y1][x2]=ans;
    }

    if(v[x1][y1]=='*')
        ans++;
    if(v[x2][y2]=='*')
        ans++;
    return memo[x1][y1][x2]=ans;
}

int main()
{
    long long i,j,k;
    long long test,t;
    scanf("%lld",&test);

    for(t=0;t<test;t++)
    {
        scanf("%lld%lld",&m,&n);
        v.resize(0);

        for(i=0;i<n;i++)
        {
            cin>>s;
            v.push_back(s);
        }

        for(i=0;i<=n;i++)
            for(j=0;j<=m;j++)
                for(k=0;k<=n;k++)
                    memo[i][j][k]=-1;

        long long ans=solve(0,0,0,0);
        printf("%lld\n",ans);
    }
    return 0;
}
