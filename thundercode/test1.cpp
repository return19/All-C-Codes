#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

map< pair<long long,long long>,long long > memo;

int main()
{

	freopen("input10.txt","w",stdout);
	long long one = 91000, mx = 100000;

	long long n = rnd.next(one,mx);
	long long m = rnd.next(91000,100000);
	long long cost = rnd.next(5,1000000000);

	cout<<n<<" "<<m<<endl;
	cout<<cost<<endl;

    long long temp=0;
    while(temp<m){
        long long x = rnd.next(one,n);
        long long y = rnd.next(one,n);

        if(x!=y && memo[ make_pair(min(x,y),max(x,y)) ] ==0){
            memo[make_pair(min(x,y),max(x,y))]=1;
            cout<<x<<" "<<y<<endl;
            temp++;
        }
    }

	return 0;
}



