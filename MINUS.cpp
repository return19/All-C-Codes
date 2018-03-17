#include<bits/stdc++.h>
using namespace std;

int arr[110];

int n,m;

int solve(int idx,int sum)
{
	if(idx>n)
		return 0;

	if(idx==n)
	{
		if(sum==0)
			return 1;
		return 0;
    }

    if(idx==n-1)
    {
        if(sum==arr[idx])
            return 1;
        return 0;
    }

int tk=0;
int nt=0;

tk=solve(idx+2,(arr[idx]-arr[idx+1]) - sum);

if(tk==1)
{
	printf("%d\n",idx+1);

	if(idx<n-2)
        printf("%d\n",idx+1);

	return 1;
}

nt=solve(idx+1,arr[idx]-sum);

if(nt==1)
	{
		printf("%d\n",idx+1);
		return 1;
}

return 0;
}

int main()
{
	int i,j,k;

	int test,t;

	scanf("%d",&test);

	for(t=0;t<test;t++)
	{
		scanf("%d%d",&n,&m);

		for(i=0;i<n;i++)
			scanf("%d",&arr[i]);

		solve(0,m);

		printf("\n");
}

	return 0;
}

