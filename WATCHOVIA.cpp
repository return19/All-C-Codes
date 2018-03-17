#include<bits/stdc++.h>
using namespace std;

int w[61];
int m[61];

int n;

int memo[61][1010];

int solve(int idx,int k)
{
	if(idx==n)
		return 0;
	if(memo[idx][k]!=-1)
		return memo[idx][k];

	if(k>=w[idx])
		return memo[idx][k]=max( solve(idx+1,k) , solve(idx+1,k-w[idx]) + m[idx] );
	return memo[idx][k]=solve(idx+1,k);
}

int main()
{
	int test,i,j,k,t;

	scanf("%d",&test);

	for(t=0;t<test;t++)
	{
                scanf("%d%d",&k,&n);

                for(i=0;i<n;i++)
                {
                    scanf("%d%d",&w[i],&m[i]);
        }

        for(i=0;i<=n;i++)
            for(j=0;j<=k;j++)
                memo[i][j]=-1;

        int ans=solve(0,k);

        printf("Hey stupid robber, you can get %d.\n",ans);
}

	return 0;
}

