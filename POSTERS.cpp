#include<bits/stdc++.h>
using namespace std;

#define ft first
#define sd second

int n,q;
map<int,int> memo;
map<int,int>::iterator it;
pair<int,int> posters[101000];
set<int> s;

int st[501000];
int f[501000];

void update(int idx,int val){
    st[idx]=max(st[idx],val);
    f[idx]=max(f[idx],val);
}

void shift(int idx,int l,int r){
    update((idx<<1)+1,f[idx]);
    update((idx<<1)+2,f[idx]);
}

void build(int idx,int l,int r){
    if(l>r)
        return;
    if(l==r){
        st[idx]=INT_MIN;
        f[idx]=INT_MIN;
        return;
    }
    int mid= l + (r-l)/2;
    build((idx<<1)+1,l,mid);
    build((idx<<1)+2,mid+1,r);
    f[idx]=INT_MIN;
}

void update(int idx,int l,int r,int ql,int qr,int val){
    //cout<<l<<" "<<r<<" : "<<ql<<" "<<qr<<endl;
    if(l>r)
        return;
    if(qr<l || r<ql)
        return;
    if(ql<=l && r<=qr){
        st[idx]=max(st[idx],val);
        f[idx]=max(f[idx],val);
        return;
    }
   // cout<<ql<<" "<<qr<<" : "<<l<<" "<<r<<endl;
    int mid= l + (r-l)/2;
    shift(idx,l,r);
    update((idx<<1)+1,l,mid,ql,qr,val);
    update((idx<<1)+2,mid+1,r,ql,qr,val);
    st[idx] = max(st[(idx<<1)+1],st[(idx<<1)+2]);
}

int query(int idx,int l,int r,int ql,int qr){
    if(l>r)
        return INT_MIN;
    if(qr<l || r<ql){
        return INT_MIN;
    }
    if(ql<=l &&r<=qr)
        return st[idx];
    int mid= l + (r-l)/2;
    shift(idx,l,r);

    return max(query((idx<<1)+1,l,mid,ql,qr),query((idx<<1)+2,mid+1,r,ql,qr));
}

int main()
{
    int i,j,k;
    int test,t;
    int x,y,z;

    scanf("%d",&test);

    for(t=0;t<test;t++)
    {
        memo.clear();
        s.clear();
        scanf("%d",&q);
        for(i=0;i<q;i++){
            scanf("%d%d",&x,&y);
            posters[i].ft=x;
            posters[i].sd=y;
            memo[x];
            memo[y];
        }

        k=0;
        for(it=memo.begin();it!=memo.end();it++){
            memo[it->first]=k++;
        }

        build(0,0,k-1);

        for(i=0;i<q;i++){
            posters[i].ft=memo[posters[i].ft];
            posters[i].sd=memo[posters[i].sd];
            update(0,0,k-1,posters[i].ft,posters[i].sd,i+1);

           /* for(j=0;j<k;j++)
                cout<<query(0,0,k-1,j,j)<<" ";
            cout<<endl;*/
        }

        for(i=0;i<k;i++){
            int cur=query(0,0,k-1,i,i);
            //cout<<cur<<" ";
            if(cur!=INT_MIN)
                s.insert(cur);
        }
       // cout<<endl;

        printf("%d\n",s.size());
    }
    return 0;
}












