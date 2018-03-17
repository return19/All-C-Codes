#include<bits/stdc++.h>
using namespace std;

int arr[1010];

int n,k;

int memo[1010][1010];

int solve(int idx,int k)
{
	if(idx==n)
		return 0;

	if(memo[idx][k]!=-1)
		return memo[idx][k];

	int tk=0,nt=0;

	if(k>=arr[idx])
		tk=arr[idx] + solve(idx+2,k-arr[idx]);

	nt=solve(idx+1,k);

	if(k-tk<=k-nt)
		return memo[idx][k]=tk;
	return memo[idx][k]=nt;
}

int main()
{
	int i,j,test,t;

	cin>>test;

	for(t=0;t<test;t++)
	{
		cin>>n>>k;

		for(i=0;i<n;i++)
			cin>>arr[i];

		for(i=0;i<=n;i++)
			for(j=0;j<=k;j++)
				memo[i][j]=-1;

		int ans=solve(0,k);

		printf("Scenario #%d: %d\n",t+1,ans);
}

	return 0;
}
