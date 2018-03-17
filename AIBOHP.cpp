#include<bits/stdc++.h>
using namespace std;

char str[601000];
char rev[601000];

int dp[6110][6110];

int main()
{
	int i,j,k;

	int test,t;

	int n;

	scanf("%d",&test);

	for(t=0;t<test;t++)
	{
		scanf("%s",str);

	n=strlen(str);

	for(i=n-1,j=0;i>=0;i--,j++)
	{
		rev[j]=str[i];
}

rev[n]='\0';

for(i=0;i<=n;i++)
{
	dp[i][0]=0;
	dp[0][i]=0;
}

for(i=1;i<=n;i++)
{
	for(j=1;j<=n;j++)
	{
		if(str[i-1]==rev[j-1])
		{
			dp[i][j] = dp[i-1][j-1] + 1;
}
else
	dp[i][j] = max( dp[i-1][j],dp[i][j-1] );
}
}



printf("%d\n",n-dp[n][n]);
}

	return 0;
}

