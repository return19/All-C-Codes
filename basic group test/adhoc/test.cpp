#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;


int main()
{

	freopen("input07.txt","w",stdout);
	int test = rnd.next(2-1,4);
	int i,j,k;

    cout<<test<<endl;

	for(int t=0;t<test;t++){
        int n = rnd.next(200000-71,200000-22);
        cout<<n<<endl;
        for(i=0;i<n;i++){
            int a = rnd.next(0,1);
            cout<<a<<" ";
        }
        cout<<endl;
	}

	return 0;
}
