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
    int s[401000];
    int lazy[401000];
    int f[401000];
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

st one(10);

int arr[10];

int main()
{
    int i,j,k;

    for(i=0;i<5;i++)
    {
        arr[i]=i;
    }

    one.build(arr);

    for(i=0;i<5;i++)
    {
        cout<<one.query(i,i)<<" ";
    }

    one.increase(1,3,2);
    one.increase(3,4,3);
    one.increase(0,3,1);
    one.increase(1,2,2);

    cout<<endl;

     for(i=0;i<5;i++)
    {
        cout<<one.query(i,i)<<" ";
    }

    return 0;
}
