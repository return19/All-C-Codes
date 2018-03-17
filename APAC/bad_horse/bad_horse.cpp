#include<bits/stdc++.h>
using namespace std;

map<string,int> memo;

string s;

int graph[110][110];

int vis[110];

int col[110];

int n;

int dfs(int x,int t)
{
    int i,j,k;

    vis[x]=1;

    col[x]=t;

    if(t==1)
        j=2;
    else
        j=1;

    for(i=0;i<n;i++)
    {
        if(graph[x][i] && !vis[i])
        {
            if(dfs(i,j))
                return 1;
        }
        else if(graph[x][i] && vis[i] && col[i]==col[x])
            return 1;
    }

    return 0;
}

int main()
{
    int i,j,k;

    int test,t;

    int x,y;

    scanf("%d",&test);

    for(t=0;t<test;t++)
    {
        scanf("%d",&n);

        k=0;

        for(i=0;i<105;i++)
            for(j=0;j<105;j++)
                graph[i][j]=0;

        for(i=0;i<n;i++)
        {
            cin>>s;

            if(memo.find(s)==memo.end())
            {
                memo[s]=k;
                k++;
            }

            x=memo[s];

            cin>>s;

            if(memo.find(s)==memo.end())
            {
                memo[s]=k;
                k++;
            }

            y=memo[s];

           // cout<<x<<" "<<y<<endl;

            graph[x][y]=1;
            graph[y][x]=1;
        }

        int ans=0;
        int temp;

        n=k;

        for(i=0;i<n;i++){
            vis[i]=0;
            col[i]=-1;
        }

        for(i=0;i<n;i++)
        {
            if(!vis[i])
                temp=dfs(i,1);

            if(temp==1)
            {
                ans=1;
                break;
            }
        }


        if(ans==1)
            printf("Case #%d: No\n",t+1);
        else
            printf("Case #%d: Yes\n",t+1);

        memo.clear();

    }

    return 0;
}









