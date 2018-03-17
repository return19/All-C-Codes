#include<bits/stdc++.h>
using namespace std;

set< pair<int,int> > s;

vector< pair<int,int> > v,ans;
map<int,int> memo;

set< pair<int,int> >::iterator it,it1;
int n;

int w[101000];
map<int,int> wmap;

map< int,vector< pair<int,int> > > adj;
map< int,vector< pair<int,int> > >::iterator mit;

int main()
{
    int i,j,k;
    int x,y;

    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        s.insert(make_pair(x,y));
        v.push_back(make_pair(x,y));
    }

    for(i=0;i<n;i++){
        scanf("%d",&w[i]);
    }

    pair<int,int> p;

    int mn_y;
    int cur=0;
    iny k=0;

    for(i=0;i<n;i++)
    {
        it=s.begin();
        p = *it;
        mn_y=p.second;

        memo[p.first-p.second]++;
        it++;

        while(it->second < mn_y)
        {
            mn_y=min(mn_y,it->second);
            cur++;
            memo[it->first - it->second]++;
        }

        for(j=k;j<=cur;j++)
        {
            wmap[w[j]]++;
        }

        for(;k<=cur;k++)
        {
            if(wmap[ v[k].first - v[k].second ]<1)
            {
                printf("NO");
                return 0;
            }

            wmap[ v[k].first - v[k].second ]--;

            adj[v[k].first - v[k].second].push_back(v[k]);
        }
    }



    return 0;
}







