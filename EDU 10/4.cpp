#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ft first
#define sd second

// just use functions defined as public

/*
    Author : Abhinandan Sharma
    Handle: return_19
    date: 26/11/2015

    Segment Tree With Lazy Propagation
*/

class st
{
    int s[801000];
    int lazy[801000];
    int f[801000];
    int n;

    void shift(int idx,int l,int r)
    {
        int mid=l + (r-l)/2;

        if(f[idx]==1){
            update((idx<<1)+1,l,mid,lazy[idx]);
            update((idx<<1)+2,mid+1,r,lazy[idx]);
        }
        lazy[idx]=0;
        f[idx]=0;
    }

    void update(int idx,int l,int r,int val)
    {
        lazy[idx]+=val;
        s[idx]+=(r-l+1)*val;
        f[idx]=1;
    }

    void build(int idx,int l,int r,int arr[])
    {
        if(l>r)
            return;
        if(l==r)
        {
            s[idx]=arr[l];
            return;
        }

        int mid= l + (r-l)/2;

        build((idx<<1)+1,l,mid,arr);
        build((idx<<1)+2,mid+1,r,arr);
        s[idx]=s[(idx<<1)+1] + s[(idx<<1)+2];
    }

    void increase(int idx,int l,int r,int ql,int qr,int val)
    {
        if(ql>r || qr<l)
            return;

        if(ql<=l&&r<=qr)
        {
            update(idx,l,r,val);
            return;
        }

        shift(idx,l,r);

        int mid=l + (r-l)/2;

        increase((idx<<1)+1,l,mid,ql,qr,val);
        increase((idx<<1)+2,mid+1,r,ql,qr,val);

        s[idx]=s[(idx<<1)+1] + s[(idx<<1)+2];
    }

    int query(int idx,int l,int r,int ql,int qr)
    {
        if(ql>r || qr<l)
            return 0;

        if(ql<=l&&r<=qr)
        {
            return s[idx];
        }

        shift(idx,l,r);

        int mid=l + (r-l)/2;

        return query((idx<<1)+1,l,mid,ql,qr) + query((idx<<1)+2,mid+1,r,ql,qr);
    }

public:

    st()
    {}

    st(int n)
    {
        int i;
        (*this).n=n;

        for(i=0;i<=n*4;i++)
        {
            s[i]=0;
            lazy[i]=0;
            f[i]=0;
        }
    }

    void setN(int n)
    {
        (*this).n=n;

        for(int i=0;i<=4*n;i++)
        {
            s[i]=0;
            lazy[i]=0;
            f[i]=0;
        }
    }

    void build(int arr[])
    {
        build(0,0,n-1,arr);
    }

    void increase(int l,int r,int val)
    {
        increase(0,0,n-1,l,r,val);
    }

    int query(int l,int r)
    {
        return query(0,0,n-1,l,r);
    }


};

st one(200010);
int ans[201000];
vector< pair< pair<int,int>,int> > r; // r,l,act idx
vector< pair < pair<int,int>,pair<int,int> > > l;// l,r,sort idx,act_idx
map<int,int> memo;
map<int,int>::iterator it;
vector< pair<int,int> > v;

int main()
{
    int i,j,k;
    int x,y,z;
    int n;
    scanf("%d",&n);

    one.setN(n+10);

    for(i=0;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        v.push_back(mp(x,y));
        memo[x];
        memo[y];
    }

    k=0;
    for(it=memo.begin();it!=memo.end();it++)
    {
        memo[it->first]=k++;
    }

    for(i=0;i<n;i++)
    {
        x=memo[v[i].ft];
        y=memo[v[i].sd];
        r.push_back(mp(mp(y,x),i));
        l.push_back(mp(mp(x,y),mp(0,i)));
    }

    sort(l.begin(),l.end());
    sort(r.begin(),r.end());

    for(i=0;i<n;i++)
    {
        l[i].sd.ft=i;
    }

    for(i=0;i<n;i++)
    {
        x=r[i].ft.sd;
        y=r[i].ft.ft;
        z=r[i].sd;
        int act;

        int bs=lower_bound(l.begin(),l.end(),mp(mp(x,0),mp(0,0))) - l.begin();
        act=l[bs].sd.ft;
        if(bs!=0)
        {
            one.increase(0,l[bs-1].sd.ft,1);
        }
        ans[z]=one.query(act,act);
    }

    for(i=0;i<n;i++)
        printf("%d\n",ans[i]);

    return 0;
}

















