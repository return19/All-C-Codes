#include<bits/stdc++.h>
using namespace std;

vector< vector<int> > v;

vector<int> dp;

int solve(vector<int> &A)
{
	int n=A.size();

	int i,j,k;
	int in,ex;

in=A[0];
ex=0;

int temp;

	for(i=1;i<n;i++)
	{
		temp=max(in,ex);

		in=ex + A[i];
		ex=temp;
}

return max(in,ex);
}

int main()
{
	int n,m;
	int i,j,k;

	scanf("%d%d",&n,&m);

	while(n!=0&m!=0)
	{
		v.resize(n);
		for(i=0;i<n;i++)
			v[i].resize(m);

		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				scanf("%d",&v[i][j]);

		dp.resize(0);

		for(i=0;i<n;i++)
			dp.push_back(solve(v[i]));

		printf("%d\n",solve(dp));

		scanf("%d%d",&n,&m);
}

return 0;
}

