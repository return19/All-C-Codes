#include<bits/stdc++.h>
using namespace std;

int n;

int pos[21];
int cor[21];

inline int dist(int x,int y,int a,int b)
{
	return abs(x-a) + abs(y-b);
}

inline int ismasked(int mask,int pos)
{
	if(mask & (1<<pos) )
		return 1;
	return 0;
}

inline void maskit(int &mask,int pos)
{
	mask |= (1<<pos);
}

int memo[1<<18];

int solve(int row,int mask)
{
	if(row>n)
	{
		return 0;
}

if(memo[mask]!=-1)
    return memo[mask];

int i,j,k;
int temp;

int ans=INT_MAX;

for(i=1;i<=n;i++)
{
	if( ! ismasked(mask,i))
	{
		temp=mask;
		maskit(temp,i);

		ans = min( ans, dist(row,pos[row] , i,cor[i]) + solve(row+1,temp) );
}
}

return memo[mask]=ans;
}

int main()
{
	int i,j,k;

scanf("%d",&n);

while(n!=0)
{
	for(i=1;i<=n;i++)
	{
		scanf("%d",&pos[i]);
}

for(i=1;i<=n;i++)
{
	scanf("%d",&cor[i]);
}

int mask=0;

int l=1<<(n+1);

for(i=0;i<l;i++)
    memo[i]=-1;

int ans=solve(1,mask);

printf("%d\n",ans);



	scanf("%d",&n);
}

	return 0;
}

