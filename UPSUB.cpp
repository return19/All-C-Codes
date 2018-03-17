#include<bits/stdc++.h>
using namespace std;

char str[110];

int dp[110];
int prev[110];

int n;

vector<string> v;

void printrev(string s)
{
	int i,j,n=s.length();

	for(i=0,j=n-1;i<j;i++,j--)
		swap(s[i],s[j]);

    v.push_back(s);

}

void backtrack(int idx,string s)
{
	int i,j;

	s.push_back(str[idx]);

	if(dp[idx]==1)
	{
		printrev(s);

		return;
}

	for(i=idx;i>=0;i--)
	{
		if(str[i]<=str[idx] && dp[i]+1==dp[idx])
		{
			backtrack(i,s);
}
}
}

int main()
{
	int test,i,j,k;
	int t;
	int ans;

	cin>>test;

	for(t=0;t<test;t++)
	{
		cin>>str;
        v.resize(0);

n=strlen(str);

for(i=0;i<n;i++)
{
dp[i]=1;
prev[i]=-1;
}

ans=INT_MIN;

for(i=1;i<n;i++)
{
	for(j=0;j<i;j++)
	{
	if(str[i]>=str[j] && dp[j] +1 > dp[i])
	{
		dp[i] = dp[j] + 1;
		prev[i] = j;
}
}


ans=max( ans , dp[i]);
}

/*
for(i=0;i<n;i++)
    cout<<dp[i]<<" ";
cout<<endl;
*/
for(i=0;i<n;i++)
{
	if(dp[i]==ans)
	{
	    string s="";
		backtrack(i,s);

}
}

    sort(v.begin(),v.end());

    int x=v.size();

    for(i=0;i<x;i++)
        cout<<v[i]<<endl;
}

	return 0;
}
