#include<bits/stdc++.h>
using namespace std;

unsigned long long arr[501000];

set< pair<unsigned long long,unsigned long long> > fr;
set< pair<unsigned long long,unsigned long long> >::iterator it;
priority_queue< unsigned long long,vector<unsigned long long>,greater<unsigned long long> > sc;

int main()
{
    unsigned long long i,j,k;
    unsigned long long test,t;
    unsigned long long l,n,m,d;

    scanf("%llu",&test);

    for(t=0;t<test;t++)
    {
        scanf("%llu%llu%llu%llu",&l,&n,&m,&d);
        for(i=0;i<n;i++){
            scanf("%llu",&arr[i]);
            fr.insert(make_pair(arr[i],i));
        }
        unsigned long long ans=0;
        pair<unsigned long long,unsigned long long> mn;
        for(i=0;i<l;i++)
        {
            it=fr.begin();
            mn.first=it->first;
            mn.second=it->second;

            fr.erase(mn);

            fr.insert(make_pair(mn.first + arr[mn.second],mn.second));

            while( !sc.empty() && sc.top()<=mn.first)
                sc.pop();

            if(sc.size()<m)
                sc.push(mn.first+d);
            else
            {
                unsigned long long x=sc.top();
                sc.pop();
                sc.push(x+d);
            }
        }

        while(!sc.empty())
        {
            ans=max(ans,sc.top());
            sc.pop();
        }
        printf("Case #%llu: %llu\n",t+1,ans);
        fr.clear();
    }

    return 0;
}










