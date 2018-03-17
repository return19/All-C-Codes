#include <bits/stdc++.h>
//#include "testlib.h"
using namespace std ;
#define LL long long int
#define ft first
#define sd second
#define PII pair<int,int>
#define MAXN 20000001
#define MAXM 1001
#define mp make_pair
#define f_in(st) freopen(st,"r",stdin)
#define f_out(st) freopen(st,"w",stdout)
#define sc(x) scanf("%d",&x)
#define scll(x) scanf("%lld",&x)
#define pr(x) printf("%lld\n",x)
#define all(x) x.begin(),x.end()
#define allr(x) x.rbegin(),x.rend()
#define pb push_back
#define MOD 1000003

int n , m , z , A[111][111];
int main(){
    cin >> n >> m >> z ;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> A[i][j] ;
        }
    }
    if(max(n,m) > z){
            if(n > m){
                int ans = MOD ;
                for(int i=1;i<=n;i++){
                    int sum = 0 ;
                    for(int j=1;j<=n;j++){
                        int v1 , v2 ;
                        v1 = v2 = 0 ;
                        for(int k=1;k<=m;k++){
                            if(A[i][k] != A[j][k]) v1 ++ ;
                            if(A[i][k] == A[j][k]) v2 ++ ;
                        }
                        sum += min(v1,v2);
                    }
                    ans = min(ans,sum) ;
                }
                if(ans > z) ans = -1 ;
                cout << ans << endl ;
            }else{
                int ans = MOD ;
                for(int i=1;i<=m;i++){
                    int sum = 0 ;
                    for(int j=1;j<=m;j++){
                        int v1 , v2 ;
                        v1 = v2 = 0 ;
                        for(int k=1;k<=n;k++){
                            if(A[k][i] != A[k][j]) v1 ++ ;
                            if(A[k][i] == A[k][j]) v2 ++ ;
                        }
                        sum += min(v1,v2);
                    }
                    ans = min(ans,sum) ;
                }
                if(ans > z) ans = -1 ;
                cout << ans << endl ;
            }
    }else{
        int ans = MOD ;
        for(int i=0;i<(1 << m);i++){
            string s ;
            s += '0' ;
            for(int j=0;j<m;j++){
                s += char(bool(i & (1 << j))+'0');
            }
            int sum = 0 ;
            for(int j=1;j<=n;j++){
                int v1 , v2 ;
                v1 = v2 = 0 ;
                for(int k=1;k<=m;k++){
                    if(s[k] != A[j][k]) v1 ++ ;
                    if(s[k] == A[j][k]) v2 ++ ;
                }
                //cout << v1 << " " << v2 << "\n";
                sum += min(v1,v2);
            }
            ans = min(ans,sum) ;
        }
        if(ans > z) ans = -1 ;
        cout << ans << endl ;
    }
    return 0 ;
}
