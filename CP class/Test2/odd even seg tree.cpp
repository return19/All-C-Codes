#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ft first
#define sd second

int f[501000];
pair<int,int> st[501000]; // sq,num
int arr[101000];
int n;

void build(int idx,int l,int r){
    if(l>r)
        return;
    if(l==r){
        st[idx].ft = arr[l]*arr[l];
        st[idx].sd = arr[l];
        f[idx]=0;
        return;
    }
    int mid = l + (r-l)/2;
    build((idx<<1)+1,l,mid);
    build((idx<<1)+2,mid+1,r);

    st[idx].ft = st[(idx<<1)+1].ft + st[(idx<<1)+2].ft;
    st[idx].sd = st[(idx<<1)+1].sd + st[(idx<<1)+2].sd;
    f[idx]=0;
}

void update(int idx,int l,int r,int x){
    st[idx].ft = st[idx].ft + (r-l+1)*x*x + 2*x*(st[idx].sd);
    st[idx].sd = st[idx].sd + (r-l+1)*x;
    f[idx]+= x;
}

void shift(int idx,int l,int mid,int r){
    if(f[idx]){
        update((idx<<1)+1,l,mid,f[idx]);
        update((idx<<1)+2,mid+1,r,f[idx]);
        f[idx]=0;
    }
}

void update(int idx,int l,int r,int ql,int qr,int x){
    if(l>r) return;
    if(qr<l || r<ql) return;
    if(ql<=l && r<=qr){
        st[idx].ft = st[idx].ft + (r-l+1)*x*x + 2*x*(st[idx].sd);
        st[idx].sd = st[idx].sd + (r-l+1)*x;
        f[idx]+= x;
        return;
    }
    int mid = l + (r-l)/2;

    shift(idx,l,mid,r);

    update((idx<<1)+1,l,mid,ql,qr,x);
    update((idx<<1)+1,mid+1,r,ql,qr,x);
    st[idx].ft = st[(idx<<1)+1].ft + st[(idx<<1)+2].ft;
    st[idx].sd = st[(idx<<1)+1].sd + st[(idx<<1)+2].sd;
}

int query(int idx,int l,int r,int ql,int qr){
    if(l>r) return 0;
    if(qr<l || r<ql)    return 0;
    if(ql<=l && r<=qr)
        return st[idx].ft;
    int mid = l + (r-l)/2;
    shift(idx,l,mid,r);

    return query((idx<<1)+1,l,mid,ql,qr)
          +query((idx<<1)+2,mid+1,r,ql,qr);
}

int main()
{
    int i,j,k;
    scanf("%d",&n);

    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    build(0,0,n-1);
    int q;
    int x,y,z;
    int t;
    scanf("%d",&q);

    for(i=0;i<q;i++){
        scanf("%d",&t);
        if(t==1){
            scanf("%d%d%d",&x,&y,&z);
            x--;    y--;
            update(0,0,n-1,x,y,z);
        } else { // t==2
            scanf("%d%d",&x,&y);
            x--;    y--;
            printf("%d\n",query(0,0,n-1,x,y));
        }

    }
    return 0;
}















