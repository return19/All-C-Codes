#include<bits/stdc++.h>
using namespace std;

int arr[101000];

//working

class seg_tree
{
    int s[401000];
    int n;

public:

    seg_tree(){}

    seg_tree(int n)
    {
        (*this).n=n;
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

        return query(l,mid,ql,qr,(id<<1) + 1) + query(mid + 1,r,ql,qr,(id<<1) + 2);
    }

    void update(int idx,int val)
    {
        update(0,n-1,idx,val,0);
    }

    void update(int l,int r,int idx,int val,int id)
    {
        if(l>r)
            return;
        if(idx<l||idx>r)
            return;

        if(l==r&&l==idx)
        {
            s[id] = val;
            return;
        }

        int mid= l + (r-l)/2;

        update(l,mid,idx,val,(id<<1) + 1);
        update(mid+1,r,idx,val,(id<<1) + 2);

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

    st.update(2,10);

    cout<<st.query(1,4)<<endl;


    return 0;
}
