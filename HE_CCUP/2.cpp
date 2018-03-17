#include<bits/stdc++.h>
using namespace std;

#define sz (1e6 + 1)
#define vi vector<long long>
#define  pb push_back
#define ll long long

#define gc getchar_unlocked

void scanint(long long &x)
{
    register long long c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}


vi pr;
vi phi(sz);

long long MOD= 1e9 + 7;

void pre_phi() {
    phi[1] = 1;
    vi lp(sz,0);
    for (long long i = 2; i < sz; i++) {
        if (lp[i] == 0) {
            lp[i] = i;
            phi[i] = i - 1;
            pr.pb(i);
        }
        else {
            if (lp[i / lp[i]] == lp[i]) {
                phi[i] = phi[i / lp[i]] * lp[i];
            }
            else {
                phi[i] = phi[i / lp[i]] * (lp[i] - 1);
            }
        }
        long long lim = pr.size();
        for (long long j = 0; j < lim && pr[j] <= lp[i] && i * pr[j] < sz; j++) {
            lp[i * pr[j]] = pr[j];
        }
    }
}

vector<long long> cache(1e6+1, -1);

ll solve(long long n) {
    if(cache[n] != -1) return cache[n];
    ll ret = 0;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret += i *1LL* phi[i];
            if (n / i != i) {
                ret += (n / i) *1LL* phi[n / i];
                //trace(phi[n/i]);
            }
        }
    }
    //trace(ret);
    ret = (ret + 1 ) >> 1;
    cache[n] = ret = ret % MOD;
    return ret;
}

long long arr[1010000];
long long ans[1010000];
long long bt[5010000];
long long n;

void add(long long idx,long long val){
    while(idx<=n){
        bt[idx] = (bt[idx] + val)%MOD;
        if(bt[idx] < 0)
            bt[idx]+=MOD;
        idx +=  (idx)&(-idx);
    }
}

long long sum(long long idx){
    long long ans=0;

    while(idx>0){
        ans = (ans + bt[idx])%MOD;
        if(ans<0)
            ans += MOD;
        idx -= (idx)&(-idx);
    }
    return ans;
}

int main(){
    long long i,j,k;
    pre_phi();

    scanint(n);

    for(i=1;i<=n;i++){
        scanint(arr[i]);
        ans[i] = solve(arr[i]);
        add(i,ans[i]);
    }

    string s;

    long long q;
    long long x,y,z;
    scanint(q);
    for(i=0;i<q;i++){
        cin>>s;
        scanint(x);
        scanint(y);

        if(s[0]=='C'){
            long long ans=0;
            ans = sum(y);
            if(x!=1)
                ans = ans - sum(x-1);
            if(ans<0)
                ans += MOD;
            printf("%lld\n",ans);
        } else if(s[0]=='U'){
            add(x,-1*ans[x]);
            ans[x] = solve(y);
            add(x,ans[x]);
        }
    }

    return 0;
}
