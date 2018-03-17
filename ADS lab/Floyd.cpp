#include<bits/stdc++.h>
using namespace std;

int g[100][100];
int dist[100][100];

int main()
{
    int i,j,k;
    int n,m;
    cout<<"Enter the number of nodes : ";
    cin>>n;

    cout<<"Enter the number of edges : ";
    cin>>m;

    for(i=0;i<n;i++)
        for(j=0;j<n;j++){
            if(i==j)
                dist[i][j]=0;
            else
                dist[i][j]=INT_MAX;
        }

    cout<<"Enter the edges : "<<endl;
    for(i=0;i<m;i++){
        int x,y,z;
        cin>>x>>y>>z;
        x--;    y--;
        g[x][y]=z;
        g[y][x]=z;
        dist[x][y]=z;
        dist[y][x]=z;
    }

    for(k=0;k<n;k++)
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                if(dist[i][k]!=INT_MAX && dist[k][j]!=INT_MAX
                   && dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];

    cout<<"All pair shortest path matrix is : "<<endl;

    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
            cout<<dist[i][j]<<" ";
        cout<<endl;
    }


    return 0;
}
