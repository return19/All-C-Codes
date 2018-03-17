#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define edge pair< int, int >
#define MAX 1001


vector< pair< int, edge > > GRAPH, MST;
int parent[MAX], total, N, E;

int findset(int x, int *parent)
{
    if(x != parent[x])
        parent[x] = findset(parent[x], parent);
    return parent[x];
}

void kruskal()
{
    int i, pu, pv;
    sort(GRAPH.begin(), GRAPH.end());
    for(i=total=0; i<E; i++)
    {
        pu = findset(GRAPH[i].second.first, parent);
        pv = findset(GRAPH[i].second.second, parent);
        if(pu != pv)
        {
            MST.push_back(GRAPH[i]);
            total += GRAPH[i].first;
            parent[pu] = parent[pv];
        }
    }
}

void reset()
{

    for(int i=1; i<=N; i++) parent[i] = i;
}

void print()
{
    int i, sz;
    sz = MST.size();
    for(i=0; i<sz; i++)
    {
        printf("( %d", MST[i].second.first);
        printf(", %d )", MST[i].second.second);
        printf(": %d\n", MST[i].first);
    }
    printf("Minimum cost: %d\n", total);
}

int main()
{
    int i, u, v, w;

    scanf("%d %d", &N, &E);
    reset();
    for(i=0; i<E; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        GRAPH.push_back(pair< int, edge >(w, edge(u, v)));
    }
    kruskal();
    print();

    return 0;
}
