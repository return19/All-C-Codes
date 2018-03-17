#include<fstream>
#include<algorithm>
#include <iostream>
#include<numeric>
#include<utility>
#include<functional>
#include<stdio.h>
#include<assert.h>
#include<memory.h>
#include<bitset>
#include <stack>
#include <queue>
#include <iterator>
#include <vector>
#include <iterator>
#include <math.h>
#include<cstring>
#include <cmath>
#include <sstream>
#include<cstring>
#include<cstdlib>
#include <set>
#include <cstdio>
#include<map>
#include <cmath>
#include <map>
#define fst first
#define snd second
#define pb push_back
#define fast std::ios_base::sync_with_stdio(false);
#define LL long long
#define endl "\n"
#define lp(i,n) for(int i=0;i<(int)n;i++)
#define all(v)              ((v).begin()), ((v).end())
#define sz(v)               ((int)((v).size()))
#define clr(v, d)           memset(v, d, sizeof(v))
#define rep(i, v)       for(int i=0;i<sz(v);i++)
#define neg(v)       memset(v,-1,sizeof(v))
#define emp(v)       memset(v,0,sizeof(v))
#define rep(i, v)       for(int i=0;i<sz(v);i++)
#define lp1(i,n)    for(int i=1;i<=(int)n;i++)
#define countBits(msk) __builtin_popcount(msk)
using namespace std;
#define FOR(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)

#define readfile freopen("input.txt","r",stdin);
#define writefile ("output.txt","w",stdout);
const double EPS = 1e-6;
LL gcd(LL a, LL b) { if(b==0) return a;   return gcd(b,a%b);  }
LL lcm (LL a, LL b) {   return a*(b/(gcd(a,b)));  }
inline int toInt(string s){int v; istringstream sin(s);sin>>v;return v;}
inline LL toLL(string s){LL v; istringstream sin(s);sin>>v;return v;}
int dcmp(double x, double y) {  return fabs(x-y) <= EPS ? 0 : x < y ? -1 : 1; }
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str();}
typedef pair < int ,int > ii;
#define PIE 3.14159265358979323846
using namespace std;
typedef unsigned long long ull;
LL oo = 312131232;
set<pair<LL,LL> > H;
set<pair<LL,LL> > W;
set<pair<LL,pair<LL,LL> > >  s1;
set<pair<LL,pair<LL,LL> > > s2;
LL X,Y,q;
int main(){
	fast
	cin >> X >> Y;
	H.insert(make_pair(Y,0));
	W.insert(make_pair(X,0));
	s1.insert(make_pair(Y,make_pair(Y,0))); s2.insert(make_pair(X,make_pair(X,0)));
	cin>>q;
	char c;
	LL cut;

	while(q--){

		cin >> c >> cut;
		if(c=='H'){
			typeof(H.begin()) it = H.lower_bound(make_pair(cut,-oo));

			LL start = it->second;
			LL end = it->first;
			H.erase(*it);
			s1.erase(make_pair(end-start,make_pair(end,start)));
			H.insert(make_pair(cut,start));
			H.insert(make_pair(end,cut));
			s1.insert(make_pair(cut-start,make_pair(cut,start)));
			s1.insert(make_pair(end-cut,make_pair(end,cut)));

		}
		else{
			typeof(W.begin()) it = W.lower_bound(make_pair(cut,oo));
			LL start = it->second;
			LL end = it->first;
			W.erase(*it);
			s2.erase(make_pair(end-start,make_pair(end,start)));
			W.insert(make_pair(cut,start)); W.insert(make_pair(end,cut));
			s2.insert(make_pair(cut-start,make_pair(cut,start)));
			s2.insert(make_pair(end-cut,make_pair(end,cut)));
		}

		pair<LL,pair<LL,LL> > r1 = *s1.rbegin();
		pair<LL,pair<LL,LL> > r2  = *s2.rbegin();
		//printf("(%d,%d)--(%d,%d)",r1.first,r1.second,r2.first,r2.second);

		cout << (LL)((r1.first)*(r2.first)) << endl;
	}

}
