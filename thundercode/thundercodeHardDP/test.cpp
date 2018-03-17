#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

int main()
{

	freopen("input08.txt","w",stdout);
	int n = rnd.next(8,10);
	int m = rnd.next(8,10);
	int money = rnd.next(8,100);
	int k = rnd.next(8,10);

	cout<<n<<" "<<m<<" "<<money<<" "<<k<<endl;
    int i,j;
	for(i=0;i<n;i++)
        cout<<rnd.next(8,100)<<" ";
    cout<<endl;

    for(i=0;i<n;i++)
        cout<<rnd.next(8,10)<<" ";
    cout<<endl;

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            cout<<rnd.next(8,100)<<" ";
        cout<<endl;
    }

    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            cout<<rnd.next(8,100)<<" ";
        cout<<endl;
    }

	return 0;
}


