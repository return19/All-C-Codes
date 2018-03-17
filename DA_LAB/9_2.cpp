
#include<bits/stdc++.h>
using namespace std;

int n;
int e;

int graph[1010][1010];

int visited[1010];

stack<int> s;

void dfs(int x)
{
    int i;

    visited[x]=1;

    for(i=0;i<n;i++)
    {
        if(graph[x][i]&&!visited[i])
            dfs(i);
    }

    s.push(x);

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

    for(i=0;i<n;i++)
        if(!visited[i])
            dfs(i);

    cout<<"Elements in topological sorted order :"<<endl;

    while(!s.empty())
    {
        cout<<s.top()+1<<" ";

        s.pop();
    }

    return 0;
}








