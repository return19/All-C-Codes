#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ft first
#define sd second


/*
    Author : Abhinandan Sharma
    Handle: return_19
    date: 26/11/2015

    Segment Tree With Lazy Propagation
*/

class st
{
    long long s[501000];
    long long lazy[501000];
    long long f[501000];
    long long n;

    void shift(long long idx,long long l,long long r)
    {
        long long mid=l + (r-l)/2;

        if(f[idx]==1){
            update((idx<<1)+1,l,mid,lazy[idx]);
            update((idx<<1)+2,mid+1,r,lazy[idx]);
        }
        lazy[idx]=0;
        f[idx]=0;
    }

    void update(long long idx,long long l,long long r,long long val)
    {
        lazy[idx]+=val;
        s[idx]+=(r-l+1)*val;
        f[idx]=1;
    }

    void build(long long idx,long long l,long long r,long long arr[])
    {
        if(l>r)
            return;
        if(l==r)
        {
            s[idx]=arr[l];
            return;
        }

        long long mid= l + (r-l)/2;

        build((idx<<1)+1,l,mid,arr);
        build((idx<<1)+2,mid+1,r,arr);
        s[idx]=s[(idx<<1)+1] + s[(idx<<1)+2];
    }

    void increase(long long idx,long long l,long long r,long long ql,long long qr,long long val)
    {
        if(ql>r || qr<l)
            return;

        if(ql<=l&&r<=qr)
        {
            update(idx,l,r,val);
            return;
        }

        shift(idx,l,r);

        long long mid=l + (r-l)/2;

        increase((idx<<1)+1,l,mid,ql,qr,val);
        increase((idx<<1)+2,mid+1,r,ql,qr,val);

        s[idx]=s[(idx<<1)+1] + s[(idx<<1)+2];
    }

    long long query(long long idx,long long l,long long r,long long ql,long long qr)
    {
        if(ql>r || qr<l)
            return 0;

        if(ql<=l&&r<=qr)
        {
            return s[idx];
        }

        shift(idx,l,r);

        long long mid=l + (r-l)/2;

        return query((idx<<1)+1,l,mid,ql,qr) + query((idx<<1)+2,mid+1,r,ql,qr);
    }

public:

    st()
    {}

    st(long long n)
    {
        long long i;
        (*this).n=n;

        for(i=0;i<=n*5;i++)
        {
            s[i]=0;
            lazy[i]=0;
            f[i]=0;
        }
    }

    void setN(long long n)
    {
        (*this).n=n;

        for(long long i=0;i<=5*n;i++)
        {
            s[i]=0;
            lazy[i]=0;
            f[i]=0;
        }
    }

    void build(long long arr[])
    {
        build(0,0,n-1,arr);
    }

    void increase(long long l,long long r,long long val)
    {
        increase(0,0,n-1,l,r,val);
    }

    long long query(long long l,long long r)
    {
        return query(0,0,n-1,l,r);
    }


};

vector< pair< pair<long long,long long>,long long > > v;

st one(1),two(1);

long long arr[101000];


long long n;


int main()
{
    long long i,j,k;
    long long test,t;
    long long m;
    long long q;
    long long x,y,z;

    scanf("%lld",&test);

    for(t=0;t<test;t++){
            v.resize(0);
        scanf("%lld%lld",&n,&q);

        for(i=0;i<q;i++){
            scanf("%lld%lld%lld",&x,&y,&z);

            x--;    y--;
            v.push_back(mp(mp(x,y),z));
        }
        scanf("%lld",&m);

        one.setN(n+100);

        for(i=0;i<m;i++){
            scanf("%lld%lld",&x,&y);
            x--;    y--;

            one.increase(x,y,1);
        }

     //  for(i=0;i<n;i++)
       // cout<<one.query(i,i)<<endl;


        two.setN(n+100);

        for(i=0;i<q;i++){
            long long mul=one.query(i,i);
            two.increase(v[i].ft.ft,v[i].ft.sd,mul*v[i].sd);
        }

        for(i=0;i<n;i++){
            printf("%lld ",two.query(i,i));
        }
        printf("\n");
    }
    return 0;
}









