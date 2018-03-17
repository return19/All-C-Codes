#include<bits/stdc++.h>
using namespace std;

set< pair<int,int> > hl,vl;
set< pair<int,int> >::iterator it;

set< pair< int, pair<int,int> > > hmx,vmx;
set< pair< int, pair<int,int> > >::reverse_iterator it1;
int main()
{
    int i,j,k;
    int w,h,n;
    char str[10];
    int x,y,z;

    scanf("%d%d%d",&w,&h,&n);

    hl.insert(make_pair(w,0));
    vl.insert(make_pair(h,0));

    hmx.insert(make_pair(w,make_pair(w,0)));
    vmx.insert(make_pair(h,make_pair(h,0)));

    for(i=0;i<n;i++)
    {
        scanf("%s",str);
        scanf("%d",&x);

        if(str[0]=='V')
        {
            it=hl.lower_bound(make_pair(x,INT_MAX));

            cout<< it->first <<" "<< it->second <<endl;

            hl.erase(*it);
            hmx.erase(make_pair(it->first-it->second,make_pair(it->first,it->second)));

            hmx.insert(make_pair(it->first-x,make_pair(it->first,x)));
            hmx.insert(make_pair(x-it->second,make_pair(x,it->second)));
            hl.insert(make_pair(it->first,x));
            hl.insert(make_pair(x,it->second));
        }
        else
        {
            it=vl.lower_bound(make_pair(x,INT_MIN));

            cout<< it->first <<" "<< it->second <<endl;

            vl.erase(*it);
            vmx.erase(make_pair(it->first-it->second,make_pair(it->first,it->second)));

            vmx.insert(make_pair(it->first-x,make_pair(it->first,x)));
            vmx.insert(make_pair(x-it->second,make_pair(x,it->second)));

            vl.insert(make_pair(it->first,x));
            vl.insert(make_pair(x,it->second));
        }

        it1=hmx.rbegin();

        int ans=it1->first;
        cout<<it1->first<<" : ";
        it1=vmx.rbegin();
        cout<<it1->first<<endl;
        ans *= (it1->first);
        printf("%d\n",ans);
    }

    return 0;
}
