#include<bits/stdc++.h>
using namespace std;

int g[510][510];
int vis[510];
int n;
int tk[510];

int dfs(int x){
    vis[x]=1;
    tk[x]=1;
    int i,j,k;

    for(i=0;i<n;i++){
        if(!vis[i] && g[x][i]){
            if(dfs(i))
                return 1;
        }else if(vis[i] && g[x][i] && tk[i])
            return 1;
    }
    tk[x]=0;
    return 0;
}

int main()
{
    int i,j,k;
    int test,t;


    scanf("%d",&test);

    for(t=0;t<test;t++){
        scanf("%d",&n);

        for(i=0;i<n;i++){
            vis[i]=0;
            tk[i]=0;
        }

        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                scanf("%d",&g[i][j]);

        int ans=0;

        for(i=0;i<n;i++){

            if(!vis[i]){
                if(dfs(i))
                {
                    ans=1;
                }
            }
        }

        if(ans)
            printf("Aye\n");
        else
            printf("Nae\n");
    }
    return 0;
}

