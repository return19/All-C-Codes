#include<bits/stdc++.h>
using namespace std;


/*
    Author : Abhinandan Sharma
    Handle: return_19
    date: 26/11/2015

    Segment Tree With Lazy Propagation
*/

#define MAX 9999999999999

class st1
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

    st1()
    {}

    st1(long long n)
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

class st
{
    long long s[401000];
    long long lazy[401000];
    long long f[401000];
    long long mn[401000];
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

        cout<<s[idx]<<" ::::: "<<val<<endl;

        s[idx]+=val;
        f[idx]=1;
    }

    void build(long long idx,long long l,long long r,long long arr[])
    {
        if(l>r)
            return;
        if(l==r)
        {
            s[idx]=arr[l];
            mn[idx]=l;
            return;
        }

        long long mid= l + (r-l)/2;

        build((idx<<1)+1,l,mid,arr);
        build((idx<<1)+2,mid+1,r,arr);
        s[idx]=min(s[(idx<<1)+1],s[(idx<<1)+2]);
    }

    void increase(long long idx,long long l,long long r,long long ql,long long qr,long long val,st1 &impact,long long arr[])
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

        increase((idx<<1)+1,l,mid,ql,qr,val,impact,arr);
        increase((idx<<1)+2,mid+1,r,ql,qr,val,impact,arr);

        //s[idx]=min(s[(idx<<1)+1],s[(idx<<1)+2]);
        pair<long long,long long> lf,rt,ans;
        lf=make_pair(s[(idx<<1)+1],mn[(idx<<1)+1]);
        rt=make_pair(s[(idx<<1)+2],mn[(idx<<1)+2]);

        if(lf.first<rt.first)
            ans= lf;
        else if(lf.first>rt.first)
            ans= rt;
        else
        {
            //cout<<"here"<<endl;
            long long li=0,ri=0;

            if(arr[lf.second]==0 && lf.second!=0)
                li=impact.query(0,lf.second-1);
            else if(arr[lf.second]==1 && lf.second != n-1)
                li=impact.query(lf.second+1,n-1);

            if(arr[rt.second]==0 && rt.second!=0)
                ri=impact.query(0,rt.second-1);
            else if(arr[rt.second]==1 && rt.second != n-1)
                ri=impact.query(rt.second+1,n-1);

           //  cout<<lf.second<<" "<<li<<" "<<rt.second<<" "<<ri<<endl;

            if(li>ri)
                ans= lf;
            else
                ans= rt;
        }

        s[idx]=ans.first;
        mn[idx]=ans.second;
    }

    pair<long long,long long> query(long long idx,long long l,long long r,long long ql,long long qr,st1 &impact,long long arr[])
    {
        if(ql>r || qr<l)
            return make_pair(MAX,3);

        if(ql<=l&&r<=qr)
        {
            return make_pair(s[idx],mn[idx]);
        }

        shift(idx,l,r);

        long long mid=l + (r-l)/2;

        pair<long long,long long> lf,rt;
        lf=query((idx<<1)+1,l,mid,ql,qr,impact,arr);
        rt=query((idx<<1)+2,mid+1,r,ql,qr,impact,arr);

        if(lf.first<rt.first)
            return lf;
        else if(lf.first>rt.first)
            return rt;
        else
        {
            //cout<<"here"<<endl;
            long long li=0,ri=0;

            if(arr[lf.second]==0 && lf.second!=0)
                li=impact.query(0,lf.second-1);
            else if(arr[lf.second]==1 && lf.second != n-1)
                li=impact.query(lf.second+1,n-1);

            if(arr[rt.second]==0 && rt.second!=0)
                ri=impact.query(0,rt.second-1);
            else if(arr[rt.second]==1 && rt.second != n-1)
                ri=impact.query(rt.second+1,n-1);

            //cout<<lf.second<<" "<<li<<" "<<rt.second<<" "<<ri<<endl;

            if(li>ri)
                return lf;
            return rt;
        }
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
            mn[i]=0;
        }
    }

    void build(long long arr[])
    {
        build(0,0,n-1,arr);
    }

    void increase(long long l,long long r,long long val,st1 &impact,long long arr[])
    {
        increase(0,0,n-1,l,r,val,impact,arr);
    }

    pair<long long,long long> query(long long l,long long r,st1 &impact,long long arr[])
    {
        return query(0,0,n-1,l,r,impact,arr);
    }


};

st1 impact(1);

long long arr[201000];
long long temp[201000];
long long n;
st one(1);

int main()
{
    long long i,j,k;

    scanf("%lld",&n);

    one.setN(n+10);
    impact.setN(n+10);
    one.build(temp);

    for(i=0;i<n;i++)
        temp[i]=1;
    impact.build(temp);

    for(i=0;i<n;i++)
    {
        scanf("%lld",&arr[i]);

        if(arr[i]==0)
        {
            if(i!=0)
                one.increase(0,i-1,1,impact,arr);
        }
        else
        {
            if(i!=n-1)
                one.increase(i+1,n-1,1,impact,arr);
        }
    }

    long long ans=0;

   /* for(i=0;i<n;i++)
        cout<<one.query(i,i,impact,arr).first<<" "<<one.query(i,i,impact,arr).second<<endl;
    cout<<endl;*/
    pair<long long,long long> p;

   /* p=one.query(0,n-1,impact,arr);
        cout<<p.first<<" "<<p.second<<endl;

    p=one.query(0,1,impact,arr);
        cout<<p.first<<" "<<p.second<<endl;

    p=one.query(2,3,impact,arr);
        cout<<p.first<<" "<<p.second<<endl;*/

    for(i=0;i<1;i++)
    {
        p=one.query(0,n-1,impact,arr);
        cout<<"here "<<p.first<<" "<<p.second<<endl;



        impact.increase(p.second,p.second,-1);

        ans += p.first;

        one.increase(p.second,p.second,MAX,impact,arr);
for(j=0;j<n;j++)
        cout<<one.query(j,j,impact,arr).first<<" "<<one.query(j,j,impact,arr).second<<endl;
    cout<<endl;
        if(arr[p.second]==0 && p.second !=0)
        {
            one.increase(0,p.second-1,-1,impact,arr);
        }
        else if(arr[p.second]==1 && p.second != n-1)
        {
            one.increase(p.second+1,n-1,-1,impact,arr);
        }
    }

    printf("%lld\n",ans);

    return 0;
}










