#include<bits/stdc++.h>
using namespace std;

vector<int> graph[11000];

int visited[11000];

int nb[11000];

int c1=0;
int n,m;

int max1;
int max_x;

void dfs(int x,int k)
{
    int i,j;

    visited[x]=1;

    if(max1<k)
    {
        max1=k;
        max_x=x;

    }

    for(i=0;i<graph[x].size();i++)
    {
        if(!visited[graph[x][i]])
        {
            dfs(graph[x][i],k+1);
        }
    }
}

int dfs2(int x)
{
    int i,j;
    int r=0,count1=0;
    int n1=0;
    visited[x]=1;

    for(i=0;i<graph[x].size();i++)
    {
        if(nb[graph[x][i]]>=2)
            n1++;

        if(!visited[graph[x][i]])
        {
            j=dfs2(graph[x][i]);
        }
    }

    if(n1>=3)
    {
        n1--;

        if(n1%2==0)
        {
            c1=c1+n1/2;
        }
        else
        {
            c1=c1+n1/2+1;
        }
    }



    return r+1;
}


int main()
{
    int test,i,j,k;
    int x,y;


    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        memset(visited,0,sizeof(visited));
        memset(nb,0,sizeof(nb));
        scanf("%d",&n);

        for(j=0;j<n-1;j++)
        {
            scanf("%d%d",&x,&y);

            graph[x].push_back(y);
            graph[y].push_back(x);

            nb[x]++;
            nb[y]++;

        }

        c1=0;

        max1=0;

        dfs(0,1);

        memset(visited,0,sizeof(visited));

        dfs2(max_x);

        if(c1==0)
        {
            printf("1\n");

        }
        else if(c1==1)
        {
            printf("2\n");
        }
        else
            printf("%d\n",c1);

        for(j=0;j<n;j++)
        {
            graph[j].resize(0);
        }
    }

    return 0;
}
