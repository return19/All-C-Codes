#include<bits/stdc++.h>
using namespace std;

vector<long long> g[101000];

long long fib[1010000];
long long M=1e9+7;
long long lvl[101000];

void dfs(long long x,long long val){
    long long i;
    lvl[x] = val;
    for(i=0;i<g[x].size();i++){
        dfs(g[x][i],val+1);
    }
}

long long solve(long long x,long long &k){
    long long i;
    long long ans=0;
    for(i=0;i<g[x].size();i++){
        ans = (ans + solve(g[x][i],k))%M;
    }
    return (ans + fib[lvl[x]+k])%M;
}

int main()
{
    long long i,j,k;
    long long n,x,y;

    fib[1]=fib[2]=1;
    for(i=3;i<1010000;i++)
        fib[i] = ((2*fib[i-1])%M + (3*fib[i-2])%M)%M;

    scanf("%lld",&n);
    for(i=1;i<n;i++){
        scanf("%lld",&x);
        x--;
        g[x].push_back(i);
    }
    dfs(0,0);
    long long q;
    scanf("%lld",&q);
    for(i=0;i<q;i++){
        scanf("%lld%lld",&y,&x);
        y--;

        long long ans = solve(y,x);
        printf("%lld\n",ans);
    }
    return 0;
}













