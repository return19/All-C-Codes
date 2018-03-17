#include<bits/stdc++.h>
using namespace std;

int graph[110][110];

int vis[110];

int n;

int printHamil(int idx,int vis[],int cnt)
{
	if(cnt==n)
	{
        vis[idx]=n;
		if(graph[idx][0])
            return 1;
        vis[idx]=0;

        return 0;
    }

	int i,j,k;

	vis[idx]=cnt;

	for(i=0;i<n;i++)
	{
		if( graph[idx][i]  && !vis[i])
		{
			if(printHamil(i,vis,cnt+1))
				return 1;
}
}

	vis[idx]=0;

	return 0;

}


int main()
{
	int i,j,k;

	cin>>n;

	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			cin>>graph[i][j];
}
}

printHamil(0,vis,1);

	for(i=0;i<n;i++)
		cout<<vis[i]<<" ";
	cout<<endl;

	return 0;
}

