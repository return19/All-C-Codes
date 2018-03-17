#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ft first
#define sd second

vector< pair< pair<long long,long long>,long long > > v;
long long ans[1100];

int main()
{
    long long i,j,k;
    long long n;
    long long x,y,z;
    long long res;

    scanf("%lld",&n);

    while(n!=0)
    {
        v.resize(0);
        for(i=0;i<n;i++)
        {
            scanf("%lld%lld%lld",&x,&y,&z);
            v.push_back(mp(mp(x,y),z));
            v.push_back(mp(mp(y,z),x));
            v.push_back(mp(mp(z,x),y));
            v.push_back(mp(mp(y,x),z));
            v.push_back(mp(mp(z,y),x));
            v.push_back(mp(mp(x,z),y));
        }

        sort(v.begin(),v.end());
        for(i=0;i<100;i++)  ans[i]=0;
        res=0;
        for(i=0;i<v.size();i++)
        {
            ans[i]=v[i].sd;
            for(j=0;j<i;j++)
            {
                if(v[j].ft.ft<v[i].ft.ft && v[j].ft.sd<v[i].ft.sd)
                    ans[i]=max(ans[i],v[i].sd + ans[j]);
            }
            res=max(res,ans[i]);
        }
        printf("%lld\n",res);

        scanf("%lld",&n);
    }
    return 0;
}




















