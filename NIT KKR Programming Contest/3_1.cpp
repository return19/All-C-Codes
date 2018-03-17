#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ft first
#define sd second


long long arr[101000];

vector< pair< pair<long long,long long>,long long > > v;

long long ans[101000];

int main()
{
    long long i,j,k;
    long long test,t;
    long long n,q;
    long long m;
    long long x,y,z;

    scanf("%lld",&test);

    for(t=0;t<test;t++){
        scanf("%lld%lld",&n,&q);
        v.resize(0);
        memset(arr,0,sizeof(arr));
        memset(ans,0,sizeof(ans));

        for(i=0;i<q;i++){
            scanf("%lld%lld%lld",&x,&y,&z);
            x--;
            y--;
            v.push_back(mp(mp(x,y),z));
        }
        scanf("%lld",&m);

        for(i=0;i<m;i++)
        {
            scanf("%lld%lld",&x,&y);
            x--;
            y--;
            arr[x]++;
            arr[y+1] = arr[y+1] -1;
        }

        for(i=1;i<q;i++)
            arr[i] += arr[i-1];

        for(i=0;i<v.size();i++){
            x=v[i].ft.ft;
            y=v[i].ft.sd;
            z=v[i].sd;

            ans[x] = ans[x] + z*arr[i];
            ans[y+1] = ans[y+1] - z*arr[i];
        }

        for(i=1;i<n;i++)
            ans[i] += ans[i-1];

        for(i=0;i<n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }

    return 0;
}







