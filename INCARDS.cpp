#include<bits/stdc++.h>
using namespace std;

long long n,e;

vector< vector< pair<long long,long long> > > v1;
vector< vector< pair<long long,long long> > > v2;

set< pair<long long,long long> > q;

long long dist1[1010000];
long long dist2[1010000];

long long vis[1010000];

void dijkstra1()
{
	long long i,j,k;

	pair<long long,long long> p;

	long long x,mn;

	q.insert(make_pair(0,0));
   // cout<<" here "<<endl;
	while( ! q.empty() )
	{
		p=*q.begin();
		q.erase(q.begin());



		x=p.second;
		mn=p.first;

		vis[x]=1;
        //cout<<"inside "<<x<<endl;
		for(i=0;i<v1[x].size();i++)
		{
		   // cout<<"f"<<i<<endl;
			if( !vis[v1[x][i].first] && dist1[v1[x][i].first] > v1[x][i].second + mn)
			{
				if(dist1[v1[x][i].first]!=LLONG_MAX)
				q.erase(q.find(make_pair( dist1[v1[x][i].first], v1[x][i].first)));
				 //cout<<"after"<<endl;
				 dist1[v1[x][i].first]=v1[x][i].second + mn;

				q.insert(make_pair(dist1[v1[x][i].first] , v1[x][i].first));


}
}
}

}

void dijkstra2()
{
	long long i,j,k;

	pair<long long,long long> p;

	long long x,mn;

	q.insert(make_pair(0,0));
     //cout<<" here "<<endl;
	while( ! q.empty() )
	{
		p=*q.begin();
		q.erase(q.begin());

		x=p.second;
		mn=p.first;

		vis[x]=1;

		for(i=0;i<v2[x].size();i++)
		{
			if( !vis[v2[x][i].first] && dist2[v2[x][i].first] > v2[x][i].second + mn)
			{
			    if(dist2[v2[x][i].first]!=LLONG_MAX)
                    q.erase(q.find(make_pair( dist2[v2[x][i].first], v2[x][i].first)));
				dist2[v2[x][i].first]=v2[x][i].second + mn;

				q.insert(make_pair(dist2[v2[x][i].first] , v2[x][i].first));

}
}
}
}

int main()
{
	long long test,t,i,j,k;
	long long x,y,z;

	scanf("%lld",&test);

	for(t=0;t<test;t++)
	{
		scanf("%lld%lld",&n,&e);

		for(i=0;i<v1.size();i++)
			v1[i].resize(0);
		v1.resize(0);

		v1.resize(n);

for(i=0;i<v2.size();i++)
			v2[i].resize(0);
		v2.resize(0);

		v2.resize(n);

		for(i=0;i<e;i++)
		{
			scanf("%lld%lld%lld",&x,&y,&z);

x--;
y--;

v1[x].push_back(make_pair(y,z));
v2[y].push_back(make_pair(x,z));
}

for(i=0;i<n;i++){
	vis[i]=0;
	dist1[i]=LLONG_MAX;
}

dist1[0]=0;

dijkstra1();

for(i=0;i<n;i++){
	vis[i]=0;
	dist2[i]=LLONG_MAX;
}

dist2[0]=0;

dijkstra2();

long long ans=0;

for(i=0;i<n;i++)
	ans+=dist1[i] + dist2[i];

printf("%lld\n",ans);

}

	return 0;
}

