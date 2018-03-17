#include<bits/stdc++.h>
using namespace std;

long long n,t;
vector< pair<long long,long long> > v[6];
long long cnt[6];
int main()
{
    long long i,j,k;
    long long x,y,z;
    scanf("%lld%lld",&n,&t);

    for(i=0;i<n;i++)
    {
        scanf("%lld%lld%lld",&x,&y,&z);
        x--;
        if(x>=0 &&x<=5)
        {
            v[x].push_back(make_pair(y,z));
        }
    }

    for(i=0;i<6;i++)
        sort(v[i].begin(),v[i].end());

    long long ans=LLONG_MAX;
    long long cur_p=0;

    for(i=0;i<6;i++){
        cur_p+=v[i][0].first;
        ans=min(ans,v[i][0].second);
    }

    long long mn,mn_idx;
    for(;;)
    {
        mn=LLONG_MAX;
        for(i=0;i<6;i++)
        {
            if(cnt[i]==v[i].size())
                continue;
            if(mn>v[i][cnt[i]].second)
            {
                mn=v[i][cnt[i]].second;
                mn_idx=i;
            }
        }

        if(mn==LLONG_MAX)
            break;

        cur_p -= v[mn_idx][cnt[i]].first;
        cnt[i]++;
        cur_p += v[mn_idx][cnt[i]].first;

        if(cur_p>t)
            break;
        ans=v[mn_idx][cnt[i]].second;
    }

    printf("%lld\n",ans);
    return 0;
}
