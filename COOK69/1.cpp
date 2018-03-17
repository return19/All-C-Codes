#include<bits/stdc++.h>
using namespace std;

vector< pair<pair<int,int>,int> > v;

int cmp(pair<pair<int,int>,int> a,pair<pair<int,int>,int> b)
{
    if(a.first.first==b.first.first)
    {
        if(a.first.second==b.first.second)
        {
            return a.second > b.second;
        }
        return a.first.second < b.first.second;
    }
    return a.first.first < b.first.first;
}

int main()
{
    int i,j,k;
    int test,t;
    int l,r;
    int n;
    scanf("%d",&test);

    for(t=0;t<test;t++)
    {
        scanf("%d",&n);
        v.resize(0);
        v.resize(n);

        for(i=0;i<n;i++)
        {
            scanf("%d",&l);
            v[i].first.first=l;
        }

        for(i=0;i<n;i++)
        {
            scanf("%d",&r);
            v[i].first.first *= r;
            v[i].first.second=r;
            v[i].second=i+1;
        }

        for(i=0;i<n;i++)
        {
            //cout<<v[i].first.first<<" "<<v[i].first.second<<endl;
        }

        sort(v.begin(),v.end(),cmp);

        printf("%d\n",v[n-1].second);
    }

    return 0;
}
