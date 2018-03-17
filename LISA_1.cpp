#include<bits/stdc++.h>
using namespace std;

char str[110];

long long n;

pair<long long,long long> memo[110][110];

pair<long long,long long> solve(long long l,long long r)
{
    long long i,j;

   // cout<<l<<" "<<r<<endl;

	if(l>r){
        //cout<<"here1"<<endl;
		return (make_pair(0,0));
	}

	if(l==r)
	{
	    //cout<<"here2"<<endl;
		return make_pair(str[l]-'0',str[l]-'0');
}

if(memo[l][r].first!=-1)
	return memo[l][r];



	long long mn=LLONG_MAX;
	long long mx=LLONG_MIN;

	long long temp1=0,temp2=0;

	for(i=l+1;i<r;i+=2)
	{
		if(str[i]=='+')
		{
		   // cout<<str[i]<<endl;
			temp1=solve(l,i-1).first + solve(i+1,r).first;
			temp2=solve(l,i-1).second + solve(i+1,r).second;
}
else if(str[i]=='*')
{
    //cout<<str[i]<<endl;
	temp1=solve(l,i-1).first * solve(i+1,r).first;
			temp2=solve(l,i-1).second * solve(i+1,r).second;
}

mx=max(mx,temp1);
mn=min(mn,temp2);
}

return memo[l][r]=make_pair(mx,mn);
}

int main()
{
	long long test,t,i,j,k;

	scanf("%lld",&test);

	for(t=0;t<test;t++)
	{
		//scanf("%d",&n);

		scanf("%s",str);

		n=strlen(str);

		//cout<<str<<endl;
		//cout<<n<<endl;

		for(i=0;i<=n;i++)
			for(j=0;j<=n;j++){
				memo[i][j].first=-1;
				memo[i][j].second=-1;
}

pair<long long,long long> ans=solve(0,n-1);

printf("%lld %lld\n",ans.first,ans.second);
}

	return 0;
}

