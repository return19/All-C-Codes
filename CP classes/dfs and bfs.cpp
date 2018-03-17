#include<bits/stdc++.h>
using namespace std;

vector<int> g[100010];
int vis[101000];

void dfs(int x){
    int i,j,k;
    vis[x]=1; // Mark node as visited
    cout<<x<<" ";
    for(i=0;i<g[x].size();i++){ // Iterate over every neighbour of x
        if(!vis[ g[x][i] ]) // if ith neighbour is not visited
            dfs(g[x][i]);
    }
}

void bfs(int x){
    int i,j,k;
    queue<int> q;
    q.push(x); // push source node for bfs
    vis[x]=1; // Mark the node as visited

    while(!q.empty()){
        int cur = q.front(); // Get node at front of the queue
        q.pop(); // Remove the node cur from front of queue
        cout<<cur<<" ";

        for(i=0;i<g[cur].size();i++){ // Iterate over every neighbour of cur node
            if(!vis[ g[cur][i] ]) // If ith neighbour is not visited
            {
                q.push(g[cur][i]); // Push ith neighbour to queue
                vis[ g[cur][i] ] = 1;  // Mark it as visited
            }
        }
    }
}

int main()
{
    int i,j,k;
    int n,m;
    int x,y;
    scanf("%d%d",&n,&m); // input number of nodes and edges

    for(i=0;i<m;i++){ // input edges
        scanf("%d%d",&x,&y); // End nodes corresponding to edges
        // Edges are bi-directional (Undirected Graph)
        g[x].push_back(y); // Adding y to neighbour list of x
        g[y].push_back(x); // Adding x to neighbour list of y
    }

    for(i=0;i<n;i++){
        if(!vis[i])
            dfs(i);
    }
    cout<<endl;

    for(i=0;i<n;i++)    vis[i]=0;

    for(i=0;i<n;i++)
        if(!vis[i])
            bfs(i);
    cout<<endl;

    return 0;
}
