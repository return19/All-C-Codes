#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;


int main()
{
	freopen("input10.txt","w",stdout);
	int n = rnd.next(990,1000);
	int s = rnd.next(1,n);
    int i;

    cout<<n<<" "<<s<<endl;

    for(i=0;i<n;i++){
        int a = rnd.next(100000-10,100000);
        cout<<a<<" ";
    }
    cout<<endl;

	return 0;
}
