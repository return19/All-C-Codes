#include<bits/stdc++.h>
using namespace std;

long long arr[10100];

long long n;

long long memo[2010][2010];

long long solve(long long l,long long r)
{
	if(l>r)
		return 0;

	if(memo[l][r]!=-1)
		return memo[l][r];

	return memo[l][r]=max((n-(r-l+1) + 1)*arr[l] + solve(l+1,r), solve(l,r-1) + (n-(r-l+1) + 1)*arr[r]);
}

int main()
{
	long long i,j,k;

	scanf("%lld",&n);

	for(i=0;i<n;i++)
	{
		scanf("%lld",&arr[i]);
}

for(i=0;i<=n;i++)
	for(j=0;j<=n;j++)
		memo[i][j]=-1;

long long ans=solve(0,n-1);

printf("%lld\n",ans);

	return 0;
}
