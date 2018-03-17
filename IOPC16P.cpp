#include<bits/stdc++.h>
using namespace std;

#define ft first
#define sd second
#define pii pair<long long,long long>
#define mp make_pair
#define MIN -99999999999999999
long long n;
long long arr[501000];

vector< pair<long long,long long> > v;

vector< pair< pii,pii > > queries;
long long ans[501000];
pair< pii,pair< pii,long long > > s[1010000]; // ans,sum,l,r,x or not

pair< pii,pair< pii,long long > > mnode(pair< pii,pair< pii,long long > > x,pair< pii,pair< pii,long long > > y)
{
    pair< pii,pair< pii,long long > > n;

    if(x.sd.sd==1)
    {
        n.sd.ft.ft=x.sd.ft.ft;
    }else{
        n.sd.ft.ft=max(x.sd.ft.ft,x.ft.sd + y.sd.ft.ft);
    }

    if(y.sd.sd==1)
    {
        n.sd.ft.sd=y.sd.ft.sd;
    }else{
        n.sd.ft.sd=max(y.sd.ft.sd,y.ft.sd + x.sd.ft.sd);
    }
    n.ft.ft=max(x.sd.ft.sd + y.sd.ft.ft,max(x.ft.ft,y.ft.ft));
    n.ft.sd=x.ft.sd + y.ft.sd;
    n.sd.sd=(x.sd.sd|y.sd.sd);

    if(x.ft.ft ==MIN && y.ft.ft==MIN)
        n.ft.ft=MIN;
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
        s[idx].sd.ft.ft=arr[l];
        s[idx].sd.ft.sd=arr[l];
        s[idx].sd.sd=0;
        return;
    }
    long long mid=l + (r-l)/2;
    build((idx<<1)+1,l,mid);
    build((idx<<1)+2,mid+1,r);

    s[idx]=mnode(s[(idx<<1)+1],s[(idx<<1)+2]);
}

pair< pii,pair< pii,long long > > query(long long idx,long long l,long long r,long long ql,long long qr)
{
    if(l>r)
        return mp(mp(MIN,0),mp(mp(MIN,MIN),0));
    if(qr<l || r<ql)
        return mp(mp(MIN,0),mp(mp(MIN,MIN),0));
    if(ql<=l && r<=qr)
        return s[idx];
    long long mid= l + (r-l)/2;

    return mnode( query((idx<<1)+1,l,mid,ql,qr),query((idx<<1)+2,mid+1,r,ql,qr) );
}

void update(long long idx,long long l,long long r,long long x)
{
    if(l>r)
        return;
    if(x<l || r<x)
        return;
    if(l==r && l==x)
    {
        s[idx].sd.sd=1;
        s[idx].ft.ft=MIN;
        s[idx].sd.ft.ft=MIN;
        s[idx].sd.ft.sd=MIN;
        return;
    }
    long long mid=l + (r-l)/2;
    update((idx<<1)+1,l,mid,x);
    update((idx<<1)+2,mid+1,r,x);

    s[idx]=mnode(s[(idx<<1)+1],s[(idx<<1)+2]);
}

int main()
{
    long long i,j,k;
    long long q;
    long long x,y,z;
    scanf("%lld%lld",&n,&q);

    for(i=0;i<n;i++){
        scanf("%lld",&arr[i]);
        v.push_back(mp(arr[i],i));
    }

    build(0,0,n-1);

  /*  for(i=0;i<n;i++)
        cout<<query(0,0,n-1,i,i).ft.ft<<" ";
    cout<<endl;*/

    for(i=0;i<q;i++)
    {
        scanf("%lld%lld%lld",&x,&y,&z);
        queries.push_back(mp(mp(z,x),mp(y,i)));
    }

    sort(v.begin(),v.end());
    sort(queries.begin(),queries.end());

    j=n-1;

    for(i=queries.size()-1;i>=0;i--)
    {
        z=queries[i].ft.ft;
        x=queries[i].ft.sd;
        y=queries[i].sd.ft;

        while(j>=0 && v[j].ft > z)
        {
            update(0,0,n-1,v[j].sd);
            j--;
        }
        //cout<<x<<" "<<y<<" "<<z<<" ";
        x--;    y--;
        ans[queries[i].sd.sd]=query(0,0,n-1,x,y).ft.ft;
       // cout<<ans[queries[i].sd.sd]<<endl;
    }

    for(i=0;i<q;i++){
        if(ans[i]==MIN)
            printf("xx\n");
        else
            printf("%lld\n",ans[i]);
    }

    return 0;
}

















