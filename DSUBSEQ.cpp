#include<bits/stdc++.h>
using namespace std;

char str[101000];

long long c[26];

long long M=1000000007;

int main()
{
	long long i,j,k;

	long long test,t;

	long long n;

	long long temp,ans;

	scanf("%lld",&test);

	for(t=0;t<test;t++)
	{
		scanf("%s",str);

		memset(c,0,sizeof(c));

		ans=2;

		c[str[0]-'A']=1;

		n=strlen(str);

		for(i=1;i<n;i++)
		{
			temp=ans;

			ans = (ans*2)%M;

			ans = (ans - c[str[i] - 'A'] + M)%M;

			c[str[i] - 'A'] = temp;
}

printf("%lld\n",ans%M);
}

	return 0;
}

