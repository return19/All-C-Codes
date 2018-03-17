#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;


int main()
{
	freopen("input10.txt","w",stdout);
	int n = rnd.next(200000-35,200000-28);
	cout<<n<<endl;
	int i,j,k;
    int cur = 1;
	for(i=1;i<=n;i++){
        cur = max(cur,i);
        int a = rnd.next(cur, min(cur+2,n));
        cur = max(cur,a);
        cout<<a<<" ";
	}
	cout<<endl;
	return 0;
}

