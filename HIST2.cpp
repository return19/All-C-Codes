#include<bits/stdc++.h>
using namespace std;

int n;

int arr[65];

void setn(int &mask,int pos)
{
	mask |= (1<<pos);
}

int memo[66000][21];
int tp[66000][21];

int isSet(int &mask,int pos)
{
	int ans=(1<<pos);

	ans = ans & mask;

	if(ans>=1)
		return 1;
	return 0;
}


pair<int,int> solve(int mask,int prev)
{

	int i,j;
	int ans=INT_MIN;
	int cnt=0;

	if(memo[mask][prev]!=-1)
        return make_pair(memo[mask][prev],tp[mask][prev]);

	for(i=1;i<=n;i++)
	{
		if( ! isSet(mask,i))
		{
			j=mask;
setn(j,i);

			if(j!=((1<<(n+1))-2))
			{
				pair<int,int> temp= solve(j,i);

				temp.first +=abs(arr[prev] - arr[i]);

				if(temp.first>ans)
				{
		ans=temp.first;		cnt=temp.second;
}
else if(temp.first==ans)
	cnt+=temp.second;

}
			else
{
	int temp= abs(arr[prev]-arr[i]) + arr[i];

	return make_pair(temp,1);
}


}
}
memo[mask][prev]=ans;
tp[mask][prev]=cnt;

return make_pair(ans,cnt);
}

int main()
{
	int i,j,k;

	cin>>n;

	//cout<<(1<<(n+1))-2<<endl;

	while(n!=0)
	{
	    for(i=0;i<=(1<<(n+1));i++)
        {
            for(j=0;j<=n;j++)
                memo[i][j]=-1;
        }

		for(i=1;i<=n;i++)
			cin>>arr[i];

        arr[0]=0;

		pair<int,int> ans=solve(0,0);

		cout<<ans.first + 2*(n)<<" "<<ans.second<<endl;

		cin>>n;
}

	return 0;
}
