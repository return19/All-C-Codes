#include<bits/stdc++.h>
using namespace std;

#define MAX 999999999999

long long n,m,b;
long long no_of_parcels;

long long graph[110][110];

long long fw[110][110];

long long st[11];
long long ed[11];
long long count1[11];

long long solve(long long mask[],
                long long last)
{
	long long i,j,k;
	long long c=0;
	long long ans=LLONG_MAX;

	for(i=0;i<no_of_parcels;i++)
	{
		if(mask[i]==0)
			c++;
}

if(c==0)
{
	return fw[last][b];
}
else
{
	for(i=0;i<no_of_parcels;i++)
	{
		if(mask[i]==0)
		{
			mask[i]=1;
			ans=min(ans,fw[last][st[i]] + (2*count1[i]-1)*fw[st[i]][ed[i]] + solve(mask,ed[i]));
			mask[i]=0;
}
}


return ans;
}
}

void folydWarshall()
{
	long long i,j,k;

	for(k=0;k<n;k++)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(fw[i][j]>fw[i][k] + fw[k][j])
					fw[i][j]=fw[i][k] + fw[k][j];
}
}
}
/*for(i=0;i<n;i++)
		{for(j=0;j<n;j++){
			cout<<fw[i][j]<<" ";
		}
		cout<<endl;
		}*/


}

int main()
{
	long long test,t,i,j,k;
	long long u,v,w;

	cin>>test;

	for(t=0;t<test;t++)
	{
		cin>>n>>m>>b;

		b--;

		for(i=0;i<n;i++)
			for(j=0;j<n;j++){
				graph[i][j]=0;
                if(i!=j)
                    fw[i][j]=MAX;
                else
                    fw[i][j]=0;
            }

		for(i=0;i<m;i++)
	{
		cin>>u>>v>>w;

		u--;
        v--;

        if(graph[u][v]!=0)
        {
            graph[u][v]=min(graph[u][v],w);
            graph[v][u]=min(graph[v][u],w);
            fw[u][v]=min(fw[u][v],w);
            fw[v][u]=min(fw[v][u],w);
        }
        else{
            graph[u][v]=w;
            graph[v][u]=w;
            fw[u][v]=w;
            fw[v][u]=w;
        }
}

folydWarshall();

cin>>no_of_parcels;

for(i=0;i<no_of_parcels;i++)
{
	cin>>st[i]>>ed[i]>>count1[i];

	st[i]--;
	ed[i]--;
}

long long mask[11];
for(i=0;i<10;i++)
	mask[i]=0;

long long ans=solve(mask,b);

cout<<ans<<endl;
}

	return 0;
}

