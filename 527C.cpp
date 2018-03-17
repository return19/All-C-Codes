#include<bits/stdc++.h>
using namespace std;

set< pair<long long,long long> > hl,vl;
set< pair< long long,pair<long long,long long> > > hmx,vmx;

set< pair<long long,long long> >::iterator it;
set< pair< long long,pair<long long,long long> > >::reverse_iterator rit;

int main()
{
    long long i,j,k;
    long long w,h,n;
    char str[10];
    long long x;

    scanf("%lld%lld%lld",&w,&h,&n);

    hl.insert(make_pair(w,0));
    vl.insert(make_pair(h,0));

    hmx.insert(make_pair(w,make_pair(w,0)));
    vmx.insert(make_pair(h,make_pair(h,0)));

    for(i=0;i<n;i++)
    {
        scanf("%s",str);
        scanf("%lld",&x);

        if(str[0]=='H') // vertical change
        {
            it=vl.lower_bound(make_pair(x,LLONG_MIN));

           // cout<<"here : :"<<it->first<<" "<<it->second<<endl;

            vl.insert(make_pair(it->first,x));
            vl.insert(make_pair(x,it->second));

            vl.erase(*it);


            vmx.erase(make_pair(it->first - it->second,make_pair(it->first,it->second)));
            vmx.insert(make_pair(it->first - x,make_pair(it->first,x)));
            vmx.insert(make_pair(x - it->second,make_pair(x,it->second)));

           /* for(it=vl.begin();it!=vl.end();it++)
                cout<<it->first<<" "<<it->second<<endl;
            cout<<" ::::"<<endl;*/
        }
        else // horizontal change
        {
            it=hl.lower_bound(make_pair(x,LLONG_MAX));
             //cout<<"here : :"<<it->first<<" "<<it->second<<endl;

            hl.insert(make_pair(it->first,x));
            hl.insert(make_pair(x,it->second));

            hl.erase(*it);


            hmx.erase(make_pair(it->first - it->second,make_pair(it->first,it->second)));
            hmx.insert(make_pair(it->first - x,make_pair(it->first,x)));
            hmx.insert(make_pair(x - it->second,make_pair(x,it->second)));


            /* for(it=hl.begin();it!=hl.end();it++)
                cout<<it->first<<" "<<it->second<<endl;
            cout<<" ::::"<<endl;*/
        }

        long long ans=0;
        rit=hmx.rbegin();
        ans=rit->first;
        rit=vmx.rbegin();
        ans = ans*(rit->first);

        printf("%lld\n",ans);
    }

    return 0;
}
