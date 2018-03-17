#include<bits/stdc++.h>
using namespace std;

long long n,m;

vector< pair< pair<long long,long long>,long long> > e;

vector< pair< long long,pair<long long,long long> > > edges;

vector< pair<long long,long long> > pool;

int main()
{
    long long i,j,k;
    long long x,y,z;
    scanf("%lld%lld",&n,&m);
    k=m;
    for(j=2;j<n;j++)
    {
        for(i=0;i<=j-2;i++)
        {
            pool.push_back(make_pair(i,j));
            k--;
            if(k<=0)
                break;
        }
        if(k<=0)
            break;
    }
    for(i=0;i<m;i++)
    {
        scanf("%lld%lld",&x,&y);
        if(y==0)
            e.push_back(make_pair(make_pair(x,2),i));
        else
            e.push_back(make_pair(make_pair(x,1),i));
    }

    sort(e.begin(),e.end());
    long long cur=0;
    long long lim=0;

    k=0;

    for(i=0;i<e.size();i++)
    {
        x=e[i].first.first;
        y=e[i].first.second;
        z=e[i].second;

        if(y==1)
        {
            edges.push_back(make_pair(z,make_pair(cur,cur+1)));
            cur++;

            lim=lim+(cur-1);
        }
        else if(y==2)
        {
            if(lim==0)
            {
                printf("-1\n");
                return 0;
            }

            edges.push_back(make_pair(z,pool[k++]));
            lim--;
        }
    }

    sort(edges.begin(),edges.end());

    for(i=0;i<edges.size();i++)
        printf("%lld %lld\n",edges[i].second.first+1,edges[i].second.second+1);

    return 0;
}












