
/********************

    root8950

*********************/


#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PII pair<int,int>
#define ft first
#define sd second
#define MAXN MOD
#define mp make_pair
#define f_in(st) freopen(st,"r",stdin)
#define f_out(st) freopen(st,"w",stdout)
#define sc(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
#define pr(x) printf("%d\n",x)
#define prll(x) printf("%lld\n",x)
#define pb push_back
#define MOD 1000000007
#define PIE 3.141592653589
#define inf INT_MAX/2
#define ASST(X,L,R) assert(X >= L && X <= R)

double solve(vector<double> &vec,int n){
    double max1=vec[0],pro=1-vec[0],sum=vec[0]/(1-vec[0]);
    for(int i=1;i<n;i++){
        pro=pro*(1-vec[i]);
        sum=sum+vec[i]/(1-vec[i]);
        max1=max(max1,pro*sum);
    }

    return max1;

}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    int n;
    cin >> n;
    vector<double> vec(n);
    for(int i=0;i<n;i++){
        cin >> vec[i];
    }
    sort(vec.begin(),vec.end());
    reverse(vec.begin(),vec.end());
    /*for(int i=0;i<n;i++){
        cout << vec[i] << " ";
    }*/
    double ans=solve(vec,n);
    printf("%.9lf\n",ans);
    //cout << ans << "\n";
    return 0;
}
