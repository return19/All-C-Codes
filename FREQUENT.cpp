#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ft first
#define sd second

struct node{
    int l,lval;
    int r,rval;
    int best;
};

int n;
int arr[101000];
node st[501000]; // val,freq

node mergenode(node l,node r){
    node newnode;
    if(l.rval == r.lval){
        if(l.r + r.l > l.best && l.r + r.l > r.best){
            newnode.best = l.r + r.l;
        }else if(l.best>r.best){
            newnode.best = l.best;
        }else{
            newnode.best = r.best;
        }
    }else{
        if(l.best>r.best){
            newnode.best = l.best;
        }else{
            newnode.best = r.best;
        }
    }

    newnode.l=l.l;
    newnode.lval=l.lval;
    newnode.r=r.r;
    newnode.rval=r.rval;
    if(l.lval == r.lval)
        newnode.l += r.l;
    if(r.rval == l.rval)
        newnode.r += l.r;
    return newnode;
}

void build(int idx,int l,int r){
    if(l>r)
        return;
    if(l==r){
        st[idx].l=1;
        st[idx].r=1;
        st[idx].best=1;
        st[idx].lval=arr[l];
        st[idx].rval=arr[r];
        return;
    }
    int mid = l + (r-l)/2;
    build((idx<<1)+1,l,mid);
    build((idx<<1)+2,mid+1,r);
    st[idx] = mergenode(st[(idx<<1)+1],st[(idx<<1)+2]);
}

node query(int idx,int l,int r,int ql,int qr){
    if(l>r || qr<l || r<ql){
        node newnode;
        newnode.l=0;
        newnode.r=0;
        newnode.lval=0;
        newnode.rval=0;
        newnode.best=0;
        return newnode;
    }
    if(ql<=l && r<=qr)
        return st[idx];
    int mid = l + (r-l)/2;
    node lf=query((idx<<1)+1,l,mid,ql,qr);
    node rt=query((idx<<1)+2,mid+1,r,ql,qr);

    return mergenode(lf,rt);
}

int main()
{
    int i,j,k;
    int m;
    int x,y;

    scanf("%d",&n);

    while(n!=0 && m!=0){
            scanf("%d",&m);
        for(i=0;i<n;i++)
            scanf("%d",&arr[i]);
        build(0,0,n-1);

        for(i=0;i<m;i++){
            scanf("%d%d",&x,&y);
            x--;    y--;
            printf("%d\n",query(0,0,n-1,x,y).best);
        }
        scanf("%d",&n);
    }
    return 0;
}
