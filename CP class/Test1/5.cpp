#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ft first
#define sd second

pair< int,pair<int,int> > st[501000]; // sum,e,o
int arr[101000];
int n;
int f[101000];
int fe[101000],fo[101000];

void build(int idx,int l,int r){
    if(l>r)
        return;
    if(l==r){
        st[idx].ft = arr[l];
        if(arr[l]&1){
            st[idx].sd.ft = 0;
            st[idx].sd.sd = 1;
        }
        else{
            st[idx].sd.ft = 1;
            st[idx].sd.sd = 0;
        }
        return;
    }
    int mid = l + (r-l)/2;
    build((idx<<1)+1,l,mid);
    build((idx<<1)+2,mid+1,r);

    st[idx].ft = st[(idx<<1)+1].ft + st[(idx<<1)+2].ft;
    st[idx].sd.ft = st[(idx<<1)+1].sd.ft + st[(idx<<1)+2].sd.ft;
    st[idx].sd.sd = st[(idx<<1)+1].sd.sd + st[(idx<<1)+2].sd.sd;
}

void updateE(int idx,int l,int r,int ql,int qr,int x){
    if(l>r) return;
    if(qr<l || r<ql) return;
    if(ql<=l && r<=qr){
        st[idx].ft += (st[idx].sd.ft)*x;
        if(x&1)
        {
            st[idx].ft.sd += st[idx].ft.ft
        }
        f[]
        return;
    }
    int mid = l + (r-l)/2;

    shift(idx,l,mid,r);

    updateE((idx<<1)+1,l,mid,ql,qr,x);
    updateE((idx<<1)+2,mid+1,r,ql,qr,x);

    st[idx].ft = st[(idx<<1)+1].ft + st[(idx<<1)+2].ft;
    st[idx].sd.ft = st[(idx<<1)+1].sd.ft + st[(idx<<1)+2].sd.ft;
    st[idx].sd.sd = st[(idx<<1)+1].sd.sd + st[(idx<<1)+2].sd.sd;
}

int main()
{
    int i,j,k;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scnaf("%d",&n);

    int q,t,x,y,z;
    scanf("%d",&q);

    for(i=0;i<q;i++){
        scanf("%d",&t);
        if(t==1){ // query
            scanf("%d%d",&x,&y);
            x--;    y--;
        } else if(t==2){ // even update
            scanf("%d%d%d",&x,&y,&z);
            x--;    y--;
        } else { // odd update
            scanf("%d%d%d",&x,&y,&z);
            x--;    y--;
        }
    }

    return 0;
}






















