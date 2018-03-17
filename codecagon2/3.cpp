#include<bits/stdc++.h>
using namespace std;

long long dp[1010][1010];
long long n;
long long bt[1010][1010];

string a,b;

string backt(long long x,long long y,string str)
{
    if(x<0 || y<0 || x>=str.length() || y>=str.length()||x>y)
    {
        string s="";
        return s;
    }
    if(x==y)
    {
        return str[x] +"";
    }
    if(str[x]==str[y])
    {
        return (str[x] + backt(x+1,y-1,str)+str[y]);
    }
    else
    {
        if(bt[x][y]==0)
        {
            return backt(x+1,y,str);
        }
        else
            return backt(x,y-1,str);
    }
}

long long solve(string str)
{
   long long i, j, x;

   for (i = 0; i < n; i++)
      dp[i][i] = 1;

    for (x=2; x<=n; x++)
    {
        for (i=0; i<n-x+1; i++)
        {
            j = i+x-1;
            if (str[i] == str[j] && x == 2)
               dp[i][j] = 2;
            else if (str[i] == str[j])
               dp[i][j] = dp[i+1][j-1] + 2;
            else{
              // dp[i][j] = max(dp[i][j-1], dp[i+1][j]);
                if(dp[i][j-1]<=dp[i+1][j])
                {
                    bt[i][j]=0;
                    dp[i][j]=dp[i+1][j];
                }
                else
                {
                    bt[i][j]=1;
                    dp[i][j]=dp[i][j-1];
                }
            }
        }
    }

    return dp[0][n-1];
}

long long cnt[300];

int main()
{
    long long i,j,k;
    long long test,t;

    scanf("%lld",&test);

    for(t=0;t<test;t++)
    {
        cin>>a>>b;

        n=a.length();
        solve(a);
        string t1=backt(0,n-1,a);


        n=b.length();
        solve(b);
        string t2=backt(0,n-1,b);

        memset(cnt,0,sizeof(cnt));

        for(i=0;i<t1.length();i++)
            cnt[t1[i]]++;
        for(i=0;i<t2.length();i++)
            cnt[t2[i]]++;
        long long ans=0;
        long long f=0;
        for(i=0;i<300;i++)
        {
            if(cnt[i]!=0 && cnt[i]%2==0)
                ans += cnt[i];

            if(cnt[i]%2!=0)
            {
                ans+= cnt[i]-1;
                f=1;
            }
        }

        if(f==1)
            ans++;
        printf("%lld\n",ans);
    }

    return 0;
}








