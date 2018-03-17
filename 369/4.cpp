#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ft first
#define sd second

long long n;
vector<long long> g[201000];
vector< pair<long long,long long> > v; // cycle size, size
long long csum[201000];
long long vis[201000];
long long cnt[201000];
long long tans;
long long M = 1e9 + 7;

long long power(long long x,long long y){
    if(y==0)
        return 1;
    if(y==1)
        return x%M;
    long long hf = pow(x,y/2);
    if(y&1)
        return (((hf*hf)%M)*x)%M;
    return (hf*hf)%M;
}

long long dfs(long long x,long long c,long long p){
    vis[x]=1;
    cnt[x]=c;
    long long i;
    long long ans=1;
    for(i=0;i<g[x].size();i++){
        if(!vis[g[x][i]]){
            ans += dfs(g[x][i],c+1,x);
        } else if(g[x][i]!=p){
          //  cout<<"here"<<x<<endl;
            tans = abs(cnt[x]- cnt[g[x][i]]) + 1;
        }
    }
    return ans;
}

int main()
{
    long long i,j,k;
    long long x,y;
    long long xtra =0;
    scanf("%lld",&n);
    for(i=0;i<n;i++){
        scanf("%lld",&x);
        x--;
        g[i].push_back(x);
        g[x].push_back(i);
    }

    for(i=0;i<n;i++){
        if(!vis[i]){
            tans=-1;
            long long sz = dfs(i,1,-1);
            if(tans==-1){
                xtra+=sz;
            }else{
                v.push_back(mp(tans,sz));
            }
        }
    }

   // cout<<xtra<<" "<<v.size()<<endl;

   // for(i=0;i<v.size();i++)
     //   cout<<v[i].ft<<" "<<v[i].sd<<endl;

    long long m = v.size();
    csum[m]=0;
    for(i=m-1;i>=0;i--)
        csum[i] = csum[i+1] + v[i].sd;

    long long ans=0;
    for(i=0;i<m;i++){
        ans = (ans + (((2*power(2,xtra))%M)*power(2,(v[i].sd - v[i].ft + csum[i+1])))%M)%M;
    }

    printf("%lld\n",(power(2,n) - ans + M)%M);

    return 0;
}









