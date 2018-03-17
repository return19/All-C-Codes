#include<bits/stdc++.h>
using namespace std;

long long M = 1e9 + 7;

long long arr[101000];
long long s[1100];
vector<long long> p;

long long st[1010000];

void sieve(){
    long long i,j,k;
    s[0]=s[1]=1;
    for(i=2;i<1100;i++)
    {
        if(!s[i]){
            p.push_back(i);
            for(j=i*2;j<1100;j+=i){
                s[j]=1;
            }
        }
    }

    /*for(i=0;i<10;i++)
        cout<<p[i]<<" ";
    cout<<endl;*/
}

long long power(long long x,long long y){
    if(y==0)
        return 1;
    if(y==1)
        return x%M;
    long long hf = power(x,y/2);
    if(y&1)
        return (((hf*hf)%M)*x)%M;
    return (hf*hf)%M;
}

long long factors(long long x){
    long long i,j,k;
    long long ans=1;
    for(i=0;p[i]*p[i]<=x;i++){
        long long c=0;
        while(x%p[i]==0){
            x /= p[i];
            c++;
        }
        ans = (ans*(c+1))%M;
    }
    if(x>1){
        ans = (ans*2)%M;
    }
    return ans;
}

void build(long long idx,long long l,long long r){
    if(l>r)
        return;
    if(l==r){
        st[idx] = factors(arr[l]);
        return;
    }
    long long mid = l + (r-l)/2;
    build((idx<<1)+1,l,mid);
    build((idx<<1)+2,mid+1,r);
    st[idx] = (st[(idx<<1)+1]*st[(idx<<1)+2])%M;
}

long long query(long long idx,long long l,long long r,long long ql,long long qr){
    if(l>r)
        return 1;
    if(qr< l || r< ql)
        return 1;
    if(ql<= l && r<= qr)
        return st[idx];
    long long mid = l + (r-l)/2;
    return (query((idx<<1)+1,l,mid,ql,qr)
           *query((idx<<1)+2,mid+1,r,ql,qr))%M;
}

void update(long long idx,long long l,long long r,long long x){
    if(x<l || r<x)
        return;
    if(l==x && r==x){
        st[idx] = factors(arr[x]);
        return;
    }
    long long mid = l + (r-l)/2;
    update((idx<<1)+1,l,mid,x);
    update((idx<<1)+2,mid+1,r,x);
    st[idx] = (st[(idx<<1)+1]*st[(idx<<1)+2])%M;
}


int main()
{
    long long i,j,k;
    long long n,q;
    sieve();
    scanf("%lld%lld",&n,&q);
    for(i=0;i<n;i++){
        scanf("%lld",&arr[i]);
    }

   /* for(i=0;i<n;i++)
        cout<<factors(arr[i])<<" ";
    cout<<endl;*/

    build(0,0,n-1);
    long long x,y;
    long long t;
    for(i=0;i<q;i++){
        scanf("%lld%lld%lld",&t,&x,&y);
        if(t==1){ // update
            x--;
            arr[x] = y;
            update(0,0,n-1,x);
        } else { // query
            x--;    y--;
            printf("%lld\n",query(0,0,n-1,x,y));
        }
    }

    return 0;
}















