#include<bits/stdc++.h>
using namespace std;

int n,k;

int arr[110];

int memo[110][110][110];

int solve(int idx,int cur_app,int w)
{

	if(idx>k)
	{
		if(w==0)
		{
			return 0;
}
return INT_MIN;
}

if(w==0)
	return 0;
else if(w<idx)
	return INT_MIN;

if(memo[idx][cur_app][w]!=-1)
	return memo[idx][cur_app][w];

int tk=0,nt=0;

int temp;

if(arr[idx]==-1){
	return memo[idx][cur_app][w]=solve(idx+1,cur_app,w);

}

tk=solve(idx+1,cur_app-1,w-idx);

if(tk!=INT_MIN)
    tk+=arr[idx];

nt= solve(idx+1,cur_app,w);

if(tk==INT_MIN)
    return nt;

if(nt==INT_MIN)
    return tk;

return memo[idx][cur_app][w]=min( nt,tk );

}

int main()
{
	int test,t,i,j;
	int x;

	scanf("%d",&test);

	for(t=0;t<test;t++)
	{
		scanf("%d%d",&n,&k);

		for(i=0;i<=k;i++)
			for(j=0;j<=k+5;j++)
				for(x=0;x<=k;x++)
					memo[i][j][x]=-1;

		for(i=1;i<=k;i++)
			scanf("%d",&arr[i]);



		int ans=solve(1,k+1,k);


        if(ans!=INT_MIN)
		printf("%d\n",ans);
		else
            printf("-1\n");
}

	return 0;
}

