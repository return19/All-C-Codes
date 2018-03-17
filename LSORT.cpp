#include<bits/stdc++.h>
using namespace std;

long long arr[1010];
long long n;


long long dp[1010][1010];

long long lft[1010][1010];
long long right[1010][1010];

long long solve(long long st,long long ed)
{
	if(st==1&&ed==n)
		return 0;

	if(dp[st][ed]!=-1)
		return dp[st][ed];

	if(st==1)
	{
		return dp[st][ed]=(ed-st+2)*lft[ed+1][st] + solve(st,ed+1);
}
else if(ed==n)
{
	return dp[st][ed]=(ed-st+2)*lft[st-1][ed] + solve(st-1,ed);
}

	return dp[st][ed]=min( (ed-st+2)*lft[st-1][ed] + solve(st-1,ed) , (ed-st+2)*lft[ed+1][st] +solve(st,ed+1)  );
}

int main()
{
	long long test,t,i,j,k;
	long long temp;
	cin>>test;

	for(t=0;t<test;t++)
	{
		cin>>n;

		for(i=0;i<=n;i++)
			for(j=0;j<=n;j++)
				dp[i][j]=-1;

		for(i=1;i<=n;i++)
		{
			cin>>temp;
			arr[temp]=i;
        }

        for(i=1;i<=n;i++)
        {
            lft[i][i]=arr[i];
            for(j=i+1;j<=n;j++)
            {
                if(arr[j]<arr[i])
                    lft[i][j]=lft[i][j-1] - 1;
                else
                    lft[i][j]=lft[i][j-1];
            }
        }


        for(i=1;i<=n;i++)
        {
            for(j=i-1;j>=1;j--)
            {
                if(arr[j]<arr[i])
                    lft[i][j]=lft[i][j+1] - 1;
                else
                    lft[i][j]=lft[i][j+1];
            }
        }


		long long ans=LLONG_MAX;

		for(i=1;i<=n;i++)
		{
			ans=min(ans,arr[i] + solve(i,i));
			//cout<<i<<" "<<arr[i] + solve(i,i)<<endl;
        }

       /* for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
                cout<<dp[i][j]<<" ";
            cout<<endl;
        }*/

cout<<ans<<endl;
}
	return 0;
}

