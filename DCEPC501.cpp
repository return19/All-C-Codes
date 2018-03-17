#include<bits/stdc++.h>
using namespace std;

long long n;

long long arr[101000];

long long memo[101000];

long long solve(long long idx)
{
	if(idx>=n)
		return 0;

	if(memo[idx]!=-1)
		return memo[idx];

	long long one=0,two=0,three=0;

	one=arr[idx] + solve(idx+2);

	if(idx+1<n)
		two = arr[idx] + arr[idx+1]  + solve(idx+4);

	if(idx+2<n)
		three= arr[idx] + arr[idx+1] + arr[idx +2] + solve(idx+6);

	return memo[idx]=max(max(one,two),three);
}

int main()
{
	long long test,t,i,j,k;

	scanf("%lld",&test);

	for(t=0;t<test;t++)
	{
		scanf("%lld",&n);

		for(i=0;i<n;i++)
		{
			memo[i]=-1;
			scanf("%lld",&arr[i]);
}

long long ans=solve(0);

printf("%lld\n",ans);
}

	return 0;
}

