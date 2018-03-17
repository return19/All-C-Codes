#include<bits/stdc++.h>
using namespace std;

long long sum[1010000];
long long a[101000];

vector< pair<long long,long long> > v;

long long ans[101000];

int main()
{
    long long i,j,k;
    long long x,y;
    long long n;
    long long mx=LLONG_MIN;

    scanf("%lld",&n);

    for(i=0;i<n;i++)
    {
        scanf("%lld%lld",&x,&y);
        mx=max(mx,x);
        sum[x]=1;
        v.push_back(make_pair(x,y));
    }
    sort(v.begin(),v.end());

    for(i=1;i<=mx;i++)
        sum[i]+=sum[i-1];

    for(i=0;i<n;i++)
        a[i]=v[i].first;

    for(i=1;i<n;i++)
    {
        long long ub=lower_bound(a,a+n,v[i].first-v[i].second)-a;
        ub--;
        //cout<<ub<<" ";
        long long im=0;

        if(ub>0)
        {
            im=ans[ub];
        }
        if(v[i].first-v[i].second-1>=0)
            ans[i]=im + sum[v[i].first-1]-sum[v[i].first-v[i].second-1];
        else
            ans[i]=im + sum[v[i].first-1];
    }
    /*cout<<endl;
    for(i=0;i<n;i++)
        cout<<ans[i]<<" ";
    cout<<endl;*/

    long long mn=LLONG_MAX;

    for(i=0;i<n;i++)
    {
        mn=min(mn,ans[i] + (n-i-1));
    }

    printf("%lld\n",mn);

    return 0;
}
















