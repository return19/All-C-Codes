#include<bits/stdc++.h>
using namespace std;

#define mp make_pair

long long n;
long long arr[11];

pair<long long,long long> solve(long long idx)
{
    if(idx==0)
    {
        return mp(arr[idx],arr[idx]);
    }

    long long best,worst;

    pair<long long,long long> temp=solve(idx-1);
    long long nbest=temp.first;
    long long nworst=temp.second;

    if(arr[idx]>0)
    {
        best=max(max(nbest-arr[idx],nbest+arr[idx]),nbest*arr[idx]);
        worst=min(min(nworst-arr[idx],nworst-arr[idx]),nworst*arr[idx]);
    }else{
        best=max(max(nbest+arr[idx],nbest-arr[idx]),nworst*arr[idx]);
        worst=min(min(nworst+arr[idx],nworst-arr[idx]),nbest*arr[idx]);
    }

    return mp(best,worst);
}

int main()
{
    long long i,j,k;
    long long test,t;
    scanf("%lld",&test);

    for(t=0;t<test;t++)
    {
        scanf("%lld",&n);
        for(i=0;i<n;i++)
            scanf("%lld",&arr[i]);
        long long ans=solve(n-1).second;
        printf("%lld\n",ans);
    }

    return 0;
}



















