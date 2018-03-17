#include<bits/stdc++.h>
using namespace std;
// C
long long x[2010];
long long y[2010];
long long r1[2010];
long long r2[2010];
long long one[2010];
long long two[2010];
long long n;


long long vis[2010];

long long f1,f2;
long long f11,f22;

long long dist(long long a,long long b,long long c,long long d)
{
    return (c-a)*(c-a) + (d-b)*(d-b);
}

long long cmp(long long a,long long b)
{
    return r1[a]<r1[b];
}

long long cmp1(long long a,long long b)
{
    return r2[a]<r2[b];
}

int main()
{
    long long i,j,k;

    scanf("%lld%lld%lld%lld%lld",&n,&f1,&f2,&f11,&f22);

    for(i=0;i<n;i++)
    {
        scanf("%lld%lld",&x[i],&y[i]);
        r1[i]=dist(f1,f2,x[i],y[i]);
        r2[i]=dist(f11,f22,x[i],y[i]);
        one[i]=i;
        two[i]=i;
    }

    /*for(i=0;i<n;i++)
        cout<<r1[i]<<" ";
    cout<<endl;
    for(i=0;i<n;i++)
        cout<<r2[i]<<" ";
    cout<<endl;*/

    sort(one,one+n,cmp);
    sort(two,two+n,cmp1);

    /* for(i=0;i<n;i++)
        cout<<one[i]<<" ";
    cout<<endl;
    for(i=0;i<n;i++)
        cout<<two[i]<<" ";
    cout<<endl;*/

    long long ans=LLONG_MAX;
    long long num=0;
    for(i=0;i<n;i++)
    {
        vis[one[i]]++;
        num=i+1;
        for(j=0;j<n;j++)
        {
            vis[two[j]]++;
            if(vis[two[j]]==1)
                num++;
            if(num==n){
               // cout<<r1[one[i]]<<" "<<r2[two[j]]<<endl;
                ans=min(ans,r1[one[i]] + r2[two[j]]);
            }
        }
        for(j=0;j<n;j++)
            vis[two[j]]--;
    }

    printf("%lld\n",min(ans,min(r1[one[n-1]],r2[two[n-1]])));

    return 0;
}












