#include<bits/stdc++.h>
using namespace std;

vector<int> v;

void solve(int m,int n,int &k)
{
	int i,j;

	if(m==0)
	{
		if(n==0)
		{
			k--;
}

return;
}

if(n==0)
{
	return;
}

for(i=1;i<=m;i++)
{
	solve(m-i,n-1,k);
	if(k==0)
	{
		v.push_back(i);
		return;
}
}
}

int main()
{
	int test,t,i,j;
	int m,n,k;
	//int ans;

	cin>>test;

	for(t=0;t<test;t++)
	{
cin>>m>>n>>k;

v.resize(0);

solve(m,n,k);

for(i=v.size()-1;i>=0;i--)
	cout<<v[i]<<" ";
cout<<endl;

//cout<<ans<<endl;
}

	return 0;
}

