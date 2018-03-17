
#include<bits/stdc++.h>
using namespace std;

int graph[1000][1000];

double prob[1000];

int visited[1000];

int n,check=0;

double prod=0;

void dfs(int x)
{
    int i,j,k;

    //cout<<"x :"<<x<<endl;

    visited[x]=1;
    if(x!=n)
        prod+=prob[x];

    for(i=0;i<n;i++)
    {
        if(!visited[i]&&graph[x][i])
        {
            dfs(i);
        }
    }
}

int main()
{
    int test,i,j,k;
    int x,y;

    scanf("%d",&test);

    for(i=0;i<test;i++)
    {


        scanf("%d",&n);

        for(j=0;j<=n+1;j++)
        {
            for(k=0;k<=n+1;k++)
                graph[j][k]=0;
        }

        memset(visited,0,sizeof(visited));

        for(j=0;j<n+1;j++)
        {
            scanf("%d",&x);

            for(k=0;k<x;k++)
            {
                scanf("%d",&y);
                y--;


                graph[y][j]=1;
            }
        }



        for(j=0;j<n;j++)
        {
            cin>>prob[j];
            //scanf("%f",&prob[j]);
        }

        prod=0;

        dfs(n);

        //cout<<check<<endl;

       cout<<(int)prod<<endl;

    }

    return 0;
}
