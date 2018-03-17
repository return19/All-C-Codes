#include<bits/stdc++.h>
using namespace std;

int visited[10010];
int n;
vector<vector<int>> graph;

int dfs(int p)
{
    set<int,int> x;
    set<int,int> temp;
    queue<set<int,int>> q;
    int i,j,k,max1=-9999;


    x->first=p;
    x->second=1;
    q.push(x);

    while(!q.empty())
    {
        temp=q.front();
        q.pop();
        visited[temp->first]=1;
        for(i=0;i<n;i++)
        {
            if(!visited[i]&&graph[temp->first][i])
            {
                x->first=i;
                x->second=temp->second+1;
                if(max1<x->second)
                {
                    max1=x->second;
                }
                q.push(x);
            }
        }
    }

    return max1;
}

int main()
{
    int test,i,j,k,t1,t2;

    scanf("%d",&test);

    for(i=0;i<test;i++)
    {
        scanf("%d",&n);

        for(i=0;i<n;i++)
        {
            scanf("%d%d",&t1,&t2);
            graph[t1].push_back(t2);
        }

    }

    return 0;
}
