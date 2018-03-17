#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define ft first
#define sd second

vector< pair<int,int> > g[101000];
int n,m;
int dist[101000];
int vis[101000];

void dijkstra(int source){
    int i,j,k;
    for(i=0;i<n;i++){
        dist[i] = INT_MAX;
        vis[i] = 0;
    }
    dist[source] = 0;
    set< pair<int,int> > s; // pair is dist, node_number
    set< pair<int,int> >::iterator it;

    for(i=0;i<n;i++)
        s.insert(mp(dist[i],i));

    while(!s.empty()){
        it = s.begin();
        pair<int,int> temp = *it;
        s.erase(temp); // remove minimum val node
        int cur = temp.sd;
        int val = temp.ft;

        if(val == INT_MAX)
            return;

        for(i=0;i<g[cur].size();i++){
            int nb = g[cur][i].ft;
            if(!vis[nb] && dist[nb] > val + g[cur][i].sd){
                s.erase(mp(dist[nb],nb)); // erase old val
                dist[nb] = val + g[cur][i].sd;
                s.insert(mp(dist[nb],nb));
            }
        }
    }
}

int main()
{
    int i,j,k;
    int x,y,z;
    scanf("%d%d",&n,&m);
    for(i=0;i<m;i++){
        scanf("%d%d%d",&x,&y,&z);
        x--;    y--; // zero indexing
        g[x].push_back(mp(y,z));
    }

    int s;
    scanf("%d",&s); // source
    s--; // zero indexing

    dijkstra(s);
    for(i=0;i<n;i++)
        cout<<dist[i]<<" ";
    cout<<endl;

    return 0;
}
