#include<bits/stdc++.h>
using namespace std;

long long n,m;
long long arr[1010000];
long long st[1010000];

long long build(long long idx,long long l,long long r){
    if(l==r){
        st[idx] = arr[l];
        return 1;
    }
    long long mid = l + (r-l)/2;
    long long lt = build((idx<<1)+1,l,mid);
    long long rt = build((idx<<1)+2,mid+1,r);

    if(lt==1){
        st[idx] = st[(idx<<1)+1]|st[(idx<<1)+2];
        return 0;
    } else{ // 0
        st[idx] = st[(idx<<1)+1]^st[(idx<<1)+2];
        return 1;
    }
}

long long update(long long idx,long long l,long long r,long long &x,long long &val){
    if(x<l || x>r)
        return -1;
    if(x==l && x==r){
        st[idx] = val;
        return 1;
    }
    long long mid = l + (r-l)/2;
    long long lt = update((idx<<1)+1,l,mid,x,val);
    long long rt = update((idx<<1)+2,mid+1,r,x,val);

    if(lt==1 || rt==1){
        st[idx] = st[(idx<<1)+1]|st[(idx<<1)+2];
        return 0;
    } else { // 0
        st[idx] = st[(idx<<1)+1]^st[(idx<<1)+2];
        return 1;
    }
}

int main()
{
    long long i,j,k;
    scanf("%lld%lld",&n,&m);

    for(i=0;i<(1<<n);i++){
        scanf("%lld",&arr[i]);
    }

    build(0,0,(1<<n)-1);

    long long x,y;
    for(i=0;i<m;i++){
        scanf("%lld%lld",&x,&y);
        x--;
        update(0,0,(1<<n)-1,x,y);
        printf("%lld\n",st[0]);
    }

    return 0;
}
