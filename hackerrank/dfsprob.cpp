#include<bits/stdc++.h>
using namespace std;

int graph[1000][1000];

float prob[1000];

int visited[1000];

int n,check=0;

float prod=0;

int dfs(int x)
{
    int i,j,k;
    int ans=0;

    if(x==n||visited[x]==5)
        return 1;

    visited[x]=1;

    prod=prod+prob[x];

    for(i=0;i<n+1;i++)
    {

        if(visited[i]!=1&&graph[x][i])
        {
            ans=dfs(i);

            if(ans)
            {
                visited[x]=5;
                check=1;
                return 1;
            }

        }

        return 0;
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

        for(j=0;j<=n;j++)
        {
            for(k=0;k<n;k++)
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


                graph[k][y]=1;
            }
        }

        for(j=0;j<n;j++)
        {
            scanf("%f",&prob[j]);
        }

        float ans=1;

        for(j=0;j<n;j++)
        {
            check=0;
            prod=0;

            if(!visited[j])
            {
                dfs(j);

                if(check==0)
                {
                    ans=ans-prod;
                }
            }
        }

        cout<<(int)ans<<endl;
    }

    return 0;
}
