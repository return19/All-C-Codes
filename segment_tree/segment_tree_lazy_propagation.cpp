#include<bits/stdc++.h>
using namespace std;

int arr[101000];

//working

class seg_tree
{
    int s[40100];
    int lazy[40100];
    int n;

public:

    seg_tree(){}

    seg_tree(int n)
    {
        (*this).n=n;
    }

    void update(int l,int r,int val,int idx)
    {
        s[idx] += (r-l+1)*val;
        lazy[idx] += val;
    }

    void shift(int l,int r,int idx)
    {
        int mid=l + (r-l)/2;

        update(l,mid,lazy[idx],(idx<<1) +1);
        update(mid+1,r,lazy[idx],(idx<<1) +2);

        lazy[idx]=0;
    }

    void build(int arr[],int n)
    {
        build(arr,0,n-1,0);

        for(int i=0;i<2*n+2;i++)
            cout<<s[i]<<" ";
        cout<<endl;
    }

    int build(int arr[],int l,int r,int id)
    {
        if(l>r)
            return 0;

        if(l==r)
        {
            s[id]=arr[l];
            lazy[id]=0;
            return s[id];
        }

        int mid= l + (r-l)/2;

        int lt=build(arr,l,mid,(id<<1) + 1);
        int rt=build(arr,mid+1,r,(id<<1) + 2);

        return s[id]=lt + rt;
    }

    int query(int l,int r)
    {
        return query(0,n-1,l,r,0);
    }

    int query(int l,int r,int ql,int qr,int id)
    {
        if(l>r)
            return 0;

        if(r<ql||l>qr)
            return 0;

        if(ql<=l&&r<=qr)
            return s[id];

        int mid= l + (r-l)/2;

        shift(l,r,id);

        return query(l,mid,ql,qr,(id<<1) + 1) + query(mid + 1,r,ql,qr,(id<<1) + 2);
    }

    void update(int l,int r,int val)
    {
        update(0,n-1,l,r,val,0);
    }

    void update(int l,int r,int ul,int ur,int val,int id)
    {
        if(l>r)
            return;
        if(ur<l||ul>r)
            return;

        if(ul<=l&&r<=ur)
        {
            update(l,r,val,id);
            return;
        }

        int mid= l + (r-l)/2;

        shift(l,r,id);

        update(l,mid,ul,ur,val,(id<<1) + 1);
        update(mid+1,r,ul,ur,val,(id<<1) + 2);

        s[id]=s[(id<<1) + 1] + s[(id<<1) + 2];
    }
};

int main()
{
    int n,i,j,k;

    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    seg_tree st(n);

    st.build(arr,n);

    for(i=0;i<n;i++)
        cout<<st.query(i,i)<<" ";
    cout<<endl;

    cout<<st.query(1,4)<<endl;

    st.update(1,3,6);

    cout<<st.query(1,4)<<endl;

    for(i=0;i<n;i++)
        cout<<st.query(i,i)<<" ";
    cout<<endl;


    return 0;
}
