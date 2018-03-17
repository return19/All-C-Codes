#include<bits/stdc++.h>
using namespace std;

int n;
int e;

int graph[1010][1010];

int visited[1010];

void dfs(int x)
{
    int i;

    visited[x]=1;

    for(i=0;i<n;i++)
    {
        if(graph[x][i]&&!visited[i])
            dfs(i);
    }

}

int main()
{
    int i,j,k;
    int x,y;

    cin>>n>>e;

    for(i=0;i<e;i++)
    {
        cin>>x>>y;

        x--;
        y--;

        graph[x][y]=1;
        graph[y][x]=1;
    }

        dfs(0);

    int ans=0;

    for(i=0;i<n;i++)
        if(!visited[i])
            ans=1;

    if(ans==0)
    {
        cout<<"Connected graph"<<endl;
    }
    else
        cout<<"Not connected"<<endl;

    return 0;
}









