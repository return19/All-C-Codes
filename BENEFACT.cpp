#include<bits/stdc++.h>
using namespace std;

long long n;

vector< vector< pair<long long,long long> > > v;

long long vis[50100];

pair<long long,long long> dfsf(long long x)
{
	vis[x]=1;

	long long mx=0;
	long long mx_idx=x;

	pair<long long,long long> temp;

	long long i,j;

	for(i=0;i<v[x].size();i++)
	{
		if( !vis[v[x][i].first] )
		{
			temp=dfsf(v[x][i].first);

			if(temp.first + v[x][i].second>mx)
			{
				mx=temp.first + v[x][i].second;
				mx_idx=temp.second;
}
}
}

return make_pair(mx,mx_idx);
}


int main()
{
	long long i,j,k;
	long long test,t;

	long long x,y,z;

	scanf("%lld",&test);

	for(t=0;t<test;t++)
	{
		scanf("%lld",&n);

		for(i=0;i<v.size();i++)
			v[i].resize(0);
		v.resize(0);

		v.resize(n);

		for(i=0;i<n-1;i++)
		{
			scanf("%lld%lld%lld",&x,&y,&z);

			x--;
			y--;

			v[x].push_back(make_pair(y,z));
			v[y].push_back(make_pair(x,z));
}

for(i=0;i<n;i++)
	vis[i]=0;

pair<long long,long long> p=dfsf(0);

for(i=0;i<n;i++)
	vis[i]=0;

long long s=p.second;

p=dfsf(s);

printf("%lld\n",p.first);

}

	return 0;
}
