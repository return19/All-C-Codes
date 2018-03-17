#include<bits/stdc++.h>
using namespace std;

long long n;
long long area[1001000];
long long ans[1010000];
map<long long,long long> memo;
map<long long,long long>::iterator it;

long double pi=3.141592653589793238;

void update(long long idx,long long l,long long r,long long x,long long val)
{
    if(l>r)
        return;
    if(x<l || r<x)
        return;

    if(l==r && l==x)
    {
        ans[idx]=val;
        return;
    }
    long long mid=l + (r-l)/2;

    update((idx<<1)+1,l,mid,x,val);
    update((idx<<1)+2,mid+1,r,x,val);

    ans[idx]= max( ans[(idx<<1) +1] , ans[(idx<<1)+2]);
}

long long query(long long idx,long long l,long long r,long long ql,long long qr)
{
    if(l>r)
        return 0;
    if(qr<l || r<ql)
        return 0;

    if(ql<=l && r<=qr)
        return ans[idx];
    long long mid=l + (r-l)/2;

    return max( query((idx<<1)+1,l,mid,ql,qr),query((idx<<1)+2,mid+1,r,ql,qr) );
}

int main()
{
    long long i,j,k;
    long long x,y,z;
    scanf("%lld",&n);

    for(i=0;i<n;i++)
    {
        scanf("%lld%lld",&x,&y);
        area[i]=x*x*y;
        memo[area[i]];
    }

    k=0;
    for(it=memo.begin();it!=memo.end();it++)
    {
        memo[it->first]=k++;
    }

    long long res=0;

    for(i=0;i<n;i++)
    {
        long long temp=query(0,0,n-1,0,memo[area[i]]-1);
        update(0,0,n-1,memo[area[i]],area[i] + temp);
        res=max(res,temp+area[i]);
    }

    long double res1=pi*res;
    cout<<setprecision(20)<<res1<<endl;
    return 0;
}


















