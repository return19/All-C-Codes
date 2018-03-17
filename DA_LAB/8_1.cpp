#include<bits/stdc++.h>
using namespace std;
#define MAX 2000000

long dist[10010][10010];
int v;

void init()
{
    long i,j;

    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            if(i==j)
            {
                dist[i][j]=0;
            }
            else
            {
                dist[i][j]=MAX;
            }

        }
    }
}
void floyd_warshall()
{


    long i,j,k;
    for(k=0;k<v;k++)
    {
        for(i=0;i<v;i++)
        {
            for(j=0;j<v;j++)
            {
                if(dist[i][j]>dist[i][k]+dist[k][j])
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }

    cout<<"Floyd Warshall distance matrix :"<<endl;

    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
            cout<<dist[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{
    long i,j,k,start,last,w;
    int edges;

        scanf("%ld",&v);
        scanf("%ld",&edges);
        init();
        for(j=0;j<edges;j++)
        {
            scanf("%ld",&start);
            scanf("%ld",&last);
            scanf("%ld",&w);
            dist[start-1][last-1]=w;
            dist[last-1][start-1]=w;
        }
        floyd_warshall();
    return 0;
}



















