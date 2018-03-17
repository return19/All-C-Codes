#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ft first
#define sd second

long long f[501000];
pair<long long,long long> st[501000]; // sq,num
long long arr[101000];
long long n;
long long M = 1e9 + 7;

void build(long long idx,long long l,long long r){
    if(l>r)
        return;
    if(l==r){
        st[idx].ft = (arr[l]*arr[l])%M;
        st[idx].sd = arr[l];
        f[idx]=0;
        return;
    }
    long long mid = l + (r-l)/2;
    build((idx<<1)+1,l,mid);
    build((idx<<1)+2,mid+1,r);

    st[idx].ft = (st[(idx<<1)+1].ft + st[(idx<<1)+2].ft)%M;
    st[idx].sd = (st[(idx<<1)+1].sd + st[(idx<<1)+2].sd)%M;
    f[idx]=0;
}

void update(long long idx,long long l,long long r,long long x){
    st[idx].ft = (st[idx].ft + ((r-l+1)*((x*x)%M))%M + (2*((x*(st[idx].sd))%M))%M )%M;
    st[idx].sd = (st[idx].sd + ((r-l+1)*x)%M )%M;
    f[idx]+= x;
}

void shift(long long idx,long long l,long long mid,long long r){
    if(f[idx]){
        update((idx<<1)+1,l,mid,f[idx]);
        update((idx<<1)+2,mid+1,r,f[idx]);
        f[idx]=0;
    }
}

void update(long long idx,long long l,long long r,long long ql,long long qr,long long x){
    if(l>r) return;
    if(qr<l || r<ql) return;
    if(ql<=l && r<=qr){
        st[idx].ft = (st[idx].ft + ((r-l+1)*((x*x)%M))%M + (2*((x*(st[idx].sd))%M))%M)%M;
        st[idx].sd = (st[idx].sd + ((r-l+1)*x)%M)%M;
        f[idx]+= x;
        return;
    }
    long long mid = l + (r-l)/2;

    shift(idx,l,mid,r);

    update((idx<<1)+1,l,mid,ql,qr,x);
    update((idx<<1)+2,mid+1,r,ql,qr,x);
    st[idx].ft = (st[(idx<<1)+1].ft + st[(idx<<1)+2].ft)%M;
    st[idx].sd = (st[(idx<<1)+1].sd + st[(idx<<1)+2].sd)%M;
}

long long query(long long idx,long long l,long long r,long long ql,long long qr){
    if(l>r) return 0;
    if(qr<l || r<ql)    return 0;
    if(ql<=l && r<=qr)
        return st[idx].ft;
    long long mid = l + (r-l)/2;
    shift(idx,l,mid,r);

    return (query((idx<<1)+1,l,mid,ql,qr)
          +query((idx<<1)+2,mid+1,r,ql,qr))%M;
}

int main()
{
    long long i,j,k;
    long long q;
    scanf("%lld",&n);
    scanf("%lld",&q);
    for(i=0;i<n;i++)
        scanf("%lld",&arr[i]);
    build(0,0,n-1);
    long long x,y,z;
    long long t;

    for(i=0;i<q;i++){
        scanf("%lld",&t);
        if(t==1){
            scanf("%lld%lld%lld",&x,&y,&z);
            x--;    y--;
            update(0,0,n-1,x,y,z);
        } else { // t==2
            scanf("%lld%lld",&x,&y);
            x--;    y--;
            printf("%lld\n",query(0,0,n-1,x,y));
        }

    }
    return 0;
}















