#include<bits/stdc++.h>
using namespace std;

long long n;
long long arr[101000];
/*long long memo[5010][5010];
long long solve(long long idx,long long k)
{
    long long i,j;
    if(idx==n-1){
        if(k==0)
            return 0;
        return long long_MAX;
    }

    if(k==0)
        return long long_MAX;

    if(memo[idx][k]!=-1)
        return memo[idx][k];

    long long ans=long long_MAX;

    for(i=idx+1;i<n;i++)
    {
        ans=min(ans,max(arr[i]-arr[idx],solve(i,k-1)));
    }
    return memo[idx][k]=ans;
}*/

vector< pair<long long,long long> > v;
long long mask[101000];
int main()
{
    long long i,j,k;
    long long test,t;

    scanf("%lld",&test);
    for(t=0;t<test;t++)
    {
        scanf("%lld%lld",&n,&k);
        for(i=0;i<n;i++){
            scanf("%lld",&arr[i]);
            mask[i]=0;
        }
        //sort(arr,arr+n);
        v.resize(0);
        for(i=1;i<n-1;i++)
        {
            v.push_back(make_pair(abs(arr[i]-arr[i-1]),i));
        }
        sort(v.begin(),v.end());

        for(i=0;i<n-1-k;i++)
            mask[v[i].second]=1;

        long long ans=LLONG_MIN;
        for(i=0;i<n-1;)
        {
            j=i+1;
            while(j<n && mask[j]==1)
                j++;
            ans=max(ans,arr[j]-arr[i]);
            i=j;
        }
        printf("%lld\n",ans);

    }

    return 0;
}
