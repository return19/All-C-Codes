#include<bits/stdc++.h>
#include "testlib.h"
using namespace std;

int par[101000];

int root(int v){return par[v] < 0 ? v : (par[v] = root(par[v]));}
void merge_dsu(int x,int y){	//	x and y are some tools (vertices)
        if((x = root(x)) == (y = root(y)))     return ;
	if(par[y] < par[x])	// balancing the height of the tree
		swap(x, y);
	par[x] += par[y];
	par[y] = x;
}


int main()
{
	freopen("input09.txt","w",stdout);
	int i,j,k;
	int n = rnd.next(100000-9,100000);
	int m = n-1;

	cout<<n<<" "<<m<<endl;

	for(i=0;i<=n;i++)
        par[i]= -1;

    for(i=1;i<n;){
        int x,y,z;
        x = rnd.next(1,n);
        y = rnd.next(1,n);
        z = rnd.next(1000000-9,1000000);

        if(root(x)!=root(y)){
            cout<<x<<" "<<y<<" "<<z<<endl;
            merge_dsu(x,y);
            i++;
        }
    }

	return 0;
}


















