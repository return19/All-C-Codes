#include<bits/stdc++.h>
using namespace std;

int n,m;

vector< vector<int> > v;

int visited[10100];

int dfs(int x,int p)
{
    visited[x]=1;

    int i,j,k;

    for(i=0;i<v[x].size();i++)
    {
        if(!visited[v[x][i]])
        {
            int temp=dfs(v[x][i],x);

            if(temp==1)
                return 1;
        }
        else
        {
            if(v[x][i]!=p)
                return 1;
        }
    }

    return 0;
}

int main()
{
    int i,j,k;
    int x,y;

    scanf("%d%d",&n,&m);

    v.resize(n);

    for(i=0;i<m;i++)
    {
        scanf("%d%d",&x,&y);

        x--;
        y--;

        v[x].push_back(y);
    }

    int check=0;
    int temp;
    int c=0;

    for(i=0;i<n;i++)
    {
        if(!visited[i]){
            c++;
            temp=dfs(i,-1);
        }

        if(temp)
            check=1;
    }

    if(c>1)
        check=1;

    if(check)
        printf("NO\n");
    else
        printf("YES\n");

    return 0;
}
