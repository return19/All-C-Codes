#include<bits/stdc++.h>
using namespace std;

class st
{
    long long s[401000];
    long long lazy[401000];
    long long f[401000];
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
        lazy[idx]=val;
        s[idx]=val;
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
        s[idx]=max(s[(idx<<1)+1],s[(idx<<1)+2]);
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

        s[idx]=max(s[(idx<<1)+1],s[(idx<<1)+2]);
    }

    long long query(long long idx,long long l,long long r,long long ql,long long qr)
    {
       // cout<<idx<<" "<<s[idx]<<endl;

        if(ql>r || qr<l)
            return LLONG_MIN;

        if(ql<=l&&r<=qr)
            return s[idx];

        shift(idx,l,r);

        long long mid=l +(r-l)/2;

        long long ans= max(query((idx<<1)+1,l,mid,ql,qr),query((idx<<1)+2,mid+1,r,ql,qr));
       // cout<<ql<<" "<<qr<<" "<<ans<<endl;
        return ans;
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
            f[i]=0;
        }
    }

    void setN(long long n)
    {
        (*this).n=n;

        for(long long i=0;i<=4*n;i++)
        {
            s[i]=0;
            lazy[i]=0;
            f[i]=0;
        }
    }

    void build(long long arr[])
    {
        build(0,0,n-1,arr);

       /* for(long long i=0;i<4*n;i++)
            cout<<s[i]<<" ";
        cout<<endl;*/
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

long long arr[101000];

st one(1);

int main()
{
    long long i,j,k;
    long long n;
    long long m;
    long long w,h;

    scanf("%lld",&n);

    for(i=0;i<n;i++)
        scanf("%lld",&arr[i]);

    one.setN(n);

    one.build(arr);

    scanf("%lld",&m);

    for(i=0;i<m;i++)
    {
        scanf("%lld%lld",&w,&h);

        w--;

        long long ans=one.query(0,w);

        one.increase(0,w,ans+h);

        printf("%lld\n",ans);
    }

    return 0;
}













