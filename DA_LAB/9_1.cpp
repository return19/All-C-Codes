#include<bits/stdc++.h>
using namespace std;

int n;
int e;

int graph[1010][1010];

int visited[1010];


void bfs(int x)
{
    int i,j,k;

    queue<int> q;

    q.push(x);
    visited[x]=1;

    while(!q.empty())
    {
        x=q.front();
        q.pop();

        for(i=0;i<n;i++)
        {
            if(graph[x][i]==1&&!visited[i])
                {
                    visited[i]=1;
                    cout<<i+1<<" ";
                    q.push(i);
                }
        }
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
    }

    cout<<"Enter the node : "<<endl;

    cin>>x;

    cout<<"Nodes reachable from "<<x<<" : ";

    x--;

    bfs(x);

    return 0;
}








