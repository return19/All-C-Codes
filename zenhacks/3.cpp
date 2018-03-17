#include<bits/stdc++.h>
using namespace std;

map< pair< pair<string,int>,string >,int > l;
map< pair< pair<string,int>,string >,int > r;

map< pair< pair<string,int>,string >,int >::iterator it;


int main()
{
    int n,i,j,k;

    scanf("%d",&n);

    string com;
    string col;
    int sz;
    string t;

    int ans=0;

    for(i=0;i<n;i++)
    {
        cin>>com;
        cin>>sz;
        cin>>col;
        cin>>t;

        if(t[0]=='L')
        {
            l[make_pair(make_pair(com,sz),col)]++;
        }
        else
        {
            r[make_pair(make_pair(com,sz),col)]++;
        }
    }

    for(it=l.begin();it!=l.end();it++)
    {
        ans += min(it->second,r[it->first]);
    }

    printf("%d\n",ans);

    return 0;
}
