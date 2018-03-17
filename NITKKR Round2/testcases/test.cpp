#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

char arr[510][510];
map< pair<int,int>,int > memo;

int main()
{

	freopen("input10.txt","w",stdout);
    int i,j;
    int n,m;
    n = rnd.next(1000000-61,1000000); // 10^6
    m = rnd.next(1000000-61,1000000); // 10^6

    cout<<n<<" "<<m<<endl;

    for(i=0;i<n;i++)
        printf("%lld ",rnd.next((long long)1e13,(long long)1e14)); // 10^14
    cout<<endl;

	return 0;
}


	/*int i,j;
	int sx,sy;
	int m = rnd.next(500-5,500);
	int n = rnd.next(500-5,500);
	cout<<m<<" "<<n<<endl;
	sx = rnd.next(1,m);
	sy = rnd.next(1,n);
	cout<<sx<<" "<<sy<<endl;

	for(i=1;i<=m;i++)
        for(j=1;j<=n;j++)
            arr[i][j]='.';

    int num = 1550;

    for(i=0;i<num;i++){
        int x = rnd.next(1,m);
        int y = rnd.next(1,n);

        arr[x][y] = 'P';
    }

    for(i=0;i<num;i++){
        int x = rnd.next(1,m);
        int y = rnd.next(1,n);

        arr[x][y] = 'S';
    }

    for(i=0;i<num;i++){
        int x = rnd.next(1,m);
        int y = rnd.next(1,n);

        arr[x][y] = 'T';
    }

    for(i=0;i<num;i++){
        int x = rnd.next(1,m);
        int y = rnd.next(1,n);

        arr[x][y] = 'C';
    }

    for(i=1;i<=m;i++)
    {
        for(j=1;j<=n;j++)
            cout<<arr[i][j];
        cout<<endl;
    }*/
