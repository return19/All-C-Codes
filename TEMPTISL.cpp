#include<bits/stdc++.h>
using namespace std;

long long d1,n;

map< pair<long long,long long>,long long > memo;

long long solve(long long cur,long long k)
{
    if(cur==0)
        cur=n;
    else if(cur==n+1)
        cur=1;

	if(k==0)
	{
		if(cur==d1)
			return 1;
		return 0;
}

if(memo.find(make_pair(cur,k))!=memo.end())
	return memo[make_pair(cur,k)];

	return memo[make_pair(cur,k)]=solve(cur + 1,k-1) + solve(cur-1,k-1);
}

int main()
{
	long long i,j;
	long long k;
	long long st,dt;

	cin>>n>>k;

	while(n!=-1&&k!=-1)
	{
	    memo.clear();

		cin>>st>>dt;

		d1=dt;

	//cout<<d1<<" "<<d2<<endl;

	long long ans=solve(st,k);

	cout<<ans<<endl;

	cin>>n>>k;

}


	return 0;

}

