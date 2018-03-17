#include<bits/stdc++.h>
using namespace std;
#define MAX 9999999
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


class st1
{
    int s[401000];
    int lazy[401000];
    int f[401000];
    int mn[401000];
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
        s[idx]+=val;
        f[idx]=1;
    }

    void build(int idx,int l,int r,int arr[],st &impact)
    {
        if(l>r)
            return;
        if(l==r)
        {
            s[idx]=arr[l];
            mn[idx]=l;
            return;
        }

        int mid= l + (r-l)/2;

        build((idx<<1)+1,l,mid,arr,impact);
        build((idx<<1)+2,mid+1,r,arr,impact);

        if(s[(idx<<1)+1]<s[(idx<<1)+2])
        {
            s[idx]=s[(idx<<1)+1];
            mn[idx]=mn[(idx<<1)+1];
        }
        else if(s[(idx<<1)+1]>s[(idx<<1)+2])
        {
            s[idx]=s[(idx<<1)+2];
            mn[idx]=mn[(idx<<1)+2];
        }
        else
        {
            int lf=(idx<<1)+1;
            int rt=(idx<<1)+2;
            int li=0,ri=0;

            if(arr[mn[lf]]==0)
            {
                if(mn[lf]!=0)
                    li=impact.query(0,mn[lf]-1);
            }
            else
            {
                if(mn[lf]!=n-1)
                    li=impact.query(mn[lf]+1,n-1);
            }

            if(arr[mn[rt]]==0)
            {
                if(mn[rt]!=0)
                    ri=impact.query(0,mn[rt]-1);
            }
            else
            {
                if(mn[rt]!=n-1)
                    ri=impact.query(mn[rt]+1,n-1);
            }

            if(li>ri)
            {
                s[idx]=s[lf];
                mn[idx]=mn[lf];
            }
            else
            {
                s[idx]=s[rt];
                mn[idx]=mn[rt];
            }
        }
    }

    void increase(int idx,int l,int r,int ql,int qr,int val,st &impact,int arr[])
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

        increase((idx<<1)+1,l,mid,ql,qr,val,impact,arr);
        increase((idx<<1)+2,mid+1,r,ql,qr,val,impact,arr);

        if(s[(idx<<1)+1]<s[(idx<<1)+2])
        {
            s[idx]=s[(idx<<1)+1];
            mn[idx]=mn[(idx<<1)+1];
        }
        else if(s[(idx<<1)+1]>s[(idx<<1)+2])
        {
            s[idx]=s[(idx<<1)+2];
            mn[idx]=mn[(idx<<1)+2];
        }
        else
        {
            int lf=(idx<<1)+1;
            int rt=(idx<<1)+2;
            int li=0,ri=0;

            if(arr[mn[lf]]==0)
            {
                if(mn[lf]!=0)
                    li=impact.query(0,mn[lf]-1);
            }
            else
            {
                if(mn[lf]!=n-1)
                    li=impact.query(mn[lf]+1,n-1);
            }

            if(arr[mn[rt]]==0)
            {
                if(mn[rt]!=0)
                    ri=impact.query(0,mn[rt]-1);
            }
            else
            {
                if(mn[rt]!=n-1)
                    ri=impact.query(mn[rt]+1,n-1);
            }

            if(li>ri)
            {
                s[idx]=s[lf];
                mn[idx]=mn[lf];
            }
            else
            {
                s[idx]=s[rt];
                mn[idx]=mn[rt];
            }
        }
    }

    pair<int,int> query(int idx,int l,int r,int ql,int qr,st &impact,int arr[])
    {
        if(ql>r || qr<l)
            return make_pair(MAX,-1);

        if(ql<=l&&r<=qr)
        {
            return make_pair(s[idx],mn[idx]);
        }

        shift(idx,l,r);

        int mid=l + (r-l)/2;

        pair<int,int> lf=query((idx<<1)+1,l,mid,ql,qr,impact,arr);
        pair<int,int> rt=query((idx<<1)+2,mid+1,r,ql,qr,impact,arr);

        if(lf.first<rt.first)
            return lf;
        else if(lf.first>rt.first)
            return rt;
        else
        {
            int li=0,ri=0;

            if(arr[lf.second]==0)
            {
                if(lf.second!=0)
                    li=impact.query(0,lf.second-1);
            }
            else
            {
                if(lf.second!=n-1)
                    li=impact.query(lf.second+1,n-1);
            }

            if(arr[rt.second]==0)
            {
                if(rt.second!=0)
                    ri=impact.query(0,rt.second-1);
            }
            else
            {
                if(rt.second!=n-1)
                    ri=impact.query(rt.second+1,n-1);
            }

            if(li>ri)
            {
                return lf;
            }
            return rt;
        }
    }

public:

    st1()
    {}

    st1(int n)
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

    void build(int arr[],st &impact)
    {
        build(0,0,n-1,arr,impact);
    }

    void increase(int l,int r,int val,st &impact,int arr[])
    {
        increase(0,0,n-1,l,r,val,impact,arr);
    }

    pair<int,int> query(int l,int r,st &impact,int arr[])
    {
        return query(0,0,n-1,l,r,impact,arr);
    }


};

st impact(1);
st1 one(1);

int arr[201000];
int temp[201000];
int temp2[201000];

int main()
{
    int i,j,k;
    int n,q;
    int x,y,z;
    char str[10];

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
        temp[i]=1;
        temp2[i]=0;
    }

    one.setN(n+10);
    impact.setN(n+10);

    one.build(temp2,impact);
    impact.build(temp);

    for(i=0;i<n;i++)
    {
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

    pair<int,int> p;
    int ans=0;

    for(i=0;i<n;i++)
    {
        p=one.query(0,n-1,impact,arr);

        //cout<<p.first<<" "<<p.second<<endl;

        ans += p.first;

        impact.increase(p.second,p.second,-1);

        one.increase(p.second,p.second,MAX,impact,arr);

        if(arr[p.second]==0)
        {
            if(p.second!=0)
                one.increase(0,p.second-1,-1,impact,arr);
        }
        else
        {
            if(p.second!=n-1)
                one.increase(p.second+1,n-1,-1,impact,arr);
        }
    }

    printf("%d\n",ans);

    return 0;
}













