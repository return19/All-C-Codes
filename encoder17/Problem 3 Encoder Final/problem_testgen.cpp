#include<bits/stdc++.h>
using namespace std;
#define M (int)1e6
void solve()
{
	int n=rand()%100+1,m=rand()%100+1;
	int i,j,temp,x,y;
	printf("%d %d\n",n,m);
	char a[n][m];
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			temp=rand()%2;
			if(temp) a[i][j]='#';
			else a[i][j]='C';
		}
	}
	x=rand()%n;y=rand()%m;
	a[x][y]='B';
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			printf("%c",a[i][j]);
		}
		printf("\n");
	}
	x=rand()%M;y=rand()%M;
	printf("%d %d\n",x,y);
	x=rand()%M;y=rand()%M;
	printf("%d %d\n",x,y);
}
int main()
{
	solve();
}
