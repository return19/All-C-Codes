#include<bits/stdc++.h>
using namespace std;

map<int,int> memo;

int solve(int n)
{
	if(n==0)
		return 0;

	if(memo.find(n)!=memo.end())
		return memo[n];

	int i,ans;

	ans=n-1;

	for(i=1;i<n;i++)
	{
		ans=max(ans,i*solve(n-i));
}

return memo[n]=ans;
}

int main()
{
	int i,j,k;
	int n;

	cin>>n;

	int ans= solve(n);

	cout<<ans<<endl;

	return 0;
}

