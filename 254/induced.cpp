#include<bits/stdc++.h>

using namespace std;

int graph[500][500];
int node[500];
int vis[500];

int main()
{
    int n,m;

    scanf("%d",&n);

    for(int i=0;i<n;i++)
        scanf("%d",&node[i]);

    for(int i=0;i<m;i++)
    {
        int x,y,v;
        scanf("%d%d%d",&x,&y,&v);

        graph[x][y] = v;
        graph[y][x] = v;
    }
    int rst = 0;

    for(int i=0;i<n;i++){

        for(int j=0;j<n;j++)
        {
            if(graph[i][j]!=0)
            {

            }
        }
    }


}
