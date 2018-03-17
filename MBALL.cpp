#include<bits/stdc++.h>
using namespace std;

long long n;

/*map< vector<long long>,long long > memo;

long long solve(long long n,long long s,long long f,long long t1,

                long long t2,


                long long t3)
{
	vector<

	long long> v;
    v.push_back(s);
    v.push_back(f);
    v.push_back(t1);
    v.push_back(t2);
    v.push_back(t3);


	if(n==0)
	{
	   if(memo.find(v)==memo.end())
		{
            memo[v]=1;
            return 1;
        }
        return 0;
    }
	if(n<0)
		return 0;

	return memo[v]=(solve(n-2,s+1,f,t1,t2,t3) + solve(n-3,s,f+1,t1,t2,t3) +
solve(n-6,s,f,t1+1,t2,t3)
 	+ solve(n-6-1,s,f,t1,t2+1,t3) + solve(n-6-2,s,f,t1,t2,t3+1));


}*/

long long dp[101000];
long long opt[10];

int main()
{
	long long test,t,i,j,k;

	cin>>test;

	opt[0]=2;
	opt[1]=3;
	opt[2]=6;
	opt[3]=7;
	opt[4]=8;

        dp[0]=1;

        for(i=0;i<=4;i++)
        {
            for(j=i;j<101000;j++)
            {
                if(dp[j-opt[i]]>0)
                    dp[j]+=dp[j-opt[i]];
            }
        }

	for(t=0;t<test;t++)
	{
		//memo.clear();
		cin>>n;

        long long ans=dp[n];
		//int ans=solve(n,0,0,0,0,0);

		cout<<ans<<endl;
}

	return 0;
}

