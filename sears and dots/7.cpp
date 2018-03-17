#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mt make_tuple
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ppii pair< pii,pii >
#define ppll pair< pll,pll >
#define vi vector<int>
#define vll vector< ll >
#define v(x) vector< x >
#define vvi vector< vector< int > >
#define vv(x) vector< vector< x > >

#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)


#else
#define trace(...)
#endif

#define traverse(container, it) for(auto it:container)

#define ft first
#define sd second
#define mp make_pair
#define pb push_back

#define root 1
#define lft (idx << 1)
#define rgt ((idx << 1 ) + 1)
#define cllft lft, st, mid
#define clrgt rgt, mid + 1, ed

#define inf INT_MAX/2
#define linf LLONG_MAX/2

#define all(p) p.begin(), p.end()
#define set(p) memset(p, -1, sizeof(p))
#define clr(p) memset(p, 0, sizeof(p))
#define mem(p, v) memset(p, v, sizeof(p))
#define cpy(d, s) memcpy(d, s, sizeof(s))
#define asst(X,L,R) assert(X >= L && X <= R)

template <class T> T max(T a, T b, T c){ return ( ( a > b ) ? ( ( a > c) ? a : c ) : ( ( b > c ) ? b : c ) ); }
template <class T> T min(T a, T b, T c){ return ( ( a < b ) ? ( ( a < c) ? a : c ) : ( ( b < c ) ? b : c ) ); }

/*
#define gc getchar_unlocked
int rd_int(){ int num=0; char c=gc(); bool flag=0; while(!((c>='0' & c<='9') || c == '-')) c=gc(); if(c=='-'){ flag=1; c=gc(); } while(c>='0' && c<='9'){ num=(num<<1)+(num<<3)+c-'0'; c=gc(); } if(flag) return -num; return num; }
#define pc putchar_unlocked
void wr_int(int num){ if(num<0){pc('-');num=-num;} char snum[20];int i=0;do{snum[i++]=num%10+48;num/=10;}while(num);i--;while(i>=0){pc(snum[i--]);}pc('\n');}
*/

// compiling with gcc11 or above
// g++ -std=c++0x
// Lambdas [capture list](parameters) -> return_type { body }     eg.   auto f = [] (int a,int b) -> int { return a+b; };
// PIE is defined as M_PI

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////MACRO ENDS//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const int MOD = (1e9) + 7 ;
const int MAXN = (1e5) + 9 ;

int T = 1, N = 1;

#define TYPE int
#define MAT vector< vector<TYPE> >

int matrixExponent(MAT &a, int d, int b, int mod) {
    MAT x(d, vector<TYPE> (d, 0) );
    MAT y(d, vector<TYPE> (d) );
    for (int i = 0; i < d; i++) {
        x[i][i] = 1;
    }
    for (int i = 0; i < d; i++) {
        for (int j = 0; j < d; j++) {
            y[i][j] = a[i][j];
        }
    }
    while (b > 0) {
        if (b & 1) {
            //multiplying x and y
            MAT mulmtrx(d, vector<TYPE> (d, 0) );
            for (int i = 0; i < d; i++) {
                for (int j = 0; j < d; j++) {
                    for (int k = 0; k < d; k++) {
                        mulmtrx[i][j] += (x[i][k] * 1LL * y[k][j]) % mod;
                    }
                }
            }
            x = mulmtrx;
        }
        //squaring matrix y
        MAT sqrmtrx(d, vector<TYPE> (d, 0) );
        for (int i = 0; i < d; i++) {
            for (int j = 0; j < d; j++) {
                for (int k = 0; k < d; k++) {
                    sqrmtrx[i][j] += (y[i][k] * 1LL * y[k][j]) % mod;
                }
            }
        }
        y = sqrmtrx;
        b = (b >> 1);
    }
    return x[0][1];
}


MAT matrixexponent(MAT & mat,int d,ll power,ll mod){
    MAT res=mat;
    if(power==1){
        return res;
    }

    res=matrixexponent(mat,d,power/2,mod);

    //squaring matrix res
    MAT sqrmtrx(d,vector<TYPE> (d,0) );
    for(int i=0;i<d;i++){
        for(int j=0;j<d;j++){
            for(int k=0;k<d;k++){
                sqrmtrx[i][j]+=( (res[i][k]%mod) * 1LL * (res[k][j]%mod) )%mod;
            }
        }
    }
    res=sqrmtrx;

    if(power%2==1){
        //multiplying res and mat
        MAT mulmtrx(d,vector<TYPE> (d,0) );
        for(int i=0;i<d;i++){
            for(int j=0;j<d;j++){
                for(int k=0;k<d;k++){
                    mulmtrx[i][j]+=( (res[i][k]%mod) * 1LL * (mat[k][j]%mod) )%mod;
                }
            }
        }
        res=mulmtrx;
    }
    return res;
}

int main() {
    #ifdef ONLINE_JUDGE
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    #endif
    //freopen("input.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //cin >> T;
    while (T--) {
        ll n, m;
        cin >> n >> m;
        vector<int> vec(n);
        for (int i = 0; i < n; i++) {
            cin >> vec[i];
            vec[i]++;
        }
        MAT mat(2, vector<int> (2));
        mat[0][1] = mat[1][0] = mat[1][1] = 1;
        MAT Mat(3, vector<int>(3));
        Mat[0][0] = 1; Mat[1][2] = 1; Mat[2][0] = 1;Mat[2][1] = 1; Mat[2][2] = 1;

        vector< pii > dp(n);
        dp[0].ft = matrixExponent(mat, 2, vec[0] - 1, m);
        if (vec[0] == 2) {
            dp[0].sd = 1;
        }
        else {
            dp[0].sd = matrixExponent(mat, 2, vec[0] - 2, m);
        }

        int foo, bar, foobar;
        int sum = 0, answer = 0;
        MAT res;
        for (int i = 0; i < n; i++) {
            if(i!=0) {
            if (vec[i] == 2) {
                foobar = 1;
            }
            else {
                foobar = matrixExponent(mat, 2, vec[i] - 2, m);
            }
            foo = matrixExponent(mat, 2, vec[i] - 1, m);
            bar = foo + foobar;
            //trace(vec[i], foobar, foo, bar);

            dp[i].ft = (dp[i-1].ft * 1LL * bar + dp[i-1].sd * 1LL* foo + bar) % m;
            dp[i].sd = (dp[i-1].ft * 1LL* foo + dp[i-1].sd * 1LL* foobar + foo) % m;
            }
            sum = 0;
            for (int j = i; j < n; j++) {
                sum += vec[j] - 1;
                if (sum == 0 || sum == 1) {
                    answer += 1;
                    //trace(1);
                }
                else {
                    res = matrixexponent(Mat, 3, sum - 1, m);
                    answer = ((answer + res[2][0]) + res[2][1]) + res[2][2];
                    //trace(sum);
                    //trace(res[2][0] + res[2][1] + res[2][2]);
                    answer = answer % m;
                }
                //trace(ans);
            }
        }
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            //trace(dp[i].ft);
            ans += dp[i].ft;
        }
        ans = ans + ans - (n*(n+1))/2;
        ans = ((ans % m) + m) % m;
        cout << ans  << " " << answer << "\n";
    }
    return 0;
}
