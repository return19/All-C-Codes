#include<bits/stdc++.h>
using namespace std;

int dis[1000];
int low[1000];
int p[1000];
int g[100][100];
int ans[1000];
int v[1000];

int t = 0;
int n;

void ap(int u)
{
	dis[u] = t++;
	low[u] = dis[u];
	int chld = 0;
	for(int i=0;i<n;i++){

		if(g[u][i] == 1 && v[i] ==0){
			chld++;
			p[i] = u;
			ap(i);

			low[u] = min(low[u],low[i]);

			if(p[u] == -1 && chld>1)
				ans[u] =1;

			if(p[u]!=-1 && low[i]>=low[u])
				ans[u] = 1;

		}
		else if(g[u][i] == 1 && p[u] != i)
			low[u] = min(low[u],dis[i]);
	}
}


int main()
{

	cin>>n;

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>g[i][j];

	for(int i=0;i<n;i++){
		v[i] = 0;
		p[i] = -1;
	}

	for(int i=0;i<n;i++){
		if(v[i]==0)
			ap(i);
	}

	for(int i=0;i<n;i++){
		if(ans[i]==1)
			cout<<i<<" ";
	}

	return 0;
}

