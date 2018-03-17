#include<bits/stdc++.h>
using namespace std;

vector<int> g[100010];
int vis[101000];
int ccno;

void dfs(int x){
    int i,j,k;
    vis[x]=ccno; // Mark node as visited
    for(i=0;i<g[x].size();i++){ // Iterate over every neighbour of x
        if(!vis[ g[x][i] ]) // if ith neighbour is not visited
            dfs(g[x][i]);
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

    ccno=1;
    for(i=0;i<n;i++){
        if(!vis[i]){
            dfs(i);
            ccno++;
        }
    }

    // vis[x] is 0 if x node is not visited
    // if vis[x] is not 0, then vis[x] denotes the connected
    // component x belongs to

   // for(i=0;i<n;i++)
     //   cout<<vis[i]<<" ";
    //cout<<endl;

    int q;
    scanf("%d",&q);
    for(i=0;i<q;i++){
        scanf("%d%d",&x,&y);
        if(vis[x]==vis[y]){
            printf("PATH EXISTS\n"); // if both x and y belongs to same connected component then there exists a path between x and y
        } else {
            printf("PATH DOESN'T EXIST\n");
        }
    }

    return 0;
}












