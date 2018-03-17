#include<bits/stdc++.h>
using namespace std;

long long st[210];
long long ed[210];

long long a[210];

long long d;

long long req[210];

long long vis[210];

long long dist(long long x1,long long y1,long long x2,long long y2)
{
    return d*(abs(x1-x2) + abs(y1-y2));
}

long long max2(long long x,long long y)
{
    if(x>y)
        return x;
    return y;
}

int main()
{
    long long test,i,j,k,t;

    long long n;

    long long x,y;

    scanf("%lld",&test);

    for(t=0;t<test;t++)
    {
        scanf("%lld%lld",&n,&d);

        a[0]=0;

        for(i=1;i<n-1;i++)
        {
            scanf("%lld",&a[i]);
        }

        for(i=0;i<n;i++)
        {
            scanf("%lld%lld",&st[i],&ed[i]);
        }

        for(i=0;i<n;i++){
            req[i]=LLONG_MAX;
            vis[i]=0;
        }

        req[n-1]=0;

        long long mn=LLONG_MAX;
        long long mn_idx;

        for(i=0;i<n;i++)
        {
            mn=LLONG_MAX;

            for(j=0;j<n;j++)
            {
                if( !vis[j] && mn>req[j])
                {
                    mn=req[j];
                    mn_idx=j;
                }
            }


            vis[mn_idx]=1;

            for(j=0;j<n;j++)
            {
                if( !vis[j] && max2(dist(st[mn_idx],ed[mn_idx],st[j],ed[j]) - a[j],0) + req[mn_idx] < req[j])
                {
                    req[j] = max2(dist(st[mn_idx],ed[mn_idx],st[j],ed[j]) - a[j],0) + req[mn_idx];
                }
            }

            /*cout<<mn_idx<<endl;

            for(j=0;j<n;j++)
                cout<<req[j]<<" ";
            cout<<endl;*/
        }

        printf("%lld\n",req[0]);


    }

    return 0;
}
