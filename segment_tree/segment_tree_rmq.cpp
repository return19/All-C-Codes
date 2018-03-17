#include<bits/stdc++.h>
using namespace std;

#define MAX 9999999
class st
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

    void build(int idx,int l,int r,int arr[])
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

        build((idx<<1)+1,l,mid,arr);
        build((idx<<1)+2,mid+1,r,arr);

        if(s[(idx<<1)+1]<s[(idx<<1)+2])
        {
            s[idx]=s[(idx<<1)+1];
            mn[idx]=mn[(idx<<1)+1];
        }
        else
        {
            s[idx]=s[(idx<<1)+2];
            mn[idx]=mn[(idx<<1)+2];
        }
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

        if(s[(idx<<1)+1]<s[(idx<<1)+2])
        {
            s[idx]=s[(idx<<1)+1];
            mn[idx]=mn[(idx<<1)+1];
        }
        else
        {
            s[idx]=s[(idx<<1)+2];
            mn[idx]=mn[(idx<<1)+2];
        }
    }

    pair<int,int> query(int idx,int l,int r,int ql,int qr)
    {
        if(ql>r || qr<l)
            return make_pair(MAX,-1);

        if(ql<=l&&r<=qr)
        {
            return make_pair(s[idx],mn[idx]);
        }

        shift(idx,l,r);

        int mid=l + (r-l)/2;

        pair<int,int> lf=query((idx<<1)+1,l,mid,ql,qr);
        pair<int,int> rt=query((idx<<1)+2,mid+1,r,ql,qr);

        if(lf.first<rt.first)
            return lf;
        else
            return rt;
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

    pair<int,int> query(int l,int r)
    {
        return query(0,0,n-1,l,r);
    }


};

st one(1);

int n,q;
int arr[101000];
char str[10];

int main()
{
    int i,j,k;
    int x,y,z;

    scanf("%d",&n);

    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    one.setN(n+10);
    one.build(arr);

    scanf("%d",&q);

    for(i=0;i<q;i++)
    {
        scanf("%s",str);

        if(str[0]=='u')// update query
        {
            scanf("%d%d%d",&x,&y,&z);

            one.increase(x,y,z);
        }
        else// min query
        {
            scanf("%d%d",&x,&y);
            pair<int,int> p=one.query(x,y);
            cout<<p.first<<" "<<p.second<<endl;
        }
    }

    return 0;
}




















