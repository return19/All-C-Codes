#include<bits/stdc++.h>
using namespace std;

int st[501000];
int f[501000];

void update(int idx,int l,int r){
    if(l>r) return;
    st[idx] = (r-l+1)-st[idx];
    f[idx]=1-f[idx];
}

void shift(int idx,int l,int r){
    int mid= l + (r-l)/2;
    if(f[idx]){
        update((idx<<1)+1,l,mid);
        update((idx<<1)+2,mid+1,r);
    }
    f[idx]=0;
}

void update(int idx,int l,int r,int ql,int qr){
    if(l>r)
        return;
    if(qr<l || r<ql)
        return;
    if(ql<=l && r<=qr){
        st[idx] = (r-l+1) - st[idx];
        f[idx]=1-f[idx];
        return;
    }
    int mid = l + (r-l)/2;
    shift(idx,l,r);
    update((idx<<1)+1,l,mid,ql,qr);
    update((idx<<1)+2,mid+1,r,ql,qr);

    st[idx] = st[(idx<<1)+1] + st[(idx<<1)+2];
}

int query(int idx,int l,int r,int ql,int qr){
    if(l>r)
        return 0;
    if(qr<l || r<ql)
        return 0;
    if(ql<=l && r<=qr)
        return st[idx];
    shift(idx,l,r);
    int mid = l + (r-l)/2;
    shift(idx,l,r);
    return query((idx<<1)+1,l,mid,ql,qr) + query((idx<<1)+2,mid+1,r,ql,qr);
}

int main()
{
    int i,j,k;
    int n,m;
    int x,y,z;
    int t;

    scanf("%d%d",&n,&m);

    for(i=0;i<m;i++){
        scanf("%d%d%d",&t,&x,&y);
        x--;    y--;
        if(t==0){
            update(0,0,n-1,x,y);
        }else{ // t==1
            printf("%d\n",query(0,0,n-1,x,y));
        }
    }
    return 0;
}
