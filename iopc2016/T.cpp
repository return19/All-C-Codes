#include<bits/stdc++.h>
using namespace std;

vector< pair<long long,long long> > adj[10100];
long long n,m,d;
long long w[10100];
long long dist[10100];
set< pair<long long,long long> > s;
set< pair<long long,long long> >::iterator it;
long long vis[10100];

void dijkstra()
{
    long long i,j,k;
    long long x,y,z;

    s.empty();

    dist[0]=0;
    vis[0]=0;
    s.insert(make_pair(0,0));

    for(i=1;i<n;i++){
        vis[i]=0;
        dist[i]=LLONG_MAX;
        s.insert(make_pair(LLONG_MAX,i));
    }

    for(i=0;i<n;i++)
    {
        it=s.begin();
        x=it->first;
        y=it->second;

        s.erase(make_pair(x,y));

        if(y==LLONG_MAX)
            return;
        vis[y]=1;

        for(j=0;j<adj[y].size();j++)
        {
            if(vis[adj[y][j].first])
                continue;
            long long temp=adj[y][j].first;
            if( x + adj[y][j].second < dist[temp])
            {
                s.erase(make_pair(dist[temp],temp));
                dist[temp]=x + adj[y][j].second;
                s.insert(make_pair(dist[temp],temp));
            }
        }
    }
}

long long memo[10010][1010];

long long solve(long long idx,long long d)
{
    if(idx==n)
    {
        return 0;
    }

    if(memo[idx][d]!=-1)
        return memo[idx][d];

    long long tk=0,nt=0;

    if(dist[idx]<=d){
        tk = w[idx] + solve(idx+1,d-dist[idx]);
    }
    nt=solve(idx+1,d);

    return memo[idx][d]=max(tk,nt);
}

int main()
{
    long long i,j,k;
    long long test,t;
    long long x,y,z;

    scanf("%lld",&test);

    for(t=0;t<test;t++)
    {
        scanf("%lld%lld%lld",&n,&m,&d);

        for(i=0;i<n;i++)
            adj[i].resize(0);

        for(i=0;i<m;i++)
        {
            scanf("%lld%lld%lld",&x,&y,&z);

            adj[x].push_back(make_pair(y,z));
            adj[y].push_back(make_pair(x,z));
        }
        for(i=1;i<n;i++)
            scanf("%lld",&w[i]);

        dijkstra();

        /*for(i=0;i<n;i++)
            cout<<dist[i]<<" ";
        cout<<endl;*/

        for(i=0;i<n;i++)
        {
            if(dist[i]!=LLONG_MAX)
            {
                dist[i]*=2;
            }
        }

        for(i=0;i<=n;i++)
            for(j=0;j<=d;j++)
                memo[i][j]=-1;

        long long ans=solve(1,d);
        printf("%lld\n",ans);
    }
    return 0;
}














