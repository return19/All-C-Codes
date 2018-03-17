#include<bits/stdc++.h>
using namespace std;

int n,k,t;
int arr[510];

//map< pair<int,int>,int > memo;
int memo[510][510];
int vis[510][510];

int solve(int idx,int k)
{
	int i,j;

	if(k==0)
        return 0;

	if(idx==n)
		return 0;

//if(memo.find(make_pair(idx,k))!=memo.end())
  //  return memo[make_pair(idx,k)];

    if(vis[idx][k]==1)
        return memo[idx][k];
    vis[idx][k]=1;

	int mn;
	int ans=INT_MIN;

	for(i=idx;i<n-(k-1);i++)
    {
        mn=INT_MAX;
		for(j=i;j>=idx&&j>i-t;j--)
		{
			mn=min(mn,arr[j]);
			ans=max(ans , (i-j+1)*mn + solve(i+1,k-1));
        }
    }

return memo[idx][k]=ans;
}

int main()
{
	int i,j;

	cin>>n>>k>>t;

	for(i=0;i<n;i++)
		cin>>arr[i];

	int ans=solve(0,k);

	cout<<ans<<endl;

	return 0;
}

