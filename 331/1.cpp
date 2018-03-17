#include<bits/stdc++.h>
using namespace std;

vector< pair<long long,long long> > p;

long long dist(pair<long long,long long> x,pair<long long,long long> a)
{
    return (x.first-a.first)*(x.first-a.first) + (x.second-a.second)*(x.second-a.second);
}

int main()
{
    long long i,j,k,t,test;
    long long n;
    long long x,y;

    scanf("%lld",&n);

    for(i=0;i<n;i++)
    {
        scanf("%lld%lld",&x,&y);
        p.push_back(make_pair(x,y));
    }

    if(n==1)
        printf("-1\n");
    else if(n==2)
    {

        if(p[0].first==p[1].first || p[0].second==p[1].second)
        {
            printf("-1\n");
            return 0;
        }

        long long ans=dist(p[0],p[1]);
        printf("%lld\n",ans/2);
    }
    else if(n==3)
    {
        sort(p.begin(),p.end());

        long long ans;

        if(p[0].first == p[1].first)
        {
            if(p[0].second == p[2].second)
            {
                ans= sqrt(dist(p[0],p[1])) * sqrt(dist(p[0],p[2]));
            }
            else
            {
                ans= sqrt(dist(p[0],p[1])) * sqrt(dist(p[1],p[2]));
            }
        }
        else
        {
            if(p[0].second == p[1].second)
            {
                ans= sqrt(dist(p[1],p[2])) * sqrt(dist(p[0],p[1]));
            }
            else
            {
                ans= sqrt(dist(p[1],p[2])) * sqrt(dist(p[0],p[2]));
            }
        }

        printf("%lld\n",ans);
    }
    else
    {
        sort(p.begin(),p.end());

        long long ans;

        ans=sqrt(dist(p[0],p[1]));

        ans=ans* (sqrt( dist(p[0],p[2]) ));

        printf("%lld\n",ans);
    }

    return 0;
}














