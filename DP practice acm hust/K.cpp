#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ft first
#define sd second

long long n,t;

pair< pair<long long,long long>,long long > cost[61][1010]; // toll,time,n
queue< pair< pair<long long,long long>,long long > > q; // n,toll,time
long long memo[61][1010]; // memoize idx and time

pair<long long,long long> dijkstra()
{
    long long i,j,k;
    pair< pair<long long,long long>,long long > p;
    long long ans_time=LLONG_MAX;
    long long ans_toll=LLONG_MAX;

    for(i=0;i<=n;i++)
        for(j=0;j<1010;j++)
            memo[i][j]=LLONG_MAX;

    while(!q.empty())   q.pop();

    q.push(mp(mp(0,0),0));
    memo[0][0]=0;

    while(!q.empty())
    {
        p=q.front();
        q.pop();

        long long idx=p.ft.ft;
        long long toll=p.ft.sd;
        long long time=p.sd;

        for(i=0;i<n;i++)
        {
            long long x,y,z;
            y=time + cost[idx][i].ft.sd ;//time
            x=toll + cost[idx][i].ft.ft ;//toll
            z=cost[idx][i].sd;

            if(y>t)
                continue;

            if(memo[z][y] <= x)
                continue;
            memo[z][y]=x;

            if(z==n-1)
            {
                if(ans_toll>x)
                {
                    ans_time=y;
                    ans_toll=x;
                }else if(ans_toll==x)
                {
                    ans_time=min(ans_time,y);
                }
            }else{
                q.push(mp(mp(z,x),y));
            }
        }
    }

    return mp(ans_toll,ans_time);
}

int main()
{
    long long i,j,k;
    scanf("%lld%lld",&n,&t);

    while(n!=0 && t!=0)
    {
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                scanf("%lld",&cost[i][j].ft.sd);
        for(i=0;i<n;i++)
            for(j=0;j<n;j++){
                scanf("%lld",&cost[i][j].ft.ft);
                cost[i][j].sd=j;
            }

       // for(i=0;i<n;i++)
         //   sort(cost[i],cost[i]+n);

        pair<long long,long long> ans=dijkstra();
        printf("%lld %lld\n",ans.ft,ans.sd);

        scanf("%lld%lld",&n,&t);
    }
    return 0;
}













