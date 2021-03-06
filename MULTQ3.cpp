#include<bits/stdc++.h>
using namespace std;

#define ft first
#define sd second
#define mp make_pair

int n;
pair< pair<int,int>,int > st[501000]; // no of 0, no of 1, flag =1,2

void rot(int l,int r,pair< pair<int,int>,int > &node){
    int temp=node.ft.ft;
    node.ft.ft=(r-l+1) - node.ft.sd - node.ft.ft;
    node.ft.sd=temp;

    node.sd=(node.sd+1)%3;
}

void shift(int l,int r,int idx){

    int mid = l + (r-l)/2;

    if(st[idx].sd==1){
        rot(l,mid,st[(idx<<1)+1]);
        rot(mid+1,r,st[(idx<<1)+2]);
    }else if(st[idx].sd==2){
        rot(l,mid,st[(idx<<1)+1]);
        rot(mid+1,r,st[(idx<<1)+2]);
        rot(l,mid,st[(idx<<1)+1]);
        rot(mid+1,r,st[(idx<<1)+2]);
    }
    st[idx].sd=0;
}

void update(int idx,int l,int r,int ql,int qr){
    if(l>r || ql>qr)
        return;
    if(r<ql || qr<l)
        return;
    if(ql<=l && r<=qr){
        rot(l,r,st[idx]);
        return;
    }

   // cout<<l<<" "<<r<<" : "<<ql<<" "<<qr<<endl;

    shift(l,r,idx);
    int mid= l + (r-l)/2;

    update((idx<<1)+1,l,mid,ql,qr);
    update((idx<<1)+2,mid+1,r,ql,qr);

    st[idx].ft.ft=st[(idx<<1)+1].ft.ft + st[(idx<<1)+2].ft.ft;
    st[idx].ft.sd=st[(idx<<1)+1].ft.sd + st[(idx<<1)+2].ft.sd;
    st[idx].sd=0;
}

int query(int idx,int l,int r,int ql,int qr){
    if(l>r || ql>qr)
        return 0;
    if(r<ql || qr<l)
        return 0;
    if(ql<=l && r<=qr)
        return st[idx].ft.ft;
    shift(l,r,idx);
    int mid=l + (r-l)/2;
    return query((idx<<1)+1,l,mid,ql,qr)+query((idx<<1)+2,mid+1,r,ql,qr);
}

void build(int idx,int l,int r){
    if(l>r)
        return;
    if(l==r){
        st[idx].ft.ft=1;
        st[idx].ft.sd=0;
        st[idx].sd=0;
        return;
    }
    int mid= l + (r-l)/2;
    build((idx<<1)+1,l,mid);
    build((idx<<1)+2,mid+1,r);

    st[idx].ft.ft=st[(idx<<1)+1].ft.ft + st[(idx<<1)+2].ft.ft;
    st[idx].ft.sd=st[(idx<<1)+1].ft.sd + st[(idx<<1)+2].ft.sd;
    st[idx].sd=0;
}

int main(){
    int i,j,k;
    int x,y,z,t,q;

    scanf("%d%d",&n,&q);

    build(0,0,n-1);

    for(i=0;i<q;i++){
        scanf("%d%d%d",&t,&x,&y);

        if(t==0){ // add 1
            update(0,0,n-1,x,y);
        }else if(t==1){ // query 1
            printf("%d\n",query(0,0,n-1,x,y));
        }

      /*  for(j=0;j<n;j++)
            cout<<query(0,0,n-1,j,j)<<" ";
        cout<<endl;*/
    }
    return 0;
}
















