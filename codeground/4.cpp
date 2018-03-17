#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ft first
#define sd second

vector< pair<long long,long long> > graph[101000];
long long n;
long long vis[101000];

long long getSum(long long x,long long y,long long t){
    if(x==y){
        return 0;
    }

    vis[x]=1;

    long long tt=1;
    if(t==1)
        tt=-1;

    long long i,j,k;
    for(i=0;i<graph[x].size();i++){

        if(!vis[graph[x][i].ft]){
            long long temp = getSum(graph[x][i].ft,y,tt);
            if(temp!=-9999999999){
                if(t==1)
                    return temp + graph[x][i].sd;
                else
                    return temp - graph[x][i].sd;
            }
        }
    }
    return -9999999999;
}

int main()
{
    long long i,j,k;
    long long x,y,z;
    scanf("%lld",&n);
    for(i=0;i<n-1;i++){
        scanf("%lld%lld%lld",&x,&y,&z);
        x--;
        y--;
        graph[x].push_back(mp(y,z));
        graph[y].push_back(mp(x,z));
    }

    long long q;
    scanf("%lld",&q);

    for(i=0;i<q;i++){
        for(j=0;j<n;j++)
            vis[j]=0;
        scanf("%lld%lld",&x,&y);
        x--;    y--;
        printf("%lld\n",getSum(x,y,1));
    }

    return 0;
}













