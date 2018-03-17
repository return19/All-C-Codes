#include<bits/stdc++.h>
using namespace std;

#define ft first
#define sd second
#define pii pair<long long,long long>
#define mp make_pair

long long MIN = -999999999999999;

long long n;
long long arr[101000];
pair< pii,pii > s[500100]; // ans,sum,l,r

pair< pii,pii > mnode(pair< pii,pii > x,pair< pii,pii > y)
{
    pair< pii,pii > n;
    n.ft.sd=x.ft.sd + y.ft.sd;
    n.sd.ft=max(x.sd.ft,x.ft.sd + y.sd.ft);
    n.sd.sd=max(y.sd.sd,y.ft.sd + x.sd.sd);
    n.ft.ft=max(x.sd.sd + y.sd.ft,max(x.ft.ft,y.ft.ft));
    return n;
}

void build(long long idx,long long l,long long r)
{
    if(l>r)
        return;
    if(l==r)
    {
        s[idx].ft.ft=arr[l];
        s[idx].ft.sd=arr[l];
        s[idx].sd.ft=arr[l];
        s[idx].sd.sd=arr[l];
        return;
    }

    long long mid=l + (r-l)/2;

    build((idx<<1)+1,l,mid);
    build((idx<<1)+2,mid+1,r);
    s[idx]=mnode(s[(idx<<1)+1],s[(idx<<1)+2]);
}

pair< pii,pii > query(long long idx,long long l,long long r,long long ql,long long qr)
{
    if(l>r)
        return mp(mp(MIN,0),mp(MIN,MIN));
    if(r<ql || l>qr)
        return mp(mp(MIN,0),mp(MIN,MIN));
    if(ql<=l && r<=qr)
        return s[idx];
    long long mid = l + (r-l)/2;

    return mnode( query( (idx<<1)+1,l,mid,ql,qr ),query( (idx<<1)+2,mid+1,r,ql,qr ) );
}

void update(long long idx,long long l,long long r,long long x,long long val)
{
    if(l>r)
        return;
    if(x<l || x>r)
        return;
    if(l==r && l==x)
    {
        s[idx]=mp(mp(val,val),mp(val,val));
        return;
    }
    long long mid=l + (r-l)/2;
    update( (idx<<1) +1,l,mid,x,val);
    update( (idx<<1) +2,mid+1,r,x,val);

    s[idx]=mnode(s[(idx<<1) +1],s[(idx<<1)+2]);
}

int main()
{
    long long i,j,k;
    long long q;
    long long x,y,z;

    scanf("%lld",&n);

    for(i=0;i<n;i++)
    {
        scanf("%lld",&arr[i]);
    }

    build(0,0,n-1);

    scanf("%lld",&q);
    long long t;

    for(i=0;i<q;i++)
    {
        scanf("%lld",&t);
        scanf("%lld%lld",&x,&y);

        if(t==0)
        {
            x--;
            update(0,0,n-1,x,y);
        }
        else
        {
            pair< pii,pii > ans;
            x--;    y--;
            ans=query(0,0,n-1,x,y);
            printf("%lld\n",ans.ft.ft);
        }
    }

    return 0;
}
















