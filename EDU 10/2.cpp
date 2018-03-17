#include<bits/stdc++.h>
using namespace std;
//3
long long n,m;
long long arr[501000];

vector< pair< pair<long long,long long>,long long> > v;
vector< pair<long long,long long> > wind;
vector<long long> ans;
map<long long,long long> l;
map<long long,long long> r;

map< pair<long long,long long>,long long > p;

int main()
{
    long long i,j,k;
    long long x,y,z;
    scanf("%lld%lld",&n,&m);

    for(i=0;i<n;i++)
    {
        scanf("%lld",&arr[i]);
        l[arr[i]]=min(l[arr[i]],i);
        r[arr[i]]=max(r[arr[i]],i);
    }

    for(i=0;i<m;i++)
    {
        scanf("%lld%lld",&x,&y);
        wind.push_back(make_pair(x,y));

        if(p.find(make_pair(x,y))==p.end() ||p.find(make_pair(y,x))==p.end())
            p[make_pair(x,y)]=1;
        else
            continue;

        if(l.find(x)==l.end() || l.find(y)==l.end())
            continue;

        v.push_back(make_pair(make_pair(l[x],i),0));
        v.push_back(make_pair(make_pair(r[y],i),1));
    }

    sort(v.begin(),v.end());

    long long st=-1;
    for(i=0;i<v.size();i++)
    {
        if(v[i].second==0)
        {
            st=v[i].first.second;
        }else{
            if(v[i].first.second == st)
                ans.push_back(v[i].first.second);
        }
    }

    long long res=0;

    for(i=0;i<ans.size();i++)
    {
        x=wind[ans[i]].first;
        y=wind[ans[i]].second;
        z=y-x-1;
        res += (z*(z+1)/2);
        res += 2*(y-x);
    }

    printf("%lld\n",res);


    return 0;
}












