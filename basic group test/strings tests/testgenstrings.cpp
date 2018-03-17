#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;


int main()
{
	freopen("input06.txt","w",stdout);
	int test = rnd.next(10,11);
	cout<<test<<endl;
	int i,j,k;


    for(i=0;i<test;i++){
        int n = rnd.next(99991,100000);

        for(j=0;j<n;j++){
            int c = rnd.next(97,122);
            cout<<(char)c;
        }
        cout<<endl;
    }

	return 0;
}

