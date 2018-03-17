#include<bits/stdc++.h>
using namespace std;

int dp[110][110];
int bt[110][110];

char a[110];
char b[110];

char lcs[110];

int main()
{
	int i,j,k;
	int n1,n2;

	while((scanf("%s",a))!=EOF)
	{
		scanf("%s",b);

		n1=strlen(a);
		n2=strlen(b);

		for(i=0;i<=n1;i++)
			dp[i][0]=0;
		for(j=0;j<=n2;j++)
			dp[0][j]=0;

		for(i=1;i<=n1;i++)
		{
			for(j=0;j<=n2;j++)
			{
				if(a[i-1]==b[j-1])
				{
					dp[i][j] = dp[i-1][j-1] + 1;
					bt[i][j]=2;
}
else
{
	if(dp[i-1][j]>dp[i][j-1])
	{
		dp[i][j]=dp[i-1][j];
		bt[i][j]=3;
}
else
{
	dp[i][j]=dp[i][j-1];
	bt[i][j]=1;
}
}
}
}

j=n1;
k=n2;

for(i=dp[n1][n2]-1;i>=0;)
{
	if(bt[j][k]==2)
	{
		lcs[i]=a[j-1];
		i--;
		j--;
		k--;
}
else if(bt[j][k]==1)
{
	k--;
}
else
	j--;
}

lcs[dp[n1][n2]]='\0';

j=0;
k=0;

//cout<<lcs<<endl;

for(i=0;i<dp[n1][n2];i++)
{
	while(j<n1  &&  a[j]!=lcs[i])
	{
		printf("%c",a[j]);
		j++;
}
while(k<n2  &&  b[k]!=lcs[i])
{
	printf("%c",b[k]);
	k++;
}
j++;
k++;
printf("%c",lcs[i]);
}

	while(j<n1)
	{
		printf("%c",a[j]);
		j++;
}
while(k<n2)
{
	printf("%c",b[k]);
	k++;
}



printf("\n");

}

	return 0;
}
