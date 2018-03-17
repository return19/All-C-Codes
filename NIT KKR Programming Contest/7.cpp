#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ft first
#define sd second

vector< long long > v[101000];
long long n;
long long cost[101000];
long long vis[101000];

long long ans;

long long dfs(long long x){
    vis[x]=1;

    long long i,j,k;

    vector<long long> res;

    for(i=0;i<v[x].size();i++){
        if(!vis[v[x][i]]){
            long long temp=dfs(v[x][i]);

            if(temp>0)
                res.push_back(temp);
        }
    }

    if(res.size()==0){
        if(cost[x]>0)
        {
            ans=max(ans,cost[x]);
            return cost[x];
        }
        return 0;
    }

    long long l=0,r=0;

    sort(res.begin(),res.end());

    long long len=res.size();

    if(len-1>=0)
        l=res[len-1];
    if(len-2>=0)
        r=res[len-2];

    ans=max(ans,l+r+cost[x]);
    return max(l,r)+cost[x];
}

int main()
{
    long long i,j,k;
    long long test,t;
    long long x,y;

    scanf("%lld",&test);

    for(t=0;t<test;t++){
        scanf("%lld",&n);

        for(i=0;i<n;i++)
            v[i].resize(0);
        ans=0;

        for(i=0;i<n;i++)
            scanf("%lld",&cost[i]);

        for(i=0;i<n-1;i++){
            scanf("%lld%lld",&x,&y);
            x--;
            y--;
            v[x].push_back(y);
            v[y].push_back(x);
        }

        memset(vis,0,sizeof(vis));
        dfs(0);
        printf("%lld\n",ans);
    }
    return 0;
}

















