#include<bits/stdc++.h>
using namespace std;

int n;

int move_x[11]={0,-1,-1,0,1,1};
int move_y[11]={-2,-1,1,2,1,-1};

map< pair< pair<int,int>,int >,int > memo;

int solve(int x,int y,int k)
{
	if(k==0)
	{
		if(x==0&&y==0)
			return 1;
		return 0;
}

if(memo.find(make_pair(make_pair(x,y),k))!=memo.end())
	return memo[make_pair(make_pair(x,y),k)];

int i,j;

int tx,ty;
int ans=0;

for(i=0;i<6;i++)
{
	tx=x+move_x[i];
	ty=y+move_y[i];

	ans+=solve(tx,ty,k-1);
}

return memo[make_pair(make_pair(x,y),k)]=ans;
}

int main()
{
	int i,j,k;
	int test,t;

	scanf("%d",&test);

	for(t=0;t<test;t++)
	{
		scanf("%d",&n);

		int ans=solve(0,0,n);

		printf("%d\n",ans);
}

return 0;
}

