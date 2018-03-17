#include<bits/stdc++.h>
using namespace std;

char str[110];

int n;

int c=0;

int checkmask(int mask,int pos)
{
	if(pos==0)
	{
		if(mask&1)
			return 1;
		return 0;
}
else
{
	if(mask&(1<<pos))
		return 1;
	return 0;
}
}

void maskit(int &mask,int pos)
{
	if(pos==0)
	{
		mask = mask|1;
}
else
	mask = mask | (1<<pos);
}

void printAll(int idx,int mask,string word)
{
	if(idx==n)
	{
		cout<<++c<<" "<<word<<endl;
}
else
{
	int i;

	for(i=0;i<n;i++)
	{
		if (  ! checkmask(mask,i) )
		{
			int temp=mask;
			maskit(temp,i);

			printAll(idx + 1,temp,word + str[i]);
}
}
}
}

int main()
{
	int i,j,k;

	cin>>str;

	n=strlen(str);

	printAll(0,0,"");

	return 0;
}

