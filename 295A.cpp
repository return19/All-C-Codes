#include<bits/stdc++.h>
using namespace std;

// working perfectly
// just use functions defined as public

/*
    Author : Abhinandan Sharma
    Handle: return_19
    date: 26/11/2015

    Segment Tree With Lazy Propagation
*/

class st
{
    long long s[401000];
    long long lazy[401000];
    long long n;

    void shift(long long idx,long long l,long long r)
    {
        long long mid=l + (r-l)/2;
        update((idx<<1)+1,l,mid,lazy[idx]);
        update((idx<<1)+2,mid+1,r,lazy[idx]);

        lazy[idx]=0;
    }

    void update(long long idx,long long l,long long r,long long val)
    {
        lazy[idx]+=val;
        s[idx]+=(r-l+1)*val;
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

        for(i=0;i<=n*4;i++)
        {
            s[i]=0;
            lazy[i]=0;
        }
    }

    void setN(long long n)
    {
        (*this).n=n;

        for(long long i=0;i<=4*n;i++)
        {
            s[i]=0;
            lazy[i]=0;
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

st one(1);
st two(1);

long long arr[100100];

long long qrs[100100][3];

int main()
{
    long long i,j,k;
    long long n,m,q;

    scanf("%lld%lld%lld",&n,&m,&q);

    for(i=0;i<n;i++)
        scanf("%lld",&arr[i]);


    one.setN(n);
    one.build(arr);

    /*for(i=0;i<n;i++)
        cout<<one.query(i,i)<<" ";
    cout<<endl;*/

    long long x,y,z;

    for(i=0;i<m;i++)
    {
        scanf("%lld%lld%lld",&qrs[i][0],&qrs[i][1],&qrs[i][2]);

        qrs[i][0]--;
        qrs[i][1]--;
    }

    two.setN(m+5);

    for(i=0;i<q;i++)
    {
        scanf("%lld%lld",&x,&y);
        x--;
        y--;

        two.increase(x,y,1);
    }

    for(i=0;i<m;i++)
    {
        one.increase(qrs[i][0],qrs[i][1],qrs[i][2]*two.query(i,i));
    }

    for(i=0;i<n;i++)
    {
        printf("%lld ",one.query(i,i));
    }

    return 0;
}







