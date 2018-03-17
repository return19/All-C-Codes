#include<bits/stdc++.h>
using namespace std;

int vis[10][10];

int arr[10][10];

int c=0;

int printPath(int x,int y,int vis[10][10],int cnt)
{

    cout<<cnt<<endl;
    c++;
    if(c==100000)
        return 1;

	if(cnt==64)
		return 1;

	if(x<0||y<0||x>=8||y>=8||vis[x][y])
		return 0;

	vis[x][y]=1;

	if(printPath(x-2,y-1,vis,cnt+1))
	{
		arr[x][y]=cnt+1;
		return 1;
}

if(printPath(x-2,y+1,vis,cnt+1))
	{
		arr[x][y]=cnt+1;
		return 1;
}

if(printPath(x+2,y-1,vis,cnt+1))
	{
		arr[x][y]=cnt+1;
		return 1;
}

if(printPath(x+2,y+1,vis,cnt+1))
	{
		arr[x][y]=cnt+1;
		return 1;
}

if(printPath(x-1,y-2,vis,cnt+1))
	{
		arr[x][y]=cnt+1;
		return 1;
}

if(printPath(x+1,y-2,vis,cnt+1))
	{
		arr[x][y]=cnt+1;
		return 1;
}

if(printPath(x-1,y+2,vis,cnt+1))
	{
		arr[x][y]=cnt+1;
		return 1;
}

if(printPath(x+1,y+2,vis,cnt+1))
	{
		arr[x][y]=cnt+1;
		return 1;
}

	vis[x][y]=0;
	return 0;
}

int main()
{
	int i,j,k;

	int n,m;

	cin>>n>>m;

n--;  // assuming (0,0) based indexing
m--;

	printPath(n,m,vis,0);

	for(i=1;i<=8;i++)
    {
        for(j=1;j<=8;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }

	return 0;
}

