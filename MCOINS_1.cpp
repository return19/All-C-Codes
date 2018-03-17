#include<bits/stdc++.h>
using namespace std;

int dp[1000100];

int main()
{
	int n,m,test;

	cin>>n>>m>>test;

	int t,i,j,k;
	int q;

	// preprocess from 1 to 10^6

	dp[0]=1;
	dp[1]=2;

	dp[n]=dp[m]=2;

	int val;

	for(i=1;i<=1000010;i++)
	{
            if(dp[i]==1)
            {

                dp[i+1]=2;

                dp[i+n]=2;

                dp[i+m]=2;

            }
        else
        {
            val=1;

                if( ! dp[i+1])
            {
                dp[i+1]=val;
            }

            if( ! dp[i+n])
            {
                dp[i+n]=val;
            }

            if( ! dp[i+m])
            {
                dp[i+m]=val;
            }
        }

    }

	string ans;

	for(t=0;t<test;t++)
	{
		cin>>q; // input the query

		if(dp[q]==1)
			ans.push_back('B');
		else
			ans.push_back('A');
}

cout<<ans<<endl;

	return 0;
}

