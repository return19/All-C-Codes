#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

map< pair<int,int>,int > memo;

int main()
{

	freopen("input11.txt","w",stdout);
	int n = rnd.next(100,200);
	int m = rnd.next(1000,1500);
	int i,j,k;
	cout<<n<<" "<<m<<endl;

    int temp=0;
    while(temp<m){
        int x = rnd.next(1,n);
        int y = rnd.next(1,n);

        if(x!=y && memo[make_pair(x,y)]==0){
            memo[ make_pair(x,y) ]=1;
            cout<<x<<" "<<y<<endl;
            temp++;
        }
    }

	return 0;
}

