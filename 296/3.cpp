#include<bits/stdc++.h>
using namespace std;

set< pair< long long,pair<long long,long long> > > h,v; // h for h cuts and v for v cuts
set< pair<long long,long long> > sh,sv;
set< pair<long long,long long> >::iterator it;
set< pair< long long,pair<long long,long long> > >::reverse_iterator rit1,rit2;

int main()
{
    long long i,j,k;
    long long w,he,q;
    long long st,ed;
    char t[10];
    long long x,y;
    scanf("%lld%lld%lld",&w,&he,&q);

    sh.insert(make_pair(0,he));
    sv.insert(make_pair(0,w));

    h.insert(make_pair(he,make_pair(0,he)));
    v.insert(make_pair(w,make_pair(0,w)));

    for(i=0;i<q;i++)
    {
        scanf("%s",t);
        scanf("%lld",&x);

        if(t[0]=='H')
        {
            it=sh.lower_bound(make_pair(x,LLONG_MAX));
            it--;
            st=it->first;
            ed=it->second;
            sh.erase(make_pair(st,ed));
            sh.insert(make_pair(st,x));
            sh.insert(make_pair(x,ed));

            h.erase(make_pair(ed-st,make_pair(st,ed)));
            h.insert(make_pair(x-st,make_pair(st,x)));
            h.insert(make_pair(ed-x,make_pair(x,ed)));
        }
        else
        {
            it=sv.lower_bound(make_pair(x,LLONG_MAX));
            it--;
            st=it->first;
            ed=it->second;
            sv.erase(make_pair(st,ed));
            sv.insert(make_pair(st,x));
            sv.insert(make_pair(x,ed));

            v.erase(make_pair(ed-st,make_pair(st,ed)));
            v.insert(make_pair(x-st,make_pair(st,x)));
            v.insert(make_pair(ed-x,make_pair(x,ed)));
        }

        rit1=h.rbegin();
        rit2=v.rbegin();

        long long ans=(rit1->first)*(rit2->first);
        printf("%lld\n",ans);

    }

    return 0;
}
















