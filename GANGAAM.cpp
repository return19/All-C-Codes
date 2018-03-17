
#define DEBUG

#include <algorithm>
#include <bitset>
#include <deque>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<string> vs;

// Basic macros
#define st          first
#define se          second
#define all(x)      (x).begin(), (x).end()
#define ini(a, v)   memset(a, v, sizeof(a))
#define re(i,s,n)  	for(int i=s;i<(n);++i)
#define rep(i,s,n)  for(int i=s;i<=(n);++i)
#define fr(i,n)     re(i,0,n)
#define repv(i,f,t) for(int i = f; i >= t; --i)
#define rev(i,f,t)  repv(i,f - 1,t)
#define frv(i,n)    rev(i,n,0)
#define pu          push_back
#define mp          make_pair
#define sz(x)       (int)(x.size())

const int oo = 2000000009;
const double eps = 1e-9;

#ifdef TRACE
    #define trace1(x)                cerr << #x << ": " << x << endl;
    #define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
    #define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
    #define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
    #define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
    #define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#else

    #define trace1(x)
    #define trace2(x, y)
    #define trace3(x, y, z)
    #define trace4(a, b, c, d)
    #define trace5(a, b, c, d, e)
    #define trace6(a, b, c, d, e, f)

#endif

const int mx = 302;
int marked[mx], n;
set<pi> alive;
int a[mx], b[mx];
pi events[2 * mx];

int main() {
    int t, x;
    scanf("%d", &t);
    while(t--) {
        scanf("%d %d", &n, &x);
        fr(i, n) {
            scanf("%d %d", &a[i], &b[i]);
            events[2 * i] = mp(a[i], -i - 1);
            events[2 * i + 1] = mp(b[i], i + 1);
        }
        ini(marked, 0);
        sort(events, events + 2 * n);
        alive.clear();
        fr(j, 2 * n) {
            int i = events[j].se;
            if(i > 0) {
                --i;
                alive.erase(mp(-b[i], i));
                trace2(j, i);
                continue;
            }
            i *= -1; --i;
            alive.insert(mp(-b[i], i));
            trace3(j, -b[i], i);
            if(sz(alive) < x) continue;

            int rem = sz(alive) - x + 1;

            while(rem--) {
                marked[alive.begin()->se] = 1;
                alive.erase(alive.begin());
            }
        }

        int ans = 0;
        fr(i, n) ans += marked[i];
        printf("%d\n", ans);
    }

	return 0;
}
