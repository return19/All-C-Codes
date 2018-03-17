#include<bits/stdc++.h>
using namespace std;

struct elem
{
	int st;
	int ed;
	int price;
};

elem arr[101000];

int n;

int cmp(elem a,elem b)
{
	if(a.st==b.st)
		return a.ed<b.ed;
	return a.st<b.st;
}

int cmp1(elem a,int b)
{
	return a.st<b;
}

int memo[101000];

int solve(int idx)
{
	if(idx>=n)
		return 0;

    if(memo[idx]!=-1)
        return memo[idx];

	int nxt=lower_bound(arr,arr+n,arr[idx].ed,cmp1)-arr;

	//cout<<arr[idx].ed<<" "<<nxt<<endl;

	if(arr[nxt].st<arr[idx].ed)
        nxt++;

	return memo[idx]=max(solve(idx+1), solve(nxt) + arr[idx].price);
}

int main()
{
	int i,j,k;

	int test,t;

	scanf("%d",&test);

	for(t=0;t<test;t++)
	{
		scanf("%d",&n);

		for(i=0;i<n;i++)
		{
		    memo[i]=-1;
			scanf("%d%d%d",&arr[i].st,&arr[i].ed,&arr[i].price);
			arr[i].ed += arr[i].st;
        }

        arr[n].st==INT_MAX;

sort(arr,arr+n,cmp);

int ans=solve(0);

printf("%d\n",ans);
}

	return 0;
}

