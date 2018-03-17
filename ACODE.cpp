#include<bits/stdc++.h>
using namespace std;

char str[5010];

long long len;

vector<long long> memo;

long long solve(long long idx)
{
	if(idx>=len)
		return 1;
    if(str[idx]=='0')
		return 0;

	if(memo[idx]!=-1)
		return memo[idx];

long long ans=0;

    if(str[idx]!='0')
        ans=solve(idx+1);

	if(  idx+1<len  &&  ( str[idx] - '0' ) * 10 + str[idx+1] - '0' <= 26)
	{
		ans += solve(idx+2);
}

return memo[idx]=ans;
}

int main()
{
	long long n;
	long long i;

	cin>>str;

	n=strlen(str);

	while( ! ( n==1  &&  str[0]=='0') )
	{
		//cin>>str;

		len=strlen(str);

		memo.resize(0);

		for(i=0;i<=len+3;i++)
			memo.push_back(-1);

		long long ans=solve(0);

		cout<<ans<<endl;

		cin>>str;
		n=strlen(str);
    }

    return 0;
}
