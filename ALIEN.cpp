#include<bits/stdc++.h>
using namespace std;

long long arr[101000];

int main()
{
	long long test,t,i,j,k;
	long long mx;
	long long sum_till;

	long long ans=0;
	long long min_sum;
	long long n;

	scanf("%lld",&test);

	for(t=0;t<test;t++)
	{
		scanf("%lld%lld",&n,&mx);

		for(i=0;i<n;i++)
			scanf("%lld",&arr[i]);

		min_sum=LLONG_MAX;
		ans=0;
		sum_till=0;

		j=0;

		for(i=0;i<n;i++)
		{
			sum_till += arr[i];

			while(sum_till>mx)
			{
				sum_till -= arr[j];
				j++;
}

if(i-j+1>ans)
{
	ans=i-j+1;
	min_sum=sum_till;
}
else if(i-j+1==ans)
{
	if(min_sum>sum_till)
		min_sum=sum_till;
}
}

if(min_sum!=LLONG_MAX)
printf("%lld %lld\n",min_sum,ans);
else
    printf("0 0\n");
}

	return 0;
}

