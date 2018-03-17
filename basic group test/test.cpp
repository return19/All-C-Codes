#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;


int main()
{

	freopen("input00.txt","w",stdout);
	int n = rnd.next(10,100);
	int i,j,k;
	cout<<n<<endl;
	for(i=0;i<n;i++){
        int x = rnd.next(-100,99);
        int y = rnd.next(x+1,100);
        int z = rnd.next(1,100);

        cout<<x<<" "<<y<<" "<<z<<endl;
	}
	int q = rnd.next(100,1000);
    cout<<q<<endl;
	for(i=0;i<q;i++){
        int x = rnd.next(-100,99);
        int y = rnd.next(x+1,100);
        cout<<x<<" "<<y<<endl;
	}
	return 0;
}
