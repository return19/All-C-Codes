#include<bits/stdc++.h>
using namespace std;

set< pair< pair<long long,long long>,long long > > s; // adj nodes, xor , node
set< pair< pair<long long,long long>,long long > >::iterator it;

long long adj[101000];
long long xora[101000];

vector< pair<long long,long long> > ans;

int main()
{
    long long n,i,j,k;
    long long x,y,z;
    long long p,q,r;
    long long m=0;

    scanf("%lld",&n);

    //printf("%lld\n",n-1);

    for(i=0;i<n;i++)
    {
        scanf("%lld%lld",&x,&y);

        adj[i]=x;
        xora[i]=y;

        if(x==0)
        {
            continue;
        }

        s.insert(make_pair(make_pair(x,y),i));
    }

   // printf("%lld\n",m);

    for(i=0;s.size()>0;i++)
    {
        it=s.begin();
        x=it->first.first;
        y=it->first.second;
        z=it->second;

        s.erase(make_pair(make_pair(x,y),z));

        //printf("%lld %lld\n",z,y);

        m++;
        ans.push_back(make_pair(z,y));

        s.erase(make_pair(make_pair(adj[y],xora[y]),y));
        adj[y]--;
        xora[y] ^=z;
        if(adj[y]!=0)
            s.insert(make_pair(make_pair(adj[y],xora[y]),y));
    }

    printf("%lld\n",m);

    for(i=0;i<ans.size();i++)
        printf("%lld %lld\n",ans[i].first,ans[i].second);

    return 0;
}









