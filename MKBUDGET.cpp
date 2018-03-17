#include<bits/stdc++.h>
using namespace std;

long long n,h,m,f;

long long arr[510];

long long memo[31][501];

long long solve(long long cur_month,long long cur_emp)
{
	if(cur_month==n)
		return 0;

	long long ans=LLONG_MAX;

	if(memo[cur_month][cur_emp]!=-1)
		return memo[cur_month][cur_emp];

	if(cur_emp<arr[cur_month])
	{
		return memo[cur_month][cur_emp]=arr[cur_month]*m + (arr[cur_month] - cur_emp)*h +solve(cur_month + 1, arr[cur_month]);
}
else
{
	long long i;

	for(i=cur_emp;i>=arr[cur_month] ; i--)
	{
		ans=min(ans, (cur_emp - i)*f + i*m + solve(cur_month + 1, i) );
}

return memo[cur_month][cur_emp]=ans;
}
}

int main()
{
	long long test,t,i,j,k;
	long long mx_emp=LLONG_MIN,cn=1;

	scanf("%lld",&n);

	while(n!=0)
	{
		//cin>>h>>m>>f;

        scanf("%lld%lld%lld",&h,&m,&f);

		mx_emp=LLONG_MIN;

		for(i=0;i<n;i++){
			scanf("%lld",&arr[i]);

			mx_emp=max(mx_emp,arr[i]);
}

for(i=0;i<=n;i++)
	for(j=0;j<=mx_emp + 10 ;j++)
		memo[i][j]=-1;

		long long ans=solve(0,0);

		printf("Case %lld, cost = $%lld\n",cn,ans);
		cn++;

		scanf("%lld",&n);

}

	return 0;
}

