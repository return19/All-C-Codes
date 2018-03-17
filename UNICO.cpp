#include<bits/stdc++.h>
using namespace std;

char str[1010000];

int count1[256];

int main()
{
	int n,i,j,k;
	int ans;
int st,ed;
int x,y;
int test,t;

scanf("%d",&test);

for(t=0;t<test;t++)
{

    memset(count1,0,sizeof(count1));
	scanf("%s",str);

	n=strlen(str);

	st=0;
x=0;
ans=0;

	for(i=0;i<n;i++)
	{
		if(count1[str[i]]==0)
{
	count1[str[i]]++;
}
else
{
    count1[str[i]]++;
	if(i-x>ans)
	{
		ans=i-x;
		st=x;
		ed=i-1;
}

while(count1[str[i]]>1)
{
	count1[str[x]]--;
	x++;
}

}
}

if(n-x>ans)
{
	ans=n-x;
	st=x;
	ed=n-1;
}

for(i=st;i<=ed;i++)
	printf("%c",str[i]);
printf("\n");
}


	return 0;
}

