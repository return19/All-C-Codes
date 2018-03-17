#include<bits/stdc++.h>
using namespace std;

map<long long,long long> memo;

long long solve(long long n)
{
	if(memo.find(n)!=memo.end())
		return memo[n];

    if(n==1)
        return n;

	return memo[n]=max( n, solve(n/2) + solve(n/3) +  solve(n/4) );
}

int main()
{
	long long n;
	long long i,j,k;

	while(scanf("%lld",&n)!=EOF)
	{
		long long ans=solve(n);

		printf("%lld\n",ans);

		memo.clear();
}

	return 0;
}

