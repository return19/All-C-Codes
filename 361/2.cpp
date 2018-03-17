#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ft first
#define sd second

long long arr[501000];
long long dist[501000];
set< pair<long long,long long> > s;

int main()
{
    long long i,j,k;
    long long n;
    scanf("%lld",&n);

    for(i=0;i<n;i++){
        scanf("%lld",&arr[i]);
        arr[i]--;
    }

    for(i=0;i<n;i++)
        s.insert(mp(i,i));
    dist[0]=0;
    for(i=1;i<n;i++)
        dist[i]=i;

    while(!s.empty()){
        pair<long long,long long> p = *(s.begin());
        s.erase(p);
        long long x=p.sd;

        if(dist[arr[x]] > dist[x]+1){
            s.erase(mp(dist[arr[x]],arr[x]));
            dist[arr[x]]=dist[x]+1;
            s.insert(mp(dist[arr[x]],arr[x]));
        }

        if(x+1<n && dist[x+1] > dist[x]+1){
            s.erase(mp(dist[x+1],x+1));
            dist[x+1]=dist[x]+1;
            s.insert(mp(dist[x+1],x+1));
        }

        if(x-1>=0 && dist[x-1] > dist[x]+1){
            s.erase(mp(dist[x-1],x-1));
            dist[x-1]=dist[x]+1;
            s.insert(mp(dist[x-1],x-1));
        }
    }

    for(i=0;i<n;i++)
        printf("%lld ",dist[i]);

    return 0;
}
















