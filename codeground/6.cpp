#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ft first
#define sd second

long long x[1010];
long long y[1010];
pair<long long,long long> ans;
long long n;
pair<long long,long long> dp[1010];

pair<long long,long long> solve(long long idx){
    if(idx==n){
        return mp(0,0);
    }

    if(dp[idx].ft!=-1)
        return dp[idx];

    pair<long long,long long> nt,tk;
    nt = solve(idx+1);
    tk = nt;
    tk.ft += x[idx];
    tk.sd += y[idx];

    if(nt.ft*nt.ft + nt.sd*nt.sd > tk.ft*tk.ft + tk.sd*tk.sd)
        return dp[idx] = nt;
    return dp[idx]= tk;
}

int main()
{
    long long i,j,k;
    long long test,t;
    scanf("%lld",&test);
    for(t=0;t<test;t++){
        scanf("%lld",&n);
        for(i=0;i<n;i++)
            scanf("%lld",&x[i]);
        for(i=0;i<n;i++)
            scanf("%lld",&y[i]);

        for(i=0;i<=n;i++){
            dp[i].ft = -1;
            dp[i].sd = -1;
        }

        ans = solve(0);
        printf("%lld\n",ans.ft*ans.ft + ans.sd*ans.sd);
    }

    return 0;
}





/*#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ft first
#define sd second

long long x[1010];
long long y[1010];
long long ans;
long long n;

long long solve(long long f,long long s){
    long long a=0,b=0;
    long long i,j,k;
    for(i=0;i<n;i++){
        if(x[i]>=0 && y[i]>=0 && f==1 && s==1)
        {
            a+= x[i];
            b+= y[i];
        } else if(x[i]<=0 && y[i]<=0 && f==0 && s==0){
            a+= x[i];
            b+= y[i];
        } else if(x[i]>=0 && y[i]<=0 && f==1 && s==0){
            a+= x[i];
            b+= y[i];
        } else if(x[i]<=0 && y[i]>=0 && f==0 && s==1){
            a+= x[i];
            b+= y[i];
        }
    }
    return a*a + b*b;
}

int main()
{
    long long i,j,k;
    long long test,t;
    scanf("%lld",&test);
    for(t=0;t<test;t++){
        scanf("%lld",&n);
        for(i=0;i<n;i++)
            scanf("%lld",&x[i]);
        for(i=0;i<n;i++)
            scanf("%lld",&y[i]);

        ans = max( max(solve(0,0),solve(1,1)),
                  max(solve(0,1),solve(1,0)));
        printf("%lld\n",ans);
    }

    return 0;
}








*/



