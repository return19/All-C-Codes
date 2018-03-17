#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

#define rep(i,b) for(LL i=0;i<b;i++)
#define rep1(i,b) for(LL i=1;i<=b;i++)
#define REP(i,a,b) for(LL i=a;i<=b;i++)
#define REV(i,b,a) for(LL i=b;i>=a;i--)

#define plln(n) printf("%lld\n",n)

#define s3ll(n1,n2,n3) scanf("%lld%lld%lld",&n1,&n2,&n3)
#define s2ll(n1,n2) scanf("%lld%lld",&n1,&n2)
#define sll(n) scanf("%lld",&n)

#define countSetBits(n) __builtin_popcountll(n)
#define gcd(a,b) __gcd(a,b)

#define mod 1000000007
#define mx 999999



map<LL,LL> cnt,ans,visited;

int main()
{
    LL t,n,i,j,k,a,b,x,flag=0;
    s3ll(n,a,b);
    LL num[n+5],cpy[n+5];
    rep(i,n){
        sll(num[i]);
        cpy[i]=num[i];
        cnt[num[i]]=1;
    }
    sort(num,num+n);
    LL s=0;
    if(b>a) { swap(a,b); s=1; }
    LL chk=0;
    rep(i,n){
        if((cnt[num[i]])&&(cnt[a-num[i]])){
            cnt[num[i]]=0;
            cnt[a-num[i]]=0;
            visited[num[i]]=visited[a-num[i]]=1;
            ans[num[i]]=ans[a-num[i]]=0;
        }else if((cnt[num[i]])&&(cnt[b-num[i]])){
            cnt[num[i]]=0;
            cnt[b-num[i]]=0;
            visited[num[i]]=visited[b-num[i]]=1;
            ans[num[i]]=ans[b-num[i]]=1;
        }else if(!visited[num[i]]){
            flag=1;
        }
    }
    if(!flag){
        printf("YES\n");
        rep(i,n){
            if(s) cout<<1-ans[cpy[i]]<<" ";
            else cout<<ans[cpy[i]]<<" ";
        }
        cout<<endl;
    }else{
        cout<<"NO\n";
    }
    return 0;
}
