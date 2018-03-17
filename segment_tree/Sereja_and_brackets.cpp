#include<bits/stdc++.h>
using namespace std;

int arr[1010000];

//working

class seg_tree
{
    int s[4010000];
    int o[4010000];
    int c[4010000];
    int n;

public:

    seg_tree(){}

    seg_tree(int n)
    {
        (*this).n=n;
    }

    void setn(int n)
    {
        (*this).n=n;
    }

    pair< pair<int,int>,int > merge_node(pair< pair<int,int>,int > l,pair< pair<int,int>,int > r)
    {
        int t,o,c;
        int temp=min(l.first.second,r.second);

        t=l.first.first + r.first.first + 2*temp;
        o=l.first.second + r.first.second-temp;
        c=l.second + r.second -temp;

        return make_pair(make_pair(t,o),c);

    }

    void build(int arr[],int n)
    {
        build(arr,0,n-1,0);

       /* for(int i=0;i<2*n+2;i++)
            cout<<s[i]<<" ";
        cout<<endl;*/
    }

    pair< pair<int,int>,int > build(int arr[],int l,int r,int id)
    {
        if(l>r)
            return make_pair(make_pair(0,0),0);

        if(l==r)
        {
            s[id]=0;
            o[id]=0;
            c[id]=0;

            if(arr[l]==1)
                o[id]++;
            else
                c[id]++;

            return make_pair(make_pair(s[id],o[id]),c[id]);
        }

        int mid= l + (r-l)/2;

        pair< pair<int,int>,int > lt=build(arr,l,mid,(id<<1) + 1);
        pair< pair<int,int>,int > rt=build(arr,mid+1,r,(id<<1) + 2);

        pair< pair<int,int>,int > par=merge_node(lt,rt);

        s[id]=par.first.first;
        o[id]=par.first.second;
        c[id]=par.second;

        return par;
    }

    int query(int l,int r)
    {
        return query(0,n-1,l,r,0).first.first;
    }

    pair< pair<int,int>,int > query(int l,int r,int ql,int qr,int id)
    {
        if(l>r)
            return make_pair(make_pair(0,0),0);

        if(r<ql||l>qr)
            return make_pair(make_pair(0,0),0);

        if(ql<=l&&r<=qr)
            return make_pair(make_pair(s[id],o[id]),c[id]);

        int mid= l + (r-l)/2;

        return merge_node(query(l,mid,ql,qr,(id<<1) + 1), query(mid + 1,r,ql,qr,(id<<1) + 2));
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

char str[1010000];

seg_tree st(1010000);

int main()
{
    int n,i,j,k;

    scanf("%s",str);

    n=strlen(str);

    for(i=0;i<n;i++)
    {
        if(str[i]=='(')
            arr[i]=1;
        else
            arr[i]=0;
    }

    /*for(i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;*/

    st.setn(n);

    st.build(arr,n);

    int q;

    scanf("%d",&q);

    int x,y;

   /* for(i=0;i<n;i++)
        cout<<st.query(i,i)<<" ";
    cout<<endl;*/

    for(i=0;i<q;i++)
    {
        scanf("%d%d",&x,&y);

        x--;
        y--;

        cout<<st.query(x,y)<<endl;
    }

    return 0;
}
