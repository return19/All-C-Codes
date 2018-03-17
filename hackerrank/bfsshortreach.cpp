#include<bits/stdc++.h>
using namespace std;

int n,m;

int graph[1100][1100];

int visited[1100];
int ans[1100];

void bfs(int x)
{
    int i,j,k;

    queue< int > q;

    ans[x]=0;

    q.push(x);

    while(!q.empty())
    {
        int p=q.front();
        q.pop();

        visited[p]=1;

        for(i=0;i<n;i++)
        {
            if(!visited[i]&&graph[p][i])
            {
                ans[i]=ans[p]+6;

                visited[i]=1;

                q.push(i);
            }
        }
    }
}

int main()
{
    int test,i,j,k;
    int s;

    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        memset(visited,0,sizeof(visited));


        scanf("%d%d",&n,&m);

        for(j=0;j<=n+1;j++)
        {
            for(k=0;k<=n+1;k++)
            {
                graph[j][k]=0;
            }
        }

        for(j=0;j<=n+1;j++)
            ans[j]=-1;

        for(j=0;j<m;j++)
        {
            int x,y;

            scanf("%d%d",&x,&y);
            x--;
            y--;

            graph[x][y]=1;
            graph[y][x]=1;

        }

        scanf("%d",&s);
        s--;

        bfs(s);

        for(j=0;j<n;j++)
        {
            if(j==s)
                continue;

            printf("%d ",ans[j]);
        }

        cout<<endl;

    }

    return 0;
}
