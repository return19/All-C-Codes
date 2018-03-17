#include<bits/stdc++.h>
using namespace std;

long long n;
long long st[1001000];
long long f[1001000];

void update(long long idx,long long val){
    st[idx] +=val;
    f[idx]+=val;
}

void shift(long long idx,long long l,long long r){
    update((idx<<1)+1,f[idx]);
    update((idx<<1)+2,f[idx]);
    f[idx]=0;
}

void build(long long idx,long long l,long long r){
    if(l>r)
        return;
    if(l==r){
        st[idx]=l;
        f[idx]=0;
        return;
    }
    long long mid = l + (r-l)/2;
    build((idx<<1)+1,l,mid);
    build((idx<<1)+2,mid+1,r);
    st[idx]=l;
    f[idx]=0;
}

void update(long long idx,long long l,long long r,long long ql,long long qr,long long val){
    if(l>r)
        return;
    if(qr<st[idx] || r<ql)
        return;
    if(ql<=st[idx] && r<=qr){
        st[idx]+=val;
        f[idx] += val;
        return;
    }
    long long mid = l + (r-l)/2;
    shift(idx,l,r);
    update((idx<<1)+1,l,mid,ql,qr,val);
    update((idx<<1)+2,mid+1,r,ql,qr,val);
    st[idx] = min(st[(idx<<1)+1],st[(idx<<1)+2]);
}

long long query(long long idx,long long l,long long r,long long x){
    if(l>r)
        return LLONG_MIN;
    if(x<l || r<x)
        return LLONG_MIN;
    if(l==r && l==x)
        return st[idx];
  //  cout<<l<<" "<<r<<endl;
    shift(idx,l,r);
    long long mid = l + (r-l)/2;
    return max(query((idx<<1)+1,l,mid,x),query((idx<<1)+2,mid+1,r,x));
}

int main()
{
    long long i,j,k;
    long long test,t;
    long long x,y,z;

    scanf("%lld",&test);

    for(t=0;t<test;t++)
    {
        scanf("%lld",&n);
        build(0,0,n-1);

        for(i=1;i<=n;i++){
            scanf("%lld",&x);
            update(0,0,n-1,x-i,x-1,1);
            update(0,0,n-1,x,x,-x);
        }

        for(i=0;i<n;i++){
            printf("%d ",query(0,0,n-1,i)+1);
        }
        printf("\n");
    }
    return 0;
}












